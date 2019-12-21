/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ham <aait-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 22:10:18 by aait-ham          #+#    #+#             */
/*   Updated: 2019/12/21 15:21:59 by aait-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_fill_ar_hex(t_param p, t_flags *fl)
{
	char	*to_p;
	int		i;
	char	*tmp;

	i = 0;
	if (fl->prec <= 0 && p.dd == 0 && fl->is_m == 0 && fl->has_pre == 1)
		return (ft_fill_zer(fl));
	if (fl->is_front_or_end == 0)
	{
		if (!(to_p = (char *)malloc((p.s + p.z + p.ns + 1) * sizeof(char))))
			return (NULL);
		while ((p.s)--)
			to_p[i++] = ' ';
		while ((p.z)--)
			to_p[i++] = '0';
		to_p[i] = '\0';
		tmp = ft_strdup(to_p);
		free(to_p);
		to_p = ft_strjoin(tmp, ft_base(p.dd, "0123456789abcdef"));
		free(tmp);
	}
	else
		to_p = ft_fill_h2(p);
	return (to_p);
}

char		*ft_fill_he2(t_param p)
{
	char	*to_p;
	int		i;
	char	*tmp;

	i = 0;
	if (!(to_p = (char *)malloc((p.s + p.z + p.ns + 1) * sizeof(char))))
		return (NULL);
	while ((p.z)--)
		to_p[i++] = '0';
	to_p[i] = '\0';
	tmp = ft_strdup(to_p);
	free(to_p);
	to_p = ft_strjoin(tmp, ft_base(p.dd, "0123456789ABCDEF"));
	free(tmp);
	i = ft_strlen(to_p);
	while ((p.s)--)
		to_p[i++] = ' ';
	to_p[i] = '\0';
	return (to_p);
}

char		*ft_fill_ar_hex2(t_param p, t_flags *fl)
{
	char	*to_p;
	int		i;
	char	*tmp;

	i = 0;
	if (fl->prec <= 0 && p.dd == 0 && fl->is_m == 0 && fl->has_pre == 1)
		return (ft_fill_zer(fl));
	if (fl->is_front_or_end == 0)
	{
		if (!(to_p = (char *)malloc((p.s + p.z + p.ns + 1) * sizeof(char))))
			return (NULL);
		while ((p.s)--)
			to_p[i++] = ' ';
		while ((p.z)--)
			to_p[i++] = '0';
		to_p[i] = '\0';
		tmp = ft_strdup(to_p);
		free(to_p);
		to_p = ft_strjoin(tmp, ft_base(p.dd, "0123456789ABCDEF"));
		free(tmp);
	}
	else
		to_p = ft_fill_he2(p);
	return (to_p);
}

char		*ft_print_hex(va_list op, t_flags **fl)
{
	char	*to_print;
	t_param	par;

	if ((*fl)->prec_arg == 1 || (*fl)->wi_arg == 1)
		ft_handle_arg(op, &(*fl));
	ft_ini_para_hex(&par, op, &(*fl));
	to_print = ft_fill_ar_hex(par, *fl);
	return (to_print);
}

char		*ft_print_hex2(va_list op, t_flags **fl)
{
	char	*to_print;
	t_param	par;

	if ((*fl)->prec_arg == 1 || (*fl)->wi_arg == 1)
		ft_handle_arg(op, &(*fl));
	ft_ini_para_hex(&par, op, &(*fl));
	to_print = ft_fill_ar_hex2(par, *fl);
	return (to_print);
}
