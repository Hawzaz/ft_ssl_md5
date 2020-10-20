/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmellon <bmellon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 14:53:11 by bmellon           #+#    #+#             */
/*   Updated: 2018/04/16 16:45:25 by bmellon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned long	i;
	char			*dest;
	char			*source;

	i = 0;
	dest = (char *)dst;
	source = (char *)src;
	if (source > dest)
	{
		while (i < len)
		{
			dest[i] = source[i];
			i++;
		}
	}
	else
	{
		while (i < len)
		{
			dest[len - i - 1] = source[len - i - 1];
			i++;
		}
	}
	return (dst);
}
