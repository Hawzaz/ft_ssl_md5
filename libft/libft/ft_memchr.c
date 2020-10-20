/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmellon <bmellon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 15:04:45 by bmellon           #+#    #+#             */
/*   Updated: 2018/04/16 16:48:39 by bmellon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int				i;
	unsigned char	*src;

	i = 0;
	src = (unsigned char *)s;
	while (n--)
	{
		if (src[i] == (unsigned char)c)
			return (void *)(src + i);
		i++;
	}
	return (NULL);
}
