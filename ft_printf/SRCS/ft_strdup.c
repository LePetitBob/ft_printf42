/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 14:50:07 by vduriez           #+#    #+#             */
/*   Updated: 2021/04/06 21:56:21 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/ft_printf.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	while (s1[i])
		i++;
	res = malloc(sizeof(char) * i + 1);
	if (!res)
		return (0);
	while (j < i)
	{
		res[j] = s1[j];
		j++;
	}
	res[j] = '\0';
	return (res);
}
