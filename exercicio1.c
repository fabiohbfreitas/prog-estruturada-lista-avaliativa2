#include <limits.h>
#include <locale.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_LAPS 256

int main(void) {
  setlocale(LC_ALL, "Portuguese");

  int n_laps = 0;
  // printf("Informe o número de voltas: ");
  // scanf("%d", &n_laps);

  float lap_times[MAX_LAPS] = {};
  float fastest_lap_time = (float) LLONG_MAX;
  int fastest_lap_index = 0;
  float partial_sum_times = 0;
  
  // for (int i = 0; i < n_laps; i += 1) {
  //   printf("Tempo da volta %d: ", i + 1);
  //   scanf("%f", &lap_times[i]);
    
  //   const float current_lap_time = lap_times[i];
  //   partial_sum_times += current_lap_time;
    
  //   if (current_lap_time <= fastest_lap_time) {
  //     fastest_lap_time = current_lap_time;
  //     fastest_lap_index = i;
  //   }
  // }
  printf("Informe o valor do tempo das voltas (ou -1 para finalizar)\n");
  while (1) {
    float current_time = 0;
    printf("Tempo da volta %d (ou -1 para finalizar)\n> ", n_laps + 1);
    scanf("%f", &current_time);
    if (
      (int) fabs(current_time - (-1.0)) < 0.0001
    ) {
      break;
    }
    lap_times[n_laps] = current_time;
    partial_sum_times += current_time;
    
    if (current_time <= fastest_lap_time) {
      fastest_lap_time = current_time;
      fastest_lap_index = n_laps;
    }
    n_laps += 1;
  }
  const float average_time = partial_sum_times / n_laps;

  printf("\n-----[Resultados]\n");
  if (n_laps < 1) {
    printf("É necessário ter pelo menos 1 volta para mais informações.\n");
  } else {
    printf("Tempo mais rápido: %.4f\n", fastest_lap_time);
    printf("Volta do tempo mais rápido: %d\n", fastest_lap_index + 1);
    printf("Média de tempo das voltas: %.4f\n", average_time);
  }


  return EXIT_SUCCESS;
}