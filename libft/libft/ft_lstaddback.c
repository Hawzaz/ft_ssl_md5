/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddback.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmellon <bmellon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 18:34:11 by bmellon           #+#    #+#             */
/*   Updated: 2018/04/25 23:55:35 by bmellon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddback(t_list *alst, t_list *new)
{
	if (alst == NULL || new == NULL)
		return ;
	new->next = NULL;
	while (alst)
		alst = alst->next;
	alst->next = new;
}
