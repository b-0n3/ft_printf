/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 03:14:30 by aait-ham          #+#    #+#             */
/*   Updated: 2019/10/11 22:13:08 by aait-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if (c == '\n' || c == '\f' || c == ' ' ||
			c == '\r' || c == '\v' || c == '\t' || c == '0')
		return (1);
	return (0);
}

int			ft_atoi( char **str)
{
	int				i;
	int				n;
	int				signe;


	n = 0;
	i = 0;
	signe = 1;
	while (ft_isspace(*(*str)))
		*str += 1;
	if (*(*str) == '-' || *(*str) == '+')
	{
		if (**str == '-')
			signe = -1;
	}
	while (*(*str) >= '0' && (*(*str) <= '9') && *(*str) != '\0')
	{
		if (((unsigned long)n > 9223372036854775807 / 10) ||
				(((unsigned long)n == 9223372036854775807 / 10) &&
				((unsigned long)n % 10) > 7))
			return ((signe > 0 ? -1 : 0));
		n = n * 10 + *(*str) - '0';
		*str += 1;
	}
	return (n * signe);
}
