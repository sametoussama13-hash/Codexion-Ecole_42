/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osamet <oussama.samet@learner.42.tech>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 15:40:49 by osamet            #+#    #+#             */
/*   Updated: 2026/11/22 23:31:32 by osamet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../codexion.h"

void	*monitoring(void *arg)
{
	t_config			*config;
	int					i;

	config = (t_config *)arg;
	while (1)
	{
		if (check_finish_coders(config) != 0)
			return (NULL) ;
		i = 0;
		while (i < config->nbr_coders)
		{
			if (check_burnout(i, config) != 0)
				return (NULL);
			i ++;
		}
	}
}

int		check_burnout(int i, t_config *config)
{
	pthread_mutex_lock(&config->coders[i].mutex);
	if (config->coders[i].finish == 0)
	{
		if (time_ms() > init_burn(i, config))
		{
			init_stop(config, i);
			return (1);
		}
	}
	pthread_mutex_unlock(&config->coders[i].mutex);
	return (0);
}

unsigned long long	init_burn(int i, t_config *config)
{
	unsigned long long	last_compile;

	last_compile = config->coders[i].last_compile_start;
	if (last_compile == 0)
		return (config->time_start + config->time_to_burnout);
	else
		return (last_compile + config->time_to_burnout);
}

void	init_stop(t_config *config, int i)
{
	pthread_mutex_unlock(&config->coders[i].mutex);
	pthread_mutex_lock(&config->mutex_stop);
	config->stop = 1;
	pthread_mutex_unlock(&config->mutex_stop);
	logger(&config->coders[i], "burned out");
}

int	check_finish_coders(t_config *config)
{
	int	i;

	i = 0;
	while (i < config->nbr_coders)
	{
		pthread_mutex_lock(&config->coders[i].mutex);
		if (config->coders[i].finish == 0)
		{
			pthread_mutex_unlock(&config->coders[i].mutex);
			return (0);
		}
		pthread_mutex_unlock(&config->coders[i].mutex);
		i++;
	}
	pthread_mutex_lock(&config->mutex_stop);
	config->stop = 1;
	pthread_mutex_unlock(&config->mutex_stop);
	return (1);
}