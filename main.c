/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdelahay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 11:40:15 by cdelahay          #+#    #+#             */
/*   Updated: 2018/12/09 13:22:55 by cdelahay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	t_env	env;

	if (argc > 2)
	{
		ft_putstr("only one file needed\n");
		return (0);
	}
	if (argc == 1)
	{
		ft_putstr("input file missing\n");
		return (0);
	}
	if (create_map(&env, argv[1]) == -1)
		return (EXIT_FAILURE);
	fdf(&env);
	free_map(&env);
	return (0);
}
