/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araqioui <araqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 17:48:02 by fraqioui          #+#    #+#             */
/*   Updated: 2023/06/03 14:48:22 by araqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

int	strlen_nl(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

char	*ft_strdup_(const char *s)
{
	char	*arr;
	size_t	n;
	int		i;

	n = strlen_nl((char *)s);
	i = 0;
	arr = malloc(sizeof(char) * (n + 1));
	if (!arr)
		return (NULL);
	while (n--)
	{
		arr[i] = s[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}
