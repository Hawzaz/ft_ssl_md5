/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmellon <bmellon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 22:04:24 by bmellon           #+#    #+#             */
/*   Updated: 2018/04/16 16:41:37 by bmellon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *str;

	if ((str = malloc(sizeof(char) * size + 1)) == NULL)
		return (NULL);
	ft_memset(str, '\0', size + 1);
	return (str);
}
