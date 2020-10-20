/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmellon <bmellon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 13:11:18 by bmellon           #+#    #+#             */
/*   Updated: 2019/08/23 22:39:03 by bmellon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>

# define BUFF_SIZE 1024
# define CHAR_SEP '\n'

int					get_next_line(const int fd, char **line);
void				ft_strclr(char *s);
void				*ft_memset(void *str, int c, size_t len);
void				ft_bzero(void *s1, size_t n);
void				*ft_memcpy(void *dst, const void *srv, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				**reverse_tab(char **tab);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *dst, char *src);
char				*ft_strncat(char *dst, char *src, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, const char *needle,
	size_t n);
int					ft_atoi(const char *str);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_isalpha(int c);
int					ft_isnum(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
void				*ft_memalloc(size_t size);
void				ft_striter(char *s, void (*f)(char *));
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
void				ft_putchar(char c);
void				ft_putstr(char const *str);
void				ft_putendl(char const *s);
void				ft_putnbr(int nb);
int					ft_nbrlen(intmax_t nb);
void				ft_putnbr_max(intmax_t nb);
void				ft_putlong(long nb);
void				ft_putlonglong(long long nb);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int nb, int fd);
char				*ft_itoa(int n);
int					ft_strequ(char const *s1, char const *s2);
char				*ft_strjoin(char *s1, char *s2, int nb);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char *s);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				**ft_splitc(char const *s, char c);
int					ft_stristr(const char *haystack, const char *needle);
char				**ft_split(char const *s, char *sep);

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef	struct		s_lst
{
	struct s_lst	*prev;
	char			*cnt;
	int				size;
	unsigned char	type;
	char			*lsr;
	struct s_lst	*next;
}					t_lst;

t_list				*ft_lstnew(void const *content, size_t content_size);
t_lst				*ft_lstnew2(void const *content, size_t content_size);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_lst **alst, void (*del)(char*, int,
						unsigned char, char *));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstaddback(t_list *alst, t_list *new);
char				*ft_revstr(char *str);
int					ft_lstlen(t_list *alst);
void				ft_putsplit(char **tab, char c);
char				*ft_revsplit(char **tab);
int					ft_stritertab(char **tab, int (*f)(char *));
void				ft_swapc(t_lst *lst1, t_lst *lst2);
void				ft_putnbrendl(int nb);
int					ft_strcstr(const char *haystack, const char *needle,
	char c);
char				*ft_strcpyn(char *dst, const char *src, size_t len);
char				*ft_strdupn(const char *s1, int ind);
char				*streplace(char *src, char *del, char *rep, int flag);
char				*ft_strndup(const char *s1, int ind);
char				**ft_tabdup(char **tab);
int					get_tab_size(char **tab);
void				handle_free(char *s1, char *s2, int nb);
int					ft_occuc(char *str, int c);
int					ft_copyuntil(char **dst, char *src, char c);
int					get_next_line_old(const int fd, char **line);
int					ft_stralnum(char *s);
void				handle_free_ext(char *s1, char *s2, char *s3, int nb);
char				*ft_itoa_base(intmax_t nb, intmax_t base);
void				ft_putnbr_base(uintmax_t n, char *base);

#endif
