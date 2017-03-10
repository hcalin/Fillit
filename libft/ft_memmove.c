/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrihorc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 19:07:07 by chrihorc          #+#    #+#             */
/*   Updated: 2017/01/09 19:07:09 by chrihorc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char str[n];

	if (!dest && !src)
		return (0);
	ft_memcpy(str, src, n);
	ft_memcpy(dest, str, n);
	return (dest);
}
