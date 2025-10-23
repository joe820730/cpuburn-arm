#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

extern void stress();

int main(int argc, char *argv[]) {
	int exit_status;
	int ncpus = sysconf(_SC_NPROCESSORS_ONLN);
	int nproc = 1;
	printf("[INFO]\t=== ARM NEON Stress test ===\n");

	if (argc == 1) {
		printf("[INFO]\tNumber of processes not specified. Using number of online processors (%d).\n", ncpus);
		printf("[INFO]\tYou can specify the number of processes with:\n%s [num_processes]\n\n\n", argv[0]);
		nproc = ncpus;
	} else {
		int tmp = atoi(argv[1]);
		if (tmp > ncpus) {
			printf("[WARN]\tSpecified number of processes (%d) exceeds number of online processors (%d), limits to online processors.\n", tmp, ncpus);
			nproc = ncpus;
		} else if (tmp < 1) {
			printf("[WARN]\tSpecified number of processes (%d) is less than 1, limits to 1.\n", tmp);
			nproc = 1;
		} else {
			nproc = tmp;
		}
	}

	if (nproc == -1) {
		fprintf(stderr, "[ERROR]\tFailed to get number of online processors.\n");
		exit(EXIT_FAILURE);
	}

	printf("[INFO]\tStarting %d processes...\n", nproc);
	if (nproc < 2) {
		goto end;
	}

	for (int i = 1; i < nproc; i++) {
		pid_t PID = fork();
		if (PID < 0) {
			perror("fork()");
			exit(EXIT_FAILURE);
		} else if (PID == 0) {
//			printf("[%d] [Child] Child's PID is %d\n", i, getpid());
			break;
		} else if (PID > 0) {
//			printf("[%d] [Parent] Parent's PID is %d\n", i, getpid());
		}
	}

end:
	printf("[INFO]\tProcess PID: %d\n", getpid());
	stress();
	return 0;
}
