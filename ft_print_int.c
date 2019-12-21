/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ham <aait-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 23:58:21 by aait-ham          #+#    #+#             */
/*   Updated: 2019/12/21 15:19:30 by aait-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_ini_para(t_param *par, va_list op, t_flags **fl)
{
	(*par).dd = 0;
	(*par).z = 0;
	(*par).s = 0;
	(*par).tp = va_arg(op, int);
	(*par).n = check_neg(&((*par).tp));
	(*par).ns = ft_nb_size((*par).tp, (*par).n);
	ft_fill(&(par), *fl);
}

char		*ft_fill_ar2(t_param par)
{
	char	*to_p;
	int		i;
	char	*tmp;

	i = 0;
	to_p = (char *)malloc((par.s + par.z + par.ns + 1) * sizeof(char ));
	if (!to_p)
		return (NULL);
	if (par.n)
		to_p[i++] = '-';
	while ((par.z)--)
		to_p[i++] = '0';
	to_p[i] = '\0';
	tmp = ft_strdup(to_p);
	free(to_p);
	if (!(to_p = ft_strjoin(tmp, ft_itoa(par.tp))))
		return (NULL);
	free(tmp);
	i = ft_strlen(to_p);
	while ((par.s)--)
		to_p[i++] = ' ';
	to_p[i] = '\0';
	return (to_p);
}

char		*ft_fill_ar3(t_param par)
{
	char	*to_p;
	int		i;
	char	*tmp;

	i = 0;
	to_p = (char *)malloc((par.s + par.z + par.ns + 1) * sizeof(char));
	if (!to_p)
		return (NULL);
	while ((par.s)--)
		to_p[i++] = ' ';
	if (par.n)
		to_p[i++] = '-';
	while ((par.z)--)
		to_p[i++] = '0';
	to_p[i] = '\0';
	tmp = ft_strdup(to_p);
	free(to_p);
	to_p = ft_strjoin(tmp, ft_itoa(par.tp));
	if (tmp != NULL)
		free(tmp);
	return (to_p);
}

char		*ft_fill_ar(t_param par, t_flags *fl)
{
	char	*to_p;
	int		i;

	i = 0;
	if (fl->prec <= 0 && par.tp == 0 && fl->is_m == 0 && fl->has_pre == 1)
		return (ft_fill_zer(fl));
	if (fl->is_front_or_end == 0)
		to_p = ft_fill_ar3(par);
	else
		to_p = ft_fill_ar2(par);
	return (to_p);
}

char		*ft_print_int(va_list op, t_flags **fl)
{
	char	*to_print;
	t_param	par;

	if ((*fl)->prec_arg == 1 || (*fl)->wi_arg == 1)
		ft_handle_arg(op, &(*fl));
	ft_ini_para(&par, op, &(*fl));
	to_print = ft_fill_ar(par, *fl);
	return (to_print);
}
