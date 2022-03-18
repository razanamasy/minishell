/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <lefendie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:10:10 by lefendie          #+#    #+#             */
/*   Updated: 2022/02/04 12:39:17 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*free_s1(char **s1)
{
	if (*s1 != NULL)
		free(*s1);
	return (NULL);
}

char	*ft_strjoin_c(char *s1, char c)
{
	char	*n_str;
	int		i;

	i = 0;
	if (!s1 || !c)
		return (0);
	n_str = malloc((ft_strlen(s1) + 1 + 1) * sizeof(char));
	if (!n_str)
		return (free_s1(&s1));
	while (s1[i])
	{
		n_str[i] = s1[i];
		i++;
	}
	n_str[i] = c;
	i++;
	n_str[i] = '\0';
	if (s1 != NULL)
	{
		free_old_str(&s1);
		s1 = NULL;
	}
	return (n_str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*n_str;
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (!s1 || !s2)
		return (0);
	n_str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!n_str)
		return (free_s1(&s1));
	while (s1[++i])
		n_str[i] = s1[i];
	while (s2[++j])
	{
		n_str[i] = s2[j];
		i++;
	}
	n_str[i] = '\0';
	if (s1 != NULL)
	{
		free_old_str(&s1);
		s1 = NULL;
	}
	return (n_str);
}
