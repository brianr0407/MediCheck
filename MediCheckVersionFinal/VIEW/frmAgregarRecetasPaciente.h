#pragma once

namespace VIEW {
	using namespace MODEL;
	using namespace CONTROLLER;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de frmAgregarRecetasPaciente
	/// </summary>
	public ref class frmAgregarRecetasPaciente : public System::Windows::Forms::Form
	{
	public:
		frmAgregarRecetasPaciente(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}
		frmAgregarRecetasPaciente(RecetaController^ recetaController, PacienteController^ pacienteController,  Paciente^ paciente)
		{
			InitializeComponent();
			this->pacienteController = pacienteController;
			this->recetaController = recetaController;
			this->paciente = paciente;
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmAgregarRecetasPaciente()
		{
			if (components)
			{
				delete components;
			}
		}
	private: PacienteController^ pacienteController;
	private: Paciente^ paciente;
	private: RecetaController^ recetaController;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	protected:
	private: System::Windows::Forms::DataGridView^ dataGridView1;





	private: System::Windows::Forms::GroupBox^ groupBox3;


	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button2;

	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::DataGridView^ dataGridView2;





	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::ContextMenuStrip^ contextMenuStrip1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn3;
	private: System::Windows::Forms::Button^ button1;
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->dataGridViewTextBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->groupBox3->SuspendLayout();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			this->SuspendLayout();
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->dataGridView1);
			this->groupBox2->Location = System::Drawing::Point(294, 12);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(778, 271);
			this->groupBox2->TabIndex = 5;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Recetas de Paciente";
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->Column1,
					this->Column2, this->Column3, this->Column4
			});
			this->dataGridView1->Location = System::Drawing::Point(21, 21);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(736, 230);
			this->dataGridView1->TabIndex = 1;
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->button1);
			this->groupBox3->Controls->Add(this->label5);
			this->groupBox3->Controls->Add(this->label4);
			this->groupBox3->Controls->Add(this->label3);
			this->groupBox3->Controls->Add(this->label2);
			this->groupBox3->Controls->Add(this->label1);
			this->groupBox3->Controls->Add(this->textBox3);
			this->groupBox3->Controls->Add(this->textBox2);
			this->groupBox3->Controls->Add(this->textBox1);
			this->groupBox3->Controls->Add(this->button3);
			this->groupBox3->Controls->Add(this->button2);
			this->groupBox3->Location = System::Drawing::Point(12, 12);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(261, 528);
			this->groupBox3->TabIndex = 6;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Opciones";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(28, 141);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(66, 16);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Paciente :";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(28, 90);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(62, 16);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Nombre :";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(28, 45);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(24, 16);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Id :";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(115, 138);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 22);
			this->textBox3->TabIndex = 5;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(115, 87);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 22);
			this->textBox2->TabIndex = 4;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(115, 45);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 22);
			this->textBox1->TabIndex = 3;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(50, 239);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(143, 32);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Agregar Receta";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &frmAgregarRecetasPaciente::button3_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(50, 342);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(143, 33);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Eliminar Receta";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &frmAgregarRecetasPaciente::button2_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->dataGridView2);
			this->groupBox1->Location = System::Drawing::Point(294, 290);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(778, 271);
			this->groupBox1->TabIndex = 6;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Todas las Recetas :";
			// 
			// dataGridView2
			// 
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->dataGridViewTextBoxColumn1,
					this->dataGridViewTextBoxColumn2, this->dataGridViewTextBoxColumn3
			});
			this->dataGridView2->Location = System::Drawing::Point(21, 21);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->RowHeadersWidth = 51;
			this->dataGridView2->RowTemplate->Height = 24;
			this->dataGridView2->Size = System::Drawing::Size(736, 230);
			this->dataGridView2->TabIndex = 1;
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(61, 4);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(9, 200);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(226, 16);
			this->label4->TabIndex = 9;
			this->label4->Text = L"Seleccionar Receta lista de Recetas";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(28, 299);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(207, 16);
			this->label5->TabIndex = 10;
			this->label5->Text = L"Seleccionar Receta de Paciente :";
			// 
			// dataGridViewTextBoxColumn1
			// 
			this->dataGridViewTextBoxColumn1->HeaderText = L"#ID";
			this->dataGridViewTextBoxColumn1->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn1->Name = L"dataGridViewTextBoxColumn1";
			this->dataGridViewTextBoxColumn1->Width = 125;
			// 
			// dataGridViewTextBoxColumn2
			// 
			this->dataGridViewTextBoxColumn2->HeaderText = L"Medicamento";
			this->dataGridViewTextBoxColumn2->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn2->Name = L"dataGridViewTextBoxColumn2";
			this->dataGridViewTextBoxColumn2->Width = 125;
			// 
			// dataGridViewTextBoxColumn3
			// 
			this->dataGridViewTextBoxColumn3->HeaderText = L"DosisDiaria";
			this->dataGridViewTextBoxColumn3->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn3->Name = L"dataGridViewTextBoxColumn3";
			this->dataGridViewTextBoxColumn3->Width = 125;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"#ID";
			this->Column1->MinimumWidth = 6;
			this->Column1->Name = L"Column1";
			this->Column1->Width = 125;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Medicamento";
			this->Column2->MinimumWidth = 6;
			this->Column2->Name = L"Column2";
			this->Column2->Width = 125;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Dosis Diaria";
			this->Column3->MinimumWidth = 6;
			this->Column3->Name = L"Column3";
			this->Column3->Width = 125;
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Dosis Tomada";
			this->Column4->MinimumWidth = 6;
			this->Column4->Name = L"Column4";
			this->Column4->Width = 125;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(50, 428);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(143, 33);
			this->button1->TabIndex = 11;
			this->button1->Text = L"Terminar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &frmAgregarRecetasPaciente::button1_Click);
			// 
			// frmAgregarRecetasPaciente
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1084, 573);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Name = L"frmAgregarRecetasPaciente";
			this->Text = L"frmAgregarRecetasPaciente";
			this->Load += gcnew System::EventHandler(this, &frmAgregarRecetasPaciente::frmAgregarRecetasPaciente_Load);
			this->groupBox2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

		// Funcion que refresca ambas grillas
