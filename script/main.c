/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:58:58 by emaillet          #+#    #+#             */
/*   Updated: 2025/02/01 04:18:47 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_push_swap(t_ps_data *d)
{
	if (ft_lstsize(d->pile_a) == 2)
		ps_sa(d);
	else if (ft_lstsize(d->pile_a) == 3)
		sort_three(d);
	else if (ft_lstsize(d->pile_a) == 4)
		sort_four(d);
	else if (ft_lstsize(d->pile_a) <= 5)
		sort_five(d);
	else
		ps_sort(d);
	if (PS_DEBUG == 1)
		ft_lstprintfd_ps(d->pile_a, d->pile_b, 1);
}

int	main(int ac, char **av)
{
	t_ps_data	*d;
	int			i;

	d = ft_calloc(1, sizeof(t_ps_data));
	i = 0;
	if (ac == 1 || av[1][0] == '\0')
		return (ft_printfd(2, "Error\n"), free(d), 0);
	pre_check(av);
	if (ac == 2)
		d->my_av = ft_spacer_split_lst(av[1]);
	else if (ac > 2)
		d->my_av = ft_strtabdup_lst(++av);
	ft_lstadd_back(ft_alist(), ft_lstnew(d));
	while (d->my_av[i])
	{
		if (d->my_av[i][0])
			ft_ps_atol(d->my_av[i++], &d->pile_a);
	}
	init_minmax(d);
	if (lst_is_sorted(d->pile_a, 1) == RETURN_ERROR)
		ft_push_swap(d);
	ft_lstclear(&d->pile_a, set_zero);
	ft_lstclear(&d->pile_b, set_zero);
	ft_alist_free();
	return (EXIT_SUCCESS);
}

int	comp_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
