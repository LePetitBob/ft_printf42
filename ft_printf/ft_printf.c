/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:23:08 by vduriez           #+#    #+#             */
/*   Updated: 2021/05/03 13:58:00 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "INCLUDES/ft_printf.h"
#include <limits.h>

int	ft_printf(const char *input, ...)
{
	va_list		args;
	char		*text;
	int			char_count;

	if (!input)
		return (0);
	va_start(args, input);
	text = ft_strdup(input);
	char_count = ft_lecture(text, args);
	va_end(args);
	free(text);
	return (char_count);
}
