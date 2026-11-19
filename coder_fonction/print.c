/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osamet <oussama.samet@learner.42.tech>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 15:40:49 by osamet            #+#    #+#             */
/*   Updated: 2026/10/21 22:45:12 by osamet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../codexion.h"

void    logger(t_coder *coder, char *str)
{
    unsigned long long  time;

    pthread_mutex_lock(&coder->config->mutex_print);
    time = time_ms() - coder->config->time_start;
    printf("%llu %d %s\n", time, coder->id, str);
    pthread_mutex_unlock(&coder->config->mutex_print);
}
