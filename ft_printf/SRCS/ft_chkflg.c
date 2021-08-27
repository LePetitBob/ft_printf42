/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chkflg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 13:36:52 by vduriez           #+#    #+#             */
/*   Updated: 2021/08/27 06:05:38 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/ft_printf.h"

char	ft_checktype(char *text, int i)
{
	if (text[i] == 's' || text[i] == 'S')
		return ('s');
	if (text[i] == 'd' || text[i] == 'i')
		return ('d');
	if (text[i] == 'u')
		return ('u');
	if (text[i] == 'c')
		return ('c');
	if (text[i] == 'X')
		return ('X');
	if (text[i] == 'x')
		return ('x');
	if (text[i] == 'p')
		return ('p');
	if (text[i] == '%')
		return ('%');
	return ('E');
}

int	ft_skipnbr(char *text, int i)
{
	if (text[i] == '*')
		i++;
	while (text[i] > 47 && text[i] < 58)
		i++;
	return (i);
}

t_flags	ft_flagsize(t_flags flags, char *text, int i)
{
	if (flags.width == -1)
		flags.width = ft_getlength(text, i);
	else
		flags.zero = 0;
	return (flags);
}

t_flags	ft_flagdot(t_flags flags, char *text, int i)
{
	if (flags.dot == 1)
		flags.zero = 0;
	if (flags.precision <= 0)
		flags.precision = ft_getlength(text, i);
	return (flags);
}

t_flags	ft_chkflg(char *text, int i, t_flags flags, va_list args)
{
	if (text[++i] == '-')
		flags.minus = 1;
	if (text[i] == '-')
		i++;
	if (text[i] == '0')
		flags.zero = 1;
	if (text[i] == '0')
		i++;
	if (text[i] == '*')
		flags.width = va_arg(args, int);
	flags = ft_flagsize(flags, text, i);
	i = ft_skipnbr(text, i);
	if (text[i] == '.')
		flags.dot = 1;
	if (text[i] == '.')
		i++;
	if (text[i] == '*')
		flags.precision = va_arg(args, int);
	flags = ft_flagdot(flags, text, i);
	i = ft_skip(text, i);
	flags.type = ft_checktype(text, i);
	return (flags);
}
