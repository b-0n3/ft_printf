/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ham <aait-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 23:54:35 by aait-ham          #+#    #+#             */
/*   Updated: 2019/12/21 00:40:48 by aait-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_fd(char *s, int fd)
{
	char ch;

	ch = 0;
	if (!s)
		return ;
	while (*s)
	{
		if (*s == -126 && s[1] == -70)
		{
			write(fd, &ch, 1);
			s++;
		}
		else
			ft_putchar_fd(*s, fd);
		s++;
	}
}
