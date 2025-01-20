/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_atol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 04:07:02 by emaillet          #+#    #+#             */
/*   Updated: 2025/01/20 21:11:54 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_zero(void *i)
{
	i = 0;
}

static void	ko(t_list **lst)
{
	ft_printfd(2, "Error\n");
	ft_lstclear(lst, set_zero);
	ft_alist_free();
	exit(-1);
}

static int	check_char(const char *str, t_list **lst)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '-' && str[i] != '+' && ft_isdigit(str[i] == 0))
			ko(lst);
		i++;
	}
	i = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	return (i);
}

long	ft_ps_atol(const char *str, t_list **lst)
{
	long	val;
	long	sign;
	long	i;

	if (!str)
		return (0);
	val = 0;
	sign = 1;
	i = check_char(str, lst);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		val = val * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] != '\0')
		ko(lst);
	ft_lstadd_back(lst, ft_lstnew((void *)(val * sign)));
	return (val * sign);
}
