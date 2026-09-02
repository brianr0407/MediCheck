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

	public ref class frmUsoSistema : public System::Windows::Forms::Form {
	public:
		frmUsoSistema() { InitializeComponent(); }

	protected:
		~frmUsoSistema() { if (components) delete components; }

	private:
		System::ComponentModel::Container^ components;
		GeneradorReportesController^ controller;
		System::Windows::Forms::Panel^ panelCabecera;
		System::Windows::Forms::Label^ lblTitulo;
		System::Windows::Forms::Label^ lblSubtitulo;
		System::Windows::Forms::Label^ lblGenerado;
		System::Windows::Forms::Panel^ panelContenido;
		System::Windows::Forms::Panel^ panelFiltros;
		System::Windows::Forms::ComboBox^ cmbPaciente;
		System::Windows::Forms::ComboBox^ cmbTipo;
		System::Windows::Forms::ComboBox^ cmbEstado;
		System::Windows::Forms::DateTimePicker^ dtpDesde;
		System::Windows::Forms::DateTimePicker^ dtpHasta;
		System::Windows::Forms::Label^ lblPacienteFiltro;
		System::Windows::Forms::Label^ lblTipoFiltro;
		System::Windows::Forms::Label^ lblEstadoFiltro;
		System::Windows::Forms::Label^ lblDesde;
		System::Windows::Forms::Label^ lblHasta;
		System::Windows::Forms::Button^ btnAplicar;
		System::Windows::Forms::Button^ btnRestablecer;

		System::Windows::Forms::Panel^ cardAutenticaciones;
		System::Windows::Forms::Label^ lblCardAutenticaciones;
		System::Windows::Forms::Label^ lblAutenticaciones;
		System::Windows::Forms::Label^ lblAutenticacionesSub;
		System::Windows::Forms::Panel^ cardExito;
		System::Windows::Forms::Label^ lblCardExito;
		System::Windows::Forms::Label^ lblExito;
		System::Windows::Forms::Label^ lblExitoSub;
		System::Windows::Forms::Panel^ cardFallos;
		System::Windows::Forms::Label^ lblCardFallos;
		System::Windows::Forms::Label^ lblFallos;
		System::Windows::Forms::Label^ lblFallosSub;
		System::Windows::Forms::Panel^ cardAgua;
		System::Windows::Forms::Label^ lblCardAgua;
		System::Windows::Forms::Label^ lblAgua;
		System::Windows::Forms::Label^ lblAguaSub;
		System::Windows::Forms::Panel^ cardDispensaciones;
		System::Windows::Forms::Label^ lblCardDispensaciones;
		System::Windows::Forms::Label^ lblDispensaciones;
		System::Windows::Forms::Label^ lblDispensacionesSub;
		System::Windows::Forms::Panel^ cardErrores;
		System::Windows::Forms::Label^ lblCardErrores;
		System::Windows::Forms::Label^ lblErrores;
		System::Windows::Forms::Label^ lblErroresSub;

		System::Windows::Forms::GroupBox^ grpAutenticaciones;
		System::Windows::Forms::DataVisualization::Charting::Chart^ chartAutenticaciones;
		System::Windows::Forms::GroupBox^ grpAgua;
		System::Windows::Forms::DataVisualization::Charting::Chart^ chartAgua;
		System::Windows::Forms::GroupBox^ grpDistribucion;
		System::Windows::Forms::DataVisualization::Charting::Chart^ chartDistribucion;
		System::Windows::Forms::GroupBox^ grpResumen;
		System::Windows::Forms::RichTextBox^ txtResumen;
		System::Windows::Forms::GroupBox^ grpDetalle;
		System::Windows::Forms::DataGridView^ dgvDetalle;
		System::Windows::Forms::DataGridViewTextBoxColumn^ colEvento;
		System::Windows::Forms::DataGridViewTextBoxColumn^ colFecha;
		System::Windows::Forms::DataGridViewTextBoxColumn^ colPaciente;
		System::Windows::Forms::DataGridViewTextBoxColumn^ colTipo;
		System::Windows::Forms::DataGridViewTextBoxColumn^ colOrigen;
		System::Windows::Forms::DataGridViewTextBoxColumn^ colCantidad;
		System::Windows::Forms::DataGridViewTextBoxColumn^ colEstado;
		System::Windows::Forms::DataGridViewTextBoxColumn^ colDetalle;
		System::Windows::Forms::GroupBox^ grpObservaciones;
		System::Windows::Forms::RichTextBox^ txtObservaciones;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void) {
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ areaAutenticaciones = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ leyendaAutenticaciones = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ serieExitosas = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ serieFallidas = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ areaAgua = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Series^ serieAgua = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ areaDistribucion = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ leyendaDistribucion = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ serieDistribucion = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->panelCabecera = (gcnew System::Windows::Forms::Panel());
			this->lblTitulo = (gcnew System::Windows::Forms::Label());
			this->lblSubtitulo = (gcnew System::Windows::Forms::Label());
			this->lblGenerado = (gcnew System::Windows::Forms::Label());
			this->panelContenido = (gcnew System::Windows::Forms::Panel());
			this->panelFiltros = (gcnew System::Windows::Forms::Panel());
			this->cmbPaciente = (gcnew System::Windows::Forms::ComboBox());
			this->cmbTipo = (gcnew System::Windows::Forms::ComboBox());
			this->cmbEstado = (gcnew System::Windows::Forms::ComboBox());
			this->dtpDesde = (gcnew System::Windows::Forms::DateTimePicker());
			this->dtpHasta = (gcnew System::Windows::Forms::DateTimePicker());
			this->lblPacienteFiltro = (gcnew System::Windows::Forms::Label());
			this->lblTipoFiltro = (gcnew System::Windows::Forms::Label());
			this->lblEstadoFiltro = (gcnew System::Windows::Forms::Label());
			this->lblDesde = (gcnew System::Windows::Forms::Label());
			this->lblHasta = (gcnew System::Windows::Forms::Label());
			this->btnAplicar = (gcnew System::Windows::Forms::Button());
			this->btnRestablecer = (gcnew System::Windows::Forms::Button());
			this->cardAutenticaciones = (gcnew System::Windows::Forms::Panel());
			this->lblCardAutenticaciones = (gcnew System::Windows::Forms::Label());
			this->lblAutenticaciones = (gcnew System::Windows::Forms::Label());
			this->lblAutenticacionesSub = (gcnew System::Windows::Forms::Label());
			this->cardExito = (gcnew System::Windows::Forms::Panel());
			this->lblCardExito = (gcnew System::Windows::Forms::Label());
			this->lblExito = (gcnew System::Windows::Forms::Label());
			this->lblExitoSub = (gcnew System::Windows::Forms::Label());
			this->cardFallos = (gcnew System::Windows::Forms::Panel());
			this->lblCardFallos = (gcnew System::Windows::Forms::Label());
			this->lblFallos = (gcnew System::Windows::Forms::Label());
			this->lblFallosSub = (gcnew System::Windows::Forms::Label());
			this->cardAgua = (gcnew System::Windows::Forms::Panel());
			this->lblCardAgua = (gcnew System::Windows::Forms::Label());
			this->lblAgua = (gcnew System::Windows::Forms::Label());
			this->lblAguaSub = (gcnew System::Windows::Forms::Label());
			this->cardDispensaciones = (gcnew System::Windows::Forms::Panel());
			this->lblCardDispensaciones = (gcnew System::Windows::Forms::Label());
			this->lblDispensaciones = (gcnew System::Windows::Forms::Label());
			this->lblDispensacionesSub = (gcnew System::Windows::Forms::Label());
			this->cardErrores = (gcnew System::Windows::Forms::Panel());
			this->lblCardErrores = (gcnew System::Windows::Forms::Label());
			this->lblErrores = (gcnew System::Windows::Forms::Label());
			this->lblErroresSub = (gcnew System::Windows::Forms::Label());
			this->grpAutenticaciones = (gcnew System::Windows::Forms::GroupBox());
			this->chartAutenticaciones = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->grpAgua = (gcnew System::Windows::Forms::GroupBox());
			this->chartAgua = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->grpDistribucion = (gcnew System::Windows::Forms::GroupBox());
			this->chartDistribucion = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->grpResumen = (gcnew System::Windows::Forms::GroupBox());
			this->txtResumen = (gcnew System::Windows::Forms::RichTextBox());
			this->grpDetalle = (gcnew System::Windows::Forms::GroupBox());
			this->dgvDetalle = (gcnew System::Windows::Forms::DataGridView());
			this->colEvento = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colFecha = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colPaciente = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colTipo = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colOrigen = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colCantidad = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colEstado = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colDetalle = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->grpObservaciones = (gcnew System::Windows::Forms::GroupBox());
			this->txtObservaciones = (gcnew System::Windows::Forms::RichTextBox());
			this->panelCabecera->SuspendLayout();
			this->panelContenido->SuspendLayout();
			this->panelFiltros->SuspendLayout();
			this->cardAutenticaciones->SuspendLayout();
			this->cardExito->SuspendLayout();
			this->cardFallos->SuspendLayout();
			this->cardAgua->SuspendLayout();
			this->cardDispensaciones->SuspendLayout();
			this->cardErrores->SuspendLayout();
			this->grpAutenticaciones->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartAutenticaciones))->BeginInit();
			this->grpAgua->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartAgua))->BeginInit();
			this->grpDistribucion->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartDistribucion))->BeginInit();
			this->grpResumen->SuspendLayout();
			this->grpDetalle->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvDetalle))->BeginInit();
			this->grpObservaciones->SuspendLayout();
			this->SuspendLayout();

			this->panelCabecera->BackColor = System::Drawing::Color::FromArgb(15, 41, 66);
			this->panelCabecera->Controls->Add(this->lblTitulo);
			this->panelCabecera->Controls->Add(this->lblSubtitulo);
			this->panelCabecera->Controls->Add(this->lblGenerado);
			this->panelCabecera->Dock = System::Windows::Forms::DockStyle::Top;
			this->panelCabecera->Size = System::Drawing::Size(1360, 84);
			this->lblTitulo->AutoSize = true;
			this->lblTitulo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15, System::Drawing::FontStyle::Regular));
			this->lblTitulo->ForeColor = System::Drawing::Color::FromArgb(220, 233, 245);
			this->lblTitulo->Location = System::Drawing::Point(26, 14);
			this->lblTitulo->Text = L"Reporte de Uso del Sistema";
			this->lblSubtitulo->AutoSize = true;
			this->lblSubtitulo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->lblSubtitulo->ForeColor = System::Drawing::Color::FromArgb(200, 218, 235);
			this->lblSubtitulo->Location = System::Drawing::Point(27, 50);
			this->lblSubtitulo->Text = L"Actividad operativa general del dispensador";
			this->lblGenerado->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right)); this->lblGenerado->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->lblGenerado->ForeColor = System::Drawing::Color::FromArgb(220, 233, 245);
			this->lblGenerado->Location = System::Drawing::Point(1060, 28);
			this->lblGenerado->Size = System::Drawing::Size(274, 22);
			this->lblGenerado->Text = L"Generado:";
			this->lblGenerado->TextAlign = System::Drawing::ContentAlignment::MiddleRight;

			this->panelContenido->AutoScroll = true;
			this->panelContenido->BackColor = System::Drawing::Color::FromArgb(241, 244, 248);
			this->panelContenido->Controls->Add(this->panelFiltros);
			this->panelContenido->Controls->Add(this->cardAutenticaciones);
			this->panelContenido->Controls->Add(this->cardExito);
			this->panelContenido->Controls->Add(this->cardFallos);
			this->panelContenido->Controls->Add(this->cardAgua);
			this->panelContenido->Controls->Add(this->cardDispensaciones);
			this->panelContenido->Controls->Add(this->cardErrores);
			this->panelContenido->Controls->Add(this->grpAutenticaciones);
			this->panelContenido->Controls->Add(this->grpAgua);
			this->panelContenido->Controls->Add(this->grpDistribucion);
			this->panelContenido->Controls->Add(this->grpResumen);
			this->panelContenido->Controls->Add(this->grpDetalle);
			this->panelContenido->Controls->Add(this->grpObservaciones);
			this->panelContenido->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panelContenido->Location = System::Drawing::Point(0, 84);
			this->panelContenido->Size = System::Drawing::Size(1360, 676);

			this->panelFiltros->BackColor = System::Drawing::Color::White;
			this->panelFiltros->Controls->Add(this->lblPacienteFiltro);
			this->panelFiltros->Controls->Add(this->cmbPaciente);
			this->panelFiltros->Controls->Add(this->lblDesde);
			this->panelFiltros->Controls->Add(this->dtpDesde);
			this->panelFiltros->Controls->Add(this->lblHasta);
			this->panelFiltros->Controls->Add(this->dtpHasta);
			this->panelFiltros->Controls->Add(this->lblTipoFiltro);
			this->panelFiltros->Controls->Add(this->cmbTipo);
			this->panelFiltros->Controls->Add(this->lblEstadoFiltro);
			this->panelFiltros->Controls->Add(this->cmbEstado);
			this->panelFiltros->Controls->Add(this->btnAplicar);
			this->panelFiltros->Controls->Add(this->btnRestablecer);
			this->panelFiltros->Location = System::Drawing::Point(22, 18);
			this->panelFiltros->Size = System::Drawing::Size(1300, 104);
			this->lblPacienteFiltro->AutoSize = true; this->lblPacienteFiltro->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold)); this->lblPacienteFiltro->ForeColor = System::Drawing::Color::FromArgb(90, 115, 140); this->lblPacienteFiltro->Location = System::Drawing::Point(16, 13); this->lblPacienteFiltro->Text = L"Paciente";
			this->cmbPaciente->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList; this->cmbPaciente->FlatStyle = System::Windows::Forms::FlatStyle::Flat; this->cmbPaciente->BackColor = System::Drawing::Color::White; this->cmbPaciente->ForeColor = System::Drawing::Color::FromArgb(30, 50, 70); this->cmbPaciente->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F)); this->cmbPaciente->Location = System::Drawing::Point(16, 40); this->cmbPaciente->Size = System::Drawing::Size(190, 24);
			this->lblDesde->AutoSize = true; this->lblDesde->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold)); this->lblDesde->ForeColor = System::Drawing::Color::FromArgb(90, 115, 140); this->lblDesde->Location = System::Drawing::Point(220, 13); this->lblDesde->Text = L"Desde";
			this->dtpDesde->Format = System::Windows::Forms::DateTimePickerFormat::Short; this->dtpDesde->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F)); this->dtpDesde->CalendarForeColor = System::Drawing::Color::FromArgb(30, 50, 70); this->dtpDesde->Location = System::Drawing::Point(220, 40); this->dtpDesde->Size = System::Drawing::Size(135, 22);
			this->lblHasta->AutoSize = true; this->lblHasta->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold)); this->lblHasta->ForeColor = System::Drawing::Color::FromArgb(90, 115, 140); this->lblHasta->Location = System::Drawing::Point(369, 13); this->lblHasta->Text = L"Hasta";
			this->dtpHasta->Format = System::Windows::Forms::DateTimePickerFormat::Short; this->dtpHasta->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F)); this->dtpHasta->CalendarForeColor = System::Drawing::Color::FromArgb(30, 50, 70); this->dtpHasta->Location = System::Drawing::Point(369, 40); this->dtpHasta->Size = System::Drawing::Size(135, 22);
			this->lblTipoFiltro->AutoSize = true; this->lblTipoFiltro->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold)); this->lblTipoFiltro->ForeColor = System::Drawing::Color::FromArgb(90, 115, 140); this->lblTipoFiltro->Location = System::Drawing::Point(518, 13); this->lblTipoFiltro->Text = L"Tipo de evento";
			this->cmbTipo->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList; this->cmbTipo->FlatStyle = System::Windows::Forms::FlatStyle::Flat; this->cmbTipo->BackColor = System::Drawing::Color::White; this->cmbTipo->ForeColor = System::Drawing::Color::FromArgb(30, 50, 70); this->cmbTipo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F)); this->cmbTipo->Location = System::Drawing::Point(518, 40); this->cmbTipo->Size = System::Drawing::Size(180, 24);
			this->lblEstadoFiltro->AutoSize = true; this->lblEstadoFiltro->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold)); this->lblEstadoFiltro->ForeColor = System::Drawing::Color::FromArgb(90, 115, 140); this->lblEstadoFiltro->Location = System::Drawing::Point(712, 13); this->lblEstadoFiltro->Text = L"Estado";
			this->cmbEstado->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList; this->cmbEstado->FlatStyle = System::Windows::Forms::FlatStyle::Flat; this->cmbEstado->BackColor = System::Drawing::Color::White; this->cmbEstado->ForeColor = System::Drawing::Color::FromArgb(30, 50, 70); this->cmbEstado->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F)); this->cmbEstado->Location = System::Drawing::Point(712, 40); this->cmbEstado->Size = System::Drawing::Size(170, 24);
			this->btnAplicar->BackColor = System::Drawing::Color::FromArgb(234, 243, 222); this->btnAplicar->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(168, 208, 106); this->btnAplicar->FlatAppearance->BorderSize = 1; this->btnAplicar->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(192, 221, 151); this->btnAplicar->FlatStyle = System::Windows::Forms::FlatStyle::Flat; this->btnAplicar->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F, System::Drawing::FontStyle::Regular)); this->btnAplicar->ForeColor = System::Drawing::Color::FromArgb(39, 80, 10); this->btnAplicar->Location = System::Drawing::Point(900, 34); this->btnAplicar->Size = System::Drawing::Size(175, 36); this->btnAplicar->Text = L"Aplicar filtros"; this->btnAplicar->UseVisualStyleBackColor = false; this->btnAplicar->Cursor = System::Windows::Forms::Cursors::Hand; this->btnAplicar->Click += gcnew System::EventHandler(this, &frmUsoSistema::btnAplicar_Click);
			this->btnRestablecer->BackColor = System::Drawing::Color::FromArgb(230, 241, 251); this->btnRestablecer->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(158, 198, 240); this->btnRestablecer->FlatAppearance->BorderSize = 1; this->btnRestablecer->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(181, 212, 244); this->btnRestablecer->FlatStyle = System::Windows::Forms::FlatStyle::Flat; this->btnRestablecer->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F, System::Drawing::FontStyle::Regular)); this->btnRestablecer->ForeColor = System::Drawing::Color::FromArgb(12, 68, 124); this->btnRestablecer->Location = System::Drawing::Point(1090, 34); this->btnRestablecer->Size = System::Drawing::Size(175, 36); this->btnRestablecer->Text = L"Restablecer"; this->btnRestablecer->UseVisualStyleBackColor = false; this->btnRestablecer->Cursor = System::Windows::Forms::Cursors::Hand; this->btnRestablecer->Click += gcnew System::EventHandler(this, &frmUsoSistema::btnRestablecer_Click);

			this->cardAutenticaciones->BackColor = System::Drawing::Color::White; this->cardAutenticaciones->Controls->Add(this->lblCardAutenticaciones); this->cardAutenticaciones->Controls->Add(this->lblAutenticaciones); this->cardAutenticaciones->Controls->Add(this->lblAutenticacionesSub); this->cardAutenticaciones->Location = System::Drawing::Point(22, 142); this->cardAutenticaciones->Size = System::Drawing::Size(200, 132);
			this->lblCardAutenticaciones->AutoSize = true; this->lblCardAutenticaciones->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold)); this->lblCardAutenticaciones->ForeColor = System::Drawing::Color::FromArgb(90, 115, 140); this->lblCardAutenticaciones->Location = System::Drawing::Point(16, 16); this->lblCardAutenticaciones->Text = L"Autenticaciones";
			this->lblAutenticaciones->AutoSize = true; this->lblAutenticaciones->Font = (gcnew System::Drawing::Font(L"Segoe UI", 20, System::Drawing::FontStyle::Bold)); this->lblAutenticaciones->Location = System::Drawing::Point(16, 45); this->lblAutenticaciones->Text = L"0";
			this->lblAutenticacionesSub->AutoSize = true; this->lblAutenticacionesSub->ForeColor = System::Drawing::Color::DimGray; this->lblAutenticacionesSub->Location = System::Drawing::Point(18, 92); this->lblAutenticacionesSub->Text = L"en el periodo";
			this->cardExito->BackColor = System::Drawing::Color::White; this->cardExito->Controls->Add(this->lblCardExito); this->cardExito->Controls->Add(this->lblExito); this->cardExito->Controls->Add(this->lblExitoSub); this->cardExito->Location = System::Drawing::Point(242, 142); this->cardExito->Size = System::Drawing::Size(200, 132);
			this->lblCardExito->AutoSize = true; this->lblCardExito->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold)); this->lblCardExito->ForeColor = System::Drawing::Color::FromArgb(90, 115, 140); this->lblCardExito->Location = System::Drawing::Point(16, 16); this->lblCardExito->Text = L"Tasa de exito";
			this->lblExito->AutoSize = true; this->lblExito->Font = (gcnew System::Drawing::Font(L"Segoe UI", 20, System::Drawing::FontStyle::Bold)); this->lblExito->ForeColor = System::Drawing::Color::FromArgb(20, 125, 95); this->lblExito->Location = System::Drawing::Point(16, 45); this->lblExito->Text = L"0%";
			this->lblExitoSub->AutoSize = true; this->lblExitoSub->ForeColor = System::Drawing::Color::DimGray; this->lblExitoSub->Location = System::Drawing::Point(18, 92); this->lblExitoSub->Text = L"autenticaciones";
			this->cardFallos->BackColor = System::Drawing::Color::White; this->cardFallos->Controls->Add(this->lblCardFallos); this->cardFallos->Controls->Add(this->lblFallos); this->cardFallos->Controls->Add(this->lblFallosSub); this->cardFallos->Location = System::Drawing::Point(462, 142); this->cardFallos->Size = System::Drawing::Size(200, 132);
			this->lblCardFallos->AutoSize = true; this->lblCardFallos->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold)); this->lblCardFallos->ForeColor = System::Drawing::Color::FromArgb(90, 115, 140); this->lblCardFallos->Location = System::Drawing::Point(16, 16); this->lblCardFallos->Text = L"Fallos de autenticacion";
			this->lblFallos->AutoSize = true; this->lblFallos->Font = (gcnew System::Drawing::Font(L"Segoe UI", 20, System::Drawing::FontStyle::Bold)); this->lblFallos->ForeColor = System::Drawing::Color::FromArgb(190, 120, 20); this->lblFallos->Location = System::Drawing::Point(16, 45); this->lblFallos->Text = L"0";
			this->lblFallosSub->AutoSize = true; this->lblFallosSub->ForeColor = System::Drawing::Color::DimGray; this->lblFallosSub->Location = System::Drawing::Point(18, 92); this->lblFallosSub->Text = L"huellas no reconocidas";
			this->cardAgua->BackColor = System::Drawing::Color::White; this->cardAgua->Controls->Add(this->lblCardAgua); this->cardAgua->Controls->Add(this->lblAgua); this->cardAgua->Controls->Add(this->lblAguaSub); this->cardAgua->Location = System::Drawing::Point(682, 142); this->cardAgua->Size = System::Drawing::Size(200, 132);
			this->lblCardAgua->AutoSize = true; this->lblCardAgua->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold)); this->lblCardAgua->ForeColor = System::Drawing::Color::FromArgb(90, 115, 140); this->lblCardAgua->Location = System::Drawing::Point(16, 16); this->lblCardAgua->Text = L"Agua servida";
			this->lblAgua->AutoSize = true; this->lblAgua->Font = (gcnew System::Drawing::Font(L"Segoe UI", 20, System::Drawing::FontStyle::Bold)); this->lblAgua->ForeColor = System::Drawing::Color::FromArgb(55, 138, 221); this->lblAgua->Location = System::Drawing::Point(16, 45); this->lblAgua->Text = L"0 L";
			this->lblAguaSub->AutoSize = true; this->lblAguaSub->ForeColor = System::Drawing::Color::DimGray; this->lblAguaSub->Location = System::Drawing::Point(18, 92); this->lblAguaSub->Text = L"volumen total";
			this->cardDispensaciones->BackColor = System::Drawing::Color::White; this->cardDispensaciones->Controls->Add(this->lblCardDispensaciones); this->cardDispensaciones->Controls->Add(this->lblDispensaciones); this->cardDispensaciones->Controls->Add(this->lblDispensacionesSub); this->cardDispensaciones->Location = System::Drawing::Point(902, 142); this->cardDispensaciones->Size = System::Drawing::Size(200, 132);
			this->lblCardDispensaciones->AutoSize = true; this->lblCardDispensaciones->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold)); this->lblCardDispensaciones->ForeColor = System::Drawing::Color::FromArgb(90, 115, 140); this->lblCardDispensaciones->Location = System::Drawing::Point(16, 16); this->lblCardDispensaciones->Text = L"Dispensaciones";
			this->lblDispensaciones->AutoSize = true; this->lblDispensaciones->Font = (gcnew System::Drawing::Font(L"Segoe UI", 20, System::Drawing::FontStyle::Bold)); this->lblDispensaciones->ForeColor = System::Drawing::Color::FromArgb(20, 125, 95); this->lblDispensaciones->Location = System::Drawing::Point(16, 45); this->lblDispensaciones->Text = L"0";
			this->lblDispensacionesSub->AutoSize = true; this->lblDispensacionesSub->ForeColor = System::Drawing::Color::DimGray; this->lblDispensacionesSub->Location = System::Drawing::Point(18, 92); this->lblDispensacionesSub->Text = L"dosis servidas";
			this->cardErrores->BackColor = System::Drawing::Color::White; this->cardErrores->Controls->Add(this->lblCardErrores); this->cardErrores->Controls->Add(this->lblErrores); this->cardErrores->Controls->Add(this->lblErroresSub); this->cardErrores->Location = System::Drawing::Point(1122, 142); this->cardErrores->Size = System::Drawing::Size(200, 132);
			this->lblCardErrores->AutoSize = true; this->lblCardErrores->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold)); this->lblCardErrores->ForeColor = System::Drawing::Color::FromArgb(90, 115, 140); this->lblCardErrores->Location = System::Drawing::Point(16, 16); this->lblCardErrores->Text = L"Errores criticos";
			this->lblErrores->AutoSize = true; this->lblErrores->Font = (gcnew System::Drawing::Font(L"Segoe UI", 20, System::Drawing::FontStyle::Bold)); this->lblErrores->ForeColor = System::Drawing::Color::FromArgb(180, 50, 50); this->lblErrores->Location = System::Drawing::Point(16, 45); this->lblErrores->Text = L"0";
			this->lblErroresSub->AutoSize = true; this->lblErroresSub->ForeColor = System::Drawing::Color::DimGray; this->lblErroresSub->Location = System::Drawing::Point(18, 92); this->lblErroresSub->Text = L"requieren revision";

			this->grpAutenticaciones->BackColor = System::Drawing::Color::White; this->grpAutenticaciones->Controls->Add(this->chartAutenticaciones); this->grpAutenticaciones->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular)); this->grpAutenticaciones->Location = System::Drawing::Point(22, 296); this->grpAutenticaciones->Size = System::Drawing::Size(640, 360); this->grpAutenticaciones->Text = L"Autenticaciones por dia";
			areaAutenticaciones->Name = L"AreaAutenticaciones"; this->chartAutenticaciones->ChartAreas->Add(areaAutenticaciones); this->chartAutenticaciones->Dock = System::Windows::Forms::DockStyle::Fill; leyendaAutenticaciones->Docking = System::Windows::Forms::DataVisualization::Charting::Docking::Top; leyendaAutenticaciones->Name = L"LeyendaAutenticaciones"; this->chartAutenticaciones->Legends->Add(leyendaAutenticaciones);
			serieExitosas->ChartArea = L"AreaAutenticaciones"; serieExitosas->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::StackedColumn; serieExitosas->Legend = L"LeyendaAutenticaciones"; serieExitosas->Name = L"Exitosas"; serieExitosas->Color = System::Drawing::Color::FromArgb(29, 158, 117); this->chartAutenticaciones->Series->Add(serieExitosas);
			serieFallidas->ChartArea = L"AreaAutenticaciones"; serieFallidas->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::StackedColumn; serieFallidas->Legend = L"LeyendaAutenticaciones"; serieFallidas->Name = L"Fallidas"; serieFallidas->Color = System::Drawing::Color::FromArgb(190, 120, 20); this->chartAutenticaciones->Series->Add(serieFallidas);
			this->grpAgua->BackColor = System::Drawing::Color::White; this->grpAgua->Controls->Add(this->chartAgua); this->grpAgua->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular)); this->grpAgua->Location = System::Drawing::Point(682, 296); this->grpAgua->Size = System::Drawing::Size(640, 360); this->grpAgua->Text = L"Agua servida por dia (ml)";
			areaAgua->Name = L"AreaAgua"; this->chartAgua->ChartAreas->Add(areaAgua); this->chartAgua->Dock = System::Windows::Forms::DockStyle::Fill; serieAgua->ChartArea = L"AreaAgua"; serieAgua->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Area; serieAgua->Name = L"Agua"; serieAgua->Color = System::Drawing::Color::FromArgb(100, 55, 138, 221); serieAgua->BorderColor = System::Drawing::Color::FromArgb(35, 105, 170); serieAgua->BorderWidth = 3; this->chartAgua->Series->Add(serieAgua);
			this->grpDistribucion->BackColor = System::Drawing::Color::White; this->grpDistribucion->Controls->Add(this->chartDistribucion); this->grpDistribucion->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular)); this->grpDistribucion->Location = System::Drawing::Point(22, 678); this->grpDistribucion->Size = System::Drawing::Size(640, 350); this->grpDistribucion->Text = L"Distribucion de actividad";
			areaDistribucion->Name = L"AreaDistribucion"; this->chartDistribucion->ChartAreas->Add(areaDistribucion); this->chartDistribucion->Dock = System::Windows::Forms::DockStyle::Fill; leyendaDistribucion->Docking = System::Windows::Forms::DataVisualization::Charting::Docking::Bottom; leyendaDistribucion->Name = L"LeyendaDistribucion"; this->chartDistribucion->Legends->Add(leyendaDistribucion); serieDistribucion->ChartArea = L"AreaDistribucion"; serieDistribucion->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Doughnut; serieDistribucion->Legend = L"LeyendaDistribucion"; serieDistribucion->Name = L"Actividad"; this->chartDistribucion->Series->Add(serieDistribucion);
			this->grpResumen->BackColor = System::Drawing::Color::White; this->grpResumen->Controls->Add(this->txtResumen); this->grpResumen->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular)); this->grpResumen->Location = System::Drawing::Point(682, 678); this->grpResumen->Size = System::Drawing::Size(640, 350); this->grpResumen->Text = L"Resumen operativo";
			this->txtResumen->BackColor = System::Drawing::Color::FromArgb(247, 249, 251); this->txtResumen->BorderStyle = System::Windows::Forms::BorderStyle::None; this->txtResumen->Dock = System::Windows::Forms::DockStyle::Fill; this->txtResumen->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10)); this->txtResumen->ForeColor = System::Drawing::Color::FromArgb(40, 60, 80); this->txtResumen->ReadOnly = true;

			this->grpDetalle->BackColor = System::Drawing::Color::White; this->grpDetalle->Controls->Add(this->dgvDetalle); this->grpDetalle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular)); this->grpDetalle->Location = System::Drawing::Point(22, 1050); this->grpDetalle->Size = System::Drawing::Size(1300, 380); this->grpDetalle->Text = L"Registro de actividad del sistema";
			this->dgvDetalle->AllowUserToAddRows = false; this->dgvDetalle->AllowUserToDeleteRows = false; this->dgvDetalle->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill; this->dgvDetalle->BackgroundColor = System::Drawing::Color::FromArgb(247, 249, 251);
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
			this->dgvDetalle->RowTemplate->Height = 32; this->dgvDetalle->BorderStyle = System::Windows::Forms::BorderStyle::None; this->dgvDetalle->Columns->AddRange(gcnew cli::array<System::Windows::Forms::DataGridViewColumn^>(8) { this->colEvento, this->colFecha, this->colPaciente, this->colTipo, this->colOrigen, this->colCantidad, this->colEstado, this->colDetalle }); this->dgvDetalle->Dock = System::Windows::Forms::DockStyle::Fill; this->dgvDetalle->ReadOnly = true; this->dgvDetalle->RowHeadersVisible = false; this->dgvDetalle->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->colEvento->HeaderText = L"# Evento"; this->colEvento->FillWeight = 50; this->colEvento->ReadOnly = true; this->colFecha->HeaderText = L"Fecha / hora"; this->colFecha->FillWeight = 95; this->colFecha->ReadOnly = true; this->colPaciente->HeaderText = L"Paciente"; this->colPaciente->FillWeight = 105; this->colPaciente->ReadOnly = true; this->colTipo->HeaderText = L"Tipo de evento"; this->colTipo->FillWeight = 90; this->colTipo->ReadOnly = true; this->colOrigen->HeaderText = L"Origen"; this->colOrigen->FillWeight = 90; this->colOrigen->ReadOnly = true; this->colCantidad->HeaderText = L"Cantidad"; this->colCantidad->FillWeight = 60; this->colCantidad->ReadOnly = true; this->colEstado->HeaderText = L"Estado"; this->colEstado->FillWeight = 70; this->colEstado->ReadOnly = true; this->colDetalle->HeaderText = L"Detalle"; this->colDetalle->FillWeight = 180; this->colDetalle->ReadOnly = true;
			this->grpObservaciones->BackColor = System::Drawing::Color::White; this->grpObservaciones->Controls->Add(this->txtObservaciones); this->grpObservaciones->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular)); this->grpObservaciones->Location = System::Drawing::Point(22, 1452); this->grpObservaciones->Size = System::Drawing::Size(1300, 180); this->grpObservaciones->Text = L"Observaciones automaticas";
			this->txtObservaciones->BackColor = System::Drawing::Color::FromArgb(247, 249, 251); this->txtObservaciones->BorderStyle = System::Windows::Forms::BorderStyle::None; this->txtObservaciones->Dock = System::Windows::Forms::DockStyle::Fill; this->txtObservaciones->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F)); this->txtObservaciones->ForeColor = System::Drawing::Color::FromArgb(40, 60, 80); this->txtObservaciones->ReadOnly = true;

			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16); this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font; this->BackColor = System::Drawing::Color::FromArgb(241, 244, 248); this->ClientSize = System::Drawing::Size(1360, 760); this->ControlBox = false; this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None; this->Controls->Add(this->panelContenido); this->Controls->Add(this->panelCabecera); this->Name = L"frmUsoSistema"; this->Text = L""; this->Load += gcnew System::EventHandler(this, &frmUsoSistema::frmUsoSistema_Load);
			this->Resize += gcnew System::EventHandler(this, &frmUsoSistema::frmUsoSistema_Resize);
			this->panelCabecera->ResumeLayout(false); this->panelCabecera->PerformLayout(); this->panelContenido->ResumeLayout(false); this->panelFiltros->ResumeLayout(false); this->panelFiltros->PerformLayout();
			this->cardAutenticaciones->ResumeLayout(false); this->cardAutenticaciones->PerformLayout(); this->cardExito->ResumeLayout(false); this->cardExito->PerformLayout(); this->cardFallos->ResumeLayout(false); this->cardFallos->PerformLayout(); this->cardAgua->ResumeLayout(false); this->cardAgua->PerformLayout(); this->cardDispensaciones->ResumeLayout(false); this->cardDispensaciones->PerformLayout(); this->cardErrores->ResumeLayout(false); this->cardErrores->PerformLayout();
			this->grpAutenticaciones->ResumeLayout(false); (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartAutenticaciones))->EndInit(); this->grpAgua->ResumeLayout(false); (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartAgua))->EndInit(); this->grpDistribucion->ResumeLayout(false); (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartDistribucion))->EndInit(); this->grpResumen->ResumeLayout(false); this->grpDetalle->ResumeLayout(false); (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvDetalle))->EndInit(); this->grpObservaciones->ResumeLayout(false); this->ResumeLayout(false);
		}
