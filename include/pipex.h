/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halzamma <halzamma@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:11:35 by halzamma          #+#    #+#             */
/*   Updated: 2025/03/12 14:11:35 by halzamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "libft.h"
# include "ft_printf.h"

char	*find_path(char *cmd, char **envp);
char	*get_path_env(char **envp);
char	*check_executable(char **paths, char *cmd);
void	error(char *msg);
char	*ft_strjoin_free(char *s1, char *s2);
void	child_process(char *cmd, char **envp, int *fd, int infile);
void	parent_process(char *cmd, char **envp, int *fd, int infile);
void	execute(char *cmd, char **envp);
void	create_child(char *cmd, char **envp, int *fd, int infile);
void	create_parent(char *cmd, char **envp, int *fd, int outfile);

#endif
