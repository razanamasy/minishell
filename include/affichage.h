/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 13:08:32 by lefendie          #+#    #+#             */
/*   Updated: 2022/02/04 13:10:31 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFFICHAGE_H
# define AFFICHAGE_H

# include "minishell.h"

void	affiche(t_token **lst_token);
void	affiche_tab_dir(t_token **tab_dir, t_token **lst_token);
void	affiche_tab_cmd(char ***tab_cmd, t_token **al_parse);

#endif
