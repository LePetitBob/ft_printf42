/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_double.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 15:06:42 by vduriez           #+#    #+#             */
/*   Updated: 2021/04/21 18:48:46 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/ft_printf.h"

int	ft_intmin(t_flags flags)
{
	int		ret;
	char	*res;

	res = ft_strdup("2147483648");
	ret = ft_flagapp(flags, res);
	free(res);
	return (ret);
}

int	ft_intmax(t_flags flags)
{
	int		ret;
	char	*res;

	res = ft_strdup("2147483647");
	ret = ft_flagapp(flags, res);
	free(res);
	return (ret);
}

int	ft_signe(int nbr)
{
	if (nbr < 0)
		return (1);
	return (0);
}

int	ft_abs(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

int	ft_treat_double(int nbr, t_flags flags)
{
	char	*res;
	int		ret;
	int		size;

	if (nbr == -2147483648)
		return (ft_intmin(flags));
	if (nbr == 2147483647)
		return (ft_intmax(flags));
	flags.signe = ft_signe(nbr);
	nbr = ft_abs(nbr);
	size = ft_size(nbr);
	res = malloc(sizeof(char) * (size + 1));
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
