/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annex5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 17:36:22 by wrosendo          #+#    #+#             */
/*   Updated: 2021/09/09 17:44:45 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	u_minus_width_precision(int n, char *s, t_option *opt)
{
	if ((*opt).precision >= (*opt).width)
	{
		u_print_zero(n, opt);
		number_print(s, opt);
	}
	else if ((*opt).precision < (*opt).width)
	{
		u_print_zero(n, opt);
		number_print(s, opt);
		u_minus_width(opt);
	}
}

void	u_width_precision(int n, char *s, t_option *opt)
{
	if ((*opt).width > (*opt).precision)
	{
		u_minus_width(opt);
		u_print_zero(n, opt);
		number_print(s, opt);
	}
	else if ((*opt).precision >= (*opt).width)
	{
		u_print_zero(n, opt);
		number_print(s, opt);
	}
}

void	u_flag_no(int n, char *s, t_option *opt)
{
	if (!(*opt).precision && (*opt).point_precision && (*opt).number[0] == '0')
	{
		if ((*opt).width)
			u_blank(n, opt);
	}
	else if ((*opt).precision > ft_strlen((*opt).number))
	{
		u_print_zero(n, opt);
		number_print(s, opt);
	}
	else if ((*opt).width > ft_strlen((*opt).number))
	{
		u_blank(n, opt);
		number_print(s, opt);
	}
	else
		number_print(s, opt);
}

void	u_minus_flag(int n, char *s, t_option *opt)
{
	if ((*opt).precision > ft_strlen((*opt).number) && \
	 (*opt).width > ft_strlen((*opt).number))
		u_minus_width_precision(n, s, opt);
	else if ((*opt).precision > ft_strlen((*opt).number))
	{
		u_print_zero(n, opt);
		number_print(s, opt);
	}
	else if (!(*opt).precision && (*opt).point_precision && \
	(*opt).number[0] == '0')
		u_blank(n, opt);
	else if ((*opt).width > ft_strlen((*opt).number))
	{
		number_print(s, opt);
		u_blank(n, opt);
	}
	else
		number_print(s, opt);
}
