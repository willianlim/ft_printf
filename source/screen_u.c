/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 17:38:16 by wrosendo          #+#    #+#             */
/*   Updated: 2021/09/17 12:35:41 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	count(long long int n)
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

char	*u_itoa(long long int n)
{
	long long int	len;
	int			neg;
	char		*tmp;

	neg = 0;
	if (n > 4294967295)
		return (ft_strdup(u_itoa(n - 4294967296)));
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

static void	disable_flags(t_option *opt)
{
	if ((*opt).point_precision)
		(*opt).flag_zero = 0;
}

int	screen_u(t_option *opt)
{
	char		*s;
	long long int	n;

	n = va_arg((*opt).ap, long long int);
	s = u_itoa(n);
	(*opt).number = s;
	disable_flags(opt);
	if ((*opt).flag_zero)
	{
		u_zero_width(n, opt);
		number_print(s, opt);
	}
	else if ((*opt).flag_minus)
		u_minus_flag(n, s, opt);
	else if ((*opt).precision > ft_strlen((*opt).number) \
	&& (*opt).width > ft_strlen((*opt).number))
		u_width_precision(n, s, opt);
	else
		u_flag_no(n, s, opt);
	free(s);
	return ((*opt).i);
}
