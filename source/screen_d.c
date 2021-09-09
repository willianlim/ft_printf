/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 17:37:52 by wrosendo          #+#    #+#             */
/*   Updated: 2021/09/09 17:37:53 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	disable_flags(int m, t_option *opt)
{
	if (m < 0)
	{
		(*opt).flag_white_space = 0;
		(*opt).flag_plus = 0;
	}
	if ((*opt).flag_plus)
		(*opt).flag_white_space = 0;
	if ((*opt).flag_zero && (*opt).flag_minus)
		(*opt).flag_zero = 0;
	if ((*opt).flag_zero && (*opt).point_precision)
		(*opt).flag_zero = 0;
}

int	screen_d(t_option *opt)
{
	int		n;
	char	*s;

	n = va_arg((*opt).ap, int);
	disable_flags(n, opt);
	s = ft_itoa(n);
	(*opt).number = s;
	if ((*opt).flag_minus)
	{
		with_flag_minus(opt);
		return ((*opt).i);
	}
	if ((*opt).flag_zero)
	{
		with_flag_zero(opt);
		return ((*opt).i);
	}
	no_flag(opt);
	return ((*opt).i);
}
