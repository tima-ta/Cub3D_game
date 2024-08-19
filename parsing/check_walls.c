/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araqioui <araqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 16:09:34 by araqioui          #+#    #+#             */
/*   Updated: 2023/06/26 10:55:08 by araqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int	vertically_check(char **map, int i, int flg)
{
	int	j;

	i = -1;
	while (map[++i])
	{
		flg = 0;
		j = 0;
		while (map[i][j])
		{
			while (map[i][j] && map[i][j] == ' ')
				j++;
			if (!map[i][j])
				break ;
			flg = 1;
			if (map[i][j] && map[i][j] != '1')
				return (0);
			while (map[i][j] && map[i][j] != ' ')
				j++;
			if ((!map[i][j] || map[i][j] == ' ') && map[i][j - 1] != '1')
				return (0);
		}
		if (!flg)
			return (0);
	}
	return (1);
}

int	horizontally_check(char **map, int s, int j, int flg)
{
	int	i;

	i = 0;
	while (map[i][++j])
	{
		flg = 0;
		while (i < s)
		{
			while (i < s && map[i][j] == ' ')
				i++;
			if (i == s)
				break ;
			flg = 1;
			if (i < s && map[i][j] != '1')
				return (0);
			while (i < s && map[i][j] != ' ')
				i++;
			if ((i == s || (i < s && map[i][j] == ' ')) && map[i - 1][j] != '1')
				return (0);
		}
		i = 0;
		if (!flg)
			return (0);
	}
	return (1);
}
