/*
 * File:   main.c
 * Author: adelinofernandes
 * Created on 30 de Outubro de 2015, 10:09
 */



#ifndef filtros_h
#define filtros_h
void grayscale(Pixel imagem[altura][largura]);
void binarization(Pixel imagem[altura][largura], int thr);
void inverter(Pixel imagem[altura][largura]);
void espelhar(Pixel imagem[altura][largura]);
void rotacionar_esq(Pixel imagem[max][max]);
void rotacionar_180(Pixel imagem[altura][largura]);
void rotacionar_270(Pixel imagem[altura][largura]);
void relevo(Pixel imagem[altura][largura]);
void ampliar_img(char arquivo[], int zoom,Pixel imagem[altura][largura]);
void reduzir_img(char arquivo[], int zoom,Pixel imagem[altura][largura]);
void passa_alta(Pixel imagem[altura][largura]);
void passa_baixa(Pixel imagem[altura][largura]);
void gaussiano(Pixel imagem[altura][largura]);
void laplace(Pixel imagem[altura][largura]);

#endif /* filtros_h */
