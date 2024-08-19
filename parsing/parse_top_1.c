/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_top_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araqioui <araqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:57:13 by fraqioui          #+#    #+#             */
/*   Updated: 2023/06/25 10:41:32 by araqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int	len_new_line(char *s)
{
	int	l;

	l = 0;
	while (*s)
	{
		if (*s == '\n')
			return (l);
		s++;
		l++;
	}
	return (-1);
}

char	*eliminate_new_line(char *s)
{
	char	*ret;
	int		l;

	if (!s)
		return (NULL);
	l = len_new_line(s);
	if (l == -1)
		return (ft_strdup(s));
	ret = malloc(sizeof(char) * (l + 1));
	if (!ret)
		return (ft_putstr_fd("Error\nAllocation failed\n", 2), NULL);
	l = 0;
	while (*s && *s != '\n')
		ret[l++] = *s++;
	ret[l] = '\0';
	return (ret);
}

static bool	check_identifier(char **s, t_info *data)
{
	char	*save;

	save = ft_strdup(*(s + 1));
	if (!save)
		return (false);
	if (!ft_memcmp(*s, "NO", 3))
		return (fill_texture(save, 1, data));
	if (!ft_memcmp(*s, "SO", 3))
		return (fill_texture(save, 2, data));
	if (!ft_memcmp(*s, "WE", 3))
		return (fill_texture(save, 3, data));
	if (!ft_memcmp(*s, "EA", 3))
		return (fill_texture(save, 4, data));
	if (!ft_memcmp(*s, "F", 2))
		return (pick_color(save, 5, data));
	if (!ft_memcmp(*s, "C", 2))
		return (pick_color(save, 6, data));
	return (ft_putstr_fd("Error\nNot a valid identifier\n", 2),
		free(save), false);
}

static bool	check_map_elements(char *s, t_info *data)
{
	if (!(data->no && data->so && data->we && data->ea
			&& data->ceiling[0] != -1 && data->floor[0] != -1))
		return (ft_putstr_fd("Error\nSix elements are required\n", 2), false);
	if (!s)
		return (ft_putstr_fd("Error\nNo map detected\n", 2), false);
	return (true);
}

int	parse_top(char **map, t_info *data, int *index)
{
	char	**sp;
	char	*save;
	int		flg_1;

	while (*map)
	{
		flg_1 = 1;
		save = eliminate_new_line(*map);
		if (!save)
			return (data_free(data), 0);
		if (reach_map(save))
			break ;
		sp = ft_split(save, ' ', &flg_1, 1);
		if (!sp)
			return (data_free(data), free(save), 0);
		if (flg_1)
			if (!check_identifier(sp, data))
				return (data_free(data), free_2d(sp), free(save), 0);
		(free_2d(sp), free(save), save = NULL);
		(*index)++;
		map++;
	}
	if (!check_map_elements(*map, data))
		return (data_free(data), free(save), 0);
	return (free(save), 1);
}
