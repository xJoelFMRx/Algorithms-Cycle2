#pragma once
#include "FormularioConversion.h"

namespace EjercicioRetador2 {

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
		}
	private: System::Windows::Forms::Label^ labelAlgoritmos;
	private: System::Windows::Forms::Label^ labelUsuarioAdministrador;
	private: System::Windows::Forms::Label^ labelUsuario;
	private: System::Windows::Forms::Label^ labelContrase�a;
	private: System::Windows::Forms::TextBox^ textBoxUsuario;
	private: System::Windows::Forms::TextBox^ textBoxContrase�a;
	protected:

	protected:





	private: System::Windows::Forms::Button^ buttonIniciarSesion;
	private: System::Windows::Forms::PictureBox^ pictureOjoCerrado;
	private: System::Windows::Forms::PictureBox^ pictureOjoAbierto;











	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->labelAlgoritmos = (gcnew System::Windows::Forms::Label());
			this->labelUsuarioAdministrador = (gcnew System::Windows::Forms::Label());
			this->labelUsuario = (gcnew System::Windows::Forms::Label());
			this->labelContrase�a = (gcnew System::Windows::Forms::Label());
			this->textBoxUsuario = (gcnew System::Windows::Forms::TextBox());
			this->textBoxContrase�a = (gcnew System::Windows::Forms::TextBox());
			this->buttonIniciarSesion = (gcnew System::Windows::Forms::Button());
			this->pictureOjoCerrado = (gcnew System::Windows::Forms::PictureBox());
			this->pictureOjoAbierto = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureOjoCerrado))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureOjoAbierto))->BeginInit();
			this->SuspendLayout();
			// 
			// labelAlgoritmos
			// 
			this->labelAlgoritmos->AutoSize = true;
			this->labelAlgoritmos->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelAlgoritmos->Location = System::Drawing::Point(80, 77);
			this->labelAlgoritmos->Name = L"labelAlgoritmos";
			this->labelAlgoritmos->Size = System::Drawing::Size(109, 24);
			this->labelAlgoritmos->TabIndex = 0;
			this->labelAlgoritmos->Text = L"Algoritmos";
			// 
			// labelUsuarioAdministrador
			// 
			this->labelUsuarioAdministrador->AutoSize = true;
			this->labelUsuarioAdministrador->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelUsuarioAdministrador->Location = System::Drawing::Point(80, 134);
			this->labelUsuarioAdministrador->Name = L"labelUsuarioAdministrador";
			this->labelUsuarioAdministrador->Size = System::Drawing::Size(216, 24);
			this->labelUsuarioAdministrador->TabIndex = 1;
			this->labelUsuarioAdministrador->Text = L"Usuario Administrador";
			// 
			// labelUsuario
			// 
			this->labelUsuario->AutoSize = true;
			this->labelUsuario->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelUsuario->Location = System::Drawing::Point(80, 257);
			this->labelUsuario->Name = L"labelUsuario";
			this->labelUsuario->Size = System::Drawing::Size(81, 24);
			this->labelUsuario->TabIndex = 2;
			this->labelUsuario->Text = L"Usuario";
			// 
			// labelContrase�a
			// 
			this->labelContrase�a->AutoSize = true;
			this->labelContrase�a->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelContrase�a->Location = System::Drawing::Point(80, 305);
			this->labelContrase�a->Name = L"labelContrase�a";
			this->labelContrase�a->Size = System::Drawing::Size(116, 24);
			this->labelContrase�a->TabIndex = 3;
			this->labelContrase�a->Text = L"Contrase�a";
			// 
			// textBoxUsuario
			// 
			this->textBoxUsuario->Location = System::Drawing::Point(233, 257);
			this->textBoxUsuario->Multiline = true;
			this->textBoxUsuario->Name = L"textBoxUsuario";
			this->textBoxUsuario->Size = System::Drawing::Size(354, 24);
			this->textBoxUsuario->TabIndex = 4;
			this->textBoxUsuario->TextChanged += gcnew System::EventHandler(this, &MyForm::textBoxUsuario_TextChanged);
			// 
			// textBoxContrase�a
			// 
			this->textBoxContrase�a->Location = System::Drawing::Point(233, 305);
			this->textBoxContrase�a->Multiline = true;
			this->textBoxContrase�a->Name = L"textBoxContrase�a";
			this->textBoxContrase�a->PasswordChar = '*';
			this->textBoxContrase�a->Size = System::Drawing::Size(354, 24);
			this->textBoxContrase�a->TabIndex = 5;
			this->textBoxContrase�a->TextChanged += gcnew System::EventHandler(this, &MyForm::textBoxContrase�a_TextChanged);
			// 
			// buttonIniciarSesion
			// 
			this->buttonIniciarSesion->BackColor = System::Drawing::Color::Black;
			this->buttonIniciarSesion->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->buttonIniciarSesion->ForeColor = System::Drawing::Color::Transparent;
			this->buttonIniciarSesion->Location = System::Drawing::Point(554, 462);
			this->buttonIniciarSesion->Name = L"buttonIniciarSesion";
			this->buttonIniciarSesion->Size = System::Drawing::Size(118, 37);
			this->buttonIniciarSesion->TabIndex = 6;
			this->buttonIniciarSesion->Text = L"Iniciar Sesion";
			this->buttonIniciarSesion->UseVisualStyleBackColor = false;
			this->buttonIniciarSesion->Click += gcnew System::EventHandler(this, &MyForm::buttonIniciarSesion_Click);
			// 
			// pictureOjoCerrado
			// 
			this->pictureOjoCerrado->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureOjoCerrado.Image")));
			this->pictureOjoCerrado->Location = System::Drawing::Point(588, 305);
			this->pictureOjoCerrado->Name = L"pictureOjoCerrado";
			this->pictureOjoCerrado->Size = System::Drawing::Size(34, 24);
			this->pictureOjoCerrado->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->pictureOjoCerrado->TabIndex = 7;
			this->pictureOjoCerrado->TabStop = false;
			this->pictureOjoCerrado->Click += gcnew System::EventHandler(this, &MyForm::pictureOjoCerrado_Click);
			// 
			// pictureOjoAbierto
			// 
			this->pictureOjoAbierto->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureOjoAbierto.Image")));
			this->pictureOjoAbierto->Location = System::Drawing::Point(588, 305);
			this->pictureOjoAbierto->Name = L"pictureOjoAbierto";
			this->pictureOjoAbierto->Size = System::Drawing::Size(34, 24);
			this->pictureOjoAbierto->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->pictureOjoAbierto->TabIndex = 8;
			this->pictureOjoAbierto->TabStop = false;
			this->pictureOjoAbierto->Click += gcnew System::EventHandler(this, &MyForm::pictureOjoAbierto_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::DodgerBlue;
			this->ClientSize = System::Drawing::Size(716, 535);
			this->Controls->Add(this->pictureOjoAbierto);
			this->Controls->Add(this->pictureOjoCerrado);
			this->Controls->Add(this->buttonIniciarSesion);
			this->Controls->Add(this->textBoxContrase�a);
			this->Controls->Add(this->textBoxUsuario);
			this->Controls->Add(this->labelContrase�a);
			this->Controls->Add(this->labelUsuario);
			this->Controls->Add(this->labelUsuarioAdministrador);
			this->Controls->Add(this->labelAlgoritmos);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureOjoCerrado))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureOjoAbierto))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void textBoxUsuario_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		pictureOjoAbierto->BringToFront(); 
		textBoxContrase�a->PasswordChar = '*';  
	}
	private: System::Void textBoxContrase�a_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void buttonIniciarSesion_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ usuarioIngresado = textBoxUsuario->Text;
		String^ contrase�aIngresada = textBoxContrase�a->Text;

		String^ usuarioCorrecto = "joelfmr";
		String^ contrase�aCorrecta = "chanchitofeliz";

		if (usuarioIngresado == usuarioCorrecto && contrase�aIngresada == contrase�aCorrecta) {
			MessageBox::Show("Autenticaci�n exitosa!", "�xito", MessageBoxButtons::OK, MessageBoxIcon::Information);

			FormularioConversion^ conversionForm = gcnew FormularioConversion();
			conversionForm->Show();
		}
		else {
			MessageBox::Show("Usuario o contrase�a incorrectos", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	private: System::Void pictureOjoAbierto_Click(System::Object^ sender, System::EventArgs^ e) {
		pictureOjoCerrado->BringToFront();
		textBoxContrase�a->PasswordChar = '\0';
	}
private: System::Void pictureOjoCerrado_Click(System::Object^ sender, System::EventArgs^ e) {
	pictureOjoAbierto->BringToFront();
	textBoxContrase�a->PasswordChar = '*';
}
};
}
