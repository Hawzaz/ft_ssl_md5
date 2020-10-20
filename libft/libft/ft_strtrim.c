/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmellon <bmellon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 14:36:19 by bmellon           #+#    #+#             */
/*   Updated: 2019/07/29 17:47:48 by bmellon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_ind_fin(char *s)
{
	int		i;
	int		j;

	j = 0;
	i = ft_strlen(s);
	while ((s[j] == ' ' || s[j] == '\n' || s[j] == '\t') && s[j])
		j++;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t' || s[i] == '\0')
		i--;
	if (i < j)
		return (0);
	return (i - j + 1);
}

char	*ft_strtrim(char *s)
{
	int		i;
	char	*str;
	int		j;
	int		len;

	if (s == NULL)
		return (NULL);
	len = ft_ind_fin(s);
	i = 0;
	j = 0;
	if (!(str = ft_memalloc(len + 1)))
		return (NULL);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (len--)
		str[j++] = s[i++];
	str[j] = '\0';
	free(s);
	return (str);
}
