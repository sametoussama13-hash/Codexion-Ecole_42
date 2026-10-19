/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_time.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osamet <oussama.samet@learner.42.tech>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 15:16:33 by osamet            #+#    #+#             */
/*   Updated: 2026/10/19 00:55:31 by osamet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../codexion.h"

void	parsing_time(char *str, t_config *config, int i)
{
	if (i == 2)
		config->time_to_burnout = time_convert(str, i);
	if (i == 3)
		config->time_to_compile = time_convert(str, i);
	if (i == 4)
		config->time_to_debug = time_convert(str, i);
	if (i == 5)
		config->time_to_refactor = time_convert(str, i);
	if (i == 7)
		config->dongle_cooldown = time_convert(str, i);
}

unsigned long long	time_convert(char *str, int i)
{
	unsigned long long	time;

	if (ft_isdigit(str) != 0)
	{
		printf("error: %s is not digit %s", name_argument(i), str);
		exit(1);
	}
	time = (unsigned long long)ft_atoull(str);
	if (time < 1)
	{
		printf("error: %s should not be less than 1", name_argument(i));
		exit(1);
	}
	return time;
}