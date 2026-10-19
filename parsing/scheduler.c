/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scheduler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osamet <oussama.samet@learner.42.tech>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 17:52:00 by osamet            #+#    #+#             */
/*   Updated: 2026/10/19 01:28:04 by osamet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../codexion.h"

void	scheduler(char *str, t_config *config)
{
	if (ft_strcamp(str, "fifo") == 0)
		config->scheduler = FIFO;
	else if (ft_strcamp(str, "edf") == 0)
		config->scheduler = EDF;
	else
	{
		printf("error: invalide Schudler %s", str);
		exit(1);
	}
}
