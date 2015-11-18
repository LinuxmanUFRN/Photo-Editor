/*
 * File:   main.c
 * Author: adelinofernandes
 *
 * Created on 30 de Outubro de 2015, 10:09
 */



#include "include/Projeto.h"
#include "include/filtros.h"
#include "include/menu.h"
#include "include/manipulacao.h"
#include "include/funcoes.h"





/*
 *Lembrar de alocar dinamicamente... pode dar erro em imagens muito grandes....
 */



int main(int argc, char** argv) {
   


    printf("%s\n","Informe o nome do arquivo de imagem a ser aberto:");
    scanf("%s",Nome_arquivo);
    reset();
    
    FILE *arquivo;

    arquivo = fopen(Nome_arquivo, "r");

    if(arquivo == NULL){
        printf("%s\n","Erro ao abrir o arquivo de imagem.");
    }else{
        printf("%s\n","Arquivo de imagem aberto com sucesso."); 
    }

        fscanf(arquivo, "P3 %i %i 255",&largura, &altura);
    
    if (largura > altura) {
        
        max = largura;
    }else{
        max = altura;
    }
    
Pixel imagem[max][max];
    

    // Ler cada Pixel alocando na variável referente ao struct
    for (i = 0; i < altura; i++){
        for(j = 0; j < largura; j++){
            fscanf(arquivo, "%i %i %i", &imagem[i][j].r, &imagem[i][j].g, &imagem[i][j].b);
        }
    }
    // fecha o arquivo
    fclose(arquivo);
    




    do{

        menu();

        printf("\nDigite o comando:>");
        scanf("%s",comando);
        reset();
   
        //converte para minusculo para facilitar a comparação.
        for(i=0;comando[i];i++)
            comando[i]=tolower(comando[i]);
   
        
        
        if(strcmp(comando,"lap")==0){
            printf("\nExecutando o comando: %s\n", comando);
            laplace(imagem);
            printf("%s\n", "Informe o nome desejado para saída:");
            scanf("%s",arq);
            gerar_img(imagem, arq);
            printf("%s\n", "Imagem tratada com sucesso.");
            return (EXIT_SUCCESS);
            
        }else if(strcmp(comando,"gau")==0){
            printf("\nExecutando o comando: %s\n", comando);
            gaussiano(imagem);
            printf("%s\n", "Informe o nome desejado para saída:");
            scanf("%s",arq);
            gerar_img(imagem, arq);
            printf("%s\n", "Imagem tratada com sucesso.");
            return (EXIT_SUCCESS);
            
        }else if(strcmp(comando,"blu")==0){
            printf("\nExecutando o comando: %s\n", comando);
            passa_baixa(imagem);
            printf("%s\n", "Informe o nome desejado para saída:");
            scanf("%s",arq);
            gerar_img(imagem, arq);
            printf("%s\n", "Imagem tratada com sucesso.");
            return (EXIT_SUCCESS);
            
        }else if(strcmp(comando,"sha")==0){
            printf("\nExecutando o comando: %s\n", comando);
            passa_alta(imagem);
            printf("%s\n", "Informe o nome desejado para saída:");
            scanf("%s",arq);
            gerar_img(imagem, arq);
            printf("%s\n", "Imagem tratada com sucesso.");
            return (EXIT_SUCCESS);
            
        }else if(strcmp(comando,"amp")==0){
           printf("\nExecutando o comando: %s\n", comando);
           
           printf("\nInforme o zoom desejado:\n");
           scanf("%i",&zoom);
           
           
           printf("%s\n", "Informe o nome desejado para saída:");
           scanf("%s",arq);
                ampliar_img(strcat(arq,".ppm"),zoom,imagem);
            
           printf("%s\n", "Imagem ampliada com sucesso.");
            return (EXIT_SUCCESS);
            
        }else if(strcmp(comando,"red")==0){
           printf("\nExecutando o comando: %s\n", comando);
           
           printf("\nInforme o zoom desejado:\n");
           scanf("%i",&zoom);
           
           
           printf("%s\n", "Informe o nome desejado para saída:");
           scanf("%s",arq);
                reduzir_img(strcat(arq,".ppm"),zoom,imagem);
            
           printf("%s\n", "Imagem reduzida com sucesso.");
            return (EXIT_SUCCESS);
            
        }else if(strcmp(comando,"rel")==0){
            printf("\nExecutando o comando: %s\n", comando);
            relevo(imagem);
            printf("%s\n", "Informe o nome desejado para saída:");
            scanf("%s",arq);
            gerar_img(imagem, arq);
            printf("%s\n", "Imagem tratada com sucesso.");
            return (EXIT_SUCCESS);
            
        }else if(strcmp(comando,"thr")==0){
            printf("\nExecutando o comando: %s\n", comando);
            printf("\nInforme o valor do thresholding:\n");
                scanf("%i",&thr);
                binarization(imagem, thr);
            printf("%s\n", "Informe o nome desejado para saída:");
                scanf("%s",arq);
                gerar_img(imagem, arq);
            printf("%s\n", "Imagem binarizada com sucesso.");
            return (EXIT_SUCCESS);

        }else if(strcmp(comando,"gra")==0){
            printf("\nExecutando o comando: %s\n", comando);
                grayscale(imagem);
            printf("%s\n", "Informe o nome desejado para saída:");
                scanf("%s",arq);
                gerar_img(imagem, arq);
            printf("%s\n", "Imagem tratada com sucesso.");
            return (EXIT_SUCCESS);
            
        }else if(strcmp(comando,"inv")==0){
            printf("\nExecutando o comando: %s\n", comando);
                inverter(imagem);
            printf("%s\n", "Informe o nome desejado para saída:");
                scanf("%s",arq);
                gerar_img(imagem, arq);
            printf("%s\n", "Imagem tratada com sucesso.");
            return (EXIT_SUCCESS);

        }else if(strcmp(comando,"esp")==0){
            printf("\nExecutando o comando: %s\n", comando);
                espelhar(imagem);
            printf("%s\n", "Informe o nome desejado para saída:");
                scanf("%s",arq);
                gerar_img(imagem, arq);
            printf("%s\n", "Imagem espelhada com sucesso.");
            return (EXIT_SUCCESS);

        }else if(strcmp(comando,"rot")==0){
            printf("%s\n", "Informe o ângulo desejado desejado (90, 180, 270):");

		scanf("%i",&angulo);
			
		if(angulo == 90){
			printf("\nExecutando o comando: %s\n", comando);
				rotacionar_esq(imagem);
			printf("%s\n", "Informe o nome desejado para saída:");
				scanf("%s",arq);
			gerar_img(imagem, arq);
				printf("%s\n", "Imagem rotacionada com sucesso.");
           	return (EXIT_SUCCESS);
		}else if(angulo == 180){
			printf("\nExecutando o comando: %s\n", comando);
				rotacionar_180(imagem);
			printf("%s\n", "Informe o nome desejado para saída:");
				scanf("%s",arq);
			gerar_img(imagem, arq);
				printf("%s\n", "Imagem rotacionada com sucesso.");
           	return (EXIT_SUCCESS);
		
		}else if(angulo == 270){
			printf("\nExecutando o comando: %s\n", comando);
				rotacionar_270(imagem);
			printf("%s\n", "Informe o nome desejado para saída:");
				scanf("%s",arq);
			gerar_img(imagem, arq);
				printf("%s\n", "Imagem rotacionada com sucesso.");
           	return (EXIT_SUCCESS);
		}
        }else{
            reset();
            printf("\nComando desconhecido: %s\n",comando);
            
        }    

    }while(strcmp(comando,"exit")!=0);



        printf("%s\n", "Programa finalizado");

    return (EXIT_SUCCESS);
}
