/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fcts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmellon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 19:46:55 by bmellon           #+#    #+#             */
/*   Updated: 2019/09/07 18:55:34 by bmellon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	handle_hash(t_printf *pt)
{
	if (pt->flags.flag_h == 1)
	{
		if (ft_strequ(pt->con, "%X") && (int)pt->unum != 0)
		{
			ft_putstr("0X");
			pt->ret += 2;
			pt->nb -= 2;
		}
		else if (ft_strequ(pt->con, "%x") && (int)pt->unum != 0)
		{
			ft_putstr("0x");
			pt->ret += 2;
			pt->nb -= 2;
		}
		else if (ft_strequ(pt->con, "%o") && (int)pt->unum != 0 &&
				pt->prec == 0)
		{
			ft_putchar('0');
			pt->ret++;
			pt->nb--;
		}
	}
	hash_three(pt);
}

void	flag_m(t_printf *pt, char car)
{
	if ((int)pt->num < 0 && car == '0')
	{
		ft_putchar('-');
		pt->num = -pt->num;
		pt->ret++;
	}
	if ((int)pt->num < 0 && pt->flags.flag_d == 1 && car == ' ' &&
			pt->nb < pt->prec)
		pt->nb--;
}

void	after_flag_m(t_printf *pt, char car)
{
	if ((int)pt->num < 0 && pt->flags.flag_d == 1 && car == ' ')
	{
		ft_putchar('-');
		pt->num = -pt->num;
		pt->ret++;
	}
}

int		act_prec(t_printf *pt, int i)
{
	pt->flags.flag_d = 1;
	if (ft_isnum(pt->str[i + 1]) && pt->str[i + 1] != 0)
		i = ft_precision(pt, i);
	else
		pt->prec = 0;
	return (i);
}

void	hash_two(t_printf *pt)
{
	if (pt->flags.flag_h == 1)
	{
		if (ft_strequ(pt->con, "%X") && (int)pt->unum != 0)
			pt->nb -= 2;
		else if (ft_strequ(pt->con, "%x") && (int)pt->unum != 0)
			pt->nb -= 2;
		else if (ft_strequ(pt->con, "%o") && (int)pt->unum != 0)
			pt->nb--;
	}
	if (pt->flags.flag_p == 1 && (int)pt->num >= 0 && pt->flags.flag_z == 1 &&
			(ft_strequ(pt->con, "%d") || ft_strequ(pt->con, "%i")))
	{
		ft_putchar('+');
		pt->ret++;
		pt->nb--;
	}
	if (pt->flags.flag_p == 1 && (int)pt->num >= 0 && pt->flags.flag_z == 0 &&
			(ft_strequ(pt->con, "%d") || ft_strequ(pt->con, "%i")))
		pt->nb--;
}
