/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrihorc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 21:59:28 by chrihorc          #+#    #+#             */
/*   Updated: 2017/02/12 17:20:07 by chrihorc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		count_tetris(char *buff, int i, int j, int lines)
{
	while (buff[++i])
	{
		j++;
		if (j == 4)
		{
			if (buff[i] == '\n')
				i++;
			else
				return (0);
			j = 0;
			lines++;
		}
		if (lines == 4)
		{
			if (buff[i] == '\n' || !buff[i])
				i++;
			else
				return (0);
			lines = 0;
		}
	}
	if (j || lines)
		return (0);
	return (i / 21);
}

char	*found_fig(char **figure, char *mat)
{
	int		i;
	char	*s;

	i = 0;
	while (figure[i])
	{
		if (ft_strstr(mat, figure[i]) && i != 19)
		{
			s = (char*)malloc(30);
			s = ft_strdup(figure[i]);
			return (s);
		}
		i++;
	}
	return (0);
}

int		hash_count(char **mat)
{
	int	i;
	int	j;
	int	cnt;

	cnt = 0;
	i = 0;
	while (mat[i])
	{
		j = 0;
		cnt = 0;
		while (mat[i][j])
		{
			if (mat[i][j] == '#')
				cnt++;
			j++;
		}
		if (cnt != 4)
			return (0);
		i++;
	}
	return (1);
}

char	**check_fig(char **mat, int i)
{
	char	**figure;

	if (!(figure = (char **)malloc(sizeof(char *) * 20)))
		return (0);
	while (i < 20)
	{
		figure[i] = (char*)malloc(sizeof(char) * 14);
		i++;
	}
	figure = make_fig(figure);
	figure[19] = NULL;
	i = 0;
	while (mat[i])
	{
		if (!(mat[i] = found_fig(figure, mat[i])))
			return (0);
		i++;
	}
	return (mat);
}

char	**convert_tetris(char *buf, int cnt, int i, int lines)
{
	char	**mat;
	int		colums;

	colums = 0;
	if (!(mat = (char**)malloc(sizeof(char*) * (cnt + 5))))
		return (0);
	mat[cnt] = NULL;
	while (i < cnt)
	{
		if (!(mat[i++] = (char*)malloc(sizeof(char) * (16 + 1))))
			return (0);
		mat[i - 1][16] = '\0';
	}
	i = -1;
	while (buf[++i])
	{
		if (buf[i] != '\n')
			mat[lines][colums++] = buf[i];
		if (!((i + 1) % 21))
		{
			colums = 0;
			lines++;
		}
	}
	return (mat);
}
