/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 13:15:24 by lefendie          #+#    #+#             */
/*   Updated: 2022/02/05 21:35:52 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "minishell.h"

char	**cpy_env(char **env);
char	*ft_getenv(char *key, t_data *data);
char	*ft_getenv_env(char *key, t_data *data);
int		get_env_size(char **env);

#endif
