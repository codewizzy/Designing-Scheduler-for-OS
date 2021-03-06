#include"types.h"
#include"fcntl.h"
#include"user.h"
#include"stat.h"

int main(int argc ,char* argv[])
{
	int priority,pid;
	if(argc<3)
	{
		printf(2,"usage set_priority pid priority\n");
		exit();
	}
	pid=atoi(argv[1]);

	
	priority=atoi(argv[2]);


	if(priority>2||priority<0)
	{
		printf(2,"Invalid priority (0,1,2)!\n");
		exit();
	}
	chpr(pid,priority);
	exit();
}
