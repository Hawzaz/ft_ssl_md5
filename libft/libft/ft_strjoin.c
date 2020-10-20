/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmellon <bmellon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 14:53:34 by bmellon           #+#    #+#             */
/*   Updated: 2019/07/29 17:47:09 by bmellon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	handle_free(char *s1, char *s2, int nb)
{
	if (nb == 1)
		free(s1);
	else if (nb == 2)
		free(s2);
	else if (nb == 3)
	{
		free(s1);
		free(s2);
	}
}

char	*ft_strjoin(char *s1, char *s2, int nb)
{
	int		i;
	int		j;
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	j = 0;
	if (!(str = ft_memalloc(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	handle_free(s1, s2, nb);
	return (str);
}
