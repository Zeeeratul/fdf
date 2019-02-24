/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 12:02:21 by frrobert          #+#    #+#             */
/*   Updated: 2018/11/12 09:49:39 by frrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*res;

	if (s == NULL)
		return (NULL);
	res = malloc(sizeof(char) * (len + 1));
	if (res)
	{
		while (start--)
			s++;
		ft_strncpy(res, s, len);
		res[len] = '\0';
	}
	return (res);
}
