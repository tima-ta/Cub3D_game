/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 18:14:22 by fraqioui          #+#    #+#             */
/*   Updated: 2023/06/03 09:35:32 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void	_print_err(void)
{
	ft_putstr_fd("Error\nCorrect usage of rgb: ", 2);
	ft_putstr_fd("[0,255],[0,255],[0,255]\n", 2);
}

int	ft_atoi(const char *s)
{
	int	res;

	res = 0;
	if (*s == '-' || *s == '+')
		return (_print_err(), -1);
	while (*s >= '0' && *s <= '9')
		res = res * 10 + (*s++ - 48);
	if (*s && (!(*s >= '0' && *s <= '9')))
		return (_print_err(), -1);
	if (res > 255)
		return (_print_err(), -1);
	return (res);
}
