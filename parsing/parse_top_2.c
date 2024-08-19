/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_top_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araqioui <araqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 08:49:34 by fraqioui          #+#    #+#             */
/*   Updated: 2023/06/25 10:41:39 by araqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

static int	rgb_format(char *s)
{
	int	i;

	i = 0;
	while (*s)
	{
		if (*s == ',')
			i++;
		s++;
	}
	return (i == 2);
}

static bool	check_existence(t_info *data, int flg)
{
	if (flg == 5)
	{
		if (data->floor[0] != -1)
			return (ft_putstr_fd("Error\nF already exists\n", 2), false);
	}
	if (flg == 6)
	{
		if (data->ceiling[0] != -1)
			return (ft_putstr_fd("Error\nC already exists\n", 2), false);
	}
	return (true);
}

bool	pick_color(char *info, int flg, t_info *data)
{
	char	**keep;
	int		r;
	int		g;
	int		b;

	if (!check_existence(data, flg))
		return (free(info), false);
	if (rgb_format(info))
	{
		keep = ft_split(info, ',', NULL, 0);
		if (keep)
		{
			r = ft_atoi(keep[0]);
			g = ft_atoi(keep[1]);
			b = ft_atoi(keep[2]);
			if (r == -1 || g == -1 || b == -1)
				return (free_2d(keep), free(info), false);
			if (flg == 5)
				fill_rgb_f(r, g, b, data);
			else if (flg == 6)
				fill_rgb_c(r, g, b, data);
			return (free_2d(keep), free(info), true);
		}
	}
	return (_print_err(), free(info), false);
}

static bool	reach_map_hlp(char *s)
{
	char	*save;
	int		flg_0;
	int		flg_1;
	int		flg_2;

	flg_0 = 0;
	flg_1 = 0;
	flg_2 = 0;
	save = s;
	while (*s && (*s == '1' || *s == ' ' || *s == '0'))
	{
		if (*s == '1')
			flg_0++;
		if (*s == '0')
			flg_1++;
		if (*s == ' ')
			flg_2++;
		s++;
	}
	if (*s || (flg_2 && !flg_0 && !flg_1))
		return (false);
	return (true);
}

bool	reach_map(char *str)
{
	if (!*str)
		return (false);
	return (reach_map_hlp(str));
}
