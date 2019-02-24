/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:17:23 by frrobert          #+#    #+#             */
/*   Updated: 2018/11/11 13:47:55 by frrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *stemp;

	stemp = (unsigned char *)s;
	while (n--)
	{
		if (*stemp == (unsigned char)c)
			return (stemp);
		stemp++;
	}
	return (NULL);
}
