/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmellon <bmellon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 14:53:34 by bmellon           #+#    #+#             */
/*   Updated: 2019/01/11 22:41:41 by bmellon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoinch(char *s1, char *s2, char *ch, int flag)
{
	int		i;
	int		j;
	char	*str;

	if (s1 == NULL || s2 == NULL || ch == NULL)
		return (NULL);
	i = ft_strlen(s1);
	j = 0;
	if ((str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) +
		ft_strlen(ch)) + 1)) == NULL)
		return (NULL);
	ft_strcpy(str, s1);
	while (ch[j])
		str[i++] = ch[j++];
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}
