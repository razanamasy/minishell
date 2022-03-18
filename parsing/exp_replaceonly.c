/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_replaceonly.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazanam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 15:18:03 by hrazanam          #+#    #+#             */
/*   Updated: 2022/02/05 15:19:22 by hrazanam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	replace_var(int *i, char *lst_str1, char **lst_str2, t_data *data)
{
	int		length;
	char	*env_name;
	char	*name_to_check;

	length = 1;
	env_name = NULL;
	name_to_check = NULL;
	if (lst_str1[1] == '?')
		return (is_ret_val(lst_str2, i));
	if (lst_str1[1] != '_' && !ft_isalpha(lst_str1[1]))
		return (end_of_story(lst_str2));
	length = push_or_get_name_size(lst_str1, lst_str2);
	name_to_check = ft_substr(lst_str1, 1, length - 1);
	if (!name_to_check)
		return (1);
	env_name = ft_getenv(name_to_check, data);
	free(name_to_check);
	if (env_name)
	{
		if (push_str(lst_str2, env_name))
			return (fail(lst_str2));
	}
	*i = *i + length - 1;
	return (0);
}
