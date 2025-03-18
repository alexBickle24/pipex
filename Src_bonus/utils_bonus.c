/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 22:55:05 by alex              #+#    #+#             */
/*   Updated: 2025/03/18 09:23:32 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*check_exe(char *x_file)
{
	char	**absolute_paths_table;
	char	*absolute_paths;
	char	*path;

	absolute_paths = get_env_value("PATH");
	if (!absolute_paths)
	{
		if (access(x_file, F_OK | X_OK))
			return (x_file);
		return (NULL);
	}
	absolute_paths_table = ft_split(absolute_paths, ':');
	if (!absolute_paths)
		return (NULL);
	path = find_exe_file(absolute_paths_table, x_file);
	if (!path)
	{
		if (access(x_file, F_OK | X_OK) != -1)
			return (x_file);
		return (ft_free_table(absolute_paths_table), NULL);
	}
	ft_free_table(absolute_paths_table);
	return (path);
}

char	*get_env_value(const char *key_value)
{
	int		i;
	size_t	key_len;
	char	*new_value;

	if (!key_value)
		return (NULL);
	key_len = ft_strlen(key_value);
	if (key_len == 0 || g_env == NULL)
		return (NULL);
	new_value = ft_strjoin(key_value, "=");
	if (new_value == NULL)
		return (NULL);
	i = 0;
	while (g_env[i] != NULL)
	{
		if ((ft_strncmp(new_value, g_env[i], key_len + 1)) == 0)
		{
			free(new_value);
			return ((g_env[i] + key_len + 1));
		}
		i++;
	}
	free(new_value);
	return (NULL);
}

char	*find_exe_file(char **posible_paths, char *x_file)
{
	char	*relative_path;
	char	*aux;
	int		i;

	if (!posible_paths || !x_file)
		return (NULL);
	i = 0;
	while (posible_paths[i])
	{
		aux = ft_strjoin(posible_paths[i], "/");
		if (!aux)
			return (NULL);
		relative_path = ft_strjoin(aux, x_file);
		if (!relative_path)
		{
			free(aux);
			return (NULL);
		}
		if (access(relative_path, F_OK | X_OK) != -1)
			return (free(aux), relative_path);
		i++;
		free(aux);
		free(relative_path);
	}
	return (NULL);
}

void	ft_error(char **table1, char **table2, char *str1, char *str2)
{
	if (table1)
		ft_free_table(table1);
	if (table2)
		ft_free_table(table2);
	if (str1)
	{
		free(str1);
		str1 = NULL;
	}
	if (str2)
	{
		free(str2);
		str2 = NULL;
	}
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	perror(strerror(errno));
	close(STDERR_FILENO);
	exit(1);
}

void	ft_free_table(char **ptr)
{
	int	i;

	if (ptr == NULL)
		return ;
	i = 0;
	while (ptr[i] != NULL)
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}
