/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osamet <oussama.samet@learner.42.tech>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 14:26:23 by osamet            #+#    #+#             */
/*   Updated: 2026/11/22 21:17:59 by osamet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../codexion.h"

void	lock_mutex(t_dongle *left, t_dongle *right)
{
	if (left->id < right->id)
	{
		pthread_mutex_lock(&left->mutex);
		pthread_mutex_lock(&right->mutex);
	}
	else
	{
		pthread_mutex_lock(&right->mutex);
		pthread_mutex_lock(&left->mutex);
	}
}

void	unlock_mutex(t_dongle *left, t_dongle *right)
{
	pthread_mutex_unlock(&left->mutex);
	pthread_mutex_unlock(&right->mutex);
}

int		check_stop(t_config *config)
{
	pthread_mutex_lock(&config->mutex_stop);
	if (config->stop == 1)
	{
		pthread_mutex_unlock(&config->mutex_stop);
		return (1);
	}
	pthread_mutex_unlock(&config->mutex_stop);
	return (0);
}
