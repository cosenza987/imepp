// womdowsVERSAUM DES
#include <stdio.h>

int main() {
    int alt, tri, base, base1, base2, entra, row;
    printf("Digite a alutra do triforce: ");
    scanf(" %d", &alt);
    if(alt%2 != 0 || alt < 4) {
        printf("ALTURA INVALIDA\n");
    } else {
        row = 0;
        tri = (alt / 2) + 1; //pegando a altura de cada triangulo
        base = (2*tri) - 1;
        base1 = base;
        base2 = base;
        entra = tri - 1;
        //imprimindo o triangulo de cima
        for(int j = 0; j < tri; j++) {
            for(int i = 0; i < base1 - 1; i++) {
            printf(" ");
            }
            base1--;
            for(int k = 0; k < (2*row) - 1; k++) {
                printf("*");
            }
            if(j != tri - 1) {
                printf("\n");
            }
            row++;
        }
        row = 0;
        for(int j = 0; j < tri; j++) {
            for(int i = 0; i < entra; i++) {
                printf(" ");
            }
            for(int i = 0; i < (2*row) - 1; i++) {
                printf("*");
            }
            for(int i = 0; i < base2; i++) {
                printf(" ");
            }
            for(int i = 0; i < (2*row) - 1; i++) {
                printf("*");
            }
            entra--;
            row++;
            base2 = base2 - 2;
            printf("\n");
        }
    }
    return 0;
}