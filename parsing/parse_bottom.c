/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bottom.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araqioui <araqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 15:13:24 by araqioui          #+#    #+#             */
/*   Updated: 2023/06/26 10:53:28 by araqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

static char	*make_it_square(char *map, int max_string)
{
	char	*str;
	int		i;

	str = malloc((max_string + 1) * sizeof(char));
	if (!str)
		return (ft_putstr_fd("Error\nAllocation failed\n", 2), NULL);
	i = 0;
	while (map[i] && map[i] != '\n')
	{
		str[i] = map[i];
		i++;
	}
	while (i < max_string)
		str[i++] = ' ';
	str[i] = '\0';
	return (str);
}

static int	get_max_len(char **map)
{
	int	max_string;
	int	keep_len;
	int	i;

	max_string = 0;
	i = -1;
	while (map[++i])
	{
		keep_len = strlen_nl(map[i]);
		if (max_string < keep_len)
			max_string = keep_len;
	}
	return (max_string);
}

static void	copy_map(char **map, char **copy_map, int size)
{
	int		max_string;
	int		keep_len;
	int		i;

	max_string = get_max_len(map);
	i = -1;
	while (++i < size)
	{
		keep_len = strlen_nl(map[i]);
		if (keep_len == max_string)
			copy_map[i] = ft_strdup_(map[i]);
		else
			copy_map[i] = make_it_square(map[i], max_string);
		if (!copy_map[i])
		{
			free_2d(copy_map);
			return ;
		}
	}
	copy_map[i] = NULL;
}

static int	check_walls(char **map, int size)
{
	char	**test_map;

	test_map = malloc((size + 1) * sizeof(char *));
	if (!test_map)
		return (ft_putstr_fd("Error\nAllocation failed\n", 2), 0);
	copy_map(map, test_map, size);
	if (!test_map)
		return (0);
	if (!vertically_check(test_map, 0, 0)
		|| !horizontally_check(test_map, size, -1, 0))
		return (free_2d(test_map), ft_putstr_fd("Error\nInvalid walls\n", 2), 0);
	return (free_2d(test_map), 1);
}

int	parse_bottom(char **file, t_info *data, int index)
{
	int	size;
	int	i;

	if (!check_chars(file + index, &size) || !check_walls(file + index, size))
		return (0);
	data->map = malloc((size + 1) * sizeof(char *));
	if (!data->map)
		return (ft_putstr_fd("Error\nAllocation failed\n", 2), 0);
	i = -1;
	while (++i < size)
	{
		data->map[i] = ft_strdup_(file[i + index]);
		if (!data->map[i])
			return (ft_putstr_fd("Error\nAllocation failed\n", 2), 0);
	}
	data->map[i] = NULL;
	return (1);
}
