/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmellon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 15:30:58 by bmellon           #+#    #+#             */
/*   Updated: 2019/07/16 22:09:40 by bmellon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcstr(const char *haystack, const char *needle, char c)
{
	char	*str;
	char	*to_find;
	size_t	i;
	size_t	j;

	to_find = (char *)needle;
	str = (char *)haystack;
	i = 0;
	if (to_find[0] == '\0' || (!c))
		return (0);
	while (str[i] && (str[i] != c))
	{
		if (str[i] == to_find[0])
		{
			j = 1;
			while ((str[i + j] == to_find[j]) && to_find[j]
					&& (str[i + j] != c))
				j++;
			if ((to_find[j] == '\0') && (str[i + j] == c))
				return (1);
		}
		i++;
	}
	return (0);
}
