/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:06:27 by emaillet          #+#    #+#             */
/*   Updated: 2025/02/06 11:13:43 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_target(t_ps_data *d, long value_b)
{
	int	pos_a;

	pos_a = 1;
	if (pos_a == 0)
		return (1);
	if (value_b > get_a(d, get_max(d->pile_a))
		|| value_b < get_a(d, get_min(d->pile_a)))
		return (get_min(d->pile_a));
	while (pos_a <= ft_lstsize(d->pile_a))
	{
		if (get_a(d, pos_a) > value_b && get_a(d, pos_a - 1) < value_b)
			break ;
		pos_a++;
	}
	return (pos_a);
}

//int	get_cost(t_ps_data *d, int pos_a, int pos_b)

void	ps_to_a(t_ps_data *d)
{
	int		target;
	int		b_pos;
	long	b_value;

	sort_five(d);
	while (ft_lstsize(d->pile_b) > 0)
	{
		b_pos = get_max(d->pile_b);
		b_value = get_b(d, b_pos);
		target = get_target(d, b_value);
		rotate_both(d, target, b_pos);
		ps_pa(d);
	}
	rotate_both(d, get_min(d->pile_a), 1);
}
