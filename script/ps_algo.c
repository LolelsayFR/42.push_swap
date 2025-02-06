/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 01:26:21 by emaillet          #+#    #+#             */
/*   Updated: 2025/02/06 11:18:30 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_ps_data *d)
{
	const long	first = get_a(d, 1);
	const long	second = get_a(d, 2);
	const long	third = get_a(d, 3);

	if (lst_is_sorted(d->pile_a, 1) == 1)
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
	if (lst_is_sorted(d->pile_a, 1) == 1)
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
	else if (get_b(d, 1) > get_a(d, 1) && get_b(d, 1) < get_a(d, 2))
	{
		ps_pa(d);
		ps_sa(d);
	}
	else
	{
		ps_rra(d);
		ps_pa(d);
		ps_ra(d);
		ps_ra(d);
	}
}

void	sort_five(t_ps_data *d)
{
	if (lst_is_sorted(d->pile_a, 1) == 1)
		return ;
	ps_pb(d);
	sort_four(d);
	if (get_b(d, 1) > get_a(d, 4))
		return (ps_pa(d), (void)ps_ra(d));
	else if (get_b(d, 1) < get_a(d, 1))
		return ((void)ps_pa(d));
	else if (get_b(d, 1) > get_a(d, 1) && get_b(d, 1) < get_a(d, 2))
		return (ps_pa(d), (void)ps_sa(d));
	else if (get_b(d, 1) > get_a(d, 2) && get_b(d, 1) < get_a(d, 3))
		return (ps_ra(d), ps_pa(d), ps_sa(d), (void)ps_rra(d));
	else
		return (ps_rra(d), ps_pa(d), ps_ra(d), (void)ps_ra(d));
}

void	ps_sort(t_ps_data *d)
{
	if (ft_lstsize(d->pile_a) > 300)
		d->chunk_size = (ft_lstsize(d->pile_a) - 5) / 10;
	else
		d->chunk_size = (ft_lstsize(d->pile_a) - 5) / 5;
	ps_chunk_to_b(d);
	ps_to_a(d);
}
