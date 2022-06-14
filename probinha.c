#include <stdio.h>

int comb(int n, int x, int ene, int xis){
    //começo da conta de Combinação
    //C n,x = ( n! )/ ( (n - x) * (x!) )
    
    int nx, enexis, fatN, fatX, fatNX, com;

    nx = ene - xis;
    enexis = nx;
    
    //fatorial de x
    for(fatX = 1; x > 1; x--)
        fatX = fatX * x;
    //fatorial de n  
    for(fatN = 1; n > 1; n--)  
        fatN = fatN * n;            
    //fatorial de n - x
    for(fatNX = 1; nx > 1; nx--)
        fatNX = fatNX * nx;
    //conta 
    com = fatN / (fatNX * fatX);
    
    
    printf("\nC %d, %d = ( %d! )\n", ene, xis, ene);
    printf("----------------------- \n");
    printf("( %d )! %d!\n", enexis, xis);
    printf(" = %d\n", com);

    return com;
    return 0;    
}

int main(){
 
    int ene, xis, nx, n, x;
    float p, combinacao;

    //pedindo os valores de n e x
    printf("Digite o número de observações: \n");
    scanf("%d", &ene);
    // printf("Digite a probabilidade de sucesso: \n");
    // scanf("%f", &p);
    printf("Digite o número especificado de sucesso: \n");
    scanf("%d", &xis);
    n = ene;
    x = xis;
    combinacao = comb(n, x, ene, xis);

    return 0;
}

