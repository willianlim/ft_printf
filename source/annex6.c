/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annex6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 08:54:55 by wrosendo          #+#    #+#             */
/*   Updated: 2021/10/07 08:54:56 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	count(unsigned long n)
{
	int	len;

	if (n <= 0)
		len = 1;
	else
		len = 0;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*strrev(char *str)
{
	int		i;
	int		length;
	char	buff;

	i = 0;
	length = ft_strlen(str);
	while (length - 1 > i)
	{
		buff = str[i];
		str[i] = str[length - 1];
		str[length - 1] = buff;
		length--;
		i++;
	}
	return (str);
}

char	*itoa_hex(unsigned long n, char *hex)
{
	int		len;
	char	*tmp;
	int		base;
	int		i;

	i = 0;
	base = ft_strlen(hex);
	if (n == 0)
		return (ft_strdup("0"));
	len = count(n);
	tmp = ft_calloc(len + 1, sizeof(char));
	if (tmp == NULL)
		return (NULL);
	while (n != 0)
	{
		tmp[i++] = hex[n % base];
		n = (n / base);
	}
	tmp = strrev(tmp);
	return (tmp);
}

int	with_flag_zero(t_option *opt)
{
	width_zero(opt);
	free((*opt).number);
	return ((*opt).i);
}
