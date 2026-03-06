#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char **argv, char **envp)
{
		char **cmd;
		char **cmd2;
		pid_t pid1;
		pid_t pid2;
		char path[] = "/bin/ls";
		int	fd[2];
		int oldfd;
		int oldfdout;

		if (argc ==  5)
		{
				if (pipe(fd) == -1)
						return (1);
				pid1 = fork();
				if (pid1 == -1)
						return (1);
				if (pid1 == 0)
				{
						oldfd = open(argv[1], O_RDONLY);
						if (oldfd == -1)
								return (1);
						dup2(oldfd, 0);
						dup2(fd[1], 1);
						close(fd[1]);
						close(oldfd);
						close(fd[0]);
						cmd = ft_split(argv[2], ' ');
						execve(path, cmd, envp);
				}
				pid2 = fork();
				if (pid2 == 0)
				{
						oldfdout = open(argv[4], O_WRONLY| O_CREAT | O_TRUNC, 0644);
						if (oldfdout == -1)
								return (1);
						dup2(oldfdout, 1);
						dup2(fd[0], 0);
						close(fd[1]);
						close(oldfdout);
						close(fd[0]);
						cmd2 = ft_split(argv[3], ' ');
						execve(path, cmd2, envp);
				}
				close(fd[0]);
				close(fd[1]);
				waitpid(pid1, NULL, 0);
				waitpid(pid2, NULL, 0);
		}
}
