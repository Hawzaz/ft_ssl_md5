/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bis.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmellon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 04:43:18 by bmellon           #+#    #+#             */
/*   Updated: 2019/07/23 15:51:56 by bmellon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include <stdio.h>

char		*ft_ralloc(void *str)
{
	char	*new;

	new = ft_strdup(ft_strchr((char *)str, '\n') + 1);
	free(str);
	return (new);
}

char		*fill_list(t_list **head, char **line, int *nbread)
{
	int		n;
	t_list	*node;
	char	*p;

	node = *head;
	n = 0;
	if (*nbread == 0 && node->content == NULL)
	{
		*line = NULL;
		return (NULL);
	}
	p = (char *)node->content;
	while (p[n] && p[n] != '\n')
		n++;
	if (!p[n] || !p[n + 1])
	{
		*line = ft_strndup(p, n);
		free(node->content);
		node->content = NULL;
		return (NULL);
	}
	else
		*line = ft_strndup(node->content, n);
	node->content = ft_ralloc(node->content);
	return (node->content);
}

t_list		*get_fd(t_list **list, int fd)
{
	t_list	*node;

	node = *list;
	while (node)
	{
		if ((int)node->content_size == fd)
			return (node);
		node = node->next;
	}
	node = ft_lstnew("\0", 1);
	ft_lstadd(list, node);
	node = *list;
	return (node);
}

int			get_next_line_old(const int fd, char **line)
{
	static	t_list	*list = NULL;
	t_list			*node;
	int				nbread;
	char			buff[BUFF_SIZE + 1];

	if (fd <= -1 || read(fd, &buff, 0))
		return (-1);
	node = get_fd(&list, fd);
	while ((nbread = read(fd, &buff, BUFF_SIZE)) > 0)
	{
		buff[nbread] = '\0';
		if ((char *)node->content)
			node->content = ft_strjoin((char *)node->content, buff, 1);
		else
			node->content = ft_strdup(buff);
		if (ft_strchr(node->content, '\n'))
			break ;
	}
	node->content = fill_list(&node, line, &nbread);
	if (*line != NULL || node->content != NULL)
		return (1);
	return (0);
}
