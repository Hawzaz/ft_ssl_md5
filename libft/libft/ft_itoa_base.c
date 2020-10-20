/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmellon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 12:46:54 by bmellon           #+#    #+#             */
/*   Updated: 2019/08/23 00:12:30 by bmellon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		nblen_base(intmax_t nb, intmax_t base)
{
	int	i;

	i = 1;
	while (nb >= base)
	{
		i++;
		nb /= base;
	}
	return (i);
}

char	*convert_base(intmax_t nb, intmax_t base, intmax_t i)
{
	char			*res;
	static	char	tab[6] = {'a', 'b', 'c', 'd', 'e', 'f'};

	if (!(res = malloc(i + 1)))
		return (NULL);
	res[i--] = '\0';
	while (nb >= base)
	{
		if ((nb % base) >= 10)
			res[i--] = tab[(nb % base) - 10];
		else
			res[i--] = (nb % base) + 48;
		nb /= base;
	}
	if ((nb % base) >= 10)
		res[i--] = tab[(nb % base) - 10];
	else
		res[i--] = (nb % base) + 48;
	return (res);
}

char	*ft_itoa_base(intmax_t nb, intmax_t base)
{
	intmax_t	i;

	if (base == 10)
		return (ft_itoa(nb));
	i = nblen_base(nb, base);
	return (convert_base(nb, base, i));
}
