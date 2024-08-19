/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_point_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araqioui <araqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 11:18:45 by fraqioui          #+#    #+#             */
/*   Updated: 2023/06/26 09:49:58 by araqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../headers/cub3d.h"

static bool	is_wall(t_holder *hold, double x, double y)
{
	int	save_x1;
	int	save_y1;

	if (x < 0 || x >= (hold->width * BOX_SIZE)
		|| y < 0 || y >= (hold->height * BOX_SIZE))
		return (true);
	save_x1 = floor(x / BOX_SIZE);
	save_y1 = floor(y / BOX_SIZE);
	if (hold->data.map[save_y1][save_x1] == '1')
		return (true);
	return (false);
}

void	horizontal_hit_point(t_holder *hold, t_direction *ray)
{
	double	step_x;
	double	step_y;
	double	step_y_tmp;

	ray->hit_info.horz_point.it_hits = false;
	step_x = ray->hit_info.x_inters;
	step_y = ray->hit_info.y_inters;
	while (step_x >= 0 && step_y >= 0 && step_x <= (hold->width * BOX_SIZE)
		&& step_y <= (hold->height * BOX_SIZE))
	{
		step_y_tmp = step_y;
		if (ray->up)
			step_y_tmp--;
		if (is_wall(hold, step_x, step_y_tmp))
		{
			ray->hit_info.horz_point.it_hits = true;
			ray->hit_info.horz_point.x = step_x;
			ray->hit_info.horz_point.y = step_y;
			break ;
		}
		step_x += ray->hit_info.dx;
		step_y += ray->hit_info.dy;
	}
}

void	vertical_hit_point(t_holder *hold, t_direction *ray)
{
	double	step_x;
	double	step_y;
	double	step_x_tmp;

	ray->hit_info.vert_point.it_hits = false;
	step_x = ray->hit_info.x_inters;
	step_y = ray->hit_info.y_inters;
	while (step_x >= 0 && step_y >= 0 && step_x <= (hold->width * BOX_SIZE)
		&& step_y <= (hold->height * BOX_SIZE))
	{
		step_x_tmp = step_x;
		if (ray->left)
			step_x_tmp--;
		if (is_wall(hold, step_x_tmp, step_y))
		{
			ray->hit_info.vert_point.it_hits = true;
			ray->hit_info.vert_point.x = step_x;
			ray->hit_info.vert_point.y = step_y;
			break ;
		}
		step_x += ray->hit_info.dx;
		step_y += ray->hit_info.dy;
	}
}

void	calc_steps_horz(t_holder *hold, t_direction *ray, double angle)
{
	double	px;
	double	py;

	px = hold->data.p_coor.x;
	py = hold->data.p_coor.y;
	ray->hit_info.y_inters = floor(py / BOX_SIZE) * BOX_SIZE;
	if (ray->down)
		ray->hit_info.y_inters += BOX_SIZE;
	ray->hit_info.x_inters
		= px + (double)(ray->hit_info.y_inters - py) / (double)tan(angle);
	ray->hit_info.dy = BOX_SIZE;
	if (ray->up)
		ray->hit_info.dy *= -1;
	ray->hit_info.dx = BOX_SIZE / (double)tan(angle);
	if (ray->left && ray->hit_info.dx > 0)
		ray->hit_info.dx *= -1;
	if (ray->right && ray->hit_info.dx < 0)
		ray->hit_info.dx *= -1;
}

void	calc_steps_vert(t_holder *hold, t_direction *ray, double angle)
{
	double	px;
	double	py;

	px = hold->data.p_coor.x;
	py = hold->data.p_coor.y;
	ray->hit_info.x_inters = floor(px / BOX_SIZE) * BOX_SIZE;
	if (ray->right)
		ray->hit_info.x_inters += BOX_SIZE;
	ray->hit_info.y_inters
		= py + (double)(ray->hit_info.x_inters - px) * (double)tan(angle);
	ray->hit_info.dx = BOX_SIZE;
	if (ray->left)
		ray->hit_info.dx *= -1;
	ray->hit_info.dy = BOX_SIZE * (double)tan(angle);
	if (ray->up && ray->hit_info.dy > 0)
		ray->hit_info.dy *= -1;
	if (ray->down && ray->hit_info.dy < 0)
		ray->hit_info.dy *= -1;
}
