/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 23:26:21 by emaillet          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/02/04 11:25:53 by emaillet         ###   ########.fr       */
=======
/*   Updated: 2025/02/04 15:29:35 by emaillet         ###   ########.fr       */
>>>>>>> 0aff9c0 (Not redraw, go back to my chunk)
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

<<<<<<< HEAD
long	get_min(t_list *lst)
=======
int	is_in_current_chunk(t_ps_data *d, int chunk_num, int i)
{
	long	start;

	start = d->min + ((chunk_num - 1) * d->chunk_size);
	if (i > 0 && get_a(d, i) >= start && get_a(d, i) < start + d->chunk_size)
		return (1);
	else if (i < 0 && get_b(d, i * -1) >= start
		&& get_b(d, i * -1) < start + d->chunk_size)
		return (1);
	return (0);
}

int	get_first_chunk(int chunk, t_ps_data *d)
>>>>>>> 0aff9c0 (Not redraw, go back to my chunk)
{
	t_list	*tmp;
	int		i;
	int		res;

<<<<<<< HEAD
	tmp = lst;
	min = (long)tmp->content;
=======
	tmp = d->pile_a;
>>>>>>> 0aff9c0 (Not redraw, go back to my chunk)
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
	int		i;
	int		res;

<<<<<<< HEAD
	tmp = lst;
	max = (long)tmp->content;
=======
	tmp = d->pile_a;
>>>>>>> 0aff9c0 (Not redraw, go back to my chunk)
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

t_list	*ft_lst_get_prev(t_list *lst, t_list *head)
{
	t_list	*tmp;

	tmp = head;
	while (tmp != NULL)
	{
		if (tmp->next > lst)
			return (tmp);
		tmp = tmp->next;
	}
	return (tmp);
}
