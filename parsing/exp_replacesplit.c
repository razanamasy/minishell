/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_replacesplit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazanam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 15:19:54 by hrazanam          #+#    #+#             */
/*   Updated: 2022/02/05 15:22:30 by hrazanam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	trim_space(int *i, int *space_start, char *env_name)
{
	*space_start = 0;
	while (is_space(env_name[*i]))
	{
		*i = *i + 1;
		*space_start = 1;
	}
	return (0);
}

int	prepare_str_token(int *i, char *env_name, char **lst_str2)
{
	if (push_c(lst_str2, env_name[*i]))
		return (1);
	*i = *i + 1;
	return (0);
}

int	push_and_next(int *i, char **lst_str2, t_token **small_lst)
{
	if (lst_push(lst_str2, small_lst))
		return (1);
	*i = *i + 1;
	return (0);
}

int	expansion_split(t_token **small_lst, char *env_name,
		char **lst_str2, t_data *data)
{
	int	i;
	int	space_start;

	i = 0;
	trim_space(&i, &space_start, env_name);
	if (push_rest(data->i, lst_str2, space_start, small_lst))
		return (1);
	while (env_name[i])
	{
		if (!is_space(env_name[i]))
		{
			if (prepare_str_token(&i, env_name, lst_str2))
				return (1);
		}
		else
		{
			if (push_and_next(&i, lst_str2, small_lst))
				return (1);
			while (is_space(env_name[i]))
				i++;
		}
	}
	return (0);
}

int	replace_and_split(int *i, char *lst_str1, char **lst_str2, t_data *data)
{
	int		length;
	char	*env_name;
	char	*name_to_check;

	length = 1;
	env_name = NULL;
	name_to_check = NULL;
	if (lst_str1[1] == '?')
		return (is_ret_val(lst_str2, i));
	if (lst_str1[1] == '\0' || lst_str1[1] == '$')
		return (end_of_story(lst_str2));
	length = push_or_get_name_size(lst_str1, lst_str2);
	name_to_check = ft_substr(lst_str1, 1, length - 1);
	if (!name_to_check)
		return (1);
	env_name = ft_getenv(name_to_check, data);
	free(name_to_check);
	if (env_name)
	{
		if (expansion_split(&data->lst_token_temp,
				env_name, lst_str2, data) == 1)
			return (fail(lst_str2));
	}
	*i = *i + length - 1;
	return (0);
}
