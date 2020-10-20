/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_fcts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmellon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 13:02:14 by bmellon           #+#    #+#             */
/*   Updated: 2019/08/30 16:53:32 by bmellon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	hash_three(t_printf *pt)
{
	if (pt->flags.flag_h == 1 && pt->flags.flag_z == 1 && pt->flags.flag_d == 0)
	{
		ft_putstr(pt->sp);
		pt->ret += ft_strlen(pt->sp);
		ft_strdel(&pt->sp);
	}
	if (pt->flags.flag_p == 1 && (int)pt->num >= 0 && pt->flags.flag_z == 0 &&
			(ft_strequ(pt->con, "%d") || ft_strequ(pt->con, "%i")))
	{
		ft_putchar('+');
		pt->ret++;
		pt->nb--;
	}
}
