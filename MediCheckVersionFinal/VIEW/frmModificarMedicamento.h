#pragma once

namespace VIEW {
	using namespace MODEL;
	using namespace CONTROLLER;

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de frmModificarMedicamento
	/// </summary>
	public ref class frmModificarMedicamento : public System::Windows::Forms::Form
	{
	public:
		frmModificarMedicamento(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}
		frmModificarMedicamento(MedicamentoController^ medicamentoController, Medicamento^ medicamento)
		{
			InitializeComponent();
			this->medicamentoController = medicamentoController;
			this->medicamento = medicamento;
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmModificarMedicamento()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:









	private: MedicamentoController^ medicamentoController;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::ComboBox^ comboBox4;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::CheckBox^ checkBox1;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::ComboBox^ comboBox2;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Label^ label1;
	private: Medicamento^ medicamento;
	private: System::Windows::Forms::CheckBox^ checkBox3;
	private: System::Windows::Forms::CheckBox^ checkBox2;
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
			this->comboBox4 = (gcnew System::Windows::Forms::ComboBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->checkBox3);
			this->groupBox1->Controls->Add(this->checkBox2);
			this->groupBox1->Controls->Add(this->comboBox4);
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->checkBox1);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->comboBox2);
			this->groupBox1->Controls->Add(this->comboBox1);
			this->groupBox1->Controls->Add(this->button2);
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->textBox2);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->button4);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(9, 10);
			this->groupBox1->Margin = System::Windows::Forms::Padding(2);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(2);
			this->groupBox1->Size = System::Drawing::Size(231, 337);
			this->groupBox1->TabIndex = 4;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Modificar";
			this->groupBox1->Enter += gcnew System::EventHandler(this, &frmModificarMedicamento::groupBox1_Enter);
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->Location = System::Drawing::Point(113, 183);
			this->checkBox3->Margin = System::Windows::Forms::Padding(2);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(82, 17);
			this->checkBox3->TabIndex = 21;
			this->checkBox3->Text = L"Suplemento";
			this->checkBox3->UseVisualStyleBackColor = true;
			this->checkBox3->CheckedChanged += gcnew System::EventHandler(this, &frmModificarMedicamento::checkBox3_CheckedChanged);
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Location = System::Drawing::Point(6, 183);
			this->checkBox2->Margin = System::Windows::Forms::Padding(2);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(75, 17);
			this->checkBox2->TabIndex = 20;
			this->checkBox2->Text = L"Antibiotico";
			this->checkBox2->UseVisualStyleBackColor = true;
			this->checkBox2->CheckedChanged += gcnew System::EventHandler(this, &frmModificarMedicamento::checkBox2_CheckedChanged);
			// 
			// comboBox4
			// 
			this->comboBox4->FormattingEnabled = true;
			this->comboBox4->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"pequeño", L"mediano", L"grande" });
			this->comboBox4->Location = System::Drawing::Point(114, 255);
			this->comboBox4->Margin = System::Windows::Forms::Padding(2);
			this->comboBox4->Name = L"comboBox4";
			this->comboBox4->Size = System::Drawing::Size(92, 21);
			this->comboBox4->TabIndex = 19;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(4, 257);
			this->label6->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(92, 13);
			this->label6->TabIndex = 18;
			this->label6->Text = L"Tipo de Vitamina :";
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(7, 215);
			this->checkBox1->Margin = System::Windows::Forms::Padding(2);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(88, 17);
			this->checkBox1->TabIndex = 17;
			this->checkBox1->Text = L"Es Prioridad\?";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(4, 154);
			this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(37, 13);
			this->label4->TabIndex = 14;
			this->label4->Text = L"Tipo : ";
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Grande", L"Mediano", L"Pequeño" });
			this->comboBox2->Location = System::Drawing::Point(76, 110);
			this->comboBox2->Margin = System::Windows::Forms::Padding(2);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(92, 21);
			this->comboBox2->TabIndex = 13;
			// 
			// comboBox1
			// 
			this->comboBox1->Enabled = false;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"1", L"2", L"3", L"4" });
			this->comboBox1->Location = System::Drawing::Point(76, 26);
			this->comboBox1->Margin = System::Windows::Forms::Padding(2);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(92, 21);
			this->comboBox1->TabIndex = 12;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(7, 298);
			this->button2->Margin = System::Windows::Forms::Padding(2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(56, 23);
			this->button2->TabIndex = 11;
			this->button2->Text = L"Modificar";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &frmModificarMedicamento::button2_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(76, 298);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(56, 23);
			this->button1->TabIndex = 10;
			this->button1->Text = L"Cancelar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &frmModificarMedicamento::button1_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(4, 112);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(52, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Tamaño :";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(76, 69);
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
			this->label2->Size = System::Drawing::Size(53, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Nombre : ";
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(152, 298);
			this->button4->Margin = System::Windows::Forms::Padding(2);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(56, 23);
			this->button4->TabIndex = 3;
			this->button4->Text = L"Borrar";
			this->button4->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(4, 28);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(34, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"# ID :";
			// 
			// frmModificarMedicamento
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(251, 358);
			this->Controls->Add(this->groupBox1);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"frmModificarMedicamento";
			this->Text = L"frmModificarMedicamento";
			this->Load += gcnew System::EventHandler(this, &frmModificarMedicamento::frmModificarMedicamento_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	this->textBox2->Clear();
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	int codigo = Convert::ToInt32(this->comboBox1->Text);
	String^ nombre = this->textBox2->Text->Trim();
	String^ tamano = this->comboBox2->Text;

	if (nombre == "" || tamano == "") {
		MessageBox::Show("Complete todos los campos.");
		return;
	}
	if (tamano->ToUpper() != "PEQUEÑO" && tamano->ToUpper() != "MEDIANO" && tamano->ToUpper() != "GRANDE") {
		MessageBox::Show("Seleccione un tamaño valido: Pequeño, Mediano o Grande");
		return;
	}
	if (!this->checkBox2->Checked && !this->checkBox3->Checked) {
		MessageBox::Show("Seleccione un tipo de medicamento.");
		return;
	}

	if (this->checkBox2->Checked) {
		bool esPrioridad = this->checkBox1->Checked;
		Antibiotico^ med = gcnew Antibiotico(codigo, nombre, tamano, esPrioridad);
		this->medicamentoController->ActualizarArchivo(med);
	}
	else if (this->checkBox3->Checked) {
		String^ tipoVitamina = this->comboBox4->Text->Trim();
		if (tipoVitamina == "") {
			MessageBox::Show("Seleccione un tipo de vitamina.");
			return;
		}
		SuplementoVitaminico^ med = gcnew SuplementoVitaminico(codigo, nombre, tamano, tipoVitamina);
		this->medicamentoController->ActualizarArchivo(med);
	}

	MessageBox::Show("Medicamento Modificado exitosamente");
	this->Close();
}
private: System::Void frmModificarMedicamento_Load(System::Object^ sender, System::EventArgs^ e) {
	// deshabilitar ambos por defecto antes de cargar
    this->checkBox1->Enabled = false;
    this->comboBox4->Enabled = false;

    if (this->medicamento != nullptr) {
        this->comboBox1->Text = this->medicamento->getId().ToString();
        this->textBox2->Text = this->medicamento->getNombre();
        this->comboBox2->Text = this->medicamento->getTamano();

        Antibiotico^ ab = dynamic_cast<Antibiotico^>(this->medicamento);
        SuplementoVitaminico^ sv = dynamic_cast<SuplementoVitaminico^>(this->medicamento);

        if (ab != nullptr) {
            this->checkBox2->Checked = true;       // activa Antibiotico
            this->checkBox1->Enabled = true;
            this->checkBox1->Checked = ab->getEsPrioridadCritica();
        }
        else if (sv != nullptr) {
            this->checkBox3->Checked = true;       // activa Suplemento
            this->comboBox4->Enabled = true;
            this->comboBox4->Text = sv->getTipo();
        }
    }
}


	   private: System::Void checkBox2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		   if (this->checkBox2->Checked) {
			   this->checkBox3->Checked = false;
			   this->checkBox1->Enabled = true;
			   this->comboBox4->Enabled = false;
			   this->comboBox4->SelectedIndex = -1;
		   }
	   }

private: System::Void checkBox3_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox3->Checked) {
		this->checkBox2->Checked = false;
		this->checkBox1->Enabled = false;
		this->checkBox1->Checked = false;
		this->comboBox4->Enabled = true;
	}
}
private: System::Void groupBox1_Enter(System::Object^ sender, System::EventArgs^ e) {
}
};
}
