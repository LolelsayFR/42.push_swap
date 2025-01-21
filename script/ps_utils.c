/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 22:36:53 by emaillet          #+#    #+#             */
/*   Updated: 2025/01/22 00:30:34 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_zero(void *i)
{
	(void)i;
	i = 0;
}

void	ft_lstprintfd_ps(t_list *list_a, t_list *list_b, int fd)
{
	t_list	*tmp_a;
	t_list	*tmp_b;
	size_t	len;

	tmp_a = list_a;
	tmp_b = list_b;
	if (ft_lstsize(list_a) > ft_lstsize(list_b))
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

int	lst_is_sorted(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp != NULL)
	{
		if (PS_DEBUG)
			ft_printfd(1, "Check = %i \n", (long)tmp->content);
		if (tmp->next != NULL && (long)tmp->content > (long)tmp->next->content)
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
	return (RETURN_SUCCESS);
}
