#include "timer.h"

// Contadores y banderas
int contadorDisparosEnemigo = 0;

// Control de tiempos para enemigos
clock_t intervaloEnemigos = 0;
clock_t relojEnemigos = 0;

// Control del tiempo para el jugador
clock_t intervaloJugador = 0;
clock_t relojJugador = 0;

// Control del tiempo para balas del jugador
clock_t intervaloBalaJugador = 0;
clock_t relojBalaJugador = 0;

// Control del tiempo para balas enemigas
clock_t intervaloBalaEnemigo = 0;
clock_t relojBalaEnemigo = 0;

// Última tecla presionada
char teclaPresionada = 0;

// Fin de la partida
bool juegoTerminado = false;
