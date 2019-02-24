/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:01:05 by frrobert          #+#    #+#             */
/*   Updated: 2018/11/13 12:02:49 by frrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	recursive_nbr_fd(int n, int fd)
{
	if ((n / 10 > 0))
		recursive_nbr_fd(n / 10, fd);
	ft_putchar_fd((n % 10) + '0', fd);
}

void			ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	recursive_nbr_fd(n, fd);
}
