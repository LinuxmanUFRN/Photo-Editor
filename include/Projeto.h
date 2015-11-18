/* 
 * File:   main.c
 * Author: adelinofernandes
 *
 * Created on 30 de Outubro de 2015, 10:09
 */

#ifndef Projeto_h
#define Projeto_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>




#define Max_nome 256 /*Tamanho do Nome do arquivo*/




int altura, largura;
int g,h,i,j; //Para percorrer as matrizes no for...
char Nome_arquivo[100];
char arq[100];
char comando[256];
int angulo;
int zoom;
int max;
int thr; // valor thresholding

 typedef struct {
    int r;
    int g;
    int b;
} color;
typedef color Pixel;


/*
 * Limpa Tela
 */


void reset() {

    
#if defined WIN32
    system("cls");
#else
    system("clear");
#endif
}

/*Limpa o buffer do teclado http://pt.stackoverflow.com/questions/9427/limpeza-do-buffer-do-teclado-após-scanf*/
void flush_in(){
    int ch;
    while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){}
}


#endif /* Projeto_h */
