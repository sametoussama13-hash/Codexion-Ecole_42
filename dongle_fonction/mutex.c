/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osamet <oussama.samet@learner.42.tech>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 14:26:23 by osamet            #+#    #+#             */
/*   Updated: 2026/11/19 23:34:40 by osamet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../codexion.h"

void    lock_mutex(t_dongle *left, t_dongle *right)
{
    pthread_mutex_lock(&left->mutex);
	pthread_mutex_lock(&right->mutex);
}

void    unlock_mutex(t_dongle *left, t_dongle *right)
{
    pthread_mutex_unlock(&left->mutex);
	pthread_mutex_unlock(&right->mutex);
}