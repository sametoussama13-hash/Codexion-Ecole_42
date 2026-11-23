/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fifo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osamet <oussama.samet@learner.42.tech>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 14:26:23 by osamet            #+#    #+#             */
/*   Updated: 2026/11/23 19:43:09 by osamet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../codexion.h"

int    scheduler_fifo(t_coder *coder)
{
    if (coder->left->queu_size == 0 && coder->right->queu_size == 0)
    {
        init_is_taken(coder);
        unlock_mutex(coder->left, coder->right);
        return (0);
    }
    else
    {
        if ((coder == coder->left->coders[0] && coder == coder->right->coders[0])
            || (coder->left->queu_size == 0 && coder == coder->right->coders[0])
            || (coder->right->queu_size == 0 && coder == coder->left->coders[0]))
        {    
	        init_is_taken(coder);
        }
        if (coder->left->is_taken == 1 && coder->right->is_taken == 1)
        {
            init_tas(coder->left, coder->right);
            unlock_mutex(coder->left, coder->right);
            return (0);
        }
    }
    unlock_mutex(coder->left, coder->right);
    return (1);
}

void	handle_heap_fifo(t_coder *coder, t_dongle *dongle)
{
	int	i;

	i = 0;
	while (i < dongle->queu_size)
	{
		if (dongle->coders[i] == coder)
			return ;
        i++ ;
	}
	if (dongle->queu_size == 2)
		return ;
	else if (dongle->queu_size == 1)
	{
		dongle->coders[1] = coder;
		dongle->queu_size ++;
	}
	else if (dongle->queu_size == 0)
	{
		dongle->coders[0] = coder;
		dongle->queu_size ++;
	}
}

void init_tas(t_dongle *left, t_dongle *right)
{
    if (left->queu_size != 0)
    {
        left->coders[0] = left->coders[left->queu_size - 1];
        left->coders[left->queu_size - 1] = NULL;
        left->queu_size --;
    }
    if (right->queu_size != 0)
    {
        right->coders[0] = right->coders[right->queu_size - 1];
        right->coders[right->queu_size - 1] = NULL;
        right->queu_size --;
    }
}

void    init_is_taken(t_coder *coder)
{
    coder->left->is_taken = 1;
	logger(coder, "has taken a dongle");
    coder->right->is_taken = 1;
	logger(coder, "has taken a dongle");
}