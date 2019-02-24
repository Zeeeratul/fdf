/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 11:25:23 by frrobert          #+#    #+#             */
/*   Updated: 2018/11/09 15:36:12 by frrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	unsigned int x;
	unsigned int pos;

	x = 0;
	pos = 0;
	pos = 0;
	if (needle[0] == '\0')
		return ((char *)&haystack[pos]);
	while (haystack[pos] != '\0')
	{
		if (haystack[pos] == needle[0])
		{
			x = 1;
			while (needle[x] != '\0' && haystack[pos + x] == needle[x])
				x++;
			if (needle[x] == '\0')
				return ((char *)&haystack[pos]);
		}
		pos++;
	}
	return (NULL);
}
