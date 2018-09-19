/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggroener <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/06 09:50:21 by ggroener          #+#    #+#             */
/*   Updated: 2016/08/06 10:36:49 by ggroener         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libgen.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

void read_all(int src, int dst) 
{
	char buf[BUFSIZ];
	ssize_t bytes_read, bytes_written;
	while ((bytes_read = read(src, buf, BUFSIZ)) > 0)
	{
		bytes_written = 0;
		while (bytes_written < bytes_read)
			bytes_written += write(dst,	buf + bytes_written,
					bytes_read - bytes_written);
	}
}

int main(int argc, char** argv)
{
	if (argc < 2)
	{
		printf("usage: %s <program> [<arg> ...]\n", basename(argv[0]));
		return EXIT_FAILURE;
	}
	/* create pipes for standard input, output, and error */
	int stdin_pipe[2];
	int stdout_pipe[2];
	int stderr_pipe[2];
	pipe(stdin_pipe);
	pipe(stdout_pipe);
	pipe(stderr_pipe);
	if (fork() == 0)
	{
		/* child process */
		/* close write end of stdin and read ends of stdout and stderr */
		close(stdin_pipe[1]);
		close(stdout_pipe[0]);
		close(stderr_pipe[0]);
		/* change child's stdin, stdout, and stderr to use pipes */
		dup2(stdin_pipe[0], STDIN_FILENO);
		dup2(stdout_pipe[1], STDOUT_FILENO);
		dup2(stderr_pipe[1], STDERR_FILENO);
		/* exec the given program */
		if (execvp(argv[1], argv+1) == -1)
		{
			perror("failed to start subprocess");
			return EXIT_FAILURE;
		}
	}
	/* parent process */
	/* close read end of stdin and write ends of stdout and stderr */
	close(stdin_pipe[0]);
	close(stdout_pipe[1]);
	close(stderr_pipe[1]);
	/* pass input to the child process */
	read_all(STDIN_FILENO, stdin_pipe[1]);
	close(stdin_pipe[1]);
	/* wait for child to finish */
	wait(NULL);
	/* read child's stdout and stderr */
	puts("\nchild's stdout:");
	fflush(stdout);
	read_all(stdout_pipe[0], STDOUT_FILENO);
	close(stdout_pipe[0]);
	puts("\nchild's stderr:");
	fflush(stdout);
	read_all(stderr_pipe[0], STDOUT_FILENO);
	close(stderr_pipe[0]);
	return EXIT_SUCCESS;
}
