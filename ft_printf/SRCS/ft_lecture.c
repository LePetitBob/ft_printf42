/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lecture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 16:32:11 by vduriez           #+#    #+#             */
/*   Updated: 2021/08/27 08:26:33 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/ft_printf.h"

int	ft_putstr(char *s)
{
	int			i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putstrn(char *s, int i, int j)
{
	int	x;

	x = 0;
	while (s[i + x] && x < j)
	{
		write(1, &s[i + x], 1);
		x++;
	}
	return (i);
}

t_flags	ft_flaginit(void)
{
	t_flags	flags;

	flags.dot = -1;
	flags.signe = 0;
	flags.minus = 0;
	flags.type = '0';
	flags.precision = 0;
	flags.zero = 0;
	flags.width = -1;
	return (flags);
}

int	ft_type(t_flags flags, va_list args, char *text, int i)
{
	if (flags.type == 'c')
		return (ft_treat_char(va_arg(args, int), flags));
	if (flags.type == 's' || flags.type == 'S')
		return (ft_treat_string(va_arg(args, char *), flags));
	if (flags.type == 'p')
		return (ft_treat_pointer(va_arg(args, unsigned long long), flags));
	if (flags.type == 'd' || flags.type == 'i')
		return (ft_treat_double(va_arg(args, int), flags));
	if (flags.type == 'u')
		return (ft_treat_uint((unsigned int)va_arg(args, unsigned int), flags));
	if (flags.type == 'x')
		return (ft_treat_hexa(va_arg(args, unsigned int), flags, 0));
	if (flags.type == 'X')
		return (ft_treat_hexa(va_arg(args, unsigned int), flags, 1));
	if (flags.type == '%')
		return (ft_flagapp(flags, "%"));
	write(1, &text[i + 1], 1);
	return (1);
}

int	ft_lecture(char *text, va_list args)
{
	t_flags		flags;
	int			output;
	int			i;
	int			j;

	i = 0;
	output = 0;
	while (text[i])
	{
		flags = ft_flaginit();
		j = 0;
		while (text[i + j] != '%' && text[i + j])
			j++;
		ft_putstrn(text, i, j);
		output += j;
		if (text[i + j] == '\0')
			break ;
		flags = ft_chkflg(text, i + j, flags, args);
		output += ft_type(flags, args, text, i + j);
		if (flags.type == 'E')
			i += j + 2;
		else
			i = ft_skip(text, ++i + j) + 1;
	}
	return (output);
}
