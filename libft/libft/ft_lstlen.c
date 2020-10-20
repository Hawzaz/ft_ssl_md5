/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmellon <bmellon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 23:52:45 by bmellon           #+#    #+#             */
/*   Updated: 2018/04/26 00:03:46 by bmellon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstlen(t_list *alst)
{
	int		i;

	i = 0;
	if (alst == NULL)
		return (0);
	while (alst)
	{
		alst = alst->next;
		i++;
	}
	return (i);
}
