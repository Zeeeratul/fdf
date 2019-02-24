/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:47:21 by frrobert          #+#    #+#             */
/*   Updated: 2018/11/16 11:12:13 by frrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned char	temp;
	char			*it1;
	char			*it2;

	if (!*needle)
		return ((void *)haystack);
	while (len-- && *haystack)
	{
		if (*haystack == *needle)
		{
			temp = len;
			it1 = (void *)haystack + 1;
			it2 = (void *)needle + 1;
			while (temp-- && *it1 && *it2 && *it1 == *it2)
			{
				++it1;
				++it2;
			}
			if (!*it2)
				return ((void *)haystack);
		}
		haystack++;
	}
	return (NULL);
}
