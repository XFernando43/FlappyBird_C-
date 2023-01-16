#pragma once
#include "CEntidad.h"
class tuvo_invertido: CEntidad {
	bool estado;
public:
	tuvo_invertido(Bitmap^ img,int x,int y) {
		this->x = x;
		this->y = y;
		dx = 20; dy = 3;
		idfilas = 0; idcolumnas = 0;
		AltoImangem = img->Height;
		AnchoImagen = img->Width;
		altoPersonaje = AltoImangem;
		anchoPersonaje = AnchoImagen;
		estado = false;
	}
	void Draw(Bitmap^ img, Graphics^ L) {
		Rectangle seccion = Rectangle(idcolumnas * anchoPersonaje, idfilas * altoPersonaje, anchoPersonaje, altoPersonaje);
		Rectangle Tamanho = Rectangle(x, y, anchoPersonaje / 1.5, altoPersonaje / 1.5);
		L->DrawImage(img, Tamanho, seccion, GraphicsUnit::Pixel);
	}

	void Mover() { x -= dx; }
	void funciona_porfavorcito() {}
	bool getEstado() { return estado; }
	int getX() { return x; }
	int getY() { return y; }
	int getAlto() { return altoPersonaje; }
	int getAncho() { return anchoPersonaje; }
	void setDx(int dx) { this->dx = dx; }
};