/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <lefendie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:14:40 by lefendie          #+#    #+#             */
/*   Updated: 2022/02/04 12:15:27 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == '\0' && (unsigned char)c == '\0')
		return ((char *)&s[i]);
	else
		return (NULL);
}

void	free_old_str(char **lst_str)
{
	char	*char_temp;

	if (*lst_str != NULL)
	{
		char_temp = *lst_str;
		*lst_str = NULL;
		free(char_temp);
	}
}

//SUBSTR
static size_t	assign(char *s, unsigned int start, int len)
{
	size_t	size_max;

	size_max = 0;
	if (len > ft_strlen(&s[start]))
		size_max = ft_strlen(&s[start]);
	else
		size_max = len;
	return (size_max);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t			size_max;
	char			*cpy;
	unsigned int	j;

	j = 0;
	if (!s)
		return (0);
	size_max = (size_t)assign(s, start, len);
	if ((int)start > ft_strlen(s))
	{
		cpy = malloc(1 * sizeof(char));
		if (!cpy)
			return (0);
	}
	else
	{
		cpy = (char *)malloc((size_max + 1) * sizeof(char));
		if (!cpy)
			return (0);
		while (j < size_max)
			cpy[j++] = s[start++];
	}
	cpy[j] = '\0';
	return (cpy);
}
