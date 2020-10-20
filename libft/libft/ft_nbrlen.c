/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmellon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 01:10:07 by bmellon           #+#    #+#             */
/*   Updated: 2019/08/24 19:08:25 by bmellon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		ft_nbrlen(intmax_t nb)
{
	int			cpt;
	uintmax_t	n;

	cpt = 1;
	n = nb;
	if (nb < 0)
	{
		n = -nb;
		cpt++;
	}
	while (n >= 10)
	{
		n /= 10;
		cpt++;
	}
	return (cpt);
}
