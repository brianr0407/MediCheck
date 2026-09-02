#pragma once

namespace VIEW {
	using namespace System;
	using namespace System::Collections::Generic;
	using namespace System::Drawing;
	using namespace System::Text;
	using namespace System::Windows::Forms;
	using namespace System::Windows::Forms::DataVisualization::Charting;
	using namespace MODEL;
	using namespace CONTROLLER;

	public ref class frmDosisOmitidas : public System::Windows::Forms::Form {
	public:
		frmDosisOmitidas() {
			InitializeComponent();
			PrepararColumnasDisenador();
		}

	protected:
		~frmDosisOmitidas() { if (components) delete components; }

	private:
		System::ComponentModel::Container^ components;
		GeneradorReportesController^ reportesController;
		MedicamentoController^ medicamentoController;
		Dictionary<int, bool>^ riesgosAltos;

		System::Windows::Forms::Panel^ panelCabecera;
		System::Windows::Forms::Label^ lblTitulo;
		System::Windows::Forms::Label^ lblSubtitulo;
		System::Windows::Forms::Label^ lblGenerado;
		System::Windows::Forms::Panel^ panelContenido;
		System::Windows::Forms::Panel^ panelAlerta;
		System::Windows::Forms::Label^ lblAlerta;
		System::Windows::Forms::Panel^ panelFiltros;
		System::Windows::Forms::Label^ lblPacienteFiltro;
		System::Windows::Forms::ComboBox^ cmbPaciente;
		System::Windows::Forms::Label^ lblDesde;
		System::Windows::Forms::DateTimePicker^ dtpDesde;
		System::Windows::Forms::Label^ lblHasta;
		System::Windows::Forms::DateTimePicker^ dtpHasta;
		System::Windows::Forms::Label^ lblMedicamentoFiltro;
		System::Windows::Forms::ComboBox^ cmbMedicamento;
		System::Windows::Forms::Label^ lblTurnoFiltro;
		System::Windows::Forms::ComboBox^ cmbTurno;
		System::Windows::Forms::Button^ btnAplicar;
		System::Windows::Forms::Button^ btnRestablecer;

		System::Windows::Forms::Panel^ cardOmitidas;
		System::Windows::Forms::Label^ lblCardOmitidas;
		System::Windows::Forms::Label^ lblOmitidas;
		System::Windows::Forms::Label^ lblOmitidasSub;
		System::Windows::Forms::Panel^ cardRiesgo;
		System::Windows::Forms::Label^ lblCardRiesgo;
		System::Windows::Forms::Label^ lblRiesgo;
		System::Windows::Forms::Label^ lblRiesgoSub;
		System::Windows::Forms::Panel^ cardError;
		System::Windows::Forms::Label^ lblCardError;
		System::Windows::Forms::Label^ lblError;
		System::Windows::Forms::Label^ lblErrorSub;
		System::Windows::Forms::Panel^ cardDormida;
		System::Windows::Forms::Label^ lblCardDormida;
		System::Windows::Forms::Label^ lblDormida;
		System::Windows::Forms::Label^ lblDormidaSub;
		System::Windows::Forms::Panel^ cardIgnorada;
		System::Windows::Forms::Label^ lblCardIgnorada;
		System::Windows::Forms::Label^ lblIgnorada;
		System::Windows::Forms::Label^ lblIgnoradaSub;

		System::Windows::Forms::GroupBox^ grpMedicamento;
		System::Windows::Forms::DataVisualization::Charting::Chart^ chartMedicamento;
		System::Windows::Forms::GroupBox^ grpDias;
		System::Windows::Forms::DataVisualization::Charting::Chart^ chartDias;


		System::Windows::Forms::GroupBox^ grpDetalle;
		System::Windows::Forms::DataGridView^ dgvDetalle;
		System::Windows::Forms::DataGridViewTextBoxColumn^ colEvento;
		System::Windows::Forms::DataGridViewTextBoxColumn^ colFecha;
		System::Windows::Forms::DataGridViewTextBoxColumn^ colTurno;
		System::Windows::Forms::DataGridViewTextBoxColumn^ colHora;
		System::Windows::Forms::DataGridViewTextBoxColumn^ colPaciente;
		System::Windows::Forms::DataGridViewTextBoxColumn^ colMedicamento;
		System::Windows::Forms::DataGridViewTextBoxColumn^ colDispensado;
		System::Windows::Forms::DataGridViewTextBoxColumn^ colCausa;
		System::Windows::Forms::DataGridViewTextBoxColumn^ colRiesgo;
		System::Windows::Forms::GroupBox^ grpObservaciones;
		System::Windows::Forms::RichTextBox^ txtObservaciones;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void) {
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea3 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Series^ series3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea4 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Series^ series4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->panelCabecera = (gcnew System::Windows::Forms::Panel());
			this->lblTitulo = (gcnew System::Windows::Forms::Label());
			this->lblSubtitulo = (gcnew System::Windows::Forms::Label());
			this->lblGenerado = (gcnew System::Windows::Forms::Label());
			this->panelContenido = (gcnew System::Windows::Forms::Panel());
			this->panelAlerta = (gcnew System::Windows::Forms::Panel());
			this->lblAlerta = (gcnew System::Windows::Forms::Label());
			this->panelFiltros = (gcnew System::Windows::Forms::Panel());
			this->lblPacienteFiltro = (gcnew System::Windows::Forms::Label());
			this->cmbPaciente = (gcnew System::Windows::Forms::ComboBox());
			this->lblDesde = (gcnew System::Windows::Forms::Label());
			this->dtpDesde = (gcnew System::Windows::Forms::DateTimePicker());
			this->lblHasta = (gcnew System::Windows::Forms::Label());
			this->dtpHasta = (gcnew System::Windows::Forms::DateTimePicker());
			this->lblMedicamentoFiltro = (gcnew System::Windows::Forms::Label());
			this->cmbMedicamento = (gcnew System::Windows::Forms::ComboBox());
			this->lblTurnoFiltro = (gcnew System::Windows::Forms::Label());
			this->cmbTurno = (gcnew System::Windows::Forms::ComboBox());
			this->btnAplicar = (gcnew System::Windows::Forms::Button());
			this->btnRestablecer = (gcnew System::Windows::Forms::Button());
			this->cardOmitidas = (gcnew System::Windows::Forms::Panel());
			this->lblCardOmitidas = (gcnew System::Windows::Forms::Label());
			this->lblOmitidas = (gcnew System::Windows::Forms::Label());
			this->lblOmitidasSub = (gcnew System::Windows::Forms::Label());
			this->cardRiesgo = (gcnew System::Windows::Forms::Panel());
			this->lblCardRiesgo = (gcnew System::Windows::Forms::Label());
			this->lblRiesgo = (gcnew System::Windows::Forms::Label());
			this->lblRiesgoSub = (gcnew System::Windows::Forms::Label());
			this->cardError = (gcnew System::Windows::Forms::Panel());
			this->lblCardError = (gcnew System::Windows::Forms::Label());
			this->lblError = (gcnew System::Windows::Forms::Label());
			this->lblErrorSub = (gcnew System::Windows::Forms::Label());
			this->cardDormida = (gcnew System::Windows::Forms::Panel());
			this->lblCardDormida = (gcnew System::Windows::Forms::Label());
			this->lblDormida = (gcnew System::Windows::Forms::Label());
			this->lblDormidaSub = (gcnew System::Windows::Forms::Label());
			this->cardIgnorada = (gcnew System::Windows::Forms::Panel());
			this->lblCardIgnorada = (gcnew System::Windows::Forms::Label());
			this->lblIgnorada = (gcnew System::Windows::Forms::Label());
			this->lblIgnoradaSub = (gcnew System::Windows::Forms::Label());
			this->grpMedicamento = (gcnew System::Windows::Forms::GroupBox());
			this->chartMedicamento = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->grpDias = (gcnew System::Windows::Forms::GroupBox());
			this->chartDias = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->grpDetalle = (gcnew System::Windows::Forms::GroupBox());
			this->dgvDetalle = (gcnew System::Windows::Forms::DataGridView());
			this->colEvento = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colFecha = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colTurno = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colHora = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colPaciente = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colMedicamento = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colDispensado = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colCausa = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colRiesgo = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->grpObservaciones = (gcnew System::Windows::Forms::GroupBox());
			this->txtObservaciones = (gcnew System::Windows::Forms::RichTextBox());
			this->panelCabecera->SuspendLayout();
			this->panelContenido->SuspendLayout();
			this->panelAlerta->SuspendLayout();
			this->panelFiltros->SuspendLayout();
			this->cardOmitidas->SuspendLayout();
			this->cardRiesgo->SuspendLayout();
			this->cardError->SuspendLayout();
			this->cardDormida->SuspendLayout();
			this->cardIgnorada->SuspendLayout();
			this->grpMedicamento->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartMedicamento))->BeginInit();
			this->grpDias->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartDias))->BeginInit();
			this->grpDetalle->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvDetalle))->BeginInit();
			this->grpObservaciones->SuspendLayout();
			this->SuspendLayout();
			// 
			// panelCabecera
			// 
			this->panelCabecera->BackColor = System::Drawing::Color::FromArgb(15, 41, 66);
			this->panelCabecera->Controls->Add(this->lblTitulo);
			this->panelCabecera->Controls->Add(this->lblSubtitulo);
			this->panelCabecera->Controls->Add(this->lblGenerado);
			this->panelCabecera->Dock = System::Windows::Forms::DockStyle::Top;
			this->panelCabecera->Location = System::Drawing::Point(0, 0);
			this->panelCabecera->Name = L"panelCabecera";
			this->panelCabecera->Size = System::Drawing::Size(1360, 84);
			this->panelCabecera->TabIndex = 1;
			// 
			// lblTitulo
			// 
			this->lblTitulo->AutoSize = true;
			this->lblTitulo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15, System::Drawing::FontStyle::Regular));
			this->lblTitulo->ForeColor = System::Drawing::Color::FromArgb(220, 233, 245);
			this->lblTitulo->Location = System::Drawing::Point(24, 13);
			this->lblTitulo->Name = L"lblTitulo";
			this->lblTitulo->Size = System::Drawing::Size(359, 37);
			this->lblTitulo->TabIndex = 0;
			this->lblTitulo->Text = L"Reporte de Dosis Omitidas";
			// 
			// lblSubtitulo
			// 
			this->lblSubtitulo->AutoSize = true;
			this->lblSubtitulo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->lblSubtitulo->ForeColor = System::Drawing::Color::FromArgb(200, 218, 235);
			this->lblSubtitulo->Location = System::Drawing::Point(27, 50);
			this->lblSubtitulo->Name = L"lblSubtitulo";
			this->lblSubtitulo->Size = System::Drawing::Size(444, 20);
			this->lblSubtitulo->TabIndex = 1;
			this->lblSubtitulo->Text = L"Seguimiento automatico de dosis no tomadas y causas probables";
			// 
			// lblGenerado
			// 
			this->lblGenerado->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->lblGenerado->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->lblGenerado->ForeColor = System::Drawing::Color::White;
			this->lblGenerado->Location = System::Drawing::Point(1060, 28);
			this->lblGenerado->Name = L"lblGenerado";
			this->lblGenerado->Size = System::Drawing::Size(274, 22);
			this->lblGenerado->TabIndex = 2;
			this->lblGenerado->Text = L"Generado:";
			this->lblGenerado->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// panelContenido
			// 
			this->panelContenido->AutoScroll = true;
			this->panelContenido->BackColor = System::Drawing::Color::FromArgb(241, 244, 248);
			this->panelContenido->Controls->Add(this->panelAlerta);
			this->panelContenido->Controls->Add(this->panelFiltros);
			this->panelContenido->Controls->Add(this->cardOmitidas);
			this->panelContenido->Controls->Add(this->cardRiesgo);
			this->panelContenido->Controls->Add(this->cardError);
			this->panelContenido->Controls->Add(this->cardDormida);
			this->panelContenido->Controls->Add(this->cardIgnorada);
			this->panelContenido->Controls->Add(this->grpMedicamento);
			this->panelContenido->Controls->Add(this->grpDias);
			this->panelContenido->Controls->Add(this->grpDetalle);
			this->panelContenido->Controls->Add(this->grpObservaciones);
			this->panelContenido->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panelContenido->Location = System::Drawing::Point(0, 84);
			this->panelContenido->Name = L"panelContenido";
			this->panelContenido->Size = System::Drawing::Size(1360, 676);
			this->panelContenido->TabIndex = 0;
			// 
			// panelAlerta
			// 
			this->panelAlerta->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(238)),
				static_cast<System::Int32>(static_cast<System::Byte>(238)));
			this->panelAlerta->Controls->Add(this->lblAlerta);
			this->panelAlerta->Location = System::Drawing::Point(22, 18);
			this->panelAlerta->Name = L"panelAlerta";
			this->panelAlerta->Size = System::Drawing::Size(1300, 54);
			this->panelAlerta->TabIndex = 0;
			// 
			// lblAlerta
			// 
			this->lblAlerta->AutoSize = true;
			this->lblAlerta->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular));
			this->lblAlerta->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(150)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
				static_cast<System::Int32>(static_cast<System::Byte>(40)));
			this->lblAlerta->Location = System::Drawing::Point(18, 16);
			this->lblAlerta->Name = L"lblAlerta";
			this->lblAlerta->Size = System::Drawing::Size(509, 23);
			this->lblAlerta->TabIndex = 0;
			this->lblAlerta->Text = L"Sin dosis de alto riesgo omitidas para los filtros seleccionados.";
			// 
			// panelFiltros
			// 
			this->panelFiltros->BackColor = System::Drawing::Color::White;
			this->panelFiltros->Controls->Add(this->lblPacienteFiltro);
			this->panelFiltros->Controls->Add(this->cmbPaciente);
			this->panelFiltros->Controls->Add(this->lblDesde);
			this->panelFiltros->Controls->Add(this->dtpDesde);
			this->panelFiltros->Controls->Add(this->lblHasta);
			this->panelFiltros->Controls->Add(this->dtpHasta);
			this->panelFiltros->Controls->Add(this->lblMedicamentoFiltro);
			this->panelFiltros->Controls->Add(this->cmbMedicamento);
			this->panelFiltros->Controls->Add(this->lblTurnoFiltro);
			this->panelFiltros->Controls->Add(this->cmbTurno);
			this->panelFiltros->Controls->Add(this->btnAplicar);
			this->panelFiltros->Controls->Add(this->btnRestablecer);
			this->panelFiltros->Location = System::Drawing::Point(22, 88);
			this->panelFiltros->Name = L"panelFiltros";
			this->panelFiltros->Size = System::Drawing::Size(1300, 104);
			this->panelFiltros->TabIndex = 1;
			// 
			// lblPacienteFiltro
			// 
			this->lblPacienteFiltro->AutoSize = true;
			this->lblPacienteFiltro->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblPacienteFiltro->ForeColor = System::Drawing::Color::FromArgb(90, 115, 140);
			this->lblPacienteFiltro->Location = System::Drawing::Point(16, 13);
			this->lblPacienteFiltro->Name = L"lblPacienteFiltro";
			this->lblPacienteFiltro->Size = System::Drawing::Size(68, 20);
			this->lblPacienteFiltro->TabIndex = 0;
			this->lblPacienteFiltro->Text = L"Paciente";
			// 
			// cmbPaciente
			// 
			this->cmbPaciente->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbPaciente->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->cmbPaciente->BackColor = System::Drawing::Color::White;
			this->cmbPaciente->ForeColor = System::Drawing::Color::FromArgb(30, 50, 70);
			this->cmbPaciente->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F));
			this->cmbPaciente->Location = System::Drawing::Point(16, 40);
			this->cmbPaciente->Name = L"cmbPaciente";
			this->cmbPaciente->Size = System::Drawing::Size(210, 24);
			this->cmbPaciente->TabIndex = 1;
			this->cmbPaciente->SelectedIndexChanged += gcnew System::EventHandler(this, &frmDosisOmitidas::cmbPaciente_SelectedIndexChanged);
			// 
			// lblDesde
			// 
			this->lblDesde->AutoSize = true;
			this->lblDesde->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblDesde->ForeColor = System::Drawing::Color::FromArgb(90, 115, 140);
			this->lblDesde->Location = System::Drawing::Point(240, 13);
			this->lblDesde->Name = L"lblDesde";
			this->lblDesde->Size = System::Drawing::Size(52, 20);
			this->lblDesde->TabIndex = 2;
			this->lblDesde->Text = L"Desde";
			// 
			// dtpDesde
			// 
			this->dtpDesde->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dtpDesde->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F));
			this->dtpDesde->CalendarForeColor = System::Drawing::Color::FromArgb(30, 50, 70);
			this->dtpDesde->Location = System::Drawing::Point(240, 40);
			this->dtpDesde->Name = L"dtpDesde";
			this->dtpDesde->Size = System::Drawing::Size(140, 22);
			this->dtpDesde->TabIndex = 3;
			// 
			// lblHasta
			// 
			this->lblHasta->AutoSize = true;
			this->lblHasta->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblHasta->ForeColor = System::Drawing::Color::FromArgb(90, 115, 140);
			this->lblHasta->Location = System::Drawing::Point(394, 13);
			this->lblHasta->Name = L"lblHasta";
			this->lblHasta->Size = System::Drawing::Size(49, 20);
			this->lblHasta->TabIndex = 4;
			this->lblHasta->Text = L"Hasta";
			// 
			// dtpHasta
			// 
			this->dtpHasta->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dtpHasta->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F));
			this->dtpHasta->CalendarForeColor = System::Drawing::Color::FromArgb(30, 50, 70);
			this->dtpHasta->Location = System::Drawing::Point(394, 40);
			this->dtpHasta->Name = L"dtpHasta";
			this->dtpHasta->Size = System::Drawing::Size(140, 22);
			this->dtpHasta->TabIndex = 5;
			// 
			// lblMedicamentoFiltro
			// 
			this->lblMedicamentoFiltro->AutoSize = true;
			this->lblMedicamentoFiltro->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblMedicamentoFiltro->ForeColor = System::Drawing::Color::FromArgb(90, 115, 140);
			this->lblMedicamentoFiltro->Location = System::Drawing::Point(548, 13);
			this->lblMedicamentoFiltro->Name = L"lblMedicamentoFiltro";
			this->lblMedicamentoFiltro->Size = System::Drawing::Size(105, 20);
			this->lblMedicamentoFiltro->TabIndex = 6;
			this->lblMedicamentoFiltro->Text = L"Medicamento";
			// 
			// cmbMedicamento
			// 
			this->cmbMedicamento->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbMedicamento->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->cmbMedicamento->BackColor = System::Drawing::Color::White;
			this->cmbMedicamento->ForeColor = System::Drawing::Color::FromArgb(30, 50, 70);
			this->cmbMedicamento->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F));
			this->cmbMedicamento->Location = System::Drawing::Point(548, 40);
			this->cmbMedicamento->Name = L"cmbMedicamento";
			this->cmbMedicamento->Size = System::Drawing::Size(205, 24);
			this->cmbMedicamento->TabIndex = 7;
			// 
			// lblTurnoFiltro
			// 
			this->lblTurnoFiltro->AutoSize = true;
			this->lblTurnoFiltro->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblTurnoFiltro->ForeColor = System::Drawing::Color::FromArgb(90, 115, 140);
			this->lblTurnoFiltro->Location = System::Drawing::Point(767, 13);
			this->lblTurnoFiltro->Name = L"lblTurnoFiltro";
			this->lblTurnoFiltro->Size = System::Drawing::Size(50, 20);
			this->lblTurnoFiltro->TabIndex = 8;
			this->lblTurnoFiltro->Text = L"Turno";
			// 
			// cmbTurno
			// 
			this->cmbTurno->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbTurno->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->cmbTurno->BackColor = System::Drawing::Color::White;
			this->cmbTurno->ForeColor = System::Drawing::Color::FromArgb(30, 50, 70);
			this->cmbTurno->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F));
			this->cmbTurno->Location = System::Drawing::Point(767, 40);
			this->cmbTurno->Name = L"cmbTurno";
			this->cmbTurno->Size = System::Drawing::Size(170, 24);
			this->cmbTurno->TabIndex = 9;
			// 
			// btnAplicar
			// 
			this->btnAplicar->BackColor = System::Drawing::Color::FromArgb(234, 243, 222);
			this->btnAplicar->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(168, 208, 106);
			this->btnAplicar->FlatAppearance->BorderSize = 1;
			this->btnAplicar->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(192, 221, 151);
			this->btnAplicar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnAplicar->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F, System::Drawing::FontStyle::Regular));
			this->btnAplicar->ForeColor = System::Drawing::Color::FromArgb(39, 80, 10);
			this->btnAplicar->Location = System::Drawing::Point(955, 34);
			this->btnAplicar->Name = L"btnAplicar";
			this->btnAplicar->Size = System::Drawing::Size(155, 36);
			this->btnAplicar->TabIndex = 10;
			this->btnAplicar->Text = L"Aplicar filtros";
			this->btnAplicar->UseVisualStyleBackColor = false;
			this->btnAplicar->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnAplicar->Click += gcnew System::EventHandler(this, &frmDosisOmitidas::btnAplicar_Click);
			// 
			// btnRestablecer
			// 
			this->btnRestablecer->BackColor = System::Drawing::Color::FromArgb(230, 241, 251);
			this->btnRestablecer->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(158, 198, 240);
			this->btnRestablecer->FlatAppearance->BorderSize = 1;
			this->btnRestablecer->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(181, 212, 244);
			this->btnRestablecer->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnRestablecer->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F, System::Drawing::FontStyle::Regular));
			this->btnRestablecer->ForeColor = System::Drawing::Color::FromArgb(12, 68, 124);
			this->btnRestablecer->Location = System::Drawing::Point(1125, 34);
			this->btnRestablecer->Name = L"btnRestablecer";
			this->btnRestablecer->Size = System::Drawing::Size(155, 36);
			this->btnRestablecer->TabIndex = 11;
			this->btnRestablecer->Text = L"Restablecer";
			this->btnRestablecer->UseVisualStyleBackColor = false;
			this->btnRestablecer->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnRestablecer->Click += gcnew System::EventHandler(this, &frmDosisOmitidas::btnRestablecer_Click);
			// 
			// cardOmitidas
			// 
			this->cardOmitidas->BackColor = System::Drawing::Color::White;
			this->cardOmitidas->Controls->Add(this->lblCardOmitidas);
			this->cardOmitidas->Controls->Add(this->lblOmitidas);
			this->cardOmitidas->Controls->Add(this->lblOmitidasSub);
			this->cardOmitidas->Location = System::Drawing::Point(22, 208);
			this->cardOmitidas->Name = L"cardOmitidas";
			this->cardOmitidas->Size = System::Drawing::Size(244, 132);
			this->cardOmitidas->TabIndex = 2;
			// 
			// lblCardOmitidas
			// 
			this->lblCardOmitidas->AutoSize = true;
			this->lblCardOmitidas->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblCardOmitidas->ForeColor = System::Drawing::Color::FromArgb(90, 115, 140);
			this->lblCardOmitidas->Location = System::Drawing::Point(16, 16);
			this->lblCardOmitidas->Name = L"lblCardOmitidas";
			this->lblCardOmitidas->Size = System::Drawing::Size(112, 20);
			this->lblCardOmitidas->TabIndex = 0;
			this->lblCardOmitidas->Text = L"Dosis omitidas";
			// 
			// lblOmitidas
			// 
			this->lblOmitidas->AutoSize = true;
			this->lblOmitidas->Font = (gcnew System::Drawing::Font(L"Segoe UI", 20, System::Drawing::FontStyle::Bold));
			this->lblOmitidas->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(180)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->lblOmitidas->Location = System::Drawing::Point(16, 45);
			this->lblOmitidas->Name = L"lblOmitidas";
			this->lblOmitidas->Size = System::Drawing::Size(40, 46);
			this->lblOmitidas->TabIndex = 1;
			this->lblOmitidas->Text = L"0";
			// 
			// lblOmitidasSub
			// 
			this->lblOmitidasSub->AutoSize = true;
			this->lblOmitidasSub->ForeColor = System::Drawing::Color::DimGray;
			this->lblOmitidasSub->Location = System::Drawing::Point(18, 92);
			this->lblOmitidasSub->Name = L"lblOmitidasSub";
			this->lblOmitidasSub->Size = System::Drawing::Size(86, 16);
			this->lblOmitidasSub->TabIndex = 2;
			this->lblOmitidasSub->Text = L"en el periodo";
			// 
			// cardRiesgo
			// 
			this->cardRiesgo->BackColor = System::Drawing::Color::White;
			this->cardRiesgo->Controls->Add(this->lblCardRiesgo);
			this->cardRiesgo->Controls->Add(this->lblRiesgo);
			this->cardRiesgo->Controls->Add(this->lblRiesgoSub);
			this->cardRiesgo->Location = System::Drawing::Point(284, 208);
			this->cardRiesgo->Name = L"cardRiesgo";
			this->cardRiesgo->Size = System::Drawing::Size(244, 132);
			this->cardRiesgo->TabIndex = 3;
			// 
			// lblCardRiesgo
			// 
			this->lblCardRiesgo->AutoSize = true;
			this->lblCardRiesgo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblCardRiesgo->ForeColor = System::Drawing::Color::FromArgb(90, 115, 140);
			this->lblCardRiesgo->Location = System::Drawing::Point(16, 16);
			this->lblCardRiesgo->Name = L"lblCardRiesgo";
			this->lblCardRiesgo->Size = System::Drawing::Size(87, 20);
			this->lblCardRiesgo->TabIndex = 0;
			this->lblCardRiesgo->Text = L"Riesgo alto";
			// 
			// lblRiesgo
			// 
			this->lblRiesgo->AutoSize = true;
			this->lblRiesgo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 20, System::Drawing::FontStyle::Bold));
			this->lblRiesgo->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(180)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->lblRiesgo->Location = System::Drawing::Point(16, 45);
			this->lblRiesgo->Name = L"lblRiesgo";
			this->lblRiesgo->Size = System::Drawing::Size(40, 46);
			this->lblRiesgo->TabIndex = 1;
			this->lblRiesgo->Text = L"0";
			// 
			// lblRiesgoSub
			// 
			this->lblRiesgoSub->AutoSize = true;
			this->lblRiesgoSub->ForeColor = System::Drawing::Color::DimGray;
			this->lblRiesgoSub->Location = System::Drawing::Point(18, 92);
			this->lblRiesgoSub->Name = L"lblRiesgoSub";
			this->lblRiesgoSub->Size = System::Drawing::Size(118, 16);
			this->lblRiesgoSub->TabIndex = 2;
			this->lblRiesgoSub->Text = L"requieren atencion";
			// 
			// cardError
			// 
			this->cardError->BackColor = System::Drawing::Color::White;
			this->cardError->Controls->Add(this->lblCardError);
			this->cardError->Controls->Add(this->lblError);
			this->cardError->Controls->Add(this->lblErrorSub);
			this->cardError->Location = System::Drawing::Point(546, 208);
			this->cardError->Name = L"cardError";
			this->cardError->Size = System::Drawing::Size(244, 132);
			this->cardError->TabIndex = 4;
			// 
			// lblCardError
			// 
			this->lblCardError->AutoSize = true;
			this->lblCardError->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblCardError->ForeColor = System::Drawing::Color::FromArgb(90, 115, 140);
			this->lblCardError->Location = System::Drawing::Point(16, 16);
			this->lblCardError->Name = L"lblCardError";
			this->lblCardError->Size = System::Drawing::Size(154, 20);
			this->lblCardError->TabIndex = 0;
			this->lblCardError->Text = L"Error de dispensador";
			// 
			// lblError
			// 
			this->lblError->AutoSize = true;
			this->lblError->Font = (gcnew System::Drawing::Font(L"Segoe UI", 20, System::Drawing::FontStyle::Bold));
			this->lblError->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(190)), static_cast<System::Int32>(static_cast<System::Byte>(120)),
				static_cast<System::Int32>(static_cast<System::Byte>(20)));
			this->lblError->Location = System::Drawing::Point(16, 45);
			this->lblError->Name = L"lblError";
			this->lblError->Size = System::Drawing::Size(40, 46);
			this->lblError->TabIndex = 1;
			this->lblError->Text = L"0";
			// 
			// lblErrorSub
			// 
			this->lblErrorSub->AutoSize = true;
			this->lblErrorSub->ForeColor = System::Drawing::Color::DimGray;
			this->lblErrorSub->Location = System::Drawing::Point(18, 92);
			this->lblErrorSub->Name = L"lblErrorSub";
			this->lblErrorSub->Size = System::Drawing::Size(100, 16);
			this->lblErrorSub->TabIndex = 2;
			this->lblErrorSub->Text = L"revision tecnica";
			// 
			// cardDormida
			// 
			this->cardDormida->BackColor = System::Drawing::Color::White;
			this->cardDormida->Controls->Add(this->lblCardDormida);
			this->cardDormida->Controls->Add(this->lblDormida);
			this->cardDormida->Controls->Add(this->lblDormidaSub);
			this->cardDormida->Location = System::Drawing::Point(808, 208);
			this->cardDormida->Name = L"cardDormida";
			this->cardDormida->Size = System::Drawing::Size(244, 132);
			this->cardDormida->TabIndex = 5;
			// 
			// lblCardDormida
			// 
			this->lblCardDormida->AutoSize = true;
			this->lblCardDormida->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblCardDormida->ForeColor = System::Drawing::Color::FromArgb(90, 115, 140);
			this->lblCardDormida->Location = System::Drawing::Point(16, 16);
			this->lblCardDormida->Name = L"lblCardDormida";
			this->lblCardDormida->Size = System::Drawing::Size(131, 20);
			this->lblCardDormida->TabIndex = 0;
			this->lblCardDormida->Text = L"Paciente dormida";
			// 
			// lblDormida
			// 
			this->lblDormida->AutoSize = true;
			this->lblDormida->Font = (gcnew System::Drawing::Font(L"Segoe UI", 20, System::Drawing::FontStyle::Bold));
			this->lblDormida->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(55)), static_cast<System::Int32>(static_cast<System::Byte>(138)),
				static_cast<System::Int32>(static_cast<System::Byte>(221)));
			this->lblDormida->Location = System::Drawing::Point(16, 45);
			this->lblDormida->Name = L"lblDormida";
			this->lblDormida->Size = System::Drawing::Size(40, 46);
			this->lblDormida->TabIndex = 1;
			this->lblDormida->Text = L"0";
			// 
			// lblDormidaSub
			// 
			this->lblDormidaSub->AutoSize = true;
			this->lblDormidaSub->ForeColor = System::Drawing::Color::DimGray;
			this->lblDormidaSub->Location = System::Drawing::Point(18, 92);
			this->lblDormidaSub->Name = L"lblDormidaSub";
			this->lblDormidaSub->Size = System::Drawing::Size(102, 16);
			this->lblDormidaSub->TabIndex = 2;
			this->lblDormidaSub->Text = L"causa probable";
			// 
			// cardIgnorada
			// 
			this->cardIgnorada->BackColor = System::Drawing::Color::White;
			this->cardIgnorada->Controls->Add(this->lblCardIgnorada);
			this->cardIgnorada->Controls->Add(this->lblIgnorada);
			this->cardIgnorada->Controls->Add(this->lblIgnoradaSub);
			this->cardIgnorada->Location = System::Drawing::Point(1070, 208);
			this->cardIgnorada->Name = L"cardIgnorada";
			this->cardIgnorada->Size = System::Drawing::Size(252, 132);
			this->cardIgnorada->TabIndex = 6;
			// 
			// lblCardIgnorada
			// 
			this->lblCardIgnorada->AutoSize = true;
			this->lblCardIgnorada->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblCardIgnorada->ForeColor = System::Drawing::Color::FromArgb(90, 115, 140);
			this->lblCardIgnorada->Location = System::Drawing::Point(16, 16);
			this->lblCardIgnorada->Name = L"lblCardIgnorada";
			this->lblCardIgnorada->Size = System::Drawing::Size(125, 20);
			this->lblCardIgnorada->TabIndex = 0;
			this->lblCardIgnorada->Text = L"Pastilla ignorada";
			// 
			// lblIgnorada
			// 
			this->lblIgnorada->AutoSize = true;
			this->lblIgnorada->Font = (gcnew System::Drawing::Font(L"Segoe UI", 20, System::Drawing::FontStyle::Bold));
			this->lblIgnorada->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(190)), static_cast<System::Int32>(static_cast<System::Byte>(120)),
				static_cast<System::Int32>(static_cast<System::Byte>(20)));
			this->lblIgnorada->Location = System::Drawing::Point(16, 45);
			this->lblIgnorada->Name = L"lblIgnorada";
			this->lblIgnorada->Size = System::Drawing::Size(40, 46);
			this->lblIgnorada->TabIndex = 1;
			this->lblIgnorada->Text = L"0";
			// 
			// lblIgnoradaSub
			// 
			this->lblIgnoradaSub->AutoSize = true;
			this->lblIgnoradaSub->ForeColor = System::Drawing::Color::DimGray;
			this->lblIgnoradaSub->Location = System::Drawing::Point(18, 92);
			this->lblIgnoradaSub->Name = L"lblIgnoradaSub";
			this->lblIgnoradaSub->Size = System::Drawing::Size(149, 16);
			this->lblIgnoradaSub->TabIndex = 2;
			this->lblIgnoradaSub->Text = L"dispensada, no tomada";
			// 
			// grpMedicamento
			// 
			this->grpMedicamento->BackColor = System::Drawing::Color::White;
			this->grpMedicamento->Controls->Add(this->chartMedicamento);
			this->grpMedicamento->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular));
			this->grpMedicamento->Location = System::Drawing::Point(22, 360);
			this->grpMedicamento->Name = L"grpMedicamento";
			this->grpMedicamento->Size = System::Drawing::Size(640, 330);
			this->grpMedicamento->TabIndex = 7;
			this->grpMedicamento->TabStop = false;
			this->grpMedicamento->Text = L"Omisiones por medicamento";
			// 
			// chartMedicamento
			// 
			chartArea3->Name = L"AreaMedicamento";
			this->chartMedicamento->ChartAreas->Add(chartArea3);
			this->chartMedicamento->Dock = System::Windows::Forms::DockStyle::Fill;
			this->chartMedicamento->Location = System::Drawing::Point(3, 26);
			this->chartMedicamento->Name = L"chartMedicamento";
			series3->ChartArea = L"AreaMedicamento";
			series3->Name = L"Omisiones";
			this->chartMedicamento->Series->Add(series3);
			this->chartMedicamento->Size = System::Drawing::Size(634, 301);
			this->chartMedicamento->TabIndex = 0;
			// 
			// grpDias
			// 
			this->grpDias->BackColor = System::Drawing::Color::White;
			this->grpDias->Controls->Add(this->chartDias);
			this->grpDias->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular));
			this->grpDias->Location = System::Drawing::Point(682, 360);
			this->grpDias->Name = L"grpDias";
			this->grpDias->Size = System::Drawing::Size(640, 330);
			this->grpDias->TabIndex = 8;
			this->grpDias->TabStop = false;
			this->grpDias->Text = L"Omisiones por dia";
			// 
			// chartDias
			// 
			chartArea4->Name = L"AreaDias";
			this->chartDias->ChartAreas->Add(chartArea4);
			this->chartDias->Dock = System::Windows::Forms::DockStyle::Fill;
			this->chartDias->Location = System::Drawing::Point(3, 26);
			this->chartDias->Name = L"chartDias";
			series4->ChartArea = L"AreaDias";
			series4->Name = L"Omisiones";
			this->chartDias->Series->Add(series4);
			this->chartDias->Size = System::Drawing::Size(634, 301);
			this->chartDias->TabIndex = 0;
			// 
			// grpDetalle
			// 
			this->grpDetalle->BackColor = System::Drawing::Color::White;
			this->grpDetalle->Controls->Add(this->dgvDetalle);
			this->grpDetalle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular));
			this->grpDetalle->Location = System::Drawing::Point(22, 708);
			this->grpDetalle->Name = L"grpDetalle";
			this->grpDetalle->Size = System::Drawing::Size(1300, 330);
			this->grpDetalle->TabIndex = 10;
			this->grpDetalle->TabStop = false;
			this->grpDetalle->Text = L"Listado detallado de dosis omitidas";
			// 
			// dgvDetalle
			// 
			this->dgvDetalle->AllowUserToAddRows = false;
			this->dgvDetalle->AllowUserToDeleteRows = false;
			this->dgvDetalle->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dgvDetalle->BackgroundColor = System::Drawing::Color::FromArgb(247, 249, 251);
			this->dgvDetalle->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::SingleHorizontal;
			this->dgvDetalle->GridColor = System::Drawing::Color::FromArgb(220, 230, 240);
			this->dgvDetalle->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
			this->dgvDetalle->EnableHeadersVisualStyles = false;
			this->dgvDetalle->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
			this->dgvDetalle->ColumnHeadersHeight = 36;
			this->dgvDetalle->ColumnHeadersDefaultCellStyle->BackColor = System::Drawing::Color::FromArgb(36, 66, 98);
			this->dgvDetalle->ColumnHeadersDefaultCellStyle->ForeColor = System::Drawing::Color::FromArgb(200, 218, 235);
			this->dgvDetalle->ColumnHeadersDefaultCellStyle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.5F, System::Drawing::FontStyle::Regular));
			this->dgvDetalle->ColumnHeadersDefaultCellStyle->SelectionBackColor = System::Drawing::Color::FromArgb(36, 66, 98);
			this->dgvDetalle->ColumnHeadersDefaultCellStyle->SelectionForeColor = System::Drawing::Color::FromArgb(200, 218, 235);
			this->dgvDetalle->DefaultCellStyle->BackColor = System::Drawing::Color::White;
			this->dgvDetalle->DefaultCellStyle->ForeColor = System::Drawing::Color::FromArgb(40, 60, 80);
			this->dgvDetalle->DefaultCellStyle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F));
			this->dgvDetalle->DefaultCellStyle->SelectionBackColor = System::Drawing::Color::FromArgb(210, 228, 248);
			this->dgvDetalle->DefaultCellStyle->SelectionForeColor = System::Drawing::Color::FromArgb(12, 52, 100);
			this->dgvDetalle->RowTemplate->Height = 32;
			this->dgvDetalle->BorderStyle = System::Windows::Forms::BorderStyle::None;

			this->dgvDetalle->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(9) {
				this->colEvento,
					this->colFecha, this->colTurno, this->colHora, this->colPaciente, this->colMedicamento, this->colDispensado, this->colCausa,
					this->colRiesgo
			});
			this->dgvDetalle->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dgvDetalle->Location = System::Drawing::Point(3, 26);
			this->dgvDetalle->Name = L"dgvDetalle";
			this->dgvDetalle->ReadOnly = true;
			this->dgvDetalle->RowHeadersVisible = false;
			this->dgvDetalle->RowHeadersWidth = 51;
			this->dgvDetalle->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dgvDetalle->Size = System::Drawing::Size(1294, 301);
			this->dgvDetalle->TabIndex = 0;
			// 
			// colEvento
			// 
			this->colEvento->MinimumWidth = 6;
			this->colEvento->Name = L"colEvento";
			this->colEvento->ReadOnly = true;
			// 
			// colFecha
			// 
			this->colFecha->MinimumWidth = 6;
			this->colFecha->Name = L"colFecha";
			this->colFecha->ReadOnly = true;
			// 
			// colTurno
			// 
			this->colTurno->MinimumWidth = 6;
			this->colTurno->Name = L"colTurno";
			this->colTurno->ReadOnly = true;
			// 
			// colHora
			// 
			this->colHora->MinimumWidth = 6;
			this->colHora->Name = L"colHora";
			this->colHora->ReadOnly = true;
			// 
			// colPaciente
			// 
			this->colPaciente->MinimumWidth = 6;
			this->colPaciente->Name = L"colPaciente";
			this->colPaciente->ReadOnly = true;
			// 
			// colMedicamento
			// 
			this->colMedicamento->MinimumWidth = 6;
			this->colMedicamento->Name = L"colMedicamento";
			this->colMedicamento->ReadOnly = true;
			// 
			// colDispensado
			// 
			this->colDispensado->MinimumWidth = 6;
			this->colDispensado->Name = L"colDispensado";
			this->colDispensado->ReadOnly = true;
			// 
			// colCausa
			// 
			this->colCausa->MinimumWidth = 6;
			this->colCausa->Name = L"colCausa";
			this->colCausa->ReadOnly = true;
			// 
			// colRiesgo
			// 
			this->colRiesgo->MinimumWidth = 6;
			this->colRiesgo->Name = L"colRiesgo";
			this->colRiesgo->ReadOnly = true;
			// 
			// grpObservaciones
			// 
			this->grpObservaciones->BackColor = System::Drawing::Color::White;
			this->grpObservaciones->Controls->Add(this->txtObservaciones);
			this->grpObservaciones->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular));
			this->grpObservaciones->Location = System::Drawing::Point(22, 1058);
			this->grpObservaciones->Name = L"grpObservaciones";
			this->grpObservaciones->Size = System::Drawing::Size(1300, 180);
			this->grpObservaciones->TabIndex = 11;
			this->grpObservaciones->TabStop = false;
			this->grpObservaciones->Text = L"Observaciones automaticas";
			// 
			// txtObservaciones
			// 
			this->txtObservaciones->BackColor = System::Drawing::Color::FromArgb(247, 249, 251);
			this->txtObservaciones->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txtObservaciones->Dock = System::Windows::Forms::DockStyle::Fill;
			this->txtObservaciones->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F));
			this->txtObservaciones->ForeColor = System::Drawing::Color::FromArgb(40, 60, 80);
			this->txtObservaciones->Location = System::Drawing::Point(3, 26);
			this->txtObservaciones->Name = L"txtObservaciones";
			this->txtObservaciones->ReadOnly = true;
			this->txtObservaciones->Size = System::Drawing::Size(1294, 151);
			this->txtObservaciones->TabIndex = 0;
			this->txtObservaciones->Text = L"";
			// 
			// frmDosisOmitidas
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(241, 244, 248);
			this->ClientSize = System::Drawing::Size(1360, 760);
			this->ControlBox = false;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Controls->Add(this->panelContenido);
			this->Controls->Add(this->panelCabecera);
			this->Name = L"frmDosisOmitidas";
			this->Text = L"";
			this->Load += gcnew System::EventHandler(
				this,
				&frmDosisOmitidas::frmDosisOmitidas_Load
			);
			this->Resize += gcnew System::EventHandler(
				this,
				&frmDosisOmitidas::frmDosisOmitidas_Resize
			);
			this->panelCabecera->ResumeLayout(false);
			this->panelCabecera->PerformLayout();
			this->panelContenido->ResumeLayout(false);
			this->panelAlerta->ResumeLayout(false);
			this->panelAlerta->PerformLayout();
			this->panelFiltros->ResumeLayout(false);
			this->panelFiltros->PerformLayout();
			this->cardOmitidas->ResumeLayout(false);
			this->cardOmitidas->PerformLayout();
			this->cardRiesgo->ResumeLayout(false);
			this->cardRiesgo->PerformLayout();
			this->cardError->ResumeLayout(false);
			this->cardError->PerformLayout();
			this->cardDormida->ResumeLayout(false);
			this->cardDormida->PerformLayout();
			this->cardIgnorada->ResumeLayout(false);
			this->cardIgnorada->PerformLayout();
			this->grpMedicamento->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartMedicamento))->EndInit();
			this->grpDias->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartDias))->EndInit();
			this->grpDetalle->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvDetalle))->EndInit();
			this->grpObservaciones->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion

	private:
		void PrepararColumnasDisenador() {
			array<DataGridViewTextBoxColumn^>^ columnas = { colEvento,colFecha,colTurno,colHora,colPaciente,colMedicamento,colDispensado,colCausa,colRiesgo };
			array<String^>^ textos = { "# Evento","Fecha","Turno","Hora programada","Paciente","Medicamento","Dispensado","Causa probable","Riesgo" };
			array<float>^ pesos = { 55,80,70,90,115,105,80,125,65 };
			for (int i = 0; i < columnas->Length; i++) {
				columnas[i]->HeaderText = textos[i]; columnas[i]->AutoSizeMode = DataGridViewAutoSizeColumnMode::Fill;
				columnas[i]->FillWeight = pesos[i]; columnas[i]->ReadOnly = true;
			}
		}

		bool Contiene(String^ texto, String^ valor) {
			return !String::IsNullOrWhiteSpace(texto) && texto->IndexOf(valor, StringComparison::OrdinalIgnoreCase) >= 0;
		}
		bool EsOmitida(LogEvento^ e) {
			return e != nullptr && (Contiene(e->getTipoEvento(), "Toma") || Contiene(e->getTipoEvento(), "Dosis")) &&
				(Contiene(e->getEstado(), "No tomada") || Contiene(e->getEstado(), "Omitida") || Contiene(e->getEstado(), "Omision"));
		}
		String^ Turno(DateTime fecha) {
			int hora = fecha.Hour; return hora >= 5 && hora < 12 ? "Manana" : hora >= 12 && hora < 18 ? "Tarde" : "Noche";
		}
		int IdSeleccionado(ComboBox^ combo) {
			if (combo->SelectedIndex <= 0 || combo->SelectedItem == nullptr) return 0;
			String^ valor = combo->SelectedItem->ToString(); int pos = valor->IndexOf(" - "); int id = 0;
			return pos > 0 && Int32::TryParse(valor->Substring(0, pos), id) ? id : 0;
		}
		bool EsRiesgoAlto(int id) { return riesgosAltos->ContainsKey(id) && riesgosAltos[id]; }
		String^ Causa(LogEvento^ e) { return String::IsNullOrWhiteSpace(e->getDetalle()) ? "Sin detalle" : e->getDetalle(); }
		bool FueDispensada(LogEvento^ e) { return !Contiene(Causa(e), "Error de dispensador") && !Contiene(Causa(e), "no encontrada"); }

		List<LogEvento^>^ Filtrar() {
			List<LogEvento^>^ lista = gcnew List<LogEvento^>(); int paciente = IdSeleccionado(cmbPaciente), medicamento = IdSeleccionado(cmbMedicamento);
			String^ turno = cmbTurno->SelectedItem == nullptr ? "Todos los turnos" : cmbTurno->SelectedItem->ToString();
			for each(LogEvento ^ e in reportesController->ObtenerTodos()) {
				if (!EsOmitida(e) || e->getFechaHoraProgramada() == DateTime::MinValue) continue;
				if (e->getFechaHoraProgramada().Date<dtpDesde->Value.Date || e->getFechaHoraProgramada().Date>dtpHasta->Value.Date) continue;
				if (paciente > 0 && e->getIdPaciente() != paciente) continue; if (medicamento > 0 && e->getIdMedicamento() != medicamento) continue;
				if (turno != "Todos los turnos" && Turno(e->getFechaHoraProgramada()) != turno) continue; lista->Add(e);
			}
			return lista;
		}

		void CargarFiltrosYRiesgos() {
			riesgosAltos = gcnew Dictionary<int, bool>(); for each(Medicamento ^ m in medicamentoController->ObtenerTodosMedicamentosTXT()) {
				Antibiotico^ a = dynamic_cast<Antibiotico^>(m); riesgosAltos[m->getId()] = a != nullptr;
			}
			SortedDictionary<int, String^>^ pacientes = gcnew SortedDictionary<int, String^>(); SortedDictionary<int, String^>^ medicamentos = gcnew SortedDictionary<int, String^>();
			DateTime min = DateTime::MaxValue, max = DateTime::MinValue;
			for each(LogEvento ^ e in reportesController->ObtenerTodos()) if (EsOmitida(e)) {
				if (e->getIdPaciente() > 0 && !pacientes->ContainsKey(e->getIdPaciente())) pacientes->Add(e->getIdPaciente(), e->getNombrePaciente());
				if (e->getIdMedicamento() > 0 && !medicamentos->ContainsKey(e->getIdMedicamento())) medicamentos->Add(e->getIdMedicamento(), e->getMedicamento());
				if (e->getFechaHoraProgramada() < min)min = e->getFechaHoraProgramada(); if (e->getFechaHoraProgramada() > max)max = e->getFechaHoraProgramada();
			}
			cmbPaciente->Items->Clear(); cmbPaciente->Items->Add("Todos los pacientes"); for each(KeyValuePair<int, String^> x in pacientes) cmbPaciente->Items->Add(x.Key + " - " + x.Value); cmbPaciente->SelectedIndex = 0;
			cmbMedicamento->Items->Clear(); cmbMedicamento->Items->Add("Todos los medicamentos"); for each(KeyValuePair<int, String^> x in medicamentos) cmbMedicamento->Items->Add(x.Key + " - " + x.Value); cmbMedicamento->SelectedIndex = 0;
			cmbTurno->Items->Clear(); cmbTurno->Items->AddRange(gcnew array<Object^>{"Todos los turnos", "Manana", "Tarde", "Noche"}); cmbTurno->SelectedIndex = 0;
			dtpDesde->Value = min == DateTime::MaxValue ? DateTime::Today.AddDays(-30) : min.Date; dtpHasta->Value = max == DateTime::MinValue ? DateTime::Today : max.Date;
		}

		void Ajustar() {
			chartMedicamento->Dock = DockStyle::None; chartDias->Dock = DockStyle::None; dgvDetalle->Dock = DockStyle::None;
			chartMedicamento->Bounds = grpMedicamento->DisplayRectangle; chartDias->Bounds = grpDias->DisplayRectangle;
			dgvDetalle->Bounds = grpDetalle->DisplayRectangle;
			AnchorStyles anclaje = AnchorStyles::Top | AnchorStyles::Bottom | AnchorStyles::Left | AnchorStyles::Right;
			chartMedicamento->Anchor = anclaje; chartDias->Anchor = anclaje; dgvDetalle->Anchor = anclaje;
			ChartArea^ a = chartMedicamento->ChartAreas["AreaMedicamento"]; a->Position->Auto = false; a->Position->X = 7; a->Position->Y = 7; a->Position->Width = 90; a->Position->Height = 85;
			a = chartDias->ChartAreas["AreaDias"]; a->Position->Auto = false; a->Position->X = 7; a->Position->Y = 7; a->Position->Width = 90; a->Position->Height = 85;
		}

		void Actualizar() {
			List<LogEvento^>^ eventos = Filtrar(); int alto = 0, error = 0, dormida = 0, ignorada = 0;
			Dictionary<String^, int>^ meds = gcnew Dictionary<String^, int>(); SortedDictionary<DateTime, List<LogEvento^>^>^ dias = gcnew SortedDictionary<DateTime, List<LogEvento^>^>();
			dgvDetalle->Rows->Clear();
			for each(LogEvento ^ e in eventos) {
				String^ causa = Causa(e);
				String^ med = String::IsNullOrWhiteSpace(e->getMedicamento()) ? "Sin medicamento" : e->getMedicamento();
				if (EsRiesgoAlto(e->getIdMedicamento()))alto++; if (Contiene(causa, "Error de dispensador"))error++; if (Contiene(causa, "dormida"))dormida++; if (Contiene(causa, "ignorada"))ignorada++;
				if (!meds->ContainsKey(med))meds->Add(med, 0); meds[med]++; DateTime dia = e->getFechaHoraProgramada().Date; if (!dias->ContainsKey(dia))dias->Add(dia, gcnew List<LogEvento^>()); dias[dia]->Add(e);
				int f = dgvDetalle->Rows->Add(e->getId(), e->getFechaHoraProgramada().ToString("dd/MM/yyyy"), Turno(e->getFechaHoraProgramada()), e->getFechaHoraProgramada().ToString("HH:mm"),
					e->getNombrePaciente(), med, FueDispensada(e) ? "Si" : "No", causa, EsRiesgoAlto(e->getIdMedicamento()) ? "Alto" : "Medio");
				dgvDetalle->Rows[f]->Cells[8]->Style->ForeColor = EsRiesgoAlto(e->getIdMedicamento()) ? Color::FromArgb(180, 50, 50) : Color::FromArgb(190, 120, 20);
			}
			lblOmitidas->Text = eventos->Count.ToString(); lblRiesgo->Text = alto.ToString(); lblError->Text = error.ToString(); lblDormida->Text = dormida.ToString(); lblIgnorada->Text = ignorada.ToString();
			lblAlerta->Text = alto > 0 ? String::Format("{0} dosis de alto riesgo omitidas. Se requiere revision prioritaria.", alto) : "Sin dosis de alto riesgo omitidas para los filtros seleccionados.";
			Series^ sm = chartMedicamento->Series["Omisiones"]; sm->Points->Clear(); for each(KeyValuePair<String^, int>x in meds)sm->Points->AddXY(x.Key, x.Value);
			Series^ sd = chartDias->Series["Omisiones"]; sd->Points->Clear();
			for each(KeyValuePair<DateTime, List<LogEvento^>^> x in dias) {
				int p = sd->Points->AddXY(x.Key.ToString("dd/MM"), x.Value->Count); sd->Points[p]->Color = Color::FromArgb(239, 159, 39);
			}
			txtObservaciones->Text = String::Format("En el periodo analizado se registraron {0} dosis omitidas, de las cuales {1} representan riesgo alto. Se detectaron {2} errores del dispensador, {3} casos de paciente dormida y {4} pastillas ignoradas. Se recomienda revisar las alertas y el mecanismo de dispensacion.", eventos->Count, alto, error, dormida, ignorada);
			lblGenerado->Text = "Generado: " + DateTime::Now.ToString("dd/MM/yyyy HH:mm"); dgvDetalle->ClearSelection();
		}


		void AjustarDistribucion() {
			int margen = 22;
			int separacion = 20;
			int anchoDisponible =
				this->panelContenido->ClientSize.Width - (margen * 2);

			if (anchoDisponible < 900)
				anchoDisponible = 900;

			int anchoMitad = (anchoDisponible - separacion) / 2;

			// Separación vertical uniforme entre todas las secciones
			int espacioVertical = 18;

			int yAlerta = 18;

			int yFiltros =
				yAlerta +
				this->panelAlerta->Height +
				espacioVertical;

			int yTarjetas =
				yFiltros +
				this->panelFiltros->Height +
				espacioVertical;

			int yGraficos =
				yTarjetas +
				this->cardOmitidas->Height +
				espacioVertical;

			int yDetalle =
				yGraficos +
				this->grpMedicamento->Height +
				espacioVertical;

			int yObservaciones =
				yDetalle +
				this->grpDetalle->Height +
				espacioVertical;

			// ?? Alerta superior ???????????????????????????????????????????????
			this->panelAlerta->Location =
				System::Drawing::Point(margen, yAlerta);
			this->panelAlerta->Width = anchoDisponible;

			// ?? Panel de filtros ???????????????????????????????????????????????
			this->panelFiltros->Location =
				System::Drawing::Point(margen, yFiltros);
			this->panelFiltros->Width = anchoDisponible;
			this->panelFiltros->Height = 104;

			int espacioInterno = 18;
			int separacionFiltro = 14;
			int anchoPaciente = 210;
			int anchoFecha = 140;
			int anchoMedicamento = 205;
			int anchoTurno = 170;
			int anchoBoton = 165;

			int x = espacioInterno;

			this->lblPacienteFiltro->Location =
				System::Drawing::Point(x, 13);
			this->cmbPaciente->Location =
				System::Drawing::Point(x, 40);
			this->cmbPaciente->Width = anchoPaciente;
			x += anchoPaciente + separacionFiltro;

			this->lblDesde->Location =
				System::Drawing::Point(x, 13);
			this->dtpDesde->Location =
				System::Drawing::Point(x, 40);
			this->dtpDesde->Width = anchoFecha;
			x += anchoFecha + separacionFiltro;

			this->lblHasta->Location =
				System::Drawing::Point(x, 13);
			this->dtpHasta->Location =
				System::Drawing::Point(x, 40);
			this->dtpHasta->Width = anchoFecha;
			x += anchoFecha + separacionFiltro;

			this->lblMedicamentoFiltro->Location =
				System::Drawing::Point(x, 13);
			this->cmbMedicamento->Location =
				System::Drawing::Point(x, 40);
			this->cmbMedicamento->Width = anchoMedicamento;
			x += anchoMedicamento + separacionFiltro;

			this->lblTurnoFiltro->Location =
				System::Drawing::Point(x, 13);
			this->cmbTurno->Location =
				System::Drawing::Point(x, 40);
			this->cmbTurno->Width = anchoTurno;

			// Botones alineados al extremo derecho
			int xRestablecer =
				this->panelFiltros->ClientSize.Width -
				espacioInterno -
				anchoBoton;

			int xAplicar =
				xRestablecer -
				separacionFiltro -
				anchoBoton;

			this->btnAplicar->Location =
				System::Drawing::Point(xAplicar, 34);
			this->btnAplicar->Width = anchoBoton;

			this->btnRestablecer->Location =
				System::Drawing::Point(xRestablecer, 34);
			this->btnRestablecer->Width = anchoBoton;

			// Evitar superposición en ventanas angostas
			if (x + anchoTurno + separacionFiltro > xAplicar) {
				this->cmbTurno->Width =
					Math::Max(100, xAplicar - separacionFiltro - x);
			}

			// ?? Cinco tarjetas ?????????????????????????????????????????????????
			array<System::Windows::Forms::Panel^>^ tarjetas = {
				this->cardOmitidas,
				this->cardRiesgo,
				this->cardError,
				this->cardDormida,
				this->cardIgnorada
			};

			int separacionTarjetas = 18;
			int anchoTarjeta =
				(anchoDisponible -
					separacionTarjetas * (tarjetas->Length - 1)) /
				tarjetas->Length;

			for (int i = 0; i < tarjetas->Length; i++) {
				tarjetas[i]->Location =
					System::Drawing::Point(
						margen + i * (anchoTarjeta + separacionTarjetas),
						yTarjetas
					);
				tarjetas[i]->Width = anchoTarjeta;
			}

			// ?? Gráficos ???????????????????????????????????????????????????????
			this->grpMedicamento->Location =
				System::Drawing::Point(margen, yGraficos);
			this->grpMedicamento->Width = anchoMitad;

			this->grpDias->Location =
				System::Drawing::Point(
					margen + anchoMitad + separacion,
					yGraficos
				);
			this->grpDias->Width = anchoMitad;

			// ?? Tabla y observaciones ??????????????????????????????????????????
			this->grpDetalle->Location =
				System::Drawing::Point(margen, yDetalle);
			this->grpDetalle->Width = anchoDisponible;

			this->grpObservaciones->Location =
				System::Drawing::Point(margen, yObservaciones);
			this->grpObservaciones->Width = anchoDisponible;

			Ajustar();
		}

		System::Void frmDosisOmitidas_Resize(
			System::Object^ sender,
			System::EventArgs^ e
		) {
			AjustarDistribucion();
		}

		System::Void frmDosisOmitidas_Load(System::Object^, System::EventArgs^) {
			reportesController = gcnew GeneradorReportesController();
			medicamentoController = gcnew MedicamentoController();
			CargarFiltrosYRiesgos();
			Actualizar();
			AjustarDistribucion();
			BeginInvoke(
				gcnew MethodInvoker(
					this,
					&frmDosisOmitidas::AjustarDistribucion
				)
			);
		}
		System::Void btnAplicar_Click(System::Object^, System::EventArgs^) {
			if (dtpDesde->Value.Date > dtpHasta->Value.Date) {
				MessageBox::Show("La fecha inicial no puede ser posterior a la fecha final.", "Dosis omitidas", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}
			Actualizar();
		}
		System::Void btnRestablecer_Click(System::Object^, System::EventArgs^) { reportesController->RefrescarDatos(); CargarFiltrosYRiesgos(); Actualizar(); }
	private: System::Void cardOmitidas_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}

	private: System::Void cmbPaciente_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		int idPaciente = IdSeleccionado(cmbPaciente);
		SortedDictionary<int, String^>^ medicamentos = gcnew SortedDictionary<int, String^>();
		for each(LogEvento ^ evento in reportesController->ObtenerTodos()) {
			if (idPaciente > 0 && evento->getIdPaciente() != idPaciente) continue;
			if (evento->getIdMedicamento() > 0 && !medicamentos->ContainsKey(evento->getIdMedicamento()))
				medicamentos->Add(evento->getIdMedicamento(), evento->getMedicamento());
		}
		cmbMedicamento->Items->Clear();
		cmbMedicamento->Items->Add("Todos los medicamentos");
		for each(KeyValuePair<int, String^> x in medicamentos)
			cmbMedicamento->Items->Add(x.Key + " - " + x.Value);
		cmbMedicamento->SelectedIndex = 0;
	}
	};
}
