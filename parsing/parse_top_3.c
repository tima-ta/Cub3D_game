/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_top_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araqioui <araqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 10:23:05 by fraqioui          #+#    #+#             */
/*   Updated: 2023/06/25 10:41:47 by araqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

static int	fill_texture_1(char *info, int flg, t_info *data)
{
	if (flg == 1)
	{
		if (data->no)
			return (ft_putstr_fd("Error\nNO already exists\n", 2),
				free(info), 0);
		data->no = info;
	}
	if (flg == 2)
	{
		if (data->so)
			return (ft_putstr_fd("Error\nSo already exists\n", 2),
				free(info), 0);
		data->so = info;
	}
	return (1);
}

static int	fill_texture_2(char *info, int flg, t_info *data)
{
	if (flg == 3)
	{
		if (data->we)
			return (ft_putstr_fd("Error\nWE already exists\n", 2),
				free(info), 0);
		data->we = info;
	}
	if (flg == 4)
	{
		if (data->ea)
			return (ft_putstr_fd("Error\nEA already exists\n", 2),
				free(info), 0);
		data->ea = info;
	}
	return (1);
}

bool	fill_texture(char *info, int flg, t_info *data)
{
	int	check;

	check = fill_texture_1(info, flg, data);
	if (!check)
		return (false);
	check = fill_texture_2(info, flg, data);
	if (!check)
		return (false);
	return (true);
}

void	fill_rgb_f(int r, int g, int b, t_info *data)
{
	data->floor[0] = r;
	data->floor[1] = g;
	data->floor[2] = b;
}

void	fill_rgb_c(int r, int g, int b, t_info *data)
{
	data->ceiling[0] = r;
	data->ceiling[1] = g;
	data->ceiling[2] = b;
}
