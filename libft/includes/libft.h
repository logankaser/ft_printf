/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaser <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 11:03:56 by lkaser            #+#    #+#             */
/*   Updated: 2017/12/21 19:14:48 by lkaser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# define NULL_GUARD(a) if(!(a)) return (NULL);
# define ASSERT(a) if (!(a)) {ASSERT_FAIL;}
# define ANY2(x,a,b) (x == a || x == b)
# define ANY3(x,a,b,c) (x == a || x == b || x == c)
# define ANY4(x,a,b,c,d) (x == a || x == b || x == c || x == d)
# define ANY5(x,a,b,c,d,e) (x == a || x == b || x == c || x == d || x == e)
# define MATCH(a,b) if (a) b
# define OR(a,b) else if (a) b
# define FT_ITOA_BASE(nbr, base) ft_itoa_base(nbr, base, sizeof base - 1)
# define FT_UTOA_BASE(nbr, base) ft_itoa_base(nbr, base, sizeof base - 1)

typedef char		t_bool;
void				*ft_memset(void *ptr, int val, size_t n);
void				ft_bzero(void *ptr, size_t b);
void				*ft_memcpy(void *dst, const void *src, size_t b);
void				*ft_memccpy(void *dst, const void *src, int c, size_t b);
void				*ft_memmove(void *dst, const void *src, size_t b);
void				*ft_memchr(const void *s, int c, size_t b);
int					ft_memcmp(const void *m1, const void *m2, size_t b);
size_t				ft_strlen(const char *str);
char				*ft_strdup(const char *str);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t size);
char				*ft_strcat(char *dst, const char *src);
char				*ft_strncat(char *dst, const char *src, size_t size);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *str, int val);
char				*ft_strrchr(const char *str, int val);
char				*ft_strstr(const char *str, const char *needle);
char				*ft_strnstr(const char *str, const char *needle,
					size_t size);
int					ft_strcmp(const char *a, const char *b);
int					ft_strncmp(const char *a, const char *b, size_t size);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ptr);
char				*ft_strnew(size_t size);
void				ft_strdel(char **str);
void				ft_strclr(char *str);
void				ft_striter(char *str, void (*f)(char *));
void				ft_striteri(char *str, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *str, char (*f)(char));
char				*ft_strmapi(char const *str, char (*f)(unsigned int, char));
int					ft_strequ(char const *a, char const *b);
int					ft_strnequ(char const *a, char const *b, size_t n);
char				*ft_strsub(char const *str, unsigned int start, size_t len);
char				*ft_strjoin(char const *a, char const *b);
char				*ft_strtrim(char const *str);
char				**ft_strsplit(char const *str, char c);
t_bool				ft_str_has_only(const char *str, const char *has_only);
void				ft_strappend(char **str, char const *add);
void				ft_strprepend(char const *add, char **str);
char				*ft_itoa(long n);
char				*ft_itoa_base(long long nbr, char *base_str, unsigned base);
char				*ft_utoa_base(unsigned long long nbr, char *base_str,
							unsigned base);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_puterror(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
unsigned			ft_sqrt(unsigned i);

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **lst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **lst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **lst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

void				*ft_lstpush(t_list **lst, void *content, size_t size);
t_list				*ft_lstfind(t_list *lst,
					char (*pred)(const void *, const void *), const void *data);
void				ft_lstrm(t_list **lst, t_list *to_rm);

void				ft_putstrarray(char **str);
void				ft_putintarray(int *int_array, size_t size);
void				ft_putmem(char *varname, void *var, size_t bytes);
int					ft_sumarray(int *int_array, size_t size);
t_bool				ft_in_range(const int i, const int low, const int high);

# define GNL_BUFF 1024

int					get_next_line(const int fd, char **line);

typedef	struct		s_fileinfo
{
	int				fd;
	long			i;
	long			fill;
	char			buff[GNL_BUFF + 1];
}					t_fileinfo;

#endif
