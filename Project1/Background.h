#pragma once
#include "CEntidad.h"
using namespace System::Drawing;
using namespace System::Drawing::Drawing2D;
class background: CEntidad {
public:
	background(Bitmap^img) {
		x = 0;
		y = 0;
		idfilas = 0; idcolumnas = 0;
		AltoImangem = img->Height;
		AnchoImagen = img->Width;
		altoPersonaje = AltoImangem;
		anchoPersonaje = AnchoImagen;
	}
	void draw(Bitmap^ img, Graphics^ L) {
		Rectangle seccion = Rectangle(idcolumnas * anchoPersonaje, idfilas * altoPersonaje, anchoPersonaje, altoPersonaje);
		Rectangle Tamanho = Rectangle(x, y, anchoPersonaje, altoPersonaje);
		L->DrawImage(img, Tamanho, seccion, GraphicsUnit::Pixel);
	}

};