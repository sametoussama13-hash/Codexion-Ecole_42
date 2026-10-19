/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osamet <oussama.samet@learner.42.tech>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 23:41:59 by osamet            #+#    #+#             */
/*   Updated: 2026/10/19 00:53:40 by osamet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "codexion.h"


int	main(int argc, char **argv)
{
	t_config	*config;

	if (argc != 9)
	{
		printf("error number argument %d given we need 8\n", argc);
		exit (1);
	}
	config = malloc(sizeof(t_config));
	if (config == NULL)
	{
		printf("faild to malloc config struct");
		exit (1);
	}
	config->time_start = time_ms();
	parsing(argc, argv, config);
	build_struct(config);
	
	all_free(config);
	return (0);
}
