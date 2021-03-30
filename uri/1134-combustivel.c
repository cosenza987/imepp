#include <stdio.h>

int main() {
    int n,i,gasolina=0,alcool=0,diesel=0;
    char c;
    while(c!='4') {
        scanf("%c",&c);
        if(c=='1') {
            alcool = alcool + 1;
        }
        if(c=='2') {
            gasolina = gasolina + 1;
        }
        if(c=='3') {
            diesel = diesel + 1;
        }
    }
    printf("MUITO OBRIGADO\nAlcool: %d\nGasolina: %d\nDiesel: %d\n",alcool,gasolina,diesel);
    return 0;
}
