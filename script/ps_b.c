/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_b.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 22:38:02 by emaillet          #+#    #+#             */
/*   Updated: 2025/02/11 11:23:40 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps/push_swap.h"

int	ps_sb(t_ps_data *d)
{
	if (ft_lstsize(d->pile_b) == 1)
		return (RETURN_ERROR);
	ft_lst_swap(&d->pile_b, &d->pile_b->next);
	if (PS_CHECKER == 0)
		ft_printfd(1, "sb\n");
	return (RETURN_SUCCESS);
}

int	ps_pb(t_ps_data *d)
{
	t_list	*new_head;

	if (ft_lstsize(d->pile_a) == 0)
		return (RETURN_ERROR);
	new_head = d->pile_a->next;
	d->pile_a->next = d->pile_b;
	d->pile_b = d->pile_a;
	d->pile_a = new_head;
	if (PS_CHECKER == 0)
		ft_printfd(1, "pb\n");
	return (RETURN_SUCCESS);
}

int	ps_rb(t_ps_data *d)
{
	if (ft_lstsize(d->pile_b) == 1)
		return (RETURN_ERROR);
	ft_lst_rotate(&d->pile_b, 1);
	if (PS_CHECKER == 0)
		ft_printfd(1, "rb\n");
	return (RETURN_SUCCESS);
}

int	ps_rrb(t_ps_data *d)
{
	if (ft_lstsize(d->pile_b) == 1)
		return (RETURN_ERROR);
	ft_lst_unrotate(&d->pile_b, 1);
	if (PS_CHECKER == 0)
		ft_printfd(1, "rrb\n");
	return (RETURN_SUCCESS);
}

void	ps_pb_all(t_ps_data *d)
{
	int	i;

	i = ft_lstsize(d->pile_a);
	while (i)
	{
		ps_pb(d);
		i--;
	}
}
