/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 18:28:59 by vduriez           #+#    #+#             */
/*   Updated: 2021/04/08 13:32:06 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/ft_printf.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	signe;
	int	somme;

	i = 0;
	signe = 1;
	somme = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		i++;
		signe = -1;
	}
	while (str[i] > 47 && str[i] < 58)
	{
		somme = 10 * somme + (str[i] - 48);
		i++;
	}
	return (somme * signe);
}
