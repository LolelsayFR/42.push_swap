/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_both.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 00:33:00 by emaillet          #+#    #+#             */
/*   Updated: 2025/01/22 00:36:09 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_ss(t_ps_data *d)
{
	if (ft_lstsize(d->pile_b) == 1 && ft_lstsize(d->pile_a) == 1)
		return (RETURN_ERROR);
	ft_lst_swap(&d->pile_b, &d->pile_b->next);
	ft_lst_swap(&d->pile_a, &d->pile_a->next);
	ft_printfd(1, "ss\n");
	return (RETURN_SUCCESS);
}

int	ps_rr(t_ps_data *d)
{
	if (ft_lstsize(d->pile_b) == 1 && ft_lstsize(d->pile_a) == 1)
		return (RETURN_ERROR);
	ft_lst_rotate(&d->pile_b, 1);
	ft_lst_rotate(&d->pile_a, 1);
	ft_printfd(1, "rr\n");
	return (RETURN_SUCCESS);
}

int	ps_rrr(t_ps_data *d)
{
	if (ft_lstsize(d->pile_b) == 1 && ft_lstsize(d->pile_b) == 1)
		return (RETURN_ERROR);
	ft_lst_unrotate(&d->pile_a, 1);
	ft_lst_unrotate(&d->pile_b, 1);
	ft_printfd(1, "rrr\n");
	return (RETURN_SUCCESS);
}
