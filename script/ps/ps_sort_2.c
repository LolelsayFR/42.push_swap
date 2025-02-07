/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:06:27 by emaillet          #+#    #+#             */
/*   Updated: 2025/02/07 11:39:42 by emaillet         ###   ########.fr       */
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
	int	cost;
	int	target;

	target = get_target(d, pos_b);
	if (pos_b <= ft_lstsize(d->pile_b) / 2
		&& target <= ft_lstsize(d->pile_a) / 2)
		return (comp_max(target, pos_b));
	else if (pos_b > ft_lstsize(d->pile_b) / 2
		&& target > ft_lstsize(d->pile_a) / 2)
		return (comp_max(ft_lstsize(d->pile_a) - target,
				ft_lstsize(d->pile_b) - pos_b));
	else
	{
		if (target > ft_lstsize(d->pile_a) / 2)
			target = ft_lstsize(d->pile_a) - target;
		if (pos_b > ft_lstsize(d->pile_b) / 2)
			pos_b = ft_lstsize(d->pile_b) - pos_b;
		cost = target + pos_b;
	}
	return (cost);
}

void	ps_to_a(t_ps_data *d)
{
	int		target;
	int		b_pos;
	int		b_cost;
	int		i;
	t_list	*tmp;

	sort_five(d);
	while (ft_lstsize(d->pile_b) > 0)
	{
		tmp = d->pile_b;
		i = 1;
		b_pos = get_max(d->pile_b);
		b_cost = get_cost(d, b_pos);
		while (i < ft_lstsize(d->pile_b))
		{
			if (get_cost(d, i) < b_cost)
				b_pos = i;
			i++;
			tmp = tmp->next;
		}
		target = get_target(d, b_pos);
		rotate_both(d, target, b_pos);
		ps_pa(d);
	}
	rotate_both(d, get_min(d->pile_a), 1);
}
