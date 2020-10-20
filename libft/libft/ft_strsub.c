/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmellon <bmellon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 14:37:28 by bmellon           #+#    #+#             */
/*   Updated: 2019/07/20 01:24:37 by bmellon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;

	if (s == NULL)
		return (NULL);
	i = 0;
	if ((str = malloc(sizeof(char) * len + 1)) == NULL)
		return (NULL);
	while (len-- && *s)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}
