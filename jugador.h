#ifndef JUGADOR_H
#define JUGADOR_H
#include <conio.h>	

class jugador {
private:
	int posx;	
	int vidas;
public:
	char tecla;
	int posy;
	jugador();
	int getPosx();
	int getPosy();
	int Vidas();
	void CantidadVidas();
	void moverjugador(char tecla);
	void dibujar();
	void borrar();	
};
#endif
