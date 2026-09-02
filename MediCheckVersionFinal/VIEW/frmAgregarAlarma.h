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
	/// Resumen de frmAgregarAlarma
	/// </summary>
	public ref class frmAgregarAlarma : public System::Windows::Forms::Form
	{
	public:
		frmAgregarAlarma(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}
		frmAgregarAlarma(AlarmaController^ alarmaController)
		{
			InitializeComponent();
			this->alarmaController = alarmaController;
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmAgregarAlarma()
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

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;
	private: AlarmaController^ alarmaController;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::CheckBox^ checkBox2;
	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::TextBox^ textBox3;

	protected:












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
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
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
			this->groupBox1->Controls->Add(this->textBox3);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->checkBox2);
			this->groupBox1->Controls->Add(this->checkBox1);
			this->groupBox1->Controls->Add(this->button2);
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->textBox2);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->button4);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(11, 8);
			this->groupBox1->Margin = System::Windows::Forms::Padding(2);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(2);
			this->groupBox1->Size = System::Drawing::Size(231, 227);
			this->groupBox1->TabIndex = 5;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Agregar";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(136, 138);
			this->textBox3->Margin = System::Windows::Forms::Padding(2);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(76, 20);
			this->textBox3->TabIndex = 15;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(26, 141);
			this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(99, 13);
			this->label4->TabIndex = 14;
			this->label4->Text = L"Tiempo de Espera :";
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Location = System::Drawing::Point(145, 99);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(57, 17);
			this->checkBox2->TabIndex = 13;
			this->checkBox2->Text = L"Crítica";
			this->checkBox2->UseVisualStyleBackColor = true;
			this->checkBox2->CheckedChanged += gcnew System::EventHandler(this, &frmAgregarAlarma::checkBox2_CheckedChanged);
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(75, 100);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(62, 17);
			this->checkBox1->TabIndex = 12;
			this->checkBox1->Text = L"Snooze";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &frmAgregarAlarma::checkBox1_CheckedChanged);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(10, 190);
			this->button2->Margin = System::Windows::Forms::Padding(2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(56, 23);
			this->button2->TabIndex = 11;
			this->button2->Text = L"Agregar";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &frmAgregarAlarma::button2_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(81, 190);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(56, 23);
			this->button1->TabIndex = 10;
			this->button1->Text = L"Cancelar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &frmAgregarAlarma::button1_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(26, 99);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(34, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Tipo :";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(105, 57);
			this->textBox2->Margin = System::Windows::Forms::Padding(2);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(76, 20);
			this->textBox2->TabIndex = 5;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(26, 64);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(46, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Estado :";
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(156, 190);
			this->button4->Margin = System::Windows::Forms::Padding(2);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(56, 23);
			this->button4->TabIndex = 3;
			this->button4->Text = L"Borrar";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &frmAgregarAlarma::button4_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(105, 26);
			this->textBox1->Margin = System::Windows::Forms::Padding(2);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(76, 20);
			this->textBox1->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(26, 28);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(34, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"# ID :";
			this->label1->Click += gcnew System::EventHandler(this, &frmAgregarAlarma::label1_Click);
			// 
			// frmAgregarAlarma
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(265, 246);
			this->Controls->Add(this->groupBox1);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"frmAgregarAlarma";
			this->Text = L"frmAgregarAlarma";
			this->Load += gcnew System::EventHandler(this, &frmAgregarAlarma::frmAgregarAlarma_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	this->checkBox1->Checked = false;
	this->checkBox2->Checked = false;
	this->textBox3->Clear();
	this->textBox3->Enabled = false;
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	int codigo = Convert::ToInt32(this->textBox1->Text);

	// Validar que se eligió un tipo
	if (!this->checkBox1->Checked && !this->checkBox2->Checked) {
		MessageBox::Show("Seleccione un tipo de alarma: Snooze o Crítica.",
			"Aviso", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		return;
	}

	if (this->checkBox1->Checked) {
		// Snooze: validar que el tiempo de espera sea un número válido
		String^ tiempoTexto = this->textBox3->Text->Trim();

		if (tiempoTexto == "") {
			MessageBox::Show("Ingrese el tiempo de espera en minutos.",
				"Aviso", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		int tiempo = 0;
		if (!Int32::TryParse(tiempoTexto, tiempo) || tiempo <= 0) {
			MessageBox::Show("El tiempo de espera debe ser un número entero mayor a 0.",
				"Aviso", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		// Estado siempre false al crear (se activa cuando un paciente la use)
		AlarmaSnooze^ alarma = gcnew AlarmaSnooze(codigo, false, tiempo);
		this->alarmaController->AgregarAlarmaTXT(alarma);
	}
	else if (this->checkBox2->Checked) {
		// Critica: no tiene atributos extra
		AlarmaCritica^ alarma = gcnew AlarmaCritica(codigo, false);
		this->alarmaController->AgregarAlarmaTXT(alarma);
	}

	MessageBox::Show("Alarma agregada exitosamente.",
		"Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);
	this->Close();
}
private: System::Void frmAgregarAlarma_Load(System::Object^ sender, System::EventArgs^ e) {
	// ID automático, el usuario no lo elige
	int siguienteId = this->alarmaController->ObtenerSiguienteId();
	this->textBox1->Text = siguienteId.ToString();
	this->textBox1->Enabled = false;

	// Estado siempre inactivo al crear, se activa cuando un paciente la use
	this->textBox2->Text = "Inactiva";
	this->textBox2->Enabled = false;

	// Tiempo de espera deshabilitado hasta que se elija Snooze
	this->textBox3->Enabled = false;
}
private: System::Void checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox1->Checked) {
		this->checkBox2->Checked = false;
		this->textBox3->Enabled = true;   // habilitar tiempo de espera
	}
	else {
		this->textBox3->Clear();
		this->textBox3->Enabled = false;  // deshabilitar si desmarca Snooze
	}
}
private: System::Void checkBox2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->checkBox2->Checked) {
		this->checkBox1->Checked = false;
		this->textBox3->Clear();
		this->textBox3->Enabled = false;  // Critica no tiene tiempo de espera
	}
}
};
}
