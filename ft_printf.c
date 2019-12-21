/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ham <aait-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 00:02:32 by aait-ham          #+#    #+#             */
/*   Updated: 2019/12/21 00:15:54 by aait-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_handle_other(char **str, t_flags **fl)
{
	if (**str == '*')
	{
		*str += 1;
		(*fl)->prec_arg = 1;
	}
	else if (ft_isdigit(**str))
		(*fl)->prec = ft_atoi(&(*str));
}

void		ft_handle_point(char **str, t_flags **fl)
{
	if (**str == '*')
	{
		*str += 2;
		if (**str == '*' || ft_isdigit(**str))
		{
			if (ft_isdigit(**str))
				(*fl)->prec = ft_atoi(&(*str));
			else
			{
				(*fl)->prec_arg = 1;
				*str += 1;
			}
		}
		(*fl)->wi_arg = 1;
	}
	else if (**str == '.')
	{
		*str += 1;
		ft_handle_other(&(*str), &(*fl));
	}
}

void		ft_check_other(char **str, va_list op, t_flags **fl, int *len)
{
	char	set[10];

	ft_strlcpy(set, "cspdiuxX%", 10);
	if (**str == '*')
	{
		(*fl)->wi_arg = 1;
		*str += 1;
	}
	if (ft_strchr(set, **str) != 0 && **str != '\0')
	{
		(*fl)->format = **str;
		*str += 1;
		ft_print_arg(&(*fl), op, &(*len));
	}
}

int			ft_check_flag(char **str, va_list op, int *len)
{
	t_flags	*fl;
	char	set[10];

	ft_strlcpy(set, "cspdiuxX%", 10);
	if (!(fl = ft_int_fla()))
		return (-1);
	*str += 1;
	if (**str == '-')
		ft_handle_minus(&(*str), &fl);
	else if (**str == '0')
		ft_handle_zero(&(*str), &fl);
	if ((my_strchr_me(*str, '.', set) == 1))
	{
		fl->has_pre = 1;
		fl->is_zero = 0;
		if (ft_isdigit(**str) == 1)
			fl->wi = ft_atoi(&(*str));
		ft_handle_point(&(*str), &fl);
	}
	if (ft_isdigit(**str) == 1)
		fl->wi = ft_atoi(&(*str));
	ft_check_other(&(*str), op, &fl, &(*len));
	return (1);
}

int			ft_printf(const char *str, ...)
{
	va_list	op;
	int		len;
	int		i;
	char	*stream;

	stream = (char *)str;
	i = 0;
	len = 0;
	va_start(op, str);
	while (*stream)
	{
		if (*stream == '%')
		{
			if (ft_check_flag(&stream, op, &len) == -1)
				return (-1);
			continue;
		}
		write(1, stream, 1);
		stream++;
		len++;
	}
	va_end(op);
	return (len);
}
