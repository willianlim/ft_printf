#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "../includes/ft_printf.h"


void	*ft_memset(void *s, int c, size_t n)
{
	char	*p;

	p = ((char *)s);
	while (n--)
		*p++ = (unsigned char)c;
	return (s);
}


size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}


void	*ft_memcpy(void *dest, const void *src, size_t num)
{
	unsigned char	*csrc;
	unsigned char	*cdest;

	if (!dest && !src)
		return (0);
	csrc = (unsigned char *)src;
	cdest = (unsigned char *)dest;
	while (num--)
		*cdest++ = *csrc++;
	return (dest);
}


void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*s;
	char	*d;

	s = (char *)src;
	d = (char *)dest;
	if (s < d)
	{
		while (n--)
			d[n] = s[n];
		return (dest);
	}
	ft_memcpy(d, s, n);
	return (dest);
}


char	*ft_strdup(const char *s)
{
	char	*str;

	str = malloc(ft_strlen(s) + 1);
	if (str == 0)
		return (NULL);
	return (ft_memmove(str, s, ft_strlen(s) + 1));
}


int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}


char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)s + i);
	return (NULL);
}


static int	count(int n)
{
	int	len;

	if (n <= 0)
		len = 1;
	else
		len = 0;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	int		neg;
	char	*tmp;

	neg = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = count(n);
	tmp = malloc(sizeof(char) * (len + 1));
	if (tmp == NULL)
		return (NULL);
	tmp[len] = '\0';
	if (n < 0)
	{
		neg = 1;
		n *= -1;
	}
	while (--len >= neg)
	{
		tmp[len] = (n % 10) + '0';
		n /= 10;
	}
	if (neg)
		tmp[len] = '-';
	return (tmp);
}


