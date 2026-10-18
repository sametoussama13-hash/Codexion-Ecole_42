/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osamet <oussama.samet@learner.42.tech>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 16:34:44 by osamet            #+#    #+#             */
/*   Updated: 2026/10/18 17:45:39 by osamet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"
#include <stdio.h>

unsigned long long time_ms(void)
{
    struct timeval tv;

    gettimeofday(&tv, NULL);
    return ((unsigned long long)tv.tv_sec * 1000
        + tv.tv_usec / 1000);
}