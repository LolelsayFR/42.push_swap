/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spacer_split_lst.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:52:01 by emaillet          #+#    #+#             */
/*   Updated: 2025/01/20 18:20:34 by emaillet         ###   ########.fr       */
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

//int	main(int argc, char *argv[])
//{
//	char	**splited;
//
//	splited = NULL;
//	if (argc == 2)
//	{
//		splited = ft_split(argv[1], ' ');
//		while (*splited != NULL)
//		{
//			ft_putendl_fd(*splited, 1);
//			free(*splited);
//			splited++;
//		}
//		free(splited);
//	}
//	return (1);
//}
