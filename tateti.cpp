#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void) {

  bool jugador = false;
  int ronda = 0;
  char x;
  int y;
  char tablero[3][3];
  bool finish = false;
  bool draw = true;

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
        tablero[i][j]= '-';
    }
  }

  printf("---JUEGO DEL TATETI---\n");
  printf("Presione cualquier tecla para iniciar\n");
  scanf("%c");
  fflush(stdin);

  while (!finish) {
    system("cls");
    printf("%d\n", ronda);
    printf("JUGADOR %d ELIJE SU SIGUENTE MOVIMIENTO (ej: A 3)\n", jugador + 1 );
    printf("   A    B    C\n");
    for (int i = 0; i < 3; i++) {
      printf("%d", i+1);
      for (int j = 0; j < 3; j++) {
          printf("| %c |", tablero[i][j]);
      }
      printf("\n  ---- ---- ----\n");
    }
    scanf("%c %d", &x, &y);
    fflush(stdin);

    while (x < 65 || x > 67 || y < 1 || y > 3 ||  tablero[y-1][x-65] != '-') {
      printf("valor incorrecto o ya ocupado, intente devuelta\n");
      scanf("%c %d", &x, &y);
      fflush(stdin);
    }
    y -= 1;
    x -= 65;
    if (jugador)  tablero[y][x] = 'X';
    else          tablero[y][x] = '0';

    if      (tablero[0][x]==tablero[1][x] && tablero[0][x]==tablero[2][x])  {finish = true; draw = false;}
    else if (tablero[y][0]==tablero[y][1] && tablero[y][0]==tablero[y][2])  {finish = true; draw = false;}
    else if ((y == x || y == x-2 || y == x+2 ) && ((tablero[x][y] == tablero[1][1] && tablero[1][1] == tablero[0][0] && tablero[2][2]==tablero[1][1]) || (tablero[x][y] == tablero[1][1] && tablero[1][1]==tablero[0][2] && tablero[1][1]==tablero[2][0]))) {finish = true; draw = false;}

    ronda ++;
    if(ronda == 9 || finish) {
      system("cls");
      printf("---JUEGO TERMINADO---\n");
      printf("   A    B    C\n");
      for (int i = 0; i < 3; i++) {
        printf("%d", i+1);
        for (int j = 0; j < 3; j++) {
            printf("| %c |", tablero[i][j]);
        }
        printf("\n  ---- ---- ----\n");
      }
      if (draw) printf("EMPATE!!!\n");
      else      printf("GANO EL JUGADOR %d!!!\n", jugador + 1);
    }
    jugador = !jugador;
  }
  return 0;
}
