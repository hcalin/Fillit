/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrihorc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 23:12:53 by chrihorc          #+#    #+#             */
/*   Updated: 2017/02/12 16:34:22 by chrihorc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**new_square(int sz)
{
	int		i;
	int		j;
	char	**sq;

	i = -1;
	if (!(sq = (char **)malloc(sizeof(char*) * sz + 2)))
		return (NULL);
	sq[sz] = NULL;
	while (++i < sz)
	{
		if (!(sq[i] = (char*)malloc(sizeof(char) * sz + 2)))
			return (NULL);
		sq[i][sz] = '\0';
	}
	i = -1;
	while (++i < sz)
	{
		j = 0;
		while (j < sz)
		{
			sq[i][j] = '.';
			j++;
		}
	}
	return (sq);
}

void	free_square(char **square)
{
	int		i;

	i = 0;
	while (square[i])
	{
		free(square[i]);
		i++;
	}
	free(square);
}

void	show_square(char **square)
{
	int i;

	i = 0;
	while (square[i])
	{
		ft_putendl(square[i]);
		i++;
	}
}
