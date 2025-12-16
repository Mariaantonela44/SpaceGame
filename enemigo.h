#ifndef ENEMIGO_H
#define ENEMIGO_H

class enemigo {
private:
	bool vivo;
protected:
	int velocidad;
	char forma;
	int color;
	
	
public:
	int direccion;
	bool ataque;
	int posx;
	int posy;
	int puntosenemigo;
	enemigo();
	enemigo(int x, int y, char f);
	enemigo(int x, int y, char f, int c);
	int getPosx();
	int getPosy();
	bool estaVivo();
	void borrar();
	void mover();
	void dibujar();
	void danio();
	bool atacar();
};


class EnemigoH : public enemigo {
public:
	EnemigoH(int x, int y);
};

class EnemigoM : public enemigo {
public:
	EnemigoM(int x, int y);
};

class EnemigoW : public enemigo {
public:
	EnemigoW(int x, int y);
};

#endif
