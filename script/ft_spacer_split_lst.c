/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spacer_split_lst.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:52:01 by emaillet          #+#    #+#             */
/*   Updated: 2025/02/06 11:56:54 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_freeall(char **result, size_t j)
{
	while (j--)
		nufree(result[j]);
	nufree(result);
}

static size_t	ft_countab(char const *s)
{
	size_t	count;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	count = 0;
	while (s[i])
	{
		while (ft_isspace(s[i]))
			i++;
		if (s[i])
		{
			count++;
			while (s[i] && !ft_isspace(s[i]))
				i++;
		}
	}
	return (count);
}

static char	**ft_splitinject(char const *s, char **result)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (ft_isspace(s[i]))
			i++;
		if (s[i])
		{
			start = i;
			while (s[i] && !ft_isspace(s[i]))
				i++;
			result[j] = ft_substr(s, start, i - start);
			if (!result[j])
				return (ft_freeall(result, j), NULL);
			ft_lstadd_back(ft_alist(), ft_lstnew(result[j]));
			j++;
		}
	}
	result[j] = NULL;
	return (result);
}

char	**ft_spacer_split_lst(char const *s)
{
	char	**result;

	result = (char **)ft_calloc((ft_countab(s) + 1), sizeof(char *));
	if (!result)
		return (NULL);
	result = ft_splitinject(s, result);
	ft_lstadd_back(ft_alist(), ft_lstnew(result));
	return (result);
}

int	init_minmax(t_ps_data *data)
{
	t_list		*stack;

	stack = data->pile_a;
	data->max = (long)stack->content;
	data->min = data->max;
	while (stack != NULL)
	{
		if ((long)stack->content > data->max)
			data->max = (long)stack->content;
		if ((long)stack->content < data->min)
			data->min = (long)stack->content;
		stack = stack->next;
	}
	get_fifth_max(data, data->pile_a);
	if (PS_DEBUG)
		ft_printfd(1, YEL"Min = %d \nMax = %d\nFIFTH = %d\n"RES,
			data->min, data->max, data->top_five[4]);
	return (RETURN_SUCCESS);
}
