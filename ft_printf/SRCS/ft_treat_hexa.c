/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 15:06:42 by vduriez           #+#    #+#             */
/*   Updated: 2021/04/21 19:23:10 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/ft_printf.h"

int	ft_nbrlen(unsigned int nbr)
{
	int	i;

	i = 1;
	while (nbr > 15)
	{
		nbr /= 16;
		i++;
	}
	return (i);
}

int	ft_treat_hexa(unsigned int nbr, t_flags flags, int maj)
{
	char	*res;
	int		size;
	char	*base;
	int		ret;

	if (maj)
		base = ft_strdup("0123456789ABCDEF");
	else
		base = ft_strdup("0123456789abcdef");
	size = ft_nbrlen(nbr);
	res = malloc(sizeof(char) * size + 1);
	if (!res)
		return (0);
	res[size] = 0;
	while (--size >= 0)
	{
		res[size] = base[nbr % 16];
		nbr /= 16;
	}
	ret = ft_flagapp(flags, res);
	free(base);
	free(res);
	return (ret);
}
