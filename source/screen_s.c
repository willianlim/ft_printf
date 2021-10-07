/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 08:55:58 by wrosendo          #+#    #+#             */
/*   Updated: 2021/10/07 08:55:59 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	strpw_valid(char *str, t_option *opt)
{
	int	i;
	int	dif;

	i = s_precision(str, opt);
	dif = (*opt).width - i;
	(*opt).i += dif;
	while (dif--)
		write(1, " ", 1);
	return ((*opt).i);
}

static int	strp_valid(char *str, t_option *opt)
{
	if (str == NULL)
	{
		null_precision(opt);
		return ((*opt).i);
	}
	else
	{
		s_precision(str, opt);
		return ((*opt).i);
	}
}

int	screen_s(t_option *opt)
{
	char	*s;
	char	*tmp;
	int		dif;
	int		value;
	int		i;

	i = 0;
	tmp = "(null)";
	s = va_arg((*opt).ap, char *);
	if (!(*opt).precision && (*opt).point_precision)
		return ((*opt).i);
	if ((*opt).precision && (*opt).width)
		return (strpw_valid(s, opt));
	if ((*opt).precision)
		return (strp_valid(s, opt));
	if (s == NULL)
		return (null_width(s, opt));
	else
		(*opt).i = ft_strlen(s);
	if ((*opt).width > ft_strlen(s))
		return (s_width(s, opt));
	ft_putstr_fd(s, 1);
	return ((*opt).i);
}
