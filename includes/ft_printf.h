#ifndef FT_PRINTF_H
#define FT_PRINTF_H

# define FLAG "-0# +"
# define TYPE "cpsdiuxX%"
# define EMPTY "(null)"

#include "../libft/libft.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef size_t t_bool;

typedef struct s_option
{
	va_list		ap;
	t_bool		flag_minus;
	t_bool		flag_zero;
	t_bool		flag_white_space;
	t_bool		flag_hash;
	t_bool		flag_plus;
	t_bool		precision;
	t_bool		point_precision;
	size_t		width;
	int			i;
	int			j;
	int			len;
	int			dif;
	char		*number;
	char		type;
}t_option;

int				ft_printf(const char *format, ...);
int				ft_vprintf(const char *format, t_option opt);
int				ft_parse(const char *tmp);
const	char	*ft_fill(const char *aux, t_option *opt);
const	char	*type(const char *aux, t_option *opt);
const	char	*precision_valid(const char *aux, t_option *opt);
void			precision(t_option *opt);
const	char	*width(const char *aux, t_option *opt);
const	char	*flag(const char *aux, t_option *opt);
int				ft_placeholder(t_option *opt);
void			reset_option(t_option *opt);
int				screen_c(t_option *opt);
int				screen_d(t_option *opt);
int				screen_s(t_option *opt);
void			width_space(t_option *opt);
void			precision_width(t_option *opt);
void			precision_width_minus(t_option *opt);
int				no_flag(t_option *opt);
void			print_space_plus(t_option *opt);
void			width_zero(t_option *opt);
void			precision_space(t_option *opt);
int				with_flag_minus(t_option *opt);
int				with_flag_zero(t_option *opt);

#endif
