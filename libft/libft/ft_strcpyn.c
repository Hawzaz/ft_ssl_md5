/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpyn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmellon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 10:07:41 by bmellon           #+#    #+#             */
/*   Updated: 2019/07/29 17:46:56 by bmellon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpyn(char *dst, const char *src, size_t len)
{
	int i;

	i = 0;
	if ((src == NULL) || (dst = NULL))
		return (NULL);
	while (src[len] && dst[i])
	{
		dst[i] = src[len];
		i++;
		len++;
	}
	dst[i] = '\0';
	return (dst);
}
