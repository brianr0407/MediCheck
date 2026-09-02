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
	/// Resumen de frmAgregarMedicamento
	/// </summary>
	public ref class frmAgregarMedicamento : public System::Windows::Forms::Form
	{
	public:
		frmAgregarMedicamento(void)
		{
			InitializeComponent();
			this->medicamentoController = gcnew MedicamentoController();
		}
		frmAgregarMedicamento(MedicamentoController^ medicamentoController)
		{
			InitializeComponent();
			this->medicamentoController = medicamentoController;
			
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmAgregarMedicamento()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^ groupBox1;
	protected:
	private: Medicamento^ medicamento;

	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Label^ label1;
	private: MedicamentoController^ medicamentoController;



	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::ComboBox^ comboBox4;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::CheckBox^ checkBox3;
	private: System::Windows::Forms::CheckBox^ checkBox2;
	private: System::Windows::Forms::CheckBox^ checkBox6;
	private: System::Windows::Forms::CheckBox^ checkBox5;
	private: System::Windows::Forms::CheckBox^ checkBox4;

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
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->comboBox4 = (gcnew System::Windows::Forms::ComboBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->checkBox4 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox5 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox6 = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->checkBox6);
			this->groupBox1->Controls->Add(this->checkBox5);
			this->groupBox1->Controls->Add(this->checkBox4);
			this->groupBox1->Controls->Add(this->checkBox3);
			this->groupBox1->Controls->Add(this->checkBox2);
			this->groupBox1->Controls->Add(this->label7);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->comboBox4);
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->checkBox1);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->comboBox1);
			this->groupBox1->Controls->Add(this->button2);
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->textBox2);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->button4);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(12, 12);
			this->groupBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->groupBox1->Size = System::Drawing::Size(305, 415);
			this->groupBox1->TabIndex = 3;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Agregar";
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->Location = System::Drawing::Point(177, 196);
			this->checkBox3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(101, 20);
			this->checkBox3->TabIndex = 23;
			this->checkBox3->Text = L"Suplemento";
			this->checkBox3->UseVisualStyleBackColor = true;
			this->checkBox3->CheckedChanged += gcnew System::EventHandler(this, &frmAgregarMedicamento::checkBox3_CheckedChanged);
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Location = System::Drawing::Point(56, 196);
			this->checkBox2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(91, 20);
			this->checkBox2->TabIndex = 22;
			this->checkBox2->Text = L"Antibiotico";
			this->checkBox2->UseVisualStyleBackColor = true;
			this->checkBox2->CheckedChanged += gcnew System::EventHandler(this, &frmAgregarMedicamento::checkBox2_CheckedChanged);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(4, 290);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(118, 16);
			this->label7->TabIndex = 21;
			this->label7->Text = L"Si es Suplemento :";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(5, 251);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(108, 16);
			this->label5->TabIndex = 20;
			this->label5->Text = L"Si es Antibiotico :";
			// 
			// comboBox4
			// 
			this->comboBox4->FormattingEnabled = true;
			this->comboBox4->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"pequeño", L"mediano", L"grande" });
			this->comboBox4->Location = System::Drawing::Point(151, 320);
			this->comboBox4->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->comboBox4->Name = L"comboBox4";
			this->comboBox4->Size = System::Drawing::Size(121, 24);
			this->comboBox4->TabIndex = 19;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(30, 323);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(115, 16);
			this->label6->TabIndex = 18;
			this->label6->Text = L"Tipo de Vitamina :";
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(128, 250);
			this->checkBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(110, 20);
			this->checkBox1->TabIndex = 17;
			this->checkBox1->Text = L"Es Prioridad\?";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(4, 200);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(44, 16);
			this->label4->TabIndex = 14;
			this->label4->Text = L"Tipo : ";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"1", L"2", L"3", L"4" });
			this->comboBox1->Location = System::Drawing::Point(101, 32);
			this->comboBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 24);
			this->comboBox1->TabIndex = 12;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(9, 367);
			this->button2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 28);
			this->button2->TabIndex = 11;
			this->button2->Text = L"Agregar";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &frmAgregarMedicamento::button2_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(110, 367);
			this->button1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 28);
			this->button1->TabIndex = 10;
			this->button1->Text = L"Cancelar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &frmAgregarMedicamento::button1_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(5, 123);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(64, 16);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Tamaño :";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(101, 81);
			this->textBox2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(121, 22);
			this->textBox2->TabIndex = 5;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(5, 85);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(65, 16);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Nombre : ";
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(205, 367);
			this->button4->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 28);
			this->button4->TabIndex = 3;
			this->button4->Text = L"Borrar";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &frmAgregarMedicamento::button4_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(5, 34);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(36, 16);
			this->label1->TabIndex = 0;
			this->label1->Text = L"# ID :";
			// 
			// checkBox4
			// 
			this->checkBox4->AutoSize = true;
			this->checkBox4->Location = System::Drawing::Point(101, 123);
			this->checkBox4->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->checkBox4->Name = L"checkBox4";
			this->checkBox4->Size = System::Drawing::Size(74, 20);
			this->checkBox4->TabIndex = 24;
			this->checkBox4->Text = L"Grande";
			this->checkBox4->UseVisualStyleBackColor = true;
			// 
			// checkBox5
			// 
			this->checkBox5->AutoSize = true;
			this->checkBox5->Location = System::Drawing::Point(208, 123);
			this->checkBox5->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->checkBox5->Name = L"checkBox5";
			this->checkBox5->Size = System::Drawing::Size(82, 20);
			this->checkBox5->TabIndex = 25;
			this->checkBox5->Text = L"Mediano";
			this->checkBox5->UseVisualStyleBackColor = true;
			// 
			// checkBox6
			// 
			this->checkBox6->AutoSize = true;
			this->checkBox6->Location = System::Drawing::Point(101, 147);
			this->checkBox6->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->checkBox6->Name = L"checkBox6";
			this->checkBox6->Size = System::Drawing::Size(84, 20);
			this->checkBox6->TabIndex = 26;
			this->checkBox6->Text = L"Pequeño";
			this->checkBox6->UseVisualStyleBackColor = true;
			// 
			// frmAgregarMedicamento
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(326, 439);
			this->Controls->Add(this->groupBox1);
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"frmAgregarMedicamento";
			this->Text = L"frmAgregarMedicamento";
			this->Load += gcnew System::EventHandler(this, &frmAgregarMedicamento::frmAgregarMedicamento_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			//cambio de eventos para checkboxes de tipo y tamaño
			this->checkBox4->CheckedChanged += gcnew System::EventHandler(this, &frmAgregarMedicamento::checkBox4_CheckedChanged);
			this->checkBox5->CheckedChanged += gcnew System::EventHandler(this, &frmAgregarMedicamento::checkBox5_CheckedChanged);
			this->checkBox6->CheckedChanged += gcnew System::EventHandler(this, &frmAgregarMedicamento::checkBox6_CheckedChanged);

		}
