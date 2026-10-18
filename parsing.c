/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osamet <oussama.samet@learner.42.tech>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 15:16:33 by osamet            #+#    #+#             */
/*   Updated: 2026/10/18 19:03:42 by osamet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	parsing(int argc, char **argv, t_config *config)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (i == 1 || i == 6)
			parsing_nbr(argv[i], config, i);
		else if ((i > 1 && i < 6) || i == 7)
			parsing_time(argv[i], config, i);
		else if (i == 8)
			scheduler(argv[i], config);
		i++;
	}
}

const char	*name_argument(int i)
{
	const char	*arguments[9];

	if (i < 1 || i > 9)
		exit(1);
	arguments[1] = "number_of_coders";
	arguments[2] = "time_to_burnout";
	arguments[3] = "time_to_compile";
	arguments[4] = "time_to_debug";
	arguments[5] = "time_to_refactor";
	arguments[6] = "number_of_compiles_required";
	arguments[7] = "dongle_cooldown";
	arguments[8] = "scheduler";
	return (arguments[i]);
}
