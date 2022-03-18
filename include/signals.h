/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 13:14:14 by lefendie          #+#    #+#             */
/*   Updated: 2022/02/07 11:03:09 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

# include "minishell.h"

void	sigint_handler_readline(int signum);
void	sigquit_handler(int signum);
void	ignore_sigquit(void);
void	custom_sigquit(void);
void	custom_sigint(void);
void	here_doc_sigquit(void);
void	default_sigint(void);
void	ignore_sigint(void);
void	sigint_handler_here_doc(int signum);
void	custom_sigint_heredoc(void);

#endif
