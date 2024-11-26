#pragma once
#include "ControladoraAnimacionCarro.h"

namespace Ejercicio1Semana13 {

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
			controladora = gcnew Controladora();
			imgCarro = gcnew Bitmap("carro.png");
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
				delete imgCarro;
			}
		}
	private: System::Windows::Forms::Timer^ timer1;
	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		Controladora^ controladora;
		Bitmap^ imgCarro;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// M�todo necesario para admitir el Dise�ador. No se puede modificar
		/// el contenido de este m�todo con el editor de c�digo.
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
			this->timer1->Interval = 60;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(684, 561);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		controladora->LeerDatosDesdeArchivo();
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ g = this->CreateGraphics();
		BufferedGraphicsContext^ espacio = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer = espacio->Allocate(g, this->ClientRectangle);
		buffer->Graphics->Clear(Color::SkyBlue);
		controladora->Iniciar(buffer->Graphics, imgCarro);
		buffer->Render(g);
		delete buffer, espacio, g;
	}
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode)
		{
		case Keys::V: controladora->getCarro()->setAnimacion(ArbolV); controladora->IncrementarContadorVerde(); controladora->GenerarPosicionesArbolesVerdes(); break;
		case Keys::R: controladora->getCarro()->setAnimacion(ArbolR); controladora->IncrementarContadorRojo(); controladora->GenerarPosicionesArbolesRojos(); break;
		case Keys::P: controladora->getCarro()->setAnimacion(Libre); controladora->LimpiarArboles(); break;
		case Keys::F: 
			timer1->Enabled = false;
			String^ reporte = String::Format("Reporte:\nCamino �rboles verdes: {0}\nCamino �rboles rojos: {1}", controladora->getContadorVerde(), controladora->getContadorRojo());
			MessageBox::Show(reporte, "Reporte Final", MessageBoxButtons::OK, MessageBoxIcon::Information);
			Application::Exit();
			break;
		}
	}
	};
}
