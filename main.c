#include <string.h>
#include <stdio.h>

int main (int ac, char **av, char **envp)
{


	while (*envp)
	{
		if (!strncmp(*envp, "PATH=", 5) && *envp[6] != 0)
		{
			printf("path directory:\n%s \n ", *envp);
			return (0);
		}
		envp++;
	}
}