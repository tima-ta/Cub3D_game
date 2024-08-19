/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araqioui <araqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 09:48:49 by fraqioui          #+#    #+#             */
/*   Updated: 2023/06/26 10:04:22 by araqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

static void	color_ceil_floor(t_holder hold)
{
	int	i;
	int	j;

	i = 0;
	while (i < (WIN_HEIGHT / 2))
	{
		j = 0;
		while (j < WIN_WIDTH)
			my_mlx_pixel_put(&hold.img, j++, i,
				rgb_to_hex(hold.data.ceiling[0],
					hold.data.ceiling[1], hold.data.ceiling[2]));
		i++;
	}
	while (i < WIN_HEIGHT)
	{
		j = 0;
		while (j < WIN_WIDTH)
			my_mlx_pixel_put(&hold.img, j++, i,
				rgb_to_hex(hold.data.floor[0],
					hold.data.floor[1], hold.data.floor[2]));
		i++;
	}
}

void	mini_map(t_holder hold)
{
	color_ceil_floor(hold);
	save_rays(&hold);
	render_walls_3d(hold);
	mlx_put_image_to_window(hold.mlx, hold.win, hold.img.img, 0, 0);
}
