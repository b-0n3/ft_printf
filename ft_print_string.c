/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ham <aait-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 23:29:44 by aait-ham          #+#    #+#             */
/*   Updated: 2019/12/21 18:02:02 by aait-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_fill_string2(t_string par, t_flags *fl)
{
	char		*tp;
	int			i;
	int			j;
	int			a;
	int			z;

	i = 0;
	j = 0;
	a = 0;
	z = 0;
	tp = (char *)malloc((par.s + (par.z != 0 ?
					par.z : par.ns) + 1) * sizeof(char));
	if (fl->has_pre != 0)
	{
		free(tp);
		return (ft_fill_str_ha(par, fl));
	}
	tp[i] = '\0';
	tp = ft_strjoin(tp, par.tp);
	i += ft_strlen(tp);
	while ((par.s)-- > a)
		tp[i++] = ' ';
	tp[i] = '\0';
	return (tp);
}

char			*ft_fill_str2(t_string par, t_flags *fl)
{
	char		*tp;
	int			i;
	int			j;
	int			a;
	int			z;

	i = 0;
	j = 0;
	a = 0;
	z = 0;
	tp = (char *)malloc((par.s + (par.z != 0 ?
		par.z : par.ns) + 1) * sizeof(char));
	if (fl->has_pre != 0 && fl->prec <= 0 && par.tp[0] != '\0')
		a = 1;
	if (fl->has_pre && fl->prec == -1 && par.tp[0] == '\0')
		a = 1;
	if (fl->wi == par.ns && fl->prec == 0)
		par.s += par.ns;
	while ((par.s)-- > a)
		tp[i++] = ' ';
	tp[i] = '\0';
	return (tp);
}

char			*ft_fill_string(t_string par, t_flags *fl)
{
	char		*tp;
	int			i;
	int			j;
	int			z;

	i = 0;
	j = 0;
	z = 0;
	if (fl->is_front_or_end == 0)
	{
		tp = ft_fill_str2(par, fl);
		i = ft_strlen(tp);
		if (fl->has_pre != 0)
		{
			while ((par.z)-- > z && par.tp[j] != '\0')
				tp[i++] = par.tp[j++];
			tp[i] = '\0';
			return (tp);
		}
		tp[i] = '\0';
		tp = ft_strjoin(tp, par.tp);
	}
	else
		tp = ft_fill_string2(par, fl);
	return (tp);
}

char			*ft_print_string(va_list op, t_flags **fl)
{
	char		*to_print;
	t_string	par;

	if ((*fl)->prec_arg == 1 || (*fl)->wi_arg == 1)
		ft_handle_arg_string(op, &(*fl));
	ft_ini(&par, op, &(*fl));
	to_print = ft_fill_string(par, *fl);
	return (to_print);
}
