/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkflagwidth.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 14:39:43 by vduriez           #+#    #+#             */
/*   Updated: 2021/08/27 09:44:06 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/ft_printf.h"

t_flags	ft_checkflagwidth(t_flags flags, int len_treat_res)
{
	if (flags.dot == 1 && flags.type == 's')
	{
		if (flags.precision > len_treat_res)
			flags.precision = len_treat_res;
		if (flags.precision < len_treat_res)
			len_treat_res = flags.precision;
	}
	else
	{
		if (flags.precision < len_treat_res)
			flags.precision = len_treat_res;
	}
	if (flags.signe == 1 && flags.width > flags.precision)
		flags.width--;
	if (flags.width < flags.precision)
		flags.width = flags.precision;
	return (flags);
}
