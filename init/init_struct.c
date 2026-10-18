/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osamet <oussama.samet@learner.42.tech>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 15:40:49 by osamet            #+#    #+#             */
/*   Updated: 2026/10/18 20:44:56 by osamet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../codexion.h"

void    init_struct(t_config *config)
{
    create_coders_struct(config);
	create_dongle_struct(config);
    assigned_dongle_to_coders(config);
}

void	create_coders_struct(t_config *config)
{
	t_coder	*coders;
	int		i;

	coders = malloc(sizeof(t_coder) * config->nbr_coders);
	if (!coders)
	{
		printf("error: faild to malloc coders struct");
		exit (1);
	}
	memset(coders, 0, sizeof(t_coder) * config->nbr_coders);
	i = 0;
	while (i < config->nbr_coders)
	{
		coders[i].id = i + 1;
		i ++;
	}
	config->coders = coders;
}

void	create_dongle_struct(t_config *config)
{
	t_dongle	*dongles;
	int		i;

	dongles = malloc(sizeof(t_dongle) * config->nbr_dongles);
	if (!dongles)
	{
		printf("error: faild to malloc dongles struct");
		exit (1);
	}
	memset(dongles, 0, sizeof(t_dongle) * config->nbr_dongles);
	i = 0;
	while (i < config->nbr_dongles)
	{
		dongles[i].id = 0;
		dongles[i].is_taken = 0;
		dongles[i].available_at = 0;
		pthread_mutex_init(&dongles[i].mutex, NULL);
	}
	config->dongles = dongles;
}

void    assigned_dongle_to_coders(t_config *config)
{
    int i;

    i = 0;
    while (i < config->nbr_coders)
    {
        config->coders[i].left = &config->dongles[i];
        config->coders[i].right = &config->dongles[((i + 1) % config->nbr_coders)];
        i++;
    }
}