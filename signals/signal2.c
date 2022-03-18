/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 01:37:11 by lefendie          #+#    #+#             */
/*   Updated: 2022/02/09 01:39:37 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	custom_sigint_heredoc(void)
{
	struct sigaction	sigint_act;

	ft_memset(&sigint_act, '\0', sizeof(sigint_act));
	sigint_act.sa_flags = SA_NODEFER;
	sigint_act.sa_handler = sigint_handler_here_doc;
	sigaction(SIGINT, &sigint_act, NULL);
}
