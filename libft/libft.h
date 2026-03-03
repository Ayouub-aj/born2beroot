/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilmer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 21:02:21 by swilmer           #+#    #+#             */
/*   Updated: 2021/10/10 12:10:54 by swilmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif
# define QUEUE_LIST 2
# define QUEUE_CLEAR 3

typedef struct s_format
{
	int				minwidth;
	int				leftadjustment;
	char			padding;
	int				precision;
	char			conversion;
	int				maxlen;
}					t_format;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int				*ft_arrbbl(int *array, int count);
int				*ft_arrdup(int *array, int count);
int				ft_arrissrt(int *array, int count);
int				ft_arrisunq(int *array, int count);
int				ft_count_strings(char **strings);
void			ft_exit(char *s);
t_format		*ft_format_lstnew(void);
int				ft_format_lstreset(t_format *list);
char			*ft_format_putchar(char c, t_format *list, char *s);
char			*ft_format_puthex(unsigned int n, t_format *list, char *s);
char			*ft_format_putnbr_uint(unsigned int n, t_format *list, char *s);
char			*ft_format_putnbr(int n, t_format *list, char *s);
char			*ft_format_putptr(void *p, t_format *list, char *s);
char			*ft_format_putstr(char const *str, t_format *list, char *s);
char			*ft_conversion_read(char const **format, va_list *va,
					t_format *list, char *s);
void			*ft_free_int_array(int **array, int size);
void			*ft_free_queue(void *data, int now);
void			*ft_free_strings(char **strings);
void			*ft_free(void *p);
char			*ft_gnl(int fd);
void			ft_lstclear_malloc(t_list **lst, void (*del)(void *));
void			ft_lstdelone_malloc(t_list *lst, void (*del)(void *));
t_list			*ft_lstfind(t_list *lst, void *find, int (*f)(void *, void *));
t_list			*ft_lstmap_malloc(t_list *lst, void *(*f)(void *),
					void (*del)(void *));
t_list			*ft_lstnew_malloc(void *content);
void			ft_lstremove_malloc(t_list **lst, t_list *remove,
					void (*del)(void *));
void			ft_lstremove(t_list **lst, t_list *remove, void (*del)(void *));
void			*ft_malloc(size_t size);
void			*ft_malloc2(void *p);
int				ft_printf(char const *format, ...);
int				ft_ptrcmp(void *p1, void *p2);
int				ft_satoi(char const *str, int *n);

void			*ft_calloc(size_t count, size_t size);
char			*ft_itoa(int n);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstadd_front(t_list **lst, t_list *new);
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));
t_list			*ft_lstnew(void *content);
void			*ft_memccpy(void *dst, const void *restrict src,
					int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
char			**ft_split(char const *str, char c);
char			*ft_strdup(const char *s1);
char			*ft_strimplode(char **strs, char *sep);
char			*ft_strjoin_free(char *s1, char *s2);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_substr(char const *src, unsigned int start, size_t len);

unsigned int	ft_abs(int n);
int				ft_atoi(const char *str);
void			ft_bzero(void *s, size_t n);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_islower(int c);
int				ft_isprint(int c);
int				ft_isspace(int c);
int				ft_isupper(int c);
int				ft_lstsize(t_list *lst);
int				ft_max(int a, int b);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memset(void *b, int c, size_t len);
int				ft_min(int a, int b);
int				ft_nbrlen_uint(unsigned int n);
int				ft_nbrlen(int n);
int				ft_putchar_fd(char c, int fd);
int				ft_putchar(char c);
int				ft_putendl_fd(char *s, int fd);
int				ft_putendl(char *s);
int				ft_putnbr_fd(int n, int fd);
int				ft_putnbr(int n);
int				ft_putstr_fd(char *s, int fd);
int				ft_putstr(char *s);
char			*ft_stpcpy(char *dest, char const *src);
char			*ft_strcat(char *dest, char const *src);
char			*ft_strchr(const char *s, int c);
int				ft_strcmp(char const *s1, char const *s2);
char			*ft_strcpy(char *dest, char const *src);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
size_t			ft_strlcpy(char *dst, char const *src, size_t dstsize);
size_t			ft_strlen(const char *str);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
size_t			ft_strnlen(char const *str, size_t maxlen);
char			*ft_strnstr(const char *big, const char *little,
					size_t len);
char			*ft_strrchr(const char *s, int c);
char			*ft_strrev(char *str);
char			*ft_strtrim(char const *src, char const *set);
char			*ft_substring(char const *src, unsigned int start,
					unsigned int end);
int				ft_tolower(int c);
int				ft_toupper(int c);

#endif