#pragma endregion

	private:
		bool Contiene(String^ texto, String^ valor) { return !String::IsNullOrWhiteSpace(texto) && texto->IndexOf(valor, StringComparison::OrdinalIgnoreCase) >= 0; }
		bool EsAutenticacion(LogEvento^ e) { return e != nullptr && Contiene(e->getTipoEvento(), "Autenticacion"); }
		bool EsAgua(LogEvento^ e) { return e != nullptr && Contiene(e->getTipoEvento(), "Agua Servida"); }
		bool EsDispensacion(LogEvento^ e) { return e != nullptr && Contiene(e->getTipoEvento(), "Toma") && Contiene(e->getOrigen(), "Dispensador") && (Contiene(e->getEstado(), "Tomada") || Contiene(e->getEstado(), "Retraso")); }
		bool EsError(LogEvento^ e) { return e != nullptr && (Contiene(e->getTipoEvento(), "Error Hardware") || Contiene(e->getTipoEvento(), "Alerta Critica")); }
		bool EsActividad(LogEvento^ e) { return EsAutenticacion(e) || EsAgua(e) || EsDispensacion(e) || EsError(e); }
		DateTime Fecha(LogEvento^ e) { return e->getFechaHoraReal() == DateTime::MinValue ? e->getFechaHoraProgramada() : e->getFechaHoraReal(); }
		String^ Categoria(LogEvento^ e) { return EsAutenticacion(e) ? "Autenticacion" : EsAgua(e) ? "Agua Servida" : EsDispensacion(e) ? "Dispensacion" : "Error Critico"; }
		int IdPacienteSeleccionado() { if (cmbPaciente->SelectedIndex <= 0 || cmbPaciente->SelectedItem == nullptr) return 0; String^ v = cmbPaciente->SelectedItem->ToString(); int p = v->IndexOf(" - "); int id = 0; return p > 0 && Int32::TryParse(v->Substring(0, p), id) ? id : 0; }

		List<LogEvento^>^ Filtrar() {
			List<LogEvento^>^ resultado = gcnew List<LogEvento^>(); int paciente = IdPacienteSeleccionado();
			String^ tipo = cmbTipo->SelectedItem == nullptr ? "Todos los eventos" : cmbTipo->SelectedItem->ToString(); String^ estado = cmbEstado->SelectedItem == nullptr ? "Todos los estados" : cmbEstado->SelectedItem->ToString();
			for each(LogEvento ^ e in controller->ObtenerTodos()) {
				if (!EsActividad(e)) continue; DateTime fecha = Fecha(e); if (fecha == DateTime::MinValue || fecha.Date < dtpDesde->Value.Date || fecha.Date > dtpHasta->Value.Date) continue;
				if (paciente > 0 && e->getIdPaciente() != paciente) continue; if (tipo != "Todos los eventos" && Categoria(e) != tipo) continue; if (estado != "Todos los estados" && !Contiene(e->getEstado(), estado)) continue; resultado->Add(e);
			}
			return resultado;
		}

		void CargarFiltros() {
			SortedDictionary<int, String^>^ pacientes = gcnew SortedDictionary<int, String^>(); SortedDictionary<String^, bool>^ estados = gcnew SortedDictionary<String^, bool>(); DateTime min = DateTime::MaxValue, max = DateTime::MinValue;
			for each(LogEvento ^ e in controller->ObtenerTodos()) if (EsActividad(e)) {
				if (e->getIdPaciente() > 0 && !pacientes->ContainsKey(e->getIdPaciente())) pacientes->Add(e->getIdPaciente(), e->getNombrePaciente()); if (!String::IsNullOrWhiteSpace(e->getEstado()) && !estados->ContainsKey(e->getEstado())) estados->Add(e->getEstado(), true);
				DateTime f = Fecha(e); if (f != DateTime::MinValue && f < min) min = f; if (f != DateTime::MinValue && f > max) max = f;
			}
			cmbPaciente->Items->Clear(); cmbPaciente->Items->Add("Todos los pacientes"); for each(KeyValuePair<int, String^> x in pacientes) cmbPaciente->Items->Add(x.Key + " - " + x.Value); cmbPaciente->SelectedIndex = 0;
			cmbTipo->Items->Clear(); cmbTipo->Items->AddRange(gcnew array<Object^>{"Todos los eventos", "Autenticacion", "Agua Servida", "Dispensacion", "Error Critico"}); cmbTipo->SelectedIndex = 0;
			cmbEstado->Items->Clear(); cmbEstado->Items->Add("Todos los estados"); for each(KeyValuePair<String^, bool> x in estados) cmbEstado->Items->Add(x.Key); cmbEstado->SelectedIndex = 0;
			dtpDesde->Value = min == DateTime::MaxValue ? DateTime::Today.AddDays(-30) : min.Date; dtpHasta->Value = max == DateTime::MinValue ? DateTime::Today : max.Date;
		}

		void Actualizar() {
			List<LogEvento^>^ eventos = Filtrar(); int auth = 0, authOk = 0, authFail = 0, agua = 0, dispensaciones = 0, errores = 0;
			SortedDictionary<DateTime, array<int>^>^ authDia = gcnew SortedDictionary<DateTime, array<int>^>(); SortedDictionary<DateTime, int>^ aguaDia = gcnew SortedDictionary<DateTime, int>(); Dictionary<String^, int>^ categorias = gcnew Dictionary<String^, int>();
			dgvDetalle->Rows->Clear();
			for each(LogEvento ^ e in eventos) {
				String^ cat = Categoria(e); if (!categorias->ContainsKey(cat)) categorias->Add(cat, 0); categorias[cat]++; DateTime fecha = Fecha(e);
				if (EsAutenticacion(e)) { auth++; if (!authDia->ContainsKey(fecha.Date)) authDia->Add(fecha.Date, gcnew array<int>(2)); if (Contiene(e->getEstado(), "Exitosa")) { authOk++; authDia[fecha.Date][0]++; } else { authFail++; authDia[fecha.Date][1]++; } }
				else if (EsAgua(e)) { int ml = Math::Max(0, e->getCantidad()); agua += ml; if (!aguaDia->ContainsKey(fecha.Date)) aguaDia->Add(fecha.Date, 0); aguaDia[fecha.Date] += ml; }
				else if (EsDispensacion(e)) dispensaciones++; else if (EsError(e)) errores++;
				dgvDetalle->Rows->Add(e->getId(), fecha.ToString("dd/MM/yyyy HH:mm"), String::IsNullOrWhiteSpace(e->getNombrePaciente()) ? "Sistema MediCheck" : e->getNombrePaciente(), cat, e->getOrigen(), e->getCantidad(), e->getEstado(), e->getDetalle());
			}
			double tasa = auth == 0 ? 0.0 : authOk * 100.0 / auth; lblAutenticaciones->Text = auth.ToString(); lblExito->Text = String::Format("{0:F0}%", tasa); lblFallos->Text = authFail.ToString(); lblAgua->Text = String::Format("{0:F1} L", agua / 1000.0); lblDispensaciones->Text = dispensaciones.ToString(); lblErrores->Text = errores.ToString();
			Series^ exitosas = chartAutenticaciones->Series["Exitosas"]; Series^ fallidas = chartAutenticaciones->Series["Fallidas"]; exitosas->Points->Clear(); fallidas->Points->Clear(); for each(KeyValuePair<DateTime, array<int>^> x in authDia) { exitosas->Points->AddXY(x.Key.ToString("dd/MM"), x.Value[0]); fallidas->Points->AddXY(x.Key.ToString("dd/MM"), x.Value[1]); }
			Series^ serieAgua = chartAgua->Series["Agua"]; serieAgua->Points->Clear(); for each(KeyValuePair<DateTime, int> x in aguaDia) serieAgua->Points->AddXY(x.Key.ToString("dd/MM"), x.Value);
			Series^ distribucion = chartDistribucion->Series["Actividad"]; distribucion->Points->Clear(); array<Color>^ colores = { Color::FromArgb(105, 95, 210), Color::FromArgb(55, 138, 221), Color::FromArgb(29, 158, 117), Color::FromArgb(180, 50, 50) }; int i = 0; for each(KeyValuePair<String^, int> x in categorias) { int p = distribucion->Points->AddXY(x.Key, x.Value); distribucion->Points[p]->Color = colores[i++ % colores->Length]; } distribucion["DoughnutRadius"] = "58";
			txtResumen->Text = String::Format("RESUMEN OPERATIVO\r\n\r\nAutenticaciones: {0}\r\nAutenticaciones exitosas: {1}\r\nFallos de autenticacion: {2}\r\nAgua servida: {3} ml\r\nDispensaciones exitosas: {4}\r\nErrores criticos: {5}", auth, authOk, authFail, agua, dispensaciones, errores);
			txtObservaciones->Text = String::Format("Durante el periodo se registraron {0} actividades del sistema. La tasa de autenticacion exitosa fue de {1:F1}%. Se sirvieron {2:F1} litros de agua y se completaron {3} dispensaciones. Se detectaron {4} fallos de autenticacion y {5} errores criticos que requieren seguimiento.", eventos->Count, tasa, agua / 1000.0, dispensaciones, authFail, errores);
			lblGenerado->Text = "Generado: " + DateTime::Now.ToString("dd/MM/yyyy HH:mm"); dgvDetalle->ClearSelection();
		}

		void Ajustar() {
			chartAutenticaciones->Dock = DockStyle::None; chartAgua->Dock = DockStyle::None; chartDistribucion->Dock = DockStyle::None; dgvDetalle->Dock = DockStyle::None;
			chartAutenticaciones->Bounds = grpAutenticaciones->DisplayRectangle; chartAgua->Bounds = grpAgua->DisplayRectangle; chartDistribucion->Bounds = grpDistribucion->DisplayRectangle; dgvDetalle->Bounds = grpDetalle->DisplayRectangle;
			AnchorStyles a = AnchorStyles::Top | AnchorStyles::Bottom | AnchorStyles::Left | AnchorStyles::Right; chartAutenticaciones->Anchor = a; chartAgua->Anchor = a; chartDistribucion->Anchor = a; dgvDetalle->Anchor = a;
			ChartArea^ area = chartAutenticaciones->ChartAreas["AreaAutenticaciones"]; area->Position->Auto = false; area->Position->X = 8; area->Position->Y = 14; area->Position->Width = 88; area->Position->Height = 76;
			area = chartAgua->ChartAreas["AreaAgua"]; area->Position->Auto = false; area->Position->X = 8; area->Position->Y = 8; area->Position->Width = 88; area->Position->Height = 82;
			area = chartDistribucion->ChartAreas["AreaDistribucion"]; area->Position->Auto = false; area->Position->X = 8; area->Position->Y = 5; area->Position->Width = 84; area->Position->Height = 80;
		}


		void AjustarDistribucion() {
			int margen = 22;
			int separacion = 20;
			int anchoDisponible = this->panelContenido->ClientSize.Width - (margen * 2);

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
				this->cardAutenticaciones->Height +
				espacioVertical;

			int yInferior =
				yGraficos +
				this->grpAutenticaciones->Height +
				espacioVertical;

			int yDetalle =
				yInferior +
				this->grpDistribucion->Height +
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

			// Distribuir los campos del filtro en todo el ancho
			int espacioInterno = 18;
			int separacionFiltro = 14;
			int anchoBoton = 165;
			int anchoFecha = 140;
			int anchoPaciente = 210;
			int anchoTipo = 190;
			int anchoEstado = 180;

			int x = espacioInterno;

			this->lblPacienteFiltro->Location = System::Drawing::Point(x, 13);
			this->cmbPaciente->Location = System::Drawing::Point(x, 40);
			this->cmbPaciente->Width = anchoPaciente;
			x += anchoPaciente + separacionFiltro;

			this->lblDesde->Location = System::Drawing::Point(x, 13);
			this->dtpDesde->Location = System::Drawing::Point(x, 40);
			this->dtpDesde->Width = anchoFecha;
			x += anchoFecha + separacionFiltro;

			this->lblHasta->Location = System::Drawing::Point(x, 13);
			this->dtpHasta->Location = System::Drawing::Point(x, 40);
			this->dtpHasta->Width = anchoFecha;
			x += anchoFecha + separacionFiltro;

			this->lblTipoFiltro->Location = System::Drawing::Point(x, 13);
			this->cmbTipo->Location = System::Drawing::Point(x, 40);
			this->cmbTipo->Width = anchoTipo;
			x += anchoTipo + separacionFiltro;

			this->lblEstadoFiltro->Location = System::Drawing::Point(x, 13);
			this->cmbEstado->Location = System::Drawing::Point(x, 40);
			this->cmbEstado->Width = anchoEstado;

			// Botones alineados a la derecha del panel
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
			if (x + anchoEstado + separacionFiltro > xAplicar) {
				this->cmbEstado->Width =
					Math::Max(110, xAplicar - separacionFiltro - x);
			}

			// Repartir las seis tarjetas
			array<System::Windows::Forms::Panel^>^ tarjetas = {
				this->cardAutenticaciones,
				this->cardExito,
				this->cardFallos,
				this->cardAgua,
				this->cardDispensaciones,
				this->cardErrores
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

			// Gráficos superiores
			this->grpAutenticaciones->Location =
				System::Drawing::Point(margen, yGraficos);
			this->grpAutenticaciones->Width = anchoMitad;

			this->grpAgua->Location =
				System::Drawing::Point(
					margen + anchoMitad + separacion,
					yGraficos
				);
			this->grpAgua->Width = anchoMitad;

			// Gráfico inferior y resumen
			this->grpDistribucion->Location =
				System::Drawing::Point(margen, yInferior);
			this->grpDistribucion->Width = anchoMitad;

			this->grpResumen->Location =
				System::Drawing::Point(
					margen + anchoMitad + separacion,
					yInferior
				);
			this->grpResumen->Width = anchoMitad;

			// Tabla y observaciones
			this->grpDetalle->Location =
				System::Drawing::Point(margen, yDetalle);
			this->grpDetalle->Width = anchoDisponible;

			this->grpObservaciones->Location =
				System::Drawing::Point(margen, yObservaciones);
			this->grpObservaciones->Width = anchoDisponible;

			Ajustar();
		}

		System::Void frmUsoSistema_Resize(
			System::Object^ sender,
			System::EventArgs^ e
		) {
			AjustarDistribucion();
		}

		System::Void frmUsoSistema_Load(System::Object^, System::EventArgs^) {
			controller = gcnew GeneradorReportesController();
			CargarFiltros();
			Actualizar();
			AjustarDistribucion();
			BeginInvoke(gcnew MethodInvoker(this, &frmUsoSistema::AjustarDistribucion));
		}
		System::Void btnAplicar_Click(System::Object^, System::EventArgs^) { Actualizar(); }
		System::Void btnRestablecer_Click(System::Object^, System::EventArgs^) { CargarFiltros(); Actualizar(); }
	};
}
