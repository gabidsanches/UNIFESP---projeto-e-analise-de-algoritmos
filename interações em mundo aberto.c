#include <stdio.h>
 
#include <stdlib.h>
 
#include <math.h>
 
 
 
typedef struct {
 
    double x;
 
    double y;
 
} ponto;
 
 
 
double distancia(ponto p1, ponto p2) {
 
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
 
}
 
 
 
int compararX(const void *a, const void *b) {
 
    ponto *p1 = (ponto *)a;
 
    ponto *p2 = (ponto *)b;
 
    if (p1->x < p2->x) return -1;
 
    if (p1->x > p2->x) return 1;
 
    return 0;
 
}
 
 
 
int compararY(const void *a, const void *b) {
 
    ponto *p1 = (ponto *)a;
 
    ponto *p2 = (ponto *)b;
 
    if (p1->y < p2->y) return -1;
 
    if (p1->y > p2->y) return 1;
 
    return 0;
 
}
 
 
 
double proxFaixa(ponto faixa[], int tam, double d) {
 
    double min = d;
 
    qsort(faixa, tam, sizeof(ponto), compararY);
 
 
 
    for (int i = 0; i < tam; i++) {
 
        for (int j = i + 1; j < tam && (faixa[j].y - faixa[i].y) < min; j++) {
 
            double dist = distancia(faixa[i], faixa[j]);
 
            if (dist < min) {
 
                min = dist;
 
            }
 
        }
 
    }
 
    return min;
 
}
 
 
 
double div_conquista(ponto pontos[], int esquerda, int direita) {
 
    if (direita - esquerda <= 3) {
 
        double min = INFINITY;
 
        for (int i = esquerda; i < direita; i++) {
 
            for (int j = i + 1; j < direita; j++) {
 
                double dist = distancia(pontos[i], pontos[j]);
 
                if (dist < min) {
 
                    min = dist;
 
                }
 
            }
 
        }
 
        return min;
 
    }
 
 
 
    int meio = (esquerda + direita) / 2;
 
    double d_esquerda = div_conquista(pontos, esquerda, meio);
 
    double d_direita = div_conquista(pontos, meio, direita);
 
 
 
    double d = fmin(d_esquerda, d_direita);
 
 
 
    ponto faixa[direita - esquerda];
 
    int k = 0;
 
    for (int i = esquerda; i < direita; i++) {
 
        if (fabs(pontos[i].x - pontos[meio].x) < d) {
 
            faixa[k++] = pontos[i];
 
        }
 
    }
 
 
 
    return fmin(d, proxFaixa(faixa, k, d));
 
}
 
 
 
double maisProx(ponto pontos[], int n) {
 
    qsort(pontos, n, sizeof(ponto), compararX);
 
    return div_conquista(pontos, 0, n);
 
}
 
 
 
int main() {
 
    int n;
 
    scanf("%d", &n);
 
 
 
    ponto *pontos = (ponto *)malloc(n * sizeof(ponto));
 
    if (pontos == NULL) {
 
        printf("Erro ao alocar memória!\n");
 
        return 1;
 
    }
 
 
 
    for (int i = 0; i < n; i++) {
 
        scanf("%lf %lf", &pontos[i].x, &pontos[i].y);
 
    }
 
 
 
    printf("%.10lf\n", maisProx(pontos, n));
 
 
 
    free(pontos);
 
    return 0;
 
}