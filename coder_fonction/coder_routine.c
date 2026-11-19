/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osamet <oussama.samet@learner.42.tech>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 15:40:49 by osamet            #+#    #+#             */
/*   Updated: 2026/10/21 23:34:58 by osamet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../codexion.h"

void    *coder_routine(void *arg)
{
    t_coder *coder;
    t_config *config;

    coder = (t_coder *)arg;
    config = coder->config;
    while (coder->compile_count < config->nbr_of_compiles_re)
    {
        compile(config, coder);
        debug(config, coder);
        refactor(config, coder);
    }
    return (NULL);
}

void    compile(t_config *config, t_coder *coder)
{
    logger(coder, "is compiling");
    coder->last_compile_start = time_ms();
    coder->compile_count++;
    usleep(config->time_to_compile * 1000);
}

void    debug(t_config *config, t_coder *coder)
{
    logger(coder, "is debugging");
    usleep(config->time_to_debug * 1000);
}

void    refactor(t_config *config, t_coder *coder)
{
    logger(coder, "is refactoring");
    usleep(config->time_to_refactor * 1000);
}