int	screen_d(t_option *opt)
{
	int		number;
	char	*number2;
	char	*number2_bak;
	int		j;
	int		len;
	int		len2;
	int		len3;

	j = 0;
	number = va_arg((*opt).ap, int);
	number2 = ft_itoa(number);
	if (*number2 == '0' && !(*opt).precision && (*opt).point_precision)
		number2[0] = '\0';
	if (number2[0] == '-')
		len3 = ft_strlen(number2 + 1);
	else
		len3 = ft_strlen(number2);
	number2_bak = number2;
	len = (*opt).width - ft_strlen(number2);
	len2 = (*opt).precision - ft_strlen(number2);
	if ((*opt).flag_zero && (*opt).width > ft_strlen(number2) && (*opt).precision <= 0)
	{
		if (*number2 == '-')
		{
			write(1, (const void *)number2, 1);
			(*opt).flag_white_space = 0;
			number2++;
			j++;
		}
		if ((*opt).flag_white_space)
		{
			write(1, " ", 1);
			len--;
		}
		if (*number2 == 0)
		{
			while (len--)
			{
				write(1, " ",1);
				j++;
			}
		}
		else
		{
			while (len--)
			{
				write(1, "0",1);
				j++;
			}
		}
		while (*number2 != '\0')
		{
			write(1, (const void *)number2, 1);
			number2++;
			j++;
		}
		free(number2_bak);
		return (j);
	}
	if (((*opt).precision >= len3 && (*opt).width > ft_strlen(number2)))
	{
		if ((*opt).precision >= (*opt).width)
		{
			if (*number2 == '-')
			{
				if ((*opt).flag_plus)
					(*opt).flag_plus = 0;
				write(1, (const void *)number2, 1);
				(*opt).flag_white_space = 0;
				number2++;
				len2++;
				j++;
			}
			if ((*opt).flag_plus)
			{
				write(1, "+", 1);
				(*opt).flag_white_space = 0;
				j++;
			}
			if ((*opt).flag_white_space)
			{
				write(1, " ", 1);
				j++;
			}
			while (len2--)
			{
				write(1, "0", 1);
				j++;
			}
			while (*number2 != '\0')
			{
				write(1, (const void *)number2, 1);
				number2++;
				j++;
			}
			free(number2_bak);
			return (j);
		}
		else if ((*opt).flag_minus && (*opt).precision < (*opt).width)
		{
			len = (*opt).width - (*opt).precision;
			if (*number2 == '-')
			{
				write(1, (const void *)number2, 1);
				(*opt).flag_white_space = 0;
				number2++;
				len--;
				len2++;
				j++;
			}
			if ((*opt).flag_white_space)
			{
				write(1, " ", 1);
				j++;
				len--;
			}
			while (len2--)
			{
				write(1, "0",1);
				j++;
			}
			while (*number2 != '\0')
			{
				write(1, (const void *)number2, 1);
				number2++;
				j++;
			}
			while (len--)
			{
				write(1, " ",1);
				j++;
			}
			free(number2_bak);
			return (j);
		}
		else if ((*opt).precision < (*opt).width)
		{
			len = (*opt).width - (*opt).precision;
			if (number2[0] == '-')
				(*opt).flag_plus = 0;
			if ((*opt).flag_plus)
				len--;
			if (number2[0] == '-')
			{
				len--;
				len2++;
			}
			while (len--)
			{
				write(1, " ",1);
				j++;
			}
			if (*number2 == '-')
			{
				write(1, (const void *)number2, 1);
				number2++;
				j++;
			}
			if ((*opt).flag_plus)
				write(1, "+", 1);
			while (len2--)
			{
				write(1, "0",1);
				j++;
			}
			while (*number2 != '\0')
			{
				write(1, (const void *)number2, 1);
				number2++;
				j++;
			}
			free(number2_bak);
			return (j);
		}
	}
	if ((*opt).flag_minus && (*opt).width && !(*opt).precision)
	{
		if ((*opt).width > ft_strlen(number2))
		{
			if (number2[0] == '-')
			{
				write(1, "-", 1);
				(*opt).flag_white_space = 0;
				number2++;
				j++;
			}
			if ((*opt).flag_white_space)
			{
				write(1, " ", 1);
				len--;
				j++;
			}
			while (*number2 != '\0')
			{
				write(1, (const void *)number2, 1);
				number2++;
				j++;
			}
			while (len--)
			{
				write(1, " ",1);
				j++;
			}
			free(number2_bak);
			return (j);
		}
		else if ((*opt).width < ft_strlen(number2))
		{
			if (number2[0] == '-')
			{
				write(1, "-", 1);
				(*opt).flag_white_space = 0;
				number2++;
				j++;
			}
			if ((*opt).flag_white_space)
			{
				write(1, " ", 1);
				j++;
			}
			while (*number2 != '\0')
			{
				write(1, (const void *)number2, 1);
				number2++;
				j++;
			}
			free(number2_bak);
			return (j);
		}
	}
	else if ((*opt).width > ft_strlen(number2) && !(*opt).precision)
	{
		if (number2[0] == '-')
		{
			if ((*opt).flag_plus)
				(*opt).flag_plus = 0;
		}
		if ((*opt).flag_plus)
			len--;
		while (len--)
		{
			write(1, " ",1);
			j++;
		}
		if ((*opt).flag_plus)
			write(1, "+", 1);
		while (*number2 != '\0')
		{
			write(1, (const void *)number2, 1);
			number2++;
			j++;
		}
		free(number2_bak);
		return (j);
	}
	else if (((*opt).width < ft_strlen(number2)) && (*opt).precision == 0)
	{
		if (number2[0] == '-')
		{
			if ((*opt).flag_plus)
				(*opt).flag_plus = 0;
			write(1, "-", 1);
			(*opt).flag_white_space = 0;
			number2++;
			j++;
		}
		if ((*opt).flag_plus)
		{
			write(1, "+", 1);
			(*opt).flag_white_space = 0;
			j++;
		}
		if ((*opt).flag_white_space)
		{
			write(1, " ", 1);
			j++;
		}
		while (*number2 != '\0')
		{
			write(1, (const void *)number2, 1);
			number2++;
			j++;
		}
		free(number2_bak);
		return (j);
	}
	else if ((*opt).width > ft_strlen(number2) && (*opt).precision && !(*opt).flag_zero)
	{
		if ((*opt).width > ft_strlen(number2))
		{
			if (number2[0] == '-')
			{
				write(1, "-", 1);
				(*opt).flag_white_space = 0;
				number2++;
				j++;
			}
			if ((*opt).flag_white_space)
			{
				write(1, " ", 1);
				len--;
				j++;
			}
			while (*number2 != '\0')
			{
				write(1, (const void *)number2, 1);
				number2++;
				j++;
			}
			while (len--)
			{
				write(1, " ",1);
				j++;
			}
			free(number2_bak);
			return (j);
		}
	}
	else if ((*opt).width > ft_strlen(number2) && (*opt).precision)
	{
		if (number2[0] == '-')
		{
			if ((*opt).flag_plus)
				(*opt).flag_plus = 0;
		}
		if ((*opt).flag_plus)
			len--;
		while (len--)
		{
			write(1, " ",1);
			j++;
		}
		if ((*opt).flag_plus)
			write(1, "+", 1);
		while (*number2 != '\0')
		{
			write(1, (const void *)number2, 1);
			number2++;
			j++;
		}
		free(number2_bak);
		return (j);
	}
	len2 = (*opt).precision - ft_strlen(number2 + 1);
	if (number2[0] == '-')
	{
		if (len2 >= 0)
		{
			number2++;
			j++;
			write(1, "-", 1);
			while (len2--)
			{
				write(1, "0", 1);
				j++;
			}
			while (*number2 != '\0')
			{
				write(1, (const void *)number2, 1);
				number2++;
				j++;
			}
			free(number2_bak);
			return (j);
		}
	}
	len2 = 0;
	len2 = (*opt).precision - ft_strlen(number2);
	if (((*opt).flag_minus || (*opt).flag_zero) && (*opt).precision > ft_strlen(number2))
	{
		if ((*opt).flag_white_space)
		{
			write(1, " ", 1);
			j++;
		}
		while (len2--)
		{
			write(1, "0",1);
			j++;
		}
		while (*number2 != '\0')
		{
			write(1, (const void *)number2, 1);
			number2++;
			j++;
		}
		free(number2_bak);
		return (j);
	}
	else if ((*opt).precision > ft_strlen(number2))
	{
		if ((*opt).flag_white_space)
		{
			write(1, " ", 1);
			j++;
		}
		while (len2--)
		{
			write(1, "0",1);
			j++;
		}
		while (*number2 != '\0')
		{
			write(1, (const void *)number2, 1);
			number2++;
			j++;
		}
		free(number2_bak);
		return (j);
	}
	else
	{
		if (*number2 == '-')
		{
			if ((*opt).flag_plus)
				(*opt).flag_plus = 0;
			write(1, (const void *)number2, 1);
			(*opt).flag_white_space = 0;
			number2++;
			j++;
		}
		if ((*opt).flag_plus)
		{
			write(1, "+", 1);
			(*opt).flag_white_space = 0;
			j++;
		}
		if ((*opt).flag_white_space)
		{
			write(1, " ", 1);
			j++;
		}
		while (*number2 != '\0')
		{
			write(1, (const void *)number2, 1);
			number2++;
			j++;
		}
		free(number2_bak);
		return (j);
	}
}

void	reset_option(t_option *opt)
{
	(*opt).flag_minus = 0;
	(*opt).flag_zero = 0;
	(*opt).flag_white_space = 0;
	(*opt).flag_hash = 0;
	(*opt).flag_plus = 0;
	(*opt).precision = 0;
	(*opt).width = 0;
	(*opt).type = 0;
}

