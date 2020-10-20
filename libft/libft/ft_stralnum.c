/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stralnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmellon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 17:30:52 by bmellon           #+#    #+#             */
/*   Updated: 2019/07/25 19:06:27 by bmellon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		ft_stralnum(char *s)
{
	int		i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i] && ft_isalnum(s[i]))
		i++;
	if ((ft_isalnum((int)s[i]) || !s[i]) && ft_isalnum((int)s[0]))
		return (1);
	else
		return (0);
}
