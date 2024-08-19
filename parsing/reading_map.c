/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraqioui <fraqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 14:08:08 by araqioui          #+#    #+#             */
/*   Updated: 2023/06/03 09:34:12 by fraqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

static int	file_len(int fd)
{
	int		len;
	char	*s;

	len = 0;
	while (1)
	{
		s = get_next_line(fd);
		if (!s)
			break ;
		free(s);
		len++;
	}
	return (len);
}

static char	**read_file(int len, int fd)
{
	char	*s;
	char	**ret;
	char	**save;

	ret = malloc(sizeof(char *) * (len + 1));
	if (!ret)
		return (ft_putstr_fd("Error\nAllocation failed\n", 2), NULL);
	save = ret;
	while (1)
	{
		s = get_next_line(fd);
		*ret++ = s;
		if (!s)
			break ;
	}
	return (close(fd), save);
}

char	**reading_map(char *file)
{
	int		len;
	int		fd;

	len = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (ft_putstr_fd("Error\n", 2), perror(""), NULL);
	len = file_len(fd);
	if (!len)
		return (ft_putstr_fd("Error\nEmpty file\n", 2), NULL);
	close(fd);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (ft_putstr_fd("Error\n", 2), perror(""), NULL);
	return (read_file(len, fd));
}
