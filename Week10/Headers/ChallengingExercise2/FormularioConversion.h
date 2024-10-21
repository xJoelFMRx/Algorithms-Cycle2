#pragma once

namespace EjercicioRetador2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FormularioConversion
	/// </summary>
	public ref class FormularioConversion : public System::Windows::Forms::Form
	{
	public:
		FormularioConversion(void)
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
		~FormularioConversion()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ labelCotizacion;
	private: System::Windows::Forms::Button^ buttonUnlock;
	private: System::Windows::Forms::TextBox^ textBoxCotEuro;
	private: System::Windows::Forms::TextBox^ textCotDolar;
	private: System::Windows::Forms::TextBox^ textCotPeso;
	protected:





	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textIngreEuro;
	private: System::Windows::Forms::TextBox^ textIngreDolar;
	private: System::Windows::Forms::TextBox^ textBoxIngrePeso;
	private: System::Windows::Forms::Button^ buttonFlecha1;
	private: System::Windows::Forms::Button^ buttonFlecha2;
	private: System::Windows::Forms::Button^ buttonFlecha3;






	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBoxEuroaEuro;
	private: System::Windows::Forms::TextBox^ textBoxDolaraEuro;
	private: System::Windows::Forms::TextBox^ textBoxPesoaEuro;




	private: System::Windows::Forms::TextBox^ textBoxEuroaDolar;
	private: System::Windows::Forms::TextBox^ textBoxDolaraDolar;
	private: System::Windows::Forms::TextBox^ textBoxPesoaDolar;



	private: System::Windows::Forms::TextBox^ textBoxEuroaPeso;
	private: System::Windows::Forms::TextBox^ textBoxDolaraPeso;
	private: System::Windows::Forms::TextBox^ textBoxPesoaPeso;



	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;

	protected:

	private:
		bool isUnlocked = false;
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->labelCotizacion = (gcnew System::Windows::Forms::Label());
			this->buttonUnlock = (gcnew System::Windows::Forms::Button());
			this->textBoxCotEuro = (gcnew System::Windows::Forms::TextBox());
			this->textCotDolar = (gcnew System::Windows::Forms::TextBox());
			this->textCotPeso = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textIngreEuro = (gcnew System::Windows::Forms::TextBox());
			this->textIngreDolar = (gcnew System::Windows::Forms::TextBox());
			this->textBoxIngrePeso = (gcnew System::Windows::Forms::TextBox());
			this->buttonFlecha1 = (gcnew System::Windows::Forms::Button());
			this->buttonFlecha2 = (gcnew System::Windows::Forms::Button());
			this->buttonFlecha3 = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBoxEuroaEuro = (gcnew System::Windows::Forms::TextBox());
			this->textBoxDolaraEuro = (gcnew System::Windows::Forms::TextBox());
			this->textBoxPesoaEuro = (gcnew System::Windows::Forms::TextBox());
			this->textBoxEuroaDolar = (gcnew System::Windows::Forms::TextBox());
			this->textBoxDolaraDolar = (gcnew System::Windows::Forms::TextBox());
			this->textBoxPesoaDolar = (gcnew System::Windows::Forms::TextBox());
			this->textBoxEuroaPeso = (gcnew System::Windows::Forms::TextBox());
			this->textBoxDolaraPeso = (gcnew System::Windows::Forms::TextBox());
			this->textBoxPesoaPeso = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// labelCotizacion
			// 
			this->labelCotizacion->AutoSize = true;
			this->labelCotizacion->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelCotizacion->Location = System::Drawing::Point(82, 33);
			this->labelCotizacion->Name = L"labelCotizacion";
			this->labelCotizacion->Size = System::Drawing::Size(89, 18);
			this->labelCotizacion->TabIndex = 0;
			this->labelCotizacion->Text = L"Cotizacion";
			// 
			// buttonUnlock
			// 
			this->buttonUnlock->Location = System::Drawing::Point(234, 32);
			this->buttonUnlock->Name = L"buttonUnlock";
			this->buttonUnlock->Size = System::Drawing::Size(75, 23);
			this->buttonUnlock->TabIndex = 1;
			this->buttonUnlock->Text = L"Unlock";
			this->buttonUnlock->UseVisualStyleBackColor = true;
			this->buttonUnlock->Click += gcnew System::EventHandler(this, &FormularioConversion::buttonUnlock_Click);
			// 
			// textBoxCotEuro
			// 
			this->textBoxCotEuro->Enabled = false;
			this->textBoxCotEuro->Location = System::Drawing::Point(382, 35);
			this->textBoxCotEuro->Name = L"textBoxCotEuro";
			this->textBoxCotEuro->Size = System::Drawing::Size(100, 20);
			this->textBoxCotEuro->TabIndex = 2;
			this->textBoxCotEuro->Text = L"0.92";
			// 
			// textCotDolar
			// 
			this->textCotDolar->Enabled = false;
			this->textCotDolar->Location = System::Drawing::Point(500, 35);
			this->textCotDolar->Name = L"textCotDolar";
			this->textCotDolar->Size = System::Drawing::Size(100, 20);
			this->textCotDolar->TabIndex = 3;
			this->textCotDolar->Text = L"1";
			// 
			// textCotPeso
			// 
			this->textCotPeso->Enabled = false;
			this->textCotPeso->Location = System::Drawing::Point(615, 35);
			this->textCotPeso->Name = L"textCotPeso";
			this->textCotPeso->Size = System::Drawing::Size(100, 20);
			this->textCotPeso->TabIndex = 4;
			this->textCotPeso->Text = L"0.011";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(12, 126);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(44, 18);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Euro";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(12, 169);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(49, 18);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Dolar";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(12, 215);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(47, 18);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Peso";
			// 
			// textIngreEuro
			// 
			this->textIngreEuro->Location = System::Drawing::Point(85, 124);
			this->textIngreEuro->Name = L"textIngreEuro";
			this->textIngreEuro->Size = System::Drawing::Size(100, 20);
			this->textIngreEuro->TabIndex = 8;
			// 
			// textIngreDolar
			// 
			this->textIngreDolar->Location = System::Drawing::Point(85, 169);
			this->textIngreDolar->Name = L"textIngreDolar";
			this->textIngreDolar->Size = System::Drawing::Size(100, 20);
			this->textIngreDolar->TabIndex = 9;
			// 
			// textBoxIngrePeso
			// 
			this->textBoxIngrePeso->Location = System::Drawing::Point(85, 213);
			this->textBoxIngrePeso->Name = L"textBoxIngrePeso";
			this->textBoxIngrePeso->Size = System::Drawing::Size(100, 20);
			this->textBoxIngrePeso->TabIndex = 10;
			// 
			// buttonFlecha1
			// 
			this->buttonFlecha1->Location = System::Drawing::Point(227, 122);
			this->buttonFlecha1->Name = L"buttonFlecha1";
			this->buttonFlecha1->Size = System::Drawing::Size(103, 23);
			this->buttonFlecha1->TabIndex = 11;
			this->buttonFlecha1->Text = L"- >";
			this->buttonFlecha1->UseVisualStyleBackColor = true;
			this->buttonFlecha1->Click += gcnew System::EventHandler(this, &FormularioConversion::buttonFlecha1_Click);
			// 
			// buttonFlecha2
			// 
			this->buttonFlecha2->Location = System::Drawing::Point(227, 169);
			this->buttonFlecha2->Name = L"buttonFlecha2";
			this->buttonFlecha2->Size = System::Drawing::Size(103, 23);
			this->buttonFlecha2->TabIndex = 12;
			this->buttonFlecha2->Text = L"- >";
			this->buttonFlecha2->UseVisualStyleBackColor = true;
			this->buttonFlecha2->Click += gcnew System::EventHandler(this, &FormularioConversion::buttonFlecha2_Click);
			// 
			// buttonFlecha3
			// 
			this->buttonFlecha3->Location = System::Drawing::Point(227, 213);
			this->buttonFlecha3->Name = L"buttonFlecha3";
			this->buttonFlecha3->Size = System::Drawing::Size(103, 23);
			this->buttonFlecha3->TabIndex = 13;
			this->buttonFlecha3->Text = L"- >";
			this->buttonFlecha3->UseVisualStyleBackColor = true;
			this->buttonFlecha3->Click += gcnew System::EventHandler(this, &FormularioConversion::buttonFlecha3_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(409, 92);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(44, 18);
			this->label5->TabIndex = 14;
			this->label5->Text = L"Euro";
			// 
			// textBoxEuroaEuro
			// 
			this->textBoxEuroaEuro->Enabled = false;
			this->textBoxEuroaEuro->Location = System::Drawing::Point(382, 124);
			this->textBoxEuroaEuro->Name = L"textBoxEuroaEuro";
			this->textBoxEuroaEuro->Size = System::Drawing::Size(100, 20);
			this->textBoxEuroaEuro->TabIndex = 15;
			// 
			// textBoxDolaraEuro
			// 
			this->textBoxDolaraEuro->Enabled = false;
			this->textBoxDolaraEuro->Location = System::Drawing::Point(382, 169);
			this->textBoxDolaraEuro->Name = L"textBoxDolaraEuro";
			this->textBoxDolaraEuro->Size = System::Drawing::Size(100, 20);
			this->textBoxDolaraEuro->TabIndex = 16;
			// 
			// textBoxPesoaEuro
			// 
			this->textBoxPesoaEuro->Enabled = false;
			this->textBoxPesoaEuro->Location = System::Drawing::Point(382, 213);
			this->textBoxPesoaEuro->Name = L"textBoxPesoaEuro";
			this->textBoxPesoaEuro->Size = System::Drawing::Size(100, 20);
			this->textBoxPesoaEuro->TabIndex = 17;
			// 
			// textBoxEuroaDolar
			// 
			this->textBoxEuroaDolar->Enabled = false;
			this->textBoxEuroaDolar->Location = System::Drawing::Point(500, 124);
			this->textBoxEuroaDolar->Name = L"textBoxEuroaDolar";
			this->textBoxEuroaDolar->Size = System::Drawing::Size(100, 20);
			this->textBoxEuroaDolar->TabIndex = 18;
			// 
			// textBoxDolaraDolar
			// 
			this->textBoxDolaraDolar->Enabled = false;
			this->textBoxDolaraDolar->Location = System::Drawing::Point(500, 169);
			this->textBoxDolaraDolar->Name = L"textBoxDolaraDolar";
			this->textBoxDolaraDolar->Size = System::Drawing::Size(100, 20);
			this->textBoxDolaraDolar->TabIndex = 19;
			// 
			// textBoxPesoaDolar
			// 
			this->textBoxPesoaDolar->Enabled = false;
			this->textBoxPesoaDolar->Location = System::Drawing::Point(500, 213);
			this->textBoxPesoaDolar->Name = L"textBoxPesoaDolar";
			this->textBoxPesoaDolar->Size = System::Drawing::Size(100, 20);
			this->textBoxPesoaDolar->TabIndex = 20;
			// 
			// textBoxEuroaPeso
			// 
			this->textBoxEuroaPeso->Enabled = false;
			this->textBoxEuroaPeso->Location = System::Drawing::Point(615, 124);
			this->textBoxEuroaPeso->Name = L"textBoxEuroaPeso";
			this->textBoxEuroaPeso->Size = System::Drawing::Size(100, 20);
			this->textBoxEuroaPeso->TabIndex = 21;
			// 
			// textBoxDolaraPeso
			// 
			this->textBoxDolaraPeso->Enabled = false;
			this->textBoxDolaraPeso->Location = System::Drawing::Point(615, 169);
			this->textBoxDolaraPeso->Name = L"textBoxDolaraPeso";
			this->textBoxDolaraPeso->Size = System::Drawing::Size(100, 20);
			this->textBoxDolaraPeso->TabIndex = 22;
			// 
			// textBoxPesoaPeso
			// 
			this->textBoxPesoaPeso->Enabled = false;
			this->textBoxPesoaPeso->Location = System::Drawing::Point(615, 213);
			this->textBoxPesoaPeso->Name = L"textBoxPesoaPeso";
			this->textBoxPesoaPeso->Size = System::Drawing::Size(100, 20);
			this->textBoxPesoaPeso->TabIndex = 23;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(527, 92);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(49, 18);
			this->label6->TabIndex = 24;
			this->label6->Text = L"Dolar";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(641, 92);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(47, 18);
			this->label7->TabIndex = 25;
			this->label7->Text = L"Peso";
			// 
			// FormularioConversion
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(757, 275);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->textBoxPesoaPeso);
			this->Controls->Add(this->textBoxDolaraPeso);
			this->Controls->Add(this->textBoxEuroaPeso);
			this->Controls->Add(this->textBoxPesoaDolar);
			this->Controls->Add(this->textBoxDolaraDolar);
			this->Controls->Add(this->textBoxEuroaDolar);
			this->Controls->Add(this->textBoxPesoaEuro);
			this->Controls->Add(this->textBoxDolaraEuro);
			this->Controls->Add(this->textBoxEuroaEuro);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->buttonFlecha3);
			this->Controls->Add(this->buttonFlecha2);
			this->Controls->Add(this->buttonFlecha1);
			this->Controls->Add(this->textBoxIngrePeso);
			this->Controls->Add(this->textIngreDolar);
			this->Controls->Add(this->textIngreEuro);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textCotPeso);
			this->Controls->Add(this->textCotDolar);
			this->Controls->Add(this->textBoxCotEuro);
			this->Controls->Add(this->buttonUnlock);
			this->Controls->Add(this->labelCotizacion);
			this->Name = L"FormularioConversion";
			this->Text = L"FormularioConversion";
			this->Load += gcnew System::EventHandler(this, &FormularioConversion::FormularioConversion_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void FormularioConversion_Load(System::Object^ sender, System::EventArgs^ e) {
		textBoxDolaraDolar->Enabled = false;
		textBoxDolaraEuro->Enabled = false;
		textBoxDolaraPeso->Enabled = false;
		textBoxEuroaDolar->Enabled = false;
		textBoxEuroaEuro->Enabled = false;
		textBoxEuroaPeso->Enabled = false;
		textBoxPesoaDolar->Enabled = false;
		textBoxPesoaPeso->Enabled = false;
		textBoxPesoaEuro->Enabled = false;
		textBoxCotEuro->Enabled = false;
		textCotDolar->Enabled = false;
		textCotPeso->Enabled = false;
	}
	private: System::Void buttonUnlock_Click(System::Object^ sender, System::EventArgs^ e) {
		if (isUnlocked) {
			textBoxCotEuro->Enabled = false;
			textCotDolar->Enabled = false;
			textCotPeso->Enabled = false;

			textIngreEuro->Enabled = true;
			textIngreDolar->Enabled = true;
			textBoxIngrePeso->Enabled = true;

			buttonUnlock->Text = "Unlock";

			isUnlocked = false;
		}
		else {
			textBoxCotEuro->Enabled = true;
			textCotDolar->Enabled = true;
			textCotPeso->Enabled = true;

			textIngreEuro->Enabled = true;
			textIngreDolar->Enabled = true;
			textBoxIngrePeso->Enabled = true;

			buttonUnlock->Text = "Lock";

			isUnlocked = true;
		}
	}
	private: System::Void buttonFlecha1_Click(System::Object^ sender, System::EventArgs^ e) {
		double cotizacionEuro = Convert::ToDouble(textBoxCotEuro->Text);
		double cotizacionDolar = Convert::ToDouble(textCotDolar->Text);
		double cotizacionPeso = Convert::ToDouble(textCotPeso->Text);

		double cantidadEuro = Convert::ToDouble(textIngreEuro->Text);

		double euroAEuro = cantidadEuro;
		double euroADolar = cantidadEuro / cotizacionEuro * cotizacionDolar;
		double euroAPeso = cantidadEuro / cotizacionEuro * cotizacionPeso;

		textBoxEuroaEuro->Text = euroAEuro.ToString();
		textBoxEuroaDolar->Text = euroADolar.ToString();
		textBoxEuroaPeso->Text = euroAPeso.ToString();
	}
	private: System::Void buttonFlecha2_Click(System::Object^ sender, System::EventArgs^ e) {
		double cotizacionEuro = Convert::ToDouble(textBoxCotEuro->Text);
		double cotizacionDolar = Convert::ToDouble(textCotDolar->Text);
		double cotizacionPeso = Convert::ToDouble(textCotPeso->Text);

		double cantidadDolar = Convert::ToDouble(textIngreDolar->Text);

		double dolarAEuro = cantidadDolar / cotizacionDolar * cotizacionEuro;
		double dolarADolar = cantidadDolar;
		double dolarAPeso = cantidadDolar / cotizacionDolar * cotizacionPeso;

		textBoxDolaraEuro->Text = dolarAEuro.ToString();
		textBoxDolaraDolar->Text = dolarADolar.ToString();
		textBoxDolaraPeso->Text = dolarAPeso.ToString();
	}
	private: System::Void buttonFlecha3_Click(System::Object^ sender, System::EventArgs^ e) {
		double cotizacionEuro = Convert::ToDouble(textBoxCotEuro->Text);
		double cotizacionDolar = Convert::ToDouble(textCotDolar->Text);
		double cotizacionPeso = Convert::ToDouble(textCotPeso->Text);

		double cantidadPeso = Convert::ToDouble(textBoxIngrePeso->Text);

		double pesoAEuro = cantidadPeso / cotizacionPeso * cotizacionEuro;
		double pesoADolar = cantidadPeso / cotizacionPeso * cotizacionDolar;
		double pesoAPeso = cantidadPeso;

		textBoxPesoaEuro->Text = pesoAEuro.ToString();
		textBoxPesoaDolar->Text = pesoADolar.ToString();
		textBoxPesoaPeso->Text = pesoAPeso.ToString();
	}
	};
}
