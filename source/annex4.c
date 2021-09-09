/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annex4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 17:36:18 by wrosendo          #+#    #+#             */
/*   Updated: 2021/09/09 17:36:59 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	number_print(char *s, t_option *opt)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		ft_putchar_fd(s[i++], 1);
	(*opt).i += i;
}

int	u_blank(int	n, t_option *opt)
{
	int	dif;
	int	i;

	i = 0;
	dif = 0;
	if (n < 0)
	{
		if ((*opt).width > 10)
			dif = (*opt).width - 10;
		else
			return ((*opt).i);
	}
	else
		dif = (*opt).width - ft_strlen((*opt).number);
	if (!(*opt).precision && (*opt).point_precision && (*opt).number[0] == '0')
		dif++;
	(*opt).i += dif;
	while (dif--)
		write(1, " ", 1);
	return ((*opt).i);
}

int	u_print_zero(int n, t_option *opt)
{
	int	dif;

	dif = 0;
	if (n < 0)
	{
		if ((*opt).precision > 10)
			dif = (*opt).precision - 10;
		else
			return ((*opt).i);
	}
	else
		dif = (*opt).precision - ft_strlen((*opt).number);
	(*opt).i += dif;
	while (dif--)
		write(1, "0", 1);
}

void	u_minus_width(t_option *opt)
{
	int	dif;

	dif = 0;
	dif = (*opt).width - (*opt).precision;
	(*opt).i += dif;
	while (dif--)
		write(1, " ", 1);
}

int	u_zero_width(int n, t_option *opt)
{
	int	dif;

	dif = 0;
	if (n < 0)
	{
		if ((*opt).width > 10)
			dif = (*opt).width - 10;
	}
	else if ((*opt).width > ft_strlen((*opt).number))
		dif = (*opt).width - ft_strlen((*opt).number);
	(*opt).i += dif;
	while (dif--)
		write(1, "0", 1);
}
