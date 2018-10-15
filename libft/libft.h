/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshults <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:34:42 by dshults           #+#    #+#             */
/*   Updated: 2017/11/14 18:34:44 by dshults          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"

size_t				ft_count_char(char *str, char c);
int					ft_atoi(const char *nptr);
intmax_t			ft_atoi_intmax(const char *nptr);
void				ft_bzero(void *s, size_t n);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isnumber(char *num);
int					ft_isprint(int c);
char				*ft_itoa(int n);
char				**ft_malloc_xy(size_t x, size_t y);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memset(void *s, int c, size_t n);
void				ft_putchar_fd(char c, int fd);
void				ft_putchar(char c);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putendl(char const *s);
void				ft_putnbr_fd(int n, int fd);
void				ft_putnbr(int n);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putstr(char const *s);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strchr(const char *s, int c);
char				*ft_strchr_no_zero(const char *s, int c);
void				ft_strclr(char *s);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dest, const char *src);
void				ft_strdel(char **as);
char				*ft_strdup(const char *s);
int					ft_strdup_c(const char *src, char **dst, char c);
int					ft_strequ(char const *s1, char const *s2);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *str);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *dest, const char *src, size_t nb);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strndup(const char *s, size_t n);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strnstr(const char *str, const char *to_find
					, size_t len);
char				*ft_strrchr(const char *s, int c);
char				**ft_strsplit(char const *s, char c);
char				*ft_strstr(const char *str, const char *to_find);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
int					ft_tolower(int c);
int					ft_toupper(int c);

#endif
