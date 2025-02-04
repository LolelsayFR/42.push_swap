/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 23:26:21 by emaillet          #+#    #+#             */
/*   Updated: 2025/02/04 17:15:37 by emaillet         ###   ########.fr       */
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

int	get_first_chunk(int chunk, t_ps_data *d)
{
	t_list	*tmp;
	int		i;
	int		res;

	tmp = d->pile_a;
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
	int		i;
	int		res;

	tmp = d->pile_a;
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
