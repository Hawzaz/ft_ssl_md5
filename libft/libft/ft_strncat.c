/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmellon <bmellon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 14:01:56 by bmellon           #+#    #+#             */
/*   Updated: 2018/04/16 16:46:34 by bmellon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strncat(char *dst, char *src, size_t n)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (dst[i])
		i++;
	while (n > 0 && src[j])
	{
		dst[i] = src[j];
		n--;
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dst);
}
