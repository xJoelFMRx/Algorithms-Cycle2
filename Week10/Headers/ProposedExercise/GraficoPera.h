#pragma once

namespace PeraEjercicioPropuesto {

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
			//
			//TODO: agregar c�digo de constructor aqu�
			//
		}
		void DibujarTrianguloGrandeAmarrillo(PaintEventArgs^ e)
		{
			//Triangulo Grande Amarrillo
			array<Point>^ puntos = { Point(220,220),Point(190,250), Point(220,280) };
			SolidBrush::Brush^ brocha = gcnew SolidBrush(Color::Yellow);
			e->Graphics->FillPolygon(brocha, puntos);
		}
		void DibujarTrianguloGrandeVerde(PaintEventArgs^ e)
		{
			//Triangulo Grande Verde
			array<Point>^ puntos1 = { Point(220,220),Point(250,250), Point(220,280) };
			SolidBrush::Brush^ brocha1 = gcnew SolidBrush(Color::Green);
			e->Graphics->FillPolygon(brocha1, puntos1);
		}
		void DibujarTrianguloChicoVerdeClaro(PaintEventArgs^ e)
		{
			//Triangulo Chico Verde Claro
			array<Point>^ puntos2 = { Point(250,250),Point(250,220), Point(220,220) };
			SolidBrush::Brush^ brocha2 = gcnew SolidBrush(Color::GreenYellow);
			e->Graphics->FillPolygon(brocha2, puntos2);
		}
		void DibujarTrianguloChicoAnaranjado(PaintEventArgs^ e)
		{
			//Triangulo Chico Anaranjado
			array<Point>^ puntos3 = { Point(190,250),Point(190,220), Point(205,235) };
			SolidBrush::Brush^ brocha3 = gcnew SolidBrush(Color::Orange);
			e->Graphics->FillPolygon(brocha3, puntos3);
		}
		void DibujarCuadradoChicoRojo(PaintEventArgs^ e)
		{
			//Triangulo Arriba Rojo del Cuadrado
			array<Point>^ puntos4 = { Point(220,220),Point(190,220), Point(205,205) };
			SolidBrush::Brush^ brocha4 = gcnew SolidBrush(Color::Red);
			e->Graphics->FillPolygon(brocha4, puntos4);

			//Triangulo Abajo Rojo del Cuadrado
			array<Point>^ puntos5 = { Point(205,235),Point(220,220), Point(190,220) };
			SolidBrush::Brush^ brocha5 = gcnew SolidBrush(Color::Red);
			e->Graphics->FillPolygon(brocha5, puntos5);
		}
		void DibujarTrianguloChicoCeleste(PaintEventArgs^ e)
		{
			//Triangulo Chico Celeste
			array<Point>^ puntos6 = { Point(220,220),Point(250,220), Point(235,205) };
			SolidBrush::Brush^ brocha6 = gcnew SolidBrush(Color::LightSkyBlue);
			e->Graphics->FillPolygon(brocha6, puntos6);
		}
		void DibujarParalelogramoGrandeAzul(PaintEventArgs^ e)
		{
			//Triangulo Abajo Paralelogramo
			array<Point>^ puntos7 = { Point(217,200),Point(220,220), Point(235,196) };
			SolidBrush::Brush^ brocha7 = gcnew SolidBrush(Color::Blue);
			e->Graphics->FillPolygon(brocha7, puntos7);

			//Triangulo Arriba Paralelogramo
			array<Point>^ puntos8 = { Point(217,200),Point(232,170), Point(235,196) };
			SolidBrush::Brush^ brocha8 = gcnew SolidBrush(Color::Blue);
			e->Graphics->FillPolygon(brocha8, puntos8);
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
			}
		}

	private:
		/// <summary>
		/// Variable del dise�ador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// M�todo necesario para admitir el Dise�ador. No se puede modificar
		/// el contenido de este m�todo con el editor de c�digo.
		/// </summary>
		void InitializeComponent(void)
		{
			this->SuspendLayout();
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(499, 443);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::frmPath_Paint);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void frmPath_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		DibujarTrianguloGrandeAmarrillo(e);
		DibujarTrianguloGrandeVerde(e);
		DibujarTrianguloChicoVerdeClaro(e);
		DibujarTrianguloChicoAnaranjado(e);
		DibujarCuadradoChicoRojo(e);
		DibujarTrianguloChicoCeleste(e);
		DibujarParalelogramoGrandeAzul(e);
	}
	};
}
