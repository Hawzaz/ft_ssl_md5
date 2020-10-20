/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmellon <bmellon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 00:04:40 by bmellon           #+#    #+#             */
/*   Updated: 2019/07/21 19:27:22 by bmellon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_revsplit(char **tab)
{
	char	*str;
	int		cmp;
	int		i;

	cmp = 0;
	i = 0;
	while (tab[i])
		cmp += ft_strlen(tab[i++]);
	if (!(str = ft_memalloc((cmp + (i - 1)))))
		return (NULL);
	while (*tab)
		str = ft_strjoin(str, *tab++, 1);
	return (str);
}
