/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:47:57 by emaillet          #+#    #+#             */
/*   Updated: 2025/01/30 13:51:47 by emaillet         ###   ########.fr       */
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
		if (get_a(d, i) >= start && get_a(d, i) < start + 1 + d->chunk_size)
		{
			pos = i;
			break ;
		}
		i++;
	}
	ropti_a(d, pos - 1, ft_lstsize(d->pile_a));
}

static void	ps_rb_or_rr(t_ps_data *d, int chunk)
{
	if (!is_in_current_chunk(d, chunk + 1) && !is_in_current_chunk(d, chunk))
		ps_rr(d);
	else
		ps_rb(d);
}

void	ps_chunk_to_b(t_ps_data *d)
{
	int	chunk;

	chunk = 1;
	while (ft_lstsize(d->pile_a) > 3)
	{
		if (is_in_current_chunk(d, chunk + 1))
		{
			ps_pb(d);
			if (chunk % 2 == 0)
				ps_rb_or_rr(d, chunk);
		}
		else if (is_in_current_chunk(d, chunk))
		{
			ps_pb(d);
			if (chunk % 2 == 1)
				ps_rb_or_rr(d, chunk);
		}
		else
		{
			if (!in_chunk_count(d, chunk))
				chunk++;
			else
				ps_ra_or_rra(d, chunk);
		}
	}
}
