/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 01:26:21 by emaillet          #+#    #+#             */
/*   Updated: 2025/01/22 04:26:07 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_ps_data *d)
{
	const long	first = get_a(d, 1);
	const long	second = get_a(d, 2);
	const long	third = get_a(d, 3);

	if (lst_is_sorted(d->pile_a) == 1)
		return ;
	if (first > second && second < third && first < third)
		ps_sa(d);
	else if (first > second && second < third && first > third)
		ps_ra(d);
	else if (first > second && second > third)
	{
		ps_sa(d);
		ps_rra(d);
	}
	else if (first < second && second > third && first < third)
	{
		ps_sa(d);
		ps_ra(d);
	}
	else if (first < second && second > third && first > third)
		ps_rra(d);
}

void	sort_four(t_ps_data *d)
{
	if (lst_is_sorted(d->pile_a) == 1)
		return ;
	ps_pb(d);
	sort_three(d);
	if (get_b(d, 1) > get_a(d, 3))
	{
		ps_pa(d);
		ps_ra(d);
	}
	else if (get_b(d, 1) < get_a(d, 1))
		ps_pa(d);
	else
	{
		while (ps_ra(d))
		{
			if (get_b(d, 1) < get_a(d, 1) && get_b(d, 1) > get_a(d, 3))
				break ;
		}
		ps_pa(d);
		while (lst_is_sorted(d->pile_a) != 1)
			ps_ra(d);
	}
}

void	sort_five(t_ps_data *d)
{
	if (lst_is_sorted(d->pile_a) == 1)
		return ;
	ps_pb(d);
	sort_four(d);
	if (get_b(d, 1) > get_a(d, 4))
	{
		ps_pa(d);
		ps_ra(d);
	}
	else if (get_b(d, 1) < get_a(d, 1))
		ps_pa(d);
	else
	{
		while (ps_ra(d))
		{
			if (get_b(d, 1) < get_a(d, 1) && get_b(d, 1) > get_a(d, 4))
				break ;
		}
		ps_pa(d);
		while (lst_is_sorted(d->pile_a) != 1)
			ps_ra(d);
	}
}
