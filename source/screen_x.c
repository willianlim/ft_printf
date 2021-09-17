/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 17:38:21 by wrosendo          #+#    #+#             */
/*   Updated: 2021/09/17 15:27:39 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	disable_flags(t_option *opt)
{
	if ((*opt).point_precision)
		(*opt).flag_zero = 0;
}

void	print_hash(char *tmp, t_option *opt)
{
	if ((*opt).number[0] != '0')
	{
		(*opt).i += 2;
		ft_putstr_fd(tmp, 1);
	}
	ft_putstr_fd((*opt).number, 1);
	(*opt).i += ft_strlen((*opt).number);
	free((*opt).number);
}

void	lower_upper(t_option *opt)
{
	if ((*opt).type == 'x')
	{
		(*opt).hash = HASH_LOWER;
		(*opt).hex = HEX_LOWER;
	}
	if ((*opt).type == 'X')
	{
		(*opt).hash = HASH_UPPER;
		(*opt).hex = HEX_UPPER;
	}
}

int	screen_x(t_option *opt)
{
	unsigned int	n;
	char				*s;
	char				*tmp;

	n = va_arg((*opt).ap, unsigned int);
	lower_upper(opt);
	tmp = (*opt).hash;
	s = itoa_hex(n, (*opt).hex);
	(*opt).number = s;
	disable_flags(opt);
	if ((*opt).flag_hash)
		print_hash(tmp, opt);
	else if ((*opt).flag_minus)
		with_flag_minus(opt);
	else if ((*opt).flag_zero)
		with_flag_zero(opt);
	else
		no_flag(opt);
	return ((*opt).i);
}
