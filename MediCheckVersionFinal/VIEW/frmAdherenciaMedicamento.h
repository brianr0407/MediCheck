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

	public ref class frmAdherenciaMedicamento : public System::Windows::Forms::Form {
	public:
		frmAdherenciaMedicamento() { InitializeComponent(); }

	protected:
		~frmAdherenciaMedicamento() { if (components) delete components; }

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
		System::Windows::Forms::Button^ btnAplicar;
		System::Windows::Forms::Button^ btnRestablecer;

		System::Windows::Forms::Panel^ cardGlobal;
		System::Windows::Forms::Label^ lblCardGlobal;
		System::Windows::Forms::Label^ lblGlobal;
		System::Windows::Forms::Label^ lblGlobalSub;
		System::Windows::Forms::Panel^ cardTomadas;
		System::Windows::Forms::Label^ lblCardTomadas;
		System::Windows::Forms::Label^ lblTomadas;
		System::Windows::Forms::Label^ lblTomadasSub;
		System::Windows::Forms::Panel^ cardOmitidas;
		System::Windows::Forms::Label^ lblCardOmitidas;
		System::Windows::Forms::Label^ lblOmitidas;
		System::Windows::Forms::Label^ lblOmitidasSub;
		System::Windows::Forms::Panel^ cardOptimos;
		System::Windows::Forms::Label^ lblCardOptimos;
		System::Windows::Forms::Label^ lblOptimos;
		System::Windows::Forms::Label^ lblOptimosSub;

		System::Windows::Forms::GroupBox^ grpGrafico;
		System::Windows::Forms::DataVisualization::Charting::Chart^ chartAdherencia;
		System::Windows::Forms::GroupBox^ grpResumen;
		System::Windows::Forms::RichTextBox^ txtResumen;
		System::Windows::Forms::GroupBox^ grpDetalle;
		System::Windows::Forms::DataGridView^ dgvDetalle;
		System::Windows::Forms::DataGridViewTextBoxColumn^ colMedicamento;
		System::Windows::Forms::DataGridViewTextBoxColumn^ colTamano;
		System::Windows::Forms::DataGridViewTextBoxColumn^ colDosis;
		System::Windows::Forms::DataGridViewTextBoxColumn^ colProgramadas;
		System::Windows::Forms::DataGridViewTextBoxColumn^ colTomadas;
		System::Windows::Forms::DataGridViewTextBoxColumn^ colOmitidas;
		System::Windows::Forms::DataGridViewTextBoxColumn^ colPorcentaje;
		System::Windows::Forms::DataGridViewTextBoxColumn^ colEstado;
		System::Windows::Forms::GroupBox^ grpObservaciones;
		System::Windows::Forms::RichTextBox^ txtObservaciones;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void) {
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ areaAdherencia = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Series^ serieAdherencia = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
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
			this->btnAplicar = (gcnew System::Windows::Forms::Button());
			this->btnRestablecer = (gcnew System::Windows::Forms::Button());
			this->cardGlobal = (gcnew System::Windows::Forms::Panel());
			this->lblCardGlobal = (gcnew System::Windows::Forms::Label());
			this->lblGlobal = (gcnew System::Windows::Forms::Label());
			this->lblGlobalSub = (gcnew System::Windows::Forms::Label());
			this->cardTomadas = (gcnew System::Windows::Forms::Panel());
			this->lblCardTomadas = (gcnew System::Windows::Forms::Label());
			this->lblTomadas = (gcnew System::Windows::Forms::Label());
			this->lblTomadasSub = (gcnew System::Windows::Forms::Label());
			this->cardOmitidas = (gcnew System::Windows::Forms::Panel());
			this->lblCardOmitidas = (gcnew System::Windows::Forms::Label());
			this->lblOmitidas = (gcnew System::Windows::Forms::Label());
			this->lblOmitidasSub = (gcnew System::Windows::Forms::Label());
			this->cardOptimos = (gcnew System::Windows::Forms::Panel());
			this->lblCardOptimos = (gcnew System::Windows::Forms::Label());
			this->lblOptimos = (gcnew System::Windows::Forms::Label());
			this->lblOptimosSub = (gcnew System::Windows::Forms::Label());
			this->grpGrafico = (gcnew System::Windows::Forms::GroupBox());
			this->chartAdherencia = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->grpResumen = (gcnew System::Windows::Forms::GroupBox());
			this->txtResumen = (gcnew System::Windows::Forms::RichTextBox());
			this->grpDetalle = (gcnew System::Windows::Forms::GroupBox());
			this->dgvDetalle = (gcnew System::Windows::Forms::DataGridView());
			this->colMedicamento = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colTamano = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colDosis = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colProgramadas = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colTomadas = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colOmitidas = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colPorcentaje = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colEstado = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->grpObservaciones = (gcnew System::Windows::Forms::GroupBox());
			this->txtObservaciones = (gcnew System::Windows::Forms::RichTextBox());
			this->panelCabecera->SuspendLayout();
			this->panelContenido->SuspendLayout();
			this->panelFiltros->SuspendLayout();
			this->cardGlobal->SuspendLayout();
			this->cardTomadas->SuspendLayout();
			this->cardOmitidas->SuspendLayout();
			this->cardOptimos->SuspendLayout();
			this->grpGrafico->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartAdherencia))->BeginInit();
			this->grpResumen->SuspendLayout();
			this->grpDetalle->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvDetalle))->BeginInit();
			this->grpObservaciones->SuspendLayout();
			this->SuspendLayout();

			this->panelCabecera->BackColor = System::Drawing::Color::FromArgb(15, 41, 66);
			this->panelCabecera->Controls->Add(this->lblTitulo); this->panelCabecera->Controls->Add(this->lblSubtitulo); this->panelCabecera->Controls->Add(this->lblGenerado);
			this->panelCabecera->Dock = System::Windows::Forms::DockStyle::Top; this->panelCabecera->Size = System::Drawing::Size(1360, 84);
			this->lblTitulo->AutoSize = true; this->lblTitulo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15, System::Drawing::FontStyle::Regular)); this->lblTitulo->ForeColor = System::Drawing::Color::FromArgb(220, 233, 245); this->lblTitulo->Location = System::Drawing::Point(26, 14); this->lblTitulo->Text = L"Reporte de Adherencia por Medicamento";
			this->lblSubtitulo->AutoSize = true; this->lblSubtitulo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9)); this->lblSubtitulo->ForeColor = System::Drawing::Color::FromArgb(200, 218, 235); this->lblSubtitulo->Location = System::Drawing::Point(27, 50); this->lblSubtitulo->Text = L"Cumplimiento terapeutico individual por farmaco";
			this->lblGenerado->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right)); this->lblGenerado->ForeColor = System::Drawing::Color::White; this->lblGenerado->Location = System::Drawing::Point(1060, 28); this->lblGenerado->Size = System::Drawing::Size(274, 22); this->lblGenerado->Text = L"Generado:"; this->lblGenerado->TextAlign = System::Drawing::ContentAlignment::MiddleRight;

			this->panelContenido->AutoScroll = true; this->panelContenido->BackColor = System::Drawing::Color::FromArgb(241, 244, 248);
			this->panelContenido->Controls->Add(this->panelFiltros); this->panelContenido->Controls->Add(this->cardGlobal); this->panelContenido->Controls->Add(this->cardTomadas); this->panelContenido->Controls->Add(this->cardOmitidas); this->panelContenido->Controls->Add(this->cardOptimos); this->panelContenido->Controls->Add(this->grpGrafico); this->panelContenido->Controls->Add(this->grpResumen); this->panelContenido->Controls->Add(this->grpDetalle); this->panelContenido->Controls->Add(this->grpObservaciones);
			this->panelContenido->Dock = System::Windows::Forms::DockStyle::Fill; this->panelContenido->Location = System::Drawing::Point(0, 84); this->panelContenido->Size = System::Drawing::Size(1360, 676);

			this->panelFiltros->BackColor = System::Drawing::Color::White; this->panelFiltros->Controls->Add(this->lblPacienteFiltro); this->panelFiltros->Controls->Add(this->cmbPaciente); this->panelFiltros->Controls->Add(this->lblDesde); this->panelFiltros->Controls->Add(this->dtpDesde); this->panelFiltros->Controls->Add(this->lblHasta); this->panelFiltros->Controls->Add(this->dtpHasta); this->panelFiltros->Controls->Add(this->lblMedicamentoFiltro); this->panelFiltros->Controls->Add(this->cmbMedicamento); this->panelFiltros->Controls->Add(this->btnAplicar); this->panelFiltros->Controls->Add(this->btnRestablecer); this->panelFiltros->Location = System::Drawing::Point(22, 18); this->panelFiltros->Size = System::Drawing::Size(1300, 104);
			this->lblPacienteFiltro->AutoSize = true; this->lblPacienteFiltro->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold)); this->lblPacienteFiltro->ForeColor = System::Drawing::Color::FromArgb(90, 115, 140); this->lblPacienteFiltro->Location = System::Drawing::Point(16, 13); this->lblPacienteFiltro->Text = L"Paciente";
			this->cmbPaciente->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList; this->cmbPaciente->FlatStyle = System::Windows::Forms::FlatStyle::Flat; this->cmbPaciente->BackColor = System::Drawing::Color::White; this->cmbPaciente->ForeColor = System::Drawing::Color::FromArgb(30, 50, 70); this->cmbPaciente->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F)); this->cmbPaciente->Location = System::Drawing::Point(16, 40); this->cmbPaciente->Size = System::Drawing::Size(230, 24);
			this->lblDesde->AutoSize = true; this->lblDesde->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold)); this->lblDesde->ForeColor = System::Drawing::Color::FromArgb(90, 115, 140); this->lblDesde->Location = System::Drawing::Point(262, 13); this->lblDesde->Text = L"Desde";
			this->dtpDesde->Format = System::Windows::Forms::DateTimePickerFormat::Short; this->dtpDesde->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F)); this->dtpDesde->CalendarForeColor = System::Drawing::Color::FromArgb(30, 50, 70); this->dtpDesde->Location = System::Drawing::Point(262, 40); this->dtpDesde->Size = System::Drawing::Size(135, 22);
			this->lblHasta->AutoSize = true; this->lblHasta->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold)); this->lblHasta->ForeColor = System::Drawing::Color::FromArgb(90, 115, 140); this->lblHasta->Location = System::Drawing::Point(413, 13); this->lblHasta->Text = L"Hasta";
			this->dtpHasta->Format = System::Windows::Forms::DateTimePickerFormat::Short; this->dtpHasta->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F)); this->dtpHasta->CalendarForeColor = System::Drawing::Color::FromArgb(30, 50, 70); this->dtpHasta->Location = System::Drawing::Point(413, 40); this->dtpHasta->Size = System::Drawing::Size(135, 22);
			this->lblMedicamentoFiltro->AutoSize = true; this->lblMedicamentoFiltro->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold)); this->lblMedicamentoFiltro->ForeColor = System::Drawing::Color::FromArgb(90, 115, 140); this->lblMedicamentoFiltro->Location = System::Drawing::Point(564, 13); this->lblMedicamentoFiltro->Text = L"Medicamento";
			this->cmbPaciente->SelectedIndexChanged += gcnew System::EventHandler(this, &frmAdherenciaMedicamento::cmbPaciente_SelectedIndexChanged);
			this->cmbMedicamento->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList; this->cmbMedicamento->FlatStyle = System::Windows::Forms::FlatStyle::Flat; this->cmbMedicamento->BackColor = System::Drawing::Color::White; this->cmbMedicamento->ForeColor = System::Drawing::Color::FromArgb(30, 50, 70); this->cmbMedicamento->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F)); this->cmbMedicamento->Location = System::Drawing::Point(564, 40); this->cmbMedicamento->Size = System::Drawing::Size(230, 24);
			this->btnAplicar->BackColor = System::Drawing::Color::FromArgb(234, 243, 222); this->btnAplicar->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(168, 208, 106); this->btnAplicar->FlatAppearance->BorderSize = 1; this->btnAplicar->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(192, 221, 151); this->btnAplicar->FlatStyle = System::Windows::Forms::FlatStyle::Flat; this->btnAplicar->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F, System::Drawing::FontStyle::Regular)); this->btnAplicar->ForeColor = System::Drawing::Color::FromArgb(39, 80, 10); this->btnAplicar->Cursor = System::Windows::Forms::Cursors::Hand; this->btnAplicar->Location = System::Drawing::Point(818, 34); this->btnAplicar->Size = System::Drawing::Size(205, 36); this->btnAplicar->Text = L"Aplicar filtros"; this->btnAplicar->UseVisualStyleBackColor = false; this->btnAplicar->Click += gcnew System::EventHandler(this, &frmAdherenciaMedicamento::btnAplicar_Click);
			this->btnRestablecer->BackColor = System::Drawing::Color::FromArgb(230, 241, 251); this->btnRestablecer->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(158, 198, 240); this->btnRestablecer->FlatAppearance->BorderSize = 1; this->btnRestablecer->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(181, 212, 244); this->btnRestablecer->FlatStyle = System::Windows::Forms::FlatStyle::Flat; this->btnRestablecer->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F, System::Drawing::FontStyle::Regular)); this->btnRestablecer->ForeColor = System::Drawing::Color::FromArgb(12, 68, 124); this->btnRestablecer->Cursor = System::Windows::Forms::Cursors::Hand; this->btnRestablecer->Location = System::Drawing::Point(1040, 34); this->btnRestablecer->Size = System::Drawing::Size(205, 36); this->btnRestablecer->Text = L"Restablecer"; this->btnRestablecer->UseVisualStyleBackColor = false; this->btnRestablecer->Click += gcnew System::EventHandler(this, &frmAdherenciaMedicamento::btnRestablecer_Click);

			this->cardGlobal->BackColor = System::Drawing::Color::White; this->cardGlobal->Controls->Add(this->lblCardGlobal); this->cardGlobal->Controls->Add(this->lblGlobal); this->cardGlobal->Controls->Add(this->lblGlobalSub); this->cardGlobal->Location = System::Drawing::Point(22, 142); this->cardGlobal->Size = System::Drawing::Size(310, 132);
			this->lblCardGlobal->AutoSize = true; this->lblCardGlobal->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold)); this->lblCardGlobal->ForeColor = System::Drawing::Color::FromArgb(90, 115, 140); this->lblCardGlobal->Location = System::Drawing::Point(16, 16); this->lblCardGlobal->Text = L"Adherencia global";
			this->lblGlobal->AutoSize = true; this->lblGlobal->Font = (gcnew System::Drawing::Font(L"Segoe UI", 20, System::Drawing::FontStyle::Bold)); this->lblGlobal->ForeColor = System::Drawing::Color::FromArgb(20, 125, 95); this->lblGlobal->Location = System::Drawing::Point(16, 45); this->lblGlobal->Text = L"0%";
			this->lblGlobalSub->AutoSize = true; this->lblGlobalSub->ForeColor = System::Drawing::Color::DimGray; this->lblGlobalSub->Location = System::Drawing::Point(18, 92); this->lblGlobalSub->Text = L"meta: >= 80%";
			this->cardTomadas->BackColor = System::Drawing::Color::White; this->cardTomadas->Controls->Add(this->lblCardTomadas); this->cardTomadas->Controls->Add(this->lblTomadas); this->cardTomadas->Controls->Add(this->lblTomadasSub); this->cardTomadas->Location = System::Drawing::Point(352, 142); this->cardTomadas->Size = System::Drawing::Size(310, 132);
			this->lblCardTomadas->AutoSize = true; this->lblCardTomadas->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold)); this->lblCardTomadas->ForeColor = System::Drawing::Color::FromArgb(90, 115, 140); this->lblCardTomadas->Location = System::Drawing::Point(16, 16); this->lblCardTomadas->Text = L"Dosis tomadas";
			this->lblTomadas->AutoSize = true; this->lblTomadas->Font = (gcnew System::Drawing::Font(L"Segoe UI", 20, System::Drawing::FontStyle::Bold)); this->lblTomadas->ForeColor = System::Drawing::Color::FromArgb(20, 125, 95); this->lblTomadas->Location = System::Drawing::Point(16, 45); this->lblTomadas->Text = L"0 / 0";
			this->lblTomadasSub->AutoSize = true; this->lblTomadasSub->ForeColor = System::Drawing::Color::DimGray; this->lblTomadasSub->Location = System::Drawing::Point(18, 92); this->lblTomadasSub->Text = L"cumplidas / programadas";
			this->cardOmitidas->BackColor = System::Drawing::Color::White; this->cardOmitidas->Controls->Add(this->lblCardOmitidas); this->cardOmitidas->Controls->Add(this->lblOmitidas); this->cardOmitidas->Controls->Add(this->lblOmitidasSub); this->cardOmitidas->Location = System::Drawing::Point(682, 142); this->cardOmitidas->Size = System::Drawing::Size(310, 132);
			this->lblCardOmitidas->AutoSize = true; this->lblCardOmitidas->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold)); this->lblCardOmitidas->ForeColor = System::Drawing::Color::FromArgb(90, 115, 140); this->lblCardOmitidas->Location = System::Drawing::Point(16, 16); this->lblCardOmitidas->Text = L"Dosis omitidas";
			this->lblOmitidas->AutoSize = true; this->lblOmitidas->Font = (gcnew System::Drawing::Font(L"Segoe UI", 20, System::Drawing::FontStyle::Bold)); this->lblOmitidas->ForeColor = System::Drawing::Color::FromArgb(180, 50, 50); this->lblOmitidas->Location = System::Drawing::Point(16, 45); this->lblOmitidas->Text = L"0";
			this->lblOmitidasSub->AutoSize = true; this->lblOmitidasSub->ForeColor = System::Drawing::Color::DimGray; this->lblOmitidasSub->Location = System::Drawing::Point(18, 92); this->lblOmitidasSub->Text = L"en el periodo";
			this->cardOptimos->BackColor = System::Drawing::Color::White; this->cardOptimos->Controls->Add(this->lblCardOptimos); this->cardOptimos->Controls->Add(this->lblOptimos); this->cardOptimos->Controls->Add(this->lblOptimosSub); this->cardOptimos->Location = System::Drawing::Point(1012, 142); this->cardOptimos->Size = System::Drawing::Size(310, 132);
			this->lblCardOptimos->AutoSize = true; this->lblCardOptimos->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold)); this->lblCardOptimos->ForeColor = System::Drawing::Color::FromArgb(90, 115, 140); this->lblCardOptimos->Location = System::Drawing::Point(16, 16); this->lblCardOptimos->Text = L"Farmacos en optimo";
			this->lblOptimos->AutoSize = true; this->lblOptimos->Font = (gcnew System::Drawing::Font(L"Segoe UI", 20, System::Drawing::FontStyle::Bold)); this->lblOptimos->ForeColor = System::Drawing::Color::FromArgb(20, 125, 95); this->lblOptimos->Location = System::Drawing::Point(16, 45); this->lblOptimos->Text = L"0 / 0";
			this->lblOptimosSub->AutoSize = true; this->lblOptimosSub->ForeColor = System::Drawing::Color::DimGray; this->lblOptimosSub->Location = System::Drawing::Point(18, 92); this->lblOptimosSub->Text = L"adherencia >= 80%";

			this->grpGrafico->BackColor = System::Drawing::Color::White; this->grpGrafico->Controls->Add(this->chartAdherencia); this->grpGrafico->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular)); this->grpGrafico->Location = System::Drawing::Point(22, 296); this->grpGrafico->Size = System::Drawing::Size(840, 380); this->grpGrafico->Text = L"Adherencia por medicamento";
			areaAdherencia->Name = L"AreaAdherencia"; this->chartAdherencia->ChartAreas->Add(areaAdherencia); this->chartAdherencia->Dock = System::Windows::Forms::DockStyle::Fill; serieAdherencia->ChartArea = L"AreaAdherencia"; serieAdherencia->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Bar; serieAdherencia->IsValueShownAsLabel = true; serieAdherencia->LabelFormat = L"0'%'"; serieAdherencia->Name = L"Adherencia"; serieAdherencia->Color = System::Drawing::Color::FromArgb(29, 158, 117); this->chartAdherencia->Series->Add(serieAdherencia);
			this->grpResumen->BackColor = System::Drawing::Color::White; this->grpResumen->Controls->Add(this->txtResumen); this->grpResumen->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular)); this->grpResumen->Location = System::Drawing::Point(882, 296); this->grpResumen->Size = System::Drawing::Size(440, 380); this->grpResumen->Text = L"Resumen del periodo";
			this->txtResumen->BackColor = System::Drawing::Color::FromArgb(247, 249, 251); this->txtResumen->BorderStyle = System::Windows::Forms::BorderStyle::None; this->txtResumen->Dock = System::Windows::Forms::DockStyle::Fill; this->txtResumen->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10)); this->txtResumen->ForeColor = System::Drawing::Color::FromArgb(40, 60, 80); this->txtResumen->ReadOnly = true;

			this->grpDetalle->BackColor = System::Drawing::Color::White; this->grpDetalle->Controls->Add(this->dgvDetalle); this->grpDetalle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular)); this->grpDetalle->Location = System::Drawing::Point(22, 698); this->grpDetalle->Size = System::Drawing::Size(1300, 350); this->grpDetalle->Text = L"Detalle de adherencia por medicamento";
			this->dgvDetalle->AllowUserToAddRows = false; this->dgvDetalle->AllowUserToDeleteRows = false; this->dgvDetalle->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill; this->dgvDetalle->BackgroundColor = System::Drawing::Color::FromArgb(247, 249, 251); this->dgvDetalle->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::SingleHorizontal; this->dgvDetalle->GridColor = System::Drawing::Color::FromArgb(220, 230, 240); this->dgvDetalle->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None; this->dgvDetalle->EnableHeadersVisualStyles = false; this->dgvDetalle->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing; this->dgvDetalle->ColumnHeadersHeight = 36; this->dgvDetalle->ColumnHeadersDefaultCellStyle->BackColor = System::Drawing::Color::FromArgb(36, 66, 98); this->dgvDetalle->ColumnHeadersDefaultCellStyle->ForeColor = System::Drawing::Color::FromArgb(200, 218, 235); this->dgvDetalle->ColumnHeadersDefaultCellStyle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.5F, System::Drawing::FontStyle::Regular)); this->dgvDetalle->ColumnHeadersDefaultCellStyle->SelectionBackColor = System::Drawing::Color::FromArgb(36, 66, 98); this->dgvDetalle->ColumnHeadersDefaultCellStyle->SelectionForeColor = System::Drawing::Color::FromArgb(200, 218, 235); this->dgvDetalle->DefaultCellStyle->BackColor = System::Drawing::Color::White; this->dgvDetalle->DefaultCellStyle->ForeColor = System::Drawing::Color::FromArgb(40, 60, 80); this->dgvDetalle->DefaultCellStyle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F)); this->dgvDetalle->DefaultCellStyle->SelectionBackColor = System::Drawing::Color::FromArgb(210, 228, 248); this->dgvDetalle->DefaultCellStyle->SelectionForeColor = System::Drawing::Color::FromArgb(12, 52, 100); this->dgvDetalle->RowTemplate->Height = 32; this->dgvDetalle->BorderStyle = System::Windows::Forms::BorderStyle::None; this->dgvDetalle->Columns->AddRange(gcnew cli::array<System::Windows::Forms::DataGridViewColumn^>(8) { this->colMedicamento, this->colTamano, this->colDosis, this->colProgramadas, this->colTomadas, this->colOmitidas, this->colPorcentaje, this->colEstado }); this->dgvDetalle->Dock = System::Windows::Forms::DockStyle::Fill; this->dgvDetalle->ReadOnly = true; this->dgvDetalle->RowHeadersVisible = false; this->dgvDetalle->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->colMedicamento->HeaderText = L"Medicamento"; this->colMedicamento->FillWeight = 140; this->colMedicamento->ReadOnly = true; this->colTamano->HeaderText = L"Tamano"; this->colTamano->FillWeight = 80; this->colTamano->ReadOnly = true; this->colDosis->HeaderText = L"Dosis/dia"; this->colDosis->FillWeight = 70; this->colDosis->ReadOnly = true; this->colProgramadas->HeaderText = L"Programadas"; this->colProgramadas->FillWeight = 80; this->colProgramadas->ReadOnly = true; this->colTomadas->HeaderText = L"Tomadas"; this->colTomadas->FillWeight = 75; this->colTomadas->ReadOnly = true; this->colOmitidas->HeaderText = L"Omitidas"; this->colOmitidas->FillWeight = 75; this->colOmitidas->ReadOnly = true; this->colPorcentaje->HeaderText = L"% Adherencia"; this->colPorcentaje->FillWeight = 85; this->colPorcentaje->ReadOnly = true; this->colEstado->HeaderText = L"Estado"; this->colEstado->FillWeight = 80; this->colEstado->ReadOnly = true;
			this->grpObservaciones->BackColor = System::Drawing::Color::White; this->grpObservaciones->Controls->Add(this->txtObservaciones); this->grpObservaciones->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular)); this->grpObservaciones->Location = System::Drawing::Point(22, 1070); this->grpObservaciones->Size = System::Drawing::Size(1300, 190); this->grpObservaciones->Text = L"Observaciones automaticas";
			this->txtObservaciones->BackColor = System::Drawing::Color::FromArgb(247, 249, 251); this->txtObservaciones->BorderStyle = System::Windows::Forms::BorderStyle::None; this->txtObservaciones->Dock = System::Windows::Forms::DockStyle::Fill; this->txtObservaciones->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10)); this->txtObservaciones->ReadOnly = true;

			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16); this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font; this->BackColor = System::Drawing::Color::FromArgb(241, 244, 248); this->ClientSize = System::Drawing::Size(1360, 760); this->ControlBox = false; this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None; this->Controls->Add(this->panelContenido); this->Controls->Add(this->panelCabecera); this->Name = L"frmAdherenciaMedicamento"; this->Text = L""; this->Load += gcnew System::EventHandler(this, &frmAdherenciaMedicamento::frmAdherenciaMedicamento_Load); this->Resize += gcnew System::EventHandler(this, &frmAdherenciaMedicamento::frmAdherenciaMedicamento_Resize);
			this->panelCabecera->ResumeLayout(false); this->panelCabecera->PerformLayout(); this->panelContenido->ResumeLayout(false); this->panelFiltros->ResumeLayout(false); this->panelFiltros->PerformLayout();
			this->cardGlobal->ResumeLayout(false); this->cardGlobal->PerformLayout(); this->cardTomadas->ResumeLayout(false); this->cardTomadas->PerformLayout(); this->cardOmitidas->ResumeLayout(false); this->cardOmitidas->PerformLayout(); this->cardOptimos->ResumeLayout(false); this->cardOptimos->PerformLayout();
			this->grpGrafico->ResumeLayout(false); (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartAdherencia))->EndInit(); this->grpResumen->ResumeLayout(false); this->grpDetalle->ResumeLayout(false); (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvDetalle))->EndInit(); this->grpObservaciones->ResumeLayout(false); this->ResumeLayout(false);
		}
