/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_simple.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:19:03 by alex              #+#    #+#             */
/*   Updated: 2024/12/29 21:15:56 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

int main(int argz, char **argv)
{
    int fd;
    pid_t pids;
    int   pipes[2];
    
    if (argz < 5)
        return (1);
    fd = open(argv[1], O_RDONLY, 7777);//importante dar permisos al abrir
    if (fd < 0)
        return (1);
    dup2(fd, STDIN_FILENO);
    pids = fork(void);
    
    
}