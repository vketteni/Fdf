/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vketteni <vketteni@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:19:54 by vketteni          #+#    #+#             */
/*   Updated: 2024/01/23 13:16:32 by vketteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_dlist
{
	void			*content;
	struct s_dlist	*median;
	struct s_dlist	*next_highest;
	struct s_dlist	*next_lowest;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}					t_dlist;

int					ft_atoi(const char *nptr);
int					ft_isalpha(int c);
int					ft_isdigit(unsigned int c);
int					ft_isalnum(unsigned int c);
int					ft_isascii(int c);
int					ft_isprint(unsigned int c);
int					ft_toupper(unsigned int c);
int					ft_tolower(unsigned int c);

size_t				ft_strlen(const char *str);
size_t				ft_strlcat(char *dst, const char *src, size_t dst_size);
size_t				ft_strlcpy(char *dst, const char *src, size_t dst_size);
size_t				ft_strnstr(const char *big, const char *little, size_t len);

void				*ft_calloc(size_t nmemb, size_t size);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t n);
void				*ft_memset(void *s, int c, size_t size);
void				*ft_memchr(void *src, char chr, size_t n);

int					ft_memcmp(const void *s1, const void *s2, size_t n);

void				ft_striteri(char *s, void (*f)(unsigned int, char *));
int					ft_strncmp(char *s1, char *s2, size_t n);

char				*ft_strchr(const char *src, char c);
char				*ft_strrchr(const char *src, char c);
char				*ft_strtrim(char const *s1, char const *set);

char				*ft_strdup(const char *s);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);

char				**ft_split(char const *s, char c);

void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);

int					ft_dlstsize(t_dlist *lst);
t_dlist				*ft_dlstnew(void *content);
t_dlist				*ft_dlstlast(t_dlist *lst);
void				ft_dlstiter(t_dlist *lst, void (*f)(void *));
t_dlist				**ft_dlstadd_front(t_dlist **lst, t_dlist *new);
t_dlist				**ft_dlstadd_back(t_dlist **lst, t_dlist *new);
void				ft_dlstclear(t_dlist **lst, void (*del)(void *));
t_dlist				*ft_dlstmap(t_dlist *lst, void *(*f)(void *),
						void (*del)(void *));
void				ft_dlstdelone(t_dlist *lst, void (*del)(void *));

#endif
