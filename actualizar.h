#ifndef ACTUALIZAR_H
#define ACTUALIZAR_H

class actualizar {
private:
    int posx, posy;

public:
    actualizar();
    int getPosx();
    int getPosy();
    void actualizarPosicion(int x, int y);
    void limpiar();
};

#endif