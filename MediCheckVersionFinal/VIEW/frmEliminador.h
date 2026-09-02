#pragma once

namespace VIEW {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de frmEliminador
	/// </summary>
	public ref class frmEliminador : public System::Windows::Forms::Form
	{
	public:
		frmEliminador(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}
		frmEliminador(String^ mensaje)
		{

			InitializeComponent();
			this->mensaje = mensaje;

			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmEliminador()
		{
			if (components)
			{
				delete components;
			}
		}
	private: String^ mensaje;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->button2);
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Location = System::Drawing::Point(0, 0);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(304, 208);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Eliminar";
			// 
			// label1
			// 
			this->label1->Location = System::Drawing::Point(34, 50);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(240, 80);
			this->label1->TabIndex = 2;
			this->label1->Text = L"label1";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(177, 148);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Cancelar";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &frmEliminador::button2_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(37, 148);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Aceptar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &frmEliminador::button1_Click);
			// 
			// frmEliminador
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(318, 216);
			this->Controls->Add(this->groupBox1);
			this->Name = L"frmEliminador";
			this->Text = L"frmEliminador";
			this->Load += gcnew System::EventHandler(this, &frmEliminador::frmEliminador_Load);
			this->groupBox1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void frmEliminador_Load(System::Object^ sender, System::EventArgs^ e) {
		this->label1->Text = this->mensaje;
	}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	this->DialogResult = System::Windows::Forms::DialogResult::OK;
	this->Close();
}


private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	this->DialogResult = System::Windows::Forms::DialogResult::Cancel;
	this->Close();
}
};
}
