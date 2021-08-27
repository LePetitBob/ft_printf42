/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 13:41:53 by vduriez           #+#    #+#             */
/*   Updated: 2021/04/21 14:02:57 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/ft_printf.h"

char	*ft_strncpy(char *dest, char *src, t_flags flags)
{
	int	i;
	int	res_len;

	i = 0;
	res_len = ft_strlen(src);
	if (flags.type == 's' && flags.dot == 1 && flags.precision < res_len)
		res_len = flags.precision;
	while (i < res_len)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
