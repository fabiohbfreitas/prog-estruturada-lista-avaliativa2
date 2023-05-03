#include <limits.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

#define FUNCIONARIOS_MAX 256

int pecas[FUNCIONARIOS_MAX] = {};
int funcionarios = 0;

int validaQuantidade(int pecas) { return !(pecas != -1 && pecas > 0); }

float calculaSalario(int pecas) {
  const float salario_base = 600.f;
  float bonus = 0.f;

  if (pecas <= 50) {
    bonus = 0.f;
  } else if (pecas <= 80) {
    bonus += (pecas - 50) * 0.5;
  } else {
    const float bonus_parcial = (pecas - 80) * 0.75;
    bonus += 30 * 0.5 + bonus_parcial; // 30 -> 80 - 50 já que sempre será maior que 80
  }
  return salario_base + bonus;
}

void mostraFinal() {
  printf("\n------ Salários\n");
  for (int i = 0; i < funcionarios; i += 1) {
    printf("Funcionario %d: R$%.2f\n", i + 1, calculaSalario(pecas[i]));
  }
}

int main(void) {
  setlocale(LC_ALL, "Portuguese");

  while (1) {
    int numero_atual = 0;
    while (validaQuantidade(numero_atual)) {
      printf("Peças do funcionario %d (ou -1 para finalizar)\n> ", funcionarios + 1);
      scanf("%d", &numero_atual);
      if (numero_atual == -1) {
        goto finaliza;
      }
      if (validaQuantidade(numero_atual)) {
        printf("\t[Erro] Numero de peças invalido.\n");
      }
    }
    pecas[funcionarios] = numero_atual;
    funcionarios += 1;
  }
  finaliza:
    mostraFinal();
  return EXIT_SUCCESS;
}