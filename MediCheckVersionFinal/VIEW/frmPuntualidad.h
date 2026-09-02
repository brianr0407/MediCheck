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

	public ref class frmPuntualidad : public System::Windows::Forms::Form {
	public:
		frmPuntualidad() {
			InitializeComponent();
		}

	protected:
		~frmPuntualidad() {
			if (components)
				delete components;
		}

	private:
		System::ComponentModel::Container^ components;
		GeneradorReportesController^ controller;

		System::Windows::Forms::Panel^ panelCabecera;
		System::Windows::Forms::Label^ lblTitulo;
		System::Windows::Forms::Label^ lblSubtitulo;
		System::Windows::Forms::Label^ lblGenerado;
		System::Windows::Forms::Panel^ panelContenido;
		System::Windows::Forms::Panel^ panelFiltros;
		System::Windows::Forms::Label^ lblPacienteFiltro;
		System::Windows::Forms::ComboBox^ cmbPaciente;
		System::Windows::Forms::Label^ lblDesde;
		System::Windows::Forms::DateTimePicker^ dtpDesde;
		System::Windows::Forms::Label^ lblHasta;
		System::Windows::Forms::DateTimePicker^ dtpHasta;
		System::Windows::Forms::Label^ lblMedicamentoFiltro;
		System::Windows::Forms::ComboBox^ cmbMedicamento;
		System::Windows::Forms::Button^ btnAplicarFiltros;
		System::Windows::Forms::Button^ btnRestablecer;

		System::Windows::Forms::Panel^ cardProgramadas;
		System::Windows::Forms::Label^ lblCardProgramadasTitulo;
		System::Windows::Forms::Label^ lblProgramadas;
		System::Windows::Forms::Label^ lblProgramadasSub;
		System::Windows::Forms::Panel^ cardPuntuales;
		System::Windows::Forms::Label^ lblCardPuntualesTitulo;
		System::Windows::Forms::Label^ lblPuntuales;
		System::Windows::Forms::Label^ lblPuntualesSub;
		System::Windows::Forms::Panel^ cardRetrasos;
		System::Windows::Forms::Label^ lblCardRetrasosTitulo;
		System::Windows::Forms::Label^ lblRetrasos;
		System::Windows::Forms::Label^ lblRetrasosSub;
		System::Windows::Forms::Panel^ cardNoTomadas;
		System::Windows::Forms::Label^ lblCardNoTomadasTitulo;
		System::Windows::Forms::Label^ lblNoTomadas;
		System::Windows::Forms::Label^ lblNoTomadasSub;
		System::Windows::Forms::Panel^ cardIndice;
		System::Windows::Forms::Label^ lblCardIndiceTitulo;
		System::Windows::Forms::Label^ lblIndice;
		System::Windows::Forms::Label^ lblIndiceSub;

		System::Windows::Forms::GroupBox^ grpDesviacion;
		System::Windows::Forms::DataVisualization::Charting::Chart^ chartDesviacion;


		System::Windows::Forms::GroupBox^ grpDetalle;
		System::Windows::Forms::DataGridView^ dgvDetalle;
		System::Windows::Forms::DataGridViewTextBoxColumn^ colFecha;
		System::Windows::Forms::DataGridViewTextBoxColumn^ colMedicamento;
		System::Windows::Forms::DataGridViewTextBoxColumn^ colProgramada;
		System::Windows::Forms::DataGridViewTextBoxColumn^ colReal;
		System::Windows::Forms::DataGridViewTextBoxColumn^ colDesviacion;
		System::Windows::Forms::DataGridViewTextBoxColumn^ colEstado;
		System::Windows::Forms::GroupBox^ grpObservaciones;
		System::Windows::Forms::RichTextBox^ txtObservaciones;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void) {
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->panelCabecera = (gcnew System::Windows::Forms::Panel());
			this->lblTitulo = (gcnew System::Windows::Forms::Label());
			this->lblSubtitulo = (gcnew System::Windows::Forms::Label());
			this->lblGenerado = (gcnew System::Windows::Forms::Label());
			this->panelContenido = (gcnew System::Windows::Forms::Panel());
			this->panelFiltros = (gcnew System::Windows::Forms::Panel());
			this->lblPacienteFiltro = (gcnew System::Windows::Forms::Label());
			this->cmbPaciente = (gcnew System::Windows::Forms::ComboBox());
			this->lblDesde = (gcnew System::Windows::Forms::Label());
			this->dtpDesde = (gcnew System::Windows::Forms::DateTimePicker());
			this->lblHasta = (gcnew System::Windows::Forms::Label());
			this->dtpHasta = (gcnew System::Windows::Forms::DateTimePicker());
			this->lblMedicamentoFiltro = (gcnew System::Windows::Forms::Label());
			this->cmbMedicamento = (gcnew System::Windows::Forms::ComboBox());
			this->btnAplicarFiltros = (gcnew System::Windows::Forms::Button());
			this->btnRestablecer = (gcnew System::Windows::Forms::Button());
			this->cardProgramadas = (gcnew System::Windows::Forms::Panel());
			this->lblCardProgramadasTitulo = (gcnew System::Windows::Forms::Label());
			this->lblProgramadas = (gcnew System::Windows::Forms::Label());
			this->lblProgramadasSub = (gcnew System::Windows::Forms::Label());
			this->cardPuntuales = (gcnew System::Windows::Forms::Panel());
			this->lblCardPuntualesTitulo = (gcnew System::Windows::Forms::Label());
			this->lblPuntuales = (gcnew System::Windows::Forms::Label());
			this->lblPuntualesSub = (gcnew System::Windows::Forms::Label());
			this->cardRetrasos = (gcnew System::Windows::Forms::Panel());
			this->lblCardRetrasosTitulo = (gcnew System::Windows::Forms::Label());
			this->lblRetrasos = (gcnew System::Windows::Forms::Label());
			this->lblRetrasosSub = (gcnew System::Windows::Forms::Label());
			this->cardNoTomadas = (gcnew System::Windows::Forms::Panel());
			this->lblCardNoTomadasTitulo = (gcnew System::Windows::Forms::Label());
			this->lblNoTomadas = (gcnew System::Windows::Forms::Label());
			this->lblNoTomadasSub = (gcnew System::Windows::Forms::Label());
			this->cardIndice = (gcnew System::Windows::Forms::Panel());
			this->lblCardIndiceTitulo = (gcnew System::Windows::Forms::Label());
			this->lblIndice = (gcnew System::Windows::Forms::Label());
			this->lblIndiceSub = (gcnew System::Windows::Forms::Label());
			this->grpDesviacion = (gcnew System::Windows::Forms::GroupBox());
			this->chartDesviacion = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->grpDetalle = (gcnew System::Windows::Forms::GroupBox());
			this->dgvDetalle = (gcnew System::Windows::Forms::DataGridView());
			this->colFecha = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colMedicamento = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colProgramada = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colReal = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colDesviacion = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colEstado = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->grpObservaciones = (gcnew System::Windows::Forms::GroupBox());
			this->txtObservaciones = (gcnew System::Windows::Forms::RichTextBox());
			this->panelCabecera->SuspendLayout();
			this->panelContenido->SuspendLayout();
			this->panelFiltros->SuspendLayout();
			this->cardProgramadas->SuspendLayout();
			this->cardPuntuales->SuspendLayout();
			this->cardRetrasos->SuspendLayout();
			this->cardNoTomadas->SuspendLayout();
			this->cardIndice->SuspendLayout();
			this->grpDesviacion->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartDesviacion))->BeginInit();
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
			this->lblTitulo->Size = System::Drawing::Size(323, 37);
			this->lblTitulo->TabIndex = 0;
			this->lblTitulo->Text = L"Reporte de Puntualidad";
			// 
			// lblSubtitulo
			// 
			this->lblSubtitulo->AutoSize = true;
			this->lblSubtitulo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->lblSubtitulo->ForeColor = System::Drawing::Color::FromArgb(200, 218, 235);
			this->lblSubtitulo->Location = System::Drawing::Point(27, 50);
			this->lblSubtitulo->Name = L"lblSubtitulo";
			this->lblSubtitulo->Size = System::Drawing::Size(470, 20);
			this->lblSubtitulo->TabIndex = 1;
			this->lblSubtitulo->Text = L"Comparacion automatica entre hora programada y hora real de toma";
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
			this->panelContenido->Controls->Add(this->panelFiltros);
			this->panelContenido->Controls->Add(this->cardProgramadas);
			this->panelContenido->Controls->Add(this->cardPuntuales);
			this->panelContenido->Controls->Add(this->cardRetrasos);
			this->panelContenido->Controls->Add(this->cardNoTomadas);
			this->panelContenido->Controls->Add(this->cardIndice);
			this->panelContenido->Controls->Add(this->grpDesviacion);
			this->panelContenido->Controls->Add(this->grpDetalle);
			this->panelContenido->Controls->Add(this->grpObservaciones);
			this->panelContenido->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panelContenido->Location = System::Drawing::Point(0, 84);
			this->panelContenido->Name = L"panelContenido";
			this->panelContenido->Size = System::Drawing::Size(1360, 676);
			this->panelContenido->TabIndex = 0;
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
			this->panelFiltros->Controls->Add(this->btnAplicarFiltros);
			this->panelFiltros->Controls->Add(this->btnRestablecer);
			this->panelFiltros->Location = System::Drawing::Point(22, 20);
			this->panelFiltros->Name = L"panelFiltros";
			this->panelFiltros->Size = System::Drawing::Size(1300, 104);
			this->panelFiltros->TabIndex = 0;
			// 
			// lblPacienteFiltro
			// 
			this->lblPacienteFiltro->AutoSize = true;
			this->lblPacienteFiltro->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblPacienteFiltro->ForeColor = System::Drawing::Color::FromArgb(90, 115, 140);
			this->lblPacienteFiltro->Location = System::Drawing::Point(18, 14);
			this->lblPacienteFiltro->Name = L"lblPacienteFiltro";
			this->lblPacienteFiltro->Size = System::Drawing::Size(140, 20);
			this->lblPacienteFiltro->TabIndex = 0;
			this->lblPacienteFiltro->Text = L"Paciente individual";
			// 
			// cmbPaciente
			// 
			this->cmbPaciente->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbPaciente->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->cmbPaciente->BackColor = System::Drawing::Color::White;
			this->cmbPaciente->ForeColor = System::Drawing::Color::FromArgb(30, 50, 70);
			this->cmbPaciente->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F));
			this->cmbPaciente->Location = System::Drawing::Point(18, 42);
			this->cmbPaciente->Name = L"cmbPaciente";
			this->cmbPaciente->Size = System::Drawing::Size(280, 24);
			this->cmbPaciente->TabIndex = 1;
			this->cmbPaciente->SelectedIndexChanged += gcnew System::EventHandler(this, &frmPuntualidad::cmbPaciente_SelectedIndexChanged);
			// 
			// lblDesde
			// 
			this->lblDesde->AutoSize = true;
			this->lblDesde->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblDesde->ForeColor = System::Drawing::Color::FromArgb(90, 115, 140);
			this->lblDesde->Location = System::Drawing::Point(318, 14);
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
			this->dtpDesde->Location = System::Drawing::Point(318, 42);
			this->dtpDesde->Name = L"dtpDesde";
			this->dtpDesde->Size = System::Drawing::Size(150, 22);
			this->dtpDesde->TabIndex = 3;
			// 
			// lblHasta
			// 
			this->lblHasta->AutoSize = true;
			this->lblHasta->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblHasta->ForeColor = System::Drawing::Color::FromArgb(90, 115, 140);
			this->lblHasta->Location = System::Drawing::Point(488, 14);
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
			this->dtpHasta->Location = System::Drawing::Point(488, 42);
			this->dtpHasta->Name = L"dtpHasta";
			this->dtpHasta->Size = System::Drawing::Size(150, 22);
			this->dtpHasta->TabIndex = 5;
			// 
			// lblMedicamentoFiltro
			// 
			this->lblMedicamentoFiltro->AutoSize = true;
			this->lblMedicamentoFiltro->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblMedicamentoFiltro->ForeColor = System::Drawing::Color::FromArgb(90, 115, 140);
			this->lblMedicamentoFiltro->Location = System::Drawing::Point(658, 14);
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
			this->cmbMedicamento->Location = System::Drawing::Point(658, 42);
			this->cmbMedicamento->Name = L"cmbMedicamento";
			this->cmbMedicamento->Size = System::Drawing::Size(250, 24);
			this->cmbMedicamento->TabIndex = 7;
			// 
			// btnAplicarFiltros
			// 
			this->btnAplicarFiltros->BackColor = System::Drawing::Color::FromArgb(234, 243, 222);
			this->btnAplicarFiltros->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(168, 208, 106);
			this->btnAplicarFiltros->FlatAppearance->BorderSize = 1;
			this->btnAplicarFiltros->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(192, 221, 151);
			this->btnAplicarFiltros->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnAplicarFiltros->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F, System::Drawing::FontStyle::Regular));
			this->btnAplicarFiltros->ForeColor = System::Drawing::Color::FromArgb(39, 80, 10);
			this->btnAplicarFiltros->Location = System::Drawing::Point(934, 35);
			this->btnAplicarFiltros->Name = L"btnAplicarFiltros";
			this->btnAplicarFiltros->Size = System::Drawing::Size(160, 36);
			this->btnAplicarFiltros->TabIndex = 8;
			this->btnAplicarFiltros->Text = L"Aplicar filtros";
			this->btnAplicarFiltros->UseVisualStyleBackColor = false;
			this->btnAplicarFiltros->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnAplicarFiltros->Click += gcnew System::EventHandler(this, &frmPuntualidad::btnAplicarFiltros_Click);
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
			this->btnRestablecer->Location = System::Drawing::Point(1110, 35);
			this->btnRestablecer->Name = L"btnRestablecer";
			this->btnRestablecer->Size = System::Drawing::Size(172, 36);
			this->btnRestablecer->TabIndex = 9;
			this->btnRestablecer->Text = L"Restablecer";
			this->btnRestablecer->UseVisualStyleBackColor = false;
			this->btnRestablecer->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnRestablecer->Click += gcnew System::EventHandler(this, &frmPuntualidad::btnRestablecer_Click);
			// 
			// cardProgramadas
			// 
			this->cardProgramadas->BackColor = System::Drawing::Color::White;
			this->cardProgramadas->Controls->Add(this->lblCardProgramadasTitulo);
			this->cardProgramadas->Controls->Add(this->lblProgramadas);
			this->cardProgramadas->Controls->Add(this->lblProgramadasSub);
			this->cardProgramadas->Location = System::Drawing::Point(22, 140);
			this->cardProgramadas->Name = L"cardProgramadas";
			this->cardProgramadas->Size = System::Drawing::Size(244, 132);
			this->cardProgramadas->TabIndex = 1;
			// 
			// lblCardProgramadasTitulo
			// 
			this->lblCardProgramadasTitulo->AutoSize = true;
			this->lblCardProgramadasTitulo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblCardProgramadasTitulo->ForeColor = System::Drawing::Color::FromArgb(90, 115, 140);
			this->lblCardProgramadasTitulo->Location = System::Drawing::Point(16, 16);
			this->lblCardProgramadasTitulo->Name = L"lblCardProgramadasTitulo";
			this->lblCardProgramadasTitulo->Size = System::Drawing::Size(144, 20);
			this->lblCardProgramadasTitulo->TabIndex = 0;
			this->lblCardProgramadasTitulo->Text = L"Dosis programadas";
			// 
			// lblProgramadas
			// 
			this->lblProgramadas->AutoSize = true;
			this->lblProgramadas->Font = (gcnew System::Drawing::Font(L"Segoe UI", 20, System::Drawing::FontStyle::Bold));
			this->lblProgramadas->Location = System::Drawing::Point(16, 45);
			this->lblProgramadas->Name = L"lblProgramadas";
			this->lblProgramadas->Size = System::Drawing::Size(40, 46);
			this->lblProgramadas->TabIndex = 1;
			this->lblProgramadas->Text = L"0";
			// 
			// lblProgramadasSub
			// 
			this->lblProgramadasSub->AutoSize = true;
			this->lblProgramadasSub->ForeColor = System::Drawing::Color::DimGray;
			this->lblProgramadasSub->Location = System::Drawing::Point(18, 92);
			this->lblProgramadasSub->Name = L"lblProgramadasSub";
			this->lblProgramadasSub->Size = System::Drawing::Size(147, 16);
			this->lblProgramadasSub->TabIndex = 2;
			this->lblProgramadasSub->Text = L"Seleccione un paciente";
			// 
			// cardPuntuales
			// 
			this->cardPuntuales->BackColor = System::Drawing::Color::White;
			this->cardPuntuales->Controls->Add(this->lblCardPuntualesTitulo);
			this->cardPuntuales->Controls->Add(this->lblPuntuales);
			this->cardPuntuales->Controls->Add(this->lblPuntualesSub);
			this->cardPuntuales->Location = System::Drawing::Point(284, 140);
			this->cardPuntuales->Name = L"cardPuntuales";
			this->cardPuntuales->Size = System::Drawing::Size(244, 132);
			this->cardPuntuales->TabIndex = 2;
			// 
			// lblCardPuntualesTitulo
			// 
			this->lblCardPuntualesTitulo->AutoSize = true;
			this->lblCardPuntualesTitulo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblCardPuntualesTitulo->ForeColor = System::Drawing::Color::FromArgb(90, 115, 140);
			this->lblCardPuntualesTitulo->Location = System::Drawing::Point(16, 16);
			this->lblCardPuntualesTitulo->Name = L"lblCardPuntualesTitulo";
			this->lblCardPuntualesTitulo->Size = System::Drawing::Size(138, 20);
			this->lblCardPuntualesTitulo->TabIndex = 0;
			this->lblCardPuntualesTitulo->Text = L"Tomadas a tiempo";
			// 
			// lblPuntuales
			// 
			this->lblPuntuales->AutoSize = true;
			this->lblPuntuales->Font = (gcnew System::Drawing::Font(L"Segoe UI", 20, System::Drawing::FontStyle::Bold));
			this->lblPuntuales->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(125)),
				static_cast<System::Int32>(static_cast<System::Byte>(95)));
			this->lblPuntuales->Location = System::Drawing::Point(16, 45);
			this->lblPuntuales->Name = L"lblPuntuales";
			this->lblPuntuales->Size = System::Drawing::Size(40, 46);
			this->lblPuntuales->TabIndex = 1;
			this->lblPuntuales->Text = L"0";
			// 
			// lblPuntualesSub
			// 
			this->lblPuntualesSub->AutoSize = true;
			this->lblPuntualesSub->ForeColor = System::Drawing::Color::DimGray;
			this->lblPuntualesSub->Location = System::Drawing::Point(18, 92);
			this->lblPuntualesSub->Name = L"lblPuntualesSub";
			this->lblPuntualesSub->Size = System::Drawing::Size(199, 16);
			this->lblPuntualesSub->TabIndex = 2;
			this->lblPuntualesSub->Text = L"anticipadas o hasta 10 min tarde";
			// 
			// cardRetrasos
			// 
			this->cardRetrasos->BackColor = System::Drawing::Color::White;
			this->cardRetrasos->Controls->Add(this->lblCardRetrasosTitulo);
			this->cardRetrasos->Controls->Add(this->lblRetrasos);
			this->cardRetrasos->Controls->Add(this->lblRetrasosSub);
			this->cardRetrasos->Location = System::Drawing::Point(546, 140);
			this->cardRetrasos->Name = L"cardRetrasos";
			this->cardRetrasos->Size = System::Drawing::Size(244, 132);
			this->cardRetrasos->TabIndex = 3;
			// 
			// lblCardRetrasosTitulo
			// 
			this->lblCardRetrasosTitulo->AutoSize = true;
			this->lblCardRetrasosTitulo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblCardRetrasosTitulo->ForeColor = System::Drawing::Color::FromArgb(90, 115, 140);
			this->lblCardRetrasosTitulo->Location = System::Drawing::Point(16, 16);
			this->lblCardRetrasosTitulo->Name = L"lblCardRetrasosTitulo";
			this->lblCardRetrasosTitulo->Size = System::Drawing::Size(155, 20);
			this->lblCardRetrasosTitulo->TabIndex = 0;
			this->lblCardRetrasosTitulo->Text = L"Tomadas con retraso";
			// 
			// lblRetrasos
			// 
			this->lblRetrasos->AutoSize = true;
			this->lblRetrasos->Font = (gcnew System::Drawing::Font(L"Segoe UI", 20, System::Drawing::FontStyle::Bold));
			this->lblRetrasos->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(190)), static_cast<System::Int32>(static_cast<System::Byte>(120)),
				static_cast<System::Int32>(static_cast<System::Byte>(20)));
			this->lblRetrasos->Location = System::Drawing::Point(16, 45);
			this->lblRetrasos->Name = L"lblRetrasos";
			this->lblRetrasos->Size = System::Drawing::Size(40, 46);
			this->lblRetrasos->TabIndex = 1;
			this->lblRetrasos->Text = L"0";
			// 
			// lblRetrasosSub
			// 
			this->lblRetrasosSub->AutoSize = true;
			this->lblRetrasosSub->ForeColor = System::Drawing::Color::DimGray;
			this->lblRetrasosSub->Location = System::Drawing::Point(18, 92);
			this->lblRetrasosSub->Name = L"lblRetrasosSub";
			this->lblRetrasosSub->Size = System::Drawing::Size(127, 16);
			this->lblRetrasosSub->TabIndex = 2;
			this->lblRetrasosSub->Text = L"mas de 10 min tarde";
			// 
			// cardNoTomadas
			// 
			this->cardNoTomadas->BackColor = System::Drawing::Color::White;
			this->cardNoTomadas->Controls->Add(this->lblCardNoTomadasTitulo);
			this->cardNoTomadas->Controls->Add(this->lblNoTomadas);
			this->cardNoTomadas->Controls->Add(this->lblNoTomadasSub);
			this->cardNoTomadas->Location = System::Drawing::Point(808, 140);
			this->cardNoTomadas->Name = L"cardNoTomadas";
			this->cardNoTomadas->Size = System::Drawing::Size(244, 132);
			this->cardNoTomadas->TabIndex = 4;
			// 
			// lblCardNoTomadasTitulo
			// 
			this->lblCardNoTomadasTitulo->AutoSize = true;
			this->lblCardNoTomadasTitulo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblCardNoTomadasTitulo->ForeColor = System::Drawing::Color::FromArgb(90, 115, 140);
			this->lblCardNoTomadasTitulo->Location = System::Drawing::Point(16, 16);
			this->lblCardNoTomadasTitulo->Name = L"lblCardNoTomadasTitulo";
			this->lblCardNoTomadasTitulo->Size = System::Drawing::Size(95, 20);
			this->lblCardNoTomadasTitulo->TabIndex = 0;
			this->lblCardNoTomadasTitulo->Text = L"No tomadas";
			// 
			// lblNoTomadas
			// 
			this->lblNoTomadas->AutoSize = true;
			this->lblNoTomadas->Font = (gcnew System::Drawing::Font(L"Segoe UI", 20, System::Drawing::FontStyle::Bold));
			this->lblNoTomadas->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(180)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->lblNoTomadas->Location = System::Drawing::Point(16, 45);
			this->lblNoTomadas->Name = L"lblNoTomadas";
			this->lblNoTomadas->Size = System::Drawing::Size(40, 46);
			this->lblNoTomadas->TabIndex = 1;
			this->lblNoTomadas->Text = L"0";
			// 
			// lblNoTomadasSub
			// 
			this->lblNoTomadasSub->AutoSize = true;
			this->lblNoTomadasSub->ForeColor = System::Drawing::Color::DimGray;
			this->lblNoTomadasSub->Location = System::Drawing::Point(18, 92);
			this->lblNoTomadasSub->Name = L"lblNoTomadasSub";
			this->lblNoTomadasSub->Size = System::Drawing::Size(124, 16);
			this->lblNoTomadasSub->TabIndex = 2;
			this->lblNoTomadasSub->Text = L"sin registro de toma";
			// 
			// cardIndice
			// 
			this->cardIndice->BackColor = System::Drawing::Color::White;
			this->cardIndice->Controls->Add(this->lblCardIndiceTitulo);
			this->cardIndice->Controls->Add(this->lblIndice);
			this->cardIndice->Controls->Add(this->lblIndiceSub);
			this->cardIndice->Location = System::Drawing::Point(1070, 140);
			this->cardIndice->Name = L"cardIndice";
			this->cardIndice->Size = System::Drawing::Size(252, 132);
			this->cardIndice->TabIndex = 5;
			// 
			// lblCardIndiceTitulo
			// 
			this->lblCardIndiceTitulo->AutoSize = true;
			this->lblCardIndiceTitulo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblCardIndiceTitulo->ForeColor = System::Drawing::Color::FromArgb(90, 115, 140);
			this->lblCardIndiceTitulo->Location = System::Drawing::Point(16, 16);
			this->lblCardIndiceTitulo->Name = L"lblCardIndiceTitulo";
			this->lblCardIndiceTitulo->Size = System::Drawing::Size(160, 20);
			this->lblCardIndiceTitulo->TabIndex = 0;
			this->lblCardIndiceTitulo->Text = L"Indice de puntualidad";
			// 
			// lblIndice
			// 
			this->lblIndice->AutoSize = true;
			this->lblIndice->Font = (gcnew System::Drawing::Font(L"Segoe UI", 20, System::Drawing::FontStyle::Bold));
			this->lblIndice->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(125)),
				static_cast<System::Int32>(static_cast<System::Byte>(95)));
			this->lblIndice->Location = System::Drawing::Point(16, 45);
			this->lblIndice->Name = L"lblIndice";
			this->lblIndice->Size = System::Drawing::Size(69, 46);
			this->lblIndice->TabIndex = 1;
			this->lblIndice->Text = L"0%";
			// 
			// lblIndiceSub
			// 
			this->lblIndiceSub->AutoSize = true;
			this->lblIndiceSub->ForeColor = System::Drawing::Color::DimGray;
			this->lblIndiceSub->Location = System::Drawing::Point(18, 92);
			this->lblIndiceSub->Name = L"lblIndiceSub";
			this->lblIndiceSub->Size = System::Drawing::Size(86, 16);
			this->lblIndiceSub->TabIndex = 2;
			this->lblIndiceSub->Text = L"meta: >= 80%";
			// 
			// grpDesviacion
			// 
			this->grpDesviacion->BackColor = System::Drawing::Color::White;
			this->grpDesviacion->Controls->Add(this->chartDesviacion);
			this->grpDesviacion->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular));
			this->grpDesviacion->Location = System::Drawing::Point(22, 292);
			this->grpDesviacion->Name = L"grpDesviacion";
			this->grpDesviacion->Size = System::Drawing::Size(1300, 360);
			this->grpDesviacion->TabIndex = 6;
			this->grpDesviacion->TabStop = false;
			this->grpDesviacion->Text = L"Desviacion promedio por dia (minutos)";
			// 
			// chartDesviacion
			// 
			chartArea1->Name = L"AreaDesviacion";
			this->chartDesviacion->ChartAreas->Add(chartArea1);
			this->chartDesviacion->Dock = System::Windows::Forms::DockStyle::Fill;
			this->chartDesviacion->Location = System::Drawing::Point(3, 26);
			this->chartDesviacion->Name = L"chartDesviacion";
			series1->ChartArea = L"AreaDesviacion";
			series1->Name = L"Desviacion";
			this->chartDesviacion->Series->Add(series1);
			this->chartDesviacion->Size = System::Drawing::Size(1294, 331);
			this->chartDesviacion->TabIndex = 0;
			// 
			// grpDetalle
			// 
			this->grpDetalle->BackColor = System::Drawing::Color::White;
			this->grpDetalle->Controls->Add(this->dgvDetalle);
			this->grpDetalle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular));
			this->grpDetalle->Location = System::Drawing::Point(22, 674);
			this->grpDetalle->Name = L"grpDetalle";
			this->grpDetalle->Size = System::Drawing::Size(1300, 300);
			this->grpDetalle->TabIndex = 8;
			this->grpDetalle->TabStop = false;
			this->grpDetalle->Text = L"Detalle de dosis";
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

			this->dgvDetalle->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->colFecha,
					this->colMedicamento, this->colProgramada, this->colReal, this->colDesviacion, this->colEstado
			});
			this->dgvDetalle->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dgvDetalle->Location = System::Drawing::Point(3, 26);
			this->dgvDetalle->Name = L"dgvDetalle";
			this->dgvDetalle->ReadOnly = true;
			this->dgvDetalle->RowHeadersVisible = false;
			this->dgvDetalle->RowHeadersWidth = 51;
			this->dgvDetalle->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dgvDetalle->Size = System::Drawing::Size(1294, 271);
			this->dgvDetalle->TabIndex = 0;
			// 
			// colFecha
			// 
			this->colFecha->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->colFecha->HeaderText = L"Fecha";
			this->colFecha->MinimumWidth = 6;
			this->colFecha->Name = L"colFecha";
			this->colFecha->ReadOnly = true;
			// 
			// colMedicamento
			// 
			this->colMedicamento->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->colMedicamento->FillWeight = 140;
			this->colMedicamento->HeaderText = L"Medicamento";
			this->colMedicamento->MinimumWidth = 6;
			this->colMedicamento->Name = L"colMedicamento";
			this->colMedicamento->ReadOnly = true;
			// 
			// colProgramada
			// 
			this->colProgramada->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->colProgramada->FillWeight = 105;
			this->colProgramada->HeaderText = L"Hora programada";
			this->colProgramada->MinimumWidth = 6;
			this->colProgramada->Name = L"colProgramada";
			this->colProgramada->ReadOnly = true;
			// 
			// colReal
			// 
			this->colReal->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->colReal->FillWeight = 105;
			this->colReal->HeaderText = L"Hora real";
			this->colReal->MinimumWidth = 6;
			this->colReal->Name = L"colReal";
			this->colReal->ReadOnly = true;
			// 
			// colDesviacion
			// 
			this->colDesviacion->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->colDesviacion->FillWeight = 90;
			this->colDesviacion->HeaderText = L"Desviacion";
			this->colDesviacion->MinimumWidth = 6;
			this->colDesviacion->Name = L"colDesviacion";
			this->colDesviacion->ReadOnly = true;
			// 
			// colEstado
			// 
			this->colEstado->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->colEstado->HeaderText = L"Estado";
			this->colEstado->MinimumWidth = 6;
			this->colEstado->Name = L"colEstado";
			this->colEstado->ReadOnly = true;
			// 
			// grpObservaciones
			// 
			this->grpObservaciones->BackColor = System::Drawing::Color::White;
			this->grpObservaciones->Controls->Add(this->txtObservaciones);
			this->grpObservaciones->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular));
			this->grpObservaciones->Location = System::Drawing::Point(22, 996);
			this->grpObservaciones->Name = L"grpObservaciones";
			this->grpObservaciones->Size = System::Drawing::Size(1300, 180);
			this->grpObservaciones->TabIndex = 9;
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
			// frmPuntualidad
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(241, 244, 248);
			this->ClientSize = System::Drawing::Size(1360, 760);
			this->ControlBox = false;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Controls->Add(this->panelContenido);
			this->Controls->Add(this->panelCabecera);
			this->Name = L"frmPuntualidad";
			this->Text = L"";
			this->Load += gcnew System::EventHandler(
				this,
				&frmPuntualidad::frmPuntualidad_Load
			);
			this->Resize += gcnew System::EventHandler(
				this,
				&frmPuntualidad::frmPuntualidad_Resize
			);
			this->panelCabecera->ResumeLayout(false);
			this->panelCabecera->PerformLayout();
			this->panelContenido->ResumeLayout(false);
			this->panelFiltros->ResumeLayout(false);
			this->panelFiltros->PerformLayout();
			this->cardProgramadas->ResumeLayout(false);
			this->cardProgramadas->PerformLayout();
			this->cardPuntuales->ResumeLayout(false);
			this->cardPuntuales->PerformLayout();
			this->cardRetrasos->ResumeLayout(false);
			this->cardRetrasos->PerformLayout();
			this->cardNoTomadas->ResumeLayout(false);
			this->cardNoTomadas->PerformLayout();
			this->cardIndice->ResumeLayout(false);
			this->cardIndice->PerformLayout();
			this->grpDesviacion->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartDesviacion))->EndInit();
			this->grpDetalle->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvDetalle))->EndInit();
			this->grpObservaciones->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion

	private:
		void ConfigurarTarjeta(Panel^ tarjeta, Label^ titulo, Label^ valor, Label^ subtitulo,
			Point ubicacion, String^ textoTitulo, Color colorValor, String^ textoSubtitulo) {
			tarjeta->BackColor = Color::White;
			tarjeta->Controls->Add(titulo);
			tarjeta->Controls->Add(valor);
			tarjeta->Controls->Add(subtitulo);
			tarjeta->Location = ubicacion;
			tarjeta->Size = Drawing::Size(ubicacion.X >= 1070 ? 252 : 244, 132);
			titulo->AutoSize = true;
			titulo->Font = gcnew Drawing::Font("Segoe UI", 9, FontStyle::Bold);
			titulo->ForeColor = Color::FromArgb(90, 115, 140);
			titulo->Location = Point(16, 16);
			titulo->Text = textoTitulo;
			valor->AutoSize = true;
			valor->Font = gcnew Drawing::Font("Segoe UI", 20, FontStyle::Bold);
			valor->ForeColor = colorValor;
			valor->Location = Point(16, 45);
			valor->Text = "0";
			subtitulo->AutoSize = true;
			subtitulo->ForeColor = Color::DimGray;
			subtitulo->Location = Point(18, 92);
			subtitulo->Text = textoSubtitulo;
		}

		void ConfigurarColumna(DataGridViewTextBoxColumn^ columna, String^ encabezado, float peso) {
			columna->HeaderText = encabezado;
			columna->AutoSizeMode = DataGridViewAutoSizeColumnMode::Fill;
			columna->FillWeight = peso;
			columna->ReadOnly = true;
		}

		bool Contiene(String^ texto, String^ valor) {
			return !String::IsNullOrWhiteSpace(texto) &&
				texto->IndexOf(valor, StringComparison::OrdinalIgnoreCase) >= 0;
		}

		bool EsEventoDosis(LogEvento^ evento) {
			return evento != nullptr &&
				(Contiene(evento->getTipoEvento(), "Dosis") || Contiene(evento->getTipoEvento(), "Toma")) &&
				!Contiene(evento->getEstado(), "Pausa") &&
				evento->getFechaHoraProgramada() != DateTime::MinValue;
		}

		bool EsNoTomada(LogEvento^ evento) {
			return evento == nullptr || evento->getFechaHoraReal() == DateTime::MinValue ||
				Contiene(evento->getEstado(), "No tomada") || Contiene(evento->getEstado(), "No tomado") ||
				Contiene(evento->getEstado(), "Omision") || Contiene(evento->getEstado(), "Omitida");
		}

		double DiferenciaMinutos(LogEvento^ evento) {
			return EsNoTomada(evento) ? 0.0 :
				(evento->getFechaHoraReal() - evento->getFechaHoraProgramada()).TotalMinutes;
		}

		bool EsPuntual(LogEvento^ evento) {
			return !EsNoTomada(evento) && DiferenciaMinutos(evento) <= 10.0;
		}

		String^ EstadoPuntualidad(LogEvento^ evento) {
			if (EsNoTomada(evento)) return "No tomada";
			double diferencia = DiferenciaMinutos(evento);
			if (diferencia < 0.0) return "Anticipada";
			if (diferencia <= 10.0) return "Puntual";
			if (diferencia <= 30.0) return "Retraso leve";
			return "Retraso grave";
		}

		int ObtenerIdSeleccionado(ComboBox^ combo) {
			if (combo->SelectedIndex <= 0 || combo->SelectedItem == nullptr)
				return 0;
			String^ valor = combo->SelectedItem->ToString();
			int separador = valor->IndexOf(" - ");
			int id = 0;
			return separador > 0 && Int32::TryParse(valor->Substring(0, separador), id) ? id : 0;
		}

		List<LogEvento^>^ ObtenerEventosFiltrados() {
			List<LogEvento^>^ resultado = gcnew List<LogEvento^>();
			int paciente = ObtenerIdSeleccionado(this->cmbPaciente);
			int medicamento = ObtenerIdSeleccionado(this->cmbMedicamento);
			if (paciente == 0)
				return resultado;
			for each(LogEvento ^ evento in this->controller->ObtenerTodos()) {
				if (!EsEventoDosis(evento) || evento->getIdPaciente() != paciente)
					continue;
				if (medicamento > 0 && evento->getIdMedicamento() != medicamento)
					continue;
				if (evento->getFechaHoraProgramada().Date < this->dtpDesde->Value.Date ||
					evento->getFechaHoraProgramada().Date > this->dtpHasta->Value.Date)
					continue;
				resultado->Add(evento);
			}
			resultado->Sort(gcnew Comparison<LogEvento^>(this, &frmPuntualidad::CompararEventos));
			return resultado;
		}

		int CompararEventos(LogEvento^ primero, LogEvento^ segundo) {
			return DateTime::Compare(primero->getFechaHoraProgramada(), segundo->getFechaHoraProgramada());
		}

		void CargarFiltros() {
			SortedDictionary<int, String^>^ pacientes = gcnew SortedDictionary<int, String^>();
			SortedDictionary<int, String^>^ medicamentos = gcnew SortedDictionary<int, String^>();
			DateTime minimo = DateTime::MaxValue;
			DateTime maximo = DateTime::MinValue;
			for each(LogEvento ^ evento in this->controller->ObtenerTodos()) {
				if (!EsEventoDosis(evento)) continue;
				if (evento->getIdPaciente() > 0 && !pacientes->ContainsKey(evento->getIdPaciente()))
					pacientes->Add(evento->getIdPaciente(), evento->getNombrePaciente());
				if (evento->getIdMedicamento() > 0 && !medicamentos->ContainsKey(evento->getIdMedicamento()))
					medicamentos->Add(evento->getIdMedicamento(), evento->getMedicamento());
				if (evento->getFechaHoraProgramada() < minimo) minimo = evento->getFechaHoraProgramada();
				if (evento->getFechaHoraProgramada() > maximo) maximo = evento->getFechaHoraProgramada();
			}
			this->cmbPaciente->Items->Clear();
			this->cmbPaciente->Items->Add("Seleccione un paciente");
			for each(KeyValuePair<int, String^> item in pacientes)
				this->cmbPaciente->Items->Add(item.Key + " - " + item.Value);
			this->cmbPaciente->SelectedIndex = 0;
			this->cmbMedicamento->Items->Clear();
			this->cmbMedicamento->Items->Add("Todos los medicamentos");
			for each(KeyValuePair<int, String^> item in medicamentos)
				this->cmbMedicamento->Items->Add(item.Key + " - " + item.Value);
			this->cmbMedicamento->SelectedIndex = 0;
			this->dtpDesde->Value = minimo == DateTime::MaxValue ? DateTime::Today.AddDays(-30) : minimo.Date;
			this->dtpHasta->Value = maximo == DateTime::MinValue ? DateTime::Today : maximo.Date;
		}

		void ConfigurarGraficos() {
			ChartArea^ areaDesviacion = this->chartDesviacion->ChartAreas["AreaDesviacion"];
			areaDesviacion->AxisY->Minimum = 0;
			areaDesviacion->AxisY->Title = "Minutos";
			areaDesviacion->AxisX->Interval = 1;
		}

		void AjustarControlesReporte() {
			ChartArea^ areaDesviacion = this->chartDesviacion->ChartAreas["AreaDesviacion"];
			areaDesviacion->Position->Auto = false;
			areaDesviacion->Position->X = 7; areaDesviacion->Position->Y = 7;
			areaDesviacion->Position->Width = 90; areaDesviacion->Position->Height = 85;
			for each(DataGridViewColumn ^ columna in this->dgvDetalle->Columns)
				columna->AutoSizeMode = DataGridViewAutoSizeColumnMode::Fill;
		}

		void LimpiarReporte() {
			this->lblProgramadas->Text = "0";
			this->lblPuntuales->Text = "0";
			this->lblRetrasos->Text = "0";
			this->lblNoTomadas->Text = "0";
			this->lblIndice->Text = "0%";
			this->chartDesviacion->Series["Desviacion"]->Points->Clear();
			this->dgvDetalle->Rows->Clear();
			this->txtObservaciones->Text = "Seleccione un paciente para visualizar su reporte individual de puntualidad.";
			this->lblGenerado->Text = "Generado: " + DateTime::Now.ToString("dd/MM/yyyy HH:mm");
		}

		void ActualizarReporte() {
			if (ObtenerIdSeleccionado(this->cmbPaciente) == 0) {
				LimpiarReporte();
				return;
			}
			List<LogEvento^>^ eventos = ObtenerEventosFiltrados();
			int puntuales = 0, retrasos = 0, noTomadas = 0, leves = 0, graves = 0;
			SortedDictionary<DateTime, List<double>^>^ desviacionesDia = gcnew SortedDictionary<DateTime, List<double>^>();
			this->dgvDetalle->Rows->Clear();

			for each(LogEvento ^ evento in eventos) {
				String^ estado = EstadoPuntualidad(evento);
				double diferencia = DiferenciaMinutos(evento);
				if (EsNoTomada(evento)) noTomadas++;
				else if (EsPuntual(evento)) puntuales++;
				else {
					retrasos++;
					if (diferencia <= 30.0) leves++; else graves++;
				}
				if (!desviacionesDia->ContainsKey(evento->getFechaHoraProgramada().Date))
					desviacionesDia->Add(evento->getFechaHoraProgramada().Date, gcnew List<double>());
				if (!EsNoTomada(evento))
					desviacionesDia[evento->getFechaHoraProgramada().Date]->Add(Math::Max(0.0, diferencia));

				String^ desviacionTexto = EsNoTomada(evento) ? "-" :
					String::Format("{0}{1:F0} min", diferencia >= 0 ? "+" : "", diferencia);
				int fila = this->dgvDetalle->Rows->Add(
					evento->getFechaHoraProgramada().ToString("dd/MM/yyyy"),
					String::IsNullOrWhiteSpace(evento->getMedicamento()) ? "Sin medicamento" : evento->getMedicamento(),
					evento->getFechaHoraProgramada().ToString("HH:mm"),
					EsNoTomada(evento) ? "-" : evento->getFechaHoraReal().ToString("HH:mm"),
					desviacionTexto, estado);
				this->dgvDetalle->Rows[fila]->Cells[5]->Style->ForeColor =
					estado == "No tomada" ? Color::FromArgb(180, 50, 50) :
					estado == "Retraso grave" ? Color::FromArgb(180, 50, 50) :
					estado == "Retraso leve" ? Color::FromArgb(190, 120, 20) :
					estado == "Anticipada" ? Color::FromArgb(55, 138, 221) : Color::FromArgb(20, 125, 95);
			}
			this->dgvDetalle->ClearSelection();

			Series^ desviacion = this->chartDesviacion->Series["Desviacion"];
			desviacion->Points->Clear();
			for each(KeyValuePair<DateTime, List<double>^> item in desviacionesDia) {
				double promedio = 0.0;
				for each(double valor in item.Value) promedio += valor;
				promedio = item.Value->Count == 0 ? 0.0 : promedio / item.Value->Count;
				int punto = desviacion->Points->AddXY(item.Key.ToString("dd/MM"), promedio);
				desviacion->Points[punto]->Color = promedio <= 10.0 ? Color::FromArgb(29, 158, 117) :
					promedio <= 30.0 ? Color::FromArgb(239, 159, 39) : Color::FromArgb(232, 73, 73);
			}

			double indice = eventos->Count == 0 ? 0.0 : puntuales * 100.0 / eventos->Count;
			this->lblProgramadas->Text = eventos->Count.ToString();
			this->lblPuntuales->Text = puntuales.ToString();
			this->lblRetrasos->Text = retrasos.ToString();
			this->lblNoTomadas->Text = noTomadas.ToString();
			this->lblIndice->Text = String::Format("{0:F1}%", indice);
			this->lblIndice->ForeColor = indice >= 80.0 ? Color::FromArgb(20, 125, 95) : Color::FromArgb(180, 50, 50);

			StringBuilder^ texto = gcnew StringBuilder();
			texto->AppendFormat("El paciente registro un indice de puntualidad de {0:F1}% durante el periodo analizado. ", indice);
			texto->AppendFormat("Se identificaron {0} tomas puntuales, {1} retrasos leves, {2} retrasos graves y {3} dosis no tomadas. ",
				puntuales, leves, graves, noTomadas);
			texto->Append(indice >= 80.0
				? "La puntualidad alcanza la meta recomendada. "
				: "La puntualidad se encuentra por debajo de la meta recomendada. ");
			if (retrasos > 0 || noTomadas > 0)
				texto->Append("Se recomienda revisar los horarios y alertas del dispensador.");
			this->txtObservaciones->Text = texto->ToString();
			this->lblGenerado->Text = "Generado: " + DateTime::Now.ToString("dd/MM/yyyy HH:mm");
		}


		void AjustarDistribucion() {
			int margen = 22;
			int anchoDisponible =
				this->panelContenido->ClientSize.Width - (margen * 2);

			if (anchoDisponible < 900)
				anchoDisponible = 900;

			// Separación vertical uniforme entre todas las secciones
			int espacioVertical = 18;

			int yFiltros = 18;

			int yTarjetas =
				yFiltros +
				this->panelFiltros->Height +
				espacioVertical;

			int yGrafico =
				yTarjetas +
				this->cardProgramadas->Height +
				espacioVertical;

			int yDetalle =
				yGrafico +
				this->grpDesviacion->Height +
				espacioVertical;

			int yObservaciones =
				yDetalle +
				this->grpDetalle->Height +
				espacioVertical;

			// ?? Panel de filtros ???????????????????????????????????????????????
			this->panelFiltros->Location =
				System::Drawing::Point(margen, yFiltros);
			this->panelFiltros->Width = anchoDisponible;
			this->panelFiltros->Height = 104;

			int espacioInterno = 18;
			int separacionFiltro = 14;
			int anchoPaciente = 260;
			int anchoFecha = 150;
			int anchoMedicamento = 240;
			int anchoBoton = 165;

			int x = espacioInterno;

			this->lblPacienteFiltro->Location =
				System::Drawing::Point(x, 14);
			this->cmbPaciente->Location =
				System::Drawing::Point(x, 42);
			this->cmbPaciente->Width = anchoPaciente;
			x += anchoPaciente + separacionFiltro;

			this->lblDesde->Location =
				System::Drawing::Point(x, 14);
			this->dtpDesde->Location =
				System::Drawing::Point(x, 42);
			this->dtpDesde->Width = anchoFecha;
			x += anchoFecha + separacionFiltro;

			this->lblHasta->Location =
				System::Drawing::Point(x, 14);
			this->dtpHasta->Location =
				System::Drawing::Point(x, 42);
			this->dtpHasta->Width = anchoFecha;
			x += anchoFecha + separacionFiltro;

			this->lblMedicamentoFiltro->Location =
				System::Drawing::Point(x, 14);
			this->cmbMedicamento->Location =
				System::Drawing::Point(x, 42);
			this->cmbMedicamento->Width = anchoMedicamento;

			// Botones alineados al extremo derecho
			int xRestablecer =
				this->panelFiltros->ClientSize.Width -
				espacioInterno -
				anchoBoton;

			int xAplicar =
				xRestablecer -
				separacionFiltro -
				anchoBoton;

			this->btnAplicarFiltros->Location =
				System::Drawing::Point(xAplicar, 35);
			this->btnAplicarFiltros->Width = anchoBoton;

			this->btnRestablecer->Location =
				System::Drawing::Point(xRestablecer, 35);
			this->btnRestablecer->Width = anchoBoton;

			// Evitar superposición en ventanas más angostas
			if (x + anchoMedicamento + separacionFiltro > xAplicar) {
				this->cmbMedicamento->Width =
					Math::Max(120, xAplicar - separacionFiltro - x);
			}

			// ?? Cinco tarjetas ?????????????????????????????????????????????????
			array<System::Windows::Forms::Panel^>^ tarjetas = {
				this->cardProgramadas,
				this->cardPuntuales,
				this->cardRetrasos,
				this->cardNoTomadas,
				this->cardIndice
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

			// ?? Gráfico ????????????????????????????????????????????????????????
			this->grpDesviacion->Location =
				System::Drawing::Point(margen, yGrafico);
			this->grpDesviacion->Width = anchoDisponible;

			// ?? Tabla y observaciones ??????????????????????????????????????????
			this->grpDetalle->Location =
				System::Drawing::Point(margen, yDetalle);
			this->grpDetalle->Width = anchoDisponible;

			this->grpObservaciones->Location =
				System::Drawing::Point(margen, yObservaciones);
			this->grpObservaciones->Width = anchoDisponible;

			AjustarControlesReporte();
		}

		System::Void frmPuntualidad_Resize(
			System::Object^ sender,
			System::EventArgs^ e
		) {
			AjustarDistribucion();
		}

		System::Void frmPuntualidad_Load(System::Object^ sender, System::EventArgs^ e) {
			this->controller = gcnew GeneradorReportesController();
			ConfigurarGraficos();
			CargarFiltros();
			LimpiarReporte();
			AjustarDistribucion();
			this->BeginInvoke(
				gcnew MethodInvoker(
					this,
					&frmPuntualidad::AjustarDistribucion
				)
			);
		}

		System::Void btnAplicarFiltros_Click(System::Object^ sender, System::EventArgs^ e) {
			if (ObtenerIdSeleccionado(this->cmbPaciente) == 0) {
				MessageBox::Show("Seleccione un paciente para generar el reporte individual.",
					"Puntualidad", MessageBoxButtons::OK, MessageBoxIcon::Information);
				return;
			}
			ActualizarReporte();
		}

		System::Void btnRestablecer_Click(System::Object^ sender, System::EventArgs^ e) {
			CargarFiltros();
			LimpiarReporte();
		}

	private: System::Void cmbPaciente_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		int idPaciente = ObtenerIdSeleccionado(cmbPaciente);
		SortedDictionary<int, String^>^ medicamentos = gcnew SortedDictionary<int, String^>();
		for each(LogEvento ^ evento in controller->ObtenerTodos()) {
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