#pragma endregion
		private: System::Void frmAgregarMedicamento_Load(System::Object^ sender, System::EventArgs^ e) {
			this->checkBox1->Enabled = false;  // Es Prioridad deshabilitado
			this->comboBox4->Enabled = false;  // Tipo Vitamina deshabilitado

			// verificar limite antes de abrir
			if (!this->medicamentoController->PuedeAgregarMedicamento()) {
				MessageBox::Show("Ya existen 4 medicamentos registrados, limite alcanzado.");
				this->Close();
				return;
			}

			// ID automatico, deshabilitar comboBox1
			int siguienteId = this->medicamentoController->ObtenerSiguienteId();
			this->comboBox1->Text = siguienteId.ToString();
			this->comboBox1->Enabled = false;
		}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		this->textBox2->Clear();
	}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	int codigo = Convert::ToInt32(this->comboBox1->Text);

	if (this->medicamentoController->BuscarMedicamentoPorIdTXT(codigo) != nullptr) {
		MessageBox::Show("ID ya utilizado, elija otro.");
		return;
	}
	String^ nombre = this->textBox2->Text->Trim();

	if (nombre == "" ) {
		MessageBox::Show("Complete todos los campos");
		return;
	}
	if (!this->checkBox2->Checked && !this->checkBox3->Checked) {
		MessageBox::Show("Seleccione un tipo de medicamento.");
		return;
	}
	
	// Obtener tamaño de los checkboxes
	String^ tamano = "";
	if (this->checkBox4->Checked) tamano = "grande";
	else if (this->checkBox5->Checked) tamano = "mediano";
	else if (this->checkBox6->Checked) tamano = "pequeño";

	if (tamano == "") {
		MessageBox::Show("Seleccione un tamaño: Grande, Mediano o Pequeño.");
		return;
	}

	if (this->checkBox2->Checked) {
		bool esPrioridad = this->checkBox1->Checked;
		Antibiotico^ med = gcnew Antibiotico(codigo, nombre, tamano, esPrioridad);
		if (!this->medicamentoController->AgregarMedicamentoTXT(med)) {
			MessageBox::Show("No se pudo agregar el medicamento. Verifique que aun exista espacio para 4 medicamentos.");
			return;
		}
	}
	else if (this->checkBox3->Checked) {
		String^ tipoVitamina = this->comboBox4->Text->Trim();
		if (tipoVitamina == "") {
			MessageBox::Show("Seleccione un tipo de vitamina.");
			return;
		}
		SuplementoVitaminico^ med = gcnew SuplementoVitaminico(codigo, nombre, tamano, tipoVitamina);
		if (!this->medicamentoController->AgregarMedicamentoTXT(med)) {
			MessageBox::Show("No se pudo agregar el medicamento. Verifique que aun exista espacio para 4 medicamentos.");
			return;
		}
	}
	MessageBox::Show("Medicamento agregado exitosamente");
	this->Close();

}


	   private: System::Void checkBox2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		   if (this->checkBox2->Checked) {
			   this->checkBox3->Checked = false;
			   this->checkBox1->Enabled = true;   // habilitar Es Prioridad
			   this->comboBox4->Enabled = false;  // deshabilitar Tipo Vitamina
			   this->comboBox4->SelectedIndex = -1;
		   }
	   }

private: System::Void checkBox3_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox3->Checked) {
		this->checkBox2->Checked = false;
		this->checkBox1->Enabled = false;  // deshabilitar Es Prioridad
		this->checkBox1->Checked = false;
		this->comboBox4->Enabled = true;   // habilitar Tipo Vitamina
	}
}

	   private: System::Void checkBox4_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		   if (this->checkBox4->Checked) {
			   this->checkBox5->Checked = false;
			   this->checkBox6->Checked = false;
		   }
	   }

private: System::Void checkBox5_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox5->Checked) {
		this->checkBox4->Checked = false;
		this->checkBox6->Checked = false;
	}
}

private: System::Void checkBox6_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox6->Checked) {
		this->checkBox4->Checked = false;
		this->checkBox5->Checked = false;
	}
}



};
}
