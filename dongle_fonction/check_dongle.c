/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dongle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osamet <oussama.samet@learner.42.tech>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 14:26:23 by osamet            #+#    #+#             */
/*   Updated: 2026/11/21 16:19:00 by osamet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../codexion.h"

int	lock_dongle(t_dongle *left, t_dongle *right, t_coder *coder)
{
	if (left == right)
		return (1);
	lock_mutex(left, right);
	if (left->is_taken == 1 || right->is_taken == 1
		|| check_cool_dongle(left, right) != 0)
	{
		unlock_mutex(left, right);
		return (1);
	}
	left->is_taken = 1;
	logger(coder, "has taken a dongle");
	right->is_taken = 1;
	logger(coder, "has taken a dongle");
	unlock_mutex(left, right);

	return (0);
}

void	unlock_dongle(t_dongle *left, t_dongle *right, t_config *config)
{
	lock_mutex(left, right);
	left->is_taken = 0;
	init_cool_dongle(left, config);
	right->is_taken = 0;
	init_cool_dongle(right, config);
	unlock_mutex(left, right);
}
