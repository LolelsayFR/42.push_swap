/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:06:27 by emaillet          #+#    #+#             */
/*   Updated: 2025/02/01 07:50:51 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	get_min(t_list *lst)
{
	t_list	*tmp;
	long	min;

	tmp = lst;
	min = (long)tmp->content;
	while (tmp != NULL)
	{
		if ((long)tmp->content < min)
			min = (long)tmp->content;
		tmp = tmp->next;
	}
	return (min);
}

long	get_max(t_list *lst)
{
	t_list	*tmp;
	long	max;

	tmp = lst;
	max = (long)tmp->content;
	while (tmp != NULL)
	{
		if ((long)tmp->content > max)
			max = (long)tmp->content;
		tmp = tmp->next;
	}
	return (max);
}

void	choose_rotate(t_ps_data *d, t_pile_info *info)
{
	if (info->source_pos == 1)
	{
		if (info->target_pos <= ft_lstsize(d->pile_a) / 2)
			ps_rra(d);
		else
			ps_ra(d);
	}
	if (info->source_pos <= ft_lstsize(d->pile_b) / 2)
	{
		ps_rr(d);
		info->source_pos--;
	}
	else
	{
		ps_rrr(d);
		info->source_pos++;
	}
}

void	precision_pa(t_ps_data *d, int pos)
{
	const int	val = get_b(d, pos);
	t_pile_info	info;

	if (!d->pile_a)
		return ((void)ps_pa(d));
	info = init_pile_info(d, pos);
	if (val < info.min_a)
		while (get_a(d, info.size_a) != info.max_a)
			choose_rotate(d, &info);
	else if (val > info.max_a)
		while (get_a(d, 1) != info.min_a)
			choose_rotate(d, &info);
	else
		while (!(val < get_a(d, 1) && val > get_a(d, info.size_a)))
			choose_rotate(d, &info);
	while (get_b(d, 1) != val)
	{
		if (pos <= info.size_b / 2)
			ps_rb(d);
		else
			ps_rrb(d);
	}
	ps_pa(d);
}

void	ps_to_a(t_ps_data *d)
{
	int			max_pos;
	int			size_b;

	while (d->pile_b)
	{
		size_b = ft_lstsize(d->pile_b);
		max_pos = find_max_position(d, 'b') - 1;
		if (max_pos <= size_b / 2)
		{
			while (max_pos > 0)
			{
				ps_rb(d);
				max_pos--;
			}
		}
		else
		{
			while (max_pos < size_b)
			{
				ps_rrb(d);
				max_pos++;
			}
		}
		ps_pa(d);
	}
}
