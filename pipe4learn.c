#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	main()
{
		int	fd[2];
		pid_t	pid;
		char	buffer[13];

		if (pipe(fd) == -1)
		{
				perror("pipe");
				exit(EXIT_FAILURE);
		}
		pid = fork();
		if (pid == -1)
		{
				perror("fork");
				exit(EXIT_FAILURE);
		}
		if (pid == 0)
		{
				close(fd[0]);
				write(fd[1], "Hello parent!", 13);
				close(fd[1]);
				exit(EXIT_SUCCESS);
		}
		else
		{
			close(fd[1]);
			read(fd[0], buffer, 13);
			close(fd[0]);
			printf("Message from child: '%s'\n", buffer);
			exit(EXIT_SUCCESS);
		}
}
