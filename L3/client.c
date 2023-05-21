#include <stdio.h>
#include <pthread.h>
#include <inttypes.h>
#include <errno.h>
#include <sys/neutrino.h>

int main(void)
{
	char smsg[] = "Nina";
	char rmsg[512];
	int coid;
	long serv_pid;
	printf("Prog client, enter sever's PID \n");
	
	scanf("%ld", &serv_pid);
	getchar();
	
	printf("Entered %ld \n", serv_pid);
	coid = ConnectAttach(0, serv_pid, 1, 0, 0);
	printf("Connect res %d \n", coid);
	
	if (MsgSend(coid, smsg, strlen(smsg)+1, rmsg, sizeof(rmsg)) == -1)
	{
		printf("Error MsgSend \n");
	}
	
	ConnectDetach(coid);
	return (1);
}
