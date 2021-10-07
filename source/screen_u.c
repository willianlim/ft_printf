/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 08:56:07 by wrosendo          #+#    #+#             */
/*   Updated: 2021/10/07 08:57:41 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static unsigned int	count(unsigned int n)
{
	unsigned int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*u_itoa(unsigned int n)
{
	unsigned int	len;
	char			*tmp;

	len = count(n);
	tmp = malloc(sizeof(char) * (len + 1));
	if (tmp == NULL)
		return (NULL);
	tmp[len] = '\0';
	while (len--)
	{
		tmp[len] = (n % 10) + '0';
		n /= 10;
	}
	return (tmp);
}

static void	disable_flags(t_option *opt)
{
	if ((*opt).point_precision)
		(*opt).flag_zero = 0;
}

int	screen_u(t_option *opt)
{
	char			*s;
	unsigned int	n;

	n = va_arg((*opt).ap, unsigned int);
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
