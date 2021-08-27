/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 15:06:42 by vduriez           #+#    #+#             */
/*   Updated: 2021/08/25 15:06:10 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/ft_printf.h"

int	ft_treat_string(char *str, t_flags flags)
{
	int		ret;

	if (!str)
		ret = ft_flagapp(flags, "(null)");
	else
		ret = ft_flagapp(flags, str);
	return (ret);
}
