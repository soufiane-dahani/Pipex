/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sodahani <sodahani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:03:37 by sodahani          #+#    #+#             */
/*   Updated: 2024/12/06 19:27:20 by sodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "pipex.h"

char	**parse_and_validate_command(char *cmd)
{
	char	**cmd_args;

	cmd_args = ft_split(cmd, ' ');
	if (!cmd_args || !cmd_args[0])
	{
		perror("Invalid command");
		exit(1);
	}
	return (cmd_args);
}

void	cleanup_and_execute(t_fork_args *args, char **cmd_args)
{
	close(args->input_fd);
	close(args->output_fd);
	close(args->pipefd[0]);
	close(args->pipefd[1]);
	if (execvp(cmd_args[0], cmd_args) == -1)
	{
		perror("execvp failed");
		free(cmd_args);
		exit(1);
	}
}

void	fork_process(t_fork_args *args)
{
	pid_t	pid;
	char	**cmd_args;

	pid = fork();
	if (pid == -1)
	{
		perror("fork failed");
		exit(1);
	}
	if (pid == 0)
	{
		cmd_args = parse_and_validate_command(args->cmd);
		setup_redirections(args);
		cleanup_and_execute(args, cmd_args);
	}
}

void	initialize_files_and_pipe(char **av, int *fd1, int *fd2, int pipefd[2])
{
	*fd1 = open_file(av[1], O_RDONLY);
	if (*fd1 == -1)
		exit(1);
	*fd2 = open_file(av[4], O_WRONLY | O_CREAT | O_TRUNC);
	if (*fd2 == -1)
		exit(1);
	create_a_pipe(pipefd);
}

int	main(int argc, char **argv, char **envp)
{
	int			fd1;
	int			fd2;
	int			pipefd[2];
	t_fork_args	args1;
	t_fork_args	args2;

	validate_arguments(argc);
	initialize_files_and_pipe(argv, &fd1, &fd2, pipefd);
	args1 = (t_fork_args){.input_fd = fd1, .output_fd = -1,
		.pipefd = {pipefd[0], pipefd[1]}, .cmd = argv[2], .envp = envp,
		.is_first = 1};
	args2 = (t_fork_args){.input_fd = -1, .output_fd = fd2,
		.pipefd = {pipefd[0], pipefd[1]}, .cmd = argv[3], .envp = envp,
		.is_first = 0};
	fork_process(&args1);
	fork_process(&args2);
	handle_parent_process(fd1, fd2, pipefd);
	cleanup_and_exit(fd1, fd2, pipefd, 0);
	return (0);
}
