/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_exec3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:14:37 by lefendie          #+#    #+#             */
/*   Updated: 2022/02/09 16:21:23 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	size_t			src_len;

	i = 0;
	if (!src)
		return (0);
	src_len = ft_strlen((char *)src);
	if (size > 0)
	{
		while (src[i] && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_len);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int	i;

	i = 0;
	while (i < (int)n && (dest || src))
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

char	**ft_strlistdup(char **strlist)
{
	char	**n_strlist;
	int		i;

	i = 0;
	while (strlist[i])
		i++;
	n_strlist = malloc(sizeof(char *) * (i + 1));
	if (!n_strlist)
		return (NULL);
	n_strlist[i] = NULL;
	i--;
	while (i > -1)
	{
		n_strlist[i] = ft_strdup(strlist[i]);
		i--;
	}
	return (n_strlist);
}
