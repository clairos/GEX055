#include <stdio.h>
#include <math.h> 

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
}

int pex(double p, int xis){
    double expo;

    expo = pow(p, xis);
    
    return expo;
}

int qnx(double p, int xis, int ene){
    int expNX;
    double q, res;

    q = 1 - p;
    expNX = ene - xis;

    res = pow(q, expNX);
    
    return res;
}  

int main(){
 
    int ene, xis, n, x, combinacao;
    double p, PEX, QNX, q, resposta;

    //pedindo os valores de n, p e x
    printf("Digite o número de observações: \n");
    scanf("%d", &ene);
    printf("Digite o número especificado de sucesso: \n");
    scanf("%d", &xis);
    printf("Digite a probabilidade de sucesso: \n");
    scanf("%f", &p);

    n = ene;
    x = xis;
    q = 1 - p;

    //chamando função combinação
    combinacao = comb(n, x, ene, xis);
    // printf("%d", combinacao);
    //chamando função de calcular o P elevado a X
    PEX = pex(p, xis);
    // printf("%.2lf", PEX);
    //chamando função de calcular o q elavado a n - x
    QNX = qnx(p, xis, ene);
    // printf("%.2lf", QNX);

    //resultado final
    resposta = combinacao * PEX * QNX;
    
    printf("\nP(%d) = %d * ( %.2lf ^ %d ) * ( %.2lf ^ %d - %d ) = %.2lf", x, combinacao, p, xis, q, ene, xis, resposta);

    return 0;
}

