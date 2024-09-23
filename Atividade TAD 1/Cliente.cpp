#include<stdio.h>

struct Data {

 int dia;
 int mes;
 int ano;

 void ler_data(){
    printf("Digite o dia em que nasceu: ");
    scanf("%d%*c", &dia);
    printf("Digite o mes em que nasceu: ");
    scanf("%d%*c", &mes);
    printf("Digite o ano em que nasceu: ");
    scanf("%d%*c", &ano);
 }

 void idade() {

    int calculo;

    calculo = 2024 - ano;

    if(mes > 9){
        calculo --;
    }
    else if(mes == 9 && dia > 23){
        calculo--;
    }

    printf("Sua idade e: %d\n", calculo);
    }

 };


struct Cliente {

    char nome[100];
    Data nascimento;
    char sexo;

    void ler() {
        printf("Digite seu nome: ");
        scanf("%[^\n]%*c", nome);
        nascimento.ler_data();
        printf("Digite seu sexo(M ou F): ");
        scanf("%c%*c", &sexo);
    }

    void imprimir() {
        printf("Nome: %s\n", nome);
        printf("Sexo: %c\n", sexo);
        nascimento.idade();
    }
};


int main() {

    Cliente c;
    Data d;

    c.ler();
    c.imprimir();

    return 0;
}

