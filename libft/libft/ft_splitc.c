/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmellon <bmellon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 20:40:35 by bmellon           #+#    #+#             */
/*   Updated: 2019/07/28 01:44:43 by bmellon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_car(char const *s, char c)
{
	int	cpt;

	cpt = 0;
	while (*s != c && *s)
	{
		if (!*s)
			break ;
		s++;
		cpt++;
	}
	return (cpt);
}

static	int		ft_mots(char const *s, char c)
{
	int		i;
	int		cmp;

	cmp = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
			cmp++;
		while (s[i] != c && s[i])
			i++;
	}
	return (cmp);
}

char			**ft_splitc(char const *s, char c)
{
	char	**tab;
	int		j;
	int		k;

	if (s == NULL)
		return (NULL);
	j = 0;
	if (!(tab = ft_memalloc(sizeof(char *) * (ft_mots(s, c) + 1))))
		return (NULL);
	while (*s)
	{
		k = 0;
		while (*s == c && *s)
			s++;
		if (*s)
		{
			if (!(tab[j] = ft_memalloc(ft_car(s, c) + 1)))
				return (NULL);
			while (*s != c && *s)
				tab[j][k++] = *s++;
			tab[j++][k] = '\0';
		}
	}
	tab[j] = NULL;
	return (tab);
}
