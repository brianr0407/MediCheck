#pragma once

namespace VIEW {
	using namespace System;
	using namespace System::Collections::Generic;
	using namespace System::Drawing;
	using namespace System::Windows::Forms;
	using namespace System::Windows::Forms::DataVisualization::Charting;
	using namespace MODEL;
	using namespace CONTROLLER;

	public ref class frmAlertasCriticas : public System::Windows::Forms::Form {
	public:
		frmAlertasCriticas() {
			InitializeComponent();
		}

	protected:
		~frmAlertasCriticas() { if (components) delete components; }

	private:
		System::ComponentModel::Container^ components;
		GeneradorReportesController^ reportesController;
		MedicamentoController^ medicamentoController;
		Dictionary<int, bool>^ antibioticos;

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
		System::Windows::Forms::Label^ lblCategoriaFiltro;
		System::Windows::Forms::ComboBox^ cmbCategoria;
		System::Windows::Forms::Label^ lblEstadoFiltro;
		System::Windows::Forms::ComboBox^ cmbEstado;
		System::Windows::Forms::Button^ btnAplicar;
		System::Windows::Forms::Button^ btnRestablecer;

		System::Windows::Forms::Panel^ cardOmisiones;
		System::Windows::Forms::Label^ lblCardOmisiones;
		System::Windows::Forms::Label^ lblOmisiones;
		System::Windows::Forms::Label^ lblOmisionesSub;
		System::Windows::Forms::Panel^ cardHardware;
		System::Windows::Forms::Label^ lblCardHardware;
		System::Windows::Forms::Label^ lblHardware;
		System::Windows::Forms::Label^ lblHardwareSub;
		System::Windows::Forms::Panel^ cardTotal;
		System::Windows::Forms::Label^ lblCardTotal;
		System::Windows::Forms::Label^ lblTotal;
		System::Windows::Forms::Label^ lblTotalSub;
		System::Windows::Forms::Panel^ cardDias;
		System::Windows::Forms::Label^ lblCardDias;
		System::Windows::Forms::Label^ lblDias;
		System::Windows::Forms::Label^ lblDiasSub;

		System::Windows::Forms::GroupBox^ grpDistribucion;
		System::Windows::Forms::DataVisualization::Charting::Chart^ chartDistribucion;
		System::Windows::Forms::GroupBox^ grpResumen;
		System::Windows::Forms::RichTextBox^ txtResumen;
		System::Windows::Forms::GroupBox^ grpDetalle;
		System::Windows::Forms::DataGridView^ dgvDetalle;
		System::Windows::Forms::DataGridViewTextBoxColumn^ colEvento;
		System::Windows::Forms::DataGridViewTextBoxColumn^ colFecha;
		System::Windows::Forms::DataGridViewTextBoxColumn^ colPaciente;
		System::Windows::Forms::DataGridViewTextBoxColumn^ colCategoria;
		System::Windows::Forms::DataGridViewTextBoxColumn^ colTipo;
		System::Windows::Forms::DataGridViewTextBoxColumn^ colDescripcion;
		System::Windows::Forms::DataGridViewTextBoxColumn^ colEstado;
		System::Windows::Forms::GroupBox^ grpObservaciones;
		System::Windows::Forms::RichTextBox^ txtObservaciones;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void) {
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
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
			this->lblCategoriaFiltro = (gcnew System::Windows::Forms::Label());
			this->cmbCategoria = (gcnew System::Windows::Forms::ComboBox());
			this->lblEstadoFiltro = (gcnew System::Windows::Forms::Label());
			this->cmbEstado = (gcnew System::Windows::Forms::ComboBox());
			this->btnAplicar = (gcnew System::Windows::Forms::Button());
			this->btnRestablecer = (gcnew System::Windows::Forms::Button());
			this->cardOmisiones = (gcnew System::Windows::Forms::Panel());
			this->lblCardOmisiones = (gcnew System::Windows::Forms::Label());
			this->lblOmisiones = (gcnew System::Windows::Forms::Label());
			this->lblOmisionesSub = (gcnew System::Windows::Forms::Label());
			this->cardHardware = (gcnew System::Windows::Forms::Panel());
			this->lblCardHardware = (gcnew System::Windows::Forms::Label());
			this->lblHardware = (gcnew System::Windows::Forms::Label());
			this->lblHardwareSub = (gcnew System::Windows::Forms::Label());
			this->cardTotal = (gcnew System::Windows::Forms::Panel());
			this->lblCardTotal = (gcnew System::Windows::Forms::Label());
			this->lblTotal = (gcnew System::Windows::Forms::Label());
			this->lblTotalSub = (gcnew System::Windows::Forms::Label());
			this->cardDias = (gcnew System::Windows::Forms::Panel());
			this->lblCardDias = (gcnew System::Windows::Forms::Label());
			this->lblDias = (gcnew System::Windows::Forms::Label());
			this->lblDiasSub = (gcnew System::Windows::Forms::Label());
			this->grpDistribucion = (gcnew System::Windows::Forms::GroupBox());
			this->chartDistribucion = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->grpResumen = (gcnew System::Windows::Forms::GroupBox());
			this->txtResumen = (gcnew System::Windows::Forms::RichTextBox());
			this->grpDetalle = (gcnew System::Windows::Forms::GroupBox());
			this->dgvDetalle = (gcnew System::Windows::Forms::DataGridView());
			this->colEvento = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colFecha = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colPaciente = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colCategoria = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colTipo = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colDescripcion = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colEstado = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->grpObservaciones = (gcnew System::Windows::Forms::GroupBox());
			this->txtObservaciones = (gcnew System::Windows::Forms::RichTextBox());
			this->panelCabecera->SuspendLayout();
			this->panelContenido->SuspendLayout();
			this->panelFiltros->SuspendLayout();
			this->cardOmisiones->SuspendLayout();
			this->cardHardware->SuspendLayout();
			this->cardTotal->SuspendLayout();
			this->cardDias->SuspendLayout();
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
			this->panelCabecera->Location = System::Drawing::Point(0, 0);
			this->panelCabecera->Name = L"panelCabecera";
			this->panelCabecera->Size = System::Drawing::Size(1360, 84);
			this->lblTitulo->AutoSize = true;
			this->lblTitulo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15, System::Drawing::FontStyle::Regular));
			this->lblTitulo->ForeColor = System::Drawing::Color::FromArgb(220, 233, 245);
			this->lblTitulo->Location = System::Drawing::Point(26, 14);
			this->lblTitulo->Text = L"Reporte de Alertas Criticas";
			this->lblSubtitulo->AutoSize = true;
			this->lblSubtitulo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->lblSubtitulo->ForeColor = System::Drawing::Color::FromArgb(200, 218, 235);
			this->lblSubtitulo->Location = System::Drawing::Point(27, 50);
			this->lblSubtitulo->Text = L"Incumplimientos de antibioticos y fallos del sistema";
			this->lblGenerado->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->lblGenerado->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->lblGenerado->ForeColor = System::Drawing::Color::FromArgb(220, 233, 245);
			this->lblGenerado->Location = System::Drawing::Point(1060, 28);
			this->lblGenerado->Size = System::Drawing::Size(274, 22);
			this->lblGenerado->Text = L"Generado:";
			this->lblGenerado->TextAlign = System::Drawing::ContentAlignment::MiddleRight;

			this->panelContenido->AutoScroll = true;
			this->panelContenido->BackColor = System::Drawing::Color::FromArgb(241, 244, 248);
			this->panelContenido->Controls->Add(this->panelFiltros);
			this->panelContenido->Controls->Add(this->cardOmisiones);
			this->panelContenido->Controls->Add(this->cardHardware);
			this->panelContenido->Controls->Add(this->cardTotal);
			this->panelContenido->Controls->Add(this->cardDias);
			this->panelContenido->Controls->Add(this->grpDistribucion);
			this->panelContenido->Controls->Add(this->grpResumen);
			this->panelContenido->Controls->Add(this->grpDetalle);
			this->panelContenido->Controls->Add(this->grpObservaciones);
			this->panelContenido->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panelContenido->Location = System::Drawing::Point(0, 84);
			this->panelContenido->Name = L"panelContenido";
			this->panelContenido->Size = System::Drawing::Size(1360, 676);

			this->panelFiltros->BackColor = System::Drawing::Color::White;
			this->panelFiltros->Controls->Add(this->lblPacienteFiltro);
			this->panelFiltros->Controls->Add(this->cmbPaciente);
			this->panelFiltros->Controls->Add(this->lblDesde);
			this->panelFiltros->Controls->Add(this->dtpDesde);
			this->panelFiltros->Controls->Add(this->lblHasta);
			this->panelFiltros->Controls->Add(this->dtpHasta);
			this->panelFiltros->Controls->Add(this->lblCategoriaFiltro);
			this->panelFiltros->Controls->Add(this->cmbCategoria);
			this->panelFiltros->Controls->Add(this->lblEstadoFiltro);
			this->panelFiltros->Controls->Add(this->cmbEstado);
			this->panelFiltros->Controls->Add(this->btnAplicar);
			this->panelFiltros->Controls->Add(this->btnRestablecer);
			this->panelFiltros->Location = System::Drawing::Point(22, 18);
			this->panelFiltros->Size = System::Drawing::Size(1300, 104);
			this->lblPacienteFiltro->AutoSize = true;
			this->lblPacienteFiltro->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblPacienteFiltro->ForeColor = System::Drawing::Color::FromArgb(90, 115, 140);
			this->lblPacienteFiltro->Location = System::Drawing::Point(16, 13);
			this->lblPacienteFiltro->Text = L"Paciente";
			this->cmbPaciente->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbPaciente->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->cmbPaciente->BackColor = System::Drawing::Color::White;
			this->cmbPaciente->ForeColor = System::Drawing::Color::FromArgb(30, 50, 70);
			this->cmbPaciente->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F));
			this->cmbPaciente->Location = System::Drawing::Point(16, 40);
			this->cmbPaciente->Size = System::Drawing::Size(190, 24);
			this->lblDesde->AutoSize = true;
			this->lblDesde->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblDesde->ForeColor = System::Drawing::Color::FromArgb(90, 115, 140);
			this->lblDesde->Location = System::Drawing::Point(220, 13);
			this->lblDesde->Text = L"Desde";
			this->dtpDesde->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dtpDesde->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F));
			this->dtpDesde->CalendarForeColor = System::Drawing::Color::FromArgb(30, 50, 70);
			this->dtpDesde->Location = System::Drawing::Point(220, 40);
			this->dtpDesde->Size = System::Drawing::Size(135, 22);
			this->lblHasta->AutoSize = true;
			this->lblHasta->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblHasta->ForeColor = System::Drawing::Color::FromArgb(90, 115, 140);
			this->lblHasta->Location = System::Drawing::Point(369, 13);
			this->lblHasta->Text = L"Hasta";
			this->dtpHasta->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dtpHasta->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F));
			this->dtpHasta->CalendarForeColor = System::Drawing::Color::FromArgb(30, 50, 70);
			this->dtpHasta->Location = System::Drawing::Point(369, 40);
			this->dtpHasta->Size = System::Drawing::Size(135, 22);
			this->lblCategoriaFiltro->AutoSize = true;
			this->lblCategoriaFiltro->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblCategoriaFiltro->ForeColor = System::Drawing::Color::FromArgb(90, 115, 140);
			this->lblCategoriaFiltro->Location = System::Drawing::Point(518, 13);
			this->lblCategoriaFiltro->Text = L"Categoria";
			this->cmbCategoria->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbCategoria->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->cmbCategoria->BackColor = System::Drawing::Color::White;
			this->cmbCategoria->ForeColor = System::Drawing::Color::FromArgb(30, 50, 70);
			this->cmbCategoria->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F));
			this->cmbCategoria->Location = System::Drawing::Point(518, 40);
			this->cmbCategoria->Size = System::Drawing::Size(180, 24);
			this->lblEstadoFiltro->AutoSize = true;
			this->lblEstadoFiltro->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblEstadoFiltro->ForeColor = System::Drawing::Color::FromArgb(90, 115, 140);
			this->lblEstadoFiltro->Location = System::Drawing::Point(712, 13);
			this->lblEstadoFiltro->Text = L"Estado";
			this->cmbEstado->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbEstado->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->cmbEstado->BackColor = System::Drawing::Color::White;
			this->cmbEstado->ForeColor = System::Drawing::Color::FromArgb(30, 50, 70);
			this->cmbEstado->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F));
			this->cmbEstado->Location = System::Drawing::Point(712, 40);
			this->cmbEstado->Size = System::Drawing::Size(170, 24);
			this->btnAplicar->BackColor = System::Drawing::Color::FromArgb(234, 243, 222);
			this->btnAplicar->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(168, 208, 106);
			this->btnAplicar->FlatAppearance->BorderSize = 1;
			this->btnAplicar->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(192, 221, 151);
			this->btnAplicar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnAplicar->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F, System::Drawing::FontStyle::Regular));
			this->btnAplicar->ForeColor = System::Drawing::Color::FromArgb(39, 80, 10);
			this->btnAplicar->Location = System::Drawing::Point(900, 34);
			this->btnAplicar->Size = System::Drawing::Size(175, 36);
			this->btnAplicar->Text = L"Aplicar filtros";
			this->btnAplicar->UseVisualStyleBackColor = false;
			this->btnAplicar->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnAplicar->Click += gcnew System::EventHandler(this, &frmAlertasCriticas::btnAplicar_Click);
			this->btnRestablecer->BackColor = System::Drawing::Color::FromArgb(230, 241, 251);
			this->btnRestablecer->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(158, 198, 240);
			this->btnRestablecer->FlatAppearance->BorderSize = 1;
			this->btnRestablecer->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(181, 212, 244);
			this->btnRestablecer->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnRestablecer->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F, System::Drawing::FontStyle::Regular));
			this->btnRestablecer->ForeColor = System::Drawing::Color::FromArgb(12, 68, 124);
			this->btnRestablecer->Location = System::Drawing::Point(1090, 34);
			this->btnRestablecer->Size = System::Drawing::Size(175, 36);
			this->btnRestablecer->Text = L"Restablecer";
			this->btnRestablecer->UseVisualStyleBackColor = false;
			this->btnRestablecer->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnRestablecer->Click += gcnew System::EventHandler(this, &frmAlertasCriticas::btnRestablecer_Click);

			this->cardOmisiones->BackColor = System::Drawing::Color::White;
			this->cardOmisiones->Controls->Add(this->lblCardOmisiones);
			this->cardOmisiones->Controls->Add(this->lblOmisiones);
			this->cardOmisiones->Controls->Add(this->lblOmisionesSub);
			this->cardOmisiones->Location = System::Drawing::Point(22, 142);
			this->cardOmisiones->Size = System::Drawing::Size(310, 132);
			this->lblCardOmisiones->AutoSize = true;
			this->lblCardOmisiones->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblCardOmisiones->ForeColor = System::Drawing::Color::FromArgb(90, 115, 140);
			this->lblCardOmisiones->Location = System::Drawing::Point(16, 16);
			this->lblCardOmisiones->Text = L"Omisiones criticas";
			this->lblOmisiones->AutoSize = true;
			this->lblOmisiones->Font = (gcnew System::Drawing::Font(L"Segoe UI", 20, System::Drawing::FontStyle::Bold));
			this->lblOmisiones->ForeColor = System::Drawing::Color::FromArgb(180, 50, 50);
			this->lblOmisiones->Location = System::Drawing::Point(16, 45);
			this->lblOmisiones->Text = L"0";
			this->lblOmisionesSub->AutoSize = true;
			this->lblOmisionesSub->ForeColor = System::Drawing::Color::DimGray;
			this->lblOmisionesSub->Location = System::Drawing::Point(18, 92);
			this->lblOmisionesSub->Text = L"antibioticos no tomados";

			this->cardHardware->BackColor = System::Drawing::Color::White;
			this->cardHardware->Controls->Add(this->lblCardHardware);
			this->cardHardware->Controls->Add(this->lblHardware);
			this->cardHardware->Controls->Add(this->lblHardwareSub);
			this->cardHardware->Location = System::Drawing::Point(352, 142);
			this->cardHardware->Size = System::Drawing::Size(310, 132);
			this->lblCardHardware->AutoSize = true;
			this->lblCardHardware->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblCardHardware->ForeColor = System::Drawing::Color::FromArgb(90, 115, 140);
			this->lblCardHardware->Location = System::Drawing::Point(16, 16);
			this->lblCardHardware->Text = L"Fallos de hardware";
			this->lblHardware->AutoSize = true;
			this->lblHardware->Font = (gcnew System::Drawing::Font(L"Segoe UI", 20, System::Drawing::FontStyle::Bold));
			this->lblHardware->ForeColor = System::Drawing::Color::FromArgb(190, 120, 20);
			this->lblHardware->Location = System::Drawing::Point(16, 45);
			this->lblHardware->Text = L"0";
			this->lblHardwareSub->AutoSize = true;
			this->lblHardwareSub->ForeColor = System::Drawing::Color::DimGray;
			this->lblHardwareSub->Location = System::Drawing::Point(18, 92);
			this->lblHardwareSub->Text = L"incidencias del sistema";

			this->cardTotal->BackColor = System::Drawing::Color::White;
			this->cardTotal->Controls->Add(this->lblCardTotal);
			this->cardTotal->Controls->Add(this->lblTotal);
			this->cardTotal->Controls->Add(this->lblTotalSub);
			this->cardTotal->Location = System::Drawing::Point(682, 142);
			this->cardTotal->Size = System::Drawing::Size(310, 132);
			this->lblCardTotal->AutoSize = true;
			this->lblCardTotal->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblCardTotal->ForeColor = System::Drawing::Color::FromArgb(90, 115, 140);
			this->lblCardTotal->Location = System::Drawing::Point(16, 16);
			this->lblCardTotal->Text = L"Total de alertas";
			this->lblTotal->AutoSize = true;
			this->lblTotal->Font = (gcnew System::Drawing::Font(L"Segoe UI", 20, System::Drawing::FontStyle::Bold));
			this->lblTotal->ForeColor = System::Drawing::Color::FromArgb(15, 41, 66);
			this->lblTotal->Location = System::Drawing::Point(16, 45);
			this->lblTotal->Text = L"0";
			this->lblTotalSub->AutoSize = true;
			this->lblTotalSub->ForeColor = System::Drawing::Color::DimGray;
			this->lblTotalSub->Location = System::Drawing::Point(18, 92);
			this->lblTotalSub->Text = L"en el periodo";

			this->cardDias->BackColor = System::Drawing::Color::White;
			this->cardDias->Controls->Add(this->lblCardDias);
			this->cardDias->Controls->Add(this->lblDias);
			this->cardDias->Controls->Add(this->lblDiasSub);
			this->cardDias->Location = System::Drawing::Point(1012, 142);
			this->cardDias->Size = System::Drawing::Size(310, 132);
			this->lblCardDias->AutoSize = true;
			this->lblCardDias->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblCardDias->ForeColor = System::Drawing::Color::FromArgb(90, 115, 140);
			this->lblCardDias->Location = System::Drawing::Point(16, 16);
			this->lblCardDias->Text = L"Dias sin incidentes";
			this->lblDias->AutoSize = true;
			this->lblDias->Font = (gcnew System::Drawing::Font(L"Segoe UI", 20, System::Drawing::FontStyle::Bold));
			this->lblDias->ForeColor = System::Drawing::Color::FromArgb(20, 125, 95);
			this->lblDias->Location = System::Drawing::Point(16, 45);
			this->lblDias->Text = L"0 / 0";
			this->lblDiasSub->AutoSize = true;
			this->lblDiasSub->ForeColor = System::Drawing::Color::DimGray;
			this->lblDiasSub->Location = System::Drawing::Point(18, 92);
			this->lblDiasSub->Text = L"periodo seleccionado";

			this->grpDistribucion->BackColor = System::Drawing::Color::White;
			this->grpDistribucion->Controls->Add(this->chartDistribucion);
			this->grpDistribucion->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular));
			this->grpDistribucion->Location = System::Drawing::Point(22, 296);
			this->grpDistribucion->Size = System::Drawing::Size(640, 390);
			this->grpDistribucion->Text = L"Distribucion por categoria";
			chartArea1->Name = L"AreaDistribucion";
			this->chartDistribucion->ChartAreas->Add(chartArea1);
			this->chartDistribucion->Dock = System::Windows::Forms::DockStyle::Fill;
			legend1->Docking = System::Windows::Forms::DataVisualization::Charting::Docking::Bottom;
			legend1->Name = L"Leyenda";
			this->chartDistribucion->Legends->Add(legend1);
			series1->ChartArea = L"AreaDistribucion";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Doughnut;
			series1->Legend = L"Leyenda";
			series1->Name = L"Categorias";
			this->chartDistribucion->Series->Add(series1);

			this->grpResumen->BackColor = System::Drawing::Color::White;
			this->grpResumen->Controls->Add(this->txtResumen);
			this->grpResumen->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular));
			this->grpResumen->Location = System::Drawing::Point(682, 296);
			this->grpResumen->Size = System::Drawing::Size(640, 390);
			this->grpResumen->Text = L"Resumen de alertas criticas";
			this->txtResumen->BackColor = System::Drawing::Color::FromArgb(247, 249, 251);
			this->txtResumen->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txtResumen->Dock = System::Windows::Forms::DockStyle::Fill;
			this->txtResumen->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->txtResumen->ForeColor = System::Drawing::Color::FromArgb(40, 60, 80);
			this->txtResumen->ReadOnly = true;

			this->grpDetalle->BackColor = System::Drawing::Color::White;
			this->grpDetalle->Controls->Add(this->dgvDetalle);
			this->grpDetalle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular));
			this->grpDetalle->Location = System::Drawing::Point(22, 708);
			this->grpDetalle->Size = System::Drawing::Size(1300, 370);
			this->grpDetalle->Text = L"Registro de alertas criticas";
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
				this->colEvento, this->colFecha, this->colPaciente, this->colCategoria, this->colTipo, this->colDescripcion, this->colEstado
			});
			this->dgvDetalle->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dgvDetalle->ReadOnly = true;
			this->dgvDetalle->RowHeadersVisible = false;
			this->dgvDetalle->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->colEvento->HeaderText = L"# Evento";
			this->colEvento->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->colEvento->FillWeight = 55;
			this->colEvento->ReadOnly = true;
			this->colFecha->HeaderText = L"Fecha / hora";
			this->colFecha->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->colFecha->FillWeight = 100;
			this->colFecha->ReadOnly = true;
			this->colPaciente->HeaderText = L"Paciente";
			this->colPaciente->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->colPaciente->FillWeight = 105;
			this->colPaciente->ReadOnly = true;
			this->colCategoria->HeaderText = L"Categoria";
			this->colCategoria->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->colCategoria->FillWeight = 80;
			this->colCategoria->ReadOnly = true;
			this->colTipo->HeaderText = L"Tipo / origen";
			this->colTipo->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->colTipo->FillWeight = 95;
			this->colTipo->ReadOnly = true;
			this->colDescripcion->HeaderText = L"Descripcion";
			this->colDescripcion->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->colDescripcion->FillWeight = 190;
			this->colDescripcion->ReadOnly = true;
			this->colEstado->HeaderText = L"Estado";
			this->colEstado->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->colEstado->FillWeight = 75;
			this->colEstado->ReadOnly = true;

			this->grpObservaciones->BackColor = System::Drawing::Color::White;
			this->grpObservaciones->Controls->Add(this->txtObservaciones);
			this->grpObservaciones->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular));
			this->grpObservaciones->Location = System::Drawing::Point(22, 1100);
			this->grpObservaciones->Size = System::Drawing::Size(1300, 180);
			this->grpObservaciones->Text = L"Observaciones automaticas";
			this->txtObservaciones->BackColor = System::Drawing::Color::FromArgb(247, 249, 251);
			this->txtObservaciones->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txtObservaciones->Dock = System::Windows::Forms::DockStyle::Fill;
			this->txtObservaciones->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F));
			this->txtObservaciones->ForeColor = System::Drawing::Color::FromArgb(40, 60, 80);
			this->txtObservaciones->ReadOnly = true;

			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(241, 244, 248);
			this->ClientSize = System::Drawing::Size(1360, 760);
			this->ControlBox = false;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Controls->Add(this->panelContenido);
			this->Controls->Add(this->panelCabecera);
			this->Name = L"frmAlertasCriticas";
			this->Text = L"";
			this->Load += gcnew System::EventHandler(
				this,
				&frmAlertasCriticas::frmAlertasCriticas_Load
			);
			this->Resize += gcnew System::EventHandler(
				this,
				&frmAlertasCriticas::frmAlertasCriticas_Resize
			);
			this->panelCabecera->ResumeLayout(false);
			this->panelCabecera->PerformLayout();
			this->panelContenido->ResumeLayout(false);
			this->panelFiltros->ResumeLayout(false);
			this->panelFiltros->PerformLayout();
			this->cardOmisiones->ResumeLayout(false);
			this->cardOmisiones->PerformLayout();
			this->cardHardware->ResumeLayout(false);
			this->cardHardware->PerformLayout();
			this->cardTotal->ResumeLayout(false);
			this->cardTotal->PerformLayout();
			this->cardDias->ResumeLayout(false);
			this->cardDias->PerformLayout();
			this->grpDistribucion->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartDistribucion))->EndInit();
			this->grpResumen->ResumeLayout(false);
			this->grpDetalle->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvDetalle))->EndInit();
			this->grpObservaciones->ResumeLayout(false);
			this->ResumeLayout(false);
		}
