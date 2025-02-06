/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 23:26:21 by emaillet          #+#    #+#             */
/*   Updated: 2025/02/06 12:22:42 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_in_current_chunk(t_ps_data *d, int chunk_num, int i)
{
	long	start;

	start = d->min + ((chunk_num - 1) * d->chunk_size);
	if (is_top_five(d, get_a(d, i)))
		return (0);
	if (i > 0 && get_a(d, i) >= start && get_a(d, i) < start + d->chunk_size)
		return (1);
	else if (i < 0 && get_b(d, i * -1) >= start
		&& get_b(d, i * -1) < start + d->chunk_size)
		return (1);
	return (0);
}

static void	insert_fifth_max(t_ps_data *d, int value)
{
	int	i;
	int	j;

	i = 0;
	while (i < 5 && value <= d->top_five[i])
		i++;
	if (i < 5)
	{
		j = 4;
		while (j > i)
		{
			d->top_five[j] = d->top_five[j - 1];
			j--;
		}
		d->top_five[i] = value;
	}
}

int	is_top_five(t_ps_data *d, int value)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (value == d->top_five[i])
			return (1);
		i++;
	}
	return (0);
}

void	get_fifth_max(t_ps_data *d, t_list *lst)
{
	t_list	*tmp;
	int		value;

	d->top_five[0] = INT_MIN;
	d->top_five[1] = INT_MIN;
	d->top_five[2] = INT_MIN;
	d->top_five[3] = INT_MIN;
	d->top_five[4] = INT_MIN;
	if (!lst)
		return ;
	tmp = lst;
	while (tmp != NULL)
	{
		value = (long)tmp->content;
		insert_fifth_max(d, value);
		tmp = tmp->next;
	}
}
