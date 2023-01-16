#pragma once
#include "Ave.h"
#include "arr_Obstaculos.h"
#include "Background.h"
#include "Base.h"
#include "Moneda.h"
#include "GameOver.h"
using namespace System;

class Juego {
	bool gameOver;
	int puntos;
	Ave* ave;
	Arr_Obstaculo* arreglo;
	background* mapa;
	Base* piso;
	Moneda* monedita;
	Gamve_over_P* gameOverC;
	bool vacio;
public:
	Juego(Bitmap^ imgAve, Bitmap^ imgMapa, Bitmap^ imgPiso, Bitmap^ imgTubo, Bitmap^ imgMoneda, Bitmap^ imgti, Bitmap^ imgGO) {
		arreglo = new Arr_Obstaculo();
		vacio = false;
		ave = new Ave(imgAve);
		mapa = new background(imgMapa);
		piso = new Base(imgPiso);
		gameOverC = new Gamve_over_P(imgGO, 50, 100);
		monedita = new Moneda(imgMoneda, 10, 10);
		agregar_tubos(imgTubo, imgMoneda, imgti, 8);
		puntos = 0;
		gameOver = false;
	}
	void Dibujar_ave(Bitmap^ img, Graphics^ L) {
		ave->DrawBird(img, L);
	}

	void gravedad() {
		ave->gravedad();
	}

	void Saltar_ave(System::Windows::Forms::KeyEventArgs^ e) {
		ave->Saltar(e);

	}

	///////////////////
	void Dibujar_mapa(Bitmap^ imgMapa, Graphics^ L) {
		mapa->draw(imgMapa, L);
	}
	////////////////////
	void Dibujar_Base(Bitmap^ imgpiso, Graphics^ L) {
		piso->draw(imgpiso, L);
	}
	void Mover_Base() {
		piso->Mover();
	}
	////////////////////


	void agregar_tubos(Bitmap^ imgTubo, Bitmap^ imgMoneda, Bitmap^ imgTi, int cantidad) {
		int x = 480;
		Random r;
		for (size_t i = 0; i < cantidad; i++)
		{
			arreglo->agregar_tubo(imgTubo, imgMoneda, imgTi, x, 240);
			arreglo->getTubo(i)->funciona_porfavorcito();
			x += r.Next(160, 250);
		}
	}

	void Verificar(Bitmap^ imgTubo, Bitmap^ imgMoneda, Bitmap^ imgTi, int cantidad) {
		if (arreglo->getSize() <= 3) {
			agregar_tubos(imgTubo, imgMoneda, imgTi, cantidad);

			for (size_t i = 0; i < arreglo->getSize(); i++)
			{
				cout << arreglo->getTubo(i)->getX() << endl;
			}
			cout << "fin del ciclo" << endl;
		}
	}

	void Dibujar_tubos(Bitmap^ img, Bitmap^ imgMoneda, Bitmap^ imgTi, Graphics^ L) {
		arreglo->Dibujar_tubos(img, imgMoneda, imgTi, L);
	}
	void Mover_tubos() {
		arreglo->Mover_tubos();
	}
	void Eliminar_tubos() {
		arreglo->Eliminar_tubos();
	}
	void DibujarCantidad(Graphics^ L) {
		L->DrawString(gcnew String("Numero de tubos: " + arreglo->getSize()), gcnew System::Drawing::Font("arial", 10), Brushes::Black, 10, 10);
	}
	void Dibujar_Puntos(Graphics^ L) {
		L->DrawString(gcnew String(puntos.ToString()), gcnew System::Drawing::Font("Alegrian", 20), Brushes::White, 120, 50);
	}

	///Moneda
	void MonedaDraw(Bitmap^ img, Graphics^ L) {
		monedita->Draw(img, L);
	}
	void Eliminar_Moneda() {
		arreglo->Eliminar_Monedas();
	}

	//////// colisiones

	void Colision_ave_moneda() {
		Rectangle Seccion_ave = Rectangle(ave->getX(), ave->getY(), ave->getAncho(), ave->getAlto());
		for (size_t i = 0; i < arreglo->getSize(); i++)
		{
			Rectangle seccion = Rectangle(arreglo->getTubo(i)->getMoneda()->getX(), arreglo->getTubo(i)->getMoneda()->getY(),
				arreglo->getTubo(i)->getMoneda()->getAnchoMoneda(), arreglo->getTubo(i)->getMoneda()->getAnchoMoneda());
			if (Seccion_ave.IntersectsWith(seccion)) {
				arreglo->getTubo(i)->getMoneda()->setEstado(true);
				puntos += 1;
				cout << "puntos: " << puntos << endl;
			}
		}
	}

	// mantenimiento
	void detener_tuvos() {
		for (size_t i = 0; i < arreglo->getSize(); i++)
		{
			arreglo->getTubo(i)->setDx(0);
		}
	}
	//////// imagen gameover


	void Game_over_Dibujar(Bitmap^ img, Graphics^ L) {
		if (gameOver == true) {
			gameOverC->draw(img, L);
		}
	}

	void Game_over_items() {
		gameOver = true;
		cout << "Perdiste webon" << endl;
		ave->setVelocidad(0);
		ave->muerto();
		piso->setDx(0);
		arreglo->detener_tubos();
		arreglo->detener_tubos_invertidos();
		arreglo->detener_Monedas();
	}

	void Colision_ave_tubos() {
		Rectangle Seccion_ave = Rectangle(ave->getX(), ave->getY(), ave->getAncho(), ave->getAlto());
		for (size_t i = 0; i < arreglo->getSize(); i++)
		{
			Rectangle seccion = Rectangle(arreglo->getTubo(i)->getX(), arreglo->getTubo(i)->getY(),
				arreglo->getTubo(i)->getAncho(), arreglo->getTubo(i)->getAlto());
			if (seccion.IntersectsWith(Seccion_ave)) {
				Game_over_items();
			}
		}
	}

	void colision_tuvos_invertidos() {
		cout << arreglo->getSize();
		Rectangle Seccion_ave = Rectangle(ave->getX(), ave->getY(), ave->getAncho(), ave->getAlto());
		for (size_t i = 0; i < arreglo->getSize(); i++)
		{
			Rectangle seccion = Rectangle(arreglo->getTubo(i)->getTuvo_Invertido()->getX() + 20, arreglo->getTubo(i)->getTuvo_Invertido()->getY(),
				arreglo->getTubo(i)->getTuvo_Invertido()->getAncho()/1.5, arreglo->getTubo(i)->getTuvo_Invertido()->getAlto()/1.5);
			if (seccion.IntersectsWith(Seccion_ave)) {
				Game_over_items();
			}
		}
	}
};