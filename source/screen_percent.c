/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_percent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 17:38:03 by wrosendo          #+#    #+#             */
/*   Updated: 2021/09/09 17:41:11 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	screen_percent(t_option *opt)
{
	char	c;

	c = '%';
	ft_putchar_fd(c, 1);
	(*opt).i += 1;
	return ((*opt).i);
}
