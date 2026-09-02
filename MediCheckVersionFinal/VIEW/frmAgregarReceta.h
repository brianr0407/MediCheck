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
	/// Resumen de frmAgregarReceta
	/// </summary>
	public ref class frmAgregarReceta : public System::Windows::Forms::Form
	{
	public:
		frmAgregarReceta(void)
		{
			InitializeComponent();
			this->recetaController = gcnew RecetaController();
			this->horarioController = gcnew HorarioRecetaController();
			this->horariosSeleccionados = gcnew List<TimeSpan>();
		}
		frmAgregarReceta(RecetaController^ recetaController)
		{
			InitializeComponent();
			this->recetaController = recetaController;
			this->horarioController = gcnew HorarioRecetaController();
			this->horariosSeleccionados = gcnew List<TimeSpan>();
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmAgregarReceta()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: RecetaController^ recetaController;
	private: PacienteController^ pacienteController;
	private: HorarioRecetaController^ horarioController;
	private: List<TimeSpan>^ horariosSeleccionados;
	protected:


	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label3;


	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::DataGridView^ dataGridView2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn3;
	private: System::Windows::Forms::Label^ labelTipoProgramacion;
	private: System::Windows::Forms::ComboBox^ comboBoxTipoProgramacion;
	private: System::Windows::Forms::Label^ labelHoraManual;
	private: System::Windows::Forms::DateTimePicker^ dateTimePickerHoraManual;
	private: System::Windows::Forms::Button^ buttonAgregarHora;
	private: System::Windows::Forms::Label^ labelFrecuencia;
	private: System::Windows::Forms::ComboBox^ comboBoxFrecuencia;
	private: System::Windows::Forms::Label^ labelHoraInicial;
	private: System::Windows::Forms::DateTimePicker^ dateTimePickerHoraInicial;
	private: System::Windows::Forms::Button^ buttonGenerarHoras;
	private: System::Windows::Forms::Label^ labelHorasProgramadas;
	private: System::Windows::Forms::ListBox^ listBoxHorarios;
	private: System::Windows::Forms::Button^ buttonEliminarHora;




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
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->labelTipoProgramacion = (gcnew System::Windows::Forms::Label());
			this->comboBoxTipoProgramacion = (gcnew System::Windows::Forms::ComboBox());
			this->labelHoraManual = (gcnew System::Windows::Forms::Label());
			this->dateTimePickerHoraManual = (gcnew System::Windows::Forms::DateTimePicker());
			this->buttonAgregarHora = (gcnew System::Windows::Forms::Button());
			this->labelFrecuencia = (gcnew System::Windows::Forms::Label());
			this->comboBoxFrecuencia = (gcnew System::Windows::Forms::ComboBox());
			this->labelHoraInicial = (gcnew System::Windows::Forms::Label());
			this->dateTimePickerHoraInicial = (gcnew System::Windows::Forms::DateTimePicker());
			this->buttonGenerarHoras = (gcnew System::Windows::Forms::Button());
			this->labelHorasProgramadas = (gcnew System::Windows::Forms::Label());
			this->listBoxHorarios = (gcnew System::Windows::Forms::ListBox());
			this->buttonEliminarHora = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->groupBox3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->buttonEliminarHora);
			this->groupBox1->Controls->Add(this->listBoxHorarios);
			this->groupBox1->Controls->Add(this->labelHorasProgramadas);
			this->groupBox1->Controls->Add(this->buttonGenerarHoras);
			this->groupBox1->Controls->Add(this->dateTimePickerHoraInicial);
			this->groupBox1->Controls->Add(this->labelHoraInicial);
			this->groupBox1->Controls->Add(this->comboBoxFrecuencia);
			this->groupBox1->Controls->Add(this->labelFrecuencia);
			this->groupBox1->Controls->Add(this->buttonAgregarHora);
			this->groupBox1->Controls->Add(this->dateTimePickerHoraManual);
			this->groupBox1->Controls->Add(this->labelHoraManual);
			this->groupBox1->Controls->Add(this->comboBoxTipoProgramacion);
			this->groupBox1->Controls->Add(this->labelTipoProgramacion);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->button2);
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Controls->Add(this->textBox3);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->button4);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(12, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(330, 596);
			this->groupBox1->TabIndex = 5;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Agregar";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(103, 505);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(95, 16);
			this->label4->TabIndex = 12;
			this->label4->Text = L"";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(9, 550);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 28);
			this->button2->TabIndex = 11;
			this->button2->Text = L"Agregar";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &frmAgregarReceta::buttonAgregarReceta_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(238, 550);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 28);
			this->button1->TabIndex = 10;
			this->button1->Text = L"Cancelar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &frmAgregarReceta::button1_Click);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(132, 81);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 22);
			this->textBox3->TabIndex = 7;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(17, 87);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(87, 16);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Dosis Diaria :";
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(124, 550);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 28);
			this->button4->TabIndex = 3;
			this->button4->Text = L"Borrar";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &frmAgregarReceta::button4_Click);
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
			this->label1->Location = System::Drawing::Point(17, 35);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(36, 16);
			this->label1->TabIndex = 0;
			this->label1->Text = L"# ID :";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->dataGridView1);
			this->groupBox2->Location = System::Drawing::Point(354, 12);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(594, 288);
			this->groupBox2->TabIndex = 12;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Pacientes";
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->Column1,
					this->Column2, this->Column3
			});
			this->dataGridView1->Location = System::Drawing::Point(9, 21);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->MultiSelect = false;
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridView1->Size = System::Drawing::Size(574, 252);
			this->dataGridView1->TabIndex = 0;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Id Paciente";
			this->Column1->MinimumWidth = 6;
			this->Column1->Name = L"Column1";
			this->Column1->Width = 125;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Nombre";
			this->Column2->MinimumWidth = 6;
			this->Column2->Name = L"Column2";
			this->Column2->Width = 125;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Apellido";
			this->Column3->MinimumWidth = 6;
			this->Column3->Name = L"Column3";
			this->Column3->Width = 125;
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->dataGridView2);
			this->groupBox3->Location = System::Drawing::Point(354, 312);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(594, 296);
			this->groupBox3->TabIndex = 13;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Medicamentos";
			// 
			// dataGridView2
			// 
			this->dataGridView2->AllowUserToAddRows = false;
			this->dataGridView2->AllowUserToDeleteRows = false;
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->dataGridViewTextBoxColumn1,
					this->dataGridViewTextBoxColumn2, this->dataGridViewTextBoxColumn3
			});
			this->dataGridView2->Location = System::Drawing::Point(9, 21);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->MultiSelect = false;
			this->dataGridView2->ReadOnly = true;
			this->dataGridView2->RowHeadersWidth = 51;
			this->dataGridView2->RowTemplate->Height = 24;
			this->dataGridView2->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridView2->Size = System::Drawing::Size(574, 260);
			this->dataGridView2->TabIndex = 0;
			// 
			// labelTipoProgramacion
			// 
			this->labelTipoProgramacion->AutoSize = true;
			this->labelTipoProgramacion->Location = System::Drawing::Point(17, 125);
			this->labelTipoProgramacion->Name = L"labelTipoProgramacion";
			this->labelTipoProgramacion->Text = L"Programacion:";
			// 
			// comboBoxTipoProgramacion
			// 
			this->comboBoxTipoProgramacion->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxTipoProgramacion->Location = System::Drawing::Point(132, 121);
			this->comboBoxTipoProgramacion->Name = L"comboBoxTipoProgramacion";
			this->comboBoxTipoProgramacion->Size = System::Drawing::Size(173, 24);
			this->comboBoxTipoProgramacion->SelectedIndexChanged += gcnew System::EventHandler(this, &frmAgregarReceta::comboBoxTipoProgramacion_SelectedIndexChanged);
			// 
			// labelHoraManual
			// 
			this->labelHoraManual->AutoSize = true;
			this->labelHoraManual->Location = System::Drawing::Point(17, 165);
			this->labelHoraManual->Name = L"labelHoraManual";
			this->labelHoraManual->Text = L"Hora manual:";
			// 
			// dateTimePickerHoraManual
			// 
			this->dateTimePickerHoraManual->CustomFormat = L"HH:mm";
			this->dateTimePickerHoraManual->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->dateTimePickerHoraManual->Location = System::Drawing::Point(132, 160);
			this->dateTimePickerHoraManual->Name = L"dateTimePickerHoraManual";
			this->dateTimePickerHoraManual->ShowUpDown = true;
			this->dateTimePickerHoraManual->Size = System::Drawing::Size(80, 22);
			// 
			// buttonAgregarHora
			// 
			this->buttonAgregarHora->Location = System::Drawing::Point(218, 158);
			this->buttonAgregarHora->Name = L"buttonAgregarHora";
			this->buttonAgregarHora->Size = System::Drawing::Size(87, 28);
			this->buttonAgregarHora->Text = L"Agregar";
			this->buttonAgregarHora->UseVisualStyleBackColor = true;
			this->buttonAgregarHora->Click += gcnew System::EventHandler(this, &frmAgregarReceta::buttonAgregarHora_Click);
			// 
			// labelFrecuencia
			// 
			this->labelFrecuencia->AutoSize = true;
			this->labelFrecuencia->Location = System::Drawing::Point(17, 205);
			this->labelFrecuencia->Name = L"labelFrecuencia";
			this->labelFrecuencia->Text = L"Frecuencia:";
			// 
			// comboBoxFrecuencia
			// 
			this->comboBoxFrecuencia->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxFrecuencia->Location = System::Drawing::Point(132, 201);
			this->comboBoxFrecuencia->Name = L"comboBoxFrecuencia";
			this->comboBoxFrecuencia->Size = System::Drawing::Size(173, 24);
			// 
			// labelHoraInicial
			// 
			this->labelHoraInicial->AutoSize = true;
			this->labelHoraInicial->Location = System::Drawing::Point(17, 245);
			this->labelHoraInicial->Name = L"labelHoraInicial";
			this->labelHoraInicial->Text = L"Hora inicial:";
			// 
			// dateTimePickerHoraInicial
			// 
			this->dateTimePickerHoraInicial->CustomFormat = L"HH:mm";
			this->dateTimePickerHoraInicial->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->dateTimePickerHoraInicial->Location = System::Drawing::Point(132, 240);
			this->dateTimePickerHoraInicial->Name = L"dateTimePickerHoraInicial";
			this->dateTimePickerHoraInicial->ShowUpDown = true;
			this->dateTimePickerHoraInicial->Size = System::Drawing::Size(80, 22);
			// 
			// buttonGenerarHoras
			// 
			this->buttonGenerarHoras->Location = System::Drawing::Point(218, 238);
			this->buttonGenerarHoras->Name = L"buttonGenerarHoras";
			this->buttonGenerarHoras->Size = System::Drawing::Size(87, 28);
			this->buttonGenerarHoras->Text = L"Generar";
			this->buttonGenerarHoras->UseVisualStyleBackColor = true;
			this->buttonGenerarHoras->Click += gcnew System::EventHandler(this, &frmAgregarReceta::buttonGenerarHorasV2_Click);
			// 
			// labelHorasProgramadas
			// 
			this->labelHorasProgramadas->AutoSize = true;
			this->labelHorasProgramadas->Location = System::Drawing::Point(17, 285);
			this->labelHorasProgramadas->Name = L"labelHorasProgramadas";
			this->labelHorasProgramadas->Text = L"Horas programadas:";
			// 
			// listBoxHorarios
			// 
			this->listBoxHorarios->FormattingEnabled = true;
			this->listBoxHorarios->ItemHeight = 16;
			this->listBoxHorarios->Location = System::Drawing::Point(20, 310);
			this->listBoxHorarios->Name = L"listBoxHorarios";
			this->listBoxHorarios->Size = System::Drawing::Size(285, 148);
			// 
			// buttonEliminarHora
			// 
			this->buttonEliminarHora->Location = System::Drawing::Point(20, 468);
			this->buttonEliminarHora->Name = L"buttonEliminarHora";
			this->buttonEliminarHora->Size = System::Drawing::Size(285, 30);
			this->buttonEliminarHora->Text = L"Eliminar hora seleccionada";
			this->buttonEliminarHora->UseVisualStyleBackColor = true;
			this->buttonEliminarHora->Click += gcnew System::EventHandler(this, &frmAgregarReceta::buttonEliminarHora_Click);
			// 
			// dataGridViewTextBoxColumn1
			// 
			this->dataGridViewTextBoxColumn1->HeaderText = L"Id Medicamentos";
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
			this->dataGridViewTextBoxColumn3->HeaderText = L"Tipo";
			this->dataGridViewTextBoxColumn3->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn3->Name = L"dataGridViewTextBoxColumn3";
			this->dataGridViewTextBoxColumn3->Width = 125;
			// 
			// frmAgregarReceta
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(960, 620);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Name = L"frmAgregarReceta";
			this->Text = L"frmAgregarReceta";
			this->Load += gcnew System::EventHandler(this, &frmAgregarReceta::frmAgregarReceta_LoadV2);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->groupBox3->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: void ActualizarListaHorarios() {
		this->horariosSeleccionados->Sort();
		this->listBoxHorarios->Items->Clear();
		for each (TimeSpan hora in this->horariosSeleccionados)
			this->listBoxHorarios->Items->Add(hora.ToString("hh\\:mm"));
	}

	private: void ActualizarModoProgramacion() {
		bool porFrecuencia = this->comboBoxTipoProgramacion->SelectedIndex == 1;
		this->dateTimePickerHoraManual->Enabled = !porFrecuencia;
		this->buttonAgregarHora->Enabled = !porFrecuencia;
		this->comboBoxFrecuencia->Enabled = porFrecuencia;
		this->dateTimePickerHoraInicial->Enabled = porFrecuencia;
		this->buttonGenerarHoras->Enabled = porFrecuencia;
	}

	private: void AgregarHora(TimeSpan hora) {
		TimeSpan horaNormalizada = TimeSpan(hora.Hours, hora.Minutes, 0);
		if (this->horariosSeleccionados->Contains(horaNormalizada)) {
			MessageBox::Show("La hora seleccionada ya fue agregada.");
			return;
		}
		this->horariosSeleccionados->Add(horaNormalizada);
		ActualizarListaHorarios();
	}

	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		this->textBox3->Clear();
		this->horariosSeleccionados->Clear();
		ActualizarListaHorarios();
	}


