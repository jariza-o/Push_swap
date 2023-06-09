/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 17:15:49 by jariza-o          #+#    #+#             */
/*   Updated: 2023/06/09 17:13:48 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_splited(char **argv)
{
	char	**split;
	int		size;
	int		n;
	int		i;
	int		j;
	int		k;

	i = 0;
	while (argv[i++])
		size++;
	split = (char **)malloc(sizeof(char *) * (size + 1)); // ver si al llamar a la variable delante va el *
	if (split == NULL)
		return (NULL);
	n = 1;
	i = 0;
	j = 0;
	k = 0;
	while (argv[n])
	{
		size = 0;
		while (argv[n][i++])
			size++;
		split[n] = (char *)malloc(sizeof(char) * (size + 1));
		if (split[n] == NULL)
			return (NULL);
		i = 0;
		while (argv[n][i] != '\0')
		{
			if (argv[n][i] != 32)
			{
				split[j][k] = argv[n][i];
				i++;
				k++;
			}
			else
			{
				n++;
				j++;
				k = 0;
				i = 0;
			}
		}
		n++;
		j++;
		k = 0;
		i = 0;
	}
	return (split);
}

int	ft_count_nums(char **argv)
{
	int	n;

	n = 0;
	while (argv[n])
		n++;
	return (n);
}