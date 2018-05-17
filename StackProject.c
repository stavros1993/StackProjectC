 #include <stdio.h>

const int MAXSIZE = 50;
double *stack;
int top = -1; //epeidh metrame apto 0 prepei na xw -1

//double* createStack(){
//        double *stack = (double*)malloc(sizeof(double)*MAXSIZE);
//        return stack;        
//}


// ilopoiisi push
int push(double d){
     if (top == 49) return 0;
     
     top++;
     stack[top] = d;
     
     
     return 1;
}

//ilopoiisi pop
int pop(double* d) { //krataei th timh d 
       if (top == -1) return 0;
       
       *d = stack[top];
       top--;
       return 1;
}

void main(){
     double a, b;
     char c[MAXSIZE]; 
     stack = (double*)malloc(sizeof(double)*MAXSIZE);   
     char *p;
     char d;
     int cc = 0;
     
     scanf("%s", &c);
     
     p = c;
     
     while (c[cc] != '\0') {
           if (c[cc] == '+' || c[cc] == '-' || c[cc] == '/' || c[cc] == '*') {
                 if (pop(&a) == 1 && pop(&b) == 1) {
                    switch (c[cc]) {
                           case '+': b += a; break;
                           case '-': b -= a; break;
                           case '*': b *= a; break;
                           default: b /= a;
                    }                  
                    if (push(b)==0) printf("error cannot push %lf.\n", b);
                 }
                 else printf("error cannot pop.\n");
           }
           else {
                //d = *p;
                //a = c[cc]-48;//atoi(c[cc]);     
                switch (c[cc]){
                       case '0': a = 0; break;
                       case '1': a = 1; break;
                       case '2': a = 2; break;       
                       case '3': a = 3; break;
                       case '4': a = 4; break;
                       case '5': a = 5; break;
                       case '6': a = 6; break;
                       case '7': a = 7; break;
                       case '8': a = 8; break;
                       default: a = 9; break;
                }       
                if (push(a) == 0) printf("error cannot push %lf.\n", a);
           }        
           cc++;                  
     }
     if (pop(&a)==0) printf("error cannot pop.\n");
     printf("result is %lf\n", a);
     fflush(stdin);
     scanf("%c",&d);
}
