/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halzamma <halzamma@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:29:44 by halzamma          #+#    #+#             */
/*   Updated: 2025/03/13 15:29:44 by halzamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	create_child(char *cmd, char **envp, int *fd, int infile)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		error("fork");
	if (pid == 0)
		child_process(cmd, envp, fd, infile);
}

void	create_parent(char *cmd, char **envp, int *fd, int outfile)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		error("fork");
	if (pid == 0)
		parent_process(cmd, envp, fd, outfile);
}

void	child_process(char *cmd, char **envp, int *fd, int infile)
{
	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	dup2(infile, STDIN_FILENO);
	close(fd[1]);
	execute(cmd, envp);
}

void	parent_process(char *cmd, char **envp, int *fd, int outfile)
{
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(fd[0]);
	execute(cmd, envp);
}
