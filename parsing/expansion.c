/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazanam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 14:47:13 by hrazanam          #+#    #+#             */
/*   Updated: 2022/02/05 14:52:19 by hrazanam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	replace_invisible(t_token *control)
{
	if (control->str[0] == '\0')
	{
		if (control->is_quote)
		{
			free_old_str(&control->str);
			control->str = NULL;
			control->str = ft_strdup_c(26);
			if (control->str == NULL)
				return (1);
		}
		else
		{
			free_old_str(&control->str);
			control->str = NULL;
			control->str = ft_strdup_c(25);
			if (control->str == NULL)
				return (1);
		}
	}
	return (0);
}

int	set_invisible_char(t_token *control)
{
	while (control->next != NULL)
	{
		if (replace_invisible(control))
			return (1);
		control = control->next;
	}
	if (control->str[0] == '\0')
	{
		if (replace_invisible(control))
			return (1);
	}
	return (0);
}

int	expansion(t_token **lst_token, t_data *data)
{
	t_token	*control;
	t_token	*control_after;

	control = *lst_token;
	while (control->next != NULL)
	{
		control_after = control->next;
		if (ft_strchr(control->str, '"')
			|| ft_strchr(control->str, '$')
			|| ft_strchr(control->str, '\''))
		{
			if (replace_str(control->str, control, data) == 1)
				return (1);
		}
		control = control_after;
	}
	if (replace_str(control->str, control, data) == 1)
		return (1);
	control = *lst_token;
	if (set_invisible_char(control))
		return (1);
	return (0);
}
