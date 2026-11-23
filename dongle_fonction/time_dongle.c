/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_dongle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osamet <oussama.samet@learner.42.tech>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 14:26:23 by osamet            #+#    #+#             */
/*   Updated: 2026/11/23 19:28:57 by osamet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../codexion.h"

int	check_cool_dongle(t_dongle *dongle)
{
	unsigned long long	now;

	now = time_ms();
	if (dongle->available_at <= now)
		return (0);
	return (1);
}

void	init_cool_dongle(t_dongle *dongle, t_config *config)
{
	dongle->available_at = time_ms() + config->dongle_cooldown;
}
