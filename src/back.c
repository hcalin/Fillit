/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrihorc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 22:33:35 by chrihorc          #+#    #+#             */
/*   Updated: 2017/02/12 18:15:09 by chrihorc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		rad(int x)
{
	int i;

	i = 2;
	while (i * i < x)
	{
		i++;
	}
	return (i);
}

int		sq_cnt(char **mat)
{
	int z;

	z = 0;
	while (mat[z])
		z++;
	return (z);
}

void	fillit(char **tetris, int count)
{
	char	**square;
	int		sz;

	sz = rad(count * 4);
	square = new_square(sz);
	while (back(tetris, square, 0, -1) == 0)
	{
		sz++;
		free_square(square);
		square = new_square(sz);
	}
	show_square(square);
}

void	hash_to_chr(char **tetris, int i, int j)
{
	char	x;

	x = 'A';
	while (tetris[i] != '\0')
	{
		while (tetris[i][j] != '\0')
		{
			if (tetris[i][j] == '#')
				tetris[i][j] = x;
			j++;
		}
		j = 0;
		x++;
		i++;
	}
	if (x > 'Z')
		err();
}

int		back(char **tetris, char **square, int i, int y)
{
	int		x;
	char	*s;

	if (!tetris[i])
		return (1);
	s = tetris[i];
	while (++y < sq_cnt(square))
	{
		x = -1;
		while (++x < sq_cnt(square))
		{
			if (verif(square, s, y, x) == 1)
			{
				square = add_tetris(square, s, y, x);
				if (back(tetris, square, i + 1, -1) == 1)
					return (1);
				else
					square = rm_tetris(square, s, 0, 0);
			}
		}
	}
	return (0);
}
