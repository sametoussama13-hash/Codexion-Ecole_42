/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dongle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osamet <oussama.samet@learner.42.tech>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 14:26:23 by osamet            #+#    #+#             */
/*   Updated: 2026/11/19 20:39:21 by osamet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../codexion.h"

int	lock_dongle(t_dongle *left, t_dongle *right)
{
	if (left == right)
		return (1);
	lock_mutex(left, right);
	if (left->is_taken == 1 || right->is_taken == 1)
	{
		unlock_mutex(left, right);
		return (1);
	}
	left->is_taken = 1;
	right->is_taken = 1;
	unlock_mutex(left, right);

	return (0);
}

void	unlock_dongle(t_dongle *left, t_dongle *right)
{
	lock_mutex(left, right);
	left->is_taken = 0;
	right->is_taken = 0;
	unlock_mutex(left, right);
}