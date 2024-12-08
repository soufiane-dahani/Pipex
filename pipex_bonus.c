/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sodahani <sodahani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 12:21:27 by sodahani          #+#    #+#             */
/*   Updated: 2024/12/08 16:22:29 by sodahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pipex_bonus.h"
# include "ft_printf.h"
# include "get_next_line.h"

int initialize_file(char *s, int *fd)
{
    int pipefd[2];
	*fd = open_file(s, O_RDONLY);
	if (*fd == -1)
		exit(1);
	if (pipe(pipefd) == -1)
	{
		perror("pipe failed");
		exit(1);
	}
    return(*fd);
}
// void	validate_arguments(char **av)
// {
//     if (ft_strncmp(av[1] , "here_doc", ft_strlen(av[1])) != 0)
//     {
//         if (ft_strncmp(av[1] , ".here_doc", ft_strlen(av[1])) != 0)
//         {
//             /* code */
//         }
        
//     }
    
// }

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
void handle_file_morocco(int *fdm, int ac, char **av)
{
    int i;
    *fdm = open("morocco", O_RDWR | O_CREAT | O_TRUNC, 0644);
    if (*fdm < 0)
	{
		perror("error opening file");
		exit(1);
	}
    i = 1;
    while (i < ac)
    {
        write(*fdm, av[i], strlen(av[i])); // change strlen
        write(*fdm, "\n", 1);
        i++;
    }
}
void handle_line(int *fdm, int *fd)
{
    char *line;
    fdm = open("morocco", O_RDONLY);
    while (((line = get_next_line(fdm)) != NULL))
    {
        initialize_file(line, fd);
        free(line);
    }
}
int	main(int argc, char **argv, char **envp)
{
    int fd;
    int fdm;
    handle_file_morocco(&fdm, argc, argv);
    // initialize_files(argv, &fd1, &fd2, pipefd);
    // validate_arguments(argv);
    void handle_line(fdm,fd);    
    return 0;
}
