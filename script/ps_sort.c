/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:47:57 by emaillet          #+#    #+#             */
/*   Updated: 2025/02/01 06:49:39 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	ps_ra_or_rra(t_ps_data *d, int chunk)
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
		return (ps_rr(d), 1);
	else if (pos != 1 && pos <= ft_lstsize(d->pile_a) / 2)
		return (ps_ra(d), 1);
	else if (pos != 1)
		return (ps_rra(d), -1);
	return (1);
}

void	ps_chunk_to_b(t_ps_data *d)
{
	int	chunk;

	chunk = 1;
	while (ft_lstsize(d->pile_a) > 0)
	{
		if (is_in_current_chunk(d, chunk, 1))
		{
			ps_pb(d);
			if ((ft_lstsize(d->pile_b) > 1 && get_b(d, 1) < get_b(d, 2))
				&& !is_in_current_chunk(d, chunk, 1))
				ps_rr(d);
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
