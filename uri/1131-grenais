#include <stdio.h>

int main() {
    int inter,gremio,i,n=0,total=0,binter=0,grebbio=0,empate=0;
    while(n!=2) {
        scanf("%d %d",&inter,&gremio);
        total = total + 1;
        if(inter>gremio) {
            binter = binter + 1;
        }
        if(gremio>inter) {
            grebbio = grebbio + 1;
        }
        if(gremio==inter) {
            empate = empate + 1;
        }
        printf("Novo grenal (1-sim 2-nao)\n");
        scanf("%d",&n);
    }
    printf("%d grenais\n",total);
    printf("Inter:%d\n",binter);
    printf("Gremio:%d\n",grebbio);
    printf("Empates:%d\n",empate);
    if(binter>grebbio) {
        printf("Inter venceu mais\n");
    }
    if(grebbio>binter) {
        printf("Gremio venceu mais\n");
    }
    if(grebbio==binter) {
        printf("Nao houve vencedor\n");
    }
    return 0;
}
