/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ham <aait-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 23:27:32 by aait-ham          #+#    #+#             */
/*   Updated: 2019/12/20 23:29:21 by aait-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_ini_para_p(t_param *par, va_list op, t_flags **fl)
{
	(*par).z = 0;
	(*par).s = 0;
	(*par).dd = va_arg(op, size_t);
	(*par).n = 0;
	(*par).ns = nb_size((*par).dd) + 1;
	ft_fill_hex(&(par), *fl);
}

char		*ft_fill_zero2(t_param par)
{
	char	*to_p;
	int		i;

	i = 0;
	to_p = (char *)malloc((par.s + par.z + par.ns + 1) * sizeof(char));
	if (!to_p)
		return (NULL);
	to_p[i] = '\0';
	to_p = ft_strjoin(to_p, "0x");
	i = ft_strlen(to_p);
	while ((par.z)-- >= 3)
		to_p[i++] = '0';
	i = ft_strlen(to_p);
	while ((par.s)-- > 0)
		to_p[i++] = ' ';
	to_p[i] = '\0';
	return (to_p);
}

char		*ft_fill_zero(t_param par, t_flags *fl)
{
	char	*to_p;
	int		i;

	i = 0;
	if (fl->is_front_or_end == 0)
	{
		to_p = (char *)malloc((par.s + par.z + par.ns + 1) * sizeof(char ));
		if (!to_p)
			return (NULL);
		while ((par.s)-- > 0)
			to_p[i++] = ' ';
		to_p[i] = '\0';
		to_p = ft_strjoin(to_p, "0x");
		i = ft_strlen(to_p);
		while ((par.z)-- >= 3)
			to_p[i++] = '0';
		to_p[i] = '\0';
	}
	else
		to_p = ft_fill_zero2(par);
	return (to_p);
}
