/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:47:57 by emaillet          #+#    #+#             */
/*   Updated: 2025/02/05 02:34:29 by emaillet         ###   ########.fr       */
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
	int		pos;
	int		size;

	pos = get_first_chunk(chunk, d);
	size = ft_lstsize(d->pile_a);
	if ((ft_lstsize(d->pile_b) > 1 && get_b(d, 1) < get_b(d, 2)))
		return (ps_rr(d), 1);
	else if (pos != 1 && pos <= (size * 3) / 7)
		return (ps_ra(d), 1);
	else if (pos != 1)
		return (ps_rra(d), -1);
	return (1);
}

void	ps_chunk_to_b(t_ps_data *d)
{
	int	chunk;

	chunk = 1;
	while (ft_lstsize(d->pile_a) > 5)
	{
		if (is_in_current_chunk(d, chunk, 1))
		{
			ps_pb(d);
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
