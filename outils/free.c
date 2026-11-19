/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osamet <oussama.samet@learner.42.tech>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 15:40:49 by osamet            #+#    #+#             */
/*   Updated: 2026/10/21 23:33:45 by osamet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../codexion.h"

void    all_free(t_config *config)
{
    int i;

    i = 0;
    while (i < config->nbr_coders)
    {
        pthread_mutex_destroy(&config->dongles[i].mutex);
        i++;
    }
    free(config->coders);
    free(config->dongles);
    pthread_mutex_destroy(&config->mutex_print);
    free(config);
}