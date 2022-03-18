/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazanam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 17:40:19 by hrazanam          #+#    #+#             */
/*   Updated: 2022/02/05 17:41:53 by hrazanam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_first_char(char *key, char *prefix)
{
	char	*suffix;

	suffix = " : not a valid identifier\n";
	if (!ft_isalpha(key[0]) && key[0] != '_')
	{
		write(2, prefix, ft_strlen(prefix));
		if (key[0] == 26)
			write(2, "\0", 1);
		else
			write(2, key, ft_strlen(key));
		write(2, suffix, ft_strlen(suffix));
		return (1);
	}
	return (0);
}

int	check_body_key_export(char *key, int i, char *prefix)
{
	char	*suffix;

	suffix = " : not a valid identifier\n";
	if (key[i] == '=' || key[i] == '\0')
		return (2);
	if (!ft_isalnum(key[i]) && key[i] != '_')
	{
		write(2, prefix, ft_strlen(prefix));
		write(2, key, ft_strlen(key));
		write(2, suffix, ft_strlen(suffix));
		return (1);
	}
	return (0);
}

int	check_body_key_unset(char *key, int i, char *prefix)
{
	char	*suffix;

	suffix = " : not a valid identifier\n";
	if (key[i] == '\0')
		return (2);
	if (!ft_isalnum(key[i]) && key[i] != '_')
	{
		write(2, prefix, ft_strlen(prefix));
		write(2, key, ft_strlen(key));
		write(2, suffix, ft_strlen(suffix));
		return (1);
	}
	return (0);
}

int	is_valid_key(char *key, char *prefix, int mode)
{
	int	i;
	int	ret;

	if (check_first_char(key, prefix) == 1)
		return (1);
	i = 1;
	while (key[i])
	{
		if (mode == 1)
			ret = check_body_key_export(key, i, prefix);
		else if (mode == 2)
			ret = check_body_key_unset(key, i, prefix);
		if (ret == 2)
			break ;
		else if (ret == 1)
			return (1);
		i++;
	}
	return (0);
}
