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

	public ref class frmCumplimiento : public System::Windows::Forms::Form {
	public:
		frmCumplimiento() {
			InitializeComponent();
		}

	protected:
		~frmCumplimiento() {
			if (components)
				delete components;
		}

	private:
		System::ComponentModel::Container^ components;
		GeneradorReportesController^ reportesController;
		RecetaController^ recetaController;

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
		System::Windows::Forms::Panel^ cardTomadas;
		System::Windows::Forms::Label^ lblCardTomadasTitulo;
		System::Windows::Forms::Label^ lblTomadas;
		System::Windows::Forms::Label^ lblTomadasSub;
		System::Windows::Forms::Panel^ cardOmitidas;
		System::Windows::Forms::Label^ lblCardOmitidasTitulo;
		System::Windows::Forms::Label^ lblOmitidas;
		System::Windows::Forms::Label^ lblOmitidasSub;
		System::Windows::Forms::Panel^ cardCumplimiento;
		System::Windows::Forms::Label^ lblCardCumplimientoTitulo;
		System::Windows::Forms::Label^ lblCumplimiento;
		System::Windows::Forms::Label^ lblCumplimientoSub;
		System::Windows::Forms::Panel^ cardMedicamentos;
		System::Windows::Forms::Label^ lblCardMedicamentosTitulo;
		System::Windows::Forms::Label^ lblMedicamentos;
		System::Windows::Forms::Label^ lblMedicamentosSub;

		System::Windows::Forms::GroupBox^ grpCumplimientoTotal;
		System::Windows::Forms::DataVisualization::Charting::Chart^ chartAnillo;
		System::Windows::Forms::GroupBox^ grpCumplimientoMedicamento;
		System::Windows::Forms::DataVisualization::Charting::Chart^ chartMedicamentos;
		System::Windows::Forms::GroupBox^ grpDetalle;
		System::Windows::Forms::DataGridView^ dgvDetalle;
		System::Windows::Forms::DataGridViewTextBoxColumn^ colMedicamento;
		System::Windows::Forms::DataGridViewTextBoxColumn^ colDosis;
		System::Windows::Forms::DataGridViewTextBoxColumn^ colProgramadas;
		System::Windows::Forms::DataGridViewTextBoxColumn^ colTomadas;
		System::Windows::Forms::DataGridViewTextBoxColumn^ colOmitidas;
		System::Windows::Forms::DataGridViewTextBoxColumn^ colCumplimiento;
		System::Windows::Forms::DataGridViewTextBoxColumn^ colEstado;
		System::Windows::Forms::GroupBox^ grpObservaciones;
		System::Windows::Forms::RichTextBox^ txtObservaciones;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void) {
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ areaAnillo = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ leyendaAnillo = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ serieAnillo = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ areaMedicamentos = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ leyendaMedicamentos = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ serieTomadas = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ serieOmitidas = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
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
			this->cardTomadas = (gcnew System::Windows::Forms::Panel());
			this->lblCardTomadasTitulo = (gcnew System::Windows::Forms::Label());
			this->lblTomadas = (gcnew System::Windows::Forms::Label());
			this->lblTomadasSub = (gcnew System::Windows::Forms::Label());
			this->cardOmitidas = (gcnew System::Windows::Forms::Panel());
			this->lblCardOmitidasTitulo = (gcnew System::Windows::Forms::Label());
			this->lblOmitidas = (gcnew System::Windows::Forms::Label());
			this->lblOmitidasSub = (gcnew System::Windows::Forms::Label());
			this->cardCumplimiento = (gcnew System::Windows::Forms::Panel());
			this->lblCardCumplimientoTitulo = (gcnew System::Windows::Forms::Label());
			this->lblCumplimiento = (gcnew System::Windows::Forms::Label());
			this->lblCumplimientoSub = (gcnew System::Windows::Forms::Label());
			this->cardMedicamentos = (gcnew System::Windows::Forms::Panel());
			this->lblCardMedicamentosTitulo = (gcnew System::Windows::Forms::Label());
			this->lblMedicamentos = (gcnew System::Windows::Forms::Label());
			this->lblMedicamentosSub = (gcnew System::Windows::Forms::Label());
			this->grpCumplimientoTotal = (gcnew System::Windows::Forms::GroupBox());
			this->chartAnillo = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->grpCumplimientoMedicamento = (gcnew System::Windows::Forms::GroupBox());
			this->chartMedicamentos = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->grpDetalle = (gcnew System::Windows::Forms::GroupBox());
			this->dgvDetalle = (gcnew System::Windows::Forms::DataGridView());
			this->colMedicamento = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colDosis = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colProgramadas = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colTomadas = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colOmitidas = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colCumplimiento = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colEstado = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->grpObservaciones = (gcnew System::Windows::Forms::GroupBox());
			this->txtObservaciones = (gcnew System::Windows::Forms::RichTextBox());
			this->panelCabecera->SuspendLayout();
			this->panelContenido->SuspendLayout();
			this->panelFiltros->SuspendLayout();
			this->cardProgramadas->SuspendLayout();
			this->cardTomadas->SuspendLayout();
			this->cardOmitidas->SuspendLayout();
			this->cardCumplimiento->SuspendLayout();
			this->cardMedicamentos->SuspendLayout();
			this->grpCumplimientoTotal->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartAnillo))->BeginInit();
			this->grpCumplimientoMedicamento->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartMedicamentos))->BeginInit();
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
			this->panelCabecera->TabIndex = 0;
			// 
			// lblTitulo
			// 
			this->lblTitulo->AutoSize = true;
			this->lblTitulo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15, System::Drawing::FontStyle::Regular));
			this->lblTitulo->ForeColor = System::Drawing::Color::FromArgb(220, 233, 245);
			this->lblTitulo->Location = System::Drawing::Point(24, 13);
			this->lblTitulo->Name = L"lblTitulo";
			this->lblTitulo->Text = L"Reporte de Cumplimiento";
			// 
			// lblSubtitulo
			// 
			this->lblSubtitulo->AutoSize = true;
			this->lblSubtitulo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->lblSubtitulo->ForeColor = System::Drawing::Color::FromArgb(200, 218, 235);
			this->lblSubtitulo->Location = System::Drawing::Point(27, 50);
			this->lblSubtitulo->Name = L"lblSubtitulo";
			this->lblSubtitulo->Text = L"Seguimiento automático de dosis tomadas y omitidas";
			// 
			// lblGenerado
			// 
			this->lblGenerado->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->lblGenerado->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->lblGenerado->ForeColor = System::Drawing::Color::White;
			this->lblGenerado->Location = System::Drawing::Point(1060, 28);
			this->lblGenerado->Name = L"lblGenerado";
			this->lblGenerado->Size = System::Drawing::Size(274, 22);
			this->lblGenerado->Text = L"Generado:";
			this->lblGenerado->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// panelContenido
			// 
			this->panelContenido->AutoScroll = true;
			this->panelContenido->BackColor = System::Drawing::Color::FromArgb(241, 244, 248);
			this->panelContenido->Controls->Add(this->panelFiltros);
			this->panelContenido->Controls->Add(this->cardProgramadas);
			this->panelContenido->Controls->Add(this->cardTomadas);
			this->panelContenido->Controls->Add(this->cardOmitidas);
			this->panelContenido->Controls->Add(this->cardCumplimiento);
			this->panelContenido->Controls->Add(this->cardMedicamentos);
			this->panelContenido->Controls->Add(this->grpCumplimientoTotal);
			this->panelContenido->Controls->Add(this->grpCumplimientoMedicamento);
			this->panelContenido->Controls->Add(this->grpDetalle);
			this->panelContenido->Controls->Add(this->grpObservaciones);
			this->panelContenido->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panelContenido->Location = System::Drawing::Point(0, 84);
			this->panelContenido->Name = L"panelContenido";
			this->panelContenido->Size = System::Drawing::Size(1360, 676);
			this->panelContenido->TabIndex = 1;
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
			// lblPacienteFiltro / cmbPaciente
			// 
			this->lblPacienteFiltro->AutoSize = true;
			this->lblPacienteFiltro->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblPacienteFiltro->ForeColor = System::Drawing::Color::FromArgb(90, 115, 140);
			this->lblPacienteFiltro->Location = System::Drawing::Point(18, 14);
			this->lblPacienteFiltro->Text = L"Paciente";
			this->cmbPaciente->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbPaciente->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->cmbPaciente->BackColor = System::Drawing::Color::White;
			this->cmbPaciente->ForeColor = System::Drawing::Color::FromArgb(30, 50, 70);
			this->cmbPaciente->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F));
			this->cmbPaciente->Location = System::Drawing::Point(18, 42);
			this->cmbPaciente->Name = L"cmbPaciente";
			this->cmbPaciente->Size = System::Drawing::Size(260, 24);
			// 
			// lblDesde / dtpDesde
			// 
			this->lblDesde->AutoSize = true;
			this->lblDesde->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblDesde->ForeColor = System::Drawing::Color::FromArgb(90, 115, 140);
			this->lblDesde->Location = System::Drawing::Point(300, 14);
			this->lblDesde->Text = L"Desde";
			this->dtpDesde->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dtpDesde->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F));
			this->dtpDesde->CalendarForeColor = System::Drawing::Color::FromArgb(30, 50, 70);
			this->dtpDesde->Location = System::Drawing::Point(300, 42);
			this->dtpDesde->Name = L"dtpDesde";
			this->dtpDesde->Size = System::Drawing::Size(160, 22);
			// 
			// lblHasta / dtpHasta
			// 
			this->lblHasta->AutoSize = true;
			this->lblHasta->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblHasta->ForeColor = System::Drawing::Color::FromArgb(90, 115, 140);
			this->lblHasta->Location = System::Drawing::Point(480, 14);
			this->lblHasta->Text = L"Hasta";
			this->dtpHasta->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dtpHasta->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F));
			this->dtpHasta->CalendarForeColor = System::Drawing::Color::FromArgb(30, 50, 70);
			this->dtpHasta->Location = System::Drawing::Point(480, 42);
			this->dtpHasta->Name = L"dtpHasta";
			this->dtpHasta->Size = System::Drawing::Size(160, 22);
			// 
			// lblMedicamentoFiltro / cmbMedicamento
			// 
			this->lblMedicamentoFiltro->AutoSize = true;
			this->lblMedicamentoFiltro->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblMedicamentoFiltro->ForeColor = System::Drawing::Color::FromArgb(90, 115, 140);
			this->lblMedicamentoFiltro->Location = System::Drawing::Point(660, 14);
			this->lblMedicamentoFiltro->Text = L"Medicamento";
			this->cmbPaciente->SelectedIndexChanged += gcnew System::EventHandler(this, &frmCumplimiento::cmbPaciente_SelectedIndexChanged);
			this->cmbMedicamento->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbMedicamento->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->cmbMedicamento->BackColor = System::Drawing::Color::White;
			this->cmbMedicamento->ForeColor = System::Drawing::Color::FromArgb(30, 50, 70);
			this->cmbMedicamento->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F));
			this->cmbMedicamento->Location = System::Drawing::Point(660, 42);
			this->cmbMedicamento->Name = L"cmbMedicamento";
			this->cmbMedicamento->Size = System::Drawing::Size(260, 24);
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
			this->btnAplicarFiltros->Location = System::Drawing::Point(946, 35);
			this->btnAplicarFiltros->Name = L"btnAplicarFiltros";
			this->btnAplicarFiltros->Size = System::Drawing::Size(160, 36);
			this->btnAplicarFiltros->Text = L"Aplicar filtros";
			this->btnAplicarFiltros->UseVisualStyleBackColor = false;
			this->btnAplicarFiltros->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnAplicarFiltros->Click += gcnew System::EventHandler(this, &frmCumplimiento::btnAplicarFiltros_Click);
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
			this->btnRestablecer->Location = System::Drawing::Point(1120, 35);
			this->btnRestablecer->Name = L"btnRestablecer";
			this->btnRestablecer->Size = System::Drawing::Size(160, 36);
			this->btnRestablecer->Text = L"Restablecer";
			this->btnRestablecer->UseVisualStyleBackColor = false;
			this->btnRestablecer->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnRestablecer->Click += gcnew System::EventHandler(this, &frmCumplimiento::btnRestablecer_Click);
			// 
			// KPI cards
			// 
			this->cardProgramadas->BackColor = System::Drawing::Color::White;
			this->cardProgramadas->Controls->Add(this->lblCardProgramadasTitulo);
			this->cardProgramadas->Controls->Add(this->lblProgramadas);
			this->cardProgramadas->Controls->Add(this->lblProgramadasSub);
			this->cardProgramadas->Location = System::Drawing::Point(22, 140);
			this->cardProgramadas->Size = System::Drawing::Size(244, 132);
			this->lblCardProgramadasTitulo->AutoSize = true;
			this->lblCardProgramadasTitulo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblCardProgramadasTitulo->ForeColor = System::Drawing::Color::FromArgb(90, 115, 140);
			this->lblCardProgramadasTitulo->Location = System::Drawing::Point(16, 16);
			this->lblCardProgramadasTitulo->Text = L"Dosis programadas";
			this->lblProgramadas->AutoSize = true;
			this->lblProgramadas->Font = (gcnew System::Drawing::Font(L"Segoe UI", 20, System::Drawing::FontStyle::Bold));
			this->lblProgramadas->Location = System::Drawing::Point(16, 45);
			this->lblProgramadas->Text = L"0";
			this->lblProgramadasSub->AutoSize = true;
			this->lblProgramadasSub->ForeColor = System::Drawing::Color::DimGray;
			this->lblProgramadasSub->Location = System::Drawing::Point(18, 92);
			this->lblProgramadasSub->Text = L"0 medicamento(s)";
			this->cardTomadas->BackColor = System::Drawing::Color::White;
			this->cardTomadas->Controls->Add(this->lblCardTomadasTitulo);
			this->cardTomadas->Controls->Add(this->lblTomadas);
			this->cardTomadas->Controls->Add(this->lblTomadasSub);
			this->cardTomadas->Location = System::Drawing::Point(284, 140);
			this->cardTomadas->Size = System::Drawing::Size(244, 132);
			this->lblCardTomadasTitulo->AutoSize = true;
			this->lblCardTomadasTitulo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblCardTomadasTitulo->ForeColor = System::Drawing::Color::FromArgb(90, 115, 140);
			this->lblCardTomadasTitulo->Location = System::Drawing::Point(16, 16);
			this->lblCardTomadasTitulo->Text = L"Dosis tomadas";
			this->lblTomadas->AutoSize = true;
			this->lblTomadas->Font = (gcnew System::Drawing::Font(L"Segoe UI", 20, System::Drawing::FontStyle::Bold));
			this->lblTomadas->ForeColor = System::Drawing::Color::FromArgb(20, 125, 95);
			this->lblTomadas->Location = System::Drawing::Point(16, 45);
			this->lblTomadas->Text = L"0";
			this->lblTomadasSub->AutoSize = true;
			this->lblTomadasSub->ForeColor = System::Drawing::Color::DimGray;
			this->lblTomadasSub->Location = System::Drawing::Point(18, 92);
			this->lblTomadasSub->Text = L"0% del total";
			this->cardOmitidas->BackColor = System::Drawing::Color::White;
			this->cardOmitidas->Controls->Add(this->lblCardOmitidasTitulo);
			this->cardOmitidas->Controls->Add(this->lblOmitidas);
			this->cardOmitidas->Controls->Add(this->lblOmitidasSub);
			this->cardOmitidas->Location = System::Drawing::Point(546, 140);
			this->cardOmitidas->Size = System::Drawing::Size(244, 132);
			this->lblCardOmitidasTitulo->AutoSize = true;
			this->lblCardOmitidasTitulo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblCardOmitidasTitulo->ForeColor = System::Drawing::Color::FromArgb(90, 115, 140);
			this->lblCardOmitidasTitulo->Location = System::Drawing::Point(16, 16);
			this->lblCardOmitidasTitulo->Text = L"Dosis omitidas";
			this->lblOmitidas->AutoSize = true;
			this->lblOmitidas->Font = (gcnew System::Drawing::Font(L"Segoe UI", 20, System::Drawing::FontStyle::Bold));
			this->lblOmitidas->ForeColor = System::Drawing::Color::FromArgb(180, 50, 50);
			this->lblOmitidas->Location = System::Drawing::Point(16, 45);
			this->lblOmitidas->Text = L"0";
			this->lblOmitidasSub->AutoSize = true;
			this->lblOmitidasSub->ForeColor = System::Drawing::Color::DimGray;
			this->lblOmitidasSub->Location = System::Drawing::Point(18, 92);
			this->lblOmitidasSub->Text = L"0% del total";
			this->cardCumplimiento->BackColor = System::Drawing::Color::White;
			this->cardCumplimiento->Controls->Add(this->lblCardCumplimientoTitulo);
			this->cardCumplimiento->Controls->Add(this->lblCumplimiento);
			this->cardCumplimiento->Controls->Add(this->lblCumplimientoSub);
			this->cardCumplimiento->Location = System::Drawing::Point(808, 140);
			this->cardCumplimiento->Size = System::Drawing::Size(244, 132);
			this->lblCardCumplimientoTitulo->AutoSize = true;
			this->lblCardCumplimientoTitulo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblCardCumplimientoTitulo->ForeColor = System::Drawing::Color::FromArgb(90, 115, 140);
			this->lblCardCumplimientoTitulo->Location = System::Drawing::Point(16, 16);
			this->lblCardCumplimientoTitulo->Text = L"% Cumplimiento total";
			this->lblCumplimiento->AutoSize = true;
			this->lblCumplimiento->Font = (gcnew System::Drawing::Font(L"Segoe UI", 20, System::Drawing::FontStyle::Bold));
			this->lblCumplimiento->ForeColor = System::Drawing::Color::FromArgb(20, 125, 95);
			this->lblCumplimiento->Location = System::Drawing::Point(16, 45);
			this->lblCumplimiento->Text = L"0%";
			this->lblCumplimientoSub->AutoSize = true;
			this->lblCumplimientoSub->ForeColor = System::Drawing::Color::DimGray;
			this->lblCumplimientoSub->Location = System::Drawing::Point(18, 92);
			this->lblCumplimientoSub->Text = L"Meta: >= 80%";
			this->cardMedicamentos->BackColor = System::Drawing::Color::White;
			this->cardMedicamentos->Controls->Add(this->lblCardMedicamentosTitulo);
			this->cardMedicamentos->Controls->Add(this->lblMedicamentos);
			this->cardMedicamentos->Controls->Add(this->lblMedicamentosSub);
			this->cardMedicamentos->Location = System::Drawing::Point(1070, 140);
			this->cardMedicamentos->Size = System::Drawing::Size(252, 132);
			this->lblCardMedicamentosTitulo->AutoSize = true;
			this->lblCardMedicamentosTitulo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblCardMedicamentosTitulo->ForeColor = System::Drawing::Color::FromArgb(90, 115, 140);
			this->lblCardMedicamentosTitulo->Location = System::Drawing::Point(16, 16);
			this->lblCardMedicamentosTitulo->Text = L"Medicamentos";
			this->lblMedicamentos->AutoSize = true;
			this->lblMedicamentos->Font = (gcnew System::Drawing::Font(L"Segoe UI", 20, System::Drawing::FontStyle::Bold));
			this->lblMedicamentos->Location = System::Drawing::Point(16, 45);
			this->lblMedicamentos->Text = L"0";
			this->lblMedicamentosSub->AutoSize = true;
			this->lblMedicamentosSub->ForeColor = System::Drawing::Color::DimGray;
			this->lblMedicamentosSub->Location = System::Drawing::Point(18, 92);
			this->lblMedicamentosSub->Text = L"en seguimiento";
			// 
			// grpCumplimientoTotal / chartAnillo
			// 
			this->grpCumplimientoTotal->BackColor = System::Drawing::Color::White;
			this->grpCumplimientoTotal->Controls->Add(this->chartAnillo);
			this->grpCumplimientoTotal->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular));
			this->grpCumplimientoTotal->Location = System::Drawing::Point(22, 292);
			this->grpCumplimientoTotal->Name = L"grpCumplimientoTotal";
			this->grpCumplimientoTotal->Size = System::Drawing::Size(620, 360);
			this->grpCumplimientoTotal->Text = L"Cumplimiento total";
			areaAnillo->Name = L"AreaAnillo";
			this->chartAnillo->ChartAreas->Add(areaAnillo);
			this->chartAnillo->Dock = System::Windows::Forms::DockStyle::Fill;
			leyendaAnillo->Docking = System::Windows::Forms::DataVisualization::Charting::Docking::Bottom;
			leyendaAnillo->Name = L"LeyendaAnillo";
			this->chartAnillo->Legends->Add(leyendaAnillo);
			serieAnillo->ChartArea = L"AreaAnillo";
			serieAnillo->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Doughnut;
			serieAnillo->Legend = L"LeyendaAnillo";
			serieAnillo->Name = L"Cumplimiento";
			this->chartAnillo->Series->Add(serieAnillo);
			// 
			// grpCumplimientoMedicamento / chartMedicamentos
			// 
			this->grpCumplimientoMedicamento->BackColor = System::Drawing::Color::White;
			this->grpCumplimientoMedicamento->Controls->Add(this->chartMedicamentos);
			this->grpCumplimientoMedicamento->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular));
			this->grpCumplimientoMedicamento->Location = System::Drawing::Point(662, 292);
			this->grpCumplimientoMedicamento->Name = L"grpCumplimientoMedicamento";
			this->grpCumplimientoMedicamento->Size = System::Drawing::Size(660, 360);
			this->grpCumplimientoMedicamento->Text = L"Cumplimiento por medicamento";
			areaMedicamentos->Name = L"AreaMedicamentos";
			this->chartMedicamentos->ChartAreas->Add(areaMedicamentos);
			this->chartMedicamentos->Dock = System::Windows::Forms::DockStyle::Fill;
			leyendaMedicamentos->Docking = System::Windows::Forms::DataVisualization::Charting::Docking::Top;
			leyendaMedicamentos->Name = L"LeyendaMedicamentos";
			this->chartMedicamentos->Legends->Add(leyendaMedicamentos);
			serieTomadas->ChartArea = L"AreaMedicamentos";
			serieTomadas->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::StackedColumn100;
			serieTomadas->Legend = L"LeyendaMedicamentos";
			serieTomadas->Name = L"Tomadas";
			serieOmitidas->ChartArea = L"AreaMedicamentos";
			serieOmitidas->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::StackedColumn100;
			serieOmitidas->Legend = L"LeyendaMedicamentos";
			serieOmitidas->Name = L"Omitidas";
			this->chartMedicamentos->Series->Add(serieTomadas);
			this->chartMedicamentos->Series->Add(serieOmitidas);
			// 
			// grpDetalle / dgvDetalle
			// 
			this->grpDetalle->BackColor = System::Drawing::Color::White;
			this->grpDetalle->Controls->Add(this->dgvDetalle);
			this->grpDetalle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular));
			this->grpDetalle->Location = System::Drawing::Point(22, 674);
			this->grpDetalle->Name = L"grpDetalle";
			this->grpDetalle->Size = System::Drawing::Size(1300, 280);
			this->grpDetalle->Text = L"Detalle por medicamento";
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
			this->dgvDetalle->Columns->AddRange(gcnew cli::array<System::Windows::Forms::DataGridViewColumn^>(7) {
				this->colMedicamento, this->colDosis, this->colProgramadas, this->colTomadas,
					this->colOmitidas, this->colCumplimiento, this->colEstado
			});
			this->dgvDetalle->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dgvDetalle->Name = L"dgvDetalle";
			this->dgvDetalle->ReadOnly = true;
			this->dgvDetalle->RowHeadersVisible = false;
			this->dgvDetalle->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->colMedicamento->HeaderText = L"Medicamento";
			this->colMedicamento->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->colMedicamento->FillWeight = 150;
			this->colMedicamento->Name = L"colMedicamento";
			this->colMedicamento->ReadOnly = true;
			this->colDosis->HeaderText = L"Dosis/dia";
			this->colDosis->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->colDosis->FillWeight = 85;
			this->colDosis->Name = L"colDosis";
			this->colDosis->ReadOnly = true;
			this->colProgramadas->HeaderText = L"Programadas";
			this->colProgramadas->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->colProgramadas->FillWeight = 90;
			this->colProgramadas->Name = L"colProgramadas";
			this->colProgramadas->ReadOnly = true;
			this->colTomadas->HeaderText = L"Tomadas";
			this->colTomadas->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->colTomadas->FillWeight = 80;
			this->colTomadas->Name = L"colTomadas";
			this->colTomadas->ReadOnly = true;
			this->colOmitidas->HeaderText = L"Omitidas";
			this->colOmitidas->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->colOmitidas->FillWeight = 80;
			this->colOmitidas->Name = L"colOmitidas";
			this->colOmitidas->ReadOnly = true;
			this->colCumplimiento->HeaderText = L"% Cumplimiento";
			this->colCumplimiento->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->colCumplimiento->FillWeight = 105;
			this->colCumplimiento->Name = L"colCumplimiento";
			this->colCumplimiento->ReadOnly = true;
			this->colEstado->HeaderText = L"Estado";
			this->colEstado->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->colEstado->FillWeight = 90;
			this->colEstado->Name = L"colEstado";
			this->colEstado->ReadOnly = true;
			// 
			// grpObservaciones / txtObservaciones
			// 
			this->grpObservaciones->BackColor = System::Drawing::Color::White;
			this->grpObservaciones->Controls->Add(this->txtObservaciones);
			this->grpObservaciones->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular));
			this->grpObservaciones->Location = System::Drawing::Point(22, 976);
			this->grpObservaciones->Name = L"grpObservaciones";
			this->grpObservaciones->Size = System::Drawing::Size(1300, 180);
			this->grpObservaciones->Text = L"Observaciones automaticas";
			this->txtObservaciones->BackColor = System::Drawing::Color::FromArgb(247, 249, 251);
			this->txtObservaciones->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txtObservaciones->Dock = System::Windows::Forms::DockStyle::Fill;
			this->txtObservaciones->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F));
			this->txtObservaciones->ForeColor = System::Drawing::Color::FromArgb(40, 60, 80);
			this->txtObservaciones->Name = L"txtObservaciones";
			this->txtObservaciones->ReadOnly = true;
			// 
			// frmCumplimiento
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(241, 244, 248);
			this->ClientSize = System::Drawing::Size(1360, 760);
			this->ControlBox = false;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Controls->Add(this->panelContenido);
			this->Controls->Add(this->panelCabecera);
			this->Name = L"frmCumplimiento";
			this->Text = L"";
			this->Load += gcnew System::EventHandler(
				this,
				&frmCumplimiento::frmCumplimiento_Load
			);
			this->Resize += gcnew System::EventHandler(
				this,
				&frmCumplimiento::frmCumplimiento_Resize
			);
			this->panelCabecera->ResumeLayout(false);
			this->panelCabecera->PerformLayout();
			this->panelContenido->ResumeLayout(false);
			this->panelFiltros->ResumeLayout(false);
			this->panelFiltros->PerformLayout();
			this->cardProgramadas->ResumeLayout(false);
			this->cardProgramadas->PerformLayout();
			this->cardTomadas->ResumeLayout(false);
			this->cardTomadas->PerformLayout();
			this->cardOmitidas->ResumeLayout(false);
			this->cardOmitidas->PerformLayout();
			this->cardCumplimiento->ResumeLayout(false);
			this->cardCumplimiento->PerformLayout();
			this->cardMedicamentos->ResumeLayout(false);
			this->cardMedicamentos->PerformLayout();
			this->grpCumplimientoTotal->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartAnillo))->EndInit();
			this->grpCumplimientoMedicamento->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartMedicamentos))->EndInit();
			this->grpDetalle->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvDetalle))->EndInit();
			this->grpObservaciones->ResumeLayout(false);
			this->ResumeLayout(false);
		}
