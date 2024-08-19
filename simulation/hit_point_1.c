/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_point_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 10:02:13 by fraqioui          #+#    #+#             */
/*   Updated: 2023/06/26 08:30:16 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../headers/cub3d.h"

static void	ray_direction(t_direction *ray, double angle)
{
	ray->down = (angle > 0 && angle < M_PI);
	ray->up = !ray->down;
	ray->right = (angle < (M_PI / 2) || angle > ((3 * M_PI) / 2));
	ray->left = !ray->right;
}

static void	actual_point_coor(t_holder *hold, t_direction *ray)
{
	if (ray->hit_info.horz_point.it_hits)
		ray->hit_info.horz_point.distance
			= distance(ray->hit_info.horz_point.x, hold->data.p_coor.x,
				ray->hit_info.horz_point.y, hold->data.p_coor.y);
	else
		ray->hit_info.horz_point.distance = INT_MAX;
	if (ray->hit_info.vert_point.it_hits)
		ray->hit_info.vert_point.distance
			= distance(ray->hit_info.vert_point.x, hold->data.p_coor.x,
				ray->hit_info.vert_point.y, hold->data.p_coor.y);
	else
		ray->hit_info.vert_point.distance = INT_MAX;
	ray->hit_info.vert_hit
		= (ray->hit_info.vert_point.distance
			< ray->hit_info.horz_point.distance);
}

void	found_hit_point(t_holder *hold, t_direction *ray, double angle)
{
	ray_direction(ray, angle);
	calc_steps_horz(hold, ray, angle);
	horizontal_hit_point(hold, ray);
	calc_steps_vert(hold, ray, angle);
	vertical_hit_point(hold, ray);
	actual_point_coor(hold, ray);
}
