/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmellon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 15:32:09 by bmellon           #+#    #+#             */
/*   Updated: 2019/05/07 18:53:31 by bmellon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, int ind)
{
	int		i;
	char	*dst;

	if (s1 == NULL)
		return (NULL);
	i = 0;
	if (!(dst = ft_memalloc(ind + 1)))
		return (NULL);
	while (i < ind)
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