int	ft_placeholder(t_option *opt)
{
	int	i;

	i = 0;
	if ((*opt).type == 'd')
		i = screen_d(opt);
	return (i);
}

const	char	*flag(const char *aux, t_option *opt)
{
	while (ft_strchr(FLAG, *aux))
	{
		if (*aux == '#')
			(*opt).flag_hash = 1;
		if (*aux == '+')
			(*opt).flag_plus = 1;
		if (*aux == ' ')
			(*opt).flag_white_space = 1;
		if (*aux == '-')
			(*opt).flag_minus = 1;
		if (*aux == '0')
			(*opt).flag_zero = 1;
		if ((*opt).flag_zero && (*opt).flag_minus)
			(*opt).flag_zero = 0;
		aux++;
	}
	return (aux);
}

const	char	*width(const char *aux, t_option *opt)
{
	int	num;

	if (*aux == '*')
	{
		num = va_arg((*opt).ap, int);
		(*opt).width = num;
		aux++;
	}
	while (ft_isdigit(*aux))
	{
		(*opt).width = (*opt).width * 10 + (*aux - 48);
		aux++;
	}
	return (aux);
}

const	char	*precision(const char *aux, t_option *opt)
{
	int	num;

	if (*aux == '.')
	{
		(*opt).point_precision = 1;
		aux++;
		if (*aux == '*')
		{
			num = va_arg((*opt).ap, int);
			(*opt).precision = num;
			aux++;
		}
		while (ft_isdigit(*aux))
		{
			(*opt).precision = (*opt).precision * 10 + (*aux - 48);
			aux++;
		}
	}
	return (aux);
}

const	char	*type(const char *aux, t_option *opt)
{
	if (ft_strchr(TYPE, *aux))
		(*opt).type = *aux;
	aux++;
	return (aux);
}

const	char	*ft_fill(const char *aux, t_option *opt)
{
	aux = flag(aux, opt);
	aux = width(aux, opt);
	aux = precision(aux, opt);
	aux = type(aux, opt);
	return (aux);
}

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

