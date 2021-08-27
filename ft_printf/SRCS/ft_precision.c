/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 18:50:44 by vduriez           #+#    #+#             */
/*   Updated: 2021/08/27 09:51:01 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/ft_printf.h"

char	*ft_strncat(char *dest, char *src, int len, t_flags flags)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	if (flags.type == 's')
	{
		while (src[j] && j < len)
		{
			dest[i + j] = src[j];
			j++;
		}
		dest[i + j] = 0;
		return (dest);
	}
	while (src[j] && j < flags.precision)
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = 0;
	return (dest);
}

int	ft_putstrflag(char *s, t_flags flags)
{
	int	i;

	i = 0;
	if (flags.type == 's')
	{
		while (s[i] && i < flags.precision)
		{
			write(1, &s[i], 1);
			i++;
		}
		return (i);
	}
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_sizesigne(t_flags flags, int res_len)
{
	if (flags.signe == 1 && flags.precision > res_len
		&& flags.type != 'u' && flags.type != 's')
		return (1);
	return (0);
}

int	ft_precision(char *treat_res, t_flags flags)
{
	char	*res;
	int		i;
	int		res_len;
	int		signe;

	res_len = ft_strlen(treat_res);
	signe = ft_sizesigne(flags, res_len);
	res = malloc(sizeof(char) * (flags.precision + res_len + signe + 1));
	if (!res)
		return (0);
	i = 0;
	if (flags.signe == 1 && flags.zero == 0)
		res[i++] = '-';
	if (flags.type == 'd' || flags.type == 'u' || flags.type == 'x'
		|| flags.type == 'X')
	{
		while (i - flags.signe < flags.precision - res_len)
			res[i++] = '0';
	}
	res[i] = 0;
	res_len = ft_putstr(res) + ft_putstrflag(treat_res, flags);
	free(res);
	return (res_len);
}
