#ifndef __TIME_BENCH__
#define __TIME_BENCH__
#include <sys/time.h>   // for gettimeofday()


struct bench {
	struct timeval start, end;
};

typedef struct bench bench;

bench *start_bench(){
	bench* b = (bench*)malloc(sizeof(bench));
	gettimeofday(&b->start, NULL);
	return b;
}

void end_bench(bench* b,const char *prefix){
	gettimeofday(&b->end, NULL);
	long seconds = (b->end.tv_sec - b->start.tv_sec);
	long micros = ((seconds * 1000000) + b->end.tv_usec) - (b->start.tv_usec);
	double secs = micros/1000000.0; 
	printf("%s%f\n", prefix, 1000*secs);
	free(b);
}


#endif
