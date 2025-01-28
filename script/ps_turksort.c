/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_turksort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:47:57 by emaillet          #+#    #+#             */
/*   Updated: 2025/01/28 19:19:26 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_turk_to_b(t_ps_data *d)
{
	int	chunk;
	int	i;

	chunk = 1;
	i = 0;
	while (ft_lstsize(d->pile_a) > 0)
	{
		if (is_in_current_chunk(d, chunk))
		{
			ps_pb(d);
			if ((ft_lstsize(d->pile_b) > 1 && get_b(d, 1) < get_b(d, 2)))
				ps_rb(d);
		}
		else
		{
			ps_ra(d);
			if (i++ >= ft_lstsize(d->pile_a))
			{
				chunk++;
				i = 0;
			}
		}
	}
}

void	ps_turk_to_a(t_ps_data *d)
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

void	ps_turksort(t_ps_data *d)
{
	if (ft_lstsize(d->pile_a) > 100)
		d->chunk_size = ft_lstsize(d->pile_a) / 10;
	else
		d->chunk_size = ft_lstsize(d->pile_a) / 6;
	ps_turk_to_b(d);
	ps_turk_to_a(d);
}
