/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmellon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 16:12:44 by bmellon           #+#    #+#             */
/*   Updated: 2019/09/07 19:05:41 by bmellon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libftprintf.h"
#include "../libft/libft.h"
#include <limits.h>

int		main(void)
{
	int		i;

	i = 42;
	ft_putnbr(printf("%.4.2s\n", NULL));
	ft_putnbr(ft_printf("%.4.2s\n", NULL));
	return (0);
}
