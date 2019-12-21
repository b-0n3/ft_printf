/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ham <aait-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 00:16:38 by aait-ham          #+#    #+#             */
/*   Updated: 2019/12/21 15:17:53 by aait-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				my_strchr_me(char *str, char c, char *set)
{
	while (ft_strchr(set, *str) == NULL)
	{
		if (*str == c)
			return (1);
		str += 1;
	}
	return (0);
}

t_flags			*ft_int_fla(void)
{
	t_flags		*fl;

	if (!(fl = (t_flags *)malloc(sizeof(t_flags))))
		return (NULL);
	fl->is_front_or_end = 0;
	fl->is_zero = 0;
	fl->format = 'z';
	fl->wi_arg = 0;
	fl->has_pre = 0;
	fl->prec_arg = 0;
	fl->wi = 0;
	fl->prec = -1;
	fl->is_m = 0;
	return (fl);
}

int				ft_check_zero(char *tp, int len)
{
	char		*tmp;

	len += ft_strlen(tp);
	tmp = ft_strchr(tp, -126);
	if (tmp != NULL)
	{
		tmp++;
		if (*tmp == -70)
			return (len - 1);
	}
	return (len);
}

char			*print_others(t_flags **fl, va_list op)
{
	char		*to_print;

	to_print = NULL;
	if ((*fl)->format == 's')
		to_print = ft_print_string(op, &(*fl));
	else if ((*fl)->format == 'p')
		to_print = ft_print_p(op, &(*fl));
	else if ((*fl)->format == 'u')
		to_print = ft_print_un(op, &(*fl));
	else if ((*fl)->format == 'x')
		to_print = ft_print_hex(op, &(*fl));
	else if ((*fl)->format == 'X')
		to_print = ft_print_hex2(op, &(*fl));
	else if ((*fl)->format == '%')
		to_print = ft_print_pr(op, &(*fl));
	return (to_print);
}

void			ft_print_arg(t_flags **fl, va_list op, int *len)
{
	char		*to_print;

	to_print = NULL;
	if ((*fl)->format == 'i' || (*fl)->format == 'd')
		to_print = ft_print_int(op, &(*fl));
	else if ((*fl)->format == 'c')
	{
		to_print = ft_print_char(op, &(*fl));
		*len = ft_check_zero(to_print, *len);
		ft_putstr_fd(to_print, 1);
		free(to_print);
		return ;
	}
	else
		to_print = print_others(&(*fl), op);
	if (!to_print)
		*len = -1;
	else
	{
		*len += ft_strlen(to_print);
		ft_putstr_fd(to_print, 1);
		free(to_print);
	}
}
