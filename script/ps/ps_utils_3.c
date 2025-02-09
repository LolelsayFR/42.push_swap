/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: LolelsayFR <emaillet@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:56:40 by LolelsayFR        #+#    #+#             */
/*   Updated: 2025/02/09 15:05:15 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	rotate_both_utils(t_ps_data *d, int *rot_a, int *rot_b)
{
	const int	size_a = ft_lstsize(d->pile_a);
	const int	size_b = ft_lstsize(d->pile_b);

	if ((*rot_a <= size_a / 2 && *rot_b > (size_b / 5) * 2
			&& *rot_b < (size_b / 5) * 3) || (*rot_b <= size_b / 2
			&& *rot_b > (size_b / 5) * 2 && *rot_b < (size_b / 5) * 3))
	{
		while (*rot_a > 1 && *rot_b > 1)
		{
			ps_rr(d);
			rot_b--;
			rot_a--;
		}
	}
	else if ((*rot_a > size_a / 2 && *rot_b > (size_b / 5) * 2
			&& *rot_b < (size_b / 5) * 3) || (*rot_b > size_b / 2
			&& *rot_b > (size_b / 5) * 2 && *rot_b < (size_b / 5) * 3))
	{
		while (*rot_a <= size_a && *rot_b <= size_b)
		{
			ps_rrr(d);
			rot_b++;
			rot_a++;
		}
	}
}

void	rotate_both(t_ps_data *d, int rot_a, int rot_b)
{
	if (rot_a <= ft_lstsize(d->pile_a) / 2
		&& rot_b <= ft_lstsize(d->pile_b) / 2)
	{
		while (rot_a > 1 && rot_b > 1)
		{
			ps_rr(d);
			rot_b--;
			rot_a--;
		}
	}
	else if (rot_a > ft_lstsize(d->pile_a) / 2
		&& rot_b > ft_lstsize(d->pile_b) / 2)
	{
		while (rot_a <= ft_lstsize(d->pile_a) && rot_b <= ft_lstsize(d->pile_b))
		{
			ps_rrr(d);
			rot_b++;
			rot_a++;
		}
	}
	else
		rotate_both_utils(d, &rot_a, &rot_b);
	rot_finish_a(d, rot_a);
	rot_finish_b(d, rot_b);
}

int	can_push(t_ps_data *d, int pos_a, int pos_b)
{
	const long	min_a = get_min(d->pile_a);

	if (get_b(d, pos_b) < get_a(d, min_a)
		&& get_a(d, 1) == get_a(d, min_a))
		return (1);
	if (get_a(d, pos_a) > get_b(d, pos_b)
		&& get_a(d, pos_a - 1) < get_b(d, pos_b))
		return (1);
	return (0);
}
