/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araqioui <araqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 16:02:38 by araqioui          #+#    #+#             */
/*   Updated: 2023/06/26 10:29:49 by araqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

static int	valid_char(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W'
		|| c == ' ' || c == '0' || c == '1')
		return (1);
	return (0);
}

static int	check_others(char **map, int i, int check)
{
	if (map[i] && map[i][0] == '\n')
	{
		while (map[i] && map[i][0] == '\n')
			i++;
		if (map[i])
			return (ft_putstr_fd("Error\nNew line\n", 2), 0);
	}
	if (!check || check > 1)
		return (ft_putstr_fd("Error\nInvalid number of players\n", 2), 0);
	return (1);
}

int	check_chars(char **map, int *size)
{
	int	i;
	int	j;
	int	check;

	check = 0;
	i = 0;
	while (map[i] && map[i][0] != '\n')
	{
		j = 0;
		while (map[i][j] && map[i][j] != '\n')
		{
			if (valid_char(map[i][j]) && check <= 1)
			{
				if (map[i][j] == 'N' || map[i][j] == 'S'
					|| map[i][j] == 'E' || map[i][j] == 'W')
				check++;
			}
			else
				return (ft_putstr_fd("Error\nInvalid character\n", 2), 0);
			j++;
		}
		i++;
	}
	*size = i;
	return (check_others(map, i, check));
}
