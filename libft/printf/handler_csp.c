/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_csp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmellon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 17:10:56 by bmellon           #+#    #+#             */
/*   Updated: 2019/09/07 19:09:01 by bmellon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		handle_c(t_printf *pt)
{
	pt->num = (int)pt->num;
	ft_putchar((char)pt->num);
	pt->ret += 1;
	return (1);
}

void	s_prec(t_printf *pt)
{
	int		i;
	int		prec;

	prec = pt->prec;
	if ((int)ft_strlen(pt->res) > pt->prec)
		pt->ret += pt->prec;
	if (pt->res == NULL)
		pt->res = "(null)";
	i = 0;
	while (pt->res[i] && prec > 0)
	{
		ft_putchar(pt->res[i++]);
		prec--;
		if ((int)ft_strlen(pt->res) < pt->prec)
			pt->ret++;
	}
}

int		handle_s(t_printf *pt)
{
	if (pt->res == NULL)
		pt->res = "(null)";
	if (pt->flags.flag_d == 1)
	{
		s_prec(pt);
		return (1);
	}
	ft_putstr(pt->res);
	pt->ret += ft_strlen(pt->res);
	return (1);
}

int		handle_p(t_printf *pt)
{
	pt->unum = (uintmax_t)pt->ptr;
	ft_putstr("0x");
	pt->ret += 2;
	handle_x(pt);
	return (1);
}
