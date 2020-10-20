/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmellon <bmellon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 17:15:23 by bmellon           #+#    #+#             */
/*   Updated: 2019/07/23 03:13:30 by bmellon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*tmp;

	if (!(tmp = ft_memalloc(sizeof(tmp))))
		return (NULL);
	if (content == NULL)
	{
		tmp->content = NULL;
		tmp->content_size = 0;
		tmp->next = NULL;
		return (tmp);
	}
	if (!(tmp->content = (void *)ft_memalloc(content_size)))
		return (NULL);
	ft_memcpy(tmp->content, content, content_size);
	tmp->content_size = content_size;
	tmp->next = NULL;
	return (tmp);
}
