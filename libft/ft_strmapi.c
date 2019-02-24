/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frrobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 11:54:34 by frrobert          #+#    #+#             */
/*   Updated: 2018/11/10 12:01:53 by frrobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
		ret[i] = f(i, stemp[i]);
	ret[i] = '\0';
	return (ret);
}
