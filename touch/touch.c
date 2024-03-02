#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

/**
 * main - Testing point.
 * @argc: Argument count.
 * @argv: Argument vector.
 *
 * Return: # 0 (on Success).
 *         # 1 otherwise.
 */

int main(int argc, char **argv)
{
	(void) argc;
	int fd;
	char *usage = "Usage: ./touch <file_name>...\n";

	if (argc < 2)
	{
		printf("%s", usage);
		return (1);
	}

	while (*++argv)
	{
		if ((fd = open(*argv, O_CREAT, 0600)) == -1)
			printf("./touch: cannot create file '%s'\n", *argv);
		else
		{
			printf("./touch: created file '%s'\n", *argv);
			close(fd);
		}
	}

	return (0);
}
