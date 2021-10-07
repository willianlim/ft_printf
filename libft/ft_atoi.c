/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 08:47:20 by wrosendo          #+#    #+#             */
/*   Updated: 2021/10/07 08:47:29 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	c;
	int	s;
	int	res;

	c = 0;
	s = 1;
	res = 0;
	while ((*nptr >= '\t' && *nptr <= '\r' ) || *nptr == ' ')
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			s *= -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		res = (*nptr++ - '0') + (res * 10);
		c++;
	}
	if (c > 10 && s == 1)
		return (-1);
	else if (c > 10)
		return (0);
	return (res * s);
}
