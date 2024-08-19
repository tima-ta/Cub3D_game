/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araqioui <araqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 09:29:30 by fraqioui          #+#    #+#             */
/*   Updated: 2023/06/26 11:22:33 by araqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../headers/cub3d.h"

static void	textur_dir_2(t_holder hold, t_direction player,
	t_hit_info ray, t_data *img)
{
	if (player.down && player.right)
	{
		if (!ray.vert_hit)
			*img = hold.no;
		else
			*img = hold.we;
	}
	else if (player.down && player.left)
	{
		if (!ray.vert_hit)
			*img = hold.no;
		else
			*img = hold.ea;
	}
}

static void	texture_dir(t_holder hold, t_direction player,
	t_hit_info ray, t_data *img)
{
	if (player.up && player.right)
	{
		if (!ray.vert_hit)
			*img = hold.so;
		else
			*img = hold.we;
	}
	else if (player.up && player.left)
	{
		if (!ray.vert_hit)
			*img = hold.so;
		else
			*img = hold.ea;
	}
	else
		textur_dir_2(hold, player, ray, img);
}

static int	ft_pixcolx(t_hit_info data)
{
	if (data.vert_hit)
		return ((int)data.vert_point.y % BOX_SIZE);
	else
		return ((int)data.horz_point.x % BOX_SIZE);
}

static void	draw_wall_strip(t_holder hold, t_hit_info data,
	double wallheight, int x)
{
	t_coor			pixelcol;
	int				get_bot_wall;
	int				fix_top_wall_for_text;
	unsigned int	color;
	int				i;

	pixelcol.x = ft_pixcolx(data);
	i = (WIN_HEIGHT / 2) - ((int)wallheight / 2);
	get_bot_wall = (WIN_HEIGHT / 2) + ((int)wallheight / 2);
	if (i < 0)
	{
		i = 0;
		get_bot_wall = WIN_HEIGHT;
	}
	while (i < get_bot_wall)
	{
		texture_dir(hold, hold.dir[x], hold.dir[x].hit_info, &hold.img_help);
		fix_top_wall_for_text = i + (wallheight / 2) - (WIN_HEIGHT / 2);
		pixelcol.y = fix_top_wall_for_text * (32 / wallheight);
		color = pixelcol.y * hold.img_help.line_length
			+ pixelcol.x * (hold.img_help.bits_per_pixel / 8);
		color = *(unsigned int *)(hold.img_help.addr + color);
		my_mlx_pixel_put(&hold.img, x, i, color);
		i++;
	}
}

void	render_walls_3d(t_holder hold)
{
	double	p_to_proj_plane;
	double	wall_height;
	double	distance;
	double	save;
	int		i;

	i = 0;
	while (i < hold.num_rays)
	{
		if (hold.dir[i].hit_info.vert_hit)
			distance = (double)(hold.dir[i].hit_info.vert_point.distance);
		else
			distance = (double)(hold.dir[i].hit_info.horz_point.distance);
		save = hold.data.angle - hold.dir[i].hit_info.angle;
		distance *= cos(save);
		p_to_proj_plane = (WIN_WIDTH / 2) / tan(M_PI / 6);
		wall_height = (BOX_SIZE / distance) * p_to_proj_plane;
		draw_wall_strip(hold, hold.dir[i].hit_info, wall_height, i);
		i++;
	}
}
