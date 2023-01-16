#pragma once
#include "CEntidad.h"
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace System::Drawing::Drawing2D;
class Ave: CEntidad{
	bool volando;
	bool vivo;
public:
	Ave(Bitmap^ img) {
		x = 0; y = 0;
		dx = 3; dy = 10;
		idfilas = 0; idcolumnas = 0;
		AltoImangem = img->Height;
		AnchoImagen = img->Width;
		altoPersonaje = AltoImangem;
		anchoPersonaje = AnchoImagen / 3;
		volando = true;
		vivo = true;
	}
	void DrawBird(Bitmap^ img, Graphics^ L) {
		Rectangle seccion = Rectangle(idcolumnas * anchoPersonaje, idfilas * altoPersonaje, anchoPersonaje, altoPersonaje);
		Rectangle Tamanho = Rectangle(x, y, anchoPersonaje, altoPersonaje);
		L->DrawImage(img, Tamanho, seccion, GraphicsUnit::Pixel);
		AumentarColumnas();
		
	}


	void muerto() {
		vivo = false;
	}
	
	void Activar_caida() {
		volando = true;
	}

	void desactivar_caida() {
		volando = false;
	}

	void elevacion() {
		if(volando==false){
			y += dx;
		}
	}


	void gravedad() {
		if (volando == true) {
			y += dy;
		}
	}

	void Saltar(System::Windows::Forms::KeyEventArgs^ e) {
		int posy;
		switch (e->KeyCode)
		{
		case Keys::Space : {
			if (vivo==true) {
				y -= 40;
			}
		}
		default:
			break;
		}
	}

	void Mover() {
		x += 0;
	}

	void AumentarColumnas() {
		if (vivo == true) {
			idcolumnas++;

		}
		if (idcolumnas > 2) {
			idcolumnas = 0;
		}

	}
	int getX() { return x; }
	int getY() { return y; }
	int getAlto() { return altoPersonaje; }
	int getAncho() { return anchoPersonaje; }

	void setVivo(bool vivo) { vivo = vivo; }
	void setVelocidad(int dy) { this->dy = dy; }
};