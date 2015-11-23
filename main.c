/**
 *  \mainpage Projeto do Processador de Imagens
 *  \author Adelino Fernandes
 *  \date 2015
 *  \version Beta 
 *
 *  \file main.c
 *  \brief Arquivo principal
 *
 *  Created on 30 de Outubro de 2015, 10:09
 *
 */



#include "include/Projeto.h"//**Biblioteca para uso de struct e variáveis usadas no programa*/
#include "include/filtros.h"//**Biblioteca com os cabeçalho das funções*/
#include "include/menu.h"//**Biblioteca com menu do programa*/
#include "include/manipulacao.h"//**Biblioteca para gerar um novo arquivo de imagem*/
#include "include/funcoes.h"//**Biblioteca das funções de manipuladoras de imagens*/


/**
 *  \brief Método main onde é carregado o arquivo de imagem
 *  \param Nenhum
 *  \return EXIT_SUCCESS
 */


int main(int argc, char** argv) {
   


    printf("%s\n","Informe o nome do arquivo de imagem a ser aberto:");//**Abertura do arquivo da imagem*/
    scanf("%s",Nome_arquivo);
    reset();//**Função limpa tela*/
    
    FILE *arquivo;

    arquivo = fopen(Nome_arquivo, "r");//**Ler o arquivo*/

    if(arquivo == NULL){//**Faz o teste de erro na abertura do arquivo*/
        printf("%s\n","Erro ao abrir o arquivo de imagem.");
    }else{
        printf("%s\n","Arquivo de imagem aberto com sucesso."); 
    }

        fscanf(arquivo, "P3 %i %i 255",&largura, &altura);/**Ler os dados do cabeçalho*/
    
    if (largura > altura) {/**Comparação para ver o maior valor da matriz*/
        
        max = largura;
    }else{
        max = altura;
    }
    
    Pixel imagem[max][max];/**Cria uma variável do tipo struct*/
    

    //**Ler cada Pixel alocando na variável referente ao struct*/
    for (i = 0; i < altura; i++){
        for(j = 0; j < largura; j++){
            fscanf(arquivo, "%i %i %i", &imagem[i][j].r, &imagem[i][j].g, &imagem[i][j].b);
        }
    }
    //**fecha o arquivo*/
    fclose(arquivo);
    




    do{

        menu();//**Menu do programa sendo chamado*/

        printf("\nDigite o comando:>");
        scanf("%s",comando);//**Comando para leitura do menu*/
        reset();
   
        
        for(i=0;comando[i];i++)//**converte as letras para minusculo afim de facilitar a comparação*/
            comando[i]=tolower(comando[i]);
   
        
        
        if(strcmp(comando,"lap")==0){//**Chama o Filtro de laplace*/
            printf("\nExecutando o comando: %s\n", comando);
            laplace(imagem);
            printf("%s\n", "Informe o nome desejado para saída:");
            scanf("%s",arq);
            gerar_img(imagem, arq);
            printf("%s\n", "Imagem tratada com sucesso.");
            return (EXIT_SUCCESS);
            
        }else if(strcmp(comando,"gau")==0){//**Chama o filtro de gaus*/
            printf("\nExecutando o comando: %s\n", comando);
            gaussiano(imagem);
            printf("%s\n", "Informe o nome desejado para saída:");
            scanf("%s",arq);
            gerar_img(imagem, arq);
            printf("%s\n", "Imagem tratada com sucesso.");
            return (EXIT_SUCCESS);
            
        }else if(strcmp(comando,"blu")==0){//**Chama o filtro Blurring*/
            printf("\nExecutando o comando: %s\n", comando);
            passa_baixa(imagem);
            printf("%s\n", "Informe o nome desejado para saída:");
            scanf("%s",arq);
            gerar_img(imagem, arq);
            printf("%s\n", "Imagem tratada com sucesso.");
            return (EXIT_SUCCESS);
            
        }else if(strcmp(comando,"sha")==0){//**Chama o filtro sharpening*/
            printf("\nExecutando o comando: %s\n", comando);
            passa_alta(imagem);
            printf("%s\n", "Informe o nome desejado para saída:");
            scanf("%s",arq);
            gerar_img(imagem, arq);
            printf("%s\n", "Imagem tratada com sucesso.");
            return (EXIT_SUCCESS);
            
        }else if(strcmp(comando,"amp")==0){//**Chama a função para ampliação da imagem*/
           printf("\nExecutando o comando: %s\n", comando);
           
           printf("\nInforme o zoom desejado:\n");
           scanf("%i",&zoom);
           
           
           printf("%s\n", "Informe o nome desejado para saída:");
           scanf("%s",arq);
                ampliar_img(strcat(arq,".ppm"),zoom,imagem);
            
           printf("%s\n", "Imagem ampliada com sucesso.");
            return (EXIT_SUCCESS);
            
        }else if(strcmp(comando,"red")==0){//**Chama a função para redução da imagem*/
           printf("\nExecutando o comando: %s\n", comando);
           
           printf("\nInforme o zoom desejado:\n");
           scanf("%i",&zoom);
           
           
           printf("%s\n", "Informe o nome desejado para saída:");
           scanf("%s",arq);
                reduzir_img(strcat(arq,".ppm"),zoom,imagem);
            
           printf("%s\n", "Imagem reduzida com sucesso.");
            return (EXIT_SUCCESS);
            
        }else if(strcmp(comando,"rel")==0){//**Chama o filtro para aplicar o relevo na imagem*/
            printf("\nExecutando o comando: %s\n", comando);
            relevo(imagem);
            printf("%s\n", "Informe o nome desejado para saída:");
            scanf("%s",arq);
            gerar_img(imagem, arq);
            printf("%s\n", "Imagem tratada com sucesso.");
            return (EXIT_SUCCESS);
            
        }else if(strcmp(comando,"thr")==0){//**Chama o filtro da binarização*/
            printf("\nExecutando o comando: %s\n", comando);
            printf("\nInforme o valor do thresholding:\n");
                scanf("%i",&thr);
                binarization(imagem, thr);
            printf("%s\n", "Informe o nome desejado para saída:");
                scanf("%s",arq);
                gerar_img(imagem, arq);
            printf("%s\n", "Imagem binarizada com sucesso.");
            return (EXIT_SUCCESS);

        }else if(strcmp(comando,"gra")==0){//**Chama o filtro para grayscale*/
            printf("\nExecutando o comando: %s\n", comando);
                grayscale(imagem);
            printf("%s\n", "Informe o nome desejado para saída:");
                scanf("%s",arq);
                gerar_img(imagem, arq);
            printf("%s\n", "Imagem tratada com sucesso.");
            return (EXIT_SUCCESS);
            
        }else if(strcmp(comando,"inv")==0){//**Chama o filtro para inverter as cores*/
            printf("\nExecutando o comando: %s\n", comando);
                inverter(imagem);
            printf("%s\n", "Informe o nome desejado para saída:");
                scanf("%s",arq);
                gerar_img(imagem, arq);
            printf("%s\n", "Imagem tratada com sucesso.");
            return (EXIT_SUCCESS);

        }else if(strcmp(comando,"esp")==0){//**Chama a função para espelhar a imagem*/
            printf("\nExecutando o comando: %s\n", comando);
                espelhar(imagem);
            printf("%s\n", "Informe o nome desejado para saída:");
                scanf("%s",arq);
                gerar_img(imagem, arq);
            printf("%s\n", "Imagem espelhada com sucesso.");
            return (EXIT_SUCCESS);

        }else if(strcmp(comando,"rot")==0){//**Chama a função para rotacionar a imagem*/
            printf("%s\n", "Informe o ângulo desejado desejado (90, 180, 270):");

		scanf("%i",&angulo);//**Detalha o ângulo de rotação*/
			
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

    return (EXIT_SUCCESS);//**Finaliza o programa*/
}
