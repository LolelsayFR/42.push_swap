/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_a.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 22:38:02 by emaillet          #+#    #+#             */
/*   Updated: 2025/01/22 02:45:43 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_sa(t_ps_data *d)
{
	if (ft_lstsize(d->pile_a) == 1)
		return (RETURN_ERROR);
	ft_lst_swap(&d->pile_a, &d->pile_a->next);
	ft_printfd(1, "sa\n");
	return (RETURN_SUCCESS);
}

int	ps_pa(t_ps_data *d)
{
	t_list	*new_head;

	if (ft_lstsize(d->pile_b) == 0)
		return (RETURN_ERROR);
	new_head = d->pile_b->next;
	d->pile_b->next = d->pile_a;
	d->pile_a = d->pile_b;
	d->pile_b = new_head;
	ft_printfd(1, "pa\n");
	return (RETURN_SUCCESS);
}

int	ps_ra(t_ps_data *d)
{
	if (ft_lstsize(d->pile_a) == 1)
		return (RETURN_ERROR);
	ft_lst_rotate(&d->pile_a, 1);
	ft_printfd(1, "ra\n");
	return (RETURN_SUCCESS);
}

int	ps_rra(t_ps_data *d)
{
	if (ft_lstsize(d->pile_a) == 1)
		return (RETURN_ERROR);
	ft_lst_unrotate(&d->pile_a, 1);
	ft_printfd(1, "rra\n");
	return (RETURN_SUCCESS);
}
