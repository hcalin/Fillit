/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrihorc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 19:02:33 by chrihorc          #+#    #+#             */
/*   Updated: 2017/01/09 19:05:05 by chrihorc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char *dst;
	unsigned char *sr;

	if (!dest || !src)
		return (0);
	dst = (unsigned char *)dest;
	sr = (unsigned char *)src;
	while (n--)
	{
		*dst++ = *sr++;
	}
	return (dest);
}
