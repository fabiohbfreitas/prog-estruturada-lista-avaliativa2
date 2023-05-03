#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_CAPACITY 32

float medias[MAX_CAPACITY] = {};
float media_peso_acima25[MAX_CAPACITY] = {};

int n_times = 0;
int qtd_menos18 = 0;
int qtd_mais80 = 0;
int qtd_jogadores = 0;

void mostraResultado() {
  printf("-----[RESULTADOS]\n");
  for(int i = 0; i < n_times; i += 1) {
    printf("\n[Time %d]\nMedia Idade: %.2f\nMedia peso (>25 anos): %.2f\n", i + 1, medias[i], media_peso_acima25[i]);
  }
  printf("\nQuantidade jogadores < 18: %d\n", qtd_menos18);
  printf("Quantidade jogadores > 80kg: %d (%.2f%%)\n", qtd_mais80, ((float) qtd_mais80 / qtd_jogadores) * 100);
}

int main(void) {
  setlocale(LC_ALL, "Portuguese");

  while (n_times < 3 || n_times >9) {
    printf("Informe o número de times: ");
    scanf("%d", &n_times);
    if (n_times < 3 || n_times >9) {
      printf("\t[Erro] O número de times deve estar entre 3 e 9.\n");
    }
  }

  
  for (int t = 0; t < n_times; t += 1) {
    int soma_idades = 0;
    int qtd_acima25 = 0;
    int soma_peso_acima25 = 0;
    
    int n_jogadores_time = 0;
    while (n_jogadores_time < 6 || n_jogadores_time > 11) {
      printf("Informe o número de jogadores do time %d: ", t + 1);
      scanf("%d", &n_jogadores_time);
      if (n_jogadores_time < 6 || n_jogadores_time > 11) {
        printf("\t[ERRO] Um time deve ter entre 6 e 11 jogadores.\n");
      }
    }
    
    for (int j = 0; j < n_jogadores_time; j += 1) {
      int idade_jogador = 0;
      while (idade_jogador <= 0 || idade_jogador > 100) {
        printf("[Time %d] Informa a idade do jogador %d: ", t + 1, j + 1);
        scanf("%d", &idade_jogador);
        if (idade_jogador <= 0 || idade_jogador > 100) {
          printf("\t[Erro] Informe uma idade válida.\n");
        }
      }

      soma_idades += idade_jogador;
      if (idade_jogador < 18) {
        qtd_menos18 += 1;
      }

      float peso_jogador = 0.f;
      while (peso_jogador <= 0 || peso_jogador > 200) {
        printf("[Time %d] Informa a peso do jogador %d(kg): ", t + 1, j + 1);
        scanf("%f", &peso_jogador);
        if (peso_jogador <= 0 || peso_jogador > 200) {
          printf("\t[Erro] Informe um peso válido.\n");
        }
      }
      if (idade_jogador > 25) {
        qtd_acima25 += 1;
        soma_peso_acima25 += peso_jogador;
      }
      if (peso_jogador > 80) {
        qtd_mais80 += 1;

      }
      qtd_jogadores += 1;
    }

    medias[t] = (float) soma_idades / n_jogadores_time;
    media_peso_acima25[t] = (float) soma_peso_acima25 / qtd_acima25;
  }
  
  mostraResultado();
  return 0;
}