/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 13:06:52 by lefendie          #+#    #+#             */
/*   Updated: 2022/02/09 01:40:34 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECTION_H
# define REDIRECTION_H

# include "minishell.h"

void	try_opening_file(t_data *data, char *file, int option, int mode);
int		choose_redir_in(t_token *redir_in, int **hc_cmd, t_data *data, int i);
int		choose_redir_out(t_data *data, t_token *redir_out);
int		open_option(t_token *redir_out);

#endif
