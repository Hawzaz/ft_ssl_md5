/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swapc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmellon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 17:10:46 by bmellon           #+#    #+#             */
/*   Updated: 2019/03/11 17:11:12 by bmellon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swapc(t_lst *lst1, t_lst *lst2)
{
	t_lst	tmp;
	size_t	n;

	n = sizeof(tmp) - sizeof(tmp.next);
	ft_memcpy(&tmp, lst1, n);
	ft_memcpy(lst1, lst2, n);
	ft_memcpy(lst2, &tmp, n);
}