private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	//verificar Completado de pestañas
	if (this->textBox3->Text == "") {
		MessageBox::Show("Por favor, complete todos los campos.");
		return;
	}
	if (this->dataGridView1->SelectedRows->Count == 0) {
		MessageBox::Show("Seleccione un paciente de la lista.");
		return;
	} 
	if (this->dataGridView2->SelectedRows->Count == 0) {
		MessageBox::Show("Seleccione un medicamento de la lista.");
		return;
	}
	 
	int dosisDiaria;

	
	//verificar que los int sean realmente int
	if (!Int32::TryParse(this->textBox3->Text, dosisDiaria)) {
		// Dosis diaria inválida
		MessageBox::Show("Por favor, ingrese una dosis diaria válida.");
		return;
	}
	if (dosisDiaria <= 0) {
		MessageBox::Show("La dosis diaria debe ser mayor que cero.");
		return;
	}
	if (this->horariosSeleccionados->Count != dosisDiaria) {
		MessageBox::Show("Debe registrar exactamente una hora por cada dosis diaria.");
		return;
	}

	

	// Tomar medicamento del datagrid2
	int idMedicamento = Convert::ToInt32(this->dataGridView2->SelectedRows[0]->Cells[0]->Value);
	MedicamentoController^ medicamentoController = gcnew MedicamentoController();
	Medicamento^ medicamento = medicamentoController->BuscarMedicamentoPorIdTXT(idMedicamento);
	if (medicamento == nullptr) {
		MessageBox::Show("No existe un medicamento con ese ID.");
		return;
	}


	int idPaciente = Convert::ToInt32(this->dataGridView1->SelectedRows[0]->Cells[0]->Value);

	int codigo = this->recetaController->ObtenerSiguienteId();

	// idPaciente = 0 (libre), dosisTomada = 0
	Receta^ receta = gcnew Receta(codigo, idPaciente, medicamento, dosisDiaria, 0);
	if (!this->recetaController->AgregarRecetaTXT(receta)) {
		MessageBox::Show("No se pudo agregar la receta.");
		return;
	}

	int idHorario = this->horarioController->ObtenerSiguienteId();
	for each (TimeSpan hora in this->horariosSeleccionados) {
		HorarioReceta^ horario = gcnew HorarioReceta(idHorario++, codigo, hora);
		if (!this->horarioController->AgregarHorarioReceta(horario)) {
			this->recetaController->EliminarRecetaTXT(codigo);
			MessageBox::Show("No se pudieron guardar todos los horarios. La receta no fue registrada.");
			return;
		}
	}

	MessageBox::Show("Receta y horarios agregados exitosamente");
	this->Close();
}


