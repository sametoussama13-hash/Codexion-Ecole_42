/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_dongle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osamet <oussama.samet@learner.42.tech>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 14:26:23 by osamet            #+#    #+#             */
/*   Updated: 2026/11/21 16:19:16 by osamet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../codexion.h"

int	check_cool_dongle(t_dongle *left, t_dongle *right)
{
	unsigned long long	now;

	now = time_ms();
	if (left->available_at <= now && right->available_at <= now)
		return (0);
	return (1);
}

void	init_cool_dongle(t_dongle *dongle, t_config *config)
{
	dongle->available_at = time_ms() + config->dongle_cooldown;
}
