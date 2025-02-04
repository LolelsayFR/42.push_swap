/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:06:27 by emaillet          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/02/04 11:22:30 by emaillet         ###   ########.fr       */
=======
/*   Updated: 2025/02/04 17:09:40 by emaillet         ###   ########.fr       */
>>>>>>> 0aff9c0 (Not redraw, go back to my chunk)
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

<<<<<<< HEAD

=======
int	get_second_max_pos(t_list *lst)
{
	t_list	*tmp;
	long	max;
	int		i;
	int		res;

	if (!lst || !lst->next)
		return (0);
	tmp = lst;
	max = (long)tmp->content;
	i = 1;
	while (tmp != NULL)
	{
		if ((long)tmp->content > max && i != get_max(lst))
			res = i;
		if ((long)tmp->content > max && i != get_max(lst))
			max = (long)tmp->content;
		tmp = tmp->next;
		i++;
	}
	return (res);
}

void	ps_check_sw(t_ps_data *d, int *pos)
{
	if (ft_lstsize(d->pile_a) > 2 && get_a(d, 1) > get_a(d, 2)
		&& get_b(d, 1) < get_b(d, 2))
		ps_ss(d);
	else if (ft_lstsize(d->pile_a) > 2 && get_a(d, 1) > get_a(d, 2))
		ps_sa(d);
	if (ft_lstsize(d->pile_b) > 2 && get_second_max_pos(d->pile_b) == 1)
	{
		pos--;
		ps_pa(d);
	}
}

void	ps_check_ra(t_ps_data *d, int *pos)
{
	if (ft_lstsize(d->pile_a) > 2 && get_b(d, 1) < get_b(d, 2)
		&& get_a(d, 1) > get_a(d, ft_lstsize(d->pile_a)))
		ps_rrr(d);
	else if (ft_lstsize(d->pile_a) > 2
		&& get_a(d, 1) > get_a(d, ft_lstsize(d->pile_a)))
		ps_rra(d);
	if (ft_lstsize(d->pile_b) > 2 && get_second_max_pos(d->pile_b) == 1)
	{
		pos--;
		ps_pa(d);
		ps_ra(d);
	}
}

void	precision_ra(t_ps_data *d, int max_pos, int size_b)
{
	if (max_pos <= size_b / 2)
	{
		while (max_pos > 0)
		{
			ps_rb(d);
			ps_check_sw(d, &max_pos);
			max_pos--;
		}
	}
	else
	{
		while (max_pos < size_b)
		{
			ps_rrb(d);
			ps_check_ra(d, &max_pos);
			ps_check_sw(d, &max_pos);
			max_pos++;
		}
	}
}

void	ps_to_a(t_ps_data *d)
{
	int			max_pos;
	int			size_b;

	while (d->pile_b)
	{
		max_pos = get_max(d->pile_b) - 1;
		size_b = ft_lstsize(d->pile_b);
		precision_ra(d, max_pos, size_b);
		ps_pa(d);
		ps_check_sw(d, 0);
	}
	ps_realign(d);
}
>>>>>>> 0aff9c0 (Not redraw, go back to my chunk)