private: void actualizarGrillas() {
	// Grilla superior: recetas del paciente
	this->dataGridView1->Rows->Clear();
	List<Receta^>^ recetasPaciente = recetaController->BuscarRecetasActivasPorCronogramaIdTXT(this->paciente->getId());
	for (int i = 0; i < recetasPaciente->Count; i++) {
		Receta^ r = recetasPaciente[i];
		array<String^>^ fila = gcnew array<String^>(4);
		fila[0] = r->getIdReceta().ToString();
		fila[1] = r->getMedicamento()->getNombre(); // o como se llame el getter
		fila[2] = r->getDosisDiaria().ToString();
		fila[3] = r->getDosisTomada().ToString();
		this->dataGridView1->Rows->Add(fila);
	}

	// Grilla inferior: todas las recetas
	this->dataGridView2->Rows->Clear();
	List<Receta^>^ todasRecetas = recetaController->ObtenerTodosRecetasTXT();
	for (int i = 0; i < todasRecetas->Count; i++) {
		Receta^ r = todasRecetas[i];
		if (r->getIdPaciente() == 0) { // solo las libres
			array<String^>^ fila = gcnew array<String^>(4);
			fila[0] = r->getIdReceta().ToString();
			fila[1] = r->getMedicamento()->getNombre();
			fila[2] = r->getDosisDiaria().ToString();
			fila[3] = r->getDosisTomada().ToString();
			this->dataGridView2->Rows->Add(fila);
		}
	}
}

	private: System::Void frmAgregarRecetasPaciente_Load(System::Object^ sender, System::EventArgs^ e) {
		this->textBox1->Text = this->paciente->getId().ToString();
		this->textBox2->Text = this->paciente->getNombre();
		this->textBox3->Text = this->paciente->getApellido();


		actualizarGrillas();
	}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	if (this->dataGridView2->SelectedRows->Count == 0) {
		MessageBox::Show("Seleccione una receta de la lista");
		return;
	}

	int idReceta = Convert::ToInt32(this->dataGridView2->SelectedRows[0]->Cells[0]->Value);
	Receta^ receta = recetaController->BuscarRecetaPorIdTXT(idReceta);

	if (receta->getIdPaciente() != 0) {
		MessageBox::Show("Esta receta ya esta asignada a otro paciente");
		return;
	}

	// Reasignar el idPaciente
	receta->setIdPaciente(this->paciente -> getId());
	recetaController->ActualizarArchivo(receta);

	MessageBox::Show("Receta agregada exitosamente");
	actualizarGrillas();
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	if (this->dataGridView1->SelectedRows->Count == 0) {
		MessageBox::Show("Seleccione una receta del paciente para quitar");
		return;
	}

	int idReceta = Convert::ToInt32(this->dataGridView1->SelectedRows[0]->Cells[0]->Value);
	Receta^ receta = recetaController->BuscarRecetaPorIdTXT(idReceta);

	// Desasignar poniendo idPaciente a 0
	receta->setIdPaciente(0);
	recetaController->ActualizarArchivo(receta);

	MessageBox::Show("Receta quitada del paciente exitosamente");
	actualizarGrillas();
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
};
}
