/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <lefendie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:09:12 by lefendie          #+#    #+#             */
/*   Updated: 2022/02/04 12:27:33 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (!n)
		return (0);
	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	while (((s1[i] && s2[i]) && (s1[i] == s2[i])) && (i < n))
		i++;
	if (i != 0 && i == n)
		return ((unsigned char)s1[i - 1] - (unsigned char)s2[i - 1]);
	else
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	while (((s1[i] && s2[i]) && (s1[i] == s2[i])))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
