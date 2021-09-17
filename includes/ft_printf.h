/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 17:53:16 by wrosendo          #+#    #+#             */
/*   Updated: 2021/09/17 20:06:42 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define FLAG "-0# +"
# define TYPE "cpsdiuxX%"
# define EMPTY "(null)"
# define HEX_LOWER "0123456789abcdef"
# define HASH_LOWER "0x"
# define HEX_UPPER "0123456789ABCDEF"
# define HASH_UPPER "0X"
# include "../libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef size_t	t_bool;

typedef struct s_option
{
	va_list	ap;
	t_bool	flag_minus;
	t_bool	flag_zero;
	t_bool	flag_white_space;
	t_bool	flag_hash;
	t_bool	flag_plus;
	t_bool	precision;
	t_bool	point_precision;
	size_t	width;
	int		i;
	int		j;
	int		len;
	int		dif;
	int		percent;
	char	*number;
	char	*hash;
	char	*hex;
	char	type;
}t_option;

int				ft_printf(const char *formart, ...);
const	char	*ft_fill(const char *aux, t_option *opt);
int				ft_placeholder(t_option *opt);
void			reset_option(t_option *opt);
int				screen_c(t_option *opt);
int				screen_d(t_option *opt);
int				screen_p(t_option *opt);
int				screen_percent(t_option *opt);
int				screen_s(t_option *opt);
int				screen_u(t_option *opt);
int				screen_x(t_option *opt);

void			exec(t_option *opt);
void			verify(t_option *opt);
void			precision(t_option *opt);
void			width_space(t_option *opt);
void			width_zero(t_option *opt);

void			precision_width(t_option *opt);
void			precision_width_minus(t_option *opt);
void			print_space_plus(t_option *opt);
int				with_flag_minus(t_option *opt);
int				no_flag(t_option *opt);

void			space(char *str, t_option *opt);
void			null_precision(t_option *opt);
int				s_precision(char *str, t_option *opt);
int				s_width(char *str, t_option *opt);
int				null_width(char *str, t_option *opt);

void			number_print(char *s, t_option *opt);
int				u_blank(int	n, t_option *opt);
int				u_print_zero(int n, t_option *opt);
void			u_minus_width(t_option *opt);
int				u_zero_width(int n, t_option *opt);

void			u_minus_width_precision(int n, char *s, t_option *opt);
void			u_width_precision(int n, char *s, t_option *opt);
void			u_flag_no(int n, char *s, t_option *opt);
void			u_minus_flag(int n, char *s, t_option *opt);

char			*itoa_hex(unsigned long n, char *hex);
int				with_flag_zero(t_option *opt);

#endif
