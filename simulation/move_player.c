/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araqioui <araqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 15:18:33 by araqioui          #+#    #+#             */
/*   Updated: 2023/06/26 11:04:22 by araqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

static void	move_for_back_ward(t_info *data, int dir, int *flg)
{
	data->p_coor.x += dir * (cos(data->angle) * PLAYER_SPEED);
	data->p_coor.y += dir * (sin(data->angle) * PLAYER_SPEED);
	*flg = 1;
}

static void	turn_dir(t_info *data, int dir, int *flg)
{
	*flg = 1;
	data->angle += dir * deg_to_rad(ANGLE_SPEED);
	data->angle = angle_range(data->angle);
}

static void	move_left_right(t_info *data, int dir, int *flg)
{
	t_coor_fl	test;

	test.x = data->p_coor.x
		+ (cos(angle_range(data->angle + dir * (M_PI / 2))) * 2);
	test.y = data->p_coor.y
		+ (sin(angle_range(data->angle + dir * (M_PI / 2))) * 2);
	data->p_coor.x = test.x;
	data->p_coor.y = test.y;
	*flg = 1;
}

int	move_player(int keycode, void *param)
{
	t_holder	*hold;
	int			flg;

	flg = 0;
	hold = (t_holder *)param;
	if (keycode == 13)
		move_for_back_ward(&hold->data, 1, &flg);
	else if (keycode == 1)
		move_for_back_ward(&hold->data, -1, &flg);
	else if (keycode == 0)
		move_left_right(&hold->data, -1, &flg);
	else if (keycode == 2)
		move_left_right(&hold->data, 1, &flg);
	else if (keycode == 123)
		turn_dir(&hold->data, -1, &flg);
	else if (keycode == 124)
		turn_dir(&hold->data, 1, &flg);
	else if (keycode == 53)
		ft_close(hold);
	if (flg)
	{
		mlx_clear_window(hold->mlx, hold->win);
		mini_map(*hold);
	}
	return (0);
}
