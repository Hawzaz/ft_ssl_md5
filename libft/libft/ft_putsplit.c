/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmellon <bmellon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 23:55:40 by bmellon           #+#    #+#             */
/*   Updated: 2019/04/28 20:13:32 by bmellon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putsplit(char **tab, char c)
{
	while (*tab)
	{
		if (!*tab)
			return ;
		ft_putstr(*tab++);
		if (*tab)
			ft_putchar(c);
	}
}
