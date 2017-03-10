/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrihorc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 19:38:07 by chrihorc          #+#    #+#             */
/*   Updated: 2017/02/12 16:53:30 by chrihorc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define BUFF_SIZE 4096

int		count_tetris(char *buff,int i, int j, int lines);
char	**convert_tetris(char *buf,int cnt, int i, int lines);
char	*found_fig(char **figure, char *mat);
char	**check_fig(char **mat, int i);
int		hash_count(char **mat);
void	fillit(char **tetris,int count);
int		rad(int x);
char	**new_square(int sz);
void	free_square(char **square);
void	show_square(char **square);
int		verif(char **square, char *str, int x, int y);
char	**add_tetris(char **square, char *str, int x, int y);
char	**rm_tetris(char **square, char *str, int x, int y);
int		sq_cnt(char **mat);
int		back(char **tetris, char **square, int i, int y);
void	err(void);
char	**make_fig(char **figure);
void	hash_to_chr(char **tetris, int i, int j);
#endif
