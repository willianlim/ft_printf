/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_option.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 08:55:23 by wrosendo          #+#    #+#             */
/*   Updated: 2021/10/07 08:55:23 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	reset_option(t_option *opt)
{
	(*opt).flag_minus = 0;
	(*opt).flag_zero = 0;
	(*opt).flag_white_space = 0;
	(*opt).flag_hash = 0;
	(*opt).flag_plus = 0;
	(*opt).precision = 0;
	(*opt).width = 0;
	(*opt).point_precision = 0;
	(*opt).i = 0;
	(*opt).j = 0;
	(*opt).len = 0;
	(*opt).dif = 0;
	(*opt).type = 0;
	(*opt).hash = 0;
	(*opt).hex = 0;
	(*opt).percent = 0;
}
