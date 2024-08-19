/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araqioui <araqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 14:33:45 by araqioui          #+#    #+#             */
/*   Updated: 2023/06/25 10:42:25 by araqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

int	map__name(char *str)
{
	int	i;

	i = ft_strlen(str);
	if (i <= 4 || str[i - 1] != 'b' || str[i - 2] != 'u'
		|| str[i - 3] != 'c' || str[i - 4] != '.')
		return (ft_putstr_fd("Error\nInvalid file extension\n", 2), 0);
	return (1);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
		write(fd, s++, 1);
}

void	data_init(t_info *data)
{
	data->no = NULL;
	data->so = NULL;
	data->we = NULL;
	data->ea = NULL;
	data->map = NULL;
	data->floor[0] = -1;
	data->ceiling[0] = -1;
}

void	data_free(t_info *data)
{
	if (data->so)
		(free(data->so), data->so = NULL);
	if (data->no)
		(free(data->no), data->no = NULL);
	if (data->we)
		(free(data->we), data->we = NULL);
	if (data->ea)
		(free(data->ea), data->ea = NULL);
	if (data->map)
		(free_2d(data->map), data->map = NULL);
}

int	check_spc(char *s)
{
	while (*s == ' ')
		s++;
	if (*s)
		return (0);
	return (1);
}
