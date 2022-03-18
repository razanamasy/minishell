/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 14:48:27 by lefendie          #+#    #+#             */
/*   Updated: 2022/02/09 19:15:03 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ignore_sigquit(void)
{
	struct sigaction	sigquit_act;

	ft_memset(&sigquit_act, '\0', sizeof(sigquit_act));
	sigquit_act.sa_handler = SIG_IGN;
	sigquit_act.sa_flags = SA_NODEFER;
	sigaction(SIGQUIT, &sigquit_act, NULL);
}

void	custom_sigquit(void)
{
	struct sigaction	sigquit_act;

	ft_memset(&sigquit_act, '\0', sizeof(sigquit_act));
	sigquit_act.sa_handler = SIG_DFL;
	sigquit_act.sa_flags = SA_NODEFER;
	sigaction(SIGQUIT, &sigquit_act, NULL);
}

void	custom_sigint(void)
{
	struct sigaction	sigint_act;

	ft_memset(&sigint_act, '\0', sizeof(sigint_act));
	sigint_act.sa_flags = SA_NODEFER;
	sigint_act.sa_handler = sigint_handler_readline;
	sigaction(SIGINT, &sigint_act, NULL);
}

void	default_sigint(void)
{
	struct sigaction	sigint_act;

	ft_memset(&sigint_act, '\0', sizeof(sigint_act));
	sigint_act.sa_flags = SA_NODEFER;
	sigint_act.sa_handler = SIG_DFL;
	sigaction(SIGINT, &sigint_act, NULL);
}

void	ignore_sigint(void)
{
	struct sigaction	sigint_act;

	ft_memset(&sigint_act, '\0', sizeof(sigint_act));
	sigint_act.sa_flags = SA_NODEFER;
	sigint_act.sa_handler = SIG_IGN;
	sigaction(SIGINT, &sigint_act, NULL);
}
