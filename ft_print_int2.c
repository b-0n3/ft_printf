/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ham <aait-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 22:38:51 by aait-ham          #+#    #+#             */
/*   Updated: 2019/12/21 15:41:06 by aait-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_nb_size(long nb, int is_neg)
{
	int		size;
	long	bc;

	bc = nb;
	size = 0;
	if (is_neg == 1 || bc == 0)
		size++;
	while (bc > 0)
	{
		bc /= 10;
		size++;
	}
	return (size);
}

int			check_neg(long long *tp)
{
	if (*tp < 0)
	{
		*tp *= -1;
		return (1);
	}
	return (0);
}

void		ft_set(t_param **par, int s, int z)
{
	(**par).s = (s > 0 ? s : 0);
	(**par).z = (z > 0 ? z : 0);
}

void		ft_fill(t_param **par, t_flags *fl)
{
	if (fl->is_zero == 1 && fl->is_front_or_end == 0)
		ft_set(&(*par), 0, (fl->wi - (*par)->ns));
	else if (fl->wi > (*par)->ns && fl->prec == (*par)->ns && (*par)->tp != 0)
		ft_set(&(*par), (fl->wi - (*par)->ns), 0);
	else if (fl->wi > fl->prec && fl->prec > (*par)->ns && (*par)->n == 1)
		ft_set(&(*par), (fl->wi - fl->prec) - 1, (fl->prec - (*par)->ns) + 1);
	else if (fl->wi >= (fl->prec + 1) && fl->prec >= (*par)->ns
			&& (*par)->tp == 0)
		ft_set(&(*par), (fl->wi - fl->prec), fl->prec - 1);
	else if (fl->wi > fl->prec && fl->prec >= (*par)->ns)
		ft_set(&(*par), (fl->wi - fl->prec), (fl->prec - (*par)->ns));
	else if (fl->wi >= (fl->prec + 1) && fl->prec >= (*par)->ns)
		ft_set(&(*par), (fl->wi - fl->prec) + 1, (fl->prec - (*par)->ns));
	else if (fl->wi < fl->prec && fl->prec > (*par)->ns && (*par)->n == 1)
		ft_set(&(*par), 0, (fl->prec - (*par)->ns) + 1);
	else if (fl->wi <= fl->prec && fl->prec >= (*par)->ns && (*par)->n == 1)
		ft_set(&(*par), 0, (fl->prec - (*par)->ns) + 1);
	else if (fl->wi <= fl->prec && fl->prec >= (*par)->ns)
		ft_set(&(*par), 0, (fl->prec - (*par)->ns));
	else if (fl->wi <= fl->prec && fl->prec <= (*par)->ns)
		ft_set(&(*par), 0, 0);
	else if (fl->wi >= fl->prec && fl->prec <= (*par)->ns)
		ft_set(&(*par), (fl->wi - (*par)->ns), 0);
	else if (fl->wi > (*par)->ns && (*par)->tp == 0)
		ft_set(&(*par), (fl->wi - fl->prec) - 1, fl->prec);
}

void		ft_handle_arg(va_list op, t_flags **fl)
{
	long	arg;

	if ((*fl)->wi_arg != 0)
	{
		arg = va_arg(op, int);
		if (arg < 0)
		{
			(*fl)->is_front_or_end = 1;
			arg *= -1;
		}
		(*fl)->wi = (int)arg;
	}
	if ((*fl)->prec_arg != 0)
	{
		arg = va_arg(op, int);
		if (arg < 0)
		{
			(*fl)->is_m = 1;
			(*fl)->prec = 0;
			return ;
		}
		(*fl)->prec = (int)arg;
	}
}
