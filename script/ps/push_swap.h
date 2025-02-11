/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:30:49 by emaillet          #+#    #+#             */
/*   Updated: 2025/02/11 23:17:45 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# ifndef PS_DEBUG
#  define PS_DEBUG 0
# endif

# ifndef PS_CHECKER
#  define PS_CHECKER 0
# endif

# include <unistd.h>
# include <stdlib.h>
# include "../../modules/42.libft/libft.h"

# define RED  "\x1B[31m"
# define GRN  "\x1B[32m"
# define YEL  "\x1B[33m"
# define RES  "\x1B[0m"

typedef struct s_ps_data
{
	t_list	*pile_a;
	t_list	*pile_b;
	char	**my_av;
	long	min;
	long	max;
	long	min_a;
	int		size_a;
	int		size_b;
	long	top_five[5];
	int		chunk_size;
	int		chunk;
	int		best_cost;
}	t_ps_data;

//Push swap init and utils
char		**ft_spacer_split_lst(char const *s);
long		ft_ps_atol(const char *str,	t_list **lst);
void		ft_lstprintfd_ps(t_list *list_a, t_list *list_b, int fd);
void		set_zero(void *i);
int			lst_is_sorted(t_list *lst, int order);
long		get_a(t_ps_data *d, int i);
long		get_b(t_ps_data *d, int i);
int			init_minmax(t_ps_data *data);
long		get_min(t_list *lst);
long		get_max(t_list *lst);
int			comp_max(int a, int b);
void		get_fifth_max(t_ps_data *d, t_list *lst);
int			is_top_five(t_ps_data *d, int value);
int			can_push(t_ps_data *d, int pos_a, int pos_b);
int			get_cost(t_ps_data *d, int pos_b);

//Push swap instructions
int			ps_sa(t_ps_data *d);
int			ps_sb(t_ps_data *d);
int			ps_ss(t_ps_data *d);
int			ps_pa(t_ps_data *d);
int			ps_pb(t_ps_data *d);
int			ps_ra(t_ps_data *d);
int			ps_rb(t_ps_data *d);
int			ps_rr(t_ps_data *d);
int			ps_rra(t_ps_data *d);
int			ps_rrb(t_ps_data *d);
int			ps_rrr(t_ps_data *d);
void		ps_pa_all(t_ps_data *d);
void		ps_pb_all(t_ps_data *d);

//Algo
void		sort_three(t_ps_data *d);
void		sort_four(t_ps_data *d);
void		sort_five(t_ps_data *d);
void		ps_sort(t_ps_data *d);
void		ps_chunk_to_b(t_ps_data *d);
void		ps_to_a(t_ps_data *d, int i, int cost, int i_cost);
int			is_in_current_chunk(t_ps_data *d, int chunk_num, int i);
int			get_first_chunk(int chunk, t_ps_data *d);
void		rotate_both(t_ps_data *d, int rot_a, int rot_b);

#endif
