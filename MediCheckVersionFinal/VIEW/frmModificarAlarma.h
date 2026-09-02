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
	/// Resumen de frmModificarAlarma
	/// </summary>
	public ref class frmModificarAlarma : public System::Windows::Forms::Form
	{
	public:
		frmModificarAlarma(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}
		frmModificarAlarma(AlarmaController^ alarmaController, Alarma^ alarma)
		{
			InitializeComponent();
			this->alarmaController = alarmaController;
			this->alarma = alarma;
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmModificarAlarma()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		Alarma^ alarma;
		AlarmaController^ alarmaController;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::CheckBox^ checkBox2;
	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;










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
			this->groupBox1->Location = System::Drawing::Point(9, 11);
			this->groupBox1->Margin = System::Windows::Forms::Padding(2);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(2);
			this->groupBox1->Size = System::Drawing::Size(231, 227);
			this->groupBox1->TabIndex = 6;
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
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(10, 190);
			this->button2->Margin = System::Windows::Forms::Padding(2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(62, 23);
			this->button2->TabIndex = 11;
			this->button2->Text = L"Modificar";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &frmModificarAlarma::button2_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(86, 190);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(56, 23);
			this->button1->TabIndex = 10;
			this->button1->Text = L"Cancelar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &frmModificarAlarma::button1_Click);
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
			this->button4->Click += gcnew System::EventHandler(this, &frmModificarAlarma::button4_Click);
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
			// 
			// frmModificarAlarma
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(251, 249);
			this->Controls->Add(this->groupBox1);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"frmModificarAlarma";
			this->Text = L"frmModificarAlarma";
			this->Load += gcnew System::EventHandler(this, &frmModificarAlarma::frmModificarAlarma_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void frmModificarAlarma_Load(System::Object^ sender, System::EventArgs^ e) {
		// ID y estado son de solo lectura, el usuario no los toca
		this->textBox1->Enabled = false;
		this->textBox2->Enabled = false;

		// textBox3 deshabilitado por defecto, solo activo si es Snooze
		this->textBox3->Enabled = false;

		// Ambos checkboxes deshabilitados por defecto
		this->checkBox1->Enabled = false;
		this->checkBox2->Enabled = false;

		if (this->alarma != nullptr) {
			// Mostrar ID y estado actual (solo lectura, informativo)
			this->textBox1->Text = this->alarma->getId().ToString();
			this->textBox2->Text = this->alarma->getEstado() ? "Activa" : "Inactiva";

			AlarmaSnooze^ sn = dynamic_cast<AlarmaSnooze^>(this->alarma);
			AlarmaCritica^ cr = dynamic_cast<AlarmaCritica^>(this->alarma);

			if (sn != nullptr) {
				// Es Snooze: marcar checkbox, habilitar y pre-rellenar tiempo de espera
				this->checkBox1->Checked = true;
				this->checkBox1->Enabled = true;
				this->textBox3->Text = sn->getTiempoDeEspera().ToString();
				this->textBox3->Enabled = true;
			}
			else if (cr != nullptr) {
				// Es Critica: marcar checkbox, tiempo de espera no aplica
				this->checkBox2->Checked = true;
				this->checkBox2->Enabled = true;
				this->textBox3->Text = "-";
				this->textBox3->Enabled = false;
			}
		}
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	int codigo = this->alarma->getId();

	AlarmaSnooze^ sn = dynamic_cast<AlarmaSnooze^>(this->alarma);
	AlarmaCritica^ cr = dynamic_cast<AlarmaCritica^>(this->alarma);

	if (sn != nullptr) {
		// Validar que el tiempo de espera sea un número válido
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

		// Conservar el estado actual (no se modifica aquí)
		AlarmaSnooze^ modificada = gcnew AlarmaSnooze(codigo, sn->getEstado(), tiempo);
		this->alarmaController->ActualizarArchivo(modificada);
	}
	else if (cr != nullptr) {
		// AlarmaCritica no tiene atributos modificables desde este formulario
		// El estado solo lo cambia el sistema cuando un paciente la usa
		MessageBox::Show("Las alarmas Críticas no tienen atributos modificables.",
			"Aviso", MessageBoxButtons::OK, MessageBoxIcon::Information);
		return;
	}

	MessageBox::Show("Alarma modificada exitosamente.",
		"Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);
	this->Close();

}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	AlarmaSnooze^ sn = dynamic_cast<AlarmaSnooze^>(this->alarma);
	if (sn != nullptr) {
		this->textBox3->Clear();
	}
}
};
}
