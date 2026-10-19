/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder_fonction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osamet <oussama.samet@learner.42.tech>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 15:40:49 by osamet            #+#    #+#             */
/*   Updated: 2026/10/19 02:16:48 by osamet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../codexion.h"

void    *coder_routine(void *arg)
{
    t_coder *coder;
    t_config *config;

    coder = (t_coder *)arg;
    config = coder->config;
    printf("Coder %d started\n", coder->id);
    printf("Compile time: %llu ms\n", config->time_to_compile);
    return (NULL);
}