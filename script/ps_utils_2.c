/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 23:26:21 by emaillet          #+#    #+#             */
/*   Updated: 2025/02/04 11:25:53 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	get_min(t_list *lst)
{
	t_list	*tmp;
	long	min;
	int		i;
	int		res;

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
