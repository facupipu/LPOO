#include <stdio.h>
#include <stdlib.h>

int main(void) {
  //declaracion de variables
  int puntaje_juego[30][7][2];
  float puntaje_final[30];
  float premios[7];
  int temp1 = -1;
  int temp2 = -1;
  int temp3 = -1;
  float temp4 = 0.0;

  printf("JUEGO DE TERMAS\n");
  printf("INGRESE EL VALOR DE LOS PREMIOS:\n");

  //blanqueo de la matriz
  for (int i = 0; i < 30; i++) {
    for (int j = 0; j < 7; j++) {
      for (int k = 0; k < 2; k++) {
        puntaje_juego[i][j][k] = 0;
      }
    }
  }

  // Ingreso de los valores de los premios
  for (int i = 0; i < 7; i++) {
    printf("premio del juego %d:", i+1);
    scanf("%f", &premios[i]);
    fflush(stdin);
  }

  //Loop de ingreso de datos de ternas
  while(1){
    // system("cls");
    printf("JUEGO DE TERMAS\n");
    printf("INGRESE LOS VALORES SIGUIENDO EL FORMATO:\n");
    printf("numero de jugador(1-30), numero de juego(1-7), puntuacion(1-10)\n");
    printf("PARA FINALIZAR ENVIA UNA TERNA AL JUGADOR 0\n");
    //ingreso de los datos guardados en variables temporaless
    scanf("%d, %d, %d", &temp1, &temp2, &temp3);
    fflush(stdin);
    //corrobora si estan bien ingresados
    while(temp1 < 0||temp1 > 30|| temp2 < 1||temp2 > 7||temp3 < 1||temp3 > 10){
      printf("Sus datos se ingresaron incorrectamente, por favor intente de nuevo\n");
      scanf("%d, %d, %d", &temp1, &temp2, &temp3);
      fflush(stdin);
      if(!(temp1 < 0||temp2 < 0||temp3 <0)){
        break;
      }
    }
    //corrobora si termina el ingreso
    if(temp1 == 0){
      temp1 = -1;
      temp2 = -1;
      temp3 = -1;
      break;
    }
    puntaje_juego[temp1-1][temp2-1][1] += temp3;
    puntaje_juego[temp1-1][temp2-1][2] ++;
    printf("%d %d %d\n", temp1, temp2, temp3);
    //default de los temporales
    temp1 = -1;
    temp2 = -1;
    temp3 = -1;
  }

  //imprecion de los resultados
  printf("\t\t|JUEGO 1|JUEGO 2|JUEGO 3|JUEGO 4|JUEGO 5|JUEGO 6|JUEGO 7|\n");
  printf("_________________________________________________________________________\n");
  for (int i = 0; i < 30; i++) {
    printf("|Jugador %d\t|", i+1);
    for (int j = 0; j < 7; j++) {
      if (puntaje_juego[i][j][1] == 0) {
        printf("S/P \t|");
      }
      else {
        temp4 = (puntaje_juego[i][j][1] * 1.0) / (puntaje_juego[i][j][2] * 1.0);
        puntaje_final[i] = temp4;
        printf("%.2f \t|", temp4);
        temp4 = 0.0;
      }
    }
    printf("\n");
  }
  printf("_________________________________________________________________________\n");
  printf("S/P: sin participar\n");
  printf("\n");
  //calculando porcentaje que no participo
  temp1 = 0;
  temp2 = 0;
  for (int i = 0; i < 30; i++) {
    for (int j = 0; j < 7; j++) {
      temp1 += puntaje_juego[i][j][1];
    }
    if (temp1 == 0) temp2 ++;
    else temp1 = 0;
  }
  temp4 = (temp2 * 1.00)/(30.0/100.0);
  temp2 = 0;
  printf("Porcentaje de jugadores que no fueron calificados: %.2f\n", temp4);
  temp4 = 0.0;
  printf("\n");
  //entrega de premios a los jugadores que quedaron primeros en cada juego(solo con mas de 8 puntos)
  for (int i = 0; i < 7; i++) {
    printf("PREMIO DE $%.2f\n DEL JUEGO %d: ", premios[i], i);
    //buscando al ganador
    for (int i = 0; i < 30; i++) {
      if (puntaje_final[i] > temp4){
        temp4 = puntaje_final[i];
        temp2 = i;
      }
    }
    //imprimiendo al ganador
    if (temp4 < 8)  printf("SIN GANADOR\n");
    else            printf("JUGADOR %d (%.2f pts)\n", temp2, temp4);
  }

  return 0;
}
