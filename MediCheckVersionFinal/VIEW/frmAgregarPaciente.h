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
	/// Resumen de frmAgregarPaciente
	/// </summary>
	public ref class frmAgregarPaciente : public System::Windows::Forms::Form
	{
	public:
		frmAgregarPaciente(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

		frmAgregarPaciente(PacienteController^ pacienteController)
		{
			InitializeComponent();
			this->pacienteController =  pacienteController;
			//
			//TODO: agregar código de constructor aquí
			//
		}
	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmAgregarPaciente()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::CheckBox^ checkBox2;
	private: System::Windows::Forms::CheckBox^ checkBox1;

	private: PacienteController^ pacienteController;
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->checkBox2);
			this->groupBox1->Controls->Add(this->checkBox1);
			this->groupBox1->Controls->Add(this->textBox5);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->button2);
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->textBox3);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->textBox2);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->button4);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(9, 10);
			this->groupBox1->Margin = System::Windows::Forms::Padding(2);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(2);
			this->groupBox1->Size = System::Drawing::Size(230, 295);
			this->groupBox1->TabIndex = 2;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Agregar";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(117, 197);
			this->textBox5->Margin = System::Windows::Forms::Padding(2);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(76, 20);
			this->textBox5->TabIndex = 13;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(4, 199);
			this->label5->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(108, 15);
			this->label5->TabIndex = 12;
			this->label5->Text = L"Dias de Estancia : ";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(76, 259);
			this->button2->Margin = System::Windows::Forms::Padding(2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(56, 23);
			this->button2->TabIndex = 11;
			this->button2->Text = L"Agregar";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &frmAgregarPaciente::button2_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(147, 259);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(56, 23);
			this->button1->TabIndex = 10;
			this->button1->Text = L"Cancelar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &frmAgregarPaciente::button1_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(4, 141);
			this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(102, 15);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Tipo de Paciente:";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(117, 110);
			this->textBox3->Margin = System::Windows::Forms::Padding(2);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(76, 20);
			this->textBox3->TabIndex = 7;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(4, 112);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(60, 15);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Apellido : ";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(117, 69);
			this->textBox2->Margin = System::Windows::Forms::Padding(2);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(76, 20);
			this->textBox2->TabIndex = 5;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(4, 72);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(61, 15);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Nombre : ";
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(7, 259);
			this->button4->Margin = System::Windows::Forms::Padding(2);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(56, 23);
			this->button4->TabIndex = 3;
			this->button4->Text = L"Borrar";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &frmAgregarPaciente::button4_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(117, 26);
			this->textBox1->Margin = System::Windows::Forms::Padding(2);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(76, 20);
			this->textBox1->TabIndex = 0;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &frmAgregarPaciente::textBox1_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(20, 28);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 15);
			this->label1->TabIndex = 0;
			this->label1->Text = L"# ID :";
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(17, 171);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(97, 19);
			this->checkBox1->TabIndex = 15;
			this->checkBox1->Text = L"Permanente";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Location = System::Drawing::Point(117, 170);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(82, 19);
			this->checkBox2->TabIndex = 16;
			this->checkBox2->Text = L"Temporal";
			this->checkBox2->UseVisualStyleBackColor = true;
			// 
			// frmAgregarPaciente
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(250, 311);
			this->Controls->Add(this->groupBox1);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"frmAgregarPaciente";
			this->Text = L"frmAgregarPaciente";
			this->Load += gcnew System::EventHandler(this, &frmAgregarPaciente::frmAgregarPaciente_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &frmAgregarPaciente::checkBox1_CheckedChanged);
			this->checkBox2->CheckedChanged += gcnew System::EventHandler(this, &frmAgregarPaciente::checkBox2_CheckedChanged);

		}
#pragma endregion
	private: System::Void frmAgregarPaciente_Load(System::Object^ sender, System::EventArgs^ e) {
		int siguienteId = this->pacienteController->ObtenerSiguienteId();
		this->textBox1->Text = siguienteId.ToString();
		this->textBox1->Enabled = false; // solo lectura, el ID es automatico
		this->textBox5->Enabled = false;

	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		int codigo = this->pacienteController->ObtenerSiguienteId();
		CronogramaToma^ cronogramaToma = gcnew CronogramaToma();
		int j = 0;

		String^ nombre = this->textBox2->Text->Trim();
		String^ apellido = this->textBox3->Text->Trim();

		if (nombre == "" || apellido == "") {
			MessageBox::Show("Complete todos los campos.");
			return;
		}

		if (!this->checkBox1->Checked && !this->checkBox2->Checked) {
			MessageBox::Show("Seleccione un tipo de paciente.");
			return;
		}


		if (this->checkBox1->Checked) {
			Paciente^ paciente = gcnew Paciente(codigo, nombre, apellido, 1, true, cronogramaToma);
			this->pacienteController->AgregarPacienteTXT(paciente);
		}
		else if (this->checkBox2->Checked) {
			if (this->textBox5->Text->Trim() == "") {
				MessageBox::Show("Ingrese los dias de estancia.");
				return;
			}
			int diasEstancia;
			if (!Int32::TryParse(this->textBox5->Text, diasEstancia)) {
				MessageBox::Show("Ingrese un valor valido para dias de estancia.");
				return;
			}
			PacienteInvitado^ paciente = gcnew PacienteInvitado(codigo, nombre, apellido, 1, true, cronogramaToma, diasEstancia);
			this->pacienteController->AgregarPacienteTXT(paciente);
		}
		

		MessageBox::Show("Paciente agregado exitosamente");
		this->Close();
		
	}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	this->textBox1->Clear();
	this->textBox2->Clear();
	this->textBox3->Clear();
}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}

	   private: System::Void checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		   if (this->checkBox1->Checked) {
			   this->checkBox2->Checked = false;
			   this->textBox5->Enabled = false;
			   this->textBox5->Clear();
		   }
	   }

private: System::Void checkBox2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox2->Checked) {
		this->checkBox1->Checked = false;
		this->textBox5->Enabled = true;
	}
}
};
}
