/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:30:49 by emaillet          #+#    #+#             */
/*   Updated: 2025/02/04 17:16:15 by emaillet         ###   ########.fr       */
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
	long	min;
	long	max;
	int		chunk_size;
	int		chunk;
}	t_ps_data;

typedef struct s_pile_info
{
	int		size_a;
	int		size_b;
	long	min_a;
	long	max_a;
	int		target_pos;
	int		pos;
}	t_pile_info;

//Push swap init and utils
char		**ft_spacer_split_lst(char const *s);
long		ft_ps_atol(const char *str,	t_list **lst);
void		ft_lstprintfd_ps(t_list *list_a, t_list *list_b, int fd);
int			pre_check(char **av);
void		set_zero(void *i);
int			lst_is_sorted(t_list *lst, int order);
long		get_a(t_ps_data *d, int i);
long		get_b(t_ps_data *d, int i);
int			init_minmax(t_ps_data *data);
long		get_min(t_list *lst);
long		get_max(t_list *lst);
int			comp_min(int a, int b);
int			comp_max(int a, int b);

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
void		ps_to_a(t_ps_data *d);
int			is_in_current_chunk(t_ps_data *d, int chunk_num, int i);
int			get_last_chunk(int chunk, t_ps_data *d);
int			get_first_chunk(int chunk, t_ps_data *d);
void		ps_realign(t_ps_data *d);
void		ps_realign_pos(t_ps_data *d, int pos);
int			find_min_position(t_ps_data *d);
int			find_position(t_list *stack, long value);
long		get_max_value(t_list *stack);
void		align_rotate(t_ps_data *d, int apos, int bpos);
#endif
