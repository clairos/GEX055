#include <stdio.h>
//#include <math. h> 

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

int pex(float p, float P, int xis){
    
    int seq;
    float expo;
    expo = P;
    for(seq = 0; seq < (xis - 1); seq++){
        expo *= P;
    }
        printf("\np ^ x = %.5f\n", expo);
        return expo;    
        return 0;
}

int qnx(float p, float P, int xis, int ene, int n){
    int seq, nx, expNX;
    float baseQ, res;
    baseQ = 1 - P;
    expNX = n - xis;
    res = baseQ;
    printf("%.2f ^ %d - %d = ", baseQ, n, xis);
    for(seq = 0; seq < (expNX - 1); seq++){
        res *= baseQ;
    }
    printf("%f", res);
    return baseQ;
    return res;
    return 0;
}  

int main(){
 
    int ene, xis, xiss, nx, n, x, combinacao;
    float p, P, PEX, QNX, Dis, baseq;

    //pedindo os valores de n, p e x
    printf("Digite o número de observações: \n");
    scanf("%d", &ene);
    printf("Digite a probabilidade de sucesso: \n");
    scanf("%f", &p);
    printf("Digite o número especificado de sucesso: \n");
    scanf("%d", &xis);
    n = ene;
    x = xis;
    P = p;
    baseq = 1 - P;
    //chamando funçao combinação
    combinacao = comb(n, x, ene, xis);
    //chamando função de calcular o P elevado a X
    PEX = pex(p, P, xis);
    //chamando função de calcular o q elavado a n - x
    QNX = qnx(p, P, xis, ene, n);

    //função para calcular resultado final

    float resposta;
    resposta = combinacao * PEX * QNX;
    
    printf("\nP(%d) = %d * ( %f ^ %d ) * ( %f ^ %d - %d ) = %f", x, combinacao, p, xis, baseq, ene, xis, resposta);

    return 0;
}

