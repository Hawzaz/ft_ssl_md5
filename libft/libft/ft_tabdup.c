/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmellon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 02:42:29 by bmellon           #+#    #+#             */
/*   Updated: 2019/07/29 17:47:21 by bmellon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabdup(char **tab)
{
	int		i;
	char	**env;

	i = get_tab_size(tab);
	if (!(env = ft_memalloc(sizeof(*env) * (i + 1))))
		return (NULL);
	if (!tab)
		return (env);
	i = 0;
	while (tab[i])
		if (!(env[i] = ft_strdup(tab[i])))
		{
			while (i--)
				free(env[i]);
			free(env);
			return (NULL);
		}
		else
			i++;
	return (env);
}
