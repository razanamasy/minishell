/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tabs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrazanam <hrazanam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 09:12:59 by hrazanam          #+#    #+#             */
/*   Updated: 2022/02/06 09:15:22 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_tab_cmd_content(char ***tab_cmd, int size_tab)
{
	int	i;
	int	j;

	(void) size_tab;
	j = 0;
	i = 0;
	if (tab_cmd == NULL)
		return ;
	while (tab_cmd[i])
	{
		j = 0;
		while (tab_cmd[i][j] != NULL)
		{
			free(tab_cmd[i][j]);
			j++;
		}
		free(tab_cmd[i]);
		i++;
	}
}

void	free_tab_dir_content(t_token **tab_dir, int size_tab)
{
	int	i;

	(void)size_tab;
	i = 0;
	if (tab_dir == NULL)
		return ;
	while (tab_dir[i])
	{
		if (tab_dir[i] != NULL)
		{
			ft_lstclear(&tab_dir[i]);
		}
		i++;
	}
}

void	free_lst_token_content(t_token **lst_token)
{
	if (lst_token == NULL)
		return ;
	ft_lstclear(lst_token);
}
