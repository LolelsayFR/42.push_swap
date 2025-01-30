/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:47:57 by emaillet          #+#    #+#             */
/*   Updated: 2025/01/30 09:42:08 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ropti_a(t_ps_data *d, int pos, int size)
{
	if (pos <= ft_lstsize(d->pile_a) / 2)
	{
		while (pos > 0)
		{
			ps_ra(d);
			pos--;
		}
	}
	else
	{
		while (pos < size)
		{
			ps_rra(d);
			pos++;
		}
	}
}

static int	in_chunk_count(t_ps_data *d, int chunk)
{
	t_list	*stack;
	int		count;
	long	start;

	start = d->min + ((chunk - 1) * d->chunk_size);
	count = 0;
	stack = d->pile_a;
	while (stack != NULL)
	{
		if ((long)stack->content >= start
			&& (long)stack->content < start + d->chunk_size)
			count++;
		stack = stack->next;
	}
	return (count);
}

static void	ps_ra_or_rra(t_ps_data *d, int chunk)
{
	int		i;
	int		pos;
	int		size;
	long	start;

	start = d->min + ((chunk - 1) * d->chunk_size);
	i = 1;
	pos = 1;
	size = ft_lstsize(d->pile_a);
	while (i <= size)
	{
		if (get_a(d, i) >= start && get_a(d, i) < start + d->chunk_size)
		{
			pos = i;
			break ;
		}
		i++;
	}
	if ((ft_lstsize(d->pile_b) > 1 && get_b(d, 1) < get_b(d, 2)))
		ps_rr(d);
	else if (pos != 1)
		ropti_a(d, pos - 1, ft_lstsize(d->pile_a));
}

void	ps_chunk_to_b(t_ps_data *d)
{
	int	chunk;
	int	i;

	chunk = 1;
	i = 0;
	while (ft_lstsize(d->pile_a) > 0)
	{
		if (is_in_current_chunk(d, chunk))
			ps_pb(d);
		else
		{
			if (!in_chunk_count(d, chunk))
				chunk++;
			else
				ps_ra_or_rra(d, chunk);
		}
	}
}

void	ps_to_a(t_ps_data *d)
{
	int	max_pos;
	int	size_b;

	while (d->pile_b)
	{
		size_b = ft_lstsize(d->pile_b);
		max_pos = find_max_position(d) - 1;
		if (max_pos <= size_b / 2)
		{
			while (max_pos > 0)
			{
				ps_rb(d);
				max_pos--;
			}
		}
		else
		{
			while (max_pos < size_b)
			{
				ps_rrb(d);
				max_pos++;
			}
		}
		ps_pa(d);
	}
}