private: System::Void frmAgregarReceta_Load(System::Object^ sender, System::EventArgs^ e) {
	int siguienteId = this->recetaController->ObtenerSiguienteId();
	this->textBox1->Text = siguienteId.ToString();
	this->textBox1->Enabled = false; // solo lectura, el ID es automatico
	this->comboBoxTipoProgramacion->Items->Clear();
	this->comboBoxTipoProgramacion->Items->Add("Horas manuales");
	this->comboBoxTipoProgramacion->Items->Add("Por frecuencia");
	this->comboBoxTipoProgramacion->SelectedIndex = 0;
	this->comboBoxFrecuencia->Items->Clear();
	this->comboBoxFrecuencia->Items->Add(6);
	this->comboBoxFrecuencia->Items->Add(8);
	this->comboBoxFrecuencia->Items->Add(12);
	this->comboBoxFrecuencia->Items->Add(24);
	this->comboBoxFrecuencia->SelectedIndex = 1;
	ActualizarModoProgramacion();

	// Cargar pacientes en el datagrid
	PacienteController^ pacienteController = gcnew PacienteController();
	List<Paciente^>^ pacientes = pacienteController->ObtenerTodosPacientesTXT();
	this->dataGridView1->Rows->Clear();
	for each (Paciente ^ p in pacientes) {
		this->dataGridView1->Rows->Add(
			p->getId().ToString(),
			p->getNombre(),
			p->getApellido()
		);
	}
	// Cargar medicamentos en datagrid2
	MedicamentoController^ medicamentoController = gcnew MedicamentoController();
	List<Medicamento^>^ medicamentos = medicamentoController->ObtenerTodosMedicamentosTXT();
	this->dataGridView2->Rows->Clear();
	for each (Medicamento ^ m in medicamentos) {
		Antibiotico^ ab = dynamic_cast<Antibiotico^>(m);
		String^ tipo = (ab != nullptr) ? "Antibiotico" : "Suplemento Vitaminico";
		this->dataGridView2->Rows->Add(
			m->getId().ToString(),
			m->getNombre(),
			tipo
		);
	}
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
private: System::Void comboBoxTipoProgramacion_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	ActualizarModoProgramacion();
}
private: System::Void buttonAgregarHora_Click(System::Object^ sender, System::EventArgs^ e) {
	AgregarHora(this->dateTimePickerHoraManual->Value.TimeOfDay);
}
private: System::Void buttonGenerarHoras_Click(System::Object^ sender, System::EventArgs^ e) {
	if (this->comboBoxFrecuencia->SelectedItem == nullptr)
		return;

	int frecuencia = Convert::ToInt32(this->comboBoxFrecuencia->SelectedItem);
	int cantidadDosis = 24 / frecuencia;
	DateTime inicio = DateTime(2000, 1, 1, this->dateTimePickerHoraInicial->Value.Hour,
		this->dateTimePickerHoraInicial->Value.Minute, 0);

	this->horariosSeleccionados->Clear();
	for (int i = 0; i < cantidadDosis; i++)
		this->horariosSeleccionados->Add(inicio.AddHours(frecuencia * i).TimeOfDay);
	this->textBox3->Text = cantidadDosis.ToString();
	ActualizarListaHorarios();
}
private: System::Void buttonEliminarHora_Click(System::Object^ sender, System::EventArgs^ e) {
	if (this->listBoxHorarios->SelectedIndex < 0)
		return;
	this->horariosSeleccionados->RemoveAt(this->listBoxHorarios->SelectedIndex);
	ActualizarListaHorarios();
}
private: System::Void frmAgregarReceta_LoadV2(System::Object^ sender, System::EventArgs^ e) {
	int siguienteId = this->recetaController->ObtenerSiguienteId();
	this->textBox1->Text = siguienteId.ToString();
	this->textBox1->Enabled = false;
	this->comboBoxTipoProgramacion->Items->Clear();
	this->comboBoxTipoProgramacion->Items->Add("Horas manuales");
	this->comboBoxTipoProgramacion->Items->Add("Por frecuencia");
	this->comboBoxTipoProgramacion->SelectedIndex = 0;
	this->comboBoxFrecuencia->Items->Clear();
	this->comboBoxFrecuencia->Items->Add(4);
	this->comboBoxFrecuencia->Items->Add(6);
	this->comboBoxFrecuencia->Items->Add(8);
	this->comboBoxFrecuencia->Items->Add(10);
	this->comboBoxFrecuencia->Items->Add(12);
	this->comboBoxFrecuencia->Items->Add(24);
	this->comboBoxFrecuencia->SelectedItem = 8;
	ActualizarModoProgramacion();

	PacienteController^ pacienteController = gcnew PacienteController();
	List<Paciente^>^ pacientes = pacienteController->ObtenerTodosPacientesTXT();
	this->dataGridView1->Rows->Clear();
	for each (Paciente ^ p in pacientes) {
		this->dataGridView1->Rows->Add(
			p->getId().ToString(),
			p->getNombre(),
			p->getApellido()
		);
	}

	MedicamentoController^ medicamentoController = gcnew MedicamentoController();
	List<Medicamento^>^ medicamentos = medicamentoController->ObtenerTodosMedicamentosTXT();
	this->dataGridView2->Rows->Clear();
	for each (Medicamento ^ m in medicamentos) {
		Antibiotico^ ab = dynamic_cast<Antibiotico^>(m);
		String^ tipo = (ab != nullptr) ? "Antibiotico" : "Suplemento Vitaminico";
		this->dataGridView2->Rows->Add(
			m->getId().ToString(),
			m->getNombre(),
			tipo
		);
	}
}
private: System::Void buttonAgregarReceta_Click(System::Object^ sender, System::EventArgs^ e) {
	if (this->dataGridView1->SelectedRows->Count == 0) {
		MessageBox::Show("Seleccione un paciente de la lista.");
		return;
	}
	if (this->dataGridView2->SelectedRows->Count == 0) {
		MessageBox::Show("Seleccione un medicamento de la lista.");
		return;
	}

	int dosisDiaria = 0;
	if (!Int32::TryParse(this->textBox3->Text, dosisDiaria)) {
		MessageBox::Show("Por favor, ingrese una dosis diaria valida.");
		return;
	}

	int idMedicamento = Convert::ToInt32(this->dataGridView2->SelectedRows[0]->Cells[0]->Value);
	MedicamentoController^ medicamentoController = gcnew MedicamentoController();
	Medicamento^ medicamento = medicamentoController->BuscarMedicamentoPorIdTXT(idMedicamento);
	if (medicamento == nullptr) {
		MessageBox::Show("No existe un medicamento con ese ID.");
		return;
	}

	int idPaciente = Convert::ToInt32(this->dataGridView1->SelectedRows[0]->Cells[0]->Value);
	int codigo = 0;
	String^ mensajeError;
	if (!this->recetaController->RegistrarRecetaConHorarios(
		idPaciente, medicamento, dosisDiaria, this->horariosSeleccionados, codigo, mensajeError)) {
		MessageBox::Show(mensajeError);
		return;
	}

	MessageBox::Show("Receta y horarios agregados exitosamente");
	this->Close();
}
private: System::Void buttonGenerarHorasV2_Click(System::Object^ sender, System::EventArgs^ e) {
	if (this->comboBoxFrecuencia->SelectedItem == nullptr)
		return;

	int dosisDiaria = 0;
	if (!Int32::TryParse(this->textBox3->Text, dosisDiaria) || dosisDiaria <= 0) {
		MessageBox::Show("Ingrese una dosis diaria valida antes de generar horarios.");
		return;
	}

	int frecuencia = Convert::ToInt32(this->comboBoxFrecuencia->SelectedItem);
	String^ mensajeError;
	List<TimeSpan>^ horariosGenerados = this->recetaController->GenerarHorariosPorFrecuencia(
		this->dateTimePickerHoraInicial->Value.TimeOfDay, frecuencia, dosisDiaria, mensajeError);
	if (horariosGenerados == nullptr) {
		MessageBox::Show(mensajeError);
		return;
	}

	this->horariosSeleccionados->Clear();
	for each (TimeSpan hora in horariosGenerados)
		this->horariosSeleccionados->Add(hora);
	ActualizarListaHorarios();
}
};
}
