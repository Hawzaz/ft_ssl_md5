/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_max.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmellon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 23:14:53 by bmellon           #+#    #+#             */
/*   Updated: 2019/08/24 01:01:39 by bmellon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_max(intmax_t nb)
{
	uintmax_t	n;

	n = nb;
	if (nb < 0)
	{
		n = -nb;
		ft_putchar('-');
	}
	if (n >= 10)
	{
		ft_putnbr_max(n / 10);
		ft_putnbr_max(n % 10);
	}
	else
		ft_putchar(n % 10 + 48);
}
