/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osamet <oussama.samet@learner.42.tech>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 15:40:49 by osamet            #+#    #+#             */
/*   Updated: 2026/10/19 01:56:02 by osamet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../codexion.h"

void    build_struct(t_config *config)
{
    create_coders_struct(config);
	create_dongle_struct(config);
    assigned_dongle_to_coders(config);
	create_threads(config);
	join_threads(config);
}

void	create_coders_struct(t_config *config)
{
	t_coder	*coders;

	coders = malloc(sizeof(t_coder) * config->nbr_coders);
	if (!coders)
	{
		printf("error: faild to malloc coders struct");
        all_free(config);
		exit (1);
	}
	memset(coders, 0, sizeof(t_coder) * config->nbr_coders);
    init_coders(config, coders);
}

void	create_dongle_struct(t_config *config)
{
	t_dongle	*dongles;

	dongles = malloc(sizeof(t_dongle) * config->nbr_dongles);
	if (!dongles)
	{
		printf("error: faild to malloc dongles struct");
        all_free(config);
		exit (1);
	}
	memset(dongles, 0, sizeof(t_dongle) * config->nbr_dongles);
    init_dongle(config, dongles);
}

void    create_threads(t_config *config)
{
    int i;

	i = 0;
    while (i < config->nbr_coders)
    {
        if (pthread_create(&config->coders[i].thread.thread, NULL, coder_routine, &config->coders[i]) != 0)
        {
            printf("error: pathread cration failed");
            all_free(config);
            exit (1);
        }
        i++;
    }
}

void	join_threads(t_config *config)
{
	int	i;

	i = 0;
	while (i < config->nbr_coders)
	{
		pthread_join(config->coders[i].thread.thread, NULL);
		i++;
	}
}