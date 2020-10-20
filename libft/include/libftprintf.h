/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmellon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 14:19:05 by bmellon           #+#    #+#             */
/*   Updated: 2019/08/30 13:11:57 by bmellon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "../libft/libft.h"
# include <limits.h>

typedef	struct		s_flags
{
	int				flag_z;
	int				flag_p;
	int				flag_m;
	int				flag_h;
	int				flag_s;
	int				flag_d;
}					t_flags;

typedef	struct		s_fltypes
{
	int				l;
	int				ll;
	int				h;
	int				hh;
	long			lo;
	long long		lolo;
	short			sh;
	unsigned char	suc;
	signed char		sc;
}					t_fltypes;

typedef	struct		s_printf
{
	char			*str;
	char			*res;
	char			*sp;
	void			*ptr;
	int				args;
	char			*con;
	int				prec;
	va_list			lst;
	int				ret;
	char			car;
	intmax_t		num;
	uintmax_t		unum;
	int				inc;
	int				nb;
	t_flags			flags;
	int				i;
	t_fltypes		fltypes;
}					t_printf;

typedef	struct		s_types
{
	char			*type;
}					t_types;

int					ft_printf(const char *format, ...);
int					print_parse(t_printf *pt, int i);
int					handling_types(t_printf *pt);
int					handle_big_x(t_printf *pt);
int					handle_x(t_printf *pt);
int					handle_u(t_printf *pt);
int					handle_o(t_printf *pt);
int					handle_di(t_printf *pt);
int					ft_print(t_printf *pt);
int					handle_p(t_printf *pt);
int					handle_s(t_printf *pt);
int					handle_c(t_printf *pt);
int					handle_num(t_printf *pt, int i);
int					handle_flag_sz(t_printf *pt);
int					flag_handling(t_printf *pt);
int					nul_flags(t_printf *pt);
int					parser_flags(t_printf *pt, int i);
void				act_z(t_printf *pt);
void				act_m(t_printf *pt);
void				act_h(t_printf *pt);
void				act_p(t_printf *pt);
void				act_s(t_printf *pt);
int					act_l(t_printf *pt, int i);
int					flagouxx(t_printf *pt);
int					ft_precision(t_printf *pt, int i);
int					buff_fill(char *str, int i, char *buf);
void				get_args(t_printf *pt);
void				clean_pt(t_printf *pt);
void				precision_pt(t_printf *pt, char c, char *str);
int					ft_nbrulen(uintmax_t n, uintmax_t base);
void				no_prec(t_printf *pt);
void				handle_hash(t_printf *pt);
void				flag_m(t_printf *pt, char car);
void				after_flag_m(t_printf *pt, char car);
int					act_prec(t_printf *pt, int i);
void				hash_two(t_printf *pt);
void				hash_three(t_printf *pt);

#endif
