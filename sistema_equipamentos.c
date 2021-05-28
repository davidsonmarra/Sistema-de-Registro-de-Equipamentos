#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

//! SISTEMA PARA CADASTRO DE EQUIPAMENTOS

struct Equipamento {
    int codigo;
    char nome[100];
    float preco;
};
struct Equipamento lista[MAX];
int n;

/*
* Descricao: procedimento que cadastra os equipamentos
* Entradas:  nada
* Saida: vetor de struct Equipamento preenchido e numero de quipamentos cadastrados
*/
void cadastra(){
    printf("\nQuantos equipamentos voce deseja cadastrar (o maximo sao %d):\t", MAX);
    do{
        scanf("%d",&n); fflush(stdin);
        if (n > MAX)
            printf("Voce que cadastrar mais equipamento que o maximo disponivel de %d equipamentos. Tente novamente com um numero menor.\n", MAX);
    }while(n > MAX);
    for(int i = 0; i < n; i++){ // preenche o vetor
        printf("\nEQUIPAMENTO %d:\n", i+1);
        printf("Codigo:\t");
        scanf("%d", &lista[i].codigo); fflush(stdin);
        printf("Nome:\t");
        gets(lista[i].nome); fflush(stdin);
        printf("Preco:\t");
        scanf("%f", &lista[i].preco); fflush(stdin);
    }
}

/*
* Descricao: procedimento que lista os equipamentos
* Entradas:  nada
* Saida: mostra na tela os equipamentos cadastrados
*/
void listaEquipamentos(){
    printf("\nOs equipamentos cadastrados sao:\n\n");
    for(int i = 0; i < n; i++){
        printf("EQUIPAMENTO %d\n", i+1);
        printf("Codigo: %d | Nome: %s | Preco: R$%.2f\n\n", lista[i].codigo, lista[i].nome, lista[i].preco);
    }
}

/*
* Descricao: procedimento que calcula o preco medio dos equipamentos e retorna por referencia
* Entradas: endereco do preco medio
* Saida: preco medio passado por referencia e mostra ele na tela
*/
void calcPrecoMedio(float * media){
    float aux = 0;
    for(int i = 0; i < n; i++)
        aux += lista[i].preco; 
    * media = aux / n;
    printf("\nA media de preco dos equipamentos eh de: R$%.2f\n", * media);
}

/*
* Descricao: procedimento que mostra os equipamentos que custam menos que o valor digitado pelo usuario
* Entradas: nada
* Saida: equipamentos que custam menos que o valor entrado pelo usuario
*/
void mostraAbaixo(){
    int cont =  0;
    float abaixo;
    printf("Listar valores abaixo de:\t");
    scanf("%f", &abaixo); fflush(stdin);
    printf("Os equipamentos que custam menos de R$%.2f sao:\n\n", abaixo);
    for(int i = 0; i < n; i++)
        if(lista[i].preco <= abaixo){
           printf("Codigo: %d | Nome: %s | Preco: R$%.2f\n", lista[i].codigo, lista[i].nome, lista[i].preco);
           cont++;
        }
    if(cont == 0)
        printf("\nNao ha equipamentos mais barato que o valor que R$%.2f.\n",abaixo);
    else 
        printf("\nHa %d equipamentos mais barato do que o R$%.2f.\n", cont, abaixo);
}

/*
* Descricao: procedimento que salva em um arquivo os dados de todos os equipamentos
* Entradas: nada
* Saida: arquivo preenchido com todos os equipamentos
*/
void salvaArquivo(){
    FILE * fp;
    char * l = "w", aux[100] = ".txt", nome[100];
    printf("\nIremos criar um arquivo txt com todos os quipamentos cadastrados.\n");
    printf("Digite o nome do arquivo txt (sem o .txt):\t");
    gets(nome);
    fflush (stdin);
    strcat(nome, aux);
    fp = fopen(nome, l);
    if(!fp)
        printf("Erro na abertura do arquivo");
    else{
        for(int i = 0; i < n; i++)
            fprintf(fp, "Codigo: %d | Nome: %s | Preco: R$%.2f\n", lista[i].codigo, lista[i].nome, lista[i].preco);
        fclose(fp);
    }
}
int main(){
    char menu;
    float precoMedio;
    do{
        printf("\nSISTEMA DE CADASTRO DE EQUIPAMENTO\n");
        printf("Seja bem vindo!\n");
        printf("a) Cadastrar equipamentos\nb) Listar Equipamentos\nc) Calcular o preco medio dos equipamentos\nd) Mostrar os equipamentos com preco abaixo de um valor digitado pelo usuario\ne) Salvar em um arquivo os dados de todos os equipamentos\nf) Sair\n");
        scanf("%c", &menu); fflush(stdin);
        if(menu == 'f')
            printf("Programa finalizado! Obrigado e volte sempre!\n");
        else{
            switch(menu){
                case 'a':
                    cadastra(); // n eh o numero de elementos que foram preenchidos
                    break;
                case 'b':
                    listaEquipamentos();
                    break;
                case 'c':
                    calcPrecoMedio(&precoMedio);
                    break;
                case 'd':
                    mostraAbaixo();
                    break;
                case 'e':
                    salvaArquivo();
                    break;
                default:
                    printf("Entrada invalida. Tente novamente.\n");
                    break;
            }
        }
    }while(menu != 'f');
    return 0;
}
