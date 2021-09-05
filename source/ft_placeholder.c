#include "../includes/ft_printf.h"

int	ft_placeholder(t_option *opt)
{
	int	i;

	i = 0;
	if ((*opt).type == 'c')
		i = screen_c(opt);
	else if ((*opt).type == 'd' || (*opt).type == 'i')
		i = screen_d(opt);
	else if ((*opt).type == 's')
		i = screen_s(opt);
	return (i);
}
