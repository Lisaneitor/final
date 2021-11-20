#pragma once
#include "Juego.h"
#include "MyForm2.h"
#include "MyForm3.h"
#include "MyForm4.h"

namespace KirbyRecycleDeluxe {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			// Archivos de los sprites

			// Deberia ser juego
			bmpAnaconda = gcnew Bitmap("sprites\\snake.png");
			bmpArana = gcnew Bitmap("sprites\\spider.png");
			bmpBasura = gcnew Bitmap("sprites\\trash.png");
			bmpCondor = gcnew Bitmap("sprites\\condor.png");
			bmpCushuro = gcnew Bitmap("sprites\\cushuro.png");
			bmpFruta = gcnew Bitmap("sprites\\fruit.png");
			bmpGranizo = gcnew Bitmap("sprites\\granizo.png");
			bmpKirbyHielo = gcnew Bitmap("sprites\\kirby_ice.png");
			bmpKirbyNada = gcnew Bitmap("sprites\\kirby_swim.png");
			bmpKirbyVuela = gcnew Bitmap("sprites\\kirby_fly.png");
			bmpKirbyFuego = gcnew Bitmap("sprites\\kirby_fire.png");
			bmpPez = gcnew Bitmap("sprites\\pez.png");
			bmpPirana = gcnew Bitmap("sprites\\piranha.png");
			bmpPulpo = gcnew Bitmap("sprites\\calamar_cabeza.png");
			bmpTenta = gcnew Bitmap("sprites\\calamar_brazo.png");
			bala = gcnew Bitmap("sprites\\fire.jpg");
			heart = gcnew Bitmap("sprites\\heart.png");

			// Fondos 
			bmpCosta = gcnew Bitmap("sprites\\underwater.png");
			bmpSierra = gcnew Bitmap("sprites\\sierra.png");
			bmpSelva = gcnew Bitmap("sprites\\selva.png");

			objJuego = new Juego();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
			// Eliminar variables
			delete objJuego, bmpAnaconda, bmpArana, bmpBasura, bmpCondor, bmpCushuro, bmpFruta, bmpGranizo,
				bmpKirbyHielo, bmpKirbyNada, bmpKirbyVuela, bmpPez, bmpPirana, bmpPulpo,
				bmpCosta, bmpSelva, bmpSierra, bmpTenta, bmpKirbyFuego, bala, heart;
		}
	private: System::Windows::Forms::Timer^ timer1;
	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		// Inicializar variables
		// Aca deberia ser Juego, no selva
		Juego* objJuego;
		Bitmap^ bmpAnaconda;
		Bitmap^ bmpArana;
		Bitmap^ bmpBasura;
		Bitmap^ bmpCondor;
		Bitmap^ bmpCushuro;
		Bitmap^ bmpFruta;
		Bitmap^ bmpGranizo;
		Bitmap^ bmpKirbyVuela;
		Bitmap^ bmpKirbyNada;
		Bitmap^ bmpKirbyHielo;
		Bitmap^ bmpKirbyFuego;
		Bitmap^ bmpPez;
		Bitmap^ bmpPirana;
		Bitmap^ bmpPulpo;
		Bitmap^ bmpTenta;
		Bitmap^ bala;
		Bitmap^ heart;

		// Fondos
		Bitmap^ bmpCosta;
		Bitmap^ bmpSelva;
		Bitmap^ bmpSierra;
		String^ nombre_jugador;
	private: System::Windows::Forms::Label^ lbPuntos;
	private: System::Windows::Forms::Timer^ timer2;
	private: System::Windows::Forms::Timer^ timer3;
	private: System::Windows::Forms::Timer^ timer4;
	private: System::Windows::Forms::Label^ lbTiempo;




