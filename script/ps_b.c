/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_b.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 22:38:02 by emaillet          #+#    #+#             */
/*   Updated: 2025/01/22 00:14:12 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_sb(t_ps_data *d)
{
	if (ft_lstsize(d->pile_b) == 1)
		return (RETURN_ERROR);
	ft_lst_swap(&d->pile_b, &d->pile_b->next);
	ft_printfd(1, "sb\n");
	return (RETURN_SUCCESS);
}

int	ps_pb(t_ps_data *d)
{
	t_list	*new_head;

	if (ft_lstsize(d->pile_a) == 0)
		return (RETURN_ERROR);
	new_head = d->pile_a->next;
	ft_lstadd_front(&d->pile_b, ft_lstnew(d->pile_a->content));
	ft_lstdelone(d->pile_a, set_zero);
	d->pile_a = new_head;
	ft_printfd(1, "pb\n");
	return (RETURN_SUCCESS);
}

int	ps_rb(t_ps_data *d)
{
	if (ft_lstsize(d->pile_b) == 1)
		return (RETURN_ERROR);
	ft_lst_rotate(&d->pile_b, 1);
	ft_printfd(1, "rb\n");
	return (RETURN_SUCCESS);
}

int	ps_rrb(t_ps_data *d)
{
	if (ft_lstsize(d->pile_b) == 1)
		return (RETURN_ERROR);
	ft_lst_unrotate(&d->pile_b, 1);
	ft_printfd(1, "rrb\n");
	return (RETURN_SUCCESS);
}
