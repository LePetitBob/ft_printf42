/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 18:11:53 by vduriez           #+#    #+#             */
/*   Updated: 2021/04/15 16:37:23 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/ft_printf.h"

int	ft_nbrulllen(unsigned long long nbr)
{
	int	i;

	i = 0;
	while (nbr > 0)
	{
		nbr /= 16;
		i++;
	}
	return (i);
}

char	*ft_strcpy(char *src, char *dst)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}

int	ft_treat_pointer(unsigned long long pointer, t_flags flags)
{
	char	*res;
	char	*base;
	int		size;
	int		ret;

	base = "0123456789abcdef";
	if (pointer)
	{
		size = ft_nbrulllen(pointer) + 2;
		res = malloc(sizeof(char) * size + 1);
		if (!res)
			return (0);
		res = ft_strcpy("0x", res);
		res[size] = '\0';
		while (--size > 1)
		{
			res[size] = base[pointer % 16];
			pointer /= 16;
		}
	}
	else
		res = ft_strdup("0x0");
	ret = ft_flagapp(flags, res);
	free(res);
	return (ret);
}
