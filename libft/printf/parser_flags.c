/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmellon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 15:16:10 by bmellon           #+#    #+#             */
/*   Updated: 2019/09/07 19:09:04 by bmellon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		buff_fill(char *str, int i, char *buf)
{
	int		j;

	j = 0;
	while (str && ft_isnum(str[i]))
	{
		buf[j++] = str[i];
		i++;
	}
	i--;
	buf[j] = '\0';
	return (i);
}

int		ft_istypes(int c)
{
	if (c == 32 || c == 35 || c == 43 || c == 45 || c == 108
		|| c == 104 || c == 46 || ft_isnum(c))
		return (1);
	return (0);
}

int		parser_flags(t_printf *pt, int i)
{
	if (pt->str[i] != '0' && ft_isnum(pt->str[i]))
		i = handle_num(pt, i) + 1;
	while (pt->str[i] && ft_istypes(pt->str[i]))
	{
		if (pt->str[i] == '0')
			act_z(pt);
		else if (pt->str[i] == '+')
			act_p(pt);
		else if (pt->str[i] == ' ')
			act_s(pt);
		else if (pt->str[i] == '-')
			act_m(pt);
		else if (pt->str[i] == '#')
			act_h(pt);
		else if (pt->str[i] == 'l' || pt->str[i] == 'h')
			i = act_l(pt, i);
		else if (pt->str[i] == '.')
			i = act_prec(pt, i);
		else if (pt->str[i] != '0' && ft_isnum(pt->str[i]))
			i = handle_num(pt, i);
		i++;
	}
	return (1);
}

int		nul_flags(t_printf *pt)
{
	if (ft_strequ(pt->con, "%d") && (pt->flags.flag_m == 1))
		pt->flags.flag_z = 0;
	if ((pt->flags.flag_p && pt->flags.flag_s) ||
			ft_strequ(pt->con, "%u"))
		pt->flags.flag_s = 0;
	if ((pt->flags.flag_p == 1) && (pt->num < 0))
		pt->flags.flag_p = 0;
	get_args(pt);
	return (1);
}

int		flag_handling(t_printf *pt)
{
	hash_two(pt);
	if (pt->flags.flag_s == 1 || pt->flags.flag_z == 1 ||
			pt->flags.flag_d == 1 || pt->nb != 0)
		handle_flag_sz(pt);
	handle_hash(pt);
	return (1);
}
