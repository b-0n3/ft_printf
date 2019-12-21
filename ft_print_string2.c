/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ham <aait-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 23:47:44 by aait-ham          #+#    #+#             */
/*   Updated: 2019/12/21 18:02:25 by aait-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_handle_arg_string(va_list op, t_flags **fl)
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
			if ((*fl)->wi == 0)
				(*fl)->has_pre = 0;
			else
				(*fl)->prec = (-arg) + 2;
			return ;
		}
		(*fl)->prec = (int)arg;
	}
}

void		ft_fill_str(t_string **par, t_flags *fl)
{
	if (fl->has_pre != 0)
	{
		(*par)->z = fl->prec != -1 ? fl->prec : 0;
		if (fl->prec == 0 && fl->wi > 2 && (*par)->tp[0] != '\0')
			(*par)->s = fl->wi - 2;
		else
		{
			if (fl->prec > (*par)->ns)
				(*par)->s = (fl->wi - (*par)->ns) > 0 ?
					(fl->wi - (*par)->ns) : 0;
			else
				(*par)->s = fl->wi - fl->prec > 0 ? fl->wi - fl->prec : 0;
		}
	}
	else
	{
		(*par)->s = (fl->wi - (*par)->ns) > 0 ? (fl->wi - (*par)->ns) : 0;
	}
}

void		ft_ini(t_string *par, va_list op, t_flags **fl)
{
	char	*tmp;

	(*par).z = 0;
	(*par).s = 0;
	tmp = va_arg(op, char *);
	if (tmp == NULL)
		(*par).tp = ft_strdup("(null)");
	else
		(*par).tp = ft_strdup(tmp);
	(*par).ns = ft_strlen((*par).tp);
	ft_fill_str(&(par), *fl);
}

char		*ft_fill_str_ha(t_string par, t_flags *fl)
{
	int		i;
	int		j;
	int		a;
	char	*tp;

	i = 0;
	j = 0;
	a = 0;
	tp = (char *)malloc((par.s + (par.z != 0 ?
					par.z : par.ns) + 1) * sizeof(char));
	if (fl->has_pre != 0 && fl->prec <= 0 && par.tp[0] != '\0')
		a = 1;
	if (fl->wi == par.ns && fl->prec == 0)
		par.s += par.ns;
	if (fl->wi > 0 && fl->prec == -1)
		a = 1;
	while ((par.z)-- > 0 && par.tp[j] != '\0')
		tp[i++] = par.tp[j++];
	while ((par.s)-- > a)
		tp[i++] = ' ';
	tp[i] = '\0';
	return (tp);
}
