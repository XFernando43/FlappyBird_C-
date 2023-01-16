#pragma once
#include <iostream>
#include "Moneda.h"
#include "tuvo_invertido.h"
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace System::Drawing::Drawing2D;
using namespace std;
class Obstaculo : CEntidad {
	bool estado;
	Moneda* monedita;
	tuvo_invertido* tuvo_I;
public:
	Obstaculo(Bitmap^ img, Bitmap^ imgMoneda, Bitmap^ imgTi, int x, int y) {
		monedita = new Moneda(imgMoneda, x, y - 50);
		tuvo_I = new tuvo_invertido(imgTi, x, y - 300);
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
	void Draw(Bitmap^ img, Bitmap^ imgMoneda, Bitmap^ imgTi,Graphics^ L) {
		Rectangle seccion = Rectangle(idcolumnas * anchoPersonaje, idfilas * altoPersonaje, anchoPersonaje, altoPersonaje);
		Rectangle Tamanho = Rectangle(x, y, anchoPersonaje / 1.5, altoPersonaje/1.5);
		L->DrawImage(img, Tamanho, seccion, GraphicsUnit::Pixel);
		monedita->Draw(imgMoneda, L);
		monedita->Mover();
		tuvo_I->Draw(imgTi, L);
		tuvo_I->Mover();
		Bandera_estado();
	}

	void Bandera_estado() {	if (x <= -10) {	estado = true;}}
	void Mover() {x -= dx;}
	void funciona_porfavorcito() {}
	bool getEstado() { return estado; }
	int getX() { return x; }
	int getY() { return y; }
	int getAlto() { return altoPersonaje; }
	int getAncho() { return anchoPersonaje; }
	Moneda* getMoneda() { return monedita; }
	tuvo_invertido* getTuvo_Invertido() { return tuvo_I; }
	void setDx(int dx) { this->dx = dx; }
};