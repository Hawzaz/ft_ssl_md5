/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmellon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 00:08:00 by bmellon           #+#    #+#             */
/*   Updated: 2019/07/29 17:44:02 by bmellon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_car(char const *s, char *sep)
{
	int	cpt;

	cpt = 0;
	while (*s && ft_strchr(sep, *s) == NULL)
	{
		s++;
		cpt++;
	}
	return (cpt);
}

static	int		ft_mots(char const *s, char *sep)
{
	int		cmp;

	cmp = 0;
	while (*s)
	{
		while (*s && ft_strchr(sep, *s))
			s++;
		if (*s && !ft_strchr(sep, *s))
			cmp++;
		while (*s && !ft_strchr(sep, *s))
			s++;
	}
	return (cmp);
}

char			**ft_split(char const *s, char *sep)
{
	char	**tab;
	int		j;
	int		k;

	if (s == NULL || sep == NULL)
		return (NULL);
	j = 0;
	if (!(tab = ft_memalloc(sizeof(char *) * (ft_mots(s, sep) + 1))))
		return (NULL);
	while (*s)
	{
		k = 0;
		while (*s && ft_strchr(sep, *s))
			s++;
		if (*s)
		{
			if (!(tab[j] = ft_memalloc(ft_car(s, sep) + 1)))
				return (NULL);
			while (*s && ft_strchr(sep, *s) == NULL)
				tab[j][k++] = *s++;
			tab[j++][k] = '\0';
		}
	}
	tab[j] = NULL;
	return (tab);
}
