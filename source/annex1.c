/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annex1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 08:54:13 by wrosendo          #+#    #+#             */
/*   Updated: 2021/10/07 08:54:14 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	exec(t_option *opt)
{
	if (!(*opt).precision && (*opt).point_precision && !(*opt).j)
	{
		(*opt).i = ft_strlen((*opt).number);
		(*opt).point_precision = 0;
		if ((*opt).number[0] == '0')
		{
			(*opt).i = 0;
			(*opt).point_precision = 1;
		}
	}
	else if (!(*opt).j)
	{
		(*opt).i = ft_strlen((*opt).number);
		if ((*opt).number[0] == '0' && \
		!(*opt).precision && (*opt).point_precision)
			(*opt).i = 0;
	}
}

void	verify(t_option *opt)
{
	int	len;

	if ((*opt).number[0] == '-' && (*opt).precision \
	&& (*opt).point_precision && !(*opt).j)
	{
		len = ft_strlen((*opt).number);
		(*opt).i += len;
		len--;
		(*opt).len += len;
		(*opt).dif = (*opt).precision - len;
	}
	else if (!(*opt).j && (*opt).precision && (*opt).point_precision)
	{
		len = ft_strlen((*opt).number);
		(*opt).i += len;
		(*opt).len += len;
		(*opt).dif = (*opt).precision - len;
	}
}

void	precision(t_option *opt)
{
	int	dif;
	int	i;

	i = 0;
	dif = 0;
	verify(opt);
	if ((*opt).precision > (*opt).len && !(*opt).j)
	{
		if ((*opt).number[0] == '-')
		{
			write(1, "-", 1);
			i++;
		}
		(*opt).i += (*opt).dif;
		while ((*opt).dif--)
			write(1, "0", 1);
		while ((*opt).number[i] != '\0')
			ft_putchar_fd((*opt).number[i++], 1);
		(*opt).j = 1;
	}
	else
		exec(opt);
}

void	width_space(t_option *opt)
{
	int	len;

	if ((*opt).width >= ft_strlen((*opt).number) && \
	(*opt).width > (*opt).precision && !(*opt).j)
	{
		if ((*opt).number[0] == '0' && \
		!(*opt).precision && (*opt).point_precision)
			len = (*opt).width;
		else
			len = (*opt).width - ft_strlen((*opt).number);
		(*opt).i += len;
		while (len--)
			write(1, " ", 1);
	}
}

void	width_zero(t_option *opt)
{
	int	len;
	int	i;

	i = 0;
	if ((*opt).width >= ft_strlen((*opt).number))
	{
		len = (*opt).width - ft_strlen((*opt).number);
		(*opt).i += len;
		(*opt).i += ft_strlen((*opt).number);
		if ((*opt).number[0] == '-')
		{
			write(1, "-", 1);
			i++;
		}
		while (len--)
			write(1, "0", 1);
		while ((*opt).number[i] != '\0')
			ft_putchar_fd((*opt).number[i++], 1);
	}
	else
	{
		(*opt).i = ft_strlen((*opt).number);
		ft_putstr_fd((*opt).number, 1);
	}
}