#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// Required method for Designer support - do not modify
		   /// the contents of this method with the code editor.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   this->components = (gcnew System::ComponentModel::Container());
			   this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			   this->lbPuntos = (gcnew System::Windows::Forms::Label());
			   this->lbTiempo = (gcnew System::Windows::Forms::Label());
			   this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			   this->timer3 = (gcnew System::Windows::Forms::Timer(this->components));
			   this->timer4 = (gcnew System::Windows::Forms::Timer(this->components));
			   this->SuspendLayout();
			   // 
			   // timer1
			   // 
			   this->timer1->Enabled = true;
			   this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			   // 
			   // lbPuntos
			   // 
			   this->lbPuntos->AutoSize = true;
			   this->lbPuntos->ImageAlign = System::Drawing::ContentAlignment::TopRight;
			   this->lbPuntos->Location = System::Drawing::Point(953, 92);
			   this->lbPuntos->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->lbPuntos->Name = L"lbPuntos";
			   this->lbPuntos->Size = System::Drawing::Size(35, 13);
			   this->lbPuntos->TabIndex = 0;
			   this->lbPuntos->Text = L"label1";
			   // 
			   // lbTiempo
			   // 
			   this->lbTiempo->AutoSize = true;
			   this->lbTiempo->ImageAlign = System::Drawing::ContentAlignment::TopRight;
			   this->lbTiempo->Location = System::Drawing::Point(1045, 92);
			   this->lbTiempo->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->lbTiempo->Name = L"lbTiempo";
			   this->lbTiempo->Size = System::Drawing::Size(35, 13);
			   this->lbTiempo->TabIndex = 1;
			   this->lbTiempo->Text = L"label2";
			   // 
			   // timer2
			   // 
			   this->timer2->Enabled = true;
			   this->timer2->Tick += gcnew System::EventHandler(this, &MyForm::timer2_Tick);
			   // 
			   // timer3
			   // 
			   this->timer3->Enabled = true;
			   this->timer3->Tick += gcnew System::EventHandler(this, &MyForm::timer3_Tick);
			   // 
			   // timer4
			   // 
			   this->timer4->Enabled = true;
			   this->timer4->Tick += gcnew System::EventHandler(this, &MyForm::timer4_Tick);
			   // 
			   // MyForm
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->BackColor = System::Drawing::SystemColors::ControlLightLight;
			   this->ClientSize = System::Drawing::Size(1118, 513);
			   this->Controls->Add(this->lbTiempo);
			   this->Controls->Add(this->lbPuntos);
			   this->ForeColor = System::Drawing::SystemColors::ControlText;
			   this->Margin = System::Windows::Forms::Padding(2);
			   this->Name = L"MyForm";
			   this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			   this->Text = L"MyForm";
			   this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			   this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			   this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion
	public: void cambiar_nombre_jugador(String^ nuevo)
	{
		nombre_jugador = nuevo;
	}
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		int nivel = objJuego->getNivel();
		if (e->KeyCode == Keys::Left)
			objJuego->Desplazar(dir::left);
		if (e->KeyCode == Keys::Right)
			objJuego->Desplazar(dir::right);
		if (e->KeyCode == Keys::Up)
			objJuego->Desplazar(dir::up);
		if (e->KeyCode == Keys::Down)
			objJuego->Desplazar(dir::down);
		if (e->KeyCode == Keys::Space)
			objJuego->Disparar(bmpKirbyFuego);
		if (e->KeyCode == Keys::Enter)
		{
			if (nivel == 2)
			{
				MyForm3^ Nsierra = gcnew MyForm3();
				Nsierra->Close();
				timer1->Enabled = true;
			}
			if (nivel == 1)
			{
				MyForm2^ Ncosta = gcnew MyForm2();
				Ncosta->Close();
				timer1->Enabled = true;
			}
			if (nivel == 3)
			{
				MyForm3^ Nsierra = gcnew MyForm3();
				Nsierra->Close();
				timer1->Enabled = true;
			}
		}
		// le pasa el bmp de kirby
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		System::String^ puntos = "Puntos: " + (objJuego->getContador());
		lbPuntos->Text = puntos;

		System::String^ tiempo = "Tiempo: " + (objJuego->getTiempo()) + "s";
		lbTiempo->Text = tiempo;
		
		Graphics^ g = CreateGraphics();
		BufferedGraphicsContext^ espacio = BufferedGraphicsManager::Current;
		BufferedGraphics^ bf = espacio->Allocate(g, ClientRectangle);

		// Variable que obtenga en que nivel esta ahora el juego
		int nivel = objJuego->getNivel();

		// Fondos
		if (nivel == 1)
			bf->Graphics->DrawImage(bmpCosta, ClientRectangle,
				Rectangle(0, 0, bmpCosta->Width, bmpCosta->Height), GraphicsUnit::Pixel);
		if (nivel == 2)
			bf->Graphics->DrawImage(bmpSierra, ClientRectangle,
				Rectangle(0, 0, bmpSierra->Width, bmpSierra->Height), GraphicsUnit::Pixel);
		if (nivel == 3)
			bf->Graphics->DrawImage(bmpSelva, ClientRectangle,
				Rectangle(0, 0, bmpSelva->Width, bmpSelva->Height), GraphicsUnit::Pixel);

		objJuego->DrawVidas(bf->Graphics, heart);

				// el Forms evalua en que nivel esta el juego
		if (!objJuego->getFin()) {
			if (nivel == 1)
				objJuego->Jugar_Costa(bf->Graphics, bmpPez, bmpPulpo,
					bmpTenta, bmpKirbyNada, bmpBasura);
			if (nivel == 2)
				objJuego->Jugar_Sierra(bf->Graphics, bmpCushuro, bmpGranizo,
					bmpCondor, bmpKirbyVuela, bmpKirbyHielo, bmpBasura);
			if (nivel == 3)
				objJuego->Jugar_Selva(bf->Graphics, bmpFruta, bmpAnaconda, bmpArana,
					bmpPirana, bmpKirbyVuela, bmpKirbyFuego, bmpBasura, bala);
		}
		else {
			if (objJuego->getGanador()) {
				if (nivel == 1 || nivel == 2)
					objJuego->setNivel();
				if (nivel == 3) {
					objJuego->Resumen(bf->Graphics);
					timer1->Enabled = false;
					vector<string> datosgrabar;
					char auxiliar[100];
					sprintf(auxiliar, "%s", nombre_jugador);
					datosgrabar.push_back(auxiliar);
					objJuego->GrabarResultado(datosgrabar);
				}
			}
			else {
				objJuego->Resumen(bf->Graphics);
				timer1->Enabled = false;
				vector<string> datosgrabar;
				char auxiliar[100];
				sprintf(auxiliar, "%s", nombre_jugador);
				datosgrabar.push_back(auxiliar);
				objJuego->GrabarResultado(datosgrabar);
			}
		}
		bf->Render(g);
		delete bf, espacio, g;
	}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void timer2_Tick(System::Object^ sender, System::EventArgs^ e) {
		int nivel = objJuego->getNivel();
		MyForm2^ Ncosta = gcnew MyForm2();
		if (!objJuego->getFin()) {
			if (nivel == 1) {
				timer1->Enabled = false;
				timer2->Enabled = false;
				Ncosta->Show();
			}
		}
	}
private: System::Void timer3_Tick(System::Object^ sender, System::EventArgs^ e) {
	int nivel = objJuego->getNivel();
	MyForm3^ Nsierra = gcnew MyForm3();

	if (!objJuego->getFin()) {

		if (nivel == 2)
		{
			timer1->Enabled = false;
			timer3->Enabled = false;
			Nsierra->Show();
		}
	}
}
private: System::Void timer4_Tick(System::Object^ sender, System::EventArgs^ e) {
	
	int nivel = objJuego->getNivel();
	MyForm4^ Nselva = gcnew MyForm4();

	if (!objJuego->getFin()) {
		if (nivel == 3) {
			timer1->Enabled = false;
			timer4->Enabled = false;
			Nselva->Show();

		}
	}
}
};
}
