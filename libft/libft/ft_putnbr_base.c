/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmellon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 22:03:02 by bmellon           #+#    #+#             */
/*   Updated: 2019/08/27 20:26:27 by bmellon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_putnbr_basebis(uintmax_t n, char *base, size_t len)
{
	uintmax_t	nb;

	nb = n;
	if (nb >= len)
	{
		ft_putnbr_basebis(n / len, base, len);
		ft_putnbr_basebis(n % len, base, len);
	}
	else
		ft_putchar_fd(base[nb], 1);
}

void			ft_putnbr_base(uintmax_t n, char *base)
{
	ft_putnbr_basebis(n, base, ft_strlen(base));
}
