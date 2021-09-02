#ifndef FT_PRINTF_H
#define FT_PRINTF_H

# define FLAG "-0# +"
# define TYPE "cpsdiuxX%"

#include "../libft/libft.h"
#include <stdarg.h>
#include <stdlib.h>

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
	char		type;
}t_option;

#endif
