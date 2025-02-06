/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: LolelsayFR <emaillet@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:56:40 by LolelsayFR        #+#    #+#             */
/*   Updated: 2025/02/06 12:18:58 by emaillet         ###   ########.fr       */
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

static void	rot_finish_a(t_ps_data *d, int rot_a)
{
	if (rot_a <= ft_lstsize(d->pile_a) / 2)
	{
		while (rot_a > 1)
		{
			ps_ra(d);
			rot_a--;
		}
	}
	else
	{
		while (rot_a <= ft_lstsize(d->pile_a))
		{
			ps_rra(d);
			rot_a++;
		}
	}
}

static void	rot_finish_b(t_ps_data *d, int rot_b)
{
	if (rot_b <= ft_lstsize(d->pile_b) / 2)
	{
		while (rot_b > 1)
		{
			ps_rb(d);
			rot_b--;
		}
	}
	else
	{
		while (rot_b <= ft_lstsize(d->pile_b))
		{
			ps_rrb(d);
			rot_b++;
		}
	}
}

void	rotate_both(t_ps_data *d, int rot_a, int rot_b)
{
	if (rot_a <= ft_lstsize(d->pile_a) / 2
		|| rot_b <= ft_lstsize(d->pile_b) / 2)
	{
		while (rot_a > 1 && rot_b > 1)
		{
			ps_rr(d);
			rot_b--;
			rot_a--;
		}
	}
	else
	{
		while (rot_a <= ft_lstsize(d->pile_a) && rot_b <= ft_lstsize(d->pile_b))
		{
			ps_rrr(d);
			rot_b++;
			rot_a++;
		}
	}
	rot_finish_a(d, rot_a);
	rot_finish_b(d, rot_b);
}
