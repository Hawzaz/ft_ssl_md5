/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmellon <bmellon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 11:30:02 by bmellon           #+#    #+#             */
/*   Updated: 2018/04/16 16:45:30 by bmellon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memset(void *str, int c, size_t len)
{
	int		i;
	char	*s;

	s = (char *)str;
	i = 0;
	while (len--)
		s[i++] = (unsigned char)c;
	return (str);
}
