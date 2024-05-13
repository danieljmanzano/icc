#include <stdio.h>

long int funcao(long int n){
   long int fib1 = 1, fib2 = 1, fibaux, resp;

   if(n == 0){
      return 0;
   
   }else if(n == 1 || n == 2){
      return 1;
   
   }else if(n > 2){
      for(long int i = 3; i <= n; i++){
         fibaux = fib2;
         fib2 += fib1;
         fib1 = fibaux;
         resp = fib2;
      }
   }
   return resp;
} 
//mais ligero e mais feio


long int fibo(long int n){
   
   if(n == 1 || n == 2) {
      return 1;
   }

   return fibo(n-1) + fibo(n-2);
}
//mais lento e mais bonito (recursiva)


int main(void){
   long int n;
   scanf("%ld", &n);
   printf("%ld\n", funcao(n));
   printf("%ld", fibo(n));
   
   return 0;
}

