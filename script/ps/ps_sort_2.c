/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:06:27 by emaillet          #+#    #+#             */
/*   Updated: 2025/02/11 23:17:26 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_target(t_ps_data *d, int b_pos)
{
	int			pos_a;
	const int	value_b = get_b(d, b_pos);

	if (value_b < get_a(d, get_min(d->pile_a)))
		return (get_min(d->pile_a));
	pos_a = d->size_a;
	while (pos_a > 1)
	{
		if (get_a(d, pos_a) > value_b && get_a(d, pos_a - 1) < value_b)
			break ;
		pos_a--;
	}
	return (pos_a);
}

int	get_cost(t_ps_data *d, int pos_b)
{
	int			target;
	int			cost_a;
	int			cost_b;

	target = get_target(d, pos_b);
	if (pos_b <= d->size_b / 2)
		cost_b = pos_b;
	else
		cost_b = d->size_b - pos_b;
	if (target <= d->size_a / 2)
		cost_a = target;
	else
		cost_a = d->size_a - target;
	if ((pos_b <= d->size_b / 2 && target <= d->size_a / 2)
		|| (pos_b > d->size_b / 2 && target > d->size_a / 2))
		return (comp_max(cost_a, cost_b));
	else
		return (cost_a + cost_b);
}

void	ps_to_a(t_ps_data *d, int i, int cost, int i_cost)
{
	int		b_pos;
	t_list	*tmp;

	while (ft_lstsize(d->pile_b) > 0)
	{
		d->min_a = get_min(d->pile_a);
		d->size_a = ft_lstsize(d->pile_a);
		d->size_b = ft_lstsize(d->pile_b);
		tmp = d->pile_b;
		i = 1;
		b_pos = get_max(d->pile_b);
		cost = get_cost(d, b_pos);
		while (i <= d->size_b)
		{
			i_cost = get_cost(d, i);
			if (i_cost < cost)
			{
				b_pos = i;
				cost = i_cost;
			}
			i++;
			tmp = tmp->next;
		}
		rotate_both(d, get_target(d, b_pos), b_pos);
	}
}
