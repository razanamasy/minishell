/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_not_set.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazanam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 14:46:17 by hrazanam          #+#    #+#             */
/*   Updated: 2022/02/06 09:55:34 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	is_after_redir(enum e_flag type)
{
	if (type == FILE_OUT || type == FILE_IN || type == COND || type == FILE_EOF)
		return (1);
	return (0);
}

int	create_new_lst(t_token *control, t_token **new_lst_token, char *temp)
{
	if (!(ft_strncmp(control->str, temp, 1)))
	{
		if (is_after_redir(control->type))
		{
			if (lst_push_cpy(control, new_lst_token))
				return (1);
		}
	}
	else
	{
		if (lst_push_cpy(control, new_lst_token))
			return (1);
	}
	return (0);
}

int	delete_not_set(t_token **lst_token)
{
	t_token	*control;
	t_token	*new_lst_token;
	char	*temp;
	char	*_null;

	_null = ft_strdup("\0");
	if (!_null)
		return (1);
	temp = ft_strjoin_c(_null, 25);
	if (!temp)
		return (1);
	new_lst_token = NULL;
	control = *lst_token;
	while (control->next != NULL)
	{
		if (create_new_lst(control, &new_lst_token, temp))
			return (1);
		control = control->next;
	}
	if (create_new_lst(control, &new_lst_token, temp))
		return (1);
	free_lst_token_content(lst_token);
	*lst_token = new_lst_token;
	free(temp);
	return (0);
}
