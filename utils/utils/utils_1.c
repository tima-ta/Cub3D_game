/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araqioui <araqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 13:32:51 by araqioui          #+#    #+#             */
/*   Updated: 2023/06/26 10:04:12 by araqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

double	deg_to_rad(double angle)
{
	return (angle * (M_PI / 180));
}

double	angle_range(double angle)
{
	double	two_pi;

	two_pi = 2 * M_PI;
	angle = fmod(angle, two_pi);
	if (angle < 0)
		angle += two_pi;
	return (angle);
}

double	distance(double x1, double x2, double y1, double y2)
{
	return (sqrt((double)((x2 - x1) * (x2 - x1))
		+ (double)((y2 - y1) * (y2 - y1))));
}

int	is_player(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}
