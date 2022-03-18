/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <lefendie.student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 10:50:03 by lefendie          #+#    #+#             */
/*   Updated: 2022/02/10 10:44:58 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

long long	ft_atoll(const char *str, int *error)
{
	long long	string_to_ll;
	long long	temp;
	int			sign;

	sign = 1;
	string_to_ll = 0;
	while (*str && (*str == 32 || (*str > 8 && *str < 14)))
		str++;
	if (*str && (*str == '-' || *str == '+'))
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	if (ft_strncmp(str, "9223372036854775808", 20) == 0)
		return (-9223372036854775807 - 1);
	while ((*str >= '0' && *str <= '9') && *str && *error != -1)
	{
		temp = string_to_ll;
		string_to_ll = string_to_ll * 10 + (*str - 48);
		str++;
		if (string_to_ll < temp)
			*error = -1;
	}
	return (string_to_ll * sign);
}

int	check_numeric_arg(t_data *data, char **cmd_arg, int verbose)
{
	char	*cmd_first_arg;

	cmd_first_arg = ft_strdup(cmd_arg[1]);
	if (!cmd_first_arg)
		return (1);
	if (verbose)
		err_with_msg_info(": numeric argument required", cmd_first_arg);
	if (is_simple_cmd(data))
	{
		free_execution_child(data);
		exit(2);
	}
	return (2);
}

int	check_too_many_arg(char **cmd_arg, int verbose)
{
	char	*cmd;

	cmd = ft_strdup(cmd_arg[0]);
	if (!cmd)
		return (1);
	if (verbose)
		err_with_msg_info(": too many arguments", cmd);
	return (1);
}

int	exit_err_check(t_data *data, char **cmd_arg, int verbose, int error)
{
	if (is_simple_cmd(data) && verbose)
		write(1, "exit\n", 6);
	if (list_size((void **)cmd_arg) > 2 && is_str_numeric(cmd_arg[1]))
		return (check_too_many_arg(cmd_arg, verbose));
	if (!is_str_numeric(cmd_arg[1]) || error == -1)
		return (check_numeric_arg(data, cmd_arg, verbose));
	return (0);
}

int	b_exit(t_data *data, char **cmd, int verbose)
{	
	long long	exit_val;
	int			error;
	int			temp;
	int			is_with_arg;

	error = 0;
	exit_val = 0;
	is_with_arg = 0;
	if (cmd[1])
		is_with_arg = 1;
	if (is_with_arg)
		exit_val = ft_atoll(cmd[1], &error);
	temp = exit_err_check(data, cmd, verbose, error);
	if (temp == 1 || temp == 2)
		return (temp);
	if (is_simple_cmd(data))
	{
		free_execution_child(data);
		if (is_with_arg)
			exit(exit_val);
		exit(g_ret_val);
	}
	return (exit_val);
}
