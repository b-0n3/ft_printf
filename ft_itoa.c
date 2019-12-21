/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ham <aait-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 02:33:27 by aait-ham          #+#    #+#             */
/*   Updated: 2019/12/21 00:40:02 by aait-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int			taille(unsigned int nv)
{
	unsigned int	size;

	size = 0;
	while (nv >= 10)
	{
		nv /= 10;
		++size;
	}
	return (int)(size + 1);
}

char				*ft_itoa(long n)
{
	char			*tab;
	unsigned int	nb;
	unsigned int	i;
	unsigned int	size;

	if (n < 0)
		nb = n * -1;
	else
		nb = n;
	size = taille(nb);
	i = 0;
	tab = malloc(size + 1 + (n < 0 ? 1 : 0));
	if (tab == 0)
		return (0);
	if (n < 0 && (tab[i] = '-'))
		size++;
	i = size - 1;
	while (nb >= 10)
	{
		tab[i--] = (nb % 10 + 48);
		nb /= 10;
	}
	tab[i] = (nb % 10 + 48);
	tab[size] = '\0';
	return (tab);
}
