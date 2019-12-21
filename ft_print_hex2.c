/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ham <aait-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 22:28:50 by aait-ham          #+#    #+#             */
/*   Updated: 2019/12/21 18:05:38 by aait-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_strrev(char *str)
{
	int		length;
	int		j;
	int		i;
	char	temp;

	length = 0;
	while (str[length] != '\0')
	{
		length++;
	}
	i = 0;
	j = length - 1;
	while (i < j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
	return (str);
}

int			nb_size(size_t nb)
{
	int		size;

	size = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		size++;
		nb /= 16;
	}
	return (size);
}

char		*ft_base(size_t nb, char *base)
{
	char	*to;
	int		i;

	i = 0;
	to = (char *)malloc((nb_size(nb) + 1) * sizeof(char));
	if (nb == 0)
		to[i++] = '0';
	while (nb >= 10)
	{
		to[i++] = base[nb % 16];
		nb /= 16;
	}
	if (nb < 10 && nb > 0)
		to[i++] = base[nb];
	to[i] = '\0';
	to = ft_strrev(to);
	return (to);
}

void		ft_fill_hex(t_param **par, t_flags *fl)
{
	if (fl->is_zero == 1)
		ft_set(&(*par), 0, (fl->wi - (*par)->ns) + 1);
	else if (fl->wi > (*par)->ns && fl->prec == (*par)->ns)
		ft_set(&(*par), (fl->wi - (*par)->ns), 1);
	else if (fl->wi > fl->prec && fl->prec > (*par)->ns)
		ft_set(&(*par), fl->wi - fl->prec, fl->prec - (*par)->ns + 1);
	else if (fl->wi >= (fl->prec + 1) && fl->prec >= (*par)->ns)
		ft_set(&(*par), (fl->wi - fl->prec), fl->prec - 1);
	else if (fl->wi > fl->prec && fl->prec >= (*par)->ns)
		ft_set(&(*par), (fl->wi - fl->prec), (fl->prec - (*par)->ns));
	else if (fl->wi >= (fl->prec + 1) && fl->prec >= (*par)->ns)
		ft_set(&(*par), fl->wi - fl->prec + 1, fl->prec - (*par)->ns);
	else if (fl->wi < fl->prec && fl->prec > (*par)->ns)
		ft_set(&(*par), 0, (fl->prec - (*par)->ns) + 1);
	else if (fl->wi <= fl->prec && fl->prec >= (*par)->ns)
		ft_set(&(*par), 0, (fl->prec - (*par)->ns) + 1);
	else if (fl->wi <= fl->prec && fl->prec <= (*par)->ns)
		ft_set(&(*par), 0, 0);
	else if (fl->wi >= fl->prec && fl->format != 'p')
		ft_set(&(*par), (fl->wi - (*par)->ns) + 1, 0);
	else if (fl->wi >= fl->prec && fl->prec < (*par)->ns)
		ft_set(&(*par), (fl->wi - (*par)->ns), 0);
	else if (fl->wi > (*par)->ns)
		ft_set(&(*par), (fl->wi - fl->prec) - 1, fl->prec);
}

void		ft_ini_para_hex(t_param *par, va_list op, t_flags **fl)
{
	(*par).z = 0;
	(*par).s = 0;
	(*par).dd = va_arg(op, unsigned int);
	(*par).n = 0;
	(*par).ns = nb_size((*par).dd) + 1;
	ft_fill_hex(&(par), *fl);
}
