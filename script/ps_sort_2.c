/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:06:27 by emaillet          #+#    #+#             */
/*   Updated: 2025/02/05 07:32:04 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_target(t_ps_data *d, int pos_b)
{
	int	pos_a;

	pos_a = ft_lstsize(d->pile_a);
	if (get_b(d, pos_b) > get_a(d, get_max(d->pile_a)
			|| get_b(d, pos_b) < get_a(d, get_min(d->pile_a))))
		return (get_min(d->pile_a));
	while (pos_a > 0)
	{
		if (get_a(d, pos_a) > get_b(d, pos_b)
			&& get_a(d, pos_a - 1) < get_b(d, pos_b))
			break ;
		pos_a--;
	}
	return (pos_a);
}

//int	get_cost(t_ps_data *d, int pos_a, int pos_b)

void	ps_to_a(t_ps_data *d)
{
	int	target;

	sort_five(d);
	while (ft_lstsize(d->pile_b) > 1)
	{
		target = get_target(d, 1);
		rotate_both(d, get_target(d, 1), 1);
		ps_pa(d);
		if (PS_DEBUG)
			ft_printf(RED"TARGET [%i] %i SOURCE %i\n"RES,target, get_a(d, target), get_b(d, 1));
	}
}
