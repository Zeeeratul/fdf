/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 08:54:03 by frrobert          #+#    #+#             */
/*   Updated: 2018/11/12 10:53:00 by frrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	lenght(int n)
{
	size_t i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char			*ft_itoa(int n)
{
	char			*str;
	size_t			len;
	unsigned int	ntemp;

	len = lenght(n);
	ntemp = n;
	if (n < 0)
	{
		ntemp = -n;
		len++;
	}
	if (!(str = ft_strnew(len)))
		return (NULL);
	str[--len] = ntemp % 10 + '0';
	while (ntemp /= 10)
		str[--len] = ntemp % 10 + '0';
	if (n < 0)
		*(str + 0) = '-';
	return (str);
}
