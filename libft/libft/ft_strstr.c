/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmellon <bmellon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 16:48:06 by bmellon           #+#    #+#             */
/*   Updated: 2019/07/30 14:21:22 by bmellon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*str;
	char	*to_find;
	int		i;
	int		j;

	if (!haystack || !needle)
		return (NULL);
	to_find = (char *)needle;
	str = (char *)haystack;
	i = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i])
	{
		if (str[i] == to_find[0])
		{
			j = 1;
			while ((str[i + j] == to_find[j]) && to_find[j])
				j++;
			if (to_find[j] == '\0')
				return (&str[i]);
		}
		i++;
	}
	return (NULL);
}
