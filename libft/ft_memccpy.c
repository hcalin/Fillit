/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrihorc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 19:06:46 by chrihorc          #+#    #+#             */
/*   Updated: 2017/01/09 19:06:49 by chrihorc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char		*d;
	const char	*s;

	d = dest;
	s = src;
	if (!dest || !src)
		return (0);
	while (n--)
	{
		if ((*d++ = *s++) == c)
			return (d);
	}
	return (0);
}
