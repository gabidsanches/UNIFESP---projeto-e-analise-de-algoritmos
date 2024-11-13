#include <stdio.h>
 
unsigned long long contar(unsigned long long n) {
    if (n < 0) return 0;
 
    unsigned long long contagem = 0;
    unsigned long long posicao_bit = 1;
 
    while (posicao_bit <= n) {
 
        unsigned long long total_pares = (n + 1) / (posicao_bit * 2);
        contagem += total_pares * posicao_bit;
 
        unsigned long long resto = (n + 1) % (posicao_bit * 2);
        if (resto > posicao_bit) {
            contagem += resto - posicao_bit;
        }
 
        posicao_bit *= 2;
    }
 
    return contagem;
}
 
unsigned long long contar_intervalo(unsigned long long x, unsigned long long y) {
    return contar(y) - contar(x - 1);
}
 
int main() {
    unsigned long long x, y;
 
    scanf("%llu", &x);
    scanf("%llu", &y);
 
    unsigned long long resultado = contar_intervalo(x, y);
    printf("%llu\n", resultado);
 
    return 0;
}