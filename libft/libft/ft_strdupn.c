/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdupn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmellon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 10:25:32 by bmellon           #+#    #+#             */
/*   Updated: 2019/08/22 20:11:20 by bmellon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdupn(const char *s1, int ind)
{
	int		i;
	char	*dst;

	if (!s1 || ind < 0)
		return (NULL);
	i = 0;
	dst = ft_memalloc(ft_strlen(s1) - ind + 1);
	while (s1[ind])
	{
		dst[i] = s1[ind];
		i++;
		ind++;
	}
	dst[i] = '\0';
	return (dst);
}
