#ifndef TIMER_H
#define TIMER_H

#include <ctime>

extern int contadorDisparosEnemigo;

// Control de tiempos para enemigos
extern clock_t intervaloEnemigos;
extern clock_t relojEnemigos;

// Control del tiempo para el jugador
extern clock_t intervaloJugador;
extern clock_t relojJugador;

// Control del tiempo para balas del jugador
extern clock_t intervaloBalaJugador;
extern clock_t relojBalaJugador;

// Control para balas enemigas
extern clock_t intervaloBalaEnemigo;
extern clock_t relojBalaEnemigo;

// Última tecla presionada
extern char teclaPresionada;

// Fin de la partida
extern bool juegoTerminado;

#endif
