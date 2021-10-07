/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_placeholder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 08:55:11 by wrosendo          #+#    #+#             */
/*   Updated: 2021/10/07 08:55:11 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	else if ((*opt).type == 'u')
		i = screen_u(opt);
	else if ((*opt).type == 'x' || (*opt).type == 'X')
		i = screen_x(opt);
	else if ((*opt).type == 'p')
		i = screen_p(opt);
	else if ((*opt).type == '%')
		i = screen_percent(opt);
	return (i);
}
