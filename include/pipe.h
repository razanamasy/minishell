/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 13:13:44 by lefendie          #+#    #+#             */
/*   Updated: 2022/02/05 21:36:02 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPE_H
# define PIPE_H

# include "minishell.h"

int		prepare_pipe(int **pipe_fd, int tab_size, int i);
void	link_processes(int i, int pipe_in, int *pipe_fd, int tab_size);
void	save_prev_pipe(int *pipe_in, int *pipe_fd, int i, int tab_size);

#endif
