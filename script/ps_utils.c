/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 22:36:53 by emaillet          #+#    #+#             */
/*   Updated: 2025/02/01 03:29:11 by emaillet         ###   ########.fr       */
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

int	pre_check(char **av)
{
	int	i;

	i = 1;
	if (PS_DEBUG == 1)
		ft_printfd(1, GRN"\nPush swap args :\n"RES);
	while (av[i])
	{
		if (PS_DEBUG == 1)
			ft_printfd(1, "%s\n", av[i]);
		i++;
	}
	if (PS_DEBUG == 1)
		ft_printfd(1, GRN"End of Push swap args..\n\n"RES);
	return (0);
}

long	get_b(t_ps_data *d, int i)
{
	t_list	*tmp;

	tmp = d->pile_b;
	if (!d->pile_b || i > ft_lstsize(d->pile_b))
		return (ft_printfd(2, "[b] error, cant get long\n"), RETURN_ERROR);
	while (--i && tmp != NULL)
		tmp = tmp->next;
	return ((long)tmp->content);
}

long	get_a(t_ps_data *d, int i)
{
	t_list	*tmp;

	tmp = d->pile_a;
	if (!d->pile_a || i > ft_lstsize(d->pile_a))
		return (ft_printfd(2, "[a] error, cant get long\n"), RETURN_ERROR);
	while (--i && tmp != NULL)
		tmp = tmp->next;
	return ((long)tmp->content);
}
