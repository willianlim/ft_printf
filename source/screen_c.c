/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 17:37:45 by wrosendo          #+#    #+#             */
/*   Updated: 2021/09/09 17:37:46 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	disable_flags(t_option *opt)
{
	(*opt).precision = 0;
}

void	width_char(t_option *opt)
{
	int	dif;

	dif = 0;
	if ((*opt).width > 1)
	{
		dif = (*opt).width - 1;
		(*opt).i = dif;
		while (dif--)
			write(1, " ", 1);
		(*opt).i++;
	}
}

int	screen_c(t_option *opt)
{
	char	s;
	int		dif;

	s = va_arg((*opt).ap, int);
	disable_flags(opt);
	if ((*opt).flag_minus && (*opt).width > 1)
	{
		ft_putchar_fd(s, 1);
		width_char(opt);
		return ((*opt).i);
	}
	if ((*opt).width > 1)
	{
		width_char(opt);
		ft_putchar_fd(s, 1);
		return ((*opt).i);
	}
	ft_putchar_fd(s, 1);
	(*opt).i++;
	return ((*opt).i);
}
