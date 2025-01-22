/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:30:49 by emaillet          #+#    #+#             */
/*   Updated: 2025/01/22 03:23:31 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# ifndef PS_DEBUG
#  define PS_DEBUG 0
# endif

# include <unistd.h>
# include <stdlib.h>
# include "../modules/42.libft/libft.h"

# define RED  "\x1B[31m"
# define GRN  "\x1B[32m"
# define YEL  "\x1B[33m"
# define RES  "\x1B[0m"

typedef struct s_ps_data
{
	t_list	*pile_a;
	t_list	*pile_b;
	t_list	*actions;
	t_list	*logs;
	char	**my_av;
}	t_ps_data;

//Push swap init and utils
char	**ft_spacer_split_lst(char const *s);
long	ft_ps_atol(const char *str,	t_list **lst);
void	ft_lstprintfd_ps(t_list *list_a, t_list *list_b, int fd);
int		pre_check(char **av);
void	set_zero(void *i);
int		lst_is_sorted(t_list *lst);
long	get_a(t_ps_data *d, int i);
long	get_b(t_ps_data *d, int i);

//Push swap instructions
int		ps_sa(t_ps_data *d);
int		ps_sb(t_ps_data *d);
int		ps_ss(t_ps_data *d);
int		ps_pa(t_ps_data *d);
int		ps_pb(t_ps_data *d);
int		ps_ra(t_ps_data *d);
int		ps_rb(t_ps_data *d);
int		ps_rr(t_ps_data *d);
int		ps_rra(t_ps_data *d);
int		ps_rrb(t_ps_data *d);
int		ps_rrr(t_ps_data *d);

//Algo
void	sort_three(t_ps_data *d);
void	sort_four(t_ps_data *d);
void	sort_five(t_ps_data *d);

#endif
