#include <stdio.h>
#include <math.h> 

double comb(double n, double x, double ene, double xis){
    //começo da conta de Combinação
    //C n,x = ( n! )/ ( (n - x) * (x!) )
    
    double nx, enexis, fatN, fatX, fatNX, com;

    nx = n - x;
    enexis = nx;

    //fatorial de n  
    for(fatN = 1; n > 1; n--)
        fatN = fatN * n; 
    
    //fatorial de x
    for(fatX = 1; x > 1; x--)
        fatX = fatX * x;

    //fatorial de n - x
    for(fatNX = 1; nx > 1; nx--)
        fatNX = fatNX * nx;

    //conta 
    com = fatN / (fatNX * fatX);
    
    
    printf("\nC %.0lf, %.0lf =  ( %.0lf! )\n", ene, xis, ene);
    printf("         ---------\n");
    printf("         ( %.0lf )! %.0lf!\n", enexis, xis);
    printf(" = %.0lf\n", com);

    return com;
}

double pex(double p, double xis){
    double expo;

    expo = pow(p, xis);
    
    return expo;
}

double qnx(double p, double xis, double ene){
    double expNX, q, res;

    q = 1 - p;
    expNX = ene - xis;

    res = pow(q, expNX);
    
    return res;
}  

int main(){
    double ene, xis, n, x, p, PEX, QNX, q, combinacao, resposta, final;

    //pedindo os valores de n, p e x
    printf("Digite o numero de observacoes: \n");
    scanf("%lf", &ene);
    printf("Digite o numero especificado de sucesso: \n");
    scanf("%lf", &xis);
    printf("Digite a probabilidade de sucesso: \n");
    scanf("%lf", &p);

    n = ene;
    x = xis;
    q = 1 - p;

    //chamando função combinação
    combinacao = comb(n, x, ene, xis);
    //chamando função de calcular o P elevado a X
    PEX = pex(p, xis);
    //chamando função de calcular o q elavado a n - x
    QNX = qnx(p, xis, ene);

    //resultado final
    resposta = (combinacao) * (PEX) * (QNX);
    final = resposta*100;
    
    printf("\nP(%.0lf) = %.0lf * ( %.2lf ^ %.0lf ) * ( %.2lf ^ %.0lf - %.0lf ) = %.4lf\n", x, combinacao, p, xis, q, ene, xis, resposta);
    printf("Resposta em porcentagem: %.2lf%%\n", final);

    return 0;
}
