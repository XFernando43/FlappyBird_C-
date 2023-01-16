#pragma once
#include "Juego.h"
namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
		//Ave* ave;
		//Tubo* tubo;
		//background* mapa;
		SoundPlayer^ musica = gcnew SoundPlayer("musica.wav");
		Juego* juego;
	private: System::Windows::Forms::Timer^ timer1;
		   Bitmap^ imgAve = gcnew Bitmap("flappy.png");
		   Bitmap^ imgTubo = gcnew Bitmap("tubo.png");
		   Bitmap^ img_mapa = gcnew Bitmap("background-night.png");
		   Bitmap^ imgPiso = gcnew Bitmap("base.png");
		   Bitmap^ imgTI = gcnew Bitmap("tubo_invertido.jpg");
		   Bitmap^ imgMoneda = gcnew Bitmap("moneda.png");
		   Bitmap^ imgGO = gcnew Bitmap("gameover.png");
	public:
		MyForm(void)
		{
			InitializeComponent();
			//ave = new Ave(imgAve);
			//tubo = new Tubo(imgTubo,240);
			//mapa = new background(img_mapa);
			//piso = new Base(imgPiso);
			juego = new Juego(imgAve, img_mapa, imgPiso, imgTubo,imgMoneda, imgTI,imgGO);
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(384, 653);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion
	Void Sound() {
		musica->PlayLooping();
	}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		Sound();
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ g = this->CreateGraphics();
		BufferedGraphicsContext^ espacio = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer = espacio->Allocate(g, this->ClientRectangle);
		buffer->Graphics->Clear(Color::White);

		juego->Dibujar_mapa(img_mapa, buffer->Graphics);

		juego->Dibujar_Base(imgPiso, buffer->Graphics);
		juego->Mover_Base();

		juego->Dibujar_ave(imgAve, buffer->Graphics);
		juego->gravedad();

		juego->Dibujar_tubos(imgTubo, imgMoneda, imgTI, buffer->Graphics);

		juego->Mover_tubos();
		juego->Verificar(imgTubo, imgMoneda, imgTI,4);
		juego->Eliminar_tubos();

		juego->Eliminar_Moneda();

		juego->Colision_ave_moneda();
		juego->colision_tuvos_invertidos();
		juego->Colision_ave_tubos();

		juego->Game_over_Dibujar(imgGO, buffer->Graphics);
		juego->Dibujar_Puntos(buffer->Graphics);

		
		buffer->Render(g);
		delete buffer;
		delete espacio;
		delete g;
	}
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		juego->Saltar_ave(e);
	}
};
}
