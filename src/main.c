/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrihorc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 16:04:32 by chrihorc          #+#    #+#             */
/*   Updated: 2017/02/12 17:18:34 by chrihorc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	err(void)
{
	ft_putstr("error\n");
	exit(EXIT_FAILURE);
}

void	next(char **tetris, int count)
{
	if (!hash_count(tetris))
		err();
	if (!check_fig(tetris, 0))
		err();
	else
		tetris = check_fig(tetris, 0);
	hash_to_chr(tetris, 0, 0);
	fillit(tetris, count);
}

int		main(int argc, char **argv)
{
	int		fd;
	int		count;
	int		bytes;
	char	**tetris;
	char	*buff;

	if (argc != 2)
	{
		ft_putstr("usage: fillit input_file\n");
		exit(0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		err();
	buff = (char*)malloc(BUFF_SIZE + 1);
	bytes = read(fd, buff, BUFF_SIZE + 1);
	if (bytes == -1)
		err();
	buff[bytes] = '\0';
	if (!(count = count_tetris(buff, 0, 0, 0)) || 
			(buff[21 * count - 2] != '\n') || buff[21 * count - 1] != '\0')
		err();
	tetris = convert_tetris(buff, count, 0, 0);
	next(tetris, count);
	return (0);
}
