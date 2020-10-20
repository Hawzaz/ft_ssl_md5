/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmellon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 14:54:23 by bmellon           #+#    #+#             */
/*   Updated: 2019/08/27 14:26:02 by bmellon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	precision_pt(t_printf *pt, char c, char *str)
{
	int		i;

	if (c == 'd')
		i = ft_nbrlen((int)pt->num);
	else if (c == 'u')
		i = ft_nbrulen(pt->unum, 10);
	else if (c == 'o')
		i = ft_nbrulen(pt->unum, 8);
	else if (c == 'x' || c == 'X')
		i = ft_nbrulen(pt->unum, 16);
	else
		i = ft_strlen(str);
	while (i < pt->prec)
	{
		ft_putchar('0');
		i++;
		pt->ret++;
	}
}

void	clean_pt(t_printf *pt)
{
	ft_memset(&pt->flags, 0, sizeof(pt->flags));
	ft_memset(&pt->fltypes, 0, sizeof(pt->fltypes));
	pt->num = 0;
	pt->args = 0;
}

char	*fill_con(char *str, int nb)
{
	char	*con;

	con = ft_memalloc(3);
	con[0] = '%';
	con[1] = str[nb];
	con[2] = '\0';
	return (con);
}

int		ft_isprintf(int c)
{
	if (ft_isnum(c) || c == 43 || c == 37 || c == 35 || c == 45 || c == 32)
		return (1);
	return (0);
}

int		print_parse(t_printf *pt, int i)
{
	char	*save;
	char	*types;

	types = "scpdiouxX%";
	if (pt->str[i])
		save = ft_strdupn(pt->str, i);
	else
		save = NULL;
	i = 1;
	if ((save = ft_strchr(save, '%')))
	{
		i = 1;
		while (save && save[i] && !ft_strchr(types, save[i]))
			i++;
		if (save && save[i] && ft_strchr(types, save[i]))
		{
			pt->con = fill_con(save, i);
			pt->inc += i;
		}
	}
	ft_strdel(&save);
	return (1);
}
