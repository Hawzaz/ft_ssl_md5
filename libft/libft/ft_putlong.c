/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlong.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmellon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 14:08:15 by bmellon           #+#    #+#             */
/*   Updated: 2019/08/16 16:57:40 by bmellon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putlong(long nb)
{
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putlong(214748364);
		ft_putlong(8);
		return ;
	}
	if (nb < 0)
	{
		nb = -nb;
		ft_putchar('-');
	}
	if (nb >= 10)
		ft_putlong(nb / 10);
	ft_putchar(nb % 10 + 48);
}
