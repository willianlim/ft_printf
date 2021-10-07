/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 08:51:01 by wrosendo          #+#    #+#             */
/*   Updated: 2021/10/07 08:51:02 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t num)
{
	unsigned char	*csrc;
	unsigned char	*cdest;

	if (!dest && !src)
		return (0);
	csrc = (unsigned char *)src;
	cdest = (unsigned char *)dest;
	while (num--)
		*cdest++ = *csrc++;
	return (dest);
}
