/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 17:15:49 by jariza-o          #+#    #+#             */
/*   Updated: 2023/05/26 17:44:16 by jariza-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_splited(char **argv[])
{
	char	**split;
	int		n;
	int		i;
	int		j;
	int		k;

	n = 0;
	i = 0;
	j = 0;
	k = 0;
	while(argv[n])
	{
		while(argv[n][i] != '\0')
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