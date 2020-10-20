/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmellon <bmellon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 20:42:42 by bmellon           #+#    #+#             */
/*   Updated: 2018/04/20 20:32:31 by bmellon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (s1 == NULL || s2 == NULL)
		return (0);
	while ((s1[i] == s2[i]) && s1[i] && --n)
		i++;
	if (s1[i] == s2[i])
		return (1);
	return (0);
}
