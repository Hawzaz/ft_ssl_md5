/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmellon <bmellon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 17:15:20 by bmellon           #+#    #+#             */
/*   Updated: 2018/04/24 03:59:25 by bmellon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*new;
	t_list	*fct;

	if (lst == NULL || f == NULL)
		return (NULL);
	fct = f(lst);
	if (!(new = ft_lstnew(fct->content, fct->content_size)))
		return (NULL);
	tmp = new;
	lst = lst->next;
	while (lst && f)
	{
		fct = f(lst);
		if (!(tmp->next = ft_lstnew(fct->content, fct->content_size)))
			return (NULL);
		tmp = tmp->next;
		lst = lst->next;
	}
	return (new);
}
