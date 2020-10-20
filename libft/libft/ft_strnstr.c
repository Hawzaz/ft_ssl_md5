/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmellon <bmellon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 19:22:29 by bmellon           #+#    #+#             */
/*   Updated: 2018/04/24 04:12:45 by bmellon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	char	*str;
	char	*to_find;
	size_t	i;
	size_t	j;

	to_find = (char *)needle;
	str = (char *)haystack;
	i = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i] && i < n)
	{
		if (str[i] == to_find[0])
		{
			j = 1;
			while ((str[i + j] == to_find[j]) && to_find[j] && (i + j < n))
				j++;
			if (to_find[j] == '\0')
				return (&str[i]);
		}
		i++;
	}
	return (NULL);
}
