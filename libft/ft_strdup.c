/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrihorc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 19:07:52 by chrihorc          #+#    #+#             */
/*   Updated: 2017/01/09 19:11:00 by chrihorc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		len;
	char	*dup;

	if (!s)
		return (0);
	len = ft_strlen(s);
	dup = (char*)malloc(sizeof(*dup) * (len + 1));
	if (!dup)
		return (0);
	ft_strcpy(dup, s);
	return (dup);
	free(dup);
}
