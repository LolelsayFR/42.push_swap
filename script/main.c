/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:58:58 by emaillet          #+#    #+#             */
/*   Updated: 2025/01/20 21:04:35 by emaillet         ###   ########.fr       */
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
	if (ft_lstsize(list_a) > ft_lstsize(list_b))
		len = ft_lstsize(list_a);
	else
		len = ft_lstsize(list_b);
	while (len--)
	{
		if (tmp_a != NULL)
			ft_printfd(fd, "%d\t\t", (long)tmp_a->content);
		else
			ft_printfd(fd, "NULL\t\t");
		if (tmp_b != NULL)
			ft_printfd(fd, "%d\n⬇\t\t⬇\n", (long)tmp_b->content);
		else
			ft_printfd(fd, "NULL\n⬇\n");
		if (tmp_a != NULL)
			tmp_a = tmp_a->next;
		if (tmp_b != NULL)
			tmp_b = tmp_b->next;
	}
}

static void	set_zero(void *i)
{
	i = 0;
}

int	main(int ac, char **av)
{
	int			i;
	char		**my_av;
	t_list		*pile_a;
	t_list		*pile_b;

	pile_a = NULL;
	pile_b = NULL;
	my_av = NULL;
	i = 0;
	if (ac == 1)
		return (0);
	else if (ac == 2)
		my_av = ft_spacer_split_lst(av[1]);
	else if (ac > 2)
		my_av = ft_strtabdup_lst(++av);
	while (my_av[i])
	{
		if (my_av[i][0])
			ft_ps_atol(my_av[i], &pile_a);
		i++;
	}
	ft_lstprintfd_ps(pile_a, pile_b, 1);
	ft_lstclear(&pile_a, set_zero);
	ft_lstclear(&pile_b, set_zero);
	ft_alist_free();
	return (EXIT_SUCCESS);
}
