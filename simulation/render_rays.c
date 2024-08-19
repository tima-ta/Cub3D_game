/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_rays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araqioui <araqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 07:54:35 by fraqioui          #+#    #+#             */
/*   Updated: 2023/06/26 11:17:59 by araqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../headers/cub3d.h"

void	save_rays(t_holder *hold)
{
	int		i;
	double	rays_angle;
	double	start_angle;

	i = 0;
	hold->help_cor.x = hold->data.p_coor.x;
	hold->help_cor.y = hold->data.p_coor.y;
	rays_angle = ((M_PI / 3) / (float)hold->num_rays);
	start_angle = (hold->data.angle - (M_PI / 6));
	while (i < hold->num_rays)
	{
		if (i <= hold->num_rays / 2)
			hold->dir[i].hit_info.left = true;
		else
			hold->dir[i].hit_info.left = false;
		found_hit_point(hold, &(hold->dir[i]), angle_range(start_angle));
		hold->dir[i].hit_info.angle = angle_range(start_angle);
		start_angle += rays_angle;
		i++;
	}
}
