/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrihorc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 16:49:12 by chrihorc          #+#    #+#             */
/*   Updated: 2017/02/12 18:15:49 by chrihorc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**make_fig(char **figure)
{
	ft_strcpy(figure[0], "###...#");
	ft_strcpy(figure[1], ".#...#..##");
	ft_strcpy(figure[2], "#...###");
	ft_strcpy(figure[3], "##..#...#");
	ft_strcpy(figure[4], "###.#");
	ft_strcpy(figure[5], "##...#...#");
	ft_strcpy(figure[6], "..#.###");
	ft_strcpy(figure[7], "#...#...##");
	ft_strcpy(figure[8], "###..#");
	ft_strcpy(figure[9], ".#..##...#");
	ft_strcpy(figure[10], ".#..###");
	ft_strcpy(figure[11], "#...##..#");
	ft_strcpy(figure[12], ".##.##");
	ft_strcpy(figure[13], "#...##...#");
	ft_strcpy(figure[14], "##...##");
	ft_strcpy(figure[15], ".#..##..#");
	ft_strcpy(figure[16], "####");
	ft_strcpy(figure[17], "#...#...#...#");
	ft_strcpy(figure[18], "##..##");
	return (figure);
}

int		verif(char **square, char *str, int x, int y)
{
	int		k;

	k = 0;
	while (str[k])
	{
		if (str[k] != '.')
		{
			if ((x + k / 4 >= sq_cnt(square)) || (y + k % 4 >= sq_cnt(square)))
				return (0);
			if (square[x + k / 4][y + k % 4] != '.')
				return (0);
		}
		k++;
	}
	return (1);
}

char	**add_tetris(char **square, char *str, int x, int y)
{
	int	k;

	k = 0;
	while (str[k])
	{
		if (str[k] != '.')
			square[x + k / 4][y + k % 4] = str[k];
		k++;
	}
	return (square);
}

char	**rm_tetris(char **square, char *str, int x, int y)
{
	int		i;

	i = 0;
	while (str[i] == '.')
		i++;
	while (square[x])
	{
		while (square[x][y])
		{
			if (square[x][y] == str[i])
				square[x][y] = '.';
			y++;
		}
		y = 0;
		x++;
	}
	return (square);
}
