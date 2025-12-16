#ifndef JUEGO_H
#define JUEGO_H
#include "enemigo.h"

class juego {
private:
	int nivel;
	int puntaje;
	int alto = 600;
	int ancho = 800;
	static const int MAX_ENEMIGOS = 30;
	enemigo* enemigos[MAX_ENEMIGOS];


public:
	int vidasAnteriores = -1;
	int puntajeAnterior = -1;
	bool hayEnemigoDebajo(enemigo* actual);
	juego();
	int getNivel();
	int getPuntaje();
	void iniciarjuego();
	void cargarenemigos();
	void aumentarPuntaje(int puntos);
	void Timers();

};

#endif
