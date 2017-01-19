#include <unistd.h>
#include <stdio.h>
int main()
{
	int fd[2];
	pipe(fd);

	if(fork() > 0)
	{
		//parent
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		printf("ls");
		return 0;
	}
	else
	{
		close(STDIN_FILENO);
		dup(fd[0]);
		close(fd[1]);
		char str[3];
		gets(str);
		printf("%s from child.\n", str);
		return 0;
	}
}
