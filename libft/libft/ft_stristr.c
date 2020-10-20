/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stristr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmellon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 11:33:20 by bmellon           #+#    #+#             */
/*   Updated: 2019/04/16 12:32:29 by bmellon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_stristr(const char *haystack, const char *needle)
{
	char	*str;
	char	*to_find;
	int		i;
	int		j;

	to_find = (char *)needle;
	str = (char *)haystack;
	i = 0;
	if (to_find[0] == '\0')
		return (-1);
	while (str[i])
	{
		if (str[i] == to_find[0])
		{
			j = 1;
			while ((str[i + j] == to_find[j]) && to_find[j])
				j++;
			if (to_find[j] == '\0')
				return (i);
		}
		i++;
	}
	return (-1);
}
