#include <limits.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_LAPS 256

int main(void) {
  setlocale(LC_ALL, "Portuguese");

  int n_laps = 0;
  printf("Informe o número de voltas: ");
  scanf("%d", &n_laps);

  float lap_times[MAX_LAPS] = {};
  float fastest_lap_time = (float) LLONG_MAX;
  int fastest_lap_index = 0;
  float partial_sum_times = 0;
  
  for (int i = 0; i < n_laps; i += 1) {
    printf("Tempo da volta %d: ", i + 1);
    scanf("%f", &lap_times[i]);
    
    const float current_lap_time = lap_times[i];
    partial_sum_times += current_lap_time;
    
    if (current_lap_time <= fastest_lap_time) {
      fastest_lap_time = current_lap_time;
      fastest_lap_index = i;
    }
  }
  const float average_time = partial_sum_times / n_laps;

  printf("Tempo mais rápido: %.4f\n", fastest_lap_time);
  printf("Volta do tempo mais rápido: %d\n", fastest_lap_index + 1);
  printf("Média de tempo das voltas: %.4f\n", average_time);
}