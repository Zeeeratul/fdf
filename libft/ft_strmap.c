/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 09:32:28 by frrobert          #+#    #+#             */
/*   Updated: 2018/11/10 12:00:03 by frrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char			*ret;
	char			*stemp;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	stemp = (char *)s;
	ret = (char *)malloc((ft_strlen(stemp) + 1) * sizeof(char));
	if (ret == NULL)
		return (NULL);
	i = -1;
	while (s[++i])
		ret[i] = f(stemp[i]);
	ret[i] = '\0';
	return (ret);
}
