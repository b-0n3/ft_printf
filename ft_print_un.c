/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_un.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ham <aait-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 23:54:14 by aait-ham          #+#    #+#             */
/*   Updated: 2019/12/21 00:05:46 by aait-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_ini_para_un(t_param *par, va_list op, t_flags **fl)
{
	(*par).dd = 0;
	(*par).z = 0;
	(*par).s = 0;
	(*par).tp = va_arg(op, unsigned int);
	(*par).n = check_neg(&((*par).tp));
	(*par).ns = ft_nb_size((*par).tp, (*par).n);
	ft_fill(&(par), *fl);
}

char		*ft_print_un(va_list op, t_flags **fl)
{
	char	*to_print;
	t_param	par;

	if ((*fl)->prec_arg == 1 || (*fl)->wi_arg == 1)
		ft_handle_arg(op, &(*fl));
	ft_ini_para_un(&par, op, &(*fl));
	to_print = ft_fill_ar(par, *fl);
	return (to_print);
}

char		*ft_fill_zer(t_flags *fl)
{
	char	*tp;
	int		i;

	i = 0;
	if (fl->wi == 0)
		return (ft_strdup(""));
	tp = (char *)malloc((fl->wi + 1) * sizeof(char));
	while (fl->wi-- > 0)
		tp[i++] = ' ';
	tp[i] = '\0';
	return (tp);
}

char		*ft_fill_h2(t_param par)
{
	char	*to_p;
	int		i;

	i = 0;
	to_p = (char *)malloc((par.s + par.z + par.ns + 1) * sizeof(char ));
	if (!to_p)
		return (NULL);
	while ((par.z)--)
		to_p[i++] = '0';
	to_p[i] = '\0';
	to_p = ft_strjoin(to_p, ft_base(par.dd, "0123456789abcdef"));
	i = ft_strlen(to_p);
	while ((par.s)--)
		to_p[i++] = ' ';
	to_p[i] = '\0';
	return (to_p);
}

void		ft_handle_minus(char **str, t_flags **fl)
{
	while (**str == '-')
		*str += 1;
	(*fl)->is_front_or_end = 1;
}
