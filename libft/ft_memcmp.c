/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 08:50:55 by wrosendo          #+#    #+#             */
/*   Updated: 2021/10/07 08:50:56 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*src;
	unsigned char	*dest;
	size_t			i;

	i = 0;
	src = (unsigned char *)s2;
	dest = (unsigned char *)s1;
	while (i < n)
	{
		if (*(dest + i) != *(src + i))
			return (*(dest + i) - *(src + i));
		i++;
	}
	return (0);
}
