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

int	init_print(int *i, char **args, char **to_print)
{
	if (args[*i] == NULL)
		*to_print = ft_strdup("\0");
	else if (args[*i + 1] != NULL && args[*i][0] == 26)
	{
		*to_print = ft_strdup(" ");
		*i = *i + 1;
	}
	else
		*to_print = ft_strdup("\0");
	if (*to_print == NULL)
		return (1);
	return (0);
}
