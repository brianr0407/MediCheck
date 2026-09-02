#pragma once

namespace VIEW {
	using namespace MODEL;
	using namespace CONTROLLER;
	using namespace System::Collections::Generic;

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de frmAgregarAdmin
	/// </summary>
	public ref class frmAgregarAdmin : public System::Windows::Forms::Form
	{
	public:
		frmAgregarAdmin(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}
		frmAgregarAdmin(AdminController^ adminController)
		{
			InitializeComponent();
			this->adminController = adminController;
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmAgregarAdmin()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^ groupBox1;
	protected:
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;
	private: AdminController^ adminController;

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
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->textBox4);
			this->groupBox1->Controls->Add(this->button2);
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Controls->Add(this->textBox3);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->textBox2);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->button4);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(21, 23);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(294, 286);
			this->groupBox1->TabIndex = 4;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Agregar";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(6, 187);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(35, 16);
			this->label4->TabIndex = 13;
			this->label4->Text = L"PIN :";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(132, 181);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(100, 22);
			this->textBox4->TabIndex = 12;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(7, 232);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 28);
			this->button2->TabIndex = 11;
			this->button2->Text = L"Agregar";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &frmAgregarAdmin::button2_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(102, 232);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 28);
			this->button1->TabIndex = 10;
			this->button1->Text = L"Cancelar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &frmAgregarAdmin::button1_Click);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(132, 135);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 22);
			this->textBox3->TabIndex = 7;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(6, 138);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(66, 16);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Apellido : ";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(132, 85);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 22);
			this->textBox2->TabIndex = 5;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(6, 88);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(65, 16);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Nombre : ";
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(200, 232);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 28);
			this->button4->TabIndex = 3;
			this->button4->Text = L"Borrar";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &frmAgregarAdmin::button4_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(132, 32);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 22);
			this->textBox1->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(26, 35);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(36, 16);
			this->label1->TabIndex = 0;
			this->label1->Text = L"# ID :";
			// 
			// frmAgregarAdmin
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(338, 342);
			this->Controls->Add(this->groupBox1);
			this->Name = L"frmAgregarAdmin";
			this->Text = L"frmAgregarAdmin";
			this->Load += gcnew System::EventHandler(this, &frmAgregarAdmin::frmAgregarAdmin_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void frmAgregarAdmin_Load(System::Object^ sender, System::EventArgs^ e) {
		int siguienteId = this->adminController->ObtenerSiguienteId();
		this->textBox1->Text = siguienteId.ToString();
		this->textBox1->Enabled = false; // solo lectura, el ID es automatico
	}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();

}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	this->textBox1->Clear();
	this->textBox2->Clear();

	this->textBox3->Clear();
	this->textBox4->Clear();
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	int codigo = this->adminController->ObtenerSiguienteId();
	
	// Verificar ID unico
	if (this->adminController->BuscarAdministradorPorIdTXT(codigo) != nullptr) {
		MessageBox::Show("ID ya utilizado, elija otro.");
		return;
	}

	String^ nombre = this->textBox2->Text->Trim();
	String^ apellido = this->textBox3->Text->Trim();
	int pin = Convert::ToInt32(this->textBox4->Text);

	if (nombre == "" || apellido == "") {
		MessageBox::Show("Complete todos los campos");
		return;
	}

	Administrador^ admin = gcnew Administrador(codigo, nombre, apellido, pin);
	this->adminController->AgregarAdministradorTXT(admin);
	MessageBox::Show("Administrador agregado exitosamente");
	this->Close();

}
};
}