#pragma endregion

	private:
		bool Contiene(String^ texto, String^ valor) {
			return !String::IsNullOrWhiteSpace(texto) && texto->IndexOf(valor, StringComparison::OrdinalIgnoreCase) >= 0;
		}

		bool EsOmitida(LogEvento^ evento) {
			return evento != nullptr && (Contiene(evento->getTipoEvento(), "Toma") || Contiene(evento->getTipoEvento(), "Dosis")) &&
				(Contiene(evento->getEstado(), "Omitida") || Contiene(evento->getEstado(), "No tomada") || Contiene(evento->getEstado(), "Omision"));
		}

		bool EsHardware(LogEvento^ evento) {
			return evento != nullptr && (Contiene(evento->getTipoEvento(), "Error Hardware") || Contiene(evento->getTipoEvento(), "Alerta Critica") ||
				Contiene(evento->getOrigen(), "Alarma Critica") || Contiene(evento->getOrigen(), "Error"));
		}

		bool EsAlerta(LogEvento^ evento) {
			return EsHardware(evento) || (EsOmitida(evento) && antibioticos->ContainsKey(evento->getIdMedicamento()));
		}

		String^ Categoria(LogEvento^ evento) { return EsHardware(evento) ? "Hardware" : "Antibiotico"; }

		DateTime FechaEvento(LogEvento^ evento) {
			return evento->getFechaHoraReal() == DateTime::MinValue ? evento->getFechaHoraProgramada() : evento->getFechaHoraReal();
		}

		int IdPacienteSeleccionado() {
			if (cmbPaciente->SelectedIndex <= 0 || cmbPaciente->SelectedItem == nullptr) return 0;
			String^ valor = cmbPaciente->SelectedItem->ToString();
			int posicion = valor->IndexOf(" - ");
			int id = 0;
			return posicion > 0 && Int32::TryParse(valor->Substring(0, posicion), id) ? id : 0;
		}

		List<LogEvento^>^ Filtrar() {
			List<LogEvento^>^ resultado = gcnew List<LogEvento^>();
			int paciente = IdPacienteSeleccionado();
			String^ categoria = cmbCategoria->SelectedItem == nullptr ? "Todas las categorias" : cmbCategoria->SelectedItem->ToString();
			String^ estado = cmbEstado->SelectedItem == nullptr ? "Todos los estados" : cmbEstado->SelectedItem->ToString();
			for each(LogEvento ^ evento in reportesController->ObtenerTodos()) {
				if (!EsAlerta(evento)) continue;
				DateTime fecha = FechaEvento(evento);
				if (fecha == DateTime::MinValue || fecha.Date < dtpDesde->Value.Date || fecha.Date > dtpHasta->Value.Date) continue;
				if (paciente > 0 && evento->getIdPaciente() != paciente) continue;
				if (categoria != "Todas las categorias" && Categoria(evento) != categoria) continue;
				if (estado != "Todos los estados" && !Contiene(evento->getEstado(), estado)) continue;
				resultado->Add(evento);
			}
			return resultado;
		}

		void CargarFiltros() {
			antibioticos = gcnew Dictionary<int, bool>();
			for each(Medicamento ^ medicamento in medicamentoController->ObtenerTodosMedicamentosTXT())
				if (dynamic_cast<Antibiotico^>(medicamento) != nullptr) antibioticos[medicamento->getId()] = true;

			SortedDictionary<int, String^>^ pacientes = gcnew SortedDictionary<int, String^>();
			SortedDictionary<String^, bool>^ estados = gcnew SortedDictionary<String^, bool>();
			DateTime minimo = DateTime::MaxValue;
			DateTime maximo = DateTime::MinValue;
			for each(LogEvento ^ evento in reportesController->ObtenerTodos()) {
				if (!EsAlerta(evento)) continue;
				if (evento->getIdPaciente() > 0 && !pacientes->ContainsKey(evento->getIdPaciente()))
					pacientes->Add(evento->getIdPaciente(), evento->getNombrePaciente());
				if (!String::IsNullOrWhiteSpace(evento->getEstado()) && !estados->ContainsKey(evento->getEstado()))
					estados->Add(evento->getEstado(), true);
				DateTime fecha = FechaEvento(evento);
				if (fecha != DateTime::MinValue && fecha < minimo) minimo = fecha;
				if (fecha != DateTime::MinValue && fecha > maximo) maximo = fecha;
			}
			cmbPaciente->Items->Clear();
			cmbPaciente->Items->Add("Todos los pacientes");
			for each(KeyValuePair<int, String^> paciente in pacientes) cmbPaciente->Items->Add(paciente.Key + " - " + paciente.Value);
			cmbPaciente->SelectedIndex = 0;
			cmbCategoria->Items->Clear();
			cmbCategoria->Items->AddRange(gcnew array<Object^>{"Todas las categorias", "Antibiotico", "Hardware"});
			cmbCategoria->SelectedIndex = 0;
			cmbEstado->Items->Clear();
			cmbEstado->Items->Add("Todos los estados");
			for each(KeyValuePair<String^, bool> estado in estados) cmbEstado->Items->Add(estado.Key);
			cmbEstado->SelectedIndex = 0;
			dtpDesde->Value = minimo == DateTime::MaxValue ? DateTime::Today.AddDays(-30) : minimo.Date;
			dtpHasta->Value = maximo == DateTime::MinValue ? DateTime::Today : maximo.Date;
		}

		void Actualizar() {
			List<LogEvento^>^ alertas = Filtrar();
			int omisiones = 0;
			int hardware = 0;
			int activas = 0;
			Dictionary<DateTime, bool>^ diasConIncidentes = gcnew Dictionary<DateTime, bool>();
			dgvDetalle->Rows->Clear();
			for each(LogEvento ^ evento in alertas) {
				String^ categoria = Categoria(evento);
				if (categoria == "Hardware") hardware++; else omisiones++;
				if (Contiene(evento->getEstado(), "Activa") || Contiene(evento->getEstado(), "Omitida") || Contiene(evento->getEstado(), "No tomada")) activas++;
				DateTime fecha = FechaEvento(evento);
				if (!diasConIncidentes->ContainsKey(fecha.Date)) diasConIncidentes->Add(fecha.Date, true);
				String^ tipo = categoria == "Hardware" ? evento->getOrigen() : evento->getMedicamento();
				String^ descripcion = String::IsNullOrWhiteSpace(evento->getDetalle()) ? tipo : evento->getDetalle();
				int fila = dgvDetalle->Rows->Add(evento->getId(), fecha.ToString("dd/MM/yyyy HH:mm"),
					String::IsNullOrWhiteSpace(evento->getNombrePaciente()) ? "Sistema MediCheck" : evento->getNombrePaciente(),
					categoria, tipo, descripcion, evento->getEstado());
				dgvDetalle->Rows[fila]->Cells[3]->Style->ForeColor = categoria == "Hardware" ? Color::FromArgb(190, 120, 20) : Color::FromArgb(180, 50, 50);
			}
			int diasPeriodo = Math::Max(1, (dtpHasta->Value.Date - dtpDesde->Value.Date).Days + 1);
			int diasSinIncidentes = Math::Max(0, diasPeriodo - diasConIncidentes->Count);
			lblOmisiones->Text = omisiones.ToString();
			lblHardware->Text = hardware.ToString();
			lblTotal->Text = alertas->Count.ToString();
			lblDias->Text = diasSinIncidentes + " / " + diasPeriodo;

			Series^ serie = chartDistribucion->Series["Categorias"];
			serie->Points->Clear();
			if (omisiones > 0) { int punto = serie->Points->AddXY("Antibiotico", omisiones); serie->Points[punto]->Color = Color::FromArgb(180, 50, 50); }
			if (hardware > 0) { int punto = serie->Points->AddXY("Hardware", hardware); serie->Points[punto]->Color = Color::FromArgb(190, 120, 20); }
			serie["DoughnutRadius"] = "55";
			serie->IsValueShownAsLabel = true;

			txtResumen->Text = String::Format(
				"ALERTAS DEL PERIODO\r\n\r\nAlertas criticas registradas: {0}\r\nOmisiones de antibioticos: {1}\r\nFallos de hardware: {2}\r\nAlertas activas o sin resolver: {3}\r\nDias sin incidentes: {4} de {5}",
				alertas->Count, omisiones, hardware, activas, diasSinIncidentes, diasPeriodo);
			txtObservaciones->Text = String::Format(
				"Durante el periodo seleccionado se registraron {0} alertas criticas. Se detectaron {1} omisiones de antibioticos y {2} fallos de hardware. Existen {3} alertas activas o pendientes de atencion. Se recomienda revisar inmediatamente los incumplimientos de medicacion y verificar los componentes reportados por el sistema.",
				alertas->Count, omisiones, hardware, activas);
			lblGenerado->Text = "Generado: " + DateTime::Now.ToString("dd/MM/yyyy HH:mm");
			dgvDetalle->ClearSelection();
		}

		void Ajustar() {
			chartDistribucion->Dock = DockStyle::None;
			dgvDetalle->Dock = DockStyle::None;
			chartDistribucion->Bounds = grpDistribucion->DisplayRectangle;
			dgvDetalle->Bounds = grpDetalle->DisplayRectangle;
			AnchorStyles anclaje = AnchorStyles::Top | AnchorStyles::Bottom | AnchorStyles::Left | AnchorStyles::Right;
			chartDistribucion->Anchor = anclaje;
			dgvDetalle->Anchor = anclaje;
			ChartArea^ area = chartDistribucion->ChartAreas["AreaDistribucion"];
			area->Position->Auto = false;
			area->Position->X = 8;
			area->Position->Y = 6;
			area->Position->Width = 84;
			area->Position->Height = 78;
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

			int ySeccionPrincipal =
				yTarjetas +
				this->cardOmisiones->Height +
				espacioVertical;

			int yDetalle =
				ySeccionPrincipal +
				this->grpDistribucion->Height +
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
			int anchoCategoria = 180;
			int anchoEstado = 180;
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

			this->lblCategoriaFiltro->Location =
				System::Drawing::Point(x, 13);
			this->cmbCategoria->Location =
				System::Drawing::Point(x, 40);
			this->cmbCategoria->Width = anchoCategoria;
			x += anchoCategoria + separacionFiltro;

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

			this->btnAplicar->Location =
				System::Drawing::Point(xAplicar, 34);
			this->btnAplicar->Width = anchoBoton;

			this->btnRestablecer->Location =
				System::Drawing::Point(xRestablecer, 34);
			this->btnRestablecer->Width = anchoBoton;

			// Evitar superposición cuando la ventana sea más estrecha
			if (x + anchoEstado + separacionFiltro > xAplicar) {
				this->cmbEstado->Width =
					Math::Max(105, xAplicar - separacionFiltro - x);
			}

			// ?? Cuatro tarjetas ????????????????????????????????????????????????
			array<System::Windows::Forms::Panel^>^ tarjetas = {
				this->cardOmisiones,
				this->cardHardware,
				this->cardTotal,
				this->cardDias
			};

			int separacionTarjetas = 20;
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

			// ?? Gráfico y resumen ??????????????????????????????????????????????
			this->grpDistribucion->Location =
				System::Drawing::Point(margen, ySeccionPrincipal);
			this->grpDistribucion->Width = anchoMitad;

			this->grpResumen->Location =
				System::Drawing::Point(
					margen + anchoMitad + separacion,
					ySeccionPrincipal
				);
			this->grpResumen->Width = anchoMitad;

			// ?? Tabla y observaciones ??????????????????????????????????????????
			this->grpDetalle->Location =
				System::Drawing::Point(margen, yDetalle);
			this->grpDetalle->Width = anchoDisponible;

			this->grpObservaciones->Location =
				System::Drawing::Point(margen, yObservaciones);
			this->grpObservaciones->Width = anchoDisponible;

			Ajustar();
		}

		System::Void frmAlertasCriticas_Resize(
			System::Object^ sender,
			System::EventArgs^ e
		) {
			AjustarDistribucion();
		}

		System::Void frmAlertasCriticas_Load(System::Object^, System::EventArgs^) {
			reportesController = gcnew GeneradorReportesController();
			medicamentoController = gcnew MedicamentoController();
			CargarFiltros();
			Actualizar();
			AjustarDistribucion();
			BeginInvoke(
				gcnew MethodInvoker(
					this,
					&frmAlertasCriticas::AjustarDistribucion
				)
			);
		}

		System::Void btnAplicar_Click(System::Object^, System::EventArgs^) { Actualizar(); }
		System::Void btnRestablecer_Click(System::Object^, System::EventArgs^) { CargarFiltros(); Actualizar(); }
	};
}
