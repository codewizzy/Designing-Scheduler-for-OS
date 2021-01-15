# Designing-Scheduler-for-OS

make qemu SCHEDFLAG=FRR
make qemu SCHEDFLAG=MLQ

if simply make qemu will be typed then by default xv6 DEFAULT scheduler will run.

* FRR - First come first serve based round robin
To schedule processes fairly, a round-robin scheduler generally employs time-sharing, giving each job a time slot or quantum (its allowance of CPU time), and interrupting the job if it is not completed by then. 
The job is resumed next time a time slot is assigned to that process. 
If the process terminates or changes its state to waiting during its attributed time quantum, the scheduler selects the first process in the ready queue to execute. 
In the absence of time-sharing, or if the quanta were large relative to the sizes of the jobs, a process that produced large jobs would be favoured over other processes.
Round-robin scheduling is simple, easy to implement, and starvation-free.
$ make qemu SCHEDFLAG=FRR

* MLQ - Multilevel queue scheduling

The multilevel queue scheduling (MLQ) represents a preemptive policy that includes a three priority queues (priority can asusme three values: 0,1,2). 
The initial process should be initiated at priority 2and the priority should be copied upon fork. 
In this scheduling policy the scheduler will select a process from a lower queue only if no process is ready to run at a higher queue.
The algorithm first runs all the process with highest priority and then, when they finish, it will consider all the process with a lower priority.
Moving between priority queues is only available via a system call.
This algorithm is very similar to PRIORITY, but in this case we have only three queues (low, medium, high) and the user must select foreach process which queue the process belongs to (default -> 1: medium)
Priority range in this algorithm is 0-2 (default is 1) where we give priority equals to 1 for the processes which we want to be completed first.
The following system call will change the priority queue of the process with a specific pid process:
int chpr(int pid, int priority)
In this case ```priority``` is a number between 0 and 2 which represents the new process priority.
To enable it and see how MLQ works use this command when compiling xv6:
$ make qemu SCHEDFLAG=MLQ

