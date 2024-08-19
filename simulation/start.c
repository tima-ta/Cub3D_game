/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araqioui <araqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 09:48:08 by fraqioui          #+#    #+#             */
/*   Updated: 2023/06/26 10:32:35 by araqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../headers/cub3d.h"

void	calc(t_holder *holder)
{
	int	i;
	int	j;
	int	width;

	i = 0;
	j = 0;
	width = 0;
	while (holder->data.map[i])
	{
		j = ft_strlen(holder->data.map[i]);
		if (width < j)
			width = j;
		i++;
	}
	holder->height = i;
	holder->width = width;
	holder->num_rays = WIN_WIDTH;
}

int	ft_close(void *param)
{
	t_holder	*hold;

	hold = (t_holder *)param;
	if (hold->dir)
		free(hold->dir);
	data_free(&hold->data);
	mlx_destroy_window(hold->mlx, hold->win);
	exit(EXIT_FAILURE);
}

static void	get_angle(t_info *data)
{
	if (data->dir == 'N')
		data->angle = (3 * M_PI) / 2;
	else if (data->dir == 'S')
		data->angle = M_PI / 2;
	else if (data->dir == 'E')
		data->angle = 0;
	else
		data->angle = M_PI;
}

static void	texel(t_holder *hold)
{
	int	i;
	int	j;

	hold->no.img = mlx_xpm_file_to_image(hold->mlx, hold->data.no, &i, &j);
	hold->so.img = mlx_xpm_file_to_image(hold->mlx, hold->data.so, &i, &j);
	hold->we.img = mlx_xpm_file_to_image(hold->mlx, hold->data.we, &i, &j);
	hold->ea.img = mlx_xpm_file_to_image(hold->mlx, hold->data.ea, &i, &j);
	if (!hold->no.img || !hold->so.img || !hold->we.img || !hold->ea.img)
	{
		ft_putstr_fd("Error\nInvalid texture\n", 2);
		ft_close(hold);
	}
	hold->no.addr = mlx_get_data_addr(hold->no.img, &hold->no.bits_per_pixel,
			&hold->no.line_length, &hold->no.endian);
	hold->so.addr = mlx_get_data_addr(hold->so.img,
			&hold->so.bits_per_pixel, &hold->so.line_length, &hold->so.endian);
	hold->we.addr = mlx_get_data_addr(hold->we.img,
			&hold->we.bits_per_pixel, &hold->we.line_length, &hold->we.endian);
	hold->ea.addr = mlx_get_data_addr(hold->ea.img,
			&hold->ea.bits_per_pixel, &hold->ea.line_length, &hold->ea.endian);
}

int	simulation(t_info data)
{
	t_holder	holder;

	holder.data = data;
	calc(&holder);
	holder.dir = malloc(sizeof(t_direction) * holder.num_rays);
	if (!holder.dir)
		return (ft_putstr_fd("Error\nAllocation failure\n", 2), 0);
	get_angle(&holder.data);
	holder.mlx = mlx_init();
	if (!holder.mlx)
		return (ft_putstr_fd("Error\nInitialize mlx\n", 2), 0);
	holder.win = mlx_new_window(holder.mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	if (!holder.win)
		return (ft_putstr_fd("Error\nNew window\n", 2), 0);
	holder.img.img = mlx_new_image(holder.mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!holder.img.img)
		return (ft_putstr_fd("Error\nNew image\n", 2), 0);
	holder.img.addr = mlx_get_data_addr(holder.img.img,
			&holder.img.bits_per_pixel, &holder.img.line_length,
			&holder.img.endian);
	texel(&holder);
	mini_map(holder);
	mlx_hook(holder.win, 2, 0, move_player, &holder);
	mlx_hook(holder.win, 17, 0, ft_close, &holder);
	return (mlx_loop(holder.mlx), 1);
}
