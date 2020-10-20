/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmellon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 12:58:05 by bmellon           #+#    #+#             */
/*   Updated: 2019/09/07 18:39:50 by bmellon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	get_args(t_printf *pt)
{
	if (ft_strequ(pt->con, "%d") || ft_strequ(pt->con, "%i") ||
			ft_strequ(pt->con, "%c"))
		pt->num = va_arg(pt->lst, intmax_t);
	else if (ft_strequ(pt->con, "%u") || ft_strequ(pt->con, "%o") ||
			ft_strequ(pt->con, "%x") || ft_strequ(pt->con, "%X"))
		pt->unum = va_arg(pt->lst, uintmax_t);
	else if (ft_strequ(pt->con, "%s"))
		pt->res = va_arg(pt->lst, char *);
	else if (ft_strequ(pt->con, "%p"))
		pt->ptr = va_arg(pt->lst, void *);
}

int		ft_precision(t_printf *pt, int i)
{
	int nbprec;

	i++;
	nbprec = 0;
	while (pt->str[i] && ft_isnum(pt->str[i]))
	{
		nbprec *= 10;
		nbprec += (int)pt->str[i] - 48;
		i++;
	}
	pt->prec = nbprec;
	i--;
	return (i);
}

char	pt_events(t_printf *pt, int size)
{
	char		car;

	if (pt->flags.flag_s && (int)pt->num >= 0 && !ft_strequ(pt->con, "%p") &&
			!ft_strequ(pt->con, "%s") && !ft_strequ(pt->con, "%c") &&
				!ft_strequ(pt->con, "%%") &&
					((pt->nb >= 0 && pt->flags.flag_z) || pt->nb == 0))
	{
		ft_putchar(' ');
		pt->ret++;
		pt->nb--;
	}
	if (pt->flags.flag_m == 1 ||
			(ft_strequ("%d", pt->con) && (pt->nb > pt->prec) &&
				pt->flags.flag_d))
		pt->flags.flag_z = 0;
	pt->nb -= size;
	if ((int)pt->num < 0 && (pt->prec > ft_nbrlen((int)pt->num)))
		pt->nb -= 1;
	if (pt->nb < 0)
		pt->nb = 0;
	if (pt->flags.flag_z == 1 && pt->flags.flag_d == 0)
		car = '0';
	else
		car = ' ';
	return (car);
}

int		arg_size(t_printf *pt)
{
	int	size;

	if (ft_strequ(pt->con, "%s"))
		size = ft_strlen(pt->res);
	else if (ft_strequ(pt->con, "%u"))
		size = ft_nbrulen(pt->unum, 10);
	else if (ft_strequ(pt->con, "%o"))
		size = ft_nbrulen(pt->unum, 8);
	else if (ft_strequ(pt->con, "%x") || ft_strequ(pt->con, "%X"))
		size = ft_nbrulen(pt->unum, 16);
	else if (ft_strequ(pt->con, "%p"))
		size = ft_nbrulen((uintmax_t)pt->ptr, 16) + 2;
	else if (ft_strequ(pt->con, "%c"))
		size = 1;
	else
		size = ft_nbrlen((int)pt->num);
	if (pt->flags.flag_d && !ft_strequ(pt->con, "%s"))
	{
		if (pt->prec > size)
			size = pt->prec;
	}
	else if (pt->flags.flag_d && ft_strequ(pt->con, "%s"))
		if (pt->prec < size)
			size = pt->prec;
	return (size);
}

int		handle_flag_sz(t_printf *pt)
{
	int		size;
	char	car;

	size = arg_size(pt);
	car = pt_events(pt, size);
	size = 0;
	flag_m(pt, car);
	if (pt->nb > 0)
	{
		pt->sp = ft_memalloc(pt->nb + 1);
		while (pt->nb-- > 0)
			pt->sp[size++] = car;
		pt->sp[size] = '\0';
		if ((pt->flags.flag_m == 0 && pt->flags.flag_h == 0) ||
				(pt->flags.flag_h == 1 && pt->flags.flag_s == 1 &&
					pt->flags.flag_m == 0))
		{
			ft_putstr(pt->sp);
			pt->ret += ft_strlen(pt->sp);
			ft_strdel(&pt->sp);
		}
	}
	after_flag_m(pt, car);
	return (1);
}
