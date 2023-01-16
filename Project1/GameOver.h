#pragma once
#include "CEntidad.h"
class Gamve_over_P: CEntidad {
public:
	Gamve_over_P(Bitmap^ img, int x, int y) {
		this->y = y;
		this->x = x;
		idfilas = 0; idcolumnas = 0;
		AltoImangem = img->Height;
		AnchoImagen = img->Width;
	}
	void draw(Bitmap^ img, Graphics^ L) {
		Rectangle seccion = Rectangle(idcolumnas * AnchoImagen, idfilas * AltoImangem, AnchoImagen, AltoImangem);
		Rectangle Tamanho = Rectangle(x, y, AnchoImagen, AltoImangem);
		L->DrawImage(img, Tamanho, seccion, GraphicsUnit::Pixel);
	}
};