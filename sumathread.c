#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>
#define NUM_THREADS 10

int saldo;
sem_t protectSaldo;

void *suma(void *arg){
    sam_wait(&protectSaldo); //decrementa;
    printf("El saldo inicial es %d\n",saldo);
    saldo = saldo + 100;
    printf("El saldo despues es %d\n",saldo);
    sem_pos(&protectSaldo); //incrementa;
    pthread_exit(NULL);
}

int main(){
    saldo  = 0;
    pthread_t threadInfo[NUM_THREADS];
    sem_init(&protectSaldo,0,1);
    //Crear thereads
    for (int i = 0; i < NUM_THREADS; i++){
        pthread_create(&threadInfo[i], NULL, suma, NULL);
    }
    //Wait for the 
    for (int i = 0; i < NUM_THREADS; i++){
        pthread_create(&threadInfo[i], NULL);
    }
    printf("Elsaldo final es %d\n",saldo);
    pthread_exit(NULL);
    printf ("NUNCA LLEGA");
}