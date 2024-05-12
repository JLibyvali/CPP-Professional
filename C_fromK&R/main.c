#include "Prac2.h"

char *hexString;    // Prac 2-3
void Prac2_3(void) {
    // Prac 2-3
    hexString = (char *) malloc(100);
    printf("Input Hex number\n");
    scanf("%s", hexString);
    int len = strlen(hexString);
    printf("Result:D%d", Htoi(hexString, len));
}

// Prac 2-6
void Prac2_6(void){
    int x,y,pos,n;
    printf("Input x, y, pos, n\n");
    scanf("%d%d%d%d",&x,&y,&pos,&n);
    printf("%s", setbits(x,pos,n,y));
}

// Prac 2-7
void Prac2_7(void){
    int x,p,n;
    printf("Input x, p, n\n");
    scanf("%d%d%d",&x,&p,&n);
    printf("%s", invert(x,p,n));

}

// Prac 2-8
void Prac2_8(void){
    int x ,n;
    printf("Input x, n\n");
    scanf("%d%d",&x,&n);
    printf("%s", rightrot(x,n));
}

int main(void) {
    Prac2_8();
    exit(0);
}
