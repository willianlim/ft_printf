/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 17:37:58 by wrosendo          #+#    #+#             */
/*   Updated: 2021/09/09 17:43:57 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_addres(char *s, char *hash, t_option *opt)
{
	ft_putstr_fd(hash, 1);
	ft_putstr_fd(s, 1);
	(*opt).i += ft_strlen(s) + 2;
}

void	pointer_space(char *s, t_option *opt)
{
	int	len;

	len = (*opt).width - ft_strlen(s) - 2;
	(*opt).i += len;
	while (len--)
		write(1, " ", 1);
}

int	screen_p(t_option *opt)
{
	unsigned long long int	n;
	char					*s;
	char					*hash;

	hash = HASH_LOWER;
	n = va_arg((*opt).ap, unsigned long long int);
	s = itoa_hex(n, HEX_LOWER);
	if ((*opt).flag_minus)
	{
		print_addres(s, hash, opt);
		if ((*opt).width > (ft_strlen(s) + 2))
			pointer_space(s, opt);
	}
	else if ((*opt).width > (ft_strlen(s) + 2))
	{
		pointer_space(s, opt);
		print_addres(s, hash, opt);
	}
	else
		print_addres(s, hash, opt);
	free(s);
	return ((*opt).i);
}