#pragma endregion

	private:
		bool Contiene(String^ texto, String^ valor) {
			return !String::IsNullOrWhiteSpace(texto) && texto->IndexOf(valor, StringComparison::OrdinalIgnoreCase) >= 0;
		}

		bool EsEventoDosis(LogEvento^ evento) {
			return evento != nullptr && (Contiene(evento->getTipoEvento(), "Toma") || Contiene(evento->getTipoEvento(), "Dosis"));
		}

		bool EsTomada(LogEvento^ evento) {
			return evento != nullptr && (Contiene(evento->getEstado(), "Tomada") || Contiene(evento->getEstado(), "Retraso"));
		}

		int ObtenerIdSeleccionado(ComboBox^ combo) {
			if (combo->SelectedIndex <= 0 || combo->SelectedItem == nullptr) return 0;
			String^ valor = combo->SelectedItem->ToString();
			int separador = valor->IndexOf(" - ");
			int id = 0;
			return separador > 0 && Int32::TryParse(valor->Substring(0, separador), id) ? id : 0;
		}

		String^ Clasificar(double porcentaje) {
			if (porcentaje >= 80.0) return "Optimo";
			if (porcentaje >= 60.0) return "Parcial";
			return "Bajo";
		}

		List<LogEvento^>^ Filtrar() {
			List<LogEvento^>^ resultado = gcnew List<LogEvento^>();
			int paciente = ObtenerIdSeleccionado(cmbPaciente);
			int medicamento = ObtenerIdSeleccionado(cmbMedicamento);
			if (paciente == 0) return resultado;
			for each(LogEvento ^ evento in reportesController->ObtenerTodos()) {
				if (!EsEventoDosis(evento) || evento->getIdPaciente() != paciente) continue;
				if (medicamento > 0 && evento->getIdMedicamento() != medicamento) continue;
				DateTime fecha = evento->getFechaHoraProgramada();
				if (fecha == DateTime::MinValue || fecha.Date < dtpDesde->Value.Date || fecha.Date > dtpHasta->Value.Date) continue;
				resultado->Add(evento);
			}
			return resultado;
		}

		void CargarFiltros() {
			SortedDictionary<int, String^>^ pacientes = gcnew SortedDictionary<int, String^>();
			SortedDictionary<int, String^>^ medicamentos = gcnew SortedDictionary<int, String^>();
			DateTime minimo = DateTime::MaxValue, maximo = DateTime::MinValue;
			for each(LogEvento ^ evento in reportesController->ObtenerTodos()) {
				if (!EsEventoDosis(evento)) continue;
				if (evento->getIdPaciente() > 0 && !pacientes->ContainsKey(evento->getIdPaciente())) pacientes->Add(evento->getIdPaciente(), evento->getNombrePaciente());
				if (evento->getIdMedicamento() > 0 && !medicamentos->ContainsKey(evento->getIdMedicamento())) medicamentos->Add(evento->getIdMedicamento(), evento->getMedicamento());
				if (evento->getFechaHoraProgramada() != DateTime::MinValue && evento->getFechaHoraProgramada() < minimo) minimo = evento->getFechaHoraProgramada();
				if (evento->getFechaHoraProgramada() != DateTime::MinValue && evento->getFechaHoraProgramada() > maximo) maximo = evento->getFechaHoraProgramada();
			}
			cmbPaciente->Items->Clear(); cmbPaciente->Items->Add("Seleccione un paciente"); for each(KeyValuePair<int, String^> x in pacientes) cmbPaciente->Items->Add(x.Key + " - " + x.Value); cmbPaciente->SelectedIndex = pacientes->Count > 0 ? 1 : 0;
			cmbMedicamento->Items->Clear(); cmbMedicamento->Items->Add("Todos los medicamentos"); for each(KeyValuePair<int, String^> x in medicamentos) cmbMedicamento->Items->Add(x.Key + " - " + x.Value); cmbMedicamento->SelectedIndex = 0;
			dtpDesde->Value = minimo == DateTime::MaxValue ? DateTime::Today.AddDays(-30) : minimo.Date;
			dtpHasta->Value = maximo == DateTime::MinValue ? DateTime::Today : maximo.Date;
		}

		void Limpiar() {
			lblGlobal->Text = "0%"; lblTomadas->Text = "0 / 0"; lblOmitidas->Text = "0"; lblOptimos->Text = "0 / 0";
			chartAdherencia->Series["Adherencia"]->Points->Clear(); dgvDetalle->Rows->Clear();
			txtResumen->Text = "Seleccione un paciente para visualizar su reporte individual.";
			txtObservaciones->Text = "El reporte calcula la adherencia a partir de los eventos de toma registrados.";
		}

		void Actualizar() {
			if (ObtenerIdSeleccionado(cmbPaciente) == 0) { Limpiar(); return; }
			List<LogEvento^>^ eventos = Filtrar();
			List<Receta^>^ recetas = recetaController->ObtenerTodosRecetasTXT();
			Dictionary<int, array<int>^>^ cantidades = gcnew Dictionary<int, array<int>^>();
			Dictionary<int, String^>^ nombres = gcnew Dictionary<int, String^>();
			for each(LogEvento ^ evento in eventos) {
				int id = evento->getIdMedicamento();
				if (!cantidades->ContainsKey(id)) { cantidades->Add(id, gcnew array<int>(2)); nombres->Add(id, String::IsNullOrWhiteSpace(evento->getMedicamento()) ? "Sin medicamento" : evento->getMedicamento()); }
				array<int>^ arr = cantidades[id]; arr[0]++;
				if (EsTomada(evento)) arr[1]++;
			}

			int total = eventos->Count, tomadas = 0, optimos = 0;
			for each(KeyValuePair<int, array<int>^> x in cantidades) tomadas += x.Value[1];
			int omitidas = total - tomadas;
			double global = total == 0 ? 0.0 : tomadas * 100.0 / total;
			lblGlobal->Text = String::Format("{0:F0}%", global); lblGlobal->ForeColor = global >= 80.0 ? Color::FromArgb(20, 125, 95) : global >= 60.0 ? Color::FromArgb(190, 120, 20) : Color::FromArgb(180, 50, 50);
			lblTomadas->Text = tomadas + " / " + total; lblOmitidas->Text = omitidas.ToString();

			Series^ serie = chartAdherencia->Series["Adherencia"]; serie->Points->Clear(); serie["PointWidth"] = "0.55"; dgvDetalle->Rows->Clear();
			String^ peor = ""; double peorValor = 101.0; String^ mejor = ""; double mejorValor = -1.0;
			for each(KeyValuePair<int, array<int>^> x in cantidades) {
				int programadas = x.Value[0], cumplidas = x.Value[1], noCumplidas = programadas - cumplidas;
				double porcentaje = programadas == 0 ? 0.0 : cumplidas * 100.0 / programadas;
				String^ estado = Clasificar(porcentaje); if (estado == "Optimo") optimos++;
				int punto = serie->Points->AddXY(nombres[x.Key], porcentaje);
				serie->Points[punto]->Color = estado == "Optimo" ? Color::FromArgb(91, 154, 31) : estado == "Parcial" ? Color::FromArgb(239, 159, 39) : Color::FromArgb(232, 73, 73);
				int dosis = 0; String^ tamano = "-";
				for each(Receta ^ receta in recetas) if (receta->getIdPaciente() == ObtenerIdSeleccionado(cmbPaciente) && receta->getMedicamento() != nullptr && receta->getMedicamento()->getId() == x.Key) { dosis += receta->getDosisDiaria(); tamano = receta->getMedicamento()->getTamano(); }
				int fila = dgvDetalle->Rows->Add(nombres[x.Key], tamano, dosis + "x/dia", programadas, cumplidas, noCumplidas, String::Format("{0:F0}%", porcentaje), estado);
				dgvDetalle->Rows[fila]->Cells[4]->Style->ForeColor = Color::FromArgb(20, 125, 95); dgvDetalle->Rows[fila]->Cells[5]->Style->ForeColor = Color::FromArgb(180, 50, 50); dgvDetalle->Rows[fila]->Cells[7]->Style->ForeColor = serie->Points[punto]->Color;
				if (porcentaje < peorValor) { peorValor = porcentaje; peor = nombres[x.Key]; } if (porcentaje > mejorValor) { mejorValor = porcentaje; mejor = nombres[x.Key]; }
			}
			lblOptimos->Text = optimos + " / " + cantidades->Count; dgvDetalle->ClearSelection();
			txtResumen->Text = String::Format("PACIENTE\r\n{0}\r\n\r\nPERIODO\r\n{1} - {2}\r\n\r\nREFERENCIA\r\nOptimo: >= 80%\r\nParcial: 60% - 79%\r\nBajo: < 60%\r\n\r\nMEDICAMENTOS EVALUADOS\r\n{3}", cmbPaciente->SelectedItem, dtpDesde->Value.ToString("dd/MM/yyyy"), dtpHasta->Value.ToString("dd/MM/yyyy"), cantidades->Count);
			if (total == 0) txtObservaciones->Text = "No existen eventos de toma para el paciente y los filtros seleccionados.";
			else {
				StringBuilder^ texto = gcnew StringBuilder();
				texto->AppendFormat("El paciente presenta una adherencia global de {0:F1}% ({1} de {2} dosis tomadas). ", global, tomadas, total);
				if (!String::IsNullOrWhiteSpace(mejor)) texto->AppendFormat("El medicamento con mejor adherencia fue {0} ({1:F1}%). ", mejor, mejorValor);
				if (!String::IsNullOrWhiteSpace(peor)) texto->AppendFormat("El medicamento con menor adherencia fue {0} ({1:F1}%). ", peor, peorValor);
				texto->Append(global >= 80.0 ? "La adherencia global alcanza la meta recomendada." : "Se recomienda revisar las causas de las dosis omitidas y reforzar los recordatorios.");
				txtObservaciones->Text = texto->ToString();
			}
			lblGenerado->Text = "Generado: " + DateTime::Now.ToString("dd/MM/yyyy HH:mm");
		}

		void Ajustar() {
			chartAdherencia->Dock = DockStyle::None; dgvDetalle->Dock = DockStyle::None;
			chartAdherencia->Bounds = grpGrafico->DisplayRectangle; dgvDetalle->Bounds = grpDetalle->DisplayRectangle;
			AnchorStyles anclas = AnchorStyles::Top | AnchorStyles::Bottom | AnchorStyles::Left | AnchorStyles::Right; chartAdherencia->Anchor = anclas; dgvDetalle->Anchor = anclas;
			ChartArea^ area = chartAdherencia->ChartAreas["AreaAdherencia"];
			area->AxisX->Minimum = Double::NaN;
			area->AxisX->Maximum = Double::NaN;
			area->AxisX->Interval = 1;
			area->AxisY->Minimum = 0;
			area->AxisY->Maximum = 100;
			area->AxisY->Interval = 20;
			area->AxisY->LabelStyle->Format = "0'%'";
			area->Position->Auto = false; area->Position->X = 8; area->Position->Y = 8; area->Position->Width = 88; area->Position->Height = 84;
		}


		void AjustarDistribucion() {
			int margen = 22;
			int separacionHorizontal = 20;
			int espacioVertical = 18;

			int anchoDisponible =
				this->panelContenido->ClientSize.Width - (margen * 2);

			if (anchoDisponible < 900)
				anchoDisponible = 900;

			// Posiciones verticales calculadas automáticamente
			int yFiltros = 18;

			int yTarjetas =
				yFiltros +
				this->panelFiltros->Height +
				espacioVertical;

			int ySeccionPrincipal =
				yTarjetas +
				this->cardGlobal->Height +
				espacioVertical;

			int yDetalle =
				ySeccionPrincipal +
				this->grpGrafico->Height +
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
			int anchoPaciente = 230;
			int anchoFecha = 140;
			int anchoMedicamento = 230;
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

			this->btnAplicar->Location =
				System::Drawing::Point(xAplicar, 34);
			this->btnAplicar->Width = anchoBoton;

			this->btnRestablecer->Location =
				System::Drawing::Point(xRestablecer, 34);
			this->btnRestablecer->Width = anchoBoton;

			if (x + anchoMedicamento + separacionFiltro > xAplicar) {
				this->cmbMedicamento->Width =
					Math::Max(120, xAplicar - separacionFiltro - x);
			}

			// Cuatro tarjetas distribuidas en todo el ancho
			array<System::Windows::Forms::Panel^>^ tarjetas = {
				this->cardGlobal,
				this->cardTomadas,
				this->cardOmitidas,
				this->cardOptimos
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

			// Gráfico y resumen: 65% / 35%
			int anchoGrafico =
				(int)((anchoDisponible - separacionHorizontal) * 0.65);

			int anchoResumen =
				anchoDisponible -
				anchoGrafico -
				separacionHorizontal;

			this->grpGrafico->Location =
				System::Drawing::Point(margen, ySeccionPrincipal);
			this->grpGrafico->Width = anchoGrafico;

			this->grpResumen->Location =
				System::Drawing::Point(
					margen + anchoGrafico + separacionHorizontal,
					ySeccionPrincipal
				);
			this->grpResumen->Width = anchoResumen;

			// Tabla y observaciones a todo el ancho
			this->grpDetalle->Location =
				System::Drawing::Point(margen, yDetalle);
			this->grpDetalle->Width = anchoDisponible;

			this->grpObservaciones->Location =
				System::Drawing::Point(margen, yObservaciones);
			this->grpObservaciones->Width = anchoDisponible;

			Ajustar();
		}

		System::Void frmAdherenciaMedicamento_Resize(
			System::Object^ sender,
			System::EventArgs^ e
		) {
			AjustarDistribucion();
		}

		System::Void frmAdherenciaMedicamento_Load(System::Object^, System::EventArgs^) {
			reportesController = gcnew GeneradorReportesController();
			recetaController = gcnew RecetaController();
			CargarFiltros();
			Actualizar();
			AjustarDistribucion();
			BeginInvoke(
				gcnew MethodInvoker(
					this,
					&frmAdherenciaMedicamento::AjustarDistribucion
				)
			);
		}

		System::Void btnAplicar_Click(System::Object^, System::EventArgs^) {
			if (ObtenerIdSeleccionado(cmbPaciente) == 0) { MessageBox::Show("Seleccione un paciente para generar el reporte individual.", "Adherencia por Medicamento", MessageBoxButtons::OK, MessageBoxIcon::Information); return; }
			if (dtpDesde->Value.Date > dtpHasta->Value.Date) { MessageBox::Show("La fecha inicial no puede ser posterior a la fecha final.", "Adherencia por Medicamento", MessageBoxButtons::OK, MessageBoxIcon::Warning); return; }
			Actualizar();
		}

		System::Void btnRestablecer_Click(System::Object^, System::EventArgs^) { CargarFiltros(); Actualizar(); }

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
