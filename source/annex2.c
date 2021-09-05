#include "../includes/ft_printf.h"

void	precision_width(t_option *opt)
{
	int	dif;

	if ((*opt).precision > ft_strlen((*opt).number) && (*opt).width > ft_strlen((*opt).number))
	{
		if ((*opt).precision > (*opt).width)
		{
			precision(opt);
			(*opt).j = 1;
		}
		else if ((*opt).precision < (*opt).width)
		{
			dif = (*opt).width - (*opt).precision;
			if ((*opt).number[0] == '-')
				dif--;
			(*opt).i += dif;
			while (dif--)
				write(1, " ", 1);
			precision(opt);
			(*opt).j = 1;
		}
	}
}

void	precision_width_minus(t_option *opt)
{
	int	dif;
	int	len3;

	if ((*opt).flag_minus)
	{
		if ((*opt).number[0] == '-')
			len3 = ft_strlen((*opt).number) - 1;
		else
			len3 = ft_strlen((*opt).number);
		if ((*opt).precision > len3 && (*opt).width > ft_strlen((*opt).number))
		{
			if ((*opt).precision > (*opt).width)
				precision(opt);
			else if ((*opt).precision < (*opt).width)
			{
				precision(opt);
				dif = (*opt).width - (*opt).i;
				(*opt).i += dif;
				while (dif--)
					write(1, " ", 1);
				(*opt).j = 1;
				(*opt).precision = 0;
			}
		}
	}
}

void	print_space_plus(t_option *opt)
{
	if ((*opt).flag_white_space)
	{
		write(1, " ", 1);
		(*opt).i++;
	}
	if ((*opt).flag_plus)
	{
		write(1, "+", 1);
		(*opt).i++;
	}
}

int	with_flag_minus(t_option *opt)
{
	precision_width_minus(opt);
	precision(opt);
	if (!(*opt).j)
	{
		print_space_plus(opt);
		if (!(*opt).precision && (*opt).point_precision && !(*opt).j)
		{
			if ((*opt).number[0] == '0' && (*opt).width <= (*opt).i)
			{
				(*opt).i = 0;
				free((*opt).number);
				return ((*opt).i);
			}
			width_space(opt);
			free((*opt).number);
			return ((*opt).i);
		}
		ft_putstr_fd((*opt).number, 1);
		width_space(opt);
	}
	free((*opt).number);
	return ((*opt).i);
}

int	with_flag_zero(t_option *opt)
{
	width_zero(opt);
	free((*opt).number);
	return ((*opt).i);
}

int		no_flag(t_option *opt)
{
	precision_width(opt);
	precision(opt);
	if (!(*opt).j)
	{
		width_space(opt);
		print_space_plus(opt);
		if (!(*opt).precision && (*opt).point_precision && !(*opt).j)
		{
			if ((*opt).number[0] == '0')
			{
				if ((*opt).width < ft_strlen((*opt).number))
					(*opt).i = 0;
				free((*opt).number);
				return ((*opt).i);
			}
		}
		ft_putstr_fd((*opt).number, 1);
	}
	free((*opt).number);
	return ((*opt).i);
}
