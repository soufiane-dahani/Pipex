/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sodahani <sodahani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:03:40 by sodahani          #+#    #+#             */
/*   Updated: 2024/12/08 11:26:08 by sodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "ft_printf.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_fork_args
{
	int		input_fd;
	int		output_fd;
	int		pipefd[2];
	char	*cmd;
	char	**envp;
	int		is_first;
}			t_fork_args;

void		validate_arguments(int argc);
void		initialize_files_and_pipe(char **av, int *fd1, int *fd2,
				int pipefd[2]);
int			open_file(const char *s, int p);
void		create_a_pipe(int pipefd[2]);
void		cleanup_and_exit(int fd1, int fd2, int pipefd[2], int status);
void		setup_redirections(t_fork_args *args);
void		setup_first_command_redirections(t_fork_args *args);
void		setup_second_command_redirections(t_fork_args *args);
void		fork_process(t_fork_args *args);
void		handle_parent_process(int fd1, int fd2, int pipefd[2]);
void		close_parent_fds(int fd1, int fd2, int pipefd[2]);
void		wait_for_children(int num_children);
char		**parse_and_validate_command(char *cmd);
void		cleanup_and_execute(t_fork_args *args, char **cmd_args);
char		**ft_split(char const *s, char c);
char		*ft_strcat(char *dest, char *src);
size_t		ft_strlen(const char *str);

#endif