/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 23:26:21 by emaillet          #+#    #+#             */
/*   Updated: 2025/02/03 06:06:25 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_in_current_chunk(t_ps_data *d, int chunk_num, int i)
{
	long	start;

	start = d->min + ((chunk_num - 1) * d->chunk_size);
	if (i > 0 && get_a(d, i) >= start && get_a(d, i) < start + d->chunk_size)
		return (1);
	else if (i < 0 && get_b(d, i * -1) >= start
		&& get_b(d, i * -1) < start + d->chunk_size)
		return (1);
	return (0);
}

static int	find_target_position(t_ps_data *d, int val, int size_a)
{
	int		i;
	long	current;
	long	next;

	i = 1;
	while (i <= size_a)
	{
		current = get_a(d, i);
		if (i == size_a)
			next = get_a(d, 1);
		else
			next = get_a(d, i + 1);
		if (val > current && val < next)
			return (i + 1);
		i++;
	}
	return (1);
}

t_pile_info	init_pile_info(t_ps_data *d, int pos)
{
	t_pile_info	info;
	int			val;

	info.size_a = ft_lstsize(d->pile_a);
	info.size_b = ft_lstsize(d->pile_b);
	info.min_a = get_min(d->pile_a);
	info.max_a = get_max(d->pile_a);
	info.pos = pos;
	val = get_b(d, pos);
	info.target_pos = find_target_position(d, val, info.size_a);
	return (info);
}

int	get_first_chunk(int chunk, t_ps_data *d)
{
	t_list	*tmp;
	long	min;
	int		i;
	int		res;

	tmp = d->pile_a;
	min = (long)tmp->content;
	i = 1;
	while (tmp != NULL)
	{
		if (is_in_current_chunk(d, chunk, i))
			res = i;
		if (is_in_current_chunk(d, chunk, i))
			break ;
		tmp = tmp->next;
		i++;
	}
	return (res);
}

int	get_last_chunk(int chunk, t_ps_data *d)
{
	t_list	*tmp;
	long	max;
	int		i;
	int		res;

	tmp = d->pile_a;
	max = (long)tmp->content;
	i = 1;
	while (tmp != NULL)
	{
		if (is_in_current_chunk(d, chunk, i))
			res = i;
		tmp = tmp->next;
		i++;
	}
	return (res);
}
