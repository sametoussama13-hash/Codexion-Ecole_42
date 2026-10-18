/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osamet <oussama.samet@learner.42.tech>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 23:41:59 by osamet            #+#    #+#             */
/*   Updated: 2026/10/18 20:15:40 by osamet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "codexion.h"


int	main(int argc, char **argv)
{
	int		i;
	t_config	*config;

	if (argc != 9)
	{
		printf("error number argument %d given we need 8\n", argc);
		exit (1);
	}
	config = malloc(sizeof(t_config));
	if (config == NULL)
		exit (1);
	config->time_start = time_ms();
	parsing(argc, argv, config);
	init_struct(config);
	
	all_free(config);
	return (0);
}
