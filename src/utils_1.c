/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ner-roui <ner-roui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:01:41 by ner-roui          #+#    #+#             */
/*   Updated: 2024/09/12 01:32:32 by ner-roui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_count(char **av)
{
	int		i;
	int		j;
	int		count;
	char	**str;

	i = 1;
	count = 0;
	while (av[i])
	{
		j = 0;
		str = ft_split(av[i], ' ');
		while (str[j])
		{
			j++;
			count++;
		}
		ft_free(str, j);
		free(str);
		i++;
	}
	return (count);
}

void	check(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0')
		ft_error("Error");
	if (str[i] == ' ')
		ft_error("Error");
}

int	*fill_array(char **av, int count)
{
	int		i;
	int		j;
	int		index;
	int		*arr;
	char	**str;

	index = 0;
	i = 1;
	arr = malloc(sizeof(int) * count);
	while (av[i])
	{
		j = 0;
		check(av[i]);
		str = ft_split(av[i], ' ');
		while (str[j])
		{
			arr[index] = ft_atoi(str[j]);
			index++;
			j++;
		}
		ft_free(str, j);
		free(str);
		i++;
	}
	return (arr);
}
