#include "listaCentros.h"
#include <stdio.h>
#include <stdlib.h>

int listarCentros( ListaCentros lc){
    int centroId;
    for (int i = 0; i< lc.numeroCentros; i++){
        printf("%d -> %s \n", lc.listaCentros[i].centroID, lc.listaCentros[i].nomeCentro);
    }
    scanf("%d", &centroId);

    //falta controlar se a opcao inserida
    return centroId;
}   

void adicionarCentro( ListaCentros *lc){
    CentroVacinacao c = criarCentro(lc->numeroCentros);
    lc->listaCentros[lc->numeroCentros++] = c;
}

void carregarDadosListaCentros(ListaCentros *lc){
    FILE *file;
    file = fopen("listaCentros.dat", "rb");

    if(file == NULL) return;

    fread(lc, sizeof(ListaCentros), 1, file);

    fclose(file);
}

void gravarDadosListaTurmas(ListaCentros lc) {
    FILE * file = fopen("listaCentros.dat", "wb");
    rewind(file);
    fwrite(&lc, sizeof(ListaCentros), 1, file);
    fclose(file);
}

void getCentroById(int centroID, ListaCentros lc){
    for(int i = 0; i < lc.numeroCentros; i++ ){
        if(lc.listaCentros[i].centroID == centroID) {
            printf("Código : %d\n", lc.listaCentros[i].codigoCentro);
            printf("Nome : %s\n", lc.listaCentros[i].nomeCentro);
            printf("Morada : %s\n", lc.listaCentros[i].morada);
        }
    }
}

void menuCentro()
{
    ListaCentros lc;
    lc.numeroCentros = 0;
    int opcao;

    printf("#########################################\n");
    printf("#------------MENU DE CENTROS------------#\n");
    printf("#########################################\n");
    printf("#\t 1 - CRIAR CENTRO               #\n");
    printf("#\t 2 - EDITAR CENTRO              #\n");
    printf("#\t 3 - INATIVAR CENTRO            #\n");
    printf("#\t 0 - SAIR                       #\n");
    printf("#########################################\n");
    printf(">\t Digite a sua opção -> ");
    scanf("%d", &opcao);
    system("clear");

    switch (opcao)
    {
    case 1:
        adicionarCentro(&lc);
        break;
    case 2:
        //editarVacina();
        break;
    case 3:
        //inativarVacina();
        break;
    case 0:
        break;
    default:
        printf("Opção inválida!");
        break;
    }
}