/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 15:06:42 by vduriez           #+#    #+#             */
/*   Updated: 2021/04/15 16:42:49 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/ft_printf.h"

int	ft_treat_uint(unsigned int nbr, t_flags flags)
{
	char	*res;
	int		ret;
	int		size;

	size = ft_size(nbr);
	res = malloc(sizeof(char) * size + 1);
	if (!res)
		return (0);
	res[size] = '\0';
	while (--size >= 0)
	{
		res[size] = (nbr % 10) + 48;
		nbr /= 10;
	}
	ret = ft_flagapp(flags, res);
	free(res);
	return (ret);
}
