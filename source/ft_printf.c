#include "../includes/ft_printf.h"

int	ft_parse(const char *tmp)
{
	int	i;

	i = 0;
	while (ft_strchr(FLAG, tmp[i]))
		i++;
	while (tmp[i] == '*')
		i++;
	while (ft_isdigit(tmp[i]))
		i++;
	if (tmp[i] == '.')
	{
		i++;
		while (tmp[i] == '*')
			i++;
		while (ft_isdigit(tmp[i]))
			i++;
	}
	if (ft_strchr(TYPE, tmp[i]))
		return (1);
	return (0);
}

int	ft_vprintf(const char *format, t_option opt)
{
	const char	*tmp;
	int			count;

	count = 0;
	tmp = format;
	while (*tmp != '\0')
	{
		if (*tmp == '%' && ft_parse(tmp + 1))
		{
			tmp++;
			tmp = ft_fill(tmp, &opt);
			count += ft_placeholder(&opt);
			reset_option(&opt);
		}
		else
		{
			write(1, (const char *)tmp, 1);
			count++;
			tmp++;
		}
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	t_option opt;
	int done;

	ft_memset(&opt, 0, sizeof(opt));
	va_start(opt.ap, format);
	done = ft_vprintf(format, opt);
	va_end(opt.ap);
	return (done);
}
