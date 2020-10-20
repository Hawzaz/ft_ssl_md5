/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmellon <bmellon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 13:42:17 by bmellon           #+#    #+#             */
/*   Updated: 2019/07/21 19:23:14 by bmellon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_bzero(void *s1, size_t n)
{
	int		i;
	char	*str;

	str = (char *)s1;
	i = 0;
	if (n == 0)
		return ;
	while (n--)
		str[i++] = 0;
}
