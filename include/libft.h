/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:41:06 by lefendie          #+#    #+#             */
/*   Updated: 2022/02/09 16:21:43 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "minishell.h"

const char	*ft_skip(const char *str, const char sep);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);

t_token		*ft_lstnew(char *str);
t_token		*ft_lstnewcpy(t_token *to_cpy);
void		*ft_memset(void *s, int c, size_t n);
char		*ft_strsufx(char *sufx, char *str);
void		*ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
char		**ft_split_(char *s, char c);
char		*ft_strdup(char *str);
char		*ft_strdup_c(char c);
char		*ft_strjoin_c(char *s1, char c);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_substr(char *s,
				unsigned int start, size_t len);
char		*ft_strchr(char *s, int c);
void		free_old_str(char **lst_str);
void		ft_lstdelone(t_token *token);
void		ft_lstclear(t_token **lst);
void		ft_lstclear_dir(t_token **lst);
void		ft_lstadd_back(t_token **alst, t_token *new);

int			ft_strlen(char *s);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_list_size(const char *str, const char sep, char ***result);
int			ft_word_size(const char *str, const char sep);
int			isstr_equal(char *str1, char *str2);
int			isstr_start_equal(char *str1, char *str2);
int			list_size(void **list);
int			ft_access(char *path);

#endif
