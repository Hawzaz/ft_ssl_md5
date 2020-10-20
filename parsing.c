/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmellon <bmellon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 15:30:15 by bmellon           #+#    #+#             */
/*   Updated: 2020/10/20 19:18:53 by bmellon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

int		usage(int mode, char *str)
{
	if (mode == 0)
		ft_printf("usage: ft_ssl command [command opts] [command args]\n");
	else if (mode == 1 && str)
	{
		ft_printf("ft_ssl: Error '%s' is not a valid command\nAvailable commands :\n\nMessage Digest :\nmd5\nsha256\n", str);
		exit(0);
	}
	return (1);
}
t_hash	catch_flags(int comm, char **args, t_hash *hash)
{
	int		i;

	i = 2;
	while(args[i][0] == '-')
	{
		if (args[i][1] == 'p')
			hash->flags.flag_p = 1;
		else if (args[i][1] == 'q')
			hash->flags.flag_q = 1;
		else if (args[i][1] == 'r')
			hash->flags.flag_r = 1;
		else if (args[i][1] == 'q')
			hash->flags.flag_s = 1;
		else
			usage(2, args[i]);
		i++;
	}
}

void	parse(char **args)
{
	int			i;
	static char	*fcts[] = {"md5", "sha256"};
	t_hash		hash;
	
	i = 0;
	while (i < (sizeof(fcts)/sizeof(fcts[0])))
	{
		if (ft_strcmp(fcts[i], args[1]))
			catch_flags(i, args, &hash);
		i++;
	}
	usage(1, args[1]);
}