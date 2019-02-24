/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 09:03:50 by frrobert          #+#    #+#             */
/*   Updated: 2018/11/16 10:54:00 by frrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*desttemp;
	char	*srctemp;

	if (len == 0)
		return (dst);
	if (dst < src)
		return (ft_memcpy(dst, src, len));
	if (dst > src)
	{
		desttemp = (char *)dst;
		srctemp = (char *)src;
		while (len--)
			desttemp[len] = srctemp[len];
		return (dst);
	}
	return (dst);
}
