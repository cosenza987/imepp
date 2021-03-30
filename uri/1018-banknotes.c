#include <stdio.h>

int main() {
    int a,b,c,d,e,f,g,h,i;
    scanf("%d",&a);
    b=c=d=e=f=g=h=0;
    i = a;
    while(a!=0) {
        if(a>=100) {
            b = a/100;
            a = a%100;
        }
        if(a>=50) {
            c = a/50;
            a = a%50;
        }
        if(a>=20) {
            d = a/20;
            a = a%20;
        }
        if(a>=10) {
            e = a/10;
            a = a%10;
        }
        if(a>=5) {
            f = a/5;
            a = a%5;
        }
        if(a>=2) {
            g = a/2;
            a = a%2;
        }
        if(a>=1) {
            h = a/1;
            a = a%1;
        }
    }
    printf("%d\n",i);
    printf("%d nota(s) de R$ 100,00\n",b);
    printf("%d nota(s) de R$ 50,00\n",c);
    printf("%d nota(s) de R$ 20,00\n",d);
    printf("%d nota(s) de R$ 10,00\n",e);
    printf("%d nota(s) de R$ 5,00\n",f);
    printf("%d nota(s) de R$ 2,00\n",g);
    printf("%d nota(s) de R$ 1,00\n",h);
    return 0;
}
