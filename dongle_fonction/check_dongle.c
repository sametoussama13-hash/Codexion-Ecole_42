/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dongle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osamet <oussama.samet@learner.42.tech>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 14:26:23 by osamet            #+#    #+#             */
/*   Updated: 2026/11/23 19:28:54 by osamet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../codexion.h"

int	lock_dongle(t_coder *coder, t_config *config)
{
	if (coder->left == coder->right)
		return (1);
	if (check_dongle(coder, config) != 0)
	{
		unlock_mutex(coder->left, coder->right);
		return (1);
	}
	if (config->scheduler == FIFO && scheduler_fifo(coder) == 0)
		return (0);
	// else
	// 	scheduler_fifo(coder);
	return (1);
}

int		check_dongle(t_coder *coder, t_config *config)
{
	lock_mutex(coder->left, coder->right);
	if (config->scheduler == FIFO)
	{
		handle_heap_fifo(coder, coder->left);
		handle_heap_fifo(coder, coder->right);
	}
	if (coder->left->is_taken == 1|| check_cool_dongle(coder->left) != 0)
		return (1);
	if (coder->right->is_taken == 1 || check_cool_dongle(coder->right) != 0)
		return (1);
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
