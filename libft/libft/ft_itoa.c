/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmellon <bmellon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 18:24:07 by bmellon           #+#    #+#             */
/*   Updated: 2018/04/19 17:01:36 by bmellon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char		*ft_rev_itoa(char *s)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(s) - 1;
	if ((str = (char *)malloc(sizeof(char) * (j + 2))) == NULL)
		return (NULL);
	if (s[0] == '-')
	{
		str[0] = s[0];
		i++;
	}
	while (j >= 0 && s[j] != '-')
		str[i++] = s[j--];
	str[i] = '\0';
	return (str);
}

char			*ft_itoa(int n)
{
	int		i;
	char	str[12];

	i = 0;
	if (n < 0)
	{
		str[i++] = '-';
		if (n == -2147483648)
		{
			str[i++] = '8';
			n /= 10;
		}
		n *= -1;
	}
	if (n == 0)
		str[i++] = '0';
	while (n > 0)
	{
		str[i++] = n % 10 + 48;
		n = n / 10;
	}
	str[i] = '\0';
	return (ft_rev_itoa(str));
}
