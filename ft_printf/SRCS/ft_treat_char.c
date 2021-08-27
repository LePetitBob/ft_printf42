/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 15:06:42 by vduriez           #+#    #+#             */
/*   Updated: 2021/08/27 03:41:43 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/ft_printf.h"

int	ft_treat_char(int c, t_flags flags)
{
	char	*res;
	int		ret;

	if (c == 0)
		return (1);
	else
	{
		res = malloc(sizeof(char) * 2);
		if (!res)
			return (0);
		res[0] = c;
		res[1] = 0;
	}
	ret = ft_flagapp(flags, res);
	free(res);
	return (ret);
}
