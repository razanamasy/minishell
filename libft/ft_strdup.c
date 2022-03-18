/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <lefendie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:12:12 by lefendie          #+#    #+#             */
/*   Updated: 2022/02/04 12:27:32 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strdup(char *str)
{
	int		i;
	char	*cpy;
	int		size;

	i = 0;
	size = ft_strlen(str);
	cpy = malloc((size + 1) * sizeof(char));
	if (!cpy)
		return (0);
	while (str[i])
	{
		cpy[i] = str[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

char	*ft_strdup_c(char c)
{
	int		i;
	char	*cpy;

	i = 0;
	cpy = malloc((1 + 1) * sizeof(char));
	if (!cpy)
		return (0);
	cpy[i] = c;
	i++;
	cpy[i] = '\0';
	return (cpy);
}
