/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halzamma <halzamma@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:47:15 by halzamma          #+#    #+#             */
/*   Updated: 2025/03/13 16:47:15 by halzamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	error(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*res;

	res = ft_strjoin(s1, s2);
	free(s1);
	return (res);
}

void	init_files(char *in_path, char *out_path, int *infile, int *outfile)
{
	*infile = open(in_path, O_RDONLY);
	if (*infile < 0)
		perror("infile");
	*outfile = open(out_path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (*outfile < 0)
		perror("outfile");
}

int	main(int argc, char **argv, char **envp)
{
	int	fd[2];
	int	infile;
	int	outfile;

	if (argc != 5)
	{
		write(2, "Usage: ./pipex infile cmd1 cmd2 outfile\n", 40);
		return (1);
	}
	init_files(argv[1], argv[4], &infile, &outfile);
	if (pipe(fd) == -1)
		error("pipe");
	create_child(argv[2], envp, fd, infile);
	create_parent(argv[3], envp, fd, outfile);
	close(fd[0]);
	close(fd[1]);
	close(infile);
	close(outfile);
	return (0);
}
