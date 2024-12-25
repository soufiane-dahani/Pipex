/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sodahani <sodahani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 12:24:58 by sodahani          #+#    #+#             */
/*   Updated: 2024/12/25 15:43:02 by sodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "ft_printf.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

void	usage(void);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	here_doc(char *limiter, int argc);
void	child_process(char *argv, char **envp);
void	execute(char *argv, char **envp);
char	*find_path(char *cmd, char **envp);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
void	error(void);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
#endif