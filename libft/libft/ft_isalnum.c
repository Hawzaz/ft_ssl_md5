/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmellon <bmellon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 23:12:00 by bmellon           #+#    #+#             */
/*   Updated: 2018/04/16 15:52:40 by bmellon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isalnum(int c)
{
	if (((48 <= c) && (c <= 57)) || ((65 <= c) && (c <= 90)) ||
	((97 <= c) && (c <= 122)))
		return (1);
	return (0);
}