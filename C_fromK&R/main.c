#include "Prac2.h"
#include "Prac5.h"

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
void Prac2_6(void) {
    int x, y, pos, n;
    printf("Input x, y, pos, n\n");
    scanf("%d%d%d%d", &x, &y, &pos, &n);
    printf("%s", setbits(x, pos, n, y));
}

// Prac 2-7
void Prac2_7(void) {
    int x, p, n;
    printf("Input x, p, n\n");
    scanf("%d%d%d", &x, &p, &n);
    printf("%s", invert(x, p, n));

}

// Prac 2-8
void Prac2_8(void) {
    int x, n;
    printf("Input x, n\n");
    scanf("%d%d", &x, &n);
    printf("%s", rightrot(x, n));
}

// Prac 4-4
void Prac4_4(void) {

    int type;
    double op2;
    char s[100];

    printf("Input one expression\n");
    scanf("%s", &s);

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case '0':
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '*':
                push(pop() * pop());
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0) {
                    push(pop() / op2);
                    break;
                } else {
                    printf("Error: zero divisor\n");
                }
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("Error: unknown command\n");
                break;

        }

    }

}

// Prac 4-14
// Marco function is useful
#define swap(t, a, b) {\
                     \
  t tmp1;            \
  tmp1 = a;          \
  a = b;             \
  b = tmp1;             \
}


// Prac 5-7
char *lineptr[MAXLINE];
int Prac5_7(void) {

    int nlines; // line num for input

    if((nlines = readlines(lineptr,MAXLINE)) >= 0){ // build one linked list for input string
        Qsort(lineptr,0,nlines-1);
        writelines(lineptr,nlines);
        return 0;
    }else{
        printf("Error: input too big\n");
        return 1;
    }
}


// Prac 5-10
void Prac5_10(int argc, char *argv[]){
    int i;
    char s[100];
    for(i=0,--argc;argc > 0;argc--,i++){
        s[i]  = (*++argv)[0];
    }

    int res = cal(s,i);
    printf("Res: %d\n",res);

}


int main(int argc, char *argv[]) {
//    while (argc--){
//        printf("%c :%d\n",(*++argv)[0],argc);
//    }
    Prac5_10(argc,argv);

    exit(0);
}
