/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osamet <oussama.samet@learner.42.tech>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 15:40:49 by osamet            #+#    #+#             */
/*   Updated: 2026/11/23 19:32:31 by osamet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../codexion.h"

void	init_config(t_config *config)
{
	config->stop = 0;
	config->time_start = time_ms();
	pthread_mutex_init(&config->mutex_print, NULL);
	pthread_mutex_init(&config->mutex_stop, NULL);
}

void	init_coders(t_config *config, t_coder *coders)
{
	int	i;

	i = 0;
	while (i < config->nbr_coders)
	{
		coders[i].id = i + 1;
		coders[i].finish = 0;
		coders[i].config = config;
		coders[i].left = NULL;
		coders[i].right = NULL;
		coders[i].last_compile_start = 0;
		coders[i].compile_count = 0;
		pthread_mutex_init(&coders[i].mutex, NULL);
		i ++;
	}
	config->coders = coders;
}

void	init_dongle(t_config *config, t_dongle *dongles)
{
	int	i;

	i = 0;
	while (i < config->nbr_dongles)
	{
		dongles[i].id = i;
		dongles[i].queu_size = 0;
		dongles[i].is_taken = 0;
		dongles[i].available_at = 0;
		pthread_mutex_init(&dongles[i].mutex, NULL);
		i++;
	}
	config->dongles = dongles;
}

void	assigned_dongle_to_coders(t_config *config)
{
	int	i;

	i = 0;
	while (i < config->nbr_coders)
	{
		config->coders[i].left = &config->dongles[i];
		config->coders[i].right = &config->dongles[(
				(i + 1) % config->nbr_coders)];
		i++;
	}
}
