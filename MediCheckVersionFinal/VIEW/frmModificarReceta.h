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
	/// Resumen de frmModificarReceta
	/// </summary>
	public ref class frmModificarReceta : public System::Windows::Forms::Form
	{
	public:
		frmModificarReceta(void)
		{
			InitializeComponent();
			this->recetaController = gcnew RecetaController();
			this->horarioController = gcnew HorarioRecetaController();
			this->horariosSeleccionados = gcnew List<TimeSpan>();
		}
		frmModificarReceta(RecetaController^ recetaController, Receta^ receta)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			this->recetaController = recetaController;
			this->receta = receta;
			this->horarioController = gcnew HorarioRecetaController();
			this->horariosSeleccionados = gcnew List<TimeSpan>();
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmModificarReceta()
		{
			if (components)
			{
				delete components;
			}
		}
	private: RecetaController^ recetaController;
	private: Receta^ receta;
	private: HorarioRecetaController^ horarioController;
	private: List<TimeSpan>^ horariosSeleccionados;
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
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
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
			this->groupBox1->Controls->Add(this->button2);
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Controls->Add(this->textBox3);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->textBox2);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->button4);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(9, 10);
			this->groupBox1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->groupBox1->Size = System::Drawing::Size(526, 500);
			this->groupBox1->TabIndex = 6;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Modificar";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(180, 445);
			this->button2->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(150, 36);
			this->button2->TabIndex = 11;
			this->button2->Text = L"Modificar";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &frmModificarReceta::buttonModificarReceta_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(345, 445);
			this->button1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(150, 36);
			this->button1->TabIndex = 10;
			this->button1->Text = L"Cancelar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &frmModificarReceta::button1_Click);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(99, 110);
			this->textBox3->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(76, 20);
			this->textBox3->TabIndex = 7;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(13, 115);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(80, 15);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Dosis Diaria :";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(99, 69);
			this->textBox2->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(76, 20);
			this->textBox2->TabIndex = 5;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(13, 72);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(102, 15);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Id Medicamento :";
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(20, 445);
			this->button4->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(145, 36);
			this->button4->TabIndex = 3;
			this->button4->Text = L"Borrar";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &frmModificarReceta::button4_Click);
			// 
			// textBox1
			// 
			this->textBox1->Enabled = false;
			this->textBox1->Location = System::Drawing::Point(99, 26);
			this->textBox1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(76, 20);
			this->textBox1->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 28);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 15);
			this->label1->TabIndex = 0;
			this->label1->Text = L"# ID :";
			// 
			// labelTipoProgramacion
			// 
			this->labelTipoProgramacion->AutoSize = true;
			this->labelTipoProgramacion->Location = System::Drawing::Point(20, 155);
			this->labelTipoProgramacion->Name = L"labelTipoProgramacion";
			this->labelTipoProgramacion->Text = L"Programacion:";
			// 
			// comboBoxTipoProgramacion
			// 
			this->comboBoxTipoProgramacion->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxTipoProgramacion->Location = System::Drawing::Point(180, 151);
			this->comboBoxTipoProgramacion->Name = L"comboBoxTipoProgramacion";
			this->comboBoxTipoProgramacion->Size = System::Drawing::Size(315, 24);
			this->comboBoxTipoProgramacion->SelectedIndexChanged += gcnew System::EventHandler(this, &frmModificarReceta::comboBoxTipoProgramacion_SelectedIndexChanged);
			// 
			// labelHoraManual
			// 
			this->labelHoraManual->AutoSize = true;
			this->labelHoraManual->Location = System::Drawing::Point(20, 196);
			this->labelHoraManual->Name = L"labelHoraManual";
			this->labelHoraManual->Text = L"Hora manual:";
			// 
			// dateTimePickerHoraManual
			// 
			this->dateTimePickerHoraManual->CustomFormat = L"HH:mm";
			this->dateTimePickerHoraManual->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->dateTimePickerHoraManual->Location = System::Drawing::Point(180, 191);
			this->dateTimePickerHoraManual->Name = L"dateTimePickerHoraManual";
			this->dateTimePickerHoraManual->ShowUpDown = true;
			this->dateTimePickerHoraManual->Size = System::Drawing::Size(110, 22);
			// 
			// buttonAgregarHora
			// 
			this->buttonAgregarHora->Location = System::Drawing::Point(305, 188);
			this->buttonAgregarHora->Name = L"buttonAgregarHora";
			this->buttonAgregarHora->Size = System::Drawing::Size(190, 29);
			this->buttonAgregarHora->Text = L"Agregar hora";
			this->buttonAgregarHora->UseVisualStyleBackColor = true;
			this->buttonAgregarHora->Click += gcnew System::EventHandler(this, &frmModificarReceta::buttonAgregarHora_Click);
			// 
			// labelFrecuencia
			// 
			this->labelFrecuencia->AutoSize = true;
			this->labelFrecuencia->Location = System::Drawing::Point(20, 235);
			this->labelFrecuencia->Name = L"labelFrecuencia";
			this->labelFrecuencia->Text = L"Frecuencia:";
			// 
			// comboBoxFrecuencia
			// 
			this->comboBoxFrecuencia->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxFrecuencia->Location = System::Drawing::Point(180, 231);
			this->comboBoxFrecuencia->Name = L"comboBoxFrecuencia";
			this->comboBoxFrecuencia->Size = System::Drawing::Size(110, 24);
			// 
			// labelHoraInicial
			// 
			this->labelHoraInicial->AutoSize = true;
			this->labelHoraInicial->Location = System::Drawing::Point(305, 235);
			this->labelHoraInicial->Name = L"labelHoraInicial";
			this->labelHoraInicial->Text = L"Hora inicial:";
			// 
			// dateTimePickerHoraInicial
			// 
			this->dateTimePickerHoraInicial->CustomFormat = L"HH:mm";
			this->dateTimePickerHoraInicial->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->dateTimePickerHoraInicial->Location = System::Drawing::Point(395, 231);
			this->dateTimePickerHoraInicial->Name = L"dateTimePickerHoraInicial";
			this->dateTimePickerHoraInicial->ShowUpDown = true;
			this->dateTimePickerHoraInicial->Size = System::Drawing::Size(100, 22);
			// 
			// buttonGenerarHoras
			// 
			this->buttonGenerarHoras->Location = System::Drawing::Point(180, 266);
			this->buttonGenerarHoras->Name = L"buttonGenerarHoras";
			this->buttonGenerarHoras->Size = System::Drawing::Size(315, 30);
			this->buttonGenerarHoras->Text = L"Generar horas por frecuencia";
			this->buttonGenerarHoras->UseVisualStyleBackColor = true;
			this->buttonGenerarHoras->Click += gcnew System::EventHandler(this, &frmModificarReceta::buttonGenerarHorasModificar_Click);
			// 
			// labelHorasProgramadas
			// 
			this->labelHorasProgramadas->AutoSize = true;
			this->labelHorasProgramadas->Location = System::Drawing::Point(20, 315);
			this->labelHorasProgramadas->Name = L"labelHorasProgramadas";
			this->labelHorasProgramadas->Text = L"Horas programadas:";
			// 
			// listBoxHorarios
			// 
			this->listBoxHorarios->FormattingEnabled = true;
			this->listBoxHorarios->ItemHeight = 16;
			this->listBoxHorarios->Location = System::Drawing::Point(180, 312);
			this->listBoxHorarios->Name = L"listBoxHorarios";
			this->listBoxHorarios->Size = System::Drawing::Size(315, 68);
			// 
			// buttonEliminarHora
			// 
			this->buttonEliminarHora->Location = System::Drawing::Point(180, 389);
			this->buttonEliminarHora->Name = L"buttonEliminarHora";
			this->buttonEliminarHora->Size = System::Drawing::Size(315, 30);
			this->buttonEliminarHora->Text = L"Eliminar hora seleccionada";
			this->buttonEliminarHora->UseVisualStyleBackColor = true;
			this->buttonEliminarHora->Click += gcnew System::EventHandler(this, &frmModificarReceta::buttonEliminarHora_Click);
			// 
			// frmModificarReceta
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(550, 524);
			this->Controls->Add(this->groupBox1);
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->Name = L"frmModificarReceta";
			this->Text = L"frmModificarReceta";
			this->Load += gcnew System::EventHandler(this, &frmModificarReceta::frmModificarReceta_LoadV2);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
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

	private: System::Void frmModificarReceta_Load(System::Object^ sender, System::EventArgs^ e) {
		if (this->receta == nullptr)
			return;
		this->textBox1->Text = this->receta->getIdReceta().ToString();
		this->textBox2->Text = this->receta->getMedicamento()->getId().ToString();
		this->textBox3->Text = this->receta->getDosisDiaria().ToString();
		this->comboBoxTipoProgramacion->Items->Add("Horas manuales");
		this->comboBoxTipoProgramacion->Items->Add("Por frecuencia");
		this->comboBoxTipoProgramacion->SelectedIndex = 0;
		this->comboBoxFrecuencia->Items->Add(6);
		this->comboBoxFrecuencia->Items->Add(8);
		this->comboBoxFrecuencia->Items->Add(12);
		this->comboBoxFrecuencia->Items->Add(24);
		this->comboBoxFrecuencia->SelectedIndex = 1;
		for each (HorarioReceta ^ horario in this->horarioController->ObtenerHorariosPorReceta(this->receta->getIdReceta()))
			this->horariosSeleccionados->Add(horario->getHoraProgramada());
		ActualizarListaHorarios();
		ActualizarModoProgramacion();
	}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	int id;
	int idMedicamento;
	int dosisDiaria;
	if (!Int32::TryParse(this->textBox1->Text, id) ||
		!Int32::TryParse(this->textBox2->Text, idMedicamento) ||
		!Int32::TryParse(this->textBox3->Text, dosisDiaria) || dosisDiaria <= 0) {
		MessageBox::Show("Ingrese valores validos.");
		return;
	}
	if (this->horariosSeleccionados->Count != dosisDiaria) {
		MessageBox::Show("Debe registrar exactamente una hora por cada dosis diaria.");
		return;
	}

	// Verificar que el medicamento existe
	MedicamentoController^ medicamentoController = gcnew MedicamentoController();
	Medicamento^ medicamento = medicamentoController->BuscarMedicamentoPorIdTXT(idMedicamento);
	if (medicamento == nullptr) {
		MessageBox::Show("No existe un medicamento con ese ID");
		return;
	}

	// Conservar idPaciente y dosisTomada que ya tenia
	Receta^ recetaActualizada = gcnew Receta(id, this->receta->getIdPaciente(), medicamento, dosisDiaria, this->receta->getDosisTomada());
	if (!this->recetaController->ActualizarArchivo(recetaActualizada)) {
		MessageBox::Show("No se pudo modificar la receta.");
		return;
	}

	this->horarioController->EliminarHorariosPorReceta(id);
	int idHorario = this->horarioController->ObtenerSiguienteId();
	for each (TimeSpan hora in this->horariosSeleccionados) {
		if (!this->horarioController->AgregarHorarioReceta(gcnew HorarioReceta(idHorario++, id, hora))) {
			MessageBox::Show("La receta fue modificada, pero no se pudieron guardar todos sus horarios.");
			return;
		}
	}

	MessageBox::Show("Receta y horarios modificados exitosamente");
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
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	this->textBox3->Clear();
	this->horariosSeleccionados->Clear();
	ActualizarListaHorarios();
}
private: System::Void frmModificarReceta_LoadV2(System::Object^ sender, System::EventArgs^ e) {
	if (this->receta == nullptr)
		return;
	this->textBox1->Text = this->receta->getIdReceta().ToString();
	this->textBox2->Text = this->receta->getMedicamento()->getId().ToString();
	this->textBox3->Text = this->receta->getDosisDiaria().ToString();
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
	for each (HorarioReceta ^ horario in this->horarioController->ObtenerHorariosPorReceta(this->receta->getIdReceta()))
		this->horariosSeleccionados->Add(horario->getHoraProgramada());
	ActualizarListaHorarios();
	ActualizarModoProgramacion();
}
private: System::Void buttonModificarReceta_Click(System::Object^ sender, System::EventArgs^ e) {
	int id = 0;
	int idMedicamento = 0;
	int dosisDiaria = 0;
	if (!Int32::TryParse(this->textBox1->Text, id) ||
		!Int32::TryParse(this->textBox2->Text, idMedicamento) ||
		!Int32::TryParse(this->textBox3->Text, dosisDiaria) || dosisDiaria <= 0) {
		MessageBox::Show("Ingrese valores validos.");
		return;
	}

	MedicamentoController^ medicamentoController = gcnew MedicamentoController();
	Medicamento^ medicamento = medicamentoController->BuscarMedicamentoPorIdTXT(idMedicamento);
	if (medicamento == nullptr) {
		MessageBox::Show("No existe un medicamento con ese ID");
		return;
	}

	String^ mensajeError;
	if (!this->recetaController->ModificarRecetaConHorarios(
		id, this->receta->getIdPaciente(), medicamento, dosisDiaria, this->receta->getDosisTomada(),
		this->horariosSeleccionados, mensajeError)) {
		MessageBox::Show(mensajeError);
		return;
	}

	MessageBox::Show("Receta y horarios modificados exitosamente");
	this->Close();
}
private: System::Void buttonGenerarHorasModificar_Click(System::Object^ sender, System::EventArgs^ e) {
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
