/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_nbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osamet <oussama.samet@learner.42.tech>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 17:36:56 by osamet            #+#    #+#             */
/*   Updated: 2026/10/19 00:55:01 by osamet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../codexion.h"

void	parsing_nbr(char *str, t_config *config, int i)
{
	if (i == 1)
	{
		config->nbr_coders = convert_nbr(str, i);
		config->nbr_dongles = config->nbr_coders;
	}
	if (i == 6)
		config->nbr_of_compiles_re = convert_nbr(str, i);
}

int	convert_nbr(char *str, int i)
{
	int	nbr;

	if (ft_isdigit(str) != 0)
	{
		printf("error: %s is not digit %s",name_argument(i), str);
		exit(1);
	}
	nbr = atoi(str);
	if (nbr < 1)
	{
		printf("error: %s should not be less than 1",name_argument(i));
		exit(1);
	}
	return (nbr);
}
