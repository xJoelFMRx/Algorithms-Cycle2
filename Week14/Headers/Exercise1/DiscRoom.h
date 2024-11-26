#pragma once
#include "ControladoraDiscRoom.h"

namespace Ejercicio1Semana14 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			controladora = new Controladora();
			imgPersonaje = gcnew Bitmap("serena.png");
			imgEscenario = gcnew Bitmap("escenarioPasto.jpg");
			imgDisco = gcnew Bitmap("discos.png");
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se est�n usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
				delete controladora;
				delete imgPersonaje;
				delete imgEscenario;
				delete imgDisco;
			}
		}

	private:
		Controladora* controladora;
		Bitmap^ imgPersonaje;
		Bitmap^ imgEscenario;
		Bitmap^ imgDisco;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Label^ labelVidas;

	private: System::Windows::Forms::Label^ labelTiempo;



	private: System::ComponentModel::IContainer^ components;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// M�todo necesario para admitir el Dise�ador. No se puede modificar
		/// el contenido de este m�todo con el editor de c�digo.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->labelVidas = (gcnew System::Windows::Forms::Label());
			this->labelTiempo = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 50;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// labelVidas
			// 
			this->labelVidas->AutoSize = true;
			this->labelVidas->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelVidas->ForeColor = System::Drawing::Color::Red;
			this->labelVidas->Location = System::Drawing::Point(12, 9);
			this->labelVidas->Name = L"labelVidas";
			this->labelVidas->Size = System::Drawing::Size(59, 20);
			this->labelVidas->TabIndex = 2;
			this->labelVidas->Text = L"Vidas:";
			this->labelVidas->Click += gcnew System::EventHandler(this, &MyForm::labelVidas_Click);
			// 
			// labelTiempo
			// 
			this->labelTiempo->AutoSize = true;
			this->labelTiempo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelTiempo->ForeColor = System::Drawing::Color::Red;
			this->labelTiempo->Location = System::Drawing::Point(478, 9);
			this->labelTiempo->Name = L"labelTiempo";
			this->labelTiempo->Size = System::Drawing::Size(77, 20);
			this->labelTiempo->TabIndex = 3;
			this->labelTiempo->Text = L"Tiempo: ";
			this->labelTiempo->Click += gcnew System::EventHandler(this, &MyForm::labelTiempo_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(684, 561);
			this->Controls->Add(this->labelTiempo);
			this->Controls->Add(this->labelVidas);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyUp);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		controladora->LeerConfiguracion();
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		if (controladora->JuegoTerminado()) 
		{
			timer1->Enabled = false;
			if (controladora->JugadorGano())
			{
				MessageBox::Show("�GANASTE! Lograste sobrevivir al tiempo establecido.", "Victoria", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
			else 
			{
				MessageBox::Show("�PERDISTE! Te quedaste sin vidas.", "Derrota", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			Application::Exit();
			return;
		}
		//Actualiza las etiquetas con el tiempo y las vidas restantes
		labelTiempo->Text = "Tiempo: " + controladora->getTiempoJuego() + " segundos";
		labelVidas->Text = "Vidas: " + controladora->getPersonaje()->getVidas();
		//Creaci�n del objeto Graphics para la actualizaci�n de la pantalla
		Graphics^ g = this->CreateGraphics();
		BufferedGraphicsContext^ espacio = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer = espacio->Allocate(g, this->ClientRectangle);
		buffer->Graphics->Clear(Color::White);
		controladora->Iniciar(buffer->Graphics, imgPersonaje, imgEscenario, imgDisco);
		buffer->Render(g);
		delete buffer, espacio, g;
	}
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode)
		{
		case Keys::Left: controladora->getPersonaje()->setTecla(Izquierda); break;
		case Keys::Right: controladora->getPersonaje()->setTecla(Derecha); break;
		case Keys::Up: controladora->getPersonaje()->setTecla(Arriba); break;
		case Keys::Down: controladora->getPersonaje()->setTecla(Abajo); break;
		}
	}
	private: System::Void MyForm_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		controladora->getPersonaje()->setTecla(Ninguno);
	}
	private: System::Void labelTiempo_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void labelVidas_Click(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
