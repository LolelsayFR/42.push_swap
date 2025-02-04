/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: LolelsayFR <emaillet@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:56:40 by LolelsayFR        #+#    #+#             */
/*   Updated: 2025/02/04 16:16:48 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	get_min(t_list *lst)
{
	t_list	*tmp;
	long	min;
	int		i;
	int		res;

	if (!lst || !lst->next)
		return (0);
	tmp = lst;
	min = (long)tmp->content;
	i = 1;
	while (tmp != NULL)
	{
		if ((long)tmp->content < min)
			res = i;
		if ((long)tmp->content < min)
			min = (long)tmp->content;
		tmp = tmp->next;
		i++;
	}
	return (res);
}

long	get_max(t_list *lst)
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
		if ((long)tmp->content > max)
			res = i;
		if ((long)tmp->content > max)
			max = (long)tmp->content;
		tmp = tmp->next;
		i++;
	}
	return (res);
}

void	ps_realign(t_ps_data *d)
{
	int	minpos;

	minpos = get_min(d->pile_a);
	if (minpos <= ft_lstsize(d->pile_b) / 2)
	{
		while (minpos > 0)
		{
			ps_rb(d);
			minpos--;
		}
	}
	else
	{
		while (minpos < ft_lstsize(d->pile_b))
		{
			ps_rrb(d);
			minpos++;
		}
	}
}