#pragma endregion

	private:
		bool Contiene(String^ texto, String^ valor) {
			return !String::IsNullOrWhiteSpace(texto) &&
				texto->IndexOf(valor, StringComparison::OrdinalIgnoreCase) >= 0;
		}

		bool EsEventoDosis(LogEvento^ evento) {
			return evento != nullptr &&
				(Contiene(evento->getTipoEvento(), "Dosis") || Contiene(evento->getTipoEvento(), "Toma")) &&
				!Contiene(evento->getEstado(), "Pausa");
		}

		bool EsTomada(LogEvento^ evento) {
			return evento != nullptr &&
				(Contiene(evento->getEstado(), "Tomada") ||
					Contiene(evento->getEstado(), "A tiempo") ||
					Contiene(evento->getEstado(), "Retraso") ||
					Contiene(evento->getEstado(), "Exitosa"));
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
			int idPaciente = ObtenerIdSeleccionado(this->cmbPaciente);
			int idMedicamento = ObtenerIdSeleccionado(this->cmbMedicamento);
			DateTime desde = this->dtpDesde->Value.Date;
			DateTime hasta = this->dtpHasta->Value.Date;

			for each(LogEvento ^ evento in this->reportesController->ObtenerTodos()) {
				if (!EsEventoDosis(evento) || evento->getFechaHoraProgramada() == DateTime::MinValue)
					continue;
				if (evento->getFechaHoraProgramada().Date < desde || evento->getFechaHoraProgramada().Date > hasta)
					continue;
				if (idPaciente > 0 && evento->getIdPaciente() != idPaciente)
					continue;
				if (idMedicamento > 0 && evento->getIdMedicamento() != idMedicamento)
					continue;
				resultado->Add(evento);
			}
			return resultado;
		}

		int ObtenerDosisDiaria(int idMedicamento) {
			int total = 0;
			int idPaciente = ObtenerIdSeleccionado(this->cmbPaciente);
			for each(Receta ^ receta in this->recetaController->ObtenerTodosRecetasTXT()) {
				if (receta->getMedicamento() == nullptr || receta->getMedicamento()->getId() != idMedicamento)
					continue;
				if (idPaciente > 0 && receta->getIdPaciente() != idPaciente)
					continue;
				total += receta->getDosisDiaria();
			}
			return total;
		}

		String^ EstadoCumplimiento(double porcentaje) {
			if (porcentaje >= 80.0)
				return "Optimo";
			if (porcentaje >= 60.0)
				return "Regular";
			return "Critico";
		}

		void CargarFiltros() {
			List<LogEvento^>^ eventos = this->reportesController->ObtenerTodos();
			SortedDictionary<int, String^>^ pacientes = gcnew SortedDictionary<int, String^>();
			SortedDictionary<int, String^>^ medicamentos = gcnew SortedDictionary<int, String^>();
			DateTime minimo = DateTime::MaxValue;
			DateTime maximo = DateTime::MinValue;

			for each(LogEvento ^ evento in eventos) {
				if (!EsEventoDosis(evento))
					continue;
				if (evento->getIdPaciente() > 0 && !pacientes->ContainsKey(evento->getIdPaciente()))
					pacientes->Add(evento->getIdPaciente(), evento->getNombrePaciente());
				if (evento->getIdMedicamento() > 0 && !medicamentos->ContainsKey(evento->getIdMedicamento()))
					medicamentos->Add(evento->getIdMedicamento(), evento->getMedicamento());
				if (evento->getFechaHoraProgramada() != DateTime::MinValue) {
					if (evento->getFechaHoraProgramada() < minimo) minimo = evento->getFechaHoraProgramada();
					if (evento->getFechaHoraProgramada() > maximo) maximo = evento->getFechaHoraProgramada();
				}
			}

			this->cmbPaciente->Items->Clear();
			this->cmbPaciente->Items->Add("Todos los pacientes");
			for each(KeyValuePair<int, String^> paciente in pacientes)
				this->cmbPaciente->Items->Add(paciente.Key + " - " + paciente.Value);
			this->cmbPaciente->SelectedIndex = 0;

			this->cmbMedicamento->Items->Clear();
			this->cmbMedicamento->Items->Add("Todos los medicamentos");
			for each(KeyValuePair<int, String^> medicamento in medicamentos)
				this->cmbMedicamento->Items->Add(medicamento.Key + " - " + medicamento.Value);
			this->cmbMedicamento->SelectedIndex = 0;

			this->dtpDesde->Value = minimo == DateTime::MaxValue ? DateTime::Today.AddDays(-30) : minimo.Date;
			this->dtpHasta->Value = maximo == DateTime::MinValue ? DateTime::Today : maximo.Date;
		}

		void ConfigurarGraficos() {
			this->chartAnillo->Series["Cumplimiento"]->SetCustomProperty("DoughnutRadius", "65");
			this->chartAnillo->Series["Cumplimiento"]->SetCustomProperty("PieLabelStyle", "Disabled");
			this->chartAnillo->BackColor = Color::White;
			this->chartAnillo->ChartAreas["AreaAnillo"]->BackColor = Color::White;

			ChartArea^ area = this->chartMedicamentos->ChartAreas["AreaMedicamentos"];
			area->AxisY->Minimum = 0;
			area->AxisY->Maximum = 100;
			area->AxisY->LabelStyle->Format = "0'%'";
			area->AxisX->Interval = 1;
			area->AxisX->LabelStyle->Angle = -20;
			area->BackColor = Color::White;
			this->chartMedicamentos->BackColor = Color::White;
			this->chartMedicamentos->Series["Tomadas"]->Color = Color::FromArgb(29, 158, 117);
			this->chartMedicamentos->Series["Omitidas"]->Color = Color::FromArgb(239, 159, 39);
		}

		void AjustarControlesReporte() {
			this->chartAnillo->Dock = System::Windows::Forms::DockStyle::Fill;
			this->chartMedicamentos->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dgvDetalle->Dock = System::Windows::Forms::DockStyle::Fill;

			ChartArea^ areaAnillo = this->chartAnillo->ChartAreas["AreaAnillo"];
			areaAnillo->Position->Auto = false;
			areaAnillo->Position->X = 4;
			areaAnillo->Position->Y = 5;
			areaAnillo->Position->Width = 58;
			areaAnillo->Position->Height = 82;

			ChartArea^ areaMedicamentos = this->chartMedicamentos->ChartAreas["AreaMedicamentos"];
			areaMedicamentos->Position->Auto = false;
			areaMedicamentos->Position->X = 7;
			areaMedicamentos->Position->Y = 12;
			areaMedicamentos->Position->Width = 90;
			areaMedicamentos->Position->Height = 78;

			for each(DataGridViewColumn ^ columna in this->dgvDetalle->Columns)
				columna->AutoSizeMode = DataGridViewAutoSizeColumnMode::Fill;

			this->grpCumplimientoTotal->PerformLayout();
			this->grpCumplimientoMedicamento->PerformLayout();
			this->grpDetalle->PerformLayout();
		}

		void ActualizarReporte() {
			List<LogEvento^>^ eventos = ObtenerEventosFiltrados();
			Dictionary<int, array<int>^>^ valores = gcnew Dictionary<int, array<int>^>();
			Dictionary<int, String^>^ nombres = gcnew Dictionary<int, String^>();
			int tomadas = 0;

			for each(LogEvento ^ evento in eventos) {
				int id = evento->getIdMedicamento();
				if (!valores->ContainsKey(id)) {
					valores->Add(id, gcnew array<int>(2));
					nombres->Add(id, String::IsNullOrWhiteSpace(evento->getMedicamento()) ? "Sin medicamento" : evento->getMedicamento());
				}
				array<int>^ arr = valores[id]; arr[0]++;
				if (EsTomada(evento)) {
					arr[1]++;
					tomadas++;
				}
			}

			int programadas = eventos->Count;
			int omitidas = programadas - tomadas;
			double porcentaje = programadas == 0 ? 0.0 : tomadas * 100.0 / programadas;
			this->lblProgramadas->Text = programadas.ToString();
			this->lblProgramadasSub->Text = valores->Count + " medicamento(s)";
			this->lblTomadas->Text = tomadas.ToString();
			this->lblTomadasSub->Text = String::Format("{0:F0}% del total", porcentaje);
			this->lblOmitidas->Text = omitidas.ToString();
			this->lblOmitidasSub->Text = String::Format("{0:F0}% del total", programadas == 0 ? 0.0 : omitidas * 100.0 / programadas);
			this->lblCumplimiento->Text = String::Format("{0:F0}%", porcentaje);
			this->lblCumplimiento->ForeColor = porcentaje >= 80.0 ? Color::FromArgb(20, 125, 95) : Color::FromArgb(180, 50, 50);
			this->lblMedicamentos->Text = valores->Count.ToString();

			Series^ anillo = this->chartAnillo->Series["Cumplimiento"];
			anillo->Points->Clear();
			int puntoTomadas = anillo->Points->AddXY("Tomadas", tomadas);
			int puntoOmitidas = anillo->Points->AddXY("Omitidas", omitidas);
			anillo->Points[puntoTomadas]->Color = Color::FromArgb(29, 158, 117);
			anillo->Points[puntoOmitidas]->Color = Color::FromArgb(232, 73, 73);
			this->chartAnillo->Titles->Clear();
			this->chartAnillo->Annotations->Clear();
			TextAnnotation^ anotacionPorcentaje = gcnew TextAnnotation();
			anotacionPorcentaje->Text = String::Format("{0:F0}%\nCumplimiento", porcentaje);
			anotacionPorcentaje->Font = gcnew Drawing::Font("Segoe UI", 13, FontStyle::Bold);
			anotacionPorcentaje->ForeColor = Color::FromArgb(60, 60, 60);
			anotacionPorcentaje->Alignment = System::Drawing::ContentAlignment::MiddleLeft;
			anotacionPorcentaje->ClipToChartArea = "AreaAnillo";
			anotacionPorcentaje->AllowMoving = false;
			anotacionPorcentaje->AllowSelecting = false;
			anotacionPorcentaje->X = 64;
			anotacionPorcentaje->Y = 36;
			anotacionPorcentaje->Width = 32;
			anotacionPorcentaje->Height = 20;
			this->chartAnillo->Annotations->Add(anotacionPorcentaje);

			Series^ serieTomadas = this->chartMedicamentos->Series["Tomadas"];
			Series^ serieOmitidas = this->chartMedicamentos->Series["Omitidas"];
			serieTomadas->Points->Clear();
			serieOmitidas->Points->Clear();
			this->dgvDetalle->Rows->Clear();
			double mejorPorcentaje = -1.0;
			String^ mejorMedicamento = "";
			List<String^>^ criticos = gcnew List<String^>();

			for each(KeyValuePair<int, array<int>^> item in valores) {
				int total = item.Value[0];
				int cumplidas = item.Value[1];
				int noCumplidas = total - cumplidas;
				double porcentajeMedicamento = total == 0 ? 0.0 : cumplidas * 100.0 / total;
				String^ nombre = nombres[item.Key];
				serieTomadas->Points->AddXY(nombre, cumplidas);
				serieOmitidas->Points->AddXY(nombre, noCumplidas);
				String^ estado = EstadoCumplimiento(porcentajeMedicamento);
				int fila = this->dgvDetalle->Rows->Add(
					nombre, ObtenerDosisDiaria(item.Key) + "x/dia", total, cumplidas,
					noCumplidas, String::Format("{0:F0}%", porcentajeMedicamento), estado);
				this->dgvDetalle->Rows[fila]->Cells[3]->Style->ForeColor = Color::FromArgb(20, 125, 95);
				this->dgvDetalle->Rows[fila]->Cells[4]->Style->ForeColor = Color::FromArgb(180, 50, 50);
				this->dgvDetalle->Rows[fila]->Cells[6]->Style->ForeColor =
					estado == "Optimo" ? Color::FromArgb(20, 125, 95) :
					estado == "Regular" ? Color::FromArgb(190, 120, 20) : Color::FromArgb(180, 50, 50);
				if (porcentajeMedicamento > mejorPorcentaje) {
					mejorPorcentaje = porcentajeMedicamento;
					mejorMedicamento = nombre;
				}
				if (porcentajeMedicamento < 60.0)
					criticos->Add(nombre);
			}
			this->dgvDetalle->ClearSelection();

			StringBuilder^ observacion = gcnew StringBuilder();
			if (programadas == 0) {
				observacion->Append("No existen eventos de toma para los filtros seleccionados.");
			}
			else {
				observacion->AppendFormat(
					"Durante el periodo analizado se registro un cumplimiento global del {0:F0}% ({1} de {2} dosis tomadas). ",
					porcentaje, tomadas, programadas);
				observacion->Append(porcentaje >= 80.0
					? "El resultado alcanza la meta recomendada del 80%. "
					: "El resultado se encuentra por debajo de la meta recomendada del 80%. ");
				if (!String::IsNullOrWhiteSpace(mejorMedicamento))
					observacion->AppendFormat("El medicamento con mejor cumplimiento fue {0} ({1:F0}%). ",
						mejorMedicamento, mejorPorcentaje);
				if (criticos->Count > 0)
					observacion->Append("Se detecto cumplimiento critico en: " + String::Join(", ", criticos->ToArray()) + ". ");
				observacion->Append("Se recomienda revisar los horarios y las causas de las dosis omitidas.");
			}
			this->txtObservaciones->Text = observacion->ToString();
			this->lblGenerado->Text = "Generado: " + DateTime::Now.ToString("dd/MM/yyyy HH:mm");
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

			int yFiltros = 18;

			int yTarjetas =
				yFiltros +
				this->panelFiltros->Height +
				espacioVertical;

			int yGraficos =
				yTarjetas +
				this->cardProgramadas->Height +
				espacioVertical;

			int yDetalle =
				yGraficos +
				this->grpCumplimientoTotal->Height +
				espacioVertical;

			int yObservaciones =
				yDetalle +
				this->grpDetalle->Height +
				espacioVertical;

			// Panel de filtros
			this->panelFiltros->Location =
				System::Drawing::Point(margen, yFiltros);
			this->panelFiltros->Width = anchoDisponible;
			this->panelFiltros->Height = 104;

			int espacioInterno = 18;
			int separacionFiltro = 14;
			int anchoPaciente = 210;
			int anchoFecha = 140;
			int anchoMedicamento = 220;
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

			int xRestablecer =
				this->panelFiltros->ClientSize.Width -
				espacioInterno -
				anchoBoton;

			int xAplicar =
				xRestablecer -
				separacionFiltro -
				anchoBoton;

			this->btnAplicarFiltros->Location =
				System::Drawing::Point(xAplicar, 34);
			this->btnAplicarFiltros->Width = anchoBoton;

			this->btnRestablecer->Location =
				System::Drawing::Point(xRestablecer, 34);
			this->btnRestablecer->Width = anchoBoton;

			if (x + anchoMedicamento + separacionFiltro > xAplicar) {
				this->cmbMedicamento->Width =
					Math::Max(120, xAplicar - separacionFiltro - x);
			}

			// Cinco tarjetas reales del formulario
			array<System::Windows::Forms::Panel^>^ tarjetas = {
				this->cardProgramadas,
				this->cardTomadas,
				this->cardOmitidas,
				this->cardCumplimiento,
				this->cardMedicamentos
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

			// Gráficos reales del formulario
			this->grpCumplimientoTotal->Location =
				System::Drawing::Point(margen, yGraficos);
			this->grpCumplimientoTotal->Width = anchoMitad;

			this->grpCumplimientoMedicamento->Location =
				System::Drawing::Point(
					margen + anchoMitad + separacion,
					yGraficos
				);
			this->grpCumplimientoMedicamento->Width = anchoMitad;

			// Tabla y observaciones
			this->grpDetalle->Location =
				System::Drawing::Point(margen, yDetalle);
			this->grpDetalle->Width = anchoDisponible;

			this->grpObservaciones->Location =
				System::Drawing::Point(margen, yObservaciones);
			this->grpObservaciones->Width = anchoDisponible;

			AjustarControlesReporte();
		}

		System::Void frmCumplimiento_Resize(
			System::Object^ sender,
			System::EventArgs^ e
		) {
			AjustarDistribucion();
		}

		System::Void frmCumplimiento_Load(System::Object^ sender, System::EventArgs^ e) {
			this->reportesController = gcnew GeneradorReportesController();
			this->recetaController = gcnew RecetaController();
			ConfigurarGraficos();
			CargarFiltros();
			ActualizarReporte();
			AjustarDistribucion();
			this->BeginInvoke(
				gcnew MethodInvoker(
					this,
					&frmCumplimiento::AjustarDistribucion
				)
			);
		}

		System::Void btnAplicarFiltros_Click(System::Object^ sender, System::EventArgs^ e) {
			if (this->dtpDesde->Value.Date > this->dtpHasta->Value.Date) {
				MessageBox::Show("La fecha inicial no puede ser posterior a la fecha final.",
					"Cumplimiento", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}
			ActualizarReporte();
		}

		System::Void btnRestablecer_Click(System::Object^ sender, System::EventArgs^ e) {
			CargarFiltros();
			ActualizarReporte();
		}

	private: System::Void cmbPaciente_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		int idPaciente = ObtenerIdSeleccionado(cmbPaciente);
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