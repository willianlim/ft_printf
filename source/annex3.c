/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annex3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 17:36:12 by wrosendo          #+#    #+#             */
/*   Updated: 2021/09/09 17:40:50 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	space(char *str, t_option *opt)
{
	int	dif;

	dif = 0;
	dif = (*opt).width - ft_strlen(str);
	(*opt).i += dif;
	while (dif--)
		write(1, " ", 1);
}

void	null_precision(t_option *opt)
{
	char	*tmp;
	int		value;
	int		i;

	i = 0;
	tmp = "(null)";
	value = (*opt).precision;
	while (value-- && tmp[i] != '\0')
	{
		ft_putchar_fd(tmp[i++], 1);
		(*opt).i += 1;
	}
}

int	s_precision(char *str, t_option *opt)
{
	int	value;
	int	i;

	i = 0;
	value = (*opt).precision;
	while (value-- && str[i] != '\0')
	{
		ft_putchar_fd(str[i++], 1);
		(*opt).i += 1;
	}
	return (i);
}

int	s_width(char *str, t_option *opt)
{
	if ((*opt).width > ft_strlen(str))
	{
		if ((*opt).width > ft_strlen(str) && (*opt).flag_minus)
		{
			ft_putstr_fd(str, 1);
			space(str, opt);
			return ((*opt).i);
		}
		else
		{
			space(str, opt);
			ft_putstr_fd(str, 1);
			return ((*opt).i);
		}
	}
}

int	null_width(char *str, t_option *opt)
{
	char	*tmp;
	int		dif;

	tmp = "(null)";
	dif = 0;
	if ((*opt).width > 6)
	{
		dif = (*opt).width - 6;
		(*opt).i = 6 + dif;
		while (dif--)
			write(1, " ", 1);
		ft_putstr_fd(tmp, 1);
		return ((*opt).i);
	}
	(*opt).i = 6;
	ft_putstr_fd(tmp, 1);
	return ((*opt).i);
}
