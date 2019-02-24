/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:31:04 by frrobert          #+#    #+#             */
/*   Updated: 2018/11/15 12:52:50 by frrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1temp;
	unsigned char	*s2temp;

	s1temp = (unsigned char *)s1;
	s2temp = (unsigned char *)s2;
	if (s1 == s2 || n == 0)
		return (0);
	while (n--)
	{
		if (*s1temp != *s2temp)
			return (*s1temp - *s2temp);
		if (n)
		{
			s1temp++;
			s2temp++;
		}
	}
	return (0);
}
