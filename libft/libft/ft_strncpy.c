/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmellon <bmellon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 17:58:16 by bmellon           #+#    #+#             */
/*   Updated: 2018/04/16 16:46:41 by bmellon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	int i;

	i = 0;
	while (src[i] && (len > 0))
	{
		dst[i] = src[i];
		len--;
		i++;
	}
	while (len > 0)
	{
		dst[i] = '\0';
		len--;
		i++;
	}
	return (dst);
}
