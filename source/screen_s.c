#include "../includes/ft_printf.h"

int	screen_s(t_option *opt)
{
	char	*s;
	char	*tmp;
	int		dif;
	int		value;
	int		i;

	i = 0;
	tmp = "(null)";
	s = va_arg((*opt).ap, char*);
	if (!(*opt).precision && (*opt).point_precision)
		return((*opt).i);
	if ((*opt).precision)
	{
		if (s == NULL)
		{
			value = (*opt).precision;
			while (value-- && tmp[i] != '\0')
			{
				ft_putchar_fd(tmp[i++], 1);
				(*opt).i += 1;
			}
			return ((*opt).i);
		}
		value = (*opt).precision;
		while (value-- && s[i] != '\0')
		{
			ft_putchar_fd(s[i++], 1);
			(*opt).i += 1;
		}
		return ((*opt).i);
	}
	if (s == NULL)
	{
		if ((*opt).width > 6)
		{
			dif = (*opt).width - 6;
			(*opt).i = 6 + dif;
			while (dif--)
				write(1, " ", 1);
			ft_putstr_fd(tmp, 1);
			return ((*opt).i);
		}
		(*opt).i = 6;
		ft_putstr_fd(tmp, 1);
		return ((*opt).i);
	}
	else
		(*opt).i = ft_strlen(s);
	if ((*opt).width > ft_strlen(s))
	{
		dif = (*opt).width - ft_strlen(s);
		(*opt).i += dif;
		while (dif--)
			write(1, " ", 1);
		ft_putstr_fd(s, 1);
		return ((*opt).i);
	}
	ft_putstr_fd(s, 1);
	return ((*opt).i);
}
