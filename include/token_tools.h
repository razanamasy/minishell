/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_tools.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 13:09:09 by lefendie          #+#    #+#             */
/*   Updated: 2022/02/04 13:12:50 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_TOOLS_H
# define TOKEN_TOOLS_H

# include "minishell.h"

t_token	*get_next_token_as(t_token *cmd_dir, int type);
t_token	*get_last_token_as(t_token *lst_token, int type1, int type2);
int		get_redir_count(t_token *redir_list, int type);

#endif
