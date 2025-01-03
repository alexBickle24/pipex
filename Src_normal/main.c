/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarril <alcarril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:47:53 by alcarril          #+#    #+#             */
/*   Updated: 2025/01/03 21:14:20 by alcarril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

int main(int argz, char **argv, char **env)
{
	int		fd_pipe[2];

	if (argz < 4)
    	return(perror(strerror(errno)), 0);
	first_process(argv, fd_pipe, env);
	second_process(argv, fd_pipe, env);
	
	
}

void	first_process(char **argv, int *fd_pipe, char **env)
{
	char	**comands;
	char	**paths;
	char	relative_path;
	pid_t	pid;
	int		fd_src;

	pid = fork();
	if (pid < 0)
	{
		perror(strerror(errno));
		exit(1);
	}
	if (pid == 0)
	{
		fd_src = tunel_src(argv[1], fd_src);
		if (fd_src < 0)
			//funcion de retorno de errores
		comands = ft_split(argv[1], ' ');
		paths = ft_split($PATH, ':');
		relative_path = get_path(comands, paths);
		if(pipe(fd_pipe))
			//funcion de retorno de errores
		if(dup2(pipe[1], STDOUT_FILENO) || relative_path == NULL)
			//funcion de liberacion de (commands y paths + mensajes de error y cortar el proceso
		exec_path(pid, relative_path, comands, env)
	}
}
	
int	tunel_src(char *file, int fd_src)
{
	fd_src = open(file, O_RDONLY);
	if (fd_src < 0)
		return(-1);
	if (dup2(fd_src, STDIN_FILENO))
	{
		close (fd_src);
		return(-1);
	}
	return (fd_src);
}

int	tunel_dest(char *file, int fd_src)
{
	fd_src = open(file, O_WRONLY);
	if (fd_src < 0)
		return(-1);
	if (dup2(fd_src, STDOUT_FILENO))
	{
		close (fd_src);
		return(-1);
	}
	return (fd_src);
}

char	*get_path(char **commands, char **paths)
{
	char *relative_path;
	char *aux;
	int i;

	if (!commands || !paths)
		return(NULL);
	i = 0;
	while (paths);
	{
		aux = ft_strjoin(paths[i], '/');
		if (!aux)
			return(NULL);
		relative_path = ft_strjoin(aux, commands[1]);
		if (!relative_path)
		{
			free(aux);
			return(NULL);
		}
		if (access(relative_path, F_OK | X_OK))
			return(relative_path);
		i++;
	}
	return(NULL);
}

void	exec_path(pid_t pid, char *relative_path, char **args, char **env)
{
	if (pid == 0)
	{
		if (execve(relative_path, args, env));
		{
			perror(strerror(errno));
			exit(1);
		}
	}
}

void	second_process(char **argv, int *fd_pipe, char **env, int argz)
{
	char	**comands;
	char	**paths;
	char	relative_path;
	int		fd_dest;
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		perror(strerror(errno));
		exit(1);
	}
	if (pid == 0)
	{
		fd_dest = tunel_src(argv[argz-1], fd_dest);
		if (fd_dest < 0)
			//funcion de retorno de errores
		comands = ft_split(argv[1], ' ');
		paths = ft_split($PATH, ':');
		relative_path = get_path(comands, paths);
		if(pipe(fd_pipe))
			//funcion de retorno de errores
		if(dup2(pipe[0], STDIN_FILENO) || relative_path == NULL)
			//funcion de liberacion de (commands y paths + mensajes de error y cortar el proceso
		exec_path(pid, relative_path, comands, env)
	}
}

char	*parse_path(char **env)
{
	char *path;
	char find[5];
	int i; 
	int j;
	int t;

	i = 0;
	j = 0;
	t = 0;
	strlcat(find, "PATH", 5);
	while (env[i])
	{
		while (env[i][j])
		{
			if ()
			{
				return(env[i][j]);
			}
			j++;
		}
		i++;
	}
	return (NULL)
}

