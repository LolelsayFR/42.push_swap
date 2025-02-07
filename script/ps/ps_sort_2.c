/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:06:27 by emaillet          #+#    #+#             */
/*   Updated: 2025/02/07 15:18:28 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_target(t_ps_data *d, int b_pos)
{
	int			pos_a;
	const int	value_b = get_b(d, b_pos);

	if (value_b < get_a(d, get_min(d->pile_a))
		&& value_b < get_a(d, get_max(d->pile_a)))
		return (get_min(d->pile_a));
	pos_a = ft_lstsize(d->pile_a);
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
	int			cost;
	int			target;
	const int	size_a = ft_lstsize(d->pile_a);
	const int	size_b = ft_lstsize(d->pile_b);

	target = get_target(d, pos_b);
	if (pos_b <= size_b / 2 && target <= size_a / 2)
		return (comp_max(target, pos_b));
	else if (pos_b > size_b / 2 && target > size_a / 2)
		return (comp_max(size_a - target, size_b - pos_b) + 1);
	else
	{
		if (target > size_a / 2)
			target = size_a - target;
		if (pos_b > size_b / 2)
			pos_b = size_b - pos_b;
		cost = target + pos_b;
	}
	return (cost);
}

void	ps_to_a(t_ps_data *d)
{
	int		b_pos;
	int		i;
	t_list	*tmp;

	sort_five(d);
	while (ft_lstsize(d->pile_b) > 0)
	{
		tmp = d->pile_b;
		i = 1;
		b_pos = get_max(d->pile_b);
		while (i < ft_lstsize(d->pile_b))
		{
			if (get_cost(d, i) < get_cost(d, b_pos))
				b_pos = i;
			i++;
			tmp = tmp->next;
		}
		rotate_both(d, get_target(d, b_pos), b_pos);
		ps_pa(d);
	}
	rotate_both(d, get_min(d->pile_a), 1);
}
