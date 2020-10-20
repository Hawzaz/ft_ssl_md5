/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmellon <bmellon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 22:47:17 by bmellon           #+#    #+#             */
/*   Updated: 2018/04/21 15:06:44 by bmellon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	int		i;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	if ((str = malloc(sizeof(char) * i + 1)) == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (f((char)s[i]))
			str[i] = f((char)s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
