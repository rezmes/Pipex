#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	main()
{
		pid_t pid;

		pid = fork();

	if (pid == -1)
	{
			perror("fork");
			exit(EXIT_FAILURE);
	}
	
	if(pid == 0)
			printf("This is the child process. (pid: %d)\n", getpid());
	else
			printf("This is the parent process. (pid: %d)\n", getpid());
	return (0);
}
