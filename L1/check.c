#include <stdio.h>
#include <string.h>

int main(void)
{
	char buf[100];
	char truename[] = "Sviridova Nina I992";
	while (gets(buf))
	{
		if (strcmp(truename, buf) == 0)
		{
			printf("Name is correct \n");
			return 0;
		}
		else
		{
			printf("Name is incorrect \n");
			return 1;
		}
	}
}
