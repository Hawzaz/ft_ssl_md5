/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmellon <bmellon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 17:15:23 by bmellon           #+#    #+#             */
/*   Updated: 2018/12/13 18:53:15 by bmellon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lst	*ft_lstnew2(void const *content, size_t content_size)
{
	t_lst	*tmp;

	tmp = NULL;
	if ((tmp = (t_lst*)malloc(sizeof(t_lst))) == NULL)
		return (NULL);
	if (content == NULL)
	{
		tmp->cnt = NULL;
		tmp->size = 0;
		tmp->next = NULL;
		return (tmp);
	}
	tmp->cnt = (void *)ft_memalloc(content_size);
	ft_memcpy(tmp->cnt, content, content_size);
	tmp->size = content_size;
	tmp->next = NULL;
	return (tmp);
}
