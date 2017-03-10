/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrihorc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 21:22:29 by chrihorc          #+#    #+#             */
/*   Updated: 2017/01/07 19:28:55 by chrihorc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	while ((unsigned char)s1[i] == (unsigned char)s2[i] &&
			(unsigned char)s1[i] != '\0' && (unsigned char)s2[i] != '\0'
			&& i < n)
		i++;
	if (i == n)
		i--;
	return (s1[i] - s2[i]);
}
