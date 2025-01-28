/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 23:26:21 by emaillet          #+#    #+#             */
/*   Updated: 2025/01/28 23:01:20 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_in_current_chunk(t_ps_data *d, int chunk_num)
{
	long	start;

	start = d->min + ((chunk_num - 1) * d->chunk_size);
	if (get_a(d, 1) >= start && get_a(d, 1) < start + d->chunk_size)
		return (1);
	return (0);
}

int	find_max_position(t_ps_data *d)
{
	int		i;
	int		max_pos;
	long	max_val;
	int		size;

	i = 1;
	max_pos = 1;
	size = ft_lstsize(d->pile_b);
	max_val = get_b(d, 1);
	while (i <= size)
	{
		if (get_b(d, i) > max_val)
		{
			max_val = get_b(d, i);
			max_pos = i;
		}
		i++;
	}
	return (max_pos);
}
