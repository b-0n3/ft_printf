/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ham <aait-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 19:53:07 by aait-ham          #+#    #+#             */
/*   Updated: 2019/12/20 22:42:02 by aait-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_print_char2(t_flags **fl, va_list op)
{
	int		i;
	int		j;
	char	*to_print;
	char	ch;

	i = 0;
	j = 1;
	ch = va_arg(op, int);
	if (!(to_print = (char *)malloc((((*fl)->wi > 1 ?
					(*fl)->wi : 1) + 3) * sizeof(char))))
		return (NULL);
	while (((*fl)->wi--) > j)
		to_print[i++] = ' ';
	if (ch == 0)
	{
		to_print[i++] = -126;
		to_print[i++] = -70;
	}
	else
		to_print[i++] = ch;
	to_print[i] = '\0';
	return (to_print);
}

char		*ft_print_char3(t_flags **fl, va_list op)
{
	int		i;
	int		j;
	char	*to_print;
	char	ch;

	i = 0;
	j = 1;
	ch = va_arg(op, int);
	if (!(to_print = (char *)malloc((((*fl)->wi > 1 ?
					(*fl)->wi : 1) + 3) * sizeof(char))))
		return (NULL);
	if (ch == 0)
	{
		to_print[i++] = -126;
		to_print[i++] = -70;
	}
	else
		to_print[i++] = ch;
	while (((*fl)->wi--) > j)
		to_print[i++] = ' ';
	to_print[i] = '\0';
	return (to_print);
}

char		*ft_print_char(va_list op, t_flags **fl)
{
	char	*to_print;
	int		i;
	int		j;

	j = 1;
	i = 0;
	if ((*fl)->prec_arg == 1 || (*fl)->wi_arg == 1)
		ft_handle_arg(op, &(*fl));
	if ((*fl)->is_front_or_end == 1)
	{
		to_print = ft_print_char3(&(*fl), op);
	}
	else
		to_print = ft_print_char2(&(*fl), op);
	return (to_print);
}

char		*ft_print_pr6(t_flags **fl)
{
	char	*to_print;
	int		i;

	i = 0;
	if (!(to_print = (char *)malloc((((*fl)->wi > 1 ?
				(*fl)->wi : 1) + 3) * sizeof(char))))
		return (NULL);
	if ((*fl)->is_zero == 0)
		while (((*fl)->wi--) > 1)
			to_print[i++] = ' ';
	else
		while (((*fl)->wi--) > 1)
			to_print[i++] = '0';
	to_print[i++] = '%';
	to_print[i] = '\0';
	return (to_print);
}

char		*ft_print_pr(va_list op, t_flags **fl)
{
	char	*to_print;
	int		i;

	i = 0;
	if ((*fl)->prec_arg == 1 || (*fl)->wi_arg == 1)
		ft_handle_arg(op, &(*fl));
	if (!(to_print = (char *)malloc((((*fl)->wi > 1 ?
					(*fl)->wi : 1) + 3) * sizeof(char))))
		return (NULL);
	if ((*fl)->is_front_or_end == 1)
	{
		to_print[i++] = '%';
		while (((*fl)->wi--) > 1)
			to_print[i++] = ' ';
		to_print[i] = '\0';
	}
	else
		to_print = ft_print_pr6(&(*fl));
	return (to_print);
}
