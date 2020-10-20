/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmellon <bmellon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 18:47:13 by bmellon           #+#    #+#             */
/*   Updated: 2018/04/26 00:02:38 by bmellon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_revstr(char *str)
{
	int i;
	int j;
	int tmp;

	i = 0;
	j = 0;
	while (str[j] != '\0')
		j++;
	j--;
	while (i < j)
	{
		tmp = str[i];
		str[i++] = str[j];
		str[j--] = tmp;
	}
	return (str);
}
