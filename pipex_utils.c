/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sodahani <sodahani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:53:02 by sodahani          #+#    #+#             */
/*   Updated: 2024/12/06 12:46:55 by sodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "pipex.h"

int	open_file(const char *s, int p)
{
	int	fd;

	fd = open(s, p, 0644);
	if (fd < 0)
	{
		perror("error opening file");
		return (-1);
	}
	return (fd);
}

void	create_a_pipe(int pipefd[2])
{
	if (pipe(pipefd) == -1)
	{
		perror("pipe failed");
		exit(1);
	}
}

void	cleanup_and_exit(int fd1, int fd2, int pipefd[2], int status)
{
	close(fd1);
	close(fd2);
	close(pipefd[0]);
	close(pipefd[1]);
	exit(status);
}

void	setup_first_command_redirections(t_fork_args *args)
{
	if (dup2(args->input_fd, STDIN_FILENO) == -1)
	{
		perror("dup2 file1 to stdin failed");
		exit(1);
	}
	if (dup2(args->pipefd[1], STDOUT_FILENO) == -1)
	{
		perror("dup2 pipe write to stdout failed");
		exit(1);
	}
}

void	setup_second_command_redirections(t_fork_args *args)
{
	if (dup2(args->pipefd[0], STDIN_FILENO) == -1)
	{
		perror("dup2 pipe read to stdin failed");
		exit(1);
	}
	if (dup2(args->output_fd, STDOUT_FILENO) == -1)
	{
		perror("dup2 file2 to stdout failed");
		exit(1);
	}
}
