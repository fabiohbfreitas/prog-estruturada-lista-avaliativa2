#include <limits.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

#define FUNCIONARIOS_MAX 1024

int pecas[FUNCIONARIOS_MAX] = {};
int funcionarios = 1;

int validaQuantidade(int pecas) { return pecas != -1 && pecas > 0; }

float calculaSalario(int pecas) {
  const float salario_base = 600.f;
  float bonus = 0.f;

  if (pecas <= 50) {
    bonus = 0.f;
  } else if (pecas <= 80) {
    bonus += (pecas - 50) * 0.5;
    printf("\tbonus atual: %.4f\n", bonus);
  } else {
    const int bonus_parcial = (pecas - 80) * 0.75;
    bonus += 30 * 0.5 +
             bonus_parcial; // 30 -> 80 - 50 já que sempre será maior que 80
    printf("\tbonus atual: %.4f\n", bonus);
  }
  return salario_base + bonus;
}

void mostraFinal() {
  printf("------ Salários\n\n");
  //printf("funcs: %d \n", n_funcionarios);
  for (int i = 0; i < funcionarios; i += 1) {
    //printf("F%d Idx %d pcs %d\n", i + 1, i, pecas[i]);
    printf("Funcionario %d: R$%.2f\n", i + 1, calculaSalario(pecas[i]));
  }
}

int main(void) {
  setlocale(LC_ALL, "Portuguese");

  while (1) {
    printf("funcionarios: %d\n", funcionarios);
    printf("Peças do funcionario %d (ou -1 para finalizar): ", funcionarios);
    int numero_atual = 0;
    scanf("%d", &numero_atual);
    if (numero_atual == -1) {
      funcionarios -= 1;
      break;
    } else {
      if (validaQuantidade(numero_atual)) {
        funcionarios += 1;
        int idx = funcionarios - 1;
        pecas[idx] = numero_atual;
      } /*else {
        printf("[Erro] Número de peças inválido\n\n");
        continue;
      }*/
      
    }
  }
  mostraFinal();
  return EXIT_SUCCESS;
}