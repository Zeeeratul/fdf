/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 10:26:23 by frrobert          #+#    #+#             */
/*   Updated: 2018/11/15 13:54:57 by frrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	char*s12;
	char*s22;

	if (s1 && s2)
	{
		s12 = (char *)s1;
		s22 = (char *)s2;
		if (ft_strlen(s12) < ft_strlen(s22))
			return (0);
		while (*s12)
		{
			if (*s12 != *s22)
				return (0);
			s12++;
			s22++;
		}
		return (1);
	}
	return (0);
}
