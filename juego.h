#ifndef JUEGO_H
#define JUEGO_H


class juego {
private:
	int nivel;
	int puntaje;
	int alto = 600;
	int ancho = 800;


public:

	juego();
	int getNivel();
	int getPuntaje();
	void iniciarjuego();
	void aumentarPuntaje(int puntos);

};

#endif
