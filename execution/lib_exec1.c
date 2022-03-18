/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_exec1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:27:51 by lefendie          #+#    #+#             */
/*   Updated: 2022/02/09 00:56:54 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_list_size(const char *str, const char sep, char ***result)
{
	int	list_size;

	list_size = 0;
	if (!str)
		return (0);
	while (*str)
	{
		while (*str && *str == sep)
			str++;
		if (*str && *str != sep)
		{
			list_size++;
			while (*str && *str != sep)
				str++;
		}
	}
	list_size++;
	*result = malloc(sizeof(char *) * list_size + 1);
	if (!*result)
		return (-1);
	return (list_size);
}

int	ft_word_size(const char *str, const char sep)
{
	int	word_size;

	word_size = 0;
	while (str[word_size] && str[word_size] != sep)
		word_size++;
	return (word_size);
}

void	*ft_bzero(void *s, size_t n)
{
	char	*new_s;

	new_s = (char *)s;
	while (n--)
		new_s[n] = '\0';
	return (new_s);
}

int	isstr_start_equal(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] && str2[i] && str1[i] == str2[i])
		i++;
	if (!str2[i])
		return (SUCCESS);
	return (FAILURE);
}

int	isstr_equal(char *str1, char *str2)
{
	int	i;

	i = 0;
	if (!(str1 && str2))
		return (FAILURE);
	while (str1[i] && str2[i] && str1[i] == str2[i])
		i++;
	if (!str2[i] && !str1[i])
		return (SUCCESS);
	return (FAILURE);
}
