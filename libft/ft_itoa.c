/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 08:49:11 by wrosendo          #+#    #+#             */
/*   Updated: 2021/10/07 08:49:12 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(int n)
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

char	*ft_itoa(int n)
{
	int		len;
	int		neg;
	char	*tmp;

	neg = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = count(n);
	tmp = malloc(sizeof(char) * (len + 1));
	if (tmp == NULL)
		return (NULL);
	tmp[len] = '\0';
	if (n < 0)
	{
		neg = 1;
		n *= -1;
	}
	while (--len >= neg)
	{
		tmp[len] = (n % 10) + '0';
		n /= 10;
	}
	if (neg)
		tmp[len] = '-';
	return (tmp);
}
