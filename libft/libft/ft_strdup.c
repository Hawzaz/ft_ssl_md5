/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmellon <bmellon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 17:33:14 by bmellon           #+#    #+#             */
/*   Updated: 2019/04/30 10:26:04 by bmellon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		cmp;
	int		i;
	char	*dst;

	i = 0;
	cmp = 0;
	if (!s1)
		return (NULL);
	while (s1[i++])
		cmp++;
	i = 0;
	if ((dst = malloc(sizeof(char) * cmp + 1)) == NULL)
		return (NULL);
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
