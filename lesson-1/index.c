#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>

#define NUM_THREADS 5

// Criando uma STRUCT
struct dados_para_thread{
	int thread_id;
	int thread_rn;
};

void *print_hello(void *threadid){
    struct dados_para_thread *dadosthread;
    dadosthread= (struct dados_para_thread *)threadid;
    printf("No principal: criando a thread - id: #%d\t Random Number: %d\n\n", dadosthread->thread_id,dadosthread->thread_rn);//In main: creating thread
    //printf("Hello World! It's me, thread #%ld!\n", tid);
    pthread_exit((void *)NULL);
};


int main(int argc, char *argv[]){
    system("cls||clear");
    pthread_t threads[NUM_THREADS];
    struct dados_para_thread dados_para_thread_array[NUM_THREADS];
    
    int error_code;
    long t,res;

    for(t = 0;t < NUM_THREADS; t++){
        dados_para_thread_array[t].thread_id = t;
    	dados_para_thread_array[t].thread_rn = rand() % 100; 
        error_code = pthread_create(&threads[t], NULL,
                                    print_hello, (void *) &dados_para_thread_array[t]);
        
        if (error_code){
            printf("ERROR; return code from pthread_create() is %d\n", error_code);
            exit(-1);
        };
      res=pthread_join(threads[t], NULL);
    };

    //printf("id: %d\n", res);    
    printf("Hello World! Sou eu, a thread #%ld!\n", res);    
    pthread_exit(NULL);
};
