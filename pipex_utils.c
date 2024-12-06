/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sodahani <sodahani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:53:02 by sodahani          #+#    #+#             */
/*   Updated: 2024/12/06 11:57:28 by sodahani         ###   ########.fr       */
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
		perror("error open file");
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
