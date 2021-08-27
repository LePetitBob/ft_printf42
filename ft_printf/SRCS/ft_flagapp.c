/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagapp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 16:45:45 by vduriez           #+#    #+#             */
/*   Updated: 2021/08/27 08:44:01 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/ft_printf.h"

char	*ft_strrcpy(char *dest, char *src, t_flags flags)
{
	int	i;
	int	j;
	int	len;

	if (flags.width == -1 && flags.dot == -1)
		return (src);
	len = ft_strlen(src);
	i = 0;
	j = 0;
	while (i < flags.width - len)
		dest[i++] = ' ';
	while (i < flags.width)
	{
		dest[i++] = src[j++];
	}
	dest[i] = 0;
	return (dest);
}

int	ft_fillspaces(t_flags flags)
{
	int	i;

	i = 0;
	if (flags.width > flags.precision)
	{
		while (i < flags.width - flags.precision)
		{
			write(1, " ", 1);
			i++;
		}
	}
	return (i);
}

int	ft_fillzeros(t_flags flags)
{
	int	i;

	i = 0;
	if (flags.signe == 1 && flags.minus == 0 && flags.precision >= flags.width)
		write(1, "-", 1);
	while (i < flags.width - flags.precision)
	{
		write(1, "0", 1);
		i++;
	}
	return (i + flags.signe);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

int	ft_flagapp(t_flags flags, char *treat_res)
{
	int	len_treat_res;
	int	ret;

	ret = 0;
	if (flags.type == '%')
		return (ft_treat_percent());
	len_treat_res = ft_strlen(treat_res);
	if (ft_strcmp(treat_res, "2147483648") && flags.type != 'u'
		&& flags.type != 's')
		flags.signe = 1;
	flags = ft_checkflagwidth(flags, len_treat_res);
	if (flags.minus == 1)
		ret += ft_precision(treat_res, flags);
	if (flags.zero == 1 && flags.minus == 0)
		ret += ft_fillzeros(flags);
	else if (flags.width > flags.precision)
		ret += ft_fillspaces(flags);
	if (flags.minus == 0)
		ret += ft_precision(treat_res, flags);
	return (ret);
}
