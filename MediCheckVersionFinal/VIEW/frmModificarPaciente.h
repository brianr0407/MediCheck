#pragma once

namespace VIEW {

	using namespace System;
	using namespace MODEL;
	using namespace CONTROLLER;

	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de frmModificarPaciente
	/// </summary>
	public ref class frmModificarPaciente : public System::Windows::Forms::Form
	{
	public:
		frmModificarPaciente(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}
		frmModificarPaciente(PacienteController^ pacienteController, Paciente^ paciente)
		{
			InitializeComponent();
			this->pacienteController = pacienteController;
			this->paciente = paciente;
			//
			//TODO: agregar código de constructor aquí
			//
		}
	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmModificarPaciente()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^ groupBox1;
	protected:
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;
	private: PacienteController^ pacienteController;
	private: Paciente^ paciente;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::Label^ label5;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::CheckBox^ checkBox2;
	private: System::Windows::Forms::CheckBox^ checkBox1;

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
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
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
			this->groupBox1->Controls->Add(this->checkBox2);
			this->groupBox1->Controls->Add(this->checkBox1);
			this->groupBox1->Controls->Add(this->textBox5);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->button2);
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Controls->Add(this->textBox3);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->textBox2);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->button4);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(12, 12);
			this->groupBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->groupBox1->Size = System::Drawing::Size(300, 353);
			this->groupBox1->TabIndex = 5;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Modoficar";
			this->groupBox1->Enter += gcnew System::EventHandler(this, &frmModificarPaciente::groupBox1_Enter);
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Location = System::Drawing::Point(139, 214);
			this->checkBox2->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(88, 20);
			this->checkBox2->TabIndex = 17;
			this->checkBox2->Text = L"Temporal";
			this->checkBox2->UseVisualStyleBackColor = true;
			this->checkBox2->CheckedChanged += gcnew System::EventHandler(this, &frmModificarPaciente::checkBox2_CheckedChanged);
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(12, 214);
			this->checkBox1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(102, 20);
			this->checkBox1->TabIndex = 16;
			this->checkBox1->Text = L"Permanente";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &frmModificarPaciente::checkBox1_CheckedChanged);
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(132, 257);
			this->textBox5->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(100, 22);
			this->textBox5->TabIndex = 15;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(5, 261);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(99, 16);
			this->label5->TabIndex = 14;
			this->label5->Text = L"Dias Estancia : ";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(5, 180);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(116, 16);
			this->label4->TabIndex = 12;
			this->label4->Text = L"Tipo de Paciente: ";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(12, 305);
			this->button2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 28);
			this->button2->TabIndex = 11;
			this->button2->Text = L"Modificar";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &frmModificarPaciente::button2_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(109, 305);
			this->button1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 28);
			this->button1->TabIndex = 10;
			this->button1->Text = L"Cancelar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &frmModificarPaciente::button1_Click);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(132, 135);
			this->textBox3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 22);
			this->textBox3->TabIndex = 7;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(5, 138);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(66, 16);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Apellido : ";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(132, 85);
			this->textBox2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 22);
			this->textBox2->TabIndex = 5;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(5, 89);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(65, 16);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Nombre : ";
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(203, 305);
			this->button4->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 28);
			this->button4->TabIndex = 3;
			this->button4->Text = L"Borrar";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &frmModificarPaciente::button4_Click);
			// 
			// textBox1
			// 
			this->textBox1->Enabled = false;
			this->textBox1->Location = System::Drawing::Point(132, 32);
			this->textBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 22);
			this->textBox1->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(5, 34);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(105, 16);
			this->label1->TabIndex = 0;
			this->label1->Text = L"# ID a modificar :";
			// 
			// frmModificarPaciente
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(325, 379);
			this->Controls->Add(this->groupBox1);
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"frmModificarPaciente";
			this->Text = L"frmModificarPaciente";
			this->Load += gcnew System::EventHandler(this, &frmModificarPaciente::frmModificarPaciente_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void frmModificarPaciente_Load(System::Object^ sender, System::EventArgs^ e) {

		this->textBox1->Text = Convert::ToString(this->paciente->getId());
		this->textBox2->Text = this->paciente->getNombre();
		this->textBox3->Text = this->paciente->getApellido();

		PacienteInvitado^ invitado = dynamic_cast<PacienteInvitado^>(this->paciente);
		if (invitado != nullptr) {
			this->checkBox2->Checked = true;   // Temporal
			this->textBox5->Text = Convert::ToString(invitado->getDiasEstancia());
			this->textBox5->Enabled = true;
		}
		else {
			this->checkBox1->Checked = true;   // Permanente
			this->textBox5->Enabled = false;
		}
	}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	this->textBox1->Clear();
	this->textBox2->Clear();
	this->textBox3->Clear();
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	int codigo = Convert::ToInt32(this->textBox1->Text);
	if (this->pacienteController->BuscarPacientePorIdTXT(codigo) != nullptr) {

		String^ nombre = this->textBox2->Text;
		String^ apellido = this->textBox3->Text;

		CronogramaTomaController^ cronogramaTomaController = gcnew CronogramaTomaController();
		CronogramaToma^ cronogramaToma = cronogramaTomaController->BuscarCronogramaPorIdTXT(codigo);

		if (this->checkBox1->Checked) {
			Paciente^ paciente = gcnew Paciente(codigo, nombre, apellido, 1, true, cronogramaToma);
			this->pacienteController->ActualizarArchivo(paciente);
		}
		else if (this->checkBox2->Checked) {
			int diasEstancia = Convert::ToInt32(this->textBox5->Text);
			PacienteInvitado^ paciente = gcnew PacienteInvitado(codigo, nombre, apellido, 1, true, cronogramaToma, diasEstancia);
			this->pacienteController->ActualizarArchivo(paciente);
		}
		else {
			MessageBox::Show("Seleccione un tipo de paciente.");
			return;
		}

		MessageBox::Show("Paciente Modificado exitosamente");
		this->Close();
	}
	else {
		MessageBox::Show("No existe el Paciente con ID: [" + codigo + "]");
	}
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
private: System::Void groupBox1_Enter(System::Object^ sender, System::EventArgs^ e) {
}
};
}
