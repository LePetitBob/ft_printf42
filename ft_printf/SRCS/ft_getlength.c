/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getlength.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 17:38:10 by vduriez           #+#    #+#             */
/*   Updated: 2021/04/06 21:56:21 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/ft_printf.h"

int	ft_getlength(char *text, int i)
{
	int		j;
	int		k;
	char	*length;

	j = 0;
	k = i;
	if (text[i] < 48 || text[i] > 57)
		return (0);
	while (text[i] >= 48 && text[i] <= 57)
	{
		i++;
		j++;
	}
	length = malloc(sizeof(char) * j + 1);
	if (!length)
		return (0);
	length[j] = 0;
	i = 0;
	while (i < j)
		length[i++] = text[k++];
	j = ft_atoi(length);
	free(length);
	return (j);
}
