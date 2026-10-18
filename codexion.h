/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osamet <oussama.samet@learner.42.tech>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 14:26:23 by osamet            #+#    #+#             */
/*   Updated: 2026/10/18 20:45:46 by osamet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CODEXION_H
# define CODEXION_H

# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>

typedef enum s_scheduler
{
	FIFO,
	EDF
}	t_scheduler;

typedef struct s_thread
{
	pthread_t	thread;
}	t_thread;

typedef struct s_coder
{
	int					id;
	t_dongle			*left;
	t_dongle			*right;
	unsigned long long 	last_compile_start;
	int					compile_count;
	t_thread			thread;
}	t_coder;

typedef struct s_dongle
{
	int					id;
	int					is_taken;
	unsigned long long 	available_at;
	pthread_mutex_t		mutex;
}	t_dongle;

typedef struct s_config
{
	int					nbr_coders;
	int					nbr_dongles;
	int					nbr_of_compiles_re;
	unsigned long long	time_start;
	unsigned long long	time_to_burnout;
	unsigned long long	time_to_compile;
	unsigned long long	time_to_debug;
	unsigned long long	time_to_refactor;
	unsigned long long	dongle_cooldown;
	t_coder				*coders;
	t_dongle			*dongles;
	t_scheduler			scheduler;
}	t_config;

//*************** main ***************//
int			main(int argc, char **argv);

//*************** parsing ***************//
void		parsing(int argc, char **argv, t_config *config);
const char	*name_argument(int i);

//----- parsing nbr -----//
void		parsing_nbr(char *str, t_config *config, int i);
int			convert_nbr(char *str, int i);

//----- parsing time -----//
void		parsing_time(char *str, t_config *config, int i);
void		time_to_compile(char *str, t_config *config);
int			time_convert(char *str, int i);

//----- parsing Scheduler -----//
void		scheduler(char *str, t_config *config);

//*************** create & Init structers ***************//
void		create_coders_struct(t_config *config);
void		create_dongle_struct(t_config *config);

//*************** outils ***************//
int			ft_strlen(char *str);
int			ft_isdigit(char *str);
int			strcamp(char *str1, char *str2);
void    	all_free(t_config *config);
unsigned long long	time_ms(void);
unsigned long long	ft_atoull(char *str);

#endif