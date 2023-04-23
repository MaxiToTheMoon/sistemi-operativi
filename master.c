#define _GNU_SOURCE
#include <sys/sem.h>
#include <errno.h>
#include <unistd.h>
#include <sys/msg.h>
#include <sys/shm.h>
#include <signal.h>
#include <math.h>
#include <float.h>
#include <time.h>
#include <sys/param.h>
#include "libs/utilities.h"

//qui dovrebbe essere num navi + num porti + n merci ecc
#define ERROR_MESSAGE(str) fprintf(stderr, "%s%s[Errore | pid: %d | file: %s | line: %d]\n-> %s\n-> [%d] %s\n%s\n", ANSI_COLOR_RESET, ANSI_COLOR_MAGENTA, getpid(), __FILE__, __LINE__, str, errno, strerror(errno), ANSI_COLOR_RESET)

#define SO_SIZE 100
#define SO_BANCHINE 4
#define SO_LATO 100
#define SO_SPID 50

int j = 1;
int pids[NUM_PORTI + NUM_NAVI];
int make_porti(int);
int make_navi(int);


int main(){
    int i;

    for (i = 0; i < NUM_PORTI + NUM_NAVI; i++) {
       
        if(i<NUM_PORTI){
            if (make_porti(i) < 0) {
                ERROR_MESSAGE("impossibile creare un processo porto");
            }
        }
        else if(i<NUM_NAVI + NUM_PORTI) {
            if (make_navi(i) < 0) {
                ERROR_MESSAGE("impossibile creare un processo nave");
            }
        }
        sleep(1);
    }
}
                
int make_porti(int i) {
    struct porto porto;
    pid_t child_porto;

    switch(child_porto = fork()) {

        case -1:
            return -1;
         
        case 0:
            srand(time(NULL));
            pids[i] = getpid();

            if(i == 0){
                printf("\nporto1");
                //porto
                struct merce m;
                struct merce m1 = creamerce(m);
                modificaporto(porto);
                porto.pidporto = getpid();
                porto.posizioneX = 0;
                porto.posizioneY = 0;
                porto.numerobanchine = rand() % SO_BANCHINE+1;
                printf("\n generato un PORTO con pid %d e posizione x %f  e posizione y %f\n", porto.pidporto, porto.posizioneX, porto.posizioneY); 
                printf("\n sono il porto e cerco questo tipo di merce = %s in queste quantita = %d \n e vendo = %s in queste quantita %d", porto.domanda.tipo, porto.domanda.quantita, porto.offerta.tipo, porto.offerta.quantita );
                printf ("\n ciao sono una merce \n di tipo  = %s \n la quantitta e = %d \n la datadiscadenza e = %d", m1.tipomerce, m1.quantitamerce, m1.datascadenza);

            } else if(i == 1){
                printf("\nporto2");
                //porto2
                struct merce m;
                struct merce m1 = creamerce(m);
                modificaporto(porto);
                porto.pidporto = getpid();
                porto.posizioneX = 0;
                porto.posizioneY = SO_LATO;
                porto.numerobanchine = rand() % SO_BANCHINE+1;
                printf("\n generato un PORTO con pid %d e posizione x %f  e posizione y %f\n", porto.pidporto, porto.posizioneX, porto.posizioneY); 
                printf("\n sono il porto e cerco questo tipo di merce = %s in queste quantita = %d\n e vendo = %s in queste quantita %d", porto.domanda.tipo, porto.domanda.quantita, porto.offerta.tipo, porto.offerta.quantita );
                printf ("\n ciao sono una merce \n di tipo  = %s\n la quantitta e = %d\n la datadiscadenza e = %d", m1.tipomerce, m1.quantitamerce, m1.datascadenza);

            }else if(i==2){
                printf("\nporto3");
                //
               struct merce m;
                struct merce m1 = creamerce(m);
                modificaporto(porto);
                porto.pidporto = getpid();
                porto.posizioneX = SO_LATO;
                porto.posizioneY = 0;
                porto.numerobanchine = rand() % SO_BANCHINE+1;
                printf("\n generato un PORTO con pid %d e posizione x %f  e posizione y %f\n", porto.pidporto, porto.posizioneX, porto.posizioneY); 
                printf("\n sono il porto e cerco questo tipo di merce = %s in queste quantita = %d \n e vendo = %s in queste quantita %d", porto.domanda.tipo, porto.domanda.quantita, porto.offerta.tipo, porto.offerta.quantita );
                printf ("\n ciao sono una merce \n di tipo  = %s \n la quantitta e = %d \n la datadiscadenza e = %d", m1.tipomerce, m1.quantitamerce, m1.datascadenza);

            }else if(i==3){
                //porto4
                printf("\nporto4");
                struct merce m;
                struct merce m1 = creamerce(m);
                modificaporto(porto);
                porto.pidporto = getpid();
                porto.posizioneX = SO_LATO;
                porto.posizioneY = SO_LATO;
                porto.numerobanchine = rand() % SO_BANCHINE+1;
                printf("\n generato un PORTO con pid %d e posizione x %f  e posizione y %f\n", porto.pidporto, porto.posizioneX, porto.posizioneY); 
                printf("\n sono il porto e cerco questo tipo di merce = %s in queste quantita = %d \n e vendo = %s in queste quantita %d", porto.domanda.tipo, porto.domanda.quantita, porto.offerta.tipo, porto.offerta.quantita );
                printf ("\n ciao sono una merce \n di tipo  = %s \n la quantitta e = %d \n la datadiscadenza e = %d", m1.tipomerce, m1.quantitamerce, m1.datascadenza);

            }else{
                printf("\nporto generato casualmente");
                struct merce m;
                struct merce m1 = creamerce(m);
                modificaporto(porto);
                porto.pidporto = getpid();
                porto.posizioneX =  ((float)rand() / (RAND_MAX)* SO_LATO);
                porto.posizioneY =  ((float)rand() / (RAND_MAX)* SO_LATO);
                porto.numerobanchine = rand() % SO_BANCHINE+1;
                printf("\n generato un PORTO con pid %d e posizione x %f  e posizione y %f\n", porto.pidporto, porto.posizioneX, porto.posizioneY); 
                printf("\n sono il porto e cerco questo tipo di merce = %s in queste quantita = %d \n e vendo = %s in queste quantita %d", porto.domanda.tipo, porto.domanda.quantita, porto.offerta.tipo, porto.offerta.quantita );
                printf ("\n ciao sono una merce \n di tipo  = %s \n la quantitta e = %d \n la datadiscadenza e = %d", m1.tipomerce, m1.quantitamerce, m1.datascadenza);
            }
            return 0;
        default:
            break;
    }
    return 0;
}

int make_navi(int i) {
    struct nave nave;
    pid_t child_nave;
    switch (child_nave = fork()){
        
    case -1: 
        return -1;

    case 0:
        srand(time(NULL));
        pids[i] = getpid();
        printf("\nnave generata casualmente , numero %d: ", j);
        nave.pidnave = getpid();
        nave.posizioneX =  ((float)rand() / (RAND_MAX)* SO_LATO);
        nave.posizioneY =  ((float)rand() / (RAND_MAX)* SO_LATO);
        printf(" \ngenerato una NAVE con pid %d e posizione x %f  e posizione y %f\n", nave.pidnave, nave.posizioneX, nave.posizioneY);   
        j++;
        break;
    default: 
        break;
    }
    return 0;
}
