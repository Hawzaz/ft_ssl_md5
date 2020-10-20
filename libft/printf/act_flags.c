/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmellon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 15:28:34 by bmellon           #+#    #+#             */
/*   Updated: 2019/08/29 00:49:24 by bmellon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	act_z(t_printf *pt)
{
	pt->flags.flag_z = 1;
}

void	act_m(t_printf *pt)
{
	pt->flags.flag_m = 1;
}

void	act_h(t_printf *pt)
{
	pt->flags.flag_h = 1;
}

void	act_p(t_printf *pt)
{
	pt->flags.flag_p = 1;
}

void	act_s(t_printf *pt)
{
	pt->flags.flag_s = 1;
}
