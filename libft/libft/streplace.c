/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   streplace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmellon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 17:35:36 by bmellon           #+#    #+#             */
/*   Updated: 2019/07/27 14:19:47 by bmellon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*streplace(char *src, char *del, char *rep, int flag)
{
	int		i;
	int		add;
	int		len;
	char	*new;

	if (src == NULL || rep == NULL || del == NULL
			|| ft_strstr(src, del) == NULL)
		return (NULL);
	add = ft_strlen(rep) - ft_strlen(del);
	len = ft_strlen(src);
	if ((new = ft_memalloc(len + add + 1)) == NULL)
		return (NULL);
	len = ft_stristr(src, del);
	new = ft_strncpy(new, src, len);
	new = ft_strcat(new, rep);
	i = len + ft_strlen(rep);
	len += ft_strlen(del) - 1;
	while (src[len++])
		new[i++] = src[len];
	handle_free_ext(src, del, rep, flag);
	return (new);
}
