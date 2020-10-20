/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmellon <bmellon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 14:26:52 by bmellon           #+#    #+#             */
/*   Updated: 2018/04/09 14:16:02 by bmellon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	char				*d;
	const char			*s;
	size_t				i;
	size_t				dlen;

	d = dst;
	s = src;
	i = size;
	while (i-- && *d)
		d++;
	dlen = d - dst;
	i = size - dlen;
	if (i == 0)
		return (dlen + ft_strlen(s));
	while (*s)
	{
		if (i != 1)
		{
			*d++ = *s;
			i--;
		}
		s++;
	}
	*d = '\0';
	return (dlen + (s - src));
}
