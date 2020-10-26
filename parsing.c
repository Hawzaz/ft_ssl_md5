/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmellon <bmellon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 15:30:15 by bmellon           #+#    #+#             */
/*   Updated: 2020/10/26 17:36:39 by bmellon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_ssl.h"

char	*ft_realloc(char *str, size_t n)
{
	char	*new;

	if (!str || n <= 0)
		return (NULL);
	new = ft_strnew(n);
	new = ft_strcpy(new, str);
	free(str);
	return (new);
}

int		usage(int mode, char *str)
{
	if (mode == 0)
		ft_printf("usage: ft_ssl command [command opts] [command args]\n");
	else if (mode == 1 && str)
	{
		ft_printf("ft_ssl: Error '%s' is not a valid command\nAvailable commands :\n\nMessage Digest :\nmd5\nsha256\n", str);
		exit(0);
	}
	else if (mode == 2 && str)
	{
		ft_printf("ft_ssl: Error invalid argument [%s]\n", str);
	}
	return (1);
}

void	catch_flags(char **args, t_hash *hash)
{
	int		i;

	i = 2;
	while(args[i] && args[i][0] == '-')
	{
		if (args[i][1] == 'p')
			hash->flags.flag_p = 1;
		else if (args[i][1] == 'q')
			hash->flags.flag_q = 1;
		else if (args[i][1] == 'r')
			hash->flags.flag_r = 1;
		else if (args[i][1] == 's')
			hash->flags.flag_s = 1;
		else
			usage(2, args[i]);
		i++;
	}
	hash->to_hash = args[i];
}

char*	stringToBinary(char* s) 
{
	size_t len;
	char ch;
	char *binary;

	if (s == NULL)
		return 0;
	len = ft_strlen(s);
	binary = malloc(len*8 + 1);
	binary[0] = '\0';
	for(size_t i = 0; i < len; ++i)
	{
		ch = s[i];
		for(int j = 7; j >= 0; --j)
			ch & (1 << j) ? strcat(binary,"1") :strcat(binary,"0");
	}
	return binary;
}

void	print_struct(t_hash h)
{
	ft_printf("Type : [%s]\nStr to hash is : [%s]\nHashed str is : [%s]\nNeed to append : [%d]\nLen is [%d]\n\nFlags : -p [%d]\t-q [%d]\t-r [%d]\t-s [%d]\n",h.type, h.to_hash, h.hash,h.append, h.len, h.flags.flag_p, h.flags.flag_q, h.flags.flag_r, h.flags.flag_s);
}

void	making_hash(t_hash hash)
{
	size_t		tmp;

	if (hash.to_hash)
	{
		hash.to_hash = stringToBinary(hash.to_hash);
		hash.len = ft_strlen(hash.to_hash);
		hash.append = hash.len;
		while (hash.append % 512 != 448)
			hash.append++;
		hash.to_hash = ft_realloc(hash.to_hash, hash.append);
		if (hash.append > hash.len)
		{
			hash.to_hash[hash.len + 1] = '1';
			ft_putnbrendl(hash.len + 1);
			tmp = hash.len + 2;
			while (tmp < hash.append)
				hash.to_hash[tmp++] = '0';
			hash.to_hash[tmp] = '\0';
		}
		else
		{
			//split
		}
	}
	print_struct(hash);
}

void	init_h (t_hash *h)
{
	h->append = 0;
	h->type = NULL;
	h->len = 0;
	h->to_hash = NULL;
	h->hash = NULL;
	h->flags.flag_p = 0;
	h->flags.flag_q = 0;
	h->flags.flag_r = 0;
	h->flags.flag_s = 0;
}

void	parse(char **args)
{
	size_t		i;
	static char	*fcts[] = {"md5", "sha256"};
	t_hash		hash;

	init_h(&hash);
	i = 0;
	while (i < (sizeof(fcts)/sizeof(fcts[0])))
	{
		if (!ft_strcmp(fcts[i], args[1]))
		{
			hash.type = fcts[i];
			catch_flags(args, &hash);
			making_hash(hash);
			return ;
		}
		i++;
	}
	usage(1, args[1]);
}