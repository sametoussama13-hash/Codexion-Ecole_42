/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osamet <oussama.samet@learner.42.tech>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 15:40:49 by osamet            #+#    #+#             */
/*   Updated: 2026/11/22 23:37:26 by osamet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../codexion.h"

void	*coder_routine(void *arg)
{
	t_coder		*coder;
	t_config	*config;

	coder = (t_coder *)arg;
	config = coder->config;
	if (coder->left == coder->right)
		return (NULL);
	while (coder->compile_count < config->nbr_of_compiles_re)
	{
		if (check_stop(config) != 0)
			return (NULL);
		if (lock_dongle(coder->left, coder->right, coder) != 0)
			continue ;
		compile(config, coder);
		unlock_dongle(coder->left, coder->right, config);
		if (check_stop(config) != 0)
			return (NULL);
		debug(config, coder);
		if (check_stop(config) != 0)
			return (NULL);
		refactor(config, coder);
	}
	return (NULL);
}

void	compile(t_config *config, t_coder *coder)
{
	logger(coder, "is compiling");
	pthread_mutex_lock(&coder->mutex);
	coder->last_compile_start = time_ms();
	pthread_mutex_unlock(&coder->mutex);
	usleep(config->time_to_compile * 1000);
	pthread_mutex_lock(&coder->mutex);
	coder->compile_count++;
	if (coder->compile_count == config->nbr_of_compiles_re)
		coder->finish = 1;
	pthread_mutex_unlock(&coder->mutex);
	
}

void	debug(t_config *config, t_coder *coder)
{
	logger(coder, "is debugging");
	usleep(config->time_to_debug * 1000);
}

void	refactor(t_config *config, t_coder *coder)
{
	logger(coder, "is refactoring");
	usleep(config->time_to_refactor * 1000);
}
