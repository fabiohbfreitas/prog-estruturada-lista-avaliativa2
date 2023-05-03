#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_CAPACITY 64

#define SEX_M 1
#define SEX_F 2
#define SALARIO_MINIMO 1400
#define ACIMA 1
#define IGUAL 2
#define ABAIXO 3

int total_assalariados = 0;
int sexos[MAX_CAPACITY] = {};
int salario_classificado[MAX_CAPACITY] = {};
float salario_array[MAX_CAPACITY] = {};

int classificaSalario(float salario) {
  const float precisao = 0.0001;
  if (
    salario + precisao > 1400 &&
    salario - precisao < 1400
  ) {
    printf("delta: %f\n", (salario - 1400));
    return IGUAL;
  } else if (salario < 1400.0) {
    return ABAIXO;
  } else {
    return ACIMA;
  }
}

void mostraClassifica() {
  for (int i = 0; i < total_assalariados; i += 1) {
    char* sexo = sexos[i] == SEX_M ? "Masculino" : "Feminino";
    char* classificacao_salario = salario_classificado[i] == IGUAL ? "Igual" : salario_classificado[i] == ABAIXO ? "Abaixo" : "Acima";
    printf("Assalariado %d -> Sexo: %s | Classificação: %s\n", i + 1, sexo, classificacao_salario);
  }
}



int main() {
  setlocale(LC_ALL, "Portuguese");

  while(1) {
    printf("\nInforme os dados do próximo assalariado (ou -1 para finalizar)\n");
    int sexo = -1;
    while (sexo != SEX_M && sexo != SEX_F) {
      printf("Sexo: (1) Masculino ou (2) Feminino\n> ");
      scanf("%d", &sexo);
      if (sexo == -1) {
        goto finaliza;
      }
      if (sexo != SEX_M && sexo != SEX_F) {
        printf("\t[Erro] Informe um valor válido.\n");
      }
    }
    sexos[total_assalariados] = sexo;

    float salario = 0.f;
    while (salario <= 1.0) {
      printf("Valor do salário (R$)\n> ");
      scanf("%f", &salario);
      if (salario <= 1.0) {
        printf("\t[Erro] Salario deve ser maior que R$1.00\n");
      }
    }
    salario_classificado[total_assalariados] = classificaSalario(salario);

    total_assalariados += 1;
  }

finaliza:
  printf("-----[Resultado]\n");
  mostraClassifica();

  return EXIT_SUCCESS;
}