// womdowsVERSAUM DES
#include <stdio.h>

int main() {
    double tot = 0, mult;
    double quanto, par;
    char quero, produto, final;
    printf("****Bem-vindo a loja INFOPROVA****\n");
    printf("\n");
    start:
    printf("Selecione o produto desejado:\n");
    printf("A - Notebook\n");
    printf("B - Monitor\n");
    printf("C - HD externo\n");
    printf("\n");
    printf("Produto selecionado: ");
    scanf(" %c", &produto);
    switch(produto) {
        case 'A':
            mult = 4500;
            break;
        case 'B':
            mult = 1099.99;
            break;
        case 'C':
            mult = 310.50;
            break;
        default:
            printf("Produto invalido!\n");
            printf("\n");
            goto end;
            break;
    }
    printf("Quantidade desejada: ");
    scanf("%lf", &quanto);
    if(quanto > 0) {
        tot = tot + (quanto * mult);
        printf("\n");
    } else {
        printf("Quantidade invalida!\n");
        printf("\n");
        goto end;
    }
    printf("Deseja levar outro produto (S/N): ");
    scanf(" %c", &quero);
    if(quero == 's' || quero == 'S') {
        printf("\n");
        goto start;
    } else if(quero == 'n' || quero == 'N') {
        printf("\n");
    } else {
        printf("Opcao invalida!\n");
        printf("\n");
        goto end;
    }
    printf("Total da compra: %.2lf\n", tot);
    printf("Forma de pagamento:\n");
    printf("A - A vista\n");
    printf("B - Parcelado\n");
    printf("\n");
    printf("Opcao selecionada: ");
    scanf(" %c", &final);
    if(final == 'A') {
        printf("Valor a ser pago: %.2lf\n", tot*.9);
        printf("\n");
        goto end;
    } if(final == 'B') {
        printf("Numero de parcelas: ");
        scanf("%lf", &par);
        if(tot > 5000) {
            if(par > 6 || par < 1) {
                printf("Numero de parcelas invalido!\n");
                printf("\n");
                goto end;
            } else {
                printf("Valor de cada parcela: %.2lf", tot/par);
                printf("\n");
                goto end;
            }
        } else {
            if(par > 3 || par < 1) {
                printf("Numero de parcelas invalido!\n");
                printf("\n");
                goto end;
            } else {
                printf("Valor de cada parcela: %.2lf", tot/par);
                printf("\n");
                goto end;
            }
        }
    }
    end:
    printf("***Obrigado por comprar conosco***");
    return 0;
}