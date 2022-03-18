/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazanam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 16:33:32 by hrazanam          #+#    #+#             */
/*   Updated: 2022/02/06 17:45:23 by hrazanam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_n(char c)
{
	if (c == 'n')
		return (1);
	return (0);
}

int	is_opt(char *arg)
{
	int	i;

	i = 0;
	if (arg != NULL && (!ft_strncmp(arg, "-n", 2)))
	{
		i = 2;
		while (arg[i] && is_n(arg[i]))
			i++;
		if (arg[i] == '\0')
			return (1);
	}
	return (0);
}

int	to_print_creator(char **args, int *i, char **to_print)
{
	while (args[*i] != NULL)
	{
		if (args[*i][0] == 26)
		{
			if (args[*i + 1] == NULL)
				break ;
			else
				*to_print = ft_strjoin(*to_print, " ");
		}
		else
			*to_print = ft_strjoin(*to_print, args[*i]);
		if (!*to_print)
			return (1);
		if (args[*i + 1] != NULL && !(args[*i][0] == 26))
		{
			*to_print = ft_strjoin(*to_print, " ");
			if (!*to_print)
				return (1);
		}
		*i = *i + 1;
	}
	return (0);
}

void	print_str(char *to_print, int option)
{
	if (option)
		write(1, to_print, ft_strlen(to_print));
	else
	{
		write(1, to_print, ft_strlen(to_print));
		write(1, "\n", 1);
	}
}

int	b_echo(char **args)
{
	int		option;
	int		i;
	char	*to_print;
	int		ret;

	option = 0;
	i = 1;
	to_print = NULL;
	while (args[i] != NULL && is_opt(args[i]))
	{
		option = 1;
		i++;
	}
	ret = init_print(&i, args, &to_print);
	if (ret)
		return (1);
	if (to_print_creator(args, &i, &to_print))
		return (1);
	print_str(to_print, option);
	free(to_print);
	return (0);
}
