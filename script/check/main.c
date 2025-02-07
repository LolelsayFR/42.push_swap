/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:58:58 by emaillet          #+#    #+#             */
/*   Updated: 2025/02/07 11:16:41 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ps/push_swap.h"

int	pre_check(char **av, t_ps_data *d)
{
	int	i;

	i = 1;
	if (PS_DEBUG == 1)
		ft_printfd(1, GRN"\nPush swap args :\n"RES);
	while (av[i])
	{
		if (PS_DEBUG == 1)
			ft_printfd(1, "%s\n", av[i]);
		if (!av[i][0])
		{
			free(d);
			ft_printfd(2, "Error\n");
			exit(-1);
		}
		i++;
	}
	if (PS_DEBUG == 1)
		ft_printfd(1, GRN"End of Push swap args..\n\n"RES);
	return (0);
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

static void	ft_push_swap_check(t_ps_data *d)
{
	(void)d;
	ft_printf(RED"test\n"RES);
}

int	main(int ac, char **av)
{
	t_ps_data	*d;
	int			i;

	d = ft_calloc(1, sizeof(t_ps_data));
	i = 0;
	if (ac == 1)
		return (free(d), 0);
	else if (av[1][0] == '\0')
		return (ft_printfd(2, "Error\n"), free(d), 0);
	pre_check(av, d);
	if (ac == 2)
		d->my_av = ft_spacer_split_lst(av[1]);
	else if (ac > 2)
		d->my_av = ft_strtabdup_lst(++av);
	ft_lstadd_back(ft_alist(), ft_lstnew(d));
	while (d->my_av[i])
		if (d->my_av[i][0])
			ft_ps_atol(d->my_av[i++], &d->pile_a);
	if (lst_is_sorted(d->pile_a, 1) == RETURN_ERROR)
		ft_push_swap_check(d);
	ft_lstclear(&d->pile_a, set_zero);
	ft_lstclear(&d->pile_b, set_zero);
	ft_alist_free();
	return (EXIT_SUCCESS);
}
