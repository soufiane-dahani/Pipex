/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sodahani <sodahani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:03:37 by sodahani          #+#    #+#             */
/*   Updated: 2024/12/05 15:31:07 by sodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"
#include "ft_printf.h"

int open_file(const char *s, int p)
{
    int fd;
    fd = open(s, p, 0644);
    if (fd < 0)
    {
        perror("error open file");
        return(-1);
    }
    return (fd);
}
void create_a_pipe(int pipefd[2])
{
    if (pipe(pipefd) == -1)
    {
        perror("pipe failed");
        exit(1);
    }    
}
void fork_process(int input_fd, int output_fd, int pipefd[2], char *cmd, char **envp, int is_first)
{
    pid_t pid = fork();
    if (pid == -1)
    {
        perror("fork failed");
        exit(1);
    }

    if (pid == 0)
    {
        if (is_first)
        {
            
            if (dup2(input_fd, STDIN_FILENO) == -1)
            {
                perror("dup2 file1 to stdin failed");
                exit(1);
            }

            
            if (dup2(pipefd[1], STDOUT_FILENO) == -1)
            {
                perror("dup2 pipe write to stdout failed");
                exit(1);
            }
        }
        else
        {
        
            if (dup2(pipefd[0], STDIN_FILENO) == -1)
            {
                perror("dup2 pipe read to stdin failed");
                exit(1);
            }
            if (dup2(output_fd, STDOUT_FILENO) == -1)
            {
                perror("dup2 file2 to stdout failed");
                exit(1);
            }
        }

        close(input_fd);
        close(output_fd);
        close(pipefd[0]);
        close(pipefd[1]); 
        
        
        char *args[] = {cmd, NULL};
        if (execve(cmd, args, envp) == -1)
        {
            perror("execve failed");
            exit(1);
        }
    }
}

void handle_parent_process(int fd1, int fd2, int pipefd[2])
{
    close(fd1);
    close(fd2);
    close(pipefd[0]);
    close(pipefd[1]);
    int status;
    pid_t pid;
    int i = 0;
    while (i < 2)
    {
        pid = wait(&status);
        if (pid == -1)
        {
            perror("wait failed");
            exit(1);
        }
        if (WIFEXITED(status))
        {
            int  exit_status = WEXITSTATUS(status);
            printf("Child process with PID %d exited with status %d\n", pid, exit_status);
        }
        else
            printf("Child process with PID %d did not exit normally\n", pid);
        i++;
    }
    
}

void cleanup_and_exit(int fd1, int fd2, int pipefd[2], int status)
{
    close(fd1);
    close(fd2);
    close(pipefd[0]);
    close(pipefd[1]);

    // Exit with the appropriate status
    exit(status);
}
int main (int ac, char **av, char **envp)
{
    int fd1, fd2 , pipefd[2];
    if (ac != 5)
    {
        ft_printf("Usage: ./pipex file1 cmd1 cmd2 file2\n");
        exit(1);
    }
    fd1 = open_file(av[1], O_RDONLY); 
    if (fd1 == -1)
        exit(1);
    fd2 = open_file(av[4], O_WRONLY | O_CREAT | O_TRUNC);
    if (fd2 == -1)
        exit(1);
    create_a_pipe(pipefd);
   fork_process(fd1, -1, pipefd, av[2], envp, 1);
   fork_process(-1, fd2, pipefd, av[3], envp, 0);
   handle_parent_process(fd1, fd2, pipefd);
   cleanup_and_exit(fd1, fd2, pipefd, 0);
   return(0);
}