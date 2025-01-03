/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarril <alcarril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 03:03:27 by alex              #+#    #+#             */
/*   Updated: 2025/01/03 16:32:51 by alcarril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	tunel_src(char *file, int fd_src)
{
	if (access(file, F_OK | R_OK))
	{
		return(perror(strerror(errno), -1));
	}
	fd_src = open(file, O_RDONLY);
	if (fd_src < 0)
		return(perror(strerror(errno), -1));
	if (dup2(fd_src, STDIN_FILENO))
	{
		close (fd_src);
		return(perror(strerror(errno), -1));
	}
	return (fd_src);
}

void	link_process(char **argz, int fd_src, pid_t pid, int *pipe_fd)
{
	static int 	counter;

	if (pipe(pipe_fd))
	{
		close(fd_src);
		return(perror(strerror(errno)));
	}
	if (counter > 0)
	{
		pipe_process();
		counter++;
	}
	else
	{
		first_process(int fd_src, int *pipe_fd, int fd_src);
		close (fd_src);
		counter++;
	}
}

void	pipe_process(pid_t pid, int *pipe_fd, char **argv, int counter)
{
	char	**comands;
	char	**paths;
	
	pid = fork(void);
	if (pid < 0)
	{
		perror(strerror(errno));
		exit(1);
	}
	if (pid == 0)
	{
		
	}
}

void	first_process(int fd_src, int *pipe_fd, char **argv, int counter)
{
	char	**comands;
	char	**paths;

	pid = fork(void);
	if (pid < 0)
	{
		perror(strerror(errno));
		exit(1);
	}
	if (pid == 0)
	{
		comands = ft_split(argv[counter + 1], ' ');
		paths = ft_split(argv[counter +1 ], ':');
		if(dup2(fd, fd2) || (comands || paths) == NULL)
			//funcion de liberacion(comands, path);
		while ()
		
		//hace el bucle de los comandos de la primera fila de commands y cada una de las filas del path 
		//si execve falla en todos los casos posibles hacer un control de errores con exit que liberar la memoria dinamica y local
	}
	else 
	{
		//hacer el waitpid o wait
		//¿control de errores de la salida del porceso hijo (porque no es necesario)?
		//salir de la funcion
	}
}

int	redirect(ind fd, int fd2)
{
	if(dup2(fd, fd2) || (commands || path) == NULL)
	{
		perror(strerror(erno));
		return (1);
	}
	return(0);
}
