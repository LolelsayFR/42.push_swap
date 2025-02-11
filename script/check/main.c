/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:58:58 by emaillet          #+#    #+#             */
/*   Updated: 2025/02/11 11:57:01 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ps/push_swap.h"

int	pre_check(char **av, t_ps_data *d)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (!av[i][0])
		{
			free(d);
			ft_printfd(2, "Error\n");
			exit(-1);
		}
		i++;
	}
	return (0);
}

void	act_handler(t_ps_data *d, char **act, int i)
{
	while (act[++i] != NULL)
	{
		if (ft_strnstr(act[i], "pa", 3))
			ps_pa(d);
		else if (ft_strnstr(act[i], "pb", 3))
			ps_pb(d);
		else if (ft_strnstr(act[i], "rra", 3))
			ps_rra(d);
		else if (ft_strnstr(act[i], "rrb", 3))
			ps_rrb(d);
		else if (ft_strnstr(act[i], "ra", 3))
			ps_ra(d);
		else if (ft_strnstr(act[i], "rb", 3))
			ps_rb(d);
		else if (ft_strnstr(act[i], "sa", 3))
			ps_sa(d);
		else if (ft_strnstr(act[i], "sb", 3))
			ps_sb(d);
		else if (ft_strnstr(act[i], "rrr", 3))
			ps_rrr(d);
		else if (ft_strnstr(act[i], "rr", 3))
			ps_rr(d);
		else if (ft_strnstr(act[i], "ss", 3))
			ps_ss(d);
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

static void	ft_push_swap_check(t_ps_data *d)
{
	char	*buf;
	char	*str;
	char	*tmp;
	char	**act;
	int		i;

	buf = ft_calloc(2, sizeof(char));
	str = ft_calloc(1, sizeof(char));
	ft_lstadd_back(ft_alist(), ft_lstnew(str));
	i = 1;
	while (i > 0)
	{
		tmp = ft_strjoin_lst(str, buf);
		str = tmp;
		i = read(0, buf, 1);
	}
	act = ft_split_lst(str, '\n');
	act_handler(d, act, -1);
	if (lst_is_sorted(d->pile_a, 1) == RETURN_SUCCESS
		&& ft_lstsize(d->pile_b) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free(buf);
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
