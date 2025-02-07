/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 22:36:53 by emaillet          #+#    #+#             */
/*   Updated: 2025/02/07 11:11:19 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstprintfd_ps(t_list *list_a, t_list *list_b, int fd)
{
	t_list	*tmp_a;
	t_list	*tmp_b;
	size_t	len;

	tmp_a = list_a;
	tmp_b = list_b;
	if (ft_lstsize(list_a) > ft_lstsize(list_b) && ft_printfd(fd, "\nA\t\tB\n"))
		len = ft_lstsize(list_a);
	else
		len = ft_lstsize(list_b);
	while (len--)
	{
		if (tmp_a != NULL)
			ft_printfd(fd, "%d\t\t", (long)tmp_a->content);
		else
			ft_printfd(fd, " \t\t");
		if (tmp_b != NULL)
			ft_printfd(fd, "%d\n⬇\t\t⬇\n", (long)tmp_b->content);
		else
			ft_printfd(fd, " \n⬇\n");
		if (tmp_a != NULL)
			tmp_a = tmp_a->next;
		if (tmp_b != NULL)
			tmp_b = tmp_b->next;
	}
}

int	lst_is_sorted(t_list *lst, int order)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp != NULL)
	{
		if (tmp->next != NULL
			&& (long)tmp->content * order > (long)tmp->next->content * order)
			return (RETURN_ERROR);
		tmp = tmp->next;
	}
	return (RETURN_SUCCESS);
}

long	get_b(t_ps_data *d, int i)
{
	t_list	*tmp;

	if (i == 0)
		return ((long)ft_lstlast(d->pile_b)->content);
	tmp = d->pile_b;
	if (!d->pile_b || i > ft_lstsize(d->pile_b) || i < 0)
		return (RETURN_ERROR);
	while (--i && tmp != NULL)
		tmp = tmp->next;
	return ((long)tmp->content);
}

long	get_a(t_ps_data *d, int i)
{
	t_list	*tmp;

	if (i == 0)
		return ((long)ft_lstlast(d->pile_a)->content);
	tmp = d->pile_a;
	if (!d->pile_a || i > ft_lstsize(d->pile_a) || i < 0)
		return (RETURN_ERROR);
	while (--i && tmp != NULL)
		tmp = tmp->next;
	return ((long)tmp->content);
}
