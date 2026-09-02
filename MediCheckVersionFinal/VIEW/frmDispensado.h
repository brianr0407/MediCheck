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

	public ref class frmDispensado : public System::Windows::Forms::Form {
	public:
		frmDispensado() {
			InitializeComponent();
		}

	protected:
		~frmDispensado() {
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
		System::Windows::Forms::Label^ lblEstadoFiltro;
		System::Windows::Forms::ComboBox^ cmbEstado;
		System::Windows::Forms::Button^ btnAplicarFiltros;
		System::Windows::Forms::Button^ btnRestablecer;

		System::Windows::Forms::Panel^ cardEventos;
		System::Windows::Forms::Label^ lblCardEventosTitulo;
		System::Windows::Forms::Label^ lblEventos;
		System::Windows::Forms::Label^ lblEventosSub;
		System::Windows::Forms::Panel^ cardOk;
		System::Windows::Forms::Label^ lblCardOkTitulo;
		System::Windows::Forms::Label^ lblOk;
		System::Windows::Forms::Label^ lblOkSub;
		System::Windows::Forms::Panel^ cardRetrasos;
		System::Windows::Forms::Label^ lblCardRetrasosTitulo;
		System::Windows::Forms::Label^ lblRetrasos;
		System::Windows::Forms::Label^ lblRetrasosSub;
		System::Windows::Forms::Panel^ cardErrores;
		System::Windows::Forms::Label^ lblCardErroresTitulo;
		System::Windows::Forms::Label^ lblErrores;
		System::Windows::Forms::Label^ lblErroresSub;
		System::Windows::Forms::Panel^ cardExito;
		System::Windows::Forms::Label^ lblCardExitoTitulo;
		System::Windows::Forms::Label^ lblExito;
		System::Windows::Forms::Label^ lblExitoSub;

		System::Windows::Forms::GroupBox^ grpUnidades;
		System::Windows::Forms::DataVisualization::Charting::Chart^ chartUnidades;
		System::Windows::Forms::GroupBox^ grpEstados;
		System::Windows::Forms::DataVisualization::Charting::Chart^ chartEstados;
		System::Windows::Forms::GroupBox^ grpDetalle;
		System::Windows::Forms::DataGridView^ dgvDetalle;
		System::Windows::Forms::DataGridViewTextBoxColumn^ colIdEvento;
		System::Windows::Forms::DataGridViewTextBoxColumn^ colFechaReal;
		System::Windows::Forms::DataGridViewTextBoxColumn^ colPaciente;
		System::Windows::Forms::DataGridViewTextBoxColumn^ colMedicamento;
		System::Windows::Forms::DataGridViewTextBoxColumn^ colCantidad;
		System::Windows::Forms::DataGridViewTextBoxColumn^ colEstado;
		System::Windows::Forms::GroupBox^ grpObservaciones;
		System::Windows::Forms::RichTextBox^ txtObservaciones;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void) {
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ areaUnidades = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ leyendaUnidades = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ serieEjemplo = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ areaEstados = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ leyendaEstados = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ serieEstados = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
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
			this->lblEstadoFiltro = (gcnew System::Windows::Forms::Label());
			this->cmbEstado = (gcnew System::Windows::Forms::ComboBox());
			this->btnAplicarFiltros = (gcnew System::Windows::Forms::Button());
			this->btnRestablecer = (gcnew System::Windows::Forms::Button());
			this->cardEventos = (gcnew System::Windows::Forms::Panel());
			this->lblCardEventosTitulo = (gcnew System::Windows::Forms::Label());
			this->lblEventos = (gcnew System::Windows::Forms::Label());
			this->lblEventosSub = (gcnew System::Windows::Forms::Label());
			this->cardOk = (gcnew System::Windows::Forms::Panel());
			this->lblCardOkTitulo = (gcnew System::Windows::Forms::Label());
			this->lblOk = (gcnew System::Windows::Forms::Label());
			this->lblOkSub = (gcnew System::Windows::Forms::Label());
			this->cardRetrasos = (gcnew System::Windows::Forms::Panel());
			this->lblCardRetrasosTitulo = (gcnew System::Windows::Forms::Label());
			this->lblRetrasos = (gcnew System::Windows::Forms::Label());
			this->lblRetrasosSub = (gcnew System::Windows::Forms::Label());
			this->cardErrores = (gcnew System::Windows::Forms::Panel());
			this->lblCardErroresTitulo = (gcnew System::Windows::Forms::Label());
			this->lblErrores = (gcnew System::Windows::Forms::Label());
			this->lblErroresSub = (gcnew System::Windows::Forms::Label());
			this->cardExito = (gcnew System::Windows::Forms::Panel());
			this->lblCardExitoTitulo = (gcnew System::Windows::Forms::Label());
			this->lblExito = (gcnew System::Windows::Forms::Label());
			this->lblExitoSub = (gcnew System::Windows::Forms::Label());
			this->grpUnidades = (gcnew System::Windows::Forms::GroupBox());
			this->chartUnidades = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->grpEstados = (gcnew System::Windows::Forms::GroupBox());
			this->chartEstados = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->grpDetalle = (gcnew System::Windows::Forms::GroupBox());
			this->dgvDetalle = (gcnew System::Windows::Forms::DataGridView());
			this->colIdEvento = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colFechaReal = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colPaciente = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colMedicamento = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colCantidad = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colEstado = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->grpObservaciones = (gcnew System::Windows::Forms::GroupBox());
			this->txtObservaciones = (gcnew System::Windows::Forms::RichTextBox());
			this->panelCabecera->SuspendLayout();
			this->panelContenido->SuspendLayout();
			this->panelFiltros->SuspendLayout();
			this->cardEventos->SuspendLayout();
			this->cardOk->SuspendLayout();
			this->cardRetrasos->SuspendLayout();
			this->cardErrores->SuspendLayout();
			this->cardExito->SuspendLayout();
			this->grpUnidades->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartUnidades))->BeginInit();
			this->grpEstados->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartEstados))->BeginInit();
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
			// 
			// lblTitulo
			// 
			this->lblTitulo->AutoSize = true;
			this->lblTitulo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15, System::Drawing::FontStyle::Regular));
			this->lblTitulo->ForeColor = System::Drawing::Color::FromArgb(220, 233, 245);
			this->lblTitulo->Location = System::Drawing::Point(24, 13);
			this->lblTitulo->Name = L"lblTitulo";
			this->lblTitulo->Text = L"Reporte de Medicamentos Dispensados";
			// 
			// lblSubtitulo
			// 
			this->lblSubtitulo->AutoSize = true;
			this->lblSubtitulo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->lblSubtitulo->ForeColor = System::Drawing::Color::FromArgb(200, 218, 235);
			this->lblSubtitulo->Location = System::Drawing::Point(27, 50);
			this->lblSubtitulo->Name = L"lblSubtitulo";
			this->lblSubtitulo->Text = L"Seguimiento automatico de dispensaciones del sistema";
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
			this->panelContenido->Controls->Add(this->cardEventos);
			this->panelContenido->Controls->Add(this->cardOk);
			this->panelContenido->Controls->Add(this->cardRetrasos);
			this->panelContenido->Controls->Add(this->cardErrores);
			this->panelContenido->Controls->Add(this->cardExito);
			this->panelContenido->Controls->Add(this->grpUnidades);
			this->panelContenido->Controls->Add(this->grpEstados);
			this->panelContenido->Controls->Add(this->grpDetalle);
			this->panelContenido->Controls->Add(this->grpObservaciones);
			this->panelContenido->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panelContenido->Location = System::Drawing::Point(0, 84);
			this->panelContenido->Name = L"panelContenido";
			this->panelContenido->Size = System::Drawing::Size(1360, 676);
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
			this->panelFiltros->Controls->Add(this->lblEstadoFiltro);
			this->panelFiltros->Controls->Add(this->cmbEstado);
			this->panelFiltros->Controls->Add(this->btnAplicarFiltros);
			this->panelFiltros->Controls->Add(this->btnRestablecer);
			this->panelFiltros->Location = System::Drawing::Point(22, 20);
			this->panelFiltros->Name = L"panelFiltros";
			this->panelFiltros->Size = System::Drawing::Size(1300, 116);
			// 
			// filtros
			// 
			this->lblPacienteFiltro->AutoSize = true;
			this->lblPacienteFiltro->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblPacienteFiltro->ForeColor = System::Drawing::Color::FromArgb(90, 115, 140);
			this->lblPacienteFiltro->Location = System::Drawing::Point(18, 13);
			this->lblPacienteFiltro->Text = L"Paciente";
			this->cmbPaciente->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbPaciente->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->cmbPaciente->BackColor = System::Drawing::Color::White;
			this->cmbPaciente->ForeColor = System::Drawing::Color::FromArgb(30, 50, 70);
			this->cmbPaciente->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F));
			this->cmbPaciente->Location = System::Drawing::Point(18, 40);
			this->cmbPaciente->Name = L"cmbPaciente";
			this->cmbPaciente->Size = System::Drawing::Size(225, 24);
			this->lblDesde->AutoSize = true;
			this->lblDesde->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblDesde->ForeColor = System::Drawing::Color::FromArgb(90, 115, 140);
			this->lblDesde->Location = System::Drawing::Point(258, 13);
			this->lblDesde->Text = L"Desde";
			this->dtpDesde->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dtpDesde->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F));
			this->dtpDesde->CalendarForeColor = System::Drawing::Color::FromArgb(30, 50, 70);
			this->dtpDesde->Location = System::Drawing::Point(258, 40);
			this->dtpDesde->Name = L"dtpDesde";
			this->dtpDesde->Size = System::Drawing::Size(140, 22);
			this->lblHasta->AutoSize = true;
			this->lblHasta->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblHasta->ForeColor = System::Drawing::Color::FromArgb(90, 115, 140);
			this->lblHasta->Location = System::Drawing::Point(413, 13);
			this->lblHasta->Text = L"Hasta";
			this->dtpHasta->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dtpHasta->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F));
			this->dtpHasta->CalendarForeColor = System::Drawing::Color::FromArgb(30, 50, 70);
			this->dtpHasta->Location = System::Drawing::Point(413, 40);
			this->dtpHasta->Name = L"dtpHasta";
			this->dtpHasta->Size = System::Drawing::Size(140, 22);
			this->lblMedicamentoFiltro->AutoSize = true;
			this->lblMedicamentoFiltro->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblMedicamentoFiltro->ForeColor = System::Drawing::Color::FromArgb(90, 115, 140);
			this->lblMedicamentoFiltro->Location = System::Drawing::Point(568, 13);
			this->lblMedicamentoFiltro->Text = L"Medicamento";
			this->cmbPaciente->SelectedIndexChanged += gcnew System::EventHandler(this, &frmDispensado::cmbPaciente_SelectedIndexChanged);
			this->cmbMedicamento->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbMedicamento->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->cmbMedicamento->BackColor = System::Drawing::Color::White;
			this->cmbMedicamento->ForeColor = System::Drawing::Color::FromArgb(30, 50, 70);
			this->cmbMedicamento->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F));
			this->cmbMedicamento->Location = System::Drawing::Point(568, 40);
			this->cmbMedicamento->Name = L"cmbMedicamento";
			this->cmbMedicamento->Size = System::Drawing::Size(220, 24);
			this->lblEstadoFiltro->AutoSize = true;
			this->lblEstadoFiltro->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblEstadoFiltro->ForeColor = System::Drawing::Color::FromArgb(90, 115, 140);
			this->lblEstadoFiltro->Location = System::Drawing::Point(803, 13);
			this->lblEstadoFiltro->Text = L"Estado";
			this->cmbEstado->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbEstado->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->cmbEstado->BackColor = System::Drawing::Color::White;
			this->cmbEstado->ForeColor = System::Drawing::Color::FromArgb(30, 50, 70);
			this->cmbEstado->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F));
			this->cmbEstado->Location = System::Drawing::Point(803, 40);
			this->cmbEstado->Name = L"cmbEstado";
			this->cmbEstado->Size = System::Drawing::Size(190, 24);
			this->btnAplicarFiltros->BackColor = System::Drawing::Color::FromArgb(234, 243, 222);
			this->btnAplicarFiltros->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(168, 208, 106);
			this->btnAplicarFiltros->FlatAppearance->BorderSize = 1;
			this->btnAplicarFiltros->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(192, 221, 151);
			this->btnAplicarFiltros->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnAplicarFiltros->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F, System::Drawing::FontStyle::Regular));
			this->btnAplicarFiltros->ForeColor = System::Drawing::Color::FromArgb(39, 80, 10);
			this->btnAplicarFiltros->Location = System::Drawing::Point(1011, 34);
			this->btnAplicarFiltros->Name = L"btnAplicarFiltros";
			this->btnAplicarFiltros->Size = System::Drawing::Size(130, 36);
			this->btnAplicarFiltros->Text = L"Aplicar filtros";
			this->btnAplicarFiltros->UseVisualStyleBackColor = false;
			this->btnAplicarFiltros->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnAplicarFiltros->Click += gcnew System::EventHandler(this, &frmDispensado::btnAplicarFiltros_Click);
			this->btnRestablecer->BackColor = System::Drawing::Color::FromArgb(230, 241, 251);
			this->btnRestablecer->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(158, 198, 240);
			this->btnRestablecer->FlatAppearance->BorderSize = 1;
			this->btnRestablecer->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(181, 212, 244);
			this->btnRestablecer->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnRestablecer->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F, System::Drawing::FontStyle::Regular));
			this->btnRestablecer->ForeColor = System::Drawing::Color::FromArgb(12, 68, 124);
			this->btnRestablecer->Location = System::Drawing::Point(1152, 34);
			this->btnRestablecer->Name = L"btnRestablecer";
			this->btnRestablecer->Size = System::Drawing::Size(130, 36);
			this->btnRestablecer->Text = L"Restablecer";
			this->btnRestablecer->UseVisualStyleBackColor = false;
			this->btnRestablecer->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnRestablecer->Click += gcnew System::EventHandler(this, &frmDispensado::btnRestablecer_Click);
			// 
			// tarjetas
			// 
			this->cardEventos->BackColor = System::Drawing::Color::White;
			this->cardEventos->Controls->Add(this->lblCardEventosTitulo);
			this->cardEventos->Controls->Add(this->lblEventos);
			this->cardEventos->Controls->Add(this->lblEventosSub);
			this->cardEventos->Location = System::Drawing::Point(22, 152);
			this->cardEventos->Size = System::Drawing::Size(244, 132);
			this->lblCardEventosTitulo->AutoSize = true;
			this->lblCardEventosTitulo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblCardEventosTitulo->ForeColor = System::Drawing::Color::FromArgb(90, 115, 140);
			this->lblCardEventosTitulo->Location = System::Drawing::Point(16, 16);
			this->lblCardEventosTitulo->Text = L"Eventos registrados";
			this->lblEventos->AutoSize = true;
			this->lblEventos->Font = (gcnew System::Drawing::Font(L"Segoe UI", 20, System::Drawing::FontStyle::Bold));
			this->lblEventos->Location = System::Drawing::Point(16, 45);
			this->lblEventos->Text = L"0";
			this->lblEventosSub->AutoSize = true;
			this->lblEventosSub->ForeColor = System::Drawing::Color::DimGray;
			this->lblEventosSub->Location = System::Drawing::Point(18, 92);
			this->lblEventosSub->Text = L"intentos del dispensador";

			this->cardOk->BackColor = System::Drawing::Color::White;
			this->cardOk->Controls->Add(this->lblCardOkTitulo);
			this->cardOk->Controls->Add(this->lblOk);
			this->cardOk->Controls->Add(this->lblOkSub);
			this->cardOk->Location = System::Drawing::Point(284, 152);
			this->cardOk->Size = System::Drawing::Size(244, 132);
			this->lblCardOkTitulo->AutoSize = true;
			this->lblCardOkTitulo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblCardOkTitulo->ForeColor = System::Drawing::Color::FromArgb(90, 115, 140);
			this->lblCardOkTitulo->Location = System::Drawing::Point(16, 16);
			this->lblCardOkTitulo->Text = L"Dispensado OK";
			this->lblOk->AutoSize = true;
			this->lblOk->Font = (gcnew System::Drawing::Font(L"Segoe UI", 20, System::Drawing::FontStyle::Bold));
			this->lblOk->ForeColor = System::Drawing::Color::FromArgb(20, 125, 95);
			this->lblOk->Location = System::Drawing::Point(16, 45);
			this->lblOk->Text = L"0";
			this->lblOkSub->AutoSize = true;
			this->lblOkSub->ForeColor = System::Drawing::Color::DimGray;
			this->lblOkSub->Location = System::Drawing::Point(18, 92);
			this->lblOkSub->Text = L"estado Tomada";

			this->cardRetrasos->BackColor = System::Drawing::Color::White;
			this->cardRetrasos->Controls->Add(this->lblCardRetrasosTitulo);
			this->cardRetrasos->Controls->Add(this->lblRetrasos);
			this->cardRetrasos->Controls->Add(this->lblRetrasosSub);
			this->cardRetrasos->Location = System::Drawing::Point(546, 152);
			this->cardRetrasos->Size = System::Drawing::Size(244, 132);
			this->lblCardRetrasosTitulo->AutoSize = true;
			this->lblCardRetrasosTitulo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblCardRetrasosTitulo->ForeColor = System::Drawing::Color::FromArgb(90, 115, 140);
			this->lblCardRetrasosTitulo->Location = System::Drawing::Point(16, 16);
			this->lblCardRetrasosTitulo->Text = L"Dispensado con retraso";
			this->lblRetrasos->AutoSize = true;
			this->lblRetrasos->Font = (gcnew System::Drawing::Font(L"Segoe UI", 20, System::Drawing::FontStyle::Bold));
			this->lblRetrasos->ForeColor = System::Drawing::Color::FromArgb(55, 138, 221);
			this->lblRetrasos->Location = System::Drawing::Point(16, 45);
			this->lblRetrasos->Text = L"0";
			this->lblRetrasosSub->AutoSize = true;
			this->lblRetrasosSub->ForeColor = System::Drawing::Color::DimGray;
			this->lblRetrasosSub->Location = System::Drawing::Point(18, 92);
			this->lblRetrasosSub->Text = L"estado Retraso";

			this->cardErrores->BackColor = System::Drawing::Color::White;
			this->cardErrores->Controls->Add(this->lblCardErroresTitulo);
			this->cardErrores->Controls->Add(this->lblErrores);
			this->cardErrores->Controls->Add(this->lblErroresSub);
			this->cardErrores->Location = System::Drawing::Point(808, 152);
			this->cardErrores->Size = System::Drawing::Size(244, 132);
			this->lblCardErroresTitulo->AutoSize = true;
			this->lblCardErroresTitulo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblCardErroresTitulo->ForeColor = System::Drawing::Color::FromArgb(90, 115, 140);
			this->lblCardErroresTitulo->Location = System::Drawing::Point(16, 16);
			this->lblCardErroresTitulo->Text = L"Errores";
			this->lblErrores->AutoSize = true;
			this->lblErrores->Font = (gcnew System::Drawing::Font(L"Segoe UI", 20, System::Drawing::FontStyle::Bold));
			this->lblErrores->ForeColor = System::Drawing::Color::FromArgb(180, 50, 50);
			this->lblErrores->Location = System::Drawing::Point(16, 45);
			this->lblErrores->Text = L"0";
			this->lblErroresSub->AutoSize = true;
			this->lblErroresSub->ForeColor = System::Drawing::Color::DimGray;
			this->lblErroresSub->Location = System::Drawing::Point(18, 92);
			this->lblErroresSub->Text = L"dispensaciones fallidas";

			this->cardExito->BackColor = System::Drawing::Color::White;
			this->cardExito->Controls->Add(this->lblCardExitoTitulo);
			this->cardExito->Controls->Add(this->lblExito);
			this->cardExito->Controls->Add(this->lblExitoSub);
			this->cardExito->Location = System::Drawing::Point(1070, 152);
			this->cardExito->Size = System::Drawing::Size(252, 132);
			this->lblCardExitoTitulo->AutoSize = true;
			this->lblCardExitoTitulo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblCardExitoTitulo->ForeColor = System::Drawing::Color::FromArgb(90, 115, 140);
			this->lblCardExitoTitulo->Location = System::Drawing::Point(16, 16);
			this->lblCardExitoTitulo->Text = L"Tasa de exito";
			this->lblExito->AutoSize = true;
			this->lblExito->Font = (gcnew System::Drawing::Font(L"Segoe UI", 20, System::Drawing::FontStyle::Bold));
			this->lblExito->ForeColor = System::Drawing::Color::FromArgb(20, 125, 95);
			this->lblExito->Location = System::Drawing::Point(16, 45);
			this->lblExito->Text = L"0%";
			this->lblExitoSub->AutoSize = true;
			this->lblExitoSub->ForeColor = System::Drawing::Color::DimGray;
			this->lblExitoSub->Location = System::Drawing::Point(18, 92);
			this->lblExitoSub->Text = L"exitosos / total";
			// 
			// graficos
			// 
			this->grpUnidades->BackColor = System::Drawing::Color::White;
			this->grpUnidades->Controls->Add(this->chartUnidades);
			this->grpUnidades->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular));
			this->grpUnidades->Location = System::Drawing::Point(22, 304);
			this->grpUnidades->Name = L"grpUnidades";
			this->grpUnidades->Size = System::Drawing::Size(760, 360);
			this->grpUnidades->Text = L"Unidades dispensadas por dia y medicamento";
			areaUnidades->Name = L"AreaUnidades";
			this->chartUnidades->ChartAreas->Add(areaUnidades);
			this->chartUnidades->Dock = System::Windows::Forms::DockStyle::Fill;
			leyendaUnidades->Docking = System::Windows::Forms::DataVisualization::Charting::Docking::Top;
			leyendaUnidades->Name = L"LeyendaUnidades";
			this->chartUnidades->Legends->Add(leyendaUnidades);
			serieEjemplo->ChartArea = L"AreaUnidades";
			serieEjemplo->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::StackedColumn;
			serieEjemplo->Legend = L"LeyendaUnidades";
			serieEjemplo->Name = L"Medicamentos";
			this->chartUnidades->Series->Add(serieEjemplo);

			this->grpEstados->BackColor = System::Drawing::Color::White;
			this->grpEstados->Controls->Add(this->chartEstados);
			this->grpEstados->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular));
			this->grpEstados->Location = System::Drawing::Point(802, 304);
			this->grpEstados->Name = L"grpEstados";
			this->grpEstados->Size = System::Drawing::Size(520, 360);
			this->grpEstados->Text = L"Estado de dispensacion";
			areaEstados->Name = L"AreaEstados";
			this->chartEstados->ChartAreas->Add(areaEstados);
			this->chartEstados->Dock = System::Windows::Forms::DockStyle::Fill;
			leyendaEstados->Docking = System::Windows::Forms::DataVisualization::Charting::Docking::Bottom;
			leyendaEstados->Name = L"LeyendaEstados";
			this->chartEstados->Legends->Add(leyendaEstados);
			serieEstados->ChartArea = L"AreaEstados";
			serieEstados->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Doughnut;
			serieEstados->Legend = L"LeyendaEstados";
			serieEstados->Name = L"Estados";
			this->chartEstados->Series->Add(serieEstados);
			// 
			// detalle
			// 
			this->grpDetalle->BackColor = System::Drawing::Color::White;
			this->grpDetalle->Controls->Add(this->dgvDetalle);
			this->grpDetalle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular));
			this->grpDetalle->Location = System::Drawing::Point(22, 686);
			this->grpDetalle->Name = L"grpDetalle";
			this->grpDetalle->Size = System::Drawing::Size(1300, 300);
			this->grpDetalle->Text = L"Registro detallado de dispensaciones";
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
			this->dgvDetalle->Columns->AddRange(gcnew cli::array<System::Windows::Forms::DataGridViewColumn^>(6) {
				this->colIdEvento, this->colFechaReal, this->colPaciente, this->colMedicamento,
					this->colCantidad, this->colEstado
			});
			this->dgvDetalle->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dgvDetalle->Name = L"dgvDetalle";
			this->dgvDetalle->ReadOnly = true;
			this->dgvDetalle->RowHeadersVisible = false;
			this->dgvDetalle->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->colIdEvento->HeaderText = L"# Evento";
			this->colIdEvento->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->colIdEvento->FillWeight = 55;
			this->colIdEvento->Name = L"colIdEvento";
			this->colIdEvento->ReadOnly = true;
			this->colFechaReal->HeaderText = L"Fecha / hora real";
			this->colFechaReal->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->colFechaReal->FillWeight = 110;
			this->colFechaReal->Name = L"colFechaReal";
			this->colFechaReal->ReadOnly = true;
			this->colPaciente->HeaderText = L"Paciente";
			this->colPaciente->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->colPaciente->FillWeight = 130;
			this->colPaciente->Name = L"colPaciente";
			this->colPaciente->ReadOnly = true;
			this->colMedicamento->HeaderText = L"Medicamento";
			this->colMedicamento->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->colMedicamento->FillWeight = 125;
			this->colMedicamento->Name = L"colMedicamento";
			this->colMedicamento->ReadOnly = true;
			this->colCantidad->HeaderText = L"Cantidad";
			this->colCantidad->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->colCantidad->FillWeight = 65;
			this->colCantidad->Name = L"colCantidad";
			this->colCantidad->ReadOnly = true;
			this->colEstado->HeaderText = L"Estado";
			this->colEstado->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->colEstado->FillWeight = 105;
			this->colEstado->Name = L"colEstado";
			this->colEstado->ReadOnly = true;
			// 
			// observaciones
			// 
			this->grpObservaciones->BackColor = System::Drawing::Color::White;
			this->grpObservaciones->Controls->Add(this->txtObservaciones);
			this->grpObservaciones->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular));
			this->grpObservaciones->Location = System::Drawing::Point(22, 1008);
			this->grpObservaciones->Name = L"grpObservaciones";
			this->grpObservaciones->Size = System::Drawing::Size(1300, 180);
			this->grpObservaciones->Text = L"Observaciones automaticas del sistema";
			this->txtObservaciones->BackColor = System::Drawing::Color::FromArgb(247, 249, 251);
			this->txtObservaciones->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txtObservaciones->Dock = System::Windows::Forms::DockStyle::Fill;
			this->txtObservaciones->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F));
			this->txtObservaciones->ForeColor = System::Drawing::Color::FromArgb(40, 60, 80);
			this->txtObservaciones->Name = L"txtObservaciones";
			this->txtObservaciones->ReadOnly = true;
			// 
			// frmDispensado
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(241, 244, 248);
			this->ClientSize = System::Drawing::Size(1360, 760);
			this->ControlBox = false;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Controls->Add(this->panelContenido);
			this->Controls->Add(this->panelCabecera);
			this->Name = L"frmDispensado";
			this->Text = L"";
			this->Load += gcnew System::EventHandler(
				this,
				&frmDispensado::frmDispensado_Load
			);
			this->Resize += gcnew System::EventHandler(
				this,
				&frmDispensado::frmDispensado_Resize
			);
			this->panelCabecera->ResumeLayout(false);
			this->panelCabecera->PerformLayout();
			this->panelContenido->ResumeLayout(false);
			this->panelFiltros->ResumeLayout(false);
			this->panelFiltros->PerformLayout();
			this->cardEventos->ResumeLayout(false);
			this->cardEventos->PerformLayout();
			this->cardOk->ResumeLayout(false);
			this->cardOk->PerformLayout();
			this->cardRetrasos->ResumeLayout(false);
			this->cardRetrasos->PerformLayout();
			this->cardErrores->ResumeLayout(false);
			this->cardErrores->PerformLayout();
			this->cardExito->ResumeLayout(false);
			this->cardExito->PerformLayout();
			this->grpUnidades->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartUnidades))->EndInit();
			this->grpEstados->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartEstados))->EndInit();
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

		bool EsEventoDispensador(LogEvento^ evento) {
			return evento != nullptr &&
				Contiene(evento->getTipoEvento(), "Toma") &&
				Contiene(evento->getOrigen(), "Dispensador");
		}

		bool EsTomada(LogEvento^ evento) {
			return evento != nullptr && Contiene(evento->getEstado(), "Tomada");
		}

		bool EsRetraso(LogEvento^ evento) {
			return evento != nullptr && Contiene(evento->getEstado(), "Retraso");
		}

		bool EsExitosa(LogEvento^ evento) {
			return EsTomada(evento) || EsRetraso(evento);
		}

		int ObtenerIdSeleccionado(ComboBox^ combo) {
			if (combo->SelectedIndex <= 0 || combo->SelectedItem == nullptr)
				return 0;
			String^ valor = combo->SelectedItem->ToString();
			int separador = valor->IndexOf(" - ");
			int id = 0;
			return separador > 0 && Int32::TryParse(valor->Substring(0, separador), id) ? id : 0;
		}

		String^ ClasificarEstado(LogEvento^ evento) {
			if (EsTomada(evento))
				return "Dispensado OK";
			if (EsRetraso(evento))
				return "Dispensado con retraso";
			return "Error";
		}

		List<LogEvento^>^ ObtenerEventosFiltrados() {
			List<LogEvento^>^ resultado = gcnew List<LogEvento^>();
			int idPaciente = ObtenerIdSeleccionado(this->cmbPaciente);
			int idMedicamento = ObtenerIdSeleccionado(this->cmbMedicamento);
			String^ estado = this->cmbEstado->SelectedItem == nullptr ? "Todos los estados" : this->cmbEstado->SelectedItem->ToString();
			DateTime desde = this->dtpDesde->Value.Date;
			DateTime hasta = this->dtpHasta->Value.Date;

			for each(LogEvento ^ evento in this->controller->ObtenerTodos()) {
				if (!EsEventoDispensador(evento) || evento->getFechaHoraReal() == DateTime::MinValue)
					continue;
				if (evento->getFechaHoraReal().Date < desde || evento->getFechaHoraReal().Date > hasta)
					continue;
				if (idPaciente > 0 && evento->getIdPaciente() != idPaciente)
					continue;
				if (idMedicamento > 0 && evento->getIdMedicamento() != idMedicamento)
					continue;
				if (estado == "Dispensado OK" && !EsTomada(evento))
					continue;
				if (estado == "Dispensado con retraso" && !EsRetraso(evento))
					continue;
				if (estado == "Error" && EsExitosa(evento))
					continue;
				resultado->Add(evento);
			}
			return resultado;
		}

		void CargarFiltros() {
			List<LogEvento^>^ eventos = this->controller->ObtenerTodos();
			SortedDictionary<int, String^>^ pacientes = gcnew SortedDictionary<int, String^>();
			SortedDictionary<int, String^>^ medicamentos = gcnew SortedDictionary<int, String^>();
			DateTime minimo = DateTime::MaxValue;
			DateTime maximo = DateTime::MinValue;

			for each(LogEvento ^ evento in eventos) {
				if (!EsEventoDispensador(evento))
					continue;
				if (evento->getIdPaciente() > 0 && !pacientes->ContainsKey(evento->getIdPaciente()))
					pacientes->Add(evento->getIdPaciente(), evento->getNombrePaciente());
				if (evento->getIdMedicamento() > 0 && !medicamentos->ContainsKey(evento->getIdMedicamento()))
					medicamentos->Add(evento->getIdMedicamento(), evento->getMedicamento());
				if (evento->getFechaHoraReal() != DateTime::MinValue) {
					if (evento->getFechaHoraReal() < minimo) minimo = evento->getFechaHoraReal();
					if (evento->getFechaHoraReal() > maximo) maximo = evento->getFechaHoraReal();
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

			this->cmbEstado->Items->Clear();
			this->cmbEstado->Items->Add("Todos los estados");
			this->cmbEstado->Items->Add("Dispensado OK");
			this->cmbEstado->Items->Add("Dispensado con retraso");
			this->cmbEstado->Items->Add("Error");
			this->cmbEstado->SelectedIndex = 0;

			this->dtpDesde->Value = minimo == DateTime::MaxValue ? DateTime::Today.AddDays(-30) : minimo.Date;
			this->dtpHasta->Value = maximo == DateTime::MinValue ? DateTime::Today : maximo.Date;
		}

		void ConfigurarGraficos() {
			this->chartEstados->Series["Estados"]->SetCustomProperty("DoughnutRadius", "65");
			this->chartEstados->Series["Estados"]->SetCustomProperty("PieLabelStyle", "Disabled");
			ChartArea^ area = this->chartUnidades->ChartAreas["AreaUnidades"];
			area->AxisX->Interval = 1;
			area->AxisX->LabelStyle->Angle = -20;
			area->AxisY->Minimum = 0;
			area->BackColor = Color::White;
			this->chartUnidades->BackColor = Color::White;
			this->chartEstados->BackColor = Color::White;
			this->chartEstados->ChartAreas["AreaEstados"]->BackColor = Color::White;
		}

		void AjustarControlesReporte() {
			this->chartUnidades->Dock = DockStyle::None;
			this->chartEstados->Dock = DockStyle::None;
			this->dgvDetalle->Dock = DockStyle::None;

			this->chartUnidades->Bounds = this->grpUnidades->DisplayRectangle;
			this->chartEstados->Bounds = this->grpEstados->DisplayRectangle;
			this->dgvDetalle->Bounds = this->grpDetalle->DisplayRectangle;

			this->chartUnidades->Anchor = AnchorStyles::Top | AnchorStyles::Bottom |
				AnchorStyles::Left | AnchorStyles::Right;
			this->chartEstados->Anchor = AnchorStyles::Top | AnchorStyles::Bottom |
				AnchorStyles::Left | AnchorStyles::Right;
			this->dgvDetalle->Anchor = AnchorStyles::Top | AnchorStyles::Bottom |
				AnchorStyles::Left | AnchorStyles::Right;

			ChartArea^ areaUnidades = this->chartUnidades->ChartAreas["AreaUnidades"];
			areaUnidades->Position->Auto = false;
			areaUnidades->Position->X = 7;
			areaUnidades->Position->Y = 12;
			areaUnidades->Position->Width = 90;
			areaUnidades->Position->Height = 78;

			ChartArea^ areaEstados = this->chartEstados->ChartAreas["AreaEstados"];
			areaEstados->Position->Auto = false;
			areaEstados->Position->X = 4;
			areaEstados->Position->Y = 5;
			areaEstados->Position->Width = 58;
			areaEstados->Position->Height = 82;

			for each(DataGridViewColumn ^ columna in this->dgvDetalle->Columns)
				columna->AutoSizeMode = DataGridViewAutoSizeColumnMode::Fill;

			this->grpUnidades->PerformLayout();
			this->grpEstados->PerformLayout();
			this->grpDetalle->PerformLayout();
			this->chartUnidades->Invalidate();
			this->chartEstados->Invalidate();
			this->dgvDetalle->Invalidate();
		}

		void ActualizarReporte() {
			List<LogEvento^>^ eventos = ObtenerEventosFiltrados();
			int tomadas = 0;
			int retrasos = 0;
			int errores = 0;
			int unidades = 0;
			Dictionary<String^, int>^ unidadesMedicamento = gcnew Dictionary<String^, int>();
			SortedDictionary<DateTime, Dictionary<String^, int>^>^ unidadesDia =
				gcnew SortedDictionary<DateTime, Dictionary<String^, int>^>();

			this->dgvDetalle->Rows->Clear();
			for each(LogEvento ^ evento in eventos) {
				if (EsTomada(evento)) tomadas++;
				else if (EsRetraso(evento)) retrasos++;
				else errores++;

				int cantidad = Math::Max(0, evento->getCantidad());
				if (EsExitosa(evento))
					unidades += cantidad;
				String^ medicamento = String::IsNullOrWhiteSpace(evento->getMedicamento()) ? "Sin medicamento" : evento->getMedicamento();
				if (EsExitosa(evento)) {
					if (!unidadesMedicamento->ContainsKey(medicamento))
						unidadesMedicamento->Add(medicamento, 0);
					unidadesMedicamento[medicamento] += cantidad;
					DateTime dia = evento->getFechaHoraReal().Date;
					if (!unidadesDia->ContainsKey(dia))
						unidadesDia->Add(dia, gcnew Dictionary<String^, int>());
					if (!unidadesDia[dia]->ContainsKey(medicamento))
						unidadesDia[dia]->Add(medicamento, 0);
					Dictionary<String^, int>^ innerDict = unidadesDia[dia]; innerDict[medicamento] += cantidad;
				}

				int fila = this->dgvDetalle->Rows->Add(
					evento->getId(),
					evento->getFechaHoraReal().ToString("dd/MM/yyyy HH:mm"),
					String::IsNullOrWhiteSpace(evento->getNombrePaciente()) ? "Sin paciente" : evento->getNombrePaciente(),
					medicamento,
					evento->getCantidad(),
					ClasificarEstado(evento));
				this->dgvDetalle->Rows[fila]->Cells[5]->Style->ForeColor =
					EsTomada(evento) ? Color::FromArgb(20, 125, 95) :
					EsRetraso(evento) ? Color::FromArgb(55, 138, 221) : Color::FromArgb(180, 50, 50);
			}
			this->dgvDetalle->ClearSelection();

			int exitosos = tomadas + retrasos;
			double tasa = eventos->Count == 0 ? 0.0 : exitosos * 100.0 / eventos->Count;
			this->lblEventos->Text = eventos->Count.ToString();
			this->lblOk->Text = tomadas.ToString();
			this->lblRetrasos->Text = retrasos.ToString();
			this->lblErrores->Text = errores.ToString();
			this->lblExito->Text = String::Format("{0:F0}%", tasa);
			this->lblExito->ForeColor = tasa >= 80.0 ? Color::FromArgb(20, 125, 95) : Color::FromArgb(180, 50, 50);

			Series^ estados = this->chartEstados->Series["Estados"];
			estados->Points->Clear();
			int puntoOk = estados->Points->AddXY("Dispensado OK", tomadas);
			int puntoRetraso = estados->Points->AddXY("Con retraso", retrasos);
			int puntoError = estados->Points->AddXY("Error", errores);
			estados->Points[puntoOk]->Color = Color::FromArgb(29, 158, 117);
			estados->Points[puntoRetraso]->Color = Color::FromArgb(55, 138, 221);
			estados->Points[puntoError]->Color = Color::FromArgb(232, 73, 73);
			this->chartEstados->Titles->Clear();
			this->chartEstados->Annotations->Clear();
			TextAnnotation^ anotacionExito = gcnew TextAnnotation();
			anotacionExito->Text = String::Format("{0:F0}%\nexito", tasa);
			anotacionExito->Font = gcnew Drawing::Font("Segoe UI", 13, FontStyle::Bold);
			anotacionExito->ForeColor = Color::FromArgb(60, 60, 60);
			anotacionExito->Alignment = System::Drawing::ContentAlignment::MiddleLeft;
			anotacionExito->ClipToChartArea = "AreaEstados";
			anotacionExito->AllowMoving = false;
			anotacionExito->AllowSelecting = false;
			anotacionExito->X = 64;
			anotacionExito->Y = 36;
			anotacionExito->Width = 32;
			anotacionExito->Height = 20;
			this->chartEstados->Annotations->Add(anotacionExito);

			this->chartUnidades->Series->Clear();
			array<Color>^ colores = gcnew array<Color>{
				Color::FromArgb(29, 158, 117), Color::FromArgb(55, 138, 221),
					Color::FromArgb(239, 159, 39), Color::FromArgb(150, 92, 180),
					Color::FromArgb(214, 78, 126), Color::FromArgb(30, 112, 145)
			};
			int indiceColor = 0;
			for each(KeyValuePair<String^, int> itemMedicamento in unidadesMedicamento) {
				Series^ serie = gcnew Series(itemMedicamento.Key);
				serie->ChartArea = "AreaUnidades";
				serie->Legend = "LeyendaUnidades";
				serie->ChartType = SeriesChartType::StackedColumn;
				serie->Color = colores[indiceColor % colores->Length];
				for each(KeyValuePair<DateTime, Dictionary<String^, int>^> itemDia in unidadesDia) {
					int valor = itemDia.Value->ContainsKey(itemMedicamento.Key) ? itemDia.Value[itemMedicamento.Key] : 0;
					serie->Points->AddXY(itemDia.Key.ToString("dd/MM"), valor);
				}
				this->chartUnidades->Series->Add(serie);
				indiceColor++;
			}

			String^ mayorMedicamento = "";
			int mayorCantidad = 0;
			for each(KeyValuePair<String^, int> item in unidadesMedicamento) {
				if (item.Value > mayorCantidad) {
					mayorCantidad = item.Value;
					mayorMedicamento = item.Key;
				}
			}

			StringBuilder^ observacion = gcnew StringBuilder();
			if (eventos->Count == 0) {
				observacion->Append("No existen eventos de dispensacion para los filtros seleccionados.");
			}
			else {
				observacion->AppendFormat(
					"Durante el periodo analizado se registraron {0} eventos del dispensador, de los cuales {1} resultaron exitosos ({2:F0}% de tasa de exito). ",
					eventos->Count, exitosos, tasa);
				observacion->AppendFormat("Se dispensaron {0} unidades en total. ", unidades);
				if (!String::IsNullOrWhiteSpace(mayorMedicamento))
					observacion->AppendFormat("El medicamento con mayor volumen dispensado fue {0}, con {1} unidades. ", mayorMedicamento, mayorCantidad);
				if (errores > 0)
					observacion->AppendFormat("Se detectaron {0} errores de dispensacion que requieren revision. ", errores);
				if (retrasos > 0)
					observacion->AppendFormat("{0} dispensaciones fueron completadas con retraso.", retrasos);
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
				this->cardEventos->Height +
				espacioVertical;

			int yDetalle =
				yGraficos +
				this->grpUnidades->Height +
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
			int anchoPaciente = 210;
			int anchoFecha = 140;
			int anchoMedicamento = 205;
			int anchoEstado = 170;
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

			this->lblEstadoFiltro->Location =
				System::Drawing::Point(x, 13);
			this->cmbEstado->Location =
				System::Drawing::Point(x, 40);
			this->cmbEstado->Width = anchoEstado;

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
				System::Drawing::Point(xAplicar, 34);
			this->btnAplicarFiltros->Width = anchoBoton;

			this->btnRestablecer->Location =
				System::Drawing::Point(xRestablecer, 34);
			this->btnRestablecer->Width = anchoBoton;

			if (x + anchoEstado + separacionFiltro > xAplicar) {
				this->cmbEstado->Width =
					Math::Max(100, xAplicar - separacionFiltro - x);
			}

			// ?? Cinco tarjetas ?????????????????????????????????????????????????
			array<System::Windows::Forms::Panel^>^ tarjetas = {
				this->cardEventos,
				this->cardOk,
				this->cardRetrasos,
				this->cardErrores,
				this->cardExito
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
			this->grpUnidades->Location =
				System::Drawing::Point(margen, yGraficos);
			this->grpUnidades->Width = anchoMitad;

			this->grpEstados->Location =
				System::Drawing::Point(
					margen + anchoMitad + separacion,
					yGraficos
				);
			this->grpEstados->Width = anchoMitad;

			// ?? Tabla y observaciones ??????????????????????????????????????????
			this->grpDetalle->Location =
				System::Drawing::Point(margen, yDetalle);
			this->grpDetalle->Width = anchoDisponible;

			this->grpObservaciones->Location =
				System::Drawing::Point(margen, yObservaciones);
			this->grpObservaciones->Width = anchoDisponible;

			AjustarControlesReporte();
		}

		System::Void frmDispensado_Resize(
			System::Object^ sender,
			System::EventArgs^ e
		) {
			AjustarDistribucion();
		}

		System::Void frmDispensado_Load(System::Object^ sender, System::EventArgs^ e) {
			this->controller = gcnew GeneradorReportesController();
			ConfigurarGraficos();
			CargarFiltros();
			ActualizarReporte();
			AjustarDistribucion();
			this->BeginInvoke(
				gcnew MethodInvoker(
					this,
					&frmDispensado::AjustarDistribucion
				)
			);
		}

		System::Void btnAplicarFiltros_Click(System::Object^ sender, System::EventArgs^ e) {
			ActualizarReporte();
		}

		System::Void btnRestablecer_Click(System::Object^ sender, System::EventArgs^ e) {
			CargarFiltros();
			ActualizarReporte();
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