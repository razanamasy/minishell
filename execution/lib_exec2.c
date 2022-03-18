/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_exec2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:12:10 by lefendie          #+#    #+#             */
/*   Updated: 2022/02/09 11:37:08 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

const char	*ft_skip(const char *str, const char sep)
{
	while (*str == sep)
		str++;
	return (str);
}

char	*ft_strsufx(char *sufx, char *str)
{
	char	*new_str;
	int		i;
	int		size;

	i = -1;
	size = ft_strlen(sufx) + ft_strlen(str) + 1;
	new_str = malloc(sizeof(char) * size);
	if (!new_str)
		return (NULL);
	while (str[++i])
		new_str[i] = str[i];
	while (*sufx)
	{
		new_str[i] = *sufx;
		i++;
		sufx++;
	}
	new_str[i] = '\0';
	return (new_str);
}

int	list_size(void **list)
{
	int	size;

	size = 0;
	if (!list)
		return (0);
	while (list[size])
		size++;
	return (size);
}

void	*ft_memset(void *s, int c, size_t n)
{
	char	*new_s;

	new_s = (char *)s;
	while (n--)
		new_s[n] = c;
	return (new_s);
}

int	ft_access(char *path)
{
	if (!path)
		return (-1);
	return (access(path, F_OK));
}
