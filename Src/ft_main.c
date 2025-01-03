/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcarril <alcarril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 18:52:14 by alex              #+#    #+#             */
/*   Updated: 2025/01/03 17:11:12 by alcarril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

int main(int argz, char **argv)
{
    //declarara ciones algunas se podran hacer dentro de otras funciones si aqui gfaltan lineas
    int fd_src;
    pid_t pid;
    int pipe_fd[2];
	int begin;
    
	
	begin = 1;
    if (argz < 4)
    {
    	return(perror(strerror(errno), 0));
    }
	fd_src = tunel_src(argv[1], fd_src);
	if (fd_src < 0)
		return(perror(strerror(errno), 0));
	while (begin < (argv))
	{
		link_process(argz, fd_src, pid, pipe_fd);
		begin++;
	}
	
    //////////////////////////todo esto en un bucle que se vaya moviendo entre los comandos y segun una variable (para poder hacer el heredoc)//////////////////////////////////////
    pid = fork(void);
    if (pid < 0)
    {
        perror(strerror(errno));///como se definen los errores de errno menos en el caso de execve que ya lo se 
        return (0);
    }
    if (pid = 0)
    {
        char *comand;
        char *find_command;
        
        if ((dup2(pipe_fd[0], STDOUT_FILENO)))
        {
           perror(strerro(errno));
           return (0); 
        }
        //hacer el split de los argumento (vale el normal)
        comand = ft_split(argv(2), ' ');
        if (!comand)
        {
            perror(strerror(errno));
            return(0);
        }
        //aqui habria que hacer un acces del archivo que contiene eñ ejecutable del comando o no hace falta porque lo hace execve
        find_command = ft_strjoin("/bin/", argv[1]);
        if (!find_command)
        {
            perror(strerror(errno));
            //funcion de liberacion de comand
            return (0);
        }
        if (execve(find_command, comand, NULL));
        {
            perror(strerror(errno));
            //funcion de livearacion de comand 
            free(comand);
            exit(errno);
        }
    }
    else 
    {   
        //manejar los casos de caso de error en exit 
        int status;
        wait(&status);
        /////volver a iterar en el bucle
    }
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    close (src_fd);
    
    //hacer funcion de salida desde el padre reconducir al ultimo argv y ejecutar execve con control de errores y salida del porgrama, en caso de error liberar memria 
}