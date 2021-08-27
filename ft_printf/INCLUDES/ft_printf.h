/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduriez <vduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 15:01:38 by vduriez           #+#    #+#             */
/*   Updated: 2021/08/27 09:54:05 by vduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct s_flags
{
	int				minus;
	int				signe;
	int				zero;
	int				dot;
	int				precision;
	int				width;
	char			type;
}					t_flags;

int					ft_printf(const char *input, ...);
int					ft_putstr(char *s);
int					ft_size(unsigned int n);
int					ft_atoi(const char *str);
int					ft_strlen(char *str);
int					ft_skip(char *text, int i);
int					ft_lecture(char *input, va_list args);
int					ft_flagapp(t_flags flags, char *treat_res);
t_flags				ft_chkflg(char *text, int i, t_flags flags, va_list args);
t_flags				ft_checkflagwidth(t_flags flags, int len_treat_res);
char				*ft_strncpy(char *dest, char *src, t_flags flags);
char				*ft_strrcpy(char *dest, char *src, t_flags flags);
int					ft_precision(char *treat_res, t_flags flags);
int					ft_treat_char(int c, t_flags flags);
int					ft_treat_pointer(unsigned long long pointer, t_flags flags);
int					ft_treat_double(int nbr, t_flags flags);
int					ft_treat_hexa(unsigned int nbr, t_flags flags, int maj);
int					ft_treat_percent(void);
int					ft_treat_string(char *str, t_flags flags);
int					ft_treat_uint(unsigned int nbr, t_flags flags);
int					ft_strlen(char *str);
char				*ft_strdup(const char *s1);
int					ft_getlength(char *text, int i);

#endif
