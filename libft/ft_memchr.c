/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrihorc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 19:07:21 by chrihorc          #+#    #+#             */
/*   Updated: 2017/01/09 19:07:23 by chrihorc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *p;

	if (!s)
		return (0);
	p = (unsigned char*)s;
	while (n > 0)
	{
		if (*p != (unsigned char)c)
			p++;
		else
			return (p);
		n--;
	}
	return (0);
}
