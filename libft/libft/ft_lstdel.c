/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmellon <bmellon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 17:15:12 by bmellon           #+#    #+#             */
/*   Updated: 2019/07/23 03:06:57 by bmellon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_lst **alst, void (*del)(char*, int, unsigned char, char *))
{
	t_lst	*node;

	if (alst == NULL || del == NULL)
		return ;
	while (*alst && del)
	{
		del((*alst)->cnt, (*alst)->size, (*alst)->type, (*alst)->lsr);
		node = (*alst)->next;
		free(*alst);
		(*alst) = node;
	}
	alst = NULL;
}