int main(int argc, char *argv[])
{
	int	a = 0, b = 0;

	// printf("TESTE[1]\n");
	// a = printf("www.%d$\n",42);
	// printf("%d\n", a);
	// b = ft_printf("www.%d$\n",42);
	// printf("%d\n\n", b);
	// if (a == b)
	// 	printf("[PASS]\n\n");
	// else
	// 	printf("\t\t[FAIL]\n\n");

	// printf("TESTE[2]\n");
	// a = printf("www.%5d$\n",42);
	// printf("%d\n", a);
	// b = ft_printf("www.%5d$\n",42);
	// printf("%d\n\n", b);

	// printf("TESTE[3]\n");
	// a = printf("www.%.5d$\n",42);
	// printf("%d\n", a);
	// b = ft_printf("www.%.5d$\n",42);
	// printf("%d\n\n", b);

	// printf("TESTE[4]\n");
	// a = printf("www.%5.5d$\n",42);
	// printf("%d\n", a);
	// b = ft_printf("www.%5.5d$\n",42);
	// printf("%d\n\n", b);

	// printf("TESTE[5]\n");
	// a = printf("www.%7.5d$\n",42);
	// printf("%d\n", a);
	// b = ft_printf("www.%7.5d$\n",42);
	// printf("%d\n\n", b);

	// printf("TESTE[6]\n");
	// a = printf("www.%5.7d$\n",42);
	// printf("%d\n", a);
	// b = ft_printf("www.%5.7d$\n",42);
	// printf("%d\n\n", b);

	// printf("TESTE[7]\n");
	// a = printf("www.%-d$\n",42);
	// printf("%d\n", a);
	// b = ft_printf("www.%-d$\n",42);
	// printf("%d\n\n", b);

	// printf("TESTE[8]\n");
	// a = printf("www.%-5d$\n",42);
	// printf("%d\n", a);
	// b = ft_printf("www.%-5d$\n",42);
	// printf("%d\n\n", b);

	// printf("TESTE[9]\n");
	// a = printf("www.%-2d$\n",42);
	// printf("%d\n", a);
	// b = ft_printf("www.%-2d$\n",42);
	// printf("%d\n\n", b);

	// printf("TESTE[10]\n");
	// a = printf("www.%-.5d$\n",42);
	// printf("%d\n", a);
	// b = ft_printf("www.%-.5d$\n",42);
	// printf("%d\n\n", b);

	// printf("TESTE[11]\n");
	// a = printf("www.%-.2d$\n",42);
	// printf("%d\n", a);
	// b = ft_printf("www.%-.2d$\n",42);
	// printf("%d\n\n", b);

	// printf("TESTE[12]\n");
	// a = printf("www.%0.5d$\n",42);
	// printf("%d\n", a);
	// b = ft_printf("www.%0.5d$\n",42);
	// printf("%d\n\n", b);

	// printf("TESTE[13]\n");
	// a = printf("www.%0.2d$\n",42);
	// printf("%d\n", a);
	// b = ft_printf("www.%0.2d$\n",42);
	// printf("%d\n\n", b);

	// printf("TESTE[14]\n");
	// a = printf("www.%-5.7d$\n",42);
	// printf("%d\n", a);
	// b = ft_printf("www.%-5.7d$\n",42);
	// printf("%d\n\n", b);

	// printf("TESTE[15]\n");
	// a = printf("www.%-7.5d$\n",42);
	// printf("%d\n", a);
	// b = ft_printf("www.%-7.5d$\n",42);
	// printf("%d\n\n", b);

	// printf("TESTE[16]\n");
	// a = printf("www.%0d$\n",42);
	// printf("%d\n", a);
	// b = ft_printf("www.%0d$\n",42);
	// printf("%d\n\n", b);

	// printf("TESTE[17]\n");
	// a = printf("www.%05d$\n",42);
	// printf("%d\n", a);
	// b = ft_printf("www.%05d$\n",42);
	// printf("%d\n\n", b);

	// printf("TESTE[18]\n");
	// a = printf("www.%02d$\n",42);
	// printf("%d\n", a);
	// b = ft_printf("www.%02d$\n",42);
	// printf("%d\n\n", b);

	// printf("TESTE[19]\n");
	// a = printf("www.%0.5d$\n",42);
	// printf("%d\n", a);
	// b = ft_printf("www.%0.5d$\n",42);
	// printf("%d\n\n", b);

	// printf("TESTE[20]\n");
	// a = printf("www.%0.2d$\n",42);
	// printf("%d\n", a);
	// b = ft_printf("www.%0.2d$\n",42);
	// printf("%d\n\n", b);

	// printf("TESTE[21]\n");
	// a = printf("www.%-05d$\n",42);
	// printf("%d\n", a);
	// b = ft_printf("www.%-05d$\n",42);
	// printf("%d\n\n", b);

	// printf("TESTE[22]\n");
	// a = printf("www.%-0.5d$\n",42);
	// printf("%d\n", a);
	// b = ft_printf("www.%-0.5d$\n",42);
	// printf("%d\n\n", b);

	// printf("TESTE[23]\n");
	// a = printf("www.%0-5d$\n",42);
	// printf("%d\n", a);
	// b = ft_printf("www.%0-5d$\n",42);
	// printf("%d\n\n", b);

	// printf("TESTE[24]\n");
	// a = printf("www.%0-.5d$\n",42);
	// printf("%d\n", a);
	// b = ft_printf("www.%0-.5d$\n",42);
	// printf("%d\n\n", b);

	// printf("TESTE[25]\n");
	// a = printf("www.%-000005d$\n",42);
	// printf("%d\n", a);
	// b = ft_printf("www.%-000005d$\n",42);
	// printf("%d\n\n", b);

	// printf("TESTE[26]\n");
	// a = printf("www.%-00000.5d$\n",42);
	// printf("%d\n", a);
	// b = ft_printf("www.%-00000.5d$\n",42);
	// printf("%d\n\n", b);

	// printf("TESTE[27]\n");
	// a = printf("www.%+d$\n",42);
	// printf("%d\n", a);
	// b = ft_printf("www.%+d$\n",42);
	// printf("%d\n\n", b);

	// printf("TESTE[28]\n");
	// a = printf("www.% +d$\n",42);
	// printf("%d\n", a);
	// b = ft_printf("www.% +d$\n",42);
	// printf("%d\n\n", b);

	// printf("TESTE[29]\n");
	// a = printf("www.%+ d$\n",42);
	// printf("%d\n", a);
	// b = ft_printf("www.%+ d$\n",42);
	// printf("%d\n\n", b);

	// printf("TESTE[30]\n");
	// a = printf("www.%+2d$\n",42);
	// printf("%d\n", a);
	// b = ft_printf("www.%+2d$\n",42);
	// printf("%d\n\n", b);

	// printf("TESTE[31]\n");
	// a = printf("www.%+3d$\n",42);
	// printf("%d\n", a);
	// b = ft_printf("www.%+3d$\n",42);
	// printf("%d\n\n", b);

	// printf("TESTE[32]\n");
	// a = printf("www.%+5d$\n",42);
	// printf("%d\n", a);
	// b = ft_printf("www.%+5d$\n",42);
	// printf("%d\n\n", b);

	// printf("TESTE[33]\n");
	// a = printf("www.%+.3d$\n",42);
	// printf("%d\n", a);
	// b = ft_printf("www.%+.3d$\n",42);
	// printf("%d\n\n", b);

	// printf("TESTE[34]\n");
	// a = printf("www.%+ 5.7d$\n",42);
	// printf("%d\n", a);
	// b = ft_printf("www.%+ 5.7d$\n",42);
	// printf("%d\n\n", b);

	// printf("TESTE[35]\n");
	// a = printf("www.%+ 7.5d$\n",42);
	// printf("%d\n", a);
	// b = ft_printf("www.%+ 7.5d$\n",42);
	// printf("%d\n\n", b);

	// printf("TESTE[36]\n");
	// a = printf("www.%+ 2.2d$\n",42);
	// printf("%d\n", a);
	// b = ft_printf("www.%+ 2.2d$\n",42);
	// printf("%d\n\n", b);

	// printf("TESTE[37]\n");
	// a = printf("www.%+ 3.3d$\n",42);
	// printf("%d\n", a);
	// b = ft_printf("www.%+ 3.3d$\n",42);
	// printf("%d\n\n", b);

	// printf("TESTE[38]\n");
	// a = printf("www.%- d$\n",42);
	// printf("%d\n", a);
	// b = ft_printf("www.%- d$\n",42);
	// printf("%d\n\n", b);

	// printf("TESTE[39]\n");
	// a = printf("www.%- 2d$\n",42);
	// printf("%d\n", a);
	// b = ft_printf("www.%- 2d$\n",42);
	// printf("%d\n\n", b);

	// printf("TESTE[40]\n");
	// a = printf("www.%- 3d$\n",42);
	// printf("%d\n", a);
	// b = ft_printf("www.%- 3d$\n",42);
	// printf("%d\n\n", b);

	// printf("TESTE[41]\n");
	// a = printf("www.%- .2d$\n",42);
	// printf("%d\n", a);
	// b = ft_printf("www.%- .2d$\n",42);
	// printf("%d\n\n", b);

	// printf("TESTE[42]\n");
	// a = printf("www.%- .3d$\n",42);
	// printf("%d\n", a);
	// b = ft_printf("www.%- .3d$\n",42);
	// printf("%d\n\n", b);

	// printf("TESTE[43]\n");
	// a = printf("www.%- 2.2d$\n",42);
	// printf("%d\n", a);
	// b = ft_printf("www.%- 2.2d$\n",42);
	// printf("%d\n\n", b);

	// printf("TESTE[44]\n");
	// a = printf("www.%- 3.3d$\n",42);
	// printf("%d\n", a);
	// b = ft_printf("www.%- 3.3d$\n",42);
	// printf("%d\n\n", b);

	// printf("TESTE[45]\n");
	// a = printf("www.%- 5.7d$\n",42);
	// printf("%d\n", a);
	// b = ft_printf("www.%- 5.7d$\n",42);
	// printf("%d\n\n", b);

	// printf("TESTE[46]\n");
	// a = printf("www.%- 10.5d$\n",42);
	// printf("%d\n", a);
	// b = ft_printf("www.%- 10.5d$\n",42);
	// printf("%d\n\n", b);

	// printf("TESTE[47]\n");
	// a = printf("www.%- 5d$\n",42);
	// printf("%d\n", a);
	// b = ft_printf("www.%- 5d$\n",42);
	// printf("%d\n\n", b);

	// printf("TESTE[48]\n");
	// a = printf("www.%0 d$\n",42);
	// printf("%d\n", a);
	// b = ft_printf("www.%0 d$\n",42);
	// printf("%d\n\n", b);

	// printf("TESTE[49]\n");
	// a = printf("www.%0 2d$\n",42);
	// printf("%d\n", a);
	// b = ft_printf("www.%0 2d$\n",42);
	// printf("%d\n\n", b);

	// printf("TESTE[50]\n");
	// a = printf("www.%0 3d$\n",42);
	// printf("%d\n", a);
	// b = ft_printf("www.%0 3d$\n",42);
	// printf("%d\n\n", b);

	// printf("TESTE[51]\n");
	// a = printf("www.%0 5d$\n",42);
	// printf("%d\n", a);
	// b = ft_printf("www.%0 5d$\n",42);
	// printf("%d\n\n", b);

	// printf("TESTE[52]\n");
	// a = printf("www.%0 .2d$\n",42);
	// printf("%d\n", a);
	// b = ft_printf("www.%0 .2d$\n",42);
	// printf("%d\n\n", b);

	// printf("TESTE[53]\n");
	// a = printf("www.%0 .5d$\n",42);
	// printf("%d\n", a);
	// b = ft_printf("www.%0 .5d$\n",42);
	// printf("%d\n\n", b);

	// printf("TESTE[54]\n");
	// a = printf("www.%0 2.2d$\n",42);
	// printf("%d\n", a);
	// b = ft_printf("www.%0 2.2d$\n",42);
	// printf("%d\n\n", b);

	// printf("TESTE[55]\n");
	// a = printf("www.%0 3.3d$\n",42);
	// printf("%d\n", a);
	// b = ft_printf("www.%0 3.3d$\n",42);
	// printf("%d\n\n", b);

	// printf("TESTE[56]\n");
	// a = printf("www.%0 5.7d$\n",42);
	// printf("%d\n", a);
	// b = ft_printf("www.%0 5.7d$\n",42);
	// printf("%d\n\n", b);

	// printf("TESTE[57]\n");
	// a = printf("www.%0 7.5d$\n",42);
	// printf("%d\n", a);
	// b = ft_printf("www.%0 7.5d$\n",42);
	// printf("%d\n\n", b);

	// printf("TESTE[58]\n");
	// a = printf("www.%#d$\n",42);
	// printf("%d\n", a);
	// b = ft_printf("www.%#d$\n",42);
	// printf("%d\n\n", b);

	// printf("TESTE[59]\n");
	// a = printf("www.%#5d$\n",42);
	// printf("%d\n", a);
	// b = ft_printf("www.%#5d$\n",42);
	// printf("%d\n\n", b);

	// printf("TESTE[60]\n");
	// a = printf("www.%#.5d$\n",42);
	// printf("%d\n", a);
	// b = ft_printf("www.%#.5d$\n",42);
	// printf("%d\n\n", b);

	// // printf("TESTE[61]\n");
	// // a = printf("www.%0*.*d$\n", 3, -2, 8);
	// // printf("%d\n", a);
	// // b = ft_printf("www.%0*.*d$\n", 3, -2, 8);
	// // printf("%d\n\n", b);

	// printf("TESTE[61]\n");
	// a = printf("www.%-15.5d$\n",2147483647);
	// printf("%d\n", a);
	// b = ft_printf("www.%-15.5d$\n",2147483647);
	// printf("%d\n\n", b);

// =============  WIDTH  =============

	// printf("TESTE[61]\n");
	// a = printf("www.%1d$\n",0);
	// printf("%d\n", a);
	// b = ft_printf("www.%1d$\n",0);
	// printf("%d\n\n", b);

	// printf("TESTE[61]\n");
	// a = printf("www.%1d$\n",-4);
	// printf("%d\n", a);
	// b = ft_printf("www.%1d$\n",-4);
	// printf("%d\n\n", b);

	// printf("TESTE[61]\n");
	// a = printf("www.%10d$\n",2147483647);
	// printf("%d\n", a);
	// b = ft_printf("www.%10d$\n",2147483647);
	// printf("%d\n\n", b);

	// printf("TESTE[61]\n");
	// a = printf("www.%10d$\n",-2147483647);
	// printf("%d\n", a);
	// b = ft_printf("www.%10d$\n",-2147483647);
	// printf("%d\n\n", b);

	// printf("TESTE[61]\n");
	// a = printf("www.%11d$\n",2147483647);
	// printf("%d\n", a);
	// b = ft_printf("www.%11d$\n",2147483647);
	// printf("%d\n\n", b);

	// printf("TESTE[61]\n");
	// a = printf("www.%11d$\n",-2147483647);
	// printf("%d\n", a);
	// b = ft_printf("www.%11d$\n",-2147483647);
	// printf("%d\n\n", b);

// =============  PRECISION  =============

	// printf("TESTE[61]\n");
	// a = printf("www.%.d$\n",0);
	// printf("%d\n", a);
	// b = ft_printf("www.%.d$\n",0);
	// printf("%d\n\n", b);

	// printf("TESTE[61]\n");
	// a = printf("www.%.0d$\n",0);
	// printf("%d\n", a);
	// b = ft_printf("www.%.0d$\n",0);
	// printf("%d\n\n", b);

	// printf("TESTE[61]\n");
	// a = printf("www.%.1d$\n",2);
	// printf("%d\n", a);
	// b = ft_printf("www.%.1d$\n",2);
	// printf("%d\n\n", b);

	// printf("TESTE[61]\n");
	// a = printf("www.%.2d$\n",3);
	// printf("%d\n", a);
	// b = ft_printf("www.%.2d$\n",3);
	// printf("%d\n\n", b);

	// printf("TESTE[61]\n");
	// a = printf("www.%.0d$\n",420000);
	// printf("%d\n", a);
	// b = ft_printf("www.%.0d$\n",420000);
	// printf("%d\n\n", b);

	// printf("TESTE[61]\n");
	// a = printf("www.%.3d$\n",-1);
	// printf("%d\n", a);
	// b = ft_printf("www.%.3d$\n",-1);
	// printf("%d\n\n", b);

	// printf("TESTE[61]\n");
	// a = printf("www.%.4d$\n",-1234);
	// printf("%d\n", a);
	// b = ft_printf("www.%.4d$\n",-1234);
	// printf("%d\n\n", b);

	// printf("TESTE[61]\n");
	// a = printf("www.%.5d$\n",-1234);
	// printf("%d\n", a);
	// b = ft_printf("www.%.5d$\n",-1234);
	// printf("%d\n\n", b);

	// printf("TESTE[61]\n");
	// a = printf("www.%.6d$\n",-1234);
	// printf("%d\n", a);
	// b = ft_printf("www.%.6d$\n",-1234);
	// printf("%d\n\n", b);

	// printf("TESTE[61]\n");
	// a = printf("www.%.0d$\n",2);
	// printf("%d\n", a);
	// b = ft_printf("www.%.0d$\n",2);
	// printf("%d\n\n", b);

	// printf("TESTE[61]\n");
	// a = printf("www.%.0d$\n",-2);
	// printf("%d\n", a);
	// b = ft_printf("www.%.0d$\n",-2);
	// printf("%d\n\n", b);

// =============  WIDTH AND '-'  =============

	// printf("TESTE[61]\n");
	// a = printf("www.%-d$\n",0);
	// printf("%d\n", a);
	// b = ft_printf("www.%-d$\n",0);
	// printf("%d\n\n", b);

	// printf("TESTE[62]\n");
	// a = printf("www.%-d$\n",1);
	// printf("%d\n", a);
	// b = ft_printf("www.%-d$\n",1);
	// printf("%d\n\n", b);

	// printf("TESTE[63]\n");
	// a = printf("www.%-1d$\n",1);
	// printf("%d\n", a);
	// b = ft_printf("www.%-1d$\n",1);
	// printf("%d\n\n", b);

	// printf("TESTE[64]\n");
	// a = printf("www.%-10d$\n",0);
	// printf("%d\n", a);
	// b = ft_printf("www.%-10d$\n",0);
	// printf("%d\n\n", b);

	// printf("TESTE[65]\n");
	// a = printf("www.%-10d$\n",2147483647);
	// printf("%d\n", a);
	// b = ft_printf("www.%-10d$\n",2147483647);
	// printf("%d\n\n", b);

	// printf("TESTE[65]\n");
	// a = printf("www.%-11d$\n",2147483647);
	// printf("%d\n", a);
	// b = ft_printf("www.%-11d$\n",2147483647);
	// printf("%d\n\n", b);

	// printf("TESTE[66]\n");
	// a = printf("www.%-10d$\n",-2147483648);
	// printf("%d\n", a);
	// b = ft_printf("www.%-10d$\n",-2147483648);
	// printf("%d\n\n", b);

	// printf("TESTE[68]\n");
	// a = printf("www.%-11d$\n",-2147483648);
	// printf("%d\n", a);
	// b = ft_printf("www.%-11d$\n",-2147483648);
	// printf("%d\n\n", b);

	// printf("TESTE[68]\n");
	// a = printf("www.%-12d$\n",-2147483648);
	// printf("%d\n", a);
	// b = ft_printf("www.%-12d$\n",-2147483648);
	// printf("%d\n\n", b);

// =============  PRECISION AND [-]  =============

	// printf("TESTE[68]\n");
	// a = printf("www.%-.d$\n",0);
	// printf("%d\n", a);
	// b = ft_printf("www.%-.d$\n",0);
	// printf("%d\n\n", b);

	// printf("TESTE[68]\n");
	// a = printf("www.%-.1d$\n",1);
	// printf("%d\n", a);
	// b = ft_printf("www.%-.1d$\n",1);
	// printf("%d\n\n", b);

	// printf("TESTE[68]\n");
	// a = printf("www.%-.2d$\n",10);
	// printf("%d\n", a);
	// b = ft_printf("www.%-.2d$\n",10);
	// printf("%d\n\n", b);

	// printf("TESTE[68]\n");
	// a = printf("www.%-.3d$\n",-10);
	// printf("%d\n", a);
	// b = ft_printf("www.%-.3d$\n",-10);
	// printf("%d\n\n", b);

	// printf("TESTE[68]\n");
	// a = printf("www.%-.4d$\n",5000);
	// printf("%d\n", a);
	// b = ft_printf("www.%-.4d$\n",5000);
	// printf("%d\n\n", b);

	// printf("TESTE[68]\n");
	// a = printf("www.%-.5d$\n",-5000);
	// printf("%d\n", a);
	// b = ft_printf("www.%-.5d$\n",-5000);
	// printf("%d\n\n", b);

// =============  WIDTH, PRECISION AND [-]  =============

	// printf("TESTE[68]\n");
	// a = printf("www.%1.8d$\n",0);
	// printf("%d\n", a);
	// b = ft_printf("www.%1.8d$\n",0);
	// printf("%d\n\n", b);

	// printf("TESTE[68]\n");
	// a = printf("www.%1.9d$\n",1);
	// printf("%d\n", a);
	// b = ft_printf("www.%1.9d$\n",1);
	// printf("%d\n\n", b);

	// printf("TESTE[68]\n");
	// a = printf("www.%1.10d$\n",10);
	// printf("%d\n", a);
	// b = ft_printf("www.%1.10d$\n",10);
	// printf("%d\n\n", b);

	// printf("TESTE[68]\n");
	// a = printf("www.%1.0d$\n",-10);
	// printf("%d\n", a);
	// b = ft_printf("www.%1.0d$\n",-10);
	// printf("%d\n\n", b);

	// printf("TESTE[68]\n");
	// a = printf("www.%1.6d$\n",5000);
	// printf("%d\n", a);
	// b = ft_printf("www.%1.6d$\n",5000);
	// printf("%d\n\n", b);

	// printf("TESTE[68]\n");
	// a = printf("www.%1.4d$\n",-5000);
	// printf("%d\n", a);
	// b = ft_printf("www.%1.4d$\n",-5000);
	// printf("%d\n\n", b);

	// printf("TESTE[68]\n");
	// a = printf("www.%1.10d$\n",(int)-2147483648);
	// printf("%d\n", a);
	// b = ft_printf("www.%1.10d$\n",(int)-2147483648);
	// printf("%d\n\n", b);

	// printf("TESTE[68]\n");
	// a = printf("www.%1.12d$\n",2147483647);
	// printf("%d\n", a);
	// b = ft_printf("www.%1.12d$\n",2147483647);
	// printf("%d\n\n", b);

	// printf("TESTE[68]\n");
	// a = printf("www.%10.d$\n",0);
	// printf("%d\n", a);
	// b = ft_printf("www.%10.d$\n",0);
	// printf("%d\n\n", b);

	// printf("TESTE[68]\n");
	// a = printf("www.%10.10d$\n",1);
	// printf("%d\n", a);
	// b = ft_printf("www.%10.10d$\n",1);
	// printf("%d\n\n", b);

	// printf("TESTE[68]\n");
	// a = printf("www.%10.5d$\n",10);
	// printf("%d\n", a);
	// b = ft_printf("www.%10.5d$\n",10);
	// printf("%d\n\n", b);

	// printf("TESTE[68]\n");
	// a = printf("www.%10.2d$\n",-10);
	// printf("%d\n", a);
	// b = ft_printf("www.%10.2d$\n",-10);
	// printf("%d\n\n", b);

	// printf("TESTE[68]\n");
	// a = printf("www.%10.5d$\n",5000);
	// printf("%d\n", a);
	// b = ft_printf("www.%10.5d$\n",5000);
	// printf("%d\n\n", b);

	// printf("TESTE[68]\n");
	// a = printf("www.%5.10d$\n",5000);
	// printf("%d\n", a);
	// b = ft_printf("www.%5.10d$\n",5000);
	// printf("%d\n\n", b);

// =============  WIDTH, PRECISION AND [-]  =============

	// printf("TESTE[68]\n");
	// a = printf("www.%-1.8d$\n",0);
	// printf("%d\n", a);
	// b = ft_printf("www.%-1.8d$\n",0);
	// printf("%d\n\n", b);

	// printf("TESTE[68]\n");
	// a = printf("www.%-1.9d$\n",1);
	// printf("%d\n", a);
	// b = ft_printf("www.%-1.9d$\n",1);
	// printf("%d\n\n", b);

	// printf("TESTE[68]\n");
	// a = printf("www.%-1.10d$\n",10);
	// printf("%d\n", a);
	// b = ft_printf("www.%-1.10d$\n",10);
	// printf("%d\n\n", b);

	// printf("TESTE[68]\n");
	// a = printf("www.%-1.0d$\n",-10);
	// printf("%d\n", a);
	// b = ft_printf("www.%-1.0d$\n",-10);
	// printf("%d\n\n", b);

	// printf("TESTE[68]\n");
	// a = printf("www.%-1.6d$\n",5000);
	// printf("%d\n", a);
	// b = ft_printf("www.%-1.6d$\n",5000);
	// printf("%d\n\n", b);

	// printf("TESTE[68]\n");
	// a = printf("www.%-1.4d$\n",-5000);
	// printf("%d\n", a);
	// b = ft_printf("www.%-1.4d$\n",-5000);
	// printf("%d\n\n", b);

	// printf("TESTE[68]\n");
	// a = printf("www.%-1.10d$\n",(int)-2147483648);
	// printf("%d\n", a);
	// b = ft_printf("www.%-1.10d$\n",(int)-2147483648);
	// printf("%d\n\n", b);

	// printf("TESTE[68]\n");
	// a = printf("www.%-1.12d$\n",2147483647);
	// printf("%d\n", a);
	// b = ft_printf("www.%-1.12d$\n",2147483647);
	// printf("%d\n\n", b);

	// printf("TESTE[68]\n");
	// a = printf("www.%-10.d$\n",0);
	// printf("%d\n", a);
	// b = ft_printf("www.%-10.d$\n",0);
	// printf("%d\n\n", b);

	// printf("TESTE[68]\n");
	// a = printf("www.%-10.10d$\n",1);
	// printf("%d\n", a);
	// b = ft_printf("www.%-10.10d$\n",1);
	// printf("%d\n\n", b);

	// printf("TESTE[68]\n");
	// a = printf("www.%-10.5d$\n",10);
	// printf("%d\n", a);
	// b = ft_printf("www.%-10.5d$\n",10);
	// printf("%d\n\n", b);

	// printf("TESTE[68]\n");
	// a = printf("www.%-10.2d$\n",-10);
	// printf("%d\n", a);
	// b = ft_printf("www.%-10.2d$\n",-10);
	// printf("%d\n\n", b);

	// printf("TESTE[68]\n");
	// a = printf("www.%-10.5d$\n",5000);
	// printf("%d\n", a);
	// b = ft_printf("www.%-10.5d$\n",5000);
	// printf("%d\n\n", b);

	// printf("TESTE[68]\n");
	// a = printf("www.%-5.10d$\n",-5000);
	// printf("%d\n", a);
	// b = ft_printf("www.%-5.10d$\n",-5000);
	// printf("%d\n\n", b);

// =============  WIDTH, PRECISION AND [0]  =============

	// printf("TESTE[68]\n");
	// a = printf("www.%01d$\n",0);
	// printf("%d\n", a);
	// b = ft_printf("www.%01d$\n",0);
	// printf("%d\n\n", b);

	// printf("TESTE[68]\n");
	// a = printf("www.%01d$\n",-4);
	// printf("%d\n", a);
	// b = ft_printf("www.%01d$\n",-4);
	// printf("%d\n\n", b);

	// printf("TESTE[68]\n");
	// a = printf("www.%010d$\n",42);
	// printf("%d\n", a);
	// b = ft_printf("www.%010d$\n",42);
	// printf("%d\n\n", b);

	// printf("TESTE[68]\n");
	// a = printf("www.%010d$\n",-42);
	// printf("%d\n", a);
	// b = ft_printf("www.%010d$\n",-42);
	// printf("%d\n\n", b);

	// printf("TESTE[68]\n");
	// a = printf("www.%010d$\n",2147483647);
	// printf("%d\n", a);
	// b = ft_printf("www.%010d$\n",2147483647);
	// printf("%d\n\n", b);

	// printf("TESTE[68]\n");
	// a = printf("www.%05d$\n",-2147483647);
	// printf("%d\n", a);
	// b = ft_printf("www.%05d$\n",-2147483647);
	// printf("%d\n\n", b);

	// printf("TESTE[68]\n");
	// a = printf("www.%05d$\n",-2147483648);
	// printf("%d\n", a);
	// b = ft_printf("www.%05d$\n",-2147483648);
	// printf("%d\n\n", b);

	// printf("TESTE[68]\n");
	// a = printf("www.%01.d$\n",0);
	// printf("%d\n", a);
	// b = ft_printf("www.%01.d$\n",0);
	// printf("%d\n\n", b);

	// printf("TESTE[68]\n");
	// a = printf("www.%01.0d$\n",0);
	// printf("%d\n", a);
	// b = ft_printf("www.%01.0d$\n",0);
	// printf("%d\n\n", b);

	// printf("TESTE[68]\n");
	// a = printf("www.%02.d$\n",0);
	// printf("%d\n", a);
	// b = ft_printf("www.%02.d$\n",0);
	// printf("%d\n\n", b);

	// printf("TESTE[68]\n");
	// a = printf("www.%03.d$\n",0);
	// printf("%d\n", a);
	// b = ft_printf("www.%03.d$\n",0);
	// printf("%d\n\n", b);

	// printf("TESTE[68]\n");
	// a = printf("www.%01.2d$\n",1);
	// printf("%d\n", a);
	// b = ft_printf("www.%01.2d$\n",1);
	// printf("%d\n\n", b);

	// printf("TESTE[68]\n");
	// a = printf("www.%01.3d$\n",2);
	// printf("%d\n", a);
	// b = ft_printf("www.%01.3d$\n",2);
	// printf("%d\n\n", b);

	// printf("TESTE[68]\n");
	// a = printf("www.%010.20d$\n",42);
	// printf("%d\n", a);
	// b = ft_printf("www.%010.20d$\n",42);
	// printf("%d\n\n", b);

	// printf("TESTE[68]\n");
	// a = printf("www.%0.3d$\n",2);
	// printf("%d\n", a);
	// b = ft_printf("www.%0.3d$\n",2);
	// printf("%d\n\n", b);

// =============  FLAG WITHE SPACE  =============

	printf("TESTE[68]\n");
	a = printf("www.% d$\n",2);
	printf("%d\n", a);
	b = ft_printf("www.% d$\n",2);
	printf("%d\n\n", b);

	printf("TESTE[68]\n");
	a = printf("www.%  d$\n",2);
	printf("%d\n", a);
	b = ft_printf("www.%  d$\n",2);
	printf("%d\n\n", b);

// =============  FLAG PLUS  =============

	printf("TESTE[68]\n");
	a = printf("www.%+d$\n",3);
	printf("%d\n", a);
	b = ft_printf("www.%+d$\n",3);
	printf("%d\n\n", b);

	printf("TESTE[68]\n");
	a = printf("www.%++d$\n",3);
	printf("%d\n", a);
	b = ft_printf("www.%++d$\n",3);
	printf("%d\n\n", b);

// =============  FLAG PLUS  =============

	printf("TESTE[68]\n");
	a = printf("www.% +d$\n",4);
	printf("%d\n", a);
	b = ft_printf("www.% +d$\n",4);
	printf("%d\n\n", b);

	printf("TESTE[68]\n");
	a = printf("www.%+ d$\n",4);
	printf("%d\n", a);
	b = ft_printf("www.%+ d$\n",4);
	printf("%d\n\n", b);

	return(0);
}
