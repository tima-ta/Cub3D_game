/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araqioui <araqioui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 15:53:27 by fraqioui          #+#    #+#             */
/*   Updated: 2023/06/04 14:35:15 by araqioui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

char	**free_2d(char **arr)
{
	unsigned int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
	return (NULL);
}

static int	ft_words(const char *s2, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (s2[i])
	{
		if (s2[i] == c)
			i++;
		else
		{
			word++;
			while (s2[i] != c && s2[i])
				i++;
		}
	}
	return (word);
}

static char	*ft_fillout(const char *s1, int *j, char c)
{
	char	*new;
	size_t	len;
	int		i;

	len = 0;
	while (s1[*j] == c)
		(*j)++;
	i = *j;
	while (s1[i] && s1[i] != c)
	{
		len++;
		i++;
	}
	new = malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (s1[*j] && s1[*j] != c)
		new[i++] = s1[(*j)++];
	new[i] = '\0';
	return (new);
}

static bool	check_elements(char *s, char **tab, int n, int *flg)
{
	if (!n)
	{
		if (!*tab || check_spc(s))
			return (*flg = 0, 1);
	}
	if (n == 2)
		return (1);
	ft_putstr_fd("Error\nCorrect Usage of elements syntax: ", 2);
	ft_putstr_fd("Identifier followed by its information\n", 2);
	return (0);
}

char	**ft_split(char const *s, char c, int *flg, int flg_0)
{
	char	**t_arr;
	int		i;
	int		wc;
	int		j;

	i = 0;
	j = -1;
	if (!s)
		return (NULL);
	wc = ft_words(s, c);
	t_arr = malloc(sizeof(char *) * (wc + 1));
	if (!t_arr)
		return (ft_putstr_fd("Error\nAllocation failed\n", 2), NULL);
	while (++j < wc)
	{
		t_arr[j] = ft_fillout(s, &i, c);
		if (!t_arr[j])
			return (ft_putstr_fd("Error\nAllocation failed\n", 2),
				free_2d(t_arr));
	}
	t_arr[j] = 0;
	if (flg_0)
		if (!check_elements((char *)s, t_arr, wc, flg))
			return (free_2d(t_arr), NULL);
	return (t_arr);
}
