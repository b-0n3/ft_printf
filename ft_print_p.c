/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ham <aait-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 19:52:55 by aait-ham          #+#    #+#             */
/*   Updated: 2019/12/21 00:21:25 by aait-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_fill_ar_p2(t_param par)
{
	char	*to_p;
	int		i;
	char	*tmp;

	i = 0;
	if (!(to_p = (char *)malloc((par.s + par.z + par.ns + 1) * sizeof(char ))))
		return (NULL);
	while ((par.z)--)
		to_p[i++] = '0';
	to_p[i] = '\0';
	to_p = ft_strjoin("0x", to_p);
	tmp = ft_strdup(to_p);
	free(to_p);
	to_p = ft_strjoin(tmp, ft_base(par.dd, "0123456789abcdef"));
	free(tmp);
	i = ft_strlen(to_p);
	while ((par.s)-- > 1)
		to_p[i++] = ' ';
	to_p[i] = '\0';
	return (to_p);
}

char		*ft_fill_ar_p(t_param par, t_flags *fl)
{
	char	*to_p;
	int		i;

	i = 0;
	if ((par.dd == 0 && fl->has_pre == 1 && fl->prec <= 0))
		return (ft_fill_zero(par, fl));
	if (fl->is_front_or_end == 0)
	{
		to_p = (char *)malloc((par.s + par.z + par.ns + 1) * sizeof(char ));
		if (!to_p)
			return (NULL);
		while ((par.s)-- > 1)
			to_p[i++] = ' ';
		to_p[i] = '\0';
		to_p = ft_strjoin(to_p, "0x");
		i = ft_strlen(to_p);
		while ((par.z)--)
			to_p[i++] = '0';
		to_p[i] = '\0';
		to_p = ft_strjoin(to_p, ft_base(par.dd, "0123456789abcdef"));
	}
	else
		to_p = ft_fill_ar_p2(par);
	return (to_p);
}

char		*ft_print_p(va_list op, t_flags **fl)
{
	char	*to_print;
	t_param	par;

	if ((*fl)->prec_arg == 1 || (*fl)->wi_arg == 1)
		ft_handle_arg(op, &(*fl));
	ft_ini_para_p(&par, op, &(*fl));
	to_print = ft_fill_ar_p(par, *fl);
	return (to_print);
}

void		ft_handle_zero(char **str, t_flags **fl)
{
	while (**str == '0')
		*str += 1;
	(*fl)->is_zero = 1;
}
