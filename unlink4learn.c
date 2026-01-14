#include <unistd.h>
#include <stdio.h>

int	main()
{
		if (unlink("example.txt") == 0)
				printf("File successfully deleted\n");
		else
				printf("Error deleting file\n");
		return (0);
}
