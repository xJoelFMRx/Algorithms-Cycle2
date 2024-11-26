#pragma once
#include "ControladoraAnimacionCalvo.h"

namespace Ejercicio3Semana13 {

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
			imgCalvo = gcnew Bitmap("calvo.png");
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
				delete imgCalvo;
			}
		}
	private: System::Windows::Forms::Timer^ timer1;
	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		Controladora^ controladora;
		Bitmap^ imgCalvo;

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
			this->ClientSize = System::Drawing::Size(884, 601);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseClick);
			this->ResumeLayout(false);
		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		controladora->LeerDatos();
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ g = this->CreateGraphics();
		BufferedGraphicsContext^ espacio = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer = espacio->Allocate(g, this->ClientRectangle);
		buffer->Graphics->Clear(Color::White);
		bool mensaje = controladora->getCalvo()->Mover(buffer->Graphics);
		if (mensaje)
		{
			MessageBox::Show("No puedes salir de la ventana!!", "Advertencia", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
		controladora->Iniciar(buffer->Graphics, imgCalvo);
		buffer->Render(g);
		delete buffer, espacio, g;
	}
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode)
		{
		case Keys::W: controladora->getCalvo()->setTecla(Arriba); break;
		case Keys::A: controladora->getCalvo()->setTecla(Izquierda); break;
		case Keys::S: controladora->getCalvo()->setTecla(Abajo); break;
		case Keys::D: controladora->getCalvo()->setTecla(Derecha); break;
		}
	}
	private: System::Void MyForm_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		controladora->AgregarCirculo(this->ClientSize.Width, this->ClientSize.Height);
	}
	};
}
