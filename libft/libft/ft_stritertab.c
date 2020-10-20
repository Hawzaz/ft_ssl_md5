/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stritertab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmellon <bmellon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 23:55:12 by bmellon           #+#    #+#             */
/*   Updated: 2018/05/12 18:40:08 by bmellon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_stritertab(char **tab, int (*f)(char *))
{
	int i;

	i = 0;
	if (tab == NULL || f == NULL)
		return (0);
	while (tab[i])
	{
		if (f(tab[i]) != 1)
			return (0);
		i++;
	}
	return (1);
}
