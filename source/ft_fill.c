/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 17:37:07 by wrosendo          #+#    #+#             */
/*   Updated: 2021/09/09 17:37:07 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

const	char	*flag(const char *aux, t_option *opt)
{
	while (ft_strchr(FLAG, *aux))
	{
		if (*aux == '#')
			(*opt).flag_hash = 1;
		if (*aux == '+')
			(*opt).flag_plus = 1;
		if (*aux == ' ')
			(*opt).flag_white_space = 1;
		if (*aux == '-')
			(*opt).flag_minus = 1;
		if (*aux == '0')
			(*opt).flag_zero = 1;
		aux++;
	}
	return (aux);
}

const	char	*width(const char *aux, t_option *opt)
{
	int	num;

	if (*aux == '*')
	{
		num = va_arg((*opt).ap, int);
		(*opt).width = num;
		aux++;
	}
	while (ft_isdigit(*aux))
	{
		(*opt).width = (*opt).width * 10 + (*aux - 48);
		aux++;
	}
	return (aux);
}

const	char	*precision_valid(const char *aux, t_option *opt)
{
	int	num;

	if (*aux == '.')
	{
		(*opt).point_precision = 1;
		aux++;
		if (*aux == '*')
		{
			num = va_arg((*opt).ap, int);
			(*opt).precision = num;
			aux++;
		}
		while (ft_isdigit(*aux))
		{
			(*opt).precision = (*opt).precision * 10 + (*aux - 48);
			aux++;
		}
	}
	return (aux);
}

const	char	*type(const char *aux, t_option *opt)
{
	if (ft_strchr(TYPE, *aux))
		(*opt).type = *aux;
	aux++;
	return (aux);
}

const	char	*ft_fill(const char *aux, t_option *opt)
{
	aux = flag(aux, opt);
	aux = width(aux, opt);
	aux = precision_valid(aux, opt);
	aux = type(aux, opt);
	return (aux);
}
