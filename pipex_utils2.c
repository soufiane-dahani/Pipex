/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sodahani <sodahani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 12:49:15 by sodahani          #+#    #+#             */
/*   Updated: 2024/12/06 17:18:51 by sodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "pipex.h"

void	setup_redirections(t_fork_args *args)
{
	if (args->is_first)
		setup_first_command_redirections(args);
	else
		setup_second_command_redirections(args);
}

void	close_parent_fds(int fd1, int fd2, int pipefd[2])
{
	close(fd1);
	close(fd2);
	close(pipefd[0]);
	close(pipefd[1]);
}

void	handle_child_exit_status(pid_t pid, int status)
{
	int	exit_status;

	if (WIFEXITED(status))
	{
		exit_status = WEXITSTATUS(status);
		ft_printf("Child process with PID %d exited with status %d\n", pid,
			exit_status);
	}
	else
	{
		ft_printf("Child process with PID %d did not exit normally\n", pid);
	}
}

void	wait_for_children(int num_children)
{
	int		status;
	pid_t	pid;
	int		i;

	i = 0;
	while (i < num_children)
	{
		pid = wait(&status);
		if (pid == -1)
		{
			perror("wait failed");
			exit(1);
		}
		handle_child_exit_status(pid, status);
		i++;
	}
}

void	handle_parent_process(int fd1, int fd2, int pipefd[2])
{
	close_parent_fds(fd1, fd2, pipefd);
	wait_for_children(2);
}
