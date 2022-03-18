/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazanam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:45:03 by hrazanam          #+#    #+#             */
/*   Updated: 2021/10/27 12:58:07 by hrazanam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	malloc_error(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		if (split[i] != 0)
		{
			free(split[i]);
			split[i] = NULL;
		}
		i++;
	}
	if (split != 0)
	{
		free(split);
		split = NULL;
	}
	return (0);
}

static int	linecount(char *s, char c)
{
	int	i;
	int	lc;

	i = 0;
	lc = 0;
	if (ft_strlen(s) == 0)
		return (0);
	while (s[i] == c && s[i])
		i++;
	while (s[i])
	{
		if (s[i] == c && s[i - 1] != c)
			lc++;
		i++;
	}
	if (s[i] == '\0' && s[i - 1] != c)
		lc++;
	return (lc);
}

int	trim(char **split, char *s, char c, int line)
{
	int	i;
	int	start;
	int	end;

	i = 0;
	start = 0;
	while (i < line)
	{
		while (s[start] == c)
			start++;
		end = start;
		while (s[end] != c && s[end])
			end++;
		split[i] = ft_substr(s, start, (end - start));
		if (!split[i])
			return (malloc_error(split));
		start = end;
		i++;
	}
	return (1);
}

char	**ft_split_(char *s, char c)
{
	char	**split;
	int		line;
	int		ret;

	if (!s)
		return (0);
	line = linecount(s, c);
	split = (char **)malloc((line + 1) * sizeof(char *));
	if (!split)
		return (0);
	split[line] = 0;
	ret = trim(split, s, c, line);
	if (ret == 0)
		return (0);
	return (split);
}
