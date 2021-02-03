
#include <unistd.h> // getopt

#include "load_latency.h"
#include "store_buffer.h"
#include "load_buffer.h"
#include "reorder.h"

static u32 g_iteration;

int main(int argc, char **argv)
{
    //init_global_variable();

	g_iteration = 1;

    char* usage = "[-T <test number>]\n";
    int c;
	int test = 0;

    while (( c = getopt(argc, argv, "T:")) != EOF) {
        switch(c) {
        case 'T':
          	test = atoi(optarg);
            break;
        default:
            printf("%s\n", usage);
            break;
        }
    }

	printf("[ Test Started ]\n");

	if (test == 1)
		cache_latency_bench();
	else if (test == 2) 
		load_latency();
	else
		printf("%s\n", usage);

    printf("[ Test Finished ]\n");

    return 0;
}
