/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmellon <bmellon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 15:27:52 by bmellon           #+#    #+#             */
/*   Updated: 2020/10/21 17:55:29 by bmellon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
#define FT_SSL_H

#include "libft/include/libftprintf.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int		usage(void);
void	parse(char **args);

typedef	struct		s_hash_flags
{
	int				flag_p;
	int				flag_q;
	int				flag_r;
	int				flag_s;
}					t_hash_flags;

typedef	struct		s_hash
{
	t_hash_flags	flags;
	size_t			len;
	int				append;
	char			*hash;
	char			*to_hash;
}					t_hash;
#endif