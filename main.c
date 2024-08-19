/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araqioui <araqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:50:34 by fraqioui          #+#    #+#             */
/*   Updated: 2023/06/26 11:12:17 by araqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/cub3d.h"

static void	get_player_cord(t_info *data)
{
	char	**map;
	int		i;
	int		j;

	map = data->map;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (is_player(map[i][j]))
			{
				data->p_coor.y = i * BOX_SIZE + 10;
				data->p_coor.x = j * BOX_SIZE + 10;
				data->dir = map[i][j];
				break ;
			}
		}
	}
}

static int	evolve(char **av)
{
	char		**map;
	t_info		data;
	int			index;

	index = 0;
	if (!map__name(av[1]))
		return (0);
	map = reading_map(av[1]);
	if (!map)
		return (0);
	data_init(&data);
	if (!parse_top(map, &data, &index) || !parse_bottom(map, &data, index))
		return (free_2d(map), data_free(&data), 1);
	get_player_cord(&data);
	if (!simulation(data))
		return (free_2d(map), data_free(&data), 1);
	return (free_2d(map), data_free(&data), 0);
}

int	main(int ac, char **av)
{
	if (ac == 2)
		return (evolve(av));
	else
		ft_putstr_fd("Error\nInvalid number of arguments\n", 2);
}
