#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h> 
#include <stdbool.h>

#define TEST_ERROR    if (errno) {fprintf(stderr, \
             "%s:%d: PID=%5d: Error %d (%s)\n",\
             FILE,\
             LINE,\
             getpid(),\
             errno,\
             strerror(errno));}

#ifndef MYLIB_H
#define MYLIB_H
                
#define SO_SIZE 100
#define SO_MIN_VITA 1
#define SO_MAX_VITA 5
#define SO_BANCHINE 4
#define NUM_PORTI 12
#define NUM_NAVI 8
#define NUM_PROC 20

#define PROCESS_INFO_STATE_RUNNING 1
#define PROCESS_INFO_STATE_TERMINATED 0
#define PROCESS_INFO_TYPE_NAVI 1
#define PROCESS_INFO_TYPE_PORTI 0

#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_RESET   "\x1b[0m"

int SO_FILL = 1000;

struct SO_MERCI{
    int quantita_Merce;
    int tempo_Vita;
};

struct nave{
    pid_t pidnave;
    double SO_SPEED;
    double posizioneX;
    double posizioneY;
    int SO_CAPACITY;
};

struct domandaporto {
    char* tipo;
    int quantita;
};

struct offertaporto {
    char* tipo;
    int quantita;
};

struct porto{
    pid_t pidporto;
    double posizioneX;
    double posizioneY;
    int numerobanchine;
    struct domandaporto domanda;
    struct offertaporto offerta;

};

    




struct merce{
    char *tipomerce;
    int quantitamerce;
    int datascadenza;
    pid_t sonoinquestoporto;
    pid_t sonoinquestanave;
    bool consegnata;
    bool scadutaporto;
    bool scadutanave;


};

 struct merce creamerce (struct merce m) {
    char *mercitypes[] = {"primotipo", "secondotipo", "terzotipo", "quartotipo", "quintitipo", "cinquetipo"};
    const size_t n = sizeof(mercitypes) / sizeof(mercitypes[0]);
    srand(time(NULL));
    int randomIndex = rand() % n;
    m.tipomerce = mercitypes[randomIndex];
    m.quantitamerce = rand () % SO_SIZE + 1 ;
    m.datascadenza = rand () % (SO_MAX_VITA - SO_MIN_VITA + 1) + SO_MIN_VITA;
  

    return m;
}


struct porto modificaporto (struct porto porto){

    char *mercitypes[] = {"primotipo", "secondotipo", "terzotipo", "quartotipo", "quintitipo", "cinquetipo"};
    const size_t n = sizeof(mercitypes) / sizeof(mercitypes[0]);
    srand(time(NULL));
    int randomIndex = rand() % n;
    porto.domanda.tipo = mercitypes[randomIndex];

    if (SO_FILL > 0 ) {
            porto.domanda.quantita = rand () % SO_FILL;
             SO_FILL = SO_FILL - porto.domanda.quantita;
    } else {
                printf("ehi hai raggiunto la capacità massima");

    }

    porto.offerta.tipo = mercitypes[randomIndex];
        if (porto.domanda.tipo == porto.offerta.tipo) {
                    if(  mercitypes[randomIndex-1] != NULL) {
                                    porto.offerta.tipo = mercitypes[randomIndex-1] ;
         }else {
                                    porto.offerta.tipo = mercitypes[randomIndex+1] ;
                                }
                            }

    if (SO_FILL > 0 ) {
        porto.offerta.quantita = rand () % SO_FILL;
         SO_FILL = SO_FILL - porto.offerta.quantita;
    } else {
        printf("ehi hai raggiunto la capacità massima");
    }
   
    return porto;
}
#endif 