/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshults <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 14:30:02 by dshults           #+#    #+#             */
/*   Updated: 2018/04/04 14:30:03 by dshults          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# define VALID_CHARS " +-.#lhjzcCdDiuUoOxXsSp%0123456789*"
# define NOT_CONVERSION_SPECIFIER " #0-+.hljz123456789*"

# define OCTAL_BASE "01234567"
# define HEX_BASE "0123456789abcdef"
# define HEX_BASE_CAPS "0123456789ABCDEF"

typedef	struct	s_size
{
	int			start;
	int			tmp;
	long long	num;
	int			width;
	int			precision;
	int			arg_size;
	int			var_size;
	int			print_w;
	int			print_p;
	char		flags;
	char		hash;
	char		mz;
	char		ps;
	char		pr;
	char		len;
	char		convsp;
	int			prnt;
	int			error;
}				t_size;
/*
** custom libft
*/
int				ft_atoii(const char *nptr);
int				ft_isasciii(int c);
int				ft_isasciii_wstr(wchar_t *s);
int				ft_isdigitt(int c);
int				ft_isprintt(int c);
void			*ft_memallocc(size_t size);
char			*ft_nbrconvert_base(size_t nbr, char *base);
void			ft_putcharr_w(wchar_t chr);
void			ft_putcharr(char c);
int				ft_putnbr_base_u(unsigned long long nbr, char *base);
int				ft_putnbr_base(long long nbr, char *base);
int				ft_putnbr_u(unsigned long long n);
int				ft_putnbrr(long long n);
int				ft_putstrr(char const *s);
int				ft_putstr_w(wchar_t *s);
char			*ft_strchr_no_zeroo(const char *s, int c);
char			ft_chrlen_w(const wchar_t chr);
int				ft_strlenn(const char *str);
intmax_t		ft_strlen_w(const wchar_t *str);
char			*ft_strndupp(const char *s, size_t n);
wchar_t			*ft_strndup_w(wchar_t *s, size_t n);
int				ft_num_lenn(long long n);
int				ft_num_lenn_u(size_t n);
/*
** printf
*/
int				ft_printf(const char *format, ...);
void			ft_get_flags(const char *s, int *i, t_size *t, va_list ap);
void			ft_get_var_size(t_size *t, va_list ap);
void			ft_get_width(const char *s, int *i, t_size *t, va_list ap);
void			ft_precision(const char *s, int *i, t_size *t, va_list ap);
void			ft_get_length(const char *s, int *i, t_size *t);
void			ft_length(int *i, t_size *t, va_list ap);
void			ft_conversion_specifier(
				const char *s, int *i, t_size *t, va_list ap);
void			ft_convsp_char(t_size *t, va_list ap);
void			ft_error(t_size *t, va_list ap);
/*
** convsp_num and functions for it
*/
void			ft_convsp_num(t_size *t, va_list ap);
void			ft_o(t_size *t);
void			ft_u(t_size *t);
void			ft_x(t_size *t);
void			ft_p(t_size *t, va_list ap);
void			ft_print_hash(t_size *t);
void			ft_plus_minus(t_size *t);
void			ft_zero(t_size *t, va_list ap);
void			ft_minus(t_size *t);

#endif
