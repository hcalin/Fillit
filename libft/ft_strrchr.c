/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrihorc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 19:16:40 by chrihorc          #+#    #+#             */
/*   Updated: 2017/01/09 19:16:41 by chrihorc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	int		len;

	if (!s)
		return (0);
	len = ft_strlen(s);
	while (s[len] != c && 0 <= len)
		len--;
	if (s[len] == (char)c)
		return ((char*)s + len);
	return (NULL);
}
