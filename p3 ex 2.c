#include <stdio.h>

int main()
{
//ler X e pegar os seus primos p.
int x;
int p=1;
int aux=1;
int i = 0;
int k;
int cprimo = 0;
int qtdePrimo=0;
int quadradoDivide=0;

scanf("%d", &x);
for(i=1; i <= x; i++){
    
    //TODOS os primos divisores de 8, e esses primos ao ^2 tem q dividir 8.
    
    for(p=2; p <= i; p++){
       if(i % p == 0){
           
           aux=p*p;
            for(k=1; k <= p; k++){
                if(p % k == 0){
                    cprimo++;
                }
            }
            if(cprimo == 2){
                qtdePrimo++;
                
                if(i % aux == 0 ){
                    quadradoDivide++;
                }
            }
        }
        cprimo=0;
    }
    
    if(quadradoDivide == qtdePrimo && qtdePrimo !=0){
                printf("%d ", i);
    }
    qtdePrimo=0;
    quadradoDivide=0;
   
}

}