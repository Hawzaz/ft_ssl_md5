/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_free_ext.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmellon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 13:52:01 by bmellon           #+#    #+#             */
/*   Updated: 2019/07/27 14:09:10 by bmellon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	handle_free_ext(char *s1, char *s2, char *s3, int nb)
{
	if (nb == 1)
		free(s1);
	else if (nb == 2)
		free(s2);
	else if (nb == 3)
		free(s3);
	else if (nb == 4)
		handle_free(s1, s2, 3);
	else if (nb == 5)
		handle_free(s1, s3, 3);
	else if (nb == 6)
		handle_free(s2, s3, 3);
	else if (nb == 7)
	{
		free(s1);
		free(s2);
		free(s3);
	}
}
