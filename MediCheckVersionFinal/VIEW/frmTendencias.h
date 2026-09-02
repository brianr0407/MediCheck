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

	public ref class frmTendencias : public System::Windows::Forms::Form {
	public:
		frmTendencias() { InitializeComponent(); }
	protected:
		~frmTendencias() { if (components) delete components; }

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
		System::Windows::Forms::Button^ btnAplicar;
		System::Windows::Forms::Button^ btnRestablecer;
		System::Windows::Forms::Panel^ cardMensual;
		System::Windows::Forms::Label^ lblCardMensual;
		System::Windows::Forms::Label^ lblMensual;
		System::Windows::Forms::Label^ lblMensualSub;
		System::Windows::Forms::Panel^ cardMejor;
		System::Windows::Forms::Label^ lblCardMejor;
		System::Windows::Forms::Label^ lblMejor;
		System::Windows::Forms::Label^ lblMejorSub;
		System::Windows::Forms::Panel^ cardCritica;
		System::Windows::Forms::Label^ lblCardCritica;
		System::Windows::Forms::Label^ lblCritica;
		System::Windows::Forms::Label^ lblCriticaSub;
		System::Windows::Forms::Panel^ cardVariacion;
		System::Windows::Forms::Label^ lblCardVariacion;
		System::Windows::Forms::Label^ lblVariacion;
		System::Windows::Forms::Label^ lblVariacionSub;
		System::Windows::Forms::GroupBox^ grpEvolucion;
		System::Windows::Forms::DataVisualization::Charting::Chart^ chartEvolucion;
		System::Windows::Forms::GroupBox^ grpDosis;
		System::Windows::Forms::DataVisualization::Charting::Chart^ chartDosis;
		System::Windows::Forms::GroupBox^ grpMedicamentos;
		System::Windows::Forms::DataVisualization::Charting::Chart^ chartMedicamentos;
		System::Windows::Forms::GroupBox^ grpDetalle;
		System::Windows::Forms::DataGridView^ dgvDetalle;
		System::Windows::Forms::DataGridViewTextBoxColumn^ colSemana;
		System::Windows::Forms::DataGridViewTextBoxColumn^ colPeriodo;
		System::Windows::Forms::DataGridViewTextBoxColumn^ colProgramadas;
		System::Windows::Forms::DataGridViewTextBoxColumn^ colTomadas;
		System::Windows::Forms::DataGridViewTextBoxColumn^ colOmitidas;
		System::Windows::Forms::DataGridViewTextBoxColumn^ colCumplimiento;
		System::Windows::Forms::DataGridViewTextBoxColumn^ colVariacion;
		System::Windows::Forms::GroupBox^ grpReporte;
		System::Windows::Forms::RichTextBox^ txtReporte;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void) {
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ areaEvolucion = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ leyendaEvolucion = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ serieCumplimiento = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ serieMeta = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ areaDosis = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ leyendaDosis = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ serieTomadas = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ serieOmitidas = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ areaMedicamentos = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ leyendaMedicamentos = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			this->panelCabecera = (gcnew System::Windows::Forms::Panel()); this->lblTitulo = (gcnew System::Windows::Forms::Label()); this->lblSubtitulo = (gcnew System::Windows::Forms::Label()); this->lblGenerado = (gcnew System::Windows::Forms::Label());
			this->panelContenido = (gcnew System::Windows::Forms::Panel()); this->panelFiltros = (gcnew System::Windows::Forms::Panel()); this->lblPacienteFiltro = (gcnew System::Windows::Forms::Label()); this->cmbPaciente = (gcnew System::Windows::Forms::ComboBox()); this->lblDesde = (gcnew System::Windows::Forms::Label()); this->dtpDesde = (gcnew System::Windows::Forms::DateTimePicker()); this->lblHasta = (gcnew System::Windows::Forms::Label()); this->dtpHasta = (gcnew System::Windows::Forms::DateTimePicker()); this->lblMedicamentoFiltro = (gcnew System::Windows::Forms::Label()); this->cmbMedicamento = (gcnew System::Windows::Forms::ComboBox()); this->btnAplicar = (gcnew System::Windows::Forms::Button()); this->btnRestablecer = (gcnew System::Windows::Forms::Button());
			this->cardMensual = (gcnew System::Windows::Forms::Panel()); this->lblCardMensual = (gcnew System::Windows::Forms::Label()); this->lblMensual = (gcnew System::Windows::Forms::Label()); this->lblMensualSub = (gcnew System::Windows::Forms::Label());
			this->cardMejor = (gcnew System::Windows::Forms::Panel()); this->lblCardMejor = (gcnew System::Windows::Forms::Label()); this->lblMejor = (gcnew System::Windows::Forms::Label()); this->lblMejorSub = (gcnew System::Windows::Forms::Label());
			this->cardCritica = (gcnew System::Windows::Forms::Panel()); this->lblCardCritica = (gcnew System::Windows::Forms::Label()); this->lblCritica = (gcnew System::Windows::Forms::Label()); this->lblCriticaSub = (gcnew System::Windows::Forms::Label());
			this->cardVariacion = (gcnew System::Windows::Forms::Panel()); this->lblCardVariacion = (gcnew System::Windows::Forms::Label()); this->lblVariacion = (gcnew System::Windows::Forms::Label()); this->lblVariacionSub = (gcnew System::Windows::Forms::Label());
			this->grpEvolucion = (gcnew System::Windows::Forms::GroupBox()); this->chartEvolucion = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart()); this->grpDosis = (gcnew System::Windows::Forms::GroupBox()); this->chartDosis = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart()); this->grpMedicamentos = (gcnew System::Windows::Forms::GroupBox()); this->chartMedicamentos = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->grpDetalle = (gcnew System::Windows::Forms::GroupBox()); this->dgvDetalle = (gcnew System::Windows::Forms::DataGridView()); this->colSemana = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn()); this->colPeriodo = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn()); this->colProgramadas = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn()); this->colTomadas = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn()); this->colOmitidas = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn()); this->colCumplimiento = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn()); this->colVariacion = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn()); this->grpReporte = (gcnew System::Windows::Forms::GroupBox()); this->txtReporte = (gcnew System::Windows::Forms::RichTextBox());
			this->panelCabecera->SuspendLayout(); this->panelContenido->SuspendLayout(); this->panelFiltros->SuspendLayout(); this->cardMensual->SuspendLayout(); this->cardMejor->SuspendLayout(); this->cardCritica->SuspendLayout(); this->cardVariacion->SuspendLayout(); this->grpEvolucion->SuspendLayout(); (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartEvolucion))->BeginInit(); this->grpDosis->SuspendLayout(); (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartDosis))->BeginInit(); this->grpMedicamentos->SuspendLayout(); (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartMedicamentos))->BeginInit(); this->grpDetalle->SuspendLayout(); (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvDetalle))->BeginInit(); this->grpReporte->SuspendLayout(); this->SuspendLayout();

			this->panelCabecera->BackColor = System::Drawing::Color::FromArgb(15, 41, 66); this->panelCabecera->Controls->Add(this->lblTitulo); this->panelCabecera->Controls->Add(this->lblSubtitulo); this->panelCabecera->Controls->Add(this->lblGenerado); this->panelCabecera->Dock = System::Windows::Forms::DockStyle::Top; this->panelCabecera->Size = System::Drawing::Size(1360, 84);
			this->lblTitulo->AutoSize = true; this->lblTitulo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15, System::Drawing::FontStyle::Regular)); this->lblTitulo->ForeColor = System::Drawing::Color::FromArgb(220, 233, 245); this->lblTitulo->Location = System::Drawing::Point(26, 14); this->lblTitulo->Text = L"Reporte de Tendencias de Cumplimiento";
			this->lblSubtitulo->AutoSize = true; this->lblSubtitulo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9)); this->lblSubtitulo->ForeColor = System::Drawing::Color::FromArgb(200, 218, 235); this->lblSubtitulo->Location = System::Drawing::Point(27, 50); this->lblSubtitulo->Text = L"Evolucion mensual del cumplimiento semana a semana";
			this->lblGenerado->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right)); this->lblGenerado->ForeColor = System::Drawing::Color::White; this->lblGenerado->Location = System::Drawing::Point(1060, 28); this->lblGenerado->Size = System::Drawing::Size(274, 22); this->lblGenerado->Text = L"Generado:"; this->lblGenerado->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->panelContenido->AutoScroll = true; this->panelContenido->BackColor = System::Drawing::Color::FromArgb(241, 244, 248); this->panelContenido->Controls->Add(this->panelFiltros); this->panelContenido->Controls->Add(this->cardMensual); this->panelContenido->Controls->Add(this->cardMejor); this->panelContenido->Controls->Add(this->cardCritica); this->panelContenido->Controls->Add(this->cardVariacion); this->panelContenido->Controls->Add(this->grpEvolucion); this->panelContenido->Controls->Add(this->grpDosis); this->panelContenido->Controls->Add(this->grpMedicamentos); this->panelContenido->Controls->Add(this->grpDetalle); this->panelContenido->Controls->Add(this->grpReporte); this->panelContenido->Dock = System::Windows::Forms::DockStyle::Fill; this->panelContenido->Location = System::Drawing::Point(0, 84); this->panelContenido->Size = System::Drawing::Size(1360, 676);

			this->panelFiltros->BackColor = System::Drawing::Color::White; this->panelFiltros->Controls->Add(this->lblPacienteFiltro); this->panelFiltros->Controls->Add(this->cmbPaciente); this->panelFiltros->Controls->Add(this->lblDesde); this->panelFiltros->Controls->Add(this->dtpDesde); this->panelFiltros->Controls->Add(this->lblHasta); this->panelFiltros->Controls->Add(this->dtpHasta); this->panelFiltros->Controls->Add(this->lblMedicamentoFiltro); this->panelFiltros->Controls->Add(this->cmbMedicamento); this->panelFiltros->Controls->Add(this->btnAplicar); this->panelFiltros->Controls->Add(this->btnRestablecer); this->panelFiltros->Location = System::Drawing::Point(22, 18); this->panelFiltros->Size = System::Drawing::Size(1300, 104);
			this->lblPacienteFiltro->AutoSize = true; this->lblPacienteFiltro->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold)); this->lblPacienteFiltro->ForeColor = System::Drawing::Color::FromArgb(90, 115, 140); this->lblPacienteFiltro->Location = System::Drawing::Point(16, 13); this->lblPacienteFiltro->Text = L"Paciente";
			this->cmbPaciente->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList; this->cmbPaciente->FlatStyle = System::Windows::Forms::FlatStyle::Flat; this->cmbPaciente->BackColor = System::Drawing::Color::White; this->cmbPaciente->ForeColor = System::Drawing::Color::FromArgb(30, 50, 70); this->cmbPaciente->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F)); this->cmbPaciente->Location = System::Drawing::Point(16, 40); this->cmbPaciente->Size = System::Drawing::Size(230, 24);
			this->lblDesde->AutoSize = true; this->lblDesde->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold)); this->lblDesde->ForeColor = System::Drawing::Color::FromArgb(90, 115, 140); this->lblDesde->Location = System::Drawing::Point(262, 13); this->lblDesde->Text = L"Desde"; this->dtpDesde->Format = System::Windows::Forms::DateTimePickerFormat::Short; this->dtpDesde->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F)); this->dtpDesde->CalendarForeColor = System::Drawing::Color::FromArgb(30, 50, 70); this->dtpDesde->Location = System::Drawing::Point(262, 40); this->dtpDesde->Size = System::Drawing::Size(135, 22);
			this->lblHasta->AutoSize = true; this->lblHasta->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold)); this->lblHasta->ForeColor = System::Drawing::Color::FromArgb(90, 115, 140); this->lblHasta->Location = System::Drawing::Point(413, 13); this->lblHasta->Text = L"Hasta"; this->dtpHasta->Format = System::Windows::Forms::DateTimePickerFormat::Short; this->dtpHasta->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F)); this->dtpHasta->CalendarForeColor = System::Drawing::Color::FromArgb(30, 50, 70); this->dtpHasta->Location = System::Drawing::Point(413, 40); this->dtpHasta->Size = System::Drawing::Size(135, 22);
			this->cmbPaciente->SelectedIndexChanged += gcnew System::EventHandler(this, &frmTendencias::cmbPaciente_SelectedIndexChanged);
			this->lblMedicamentoFiltro->AutoSize = true; this->lblMedicamentoFiltro->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold)); this->lblMedicamentoFiltro->ForeColor = System::Drawing::Color::FromArgb(90, 115, 140); this->lblMedicamentoFiltro->Location = System::Drawing::Point(564, 13); this->lblMedicamentoFiltro->Text = L"Medicamento"; this->cmbMedicamento->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList; this->cmbMedicamento->FlatStyle = System::Windows::Forms::FlatStyle::Flat; this->cmbMedicamento->BackColor = System::Drawing::Color::White; this->cmbMedicamento->ForeColor = System::Drawing::Color::FromArgb(30, 50, 70); this->cmbMedicamento->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F)); this->cmbMedicamento->Location = System::Drawing::Point(564, 40); this->cmbMedicamento->Size = System::Drawing::Size(230, 24);
			this->btnAplicar->BackColor = System::Drawing::Color::FromArgb(234, 243, 222); this->btnAplicar->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(168, 208, 106); this->btnAplicar->FlatAppearance->BorderSize = 1; this->btnAplicar->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(192, 221, 151); this->btnAplicar->FlatStyle = System::Windows::Forms::FlatStyle::Flat; this->btnAplicar->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F, System::Drawing::FontStyle::Regular)); this->btnAplicar->ForeColor = System::Drawing::Color::FromArgb(39, 80, 10); this->btnAplicar->Cursor = System::Windows::Forms::Cursors::Hand; this->btnAplicar->Location = System::Drawing::Point(818, 34); this->btnAplicar->Size = System::Drawing::Size(205, 36); this->btnAplicar->Text = L"Aplicar filtros"; this->btnAplicar->UseVisualStyleBackColor = false; this->btnAplicar->Click += gcnew System::EventHandler(this, &frmTendencias::btnAplicar_Click);
			this->btnRestablecer->BackColor = System::Drawing::Color::FromArgb(230, 241, 251); this->btnRestablecer->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(158, 198, 240); this->btnRestablecer->FlatAppearance->BorderSize = 1; this->btnRestablecer->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(181, 212, 244); this->btnRestablecer->FlatStyle = System::Windows::Forms::FlatStyle::Flat; this->btnRestablecer->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F, System::Drawing::FontStyle::Regular)); this->btnRestablecer->ForeColor = System::Drawing::Color::FromArgb(12, 68, 124); this->btnRestablecer->Cursor = System::Windows::Forms::Cursors::Hand; this->btnRestablecer->Location = System::Drawing::Point(1040, 34); this->btnRestablecer->Size = System::Drawing::Size(205, 36); this->btnRestablecer->Text = L"Restablecer"; this->btnRestablecer->UseVisualStyleBackColor = false; this->btnRestablecer->Click += gcnew System::EventHandler(this, &frmTendencias::btnRestablecer_Click);

			this->cardMensual->BackColor = System::Drawing::Color::White; this->cardMensual->Controls->Add(this->lblCardMensual); this->cardMensual->Controls->Add(this->lblMensual); this->cardMensual->Controls->Add(this->lblMensualSub); this->cardMensual->Location = System::Drawing::Point(22, 142); this->cardMensual->Size = System::Drawing::Size(310, 132);
			this->lblCardMensual->AutoSize = true; this->lblCardMensual->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold)); this->lblCardMensual->ForeColor = System::Drawing::Color::FromArgb(90, 115, 140); this->lblCardMensual->Location = System::Drawing::Point(16, 16); this->lblCardMensual->Text = L"Cumplimiento general"; this->lblMensual->AutoSize = true; this->lblMensual->Font = (gcnew System::Drawing::Font(L"Segoe UI", 20, System::Drawing::FontStyle::Bold)); this->lblMensual->ForeColor = System::Drawing::Color::FromArgb(20, 125, 95); this->lblMensual->Location = System::Drawing::Point(16, 45); this->lblMensual->Text = L"0%"; this->lblMensualSub->AutoSize = true; this->lblMensualSub->ForeColor = System::Drawing::Color::DimGray; this->lblMensualSub->Location = System::Drawing::Point(18, 92); this->lblMensualSub->Text = L"meta: >= 80%";
			this->cardMejor->BackColor = System::Drawing::Color::White; this->cardMejor->Controls->Add(this->lblCardMejor); this->cardMejor->Controls->Add(this->lblMejor); this->cardMejor->Controls->Add(this->lblMejorSub); this->cardMejor->Location = System::Drawing::Point(352, 142); this->cardMejor->Size = System::Drawing::Size(310, 132);
			this->lblCardMejor->AutoSize = true; this->lblCardMejor->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold)); this->lblCardMejor->ForeColor = System::Drawing::Color::FromArgb(90, 115, 140); this->lblCardMejor->Location = System::Drawing::Point(16, 16); this->lblCardMejor->Text = L"Mejor semana"; this->lblMejor->AutoSize = true; this->lblMejor->Font = (gcnew System::Drawing::Font(L"Segoe UI", 20, System::Drawing::FontStyle::Bold)); this->lblMejor->ForeColor = System::Drawing::Color::FromArgb(20, 125, 95); this->lblMejor->Location = System::Drawing::Point(16, 45); this->lblMejor->Text = L"-"; this->lblMejorSub->AutoSize = true; this->lblMejorSub->ForeColor = System::Drawing::Color::DimGray; this->lblMejorSub->Location = System::Drawing::Point(18, 92); this->lblMejorSub->Text = L"sin datos";
			this->cardCritica->BackColor = System::Drawing::Color::White; this->cardCritica->Controls->Add(this->lblCardCritica); this->cardCritica->Controls->Add(this->lblCritica); this->cardCritica->Controls->Add(this->lblCriticaSub); this->cardCritica->Location = System::Drawing::Point(682, 142); this->cardCritica->Size = System::Drawing::Size(310, 132);
			this->lblCardCritica->AutoSize = true; this->lblCardCritica->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold)); this->lblCardCritica->ForeColor = System::Drawing::Color::FromArgb(90, 115, 140); this->lblCardCritica->Location = System::Drawing::Point(16, 16); this->lblCardCritica->Text = L"Semana critica"; this->lblCritica->AutoSize = true; this->lblCritica->Font = (gcnew System::Drawing::Font(L"Segoe UI", 20, System::Drawing::FontStyle::Bold)); this->lblCritica->ForeColor = System::Drawing::Color::FromArgb(180, 50, 50); this->lblCritica->Location = System::Drawing::Point(16, 45); this->lblCritica->Text = L"-"; this->lblCriticaSub->AutoSize = true; this->lblCriticaSub->ForeColor = System::Drawing::Color::DimGray; this->lblCriticaSub->Location = System::Drawing::Point(18, 92); this->lblCriticaSub->Text = L"sin datos";
			this->cardVariacion->BackColor = System::Drawing::Color::White; this->cardVariacion->Controls->Add(this->lblCardVariacion); this->cardVariacion->Controls->Add(this->lblVariacion); this->cardVariacion->Controls->Add(this->lblVariacionSub); this->cardVariacion->Location = System::Drawing::Point(1012, 142); this->cardVariacion->Size = System::Drawing::Size(310, 132);
			this->lblCardVariacion->AutoSize = true; this->lblCardVariacion->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold)); this->lblCardVariacion->ForeColor = System::Drawing::Color::FromArgb(90, 115, 140); this->lblCardVariacion->Location = System::Drawing::Point(16, 16); this->lblCardVariacion->Text = L"Tendencia"; this->lblVariacion->AutoSize = true; this->lblVariacion->Font = (gcnew System::Drawing::Font(L"Segoe UI", 20, System::Drawing::FontStyle::Bold)); this->lblVariacion->ForeColor = System::Drawing::Color::FromArgb(55, 138, 221); this->lblVariacion->Location = System::Drawing::Point(16, 45); this->lblVariacion->Text = L"0%"; this->lblVariacionSub->AutoSize = true; this->lblVariacionSub->ForeColor = System::Drawing::Color::DimGray; this->lblVariacionSub->Location = System::Drawing::Point(18, 92); this->lblVariacionSub->Text = L"primera vs ultima semana";

			this->grpEvolucion->BackColor = System::Drawing::Color::White; this->grpEvolucion->Controls->Add(this->chartEvolucion); this->grpEvolucion->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular)); this->grpEvolucion->Location = System::Drawing::Point(22, 296); this->grpEvolucion->Size = System::Drawing::Size(1300, 390); this->grpEvolucion->Text = L"Evolucion semanal del cumplimiento";
			areaEvolucion->Name = L"AreaEvolucion"; this->chartEvolucion->ChartAreas->Add(areaEvolucion); this->chartEvolucion->Dock = System::Windows::Forms::DockStyle::Fill; leyendaEvolucion->Docking = System::Windows::Forms::DataVisualization::Charting::Docking::Top; leyendaEvolucion->Name = L"LeyendaEvolucion"; this->chartEvolucion->Legends->Add(leyendaEvolucion); serieCumplimiento->ChartArea = L"AreaEvolucion"; serieCumplimiento->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line; serieCumplimiento->IsValueShownAsLabel = true; serieCumplimiento->LabelFormat = L"0'%'"; serieCumplimiento->Legend = L"LeyendaEvolucion"; serieCumplimiento->Name = L"Cumplimiento"; serieCumplimiento->Color = System::Drawing::Color::FromArgb(29, 158, 117); serieCumplimiento->BorderWidth = 4; serieCumplimiento->MarkerStyle = System::Windows::Forms::DataVisualization::Charting::MarkerStyle::Circle; serieCumplimiento->MarkerSize = 8; this->chartEvolucion->Series->Add(serieCumplimiento); serieMeta->ChartArea = L"AreaEvolucion"; serieMeta->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line; serieMeta->Legend = L"LeyendaEvolucion"; serieMeta->Name = L"Meta 80%"; serieMeta->Color = System::Drawing::Color::FromArgb(55, 138, 221); serieMeta->BorderDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::Dash; serieMeta->BorderWidth = 3; this->chartEvolucion->Series->Add(serieMeta);
			this->grpDosis->BackColor = System::Drawing::Color::White; this->grpDosis->Controls->Add(this->chartDosis); this->grpDosis->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular)); this->grpDosis->Location = System::Drawing::Point(22, 708); this->grpDosis->Size = System::Drawing::Size(640, 360); this->grpDosis->Text = L"Dosis tomadas y omitidas por semana";
			areaDosis->Name = L"AreaDosis"; this->chartDosis->ChartAreas->Add(areaDosis); this->chartDosis->Dock = System::Windows::Forms::DockStyle::Fill; leyendaDosis->Docking = System::Windows::Forms::DataVisualization::Charting::Docking::Top; leyendaDosis->Name = L"LeyendaDosis"; this->chartDosis->Legends->Add(leyendaDosis); serieTomadas->ChartArea = L"AreaDosis"; serieTomadas->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::StackedArea; serieTomadas->Legend = L"LeyendaDosis"; serieTomadas->Name = L"Tomadas"; serieTomadas->Color = System::Drawing::Color::FromArgb(150, 29, 158, 117); this->chartDosis->Series->Add(serieTomadas); serieOmitidas->ChartArea = L"AreaDosis"; serieOmitidas->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::StackedArea; serieOmitidas->Legend = L"LeyendaDosis"; serieOmitidas->Name = L"Omitidas"; serieOmitidas->Color = System::Drawing::Color::FromArgb(150, 232, 73, 73); this->chartDosis->Series->Add(serieOmitidas);
			this->grpMedicamentos->BackColor = System::Drawing::Color::White; this->grpMedicamentos->Controls->Add(this->chartMedicamentos); this->grpMedicamentos->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular)); this->grpMedicamentos->Location = System::Drawing::Point(682, 708); this->grpMedicamentos->Size = System::Drawing::Size(640, 360); this->grpMedicamentos->Text = L"Tendencia por medicamento";
			areaMedicamentos->Name = L"AreaMedicamentos"; this->chartMedicamentos->ChartAreas->Add(areaMedicamentos); this->chartMedicamentos->Dock = System::Windows::Forms::DockStyle::Fill; leyendaMedicamentos->Docking = System::Windows::Forms::DataVisualization::Charting::Docking::Top; leyendaMedicamentos->Name = L"LeyendaMedicamentos"; this->chartMedicamentos->Legends->Add(leyendaMedicamentos);

			this->grpDetalle->BackColor = System::Drawing::Color::White; this->grpDetalle->Controls->Add(this->dgvDetalle); this->grpDetalle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular)); this->grpDetalle->Location = System::Drawing::Point(22, 1090); this->grpDetalle->Size = System::Drawing::Size(1300, 330); this->grpDetalle->Text = L"Detalle semanal";
			this->dgvDetalle->AllowUserToAddRows = false; this->dgvDetalle->AllowUserToDeleteRows = false; this->dgvDetalle->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill; this->dgvDetalle->BackgroundColor = System::Drawing::Color::FromArgb(247, 249, 251); this->dgvDetalle->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::SingleHorizontal; this->dgvDetalle->GridColor = System::Drawing::Color::FromArgb(220, 230, 240); this->dgvDetalle->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None; this->dgvDetalle->EnableHeadersVisualStyles = false; this->dgvDetalle->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing; this->dgvDetalle->ColumnHeadersHeight = 36; this->dgvDetalle->ColumnHeadersDefaultCellStyle->BackColor = System::Drawing::Color::FromArgb(36, 66, 98); this->dgvDetalle->ColumnHeadersDefaultCellStyle->ForeColor = System::Drawing::Color::FromArgb(200, 218, 235); this->dgvDetalle->ColumnHeadersDefaultCellStyle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.5F, System::Drawing::FontStyle::Regular)); this->dgvDetalle->ColumnHeadersDefaultCellStyle->SelectionBackColor = System::Drawing::Color::FromArgb(36, 66, 98); this->dgvDetalle->ColumnHeadersDefaultCellStyle->SelectionForeColor = System::Drawing::Color::FromArgb(200, 218, 235); this->dgvDetalle->DefaultCellStyle->BackColor = System::Drawing::Color::White; this->dgvDetalle->DefaultCellStyle->ForeColor = System::Drawing::Color::FromArgb(40, 60, 80); this->dgvDetalle->DefaultCellStyle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F)); this->dgvDetalle->DefaultCellStyle->SelectionBackColor = System::Drawing::Color::FromArgb(210, 228, 248); this->dgvDetalle->DefaultCellStyle->SelectionForeColor = System::Drawing::Color::FromArgb(12, 52, 100); this->dgvDetalle->RowTemplate->Height = 32; this->dgvDetalle->BorderStyle = System::Windows::Forms::BorderStyle::None; this->dgvDetalle->Columns->AddRange(gcnew cli::array<System::Windows::Forms::DataGridViewColumn^>(7) { this->colSemana, this->colPeriodo, this->colProgramadas, this->colTomadas, this->colOmitidas, this->colCumplimiento, this->colVariacion }); this->dgvDetalle->Dock = System::Windows::Forms::DockStyle::Fill; this->dgvDetalle->ReadOnly = true; this->dgvDetalle->RowHeadersVisible = false; this->dgvDetalle->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->colSemana->HeaderText = L"Semana"; this->colSemana->ReadOnly = true; this->colPeriodo->HeaderText = L"Periodo"; this->colPeriodo->ReadOnly = true; this->colPeriodo->FillWeight = 140; this->colProgramadas->HeaderText = L"Programadas"; this->colProgramadas->ReadOnly = true; this->colTomadas->HeaderText = L"Tomadas"; this->colTomadas->ReadOnly = true; this->colOmitidas->HeaderText = L"Omitidas"; this->colOmitidas->ReadOnly = true; this->colCumplimiento->HeaderText = L"Cumplimiento"; this->colCumplimiento->ReadOnly = true; this->colVariacion->HeaderText = L"Variacion"; this->colVariacion->ReadOnly = true;
			this->grpReporte->BackColor = System::Drawing::Color::White; this->grpReporte->Controls->Add(this->txtReporte); this->grpReporte->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular)); this->grpReporte->Location = System::Drawing::Point(22, 1442); this->grpReporte->Size = System::Drawing::Size(1300, 260); this->grpReporte->Text = L"Reporte escrito y observaciones automaticas"; this->txtReporte->BackColor = System::Drawing::Color::FromArgb(247, 249, 251); this->txtReporte->ForeColor = System::Drawing::Color::FromArgb(40, 60, 80); this->txtReporte->BorderStyle = System::Windows::Forms::BorderStyle::None; this->txtReporte->Dock = System::Windows::Forms::DockStyle::Fill; this->txtReporte->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10)); this->txtReporte->ReadOnly = true;

			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16); this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font; this->BackColor = System::Drawing::Color::FromArgb(241, 244, 248); this->ClientSize = System::Drawing::Size(1360, 760); this->ControlBox = false; this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None; this->Controls->Add(this->panelContenido); this->Controls->Add(this->panelCabecera); this->Name = L"frmTendencias"; this->Text = L""; this->Load += gcnew System::EventHandler(this, &frmTendencias::frmTendencias_Load); this->Resize += gcnew System::EventHandler(this, &frmTendencias::frmTendencias_Resize);
			this->panelCabecera->ResumeLayout(false); this->panelCabecera->PerformLayout(); this->panelContenido->ResumeLayout(false); this->panelFiltros->ResumeLayout(false); this->panelFiltros->PerformLayout(); this->cardMensual->ResumeLayout(false); this->cardMensual->PerformLayout(); this->cardMejor->ResumeLayout(false); this->cardMejor->PerformLayout(); this->cardCritica->ResumeLayout(false); this->cardCritica->PerformLayout(); this->cardVariacion->ResumeLayout(false); this->cardVariacion->PerformLayout(); this->grpEvolucion->ResumeLayout(false); (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartEvolucion))->EndInit(); this->grpDosis->ResumeLayout(false); (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartDosis))->EndInit(); this->grpMedicamentos->ResumeLayout(false); (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartMedicamentos))->EndInit(); this->grpDetalle->ResumeLayout(false); (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvDetalle))->EndInit(); this->grpReporte->ResumeLayout(false); this->ResumeLayout(false);
		}
#pragma endregion

	private:
		bool Contiene(String^ texto, String^ valor) { return !String::IsNullOrWhiteSpace(texto) && texto->IndexOf(valor, StringComparison::OrdinalIgnoreCase) >= 0; }
		bool EsDosis(LogEvento^ e) { return e != nullptr && (Contiene(e->getTipoEvento(), "Toma") || Contiene(e->getTipoEvento(), "Dosis")) && !Contiene(e->getEstado(), "Pausa"); }
		bool EsCumplida(LogEvento^ e) { return e != nullptr && (Contiene(e->getEstado(), "Tomada") || Contiene(e->getEstado(), "Retraso") || Contiene(e->getEstado(), "A tiempo")); }
		int IdSeleccionado(ComboBox^ combo) { if (combo->SelectedIndex <= 0 || combo->SelectedItem == nullptr) return 0; String^ v = combo->SelectedItem->ToString(); int p = v->IndexOf(" - "); int id = 0; return p > 0 && Int32::TryParse(v->Substring(0, p), id) ? id : 0; }
		int NumeroSemana(DateTime fecha) { return ((fecha.Date - dtpDesde->Value.Date).Days / 7) + 1; }

		List<LogEvento^>^ Filtrar() {
			List<LogEvento^>^ lista = gcnew List<LogEvento^>(); int paciente = IdSeleccionado(cmbPaciente), medicamento = IdSeleccionado(cmbMedicamento);
			for each(LogEvento ^ e in controller->ObtenerTodos()) {
				if (!EsDosis(e) || e->getFechaHoraProgramada() == DateTime::MinValue) continue;
				if (e->getFechaHoraProgramada().Date < dtpDesde->Value.Date || e->getFechaHoraProgramada().Date > dtpHasta->Value.Date) continue;
				if (paciente > 0 && e->getIdPaciente() != paciente) continue; if (medicamento > 0 && e->getIdMedicamento() != medicamento) continue; lista->Add(e);
			}
			return lista;
		}

		void CargarFiltros() {
			SortedDictionary<int, String^>^ pacientes = gcnew SortedDictionary<int, String^>(); SortedDictionary<int, String^>^ medicamentos = gcnew SortedDictionary<int, String^>(); DateTime min = DateTime::MaxValue, max = DateTime::MinValue;
			for each(LogEvento ^ e in controller->ObtenerTodos()) if (EsDosis(e)) {
				if (e->getIdPaciente() > 0 && !pacientes->ContainsKey(e->getIdPaciente())) pacientes->Add(e->getIdPaciente(), e->getNombrePaciente());
				if (e->getIdMedicamento() > 0 && !medicamentos->ContainsKey(e->getIdMedicamento())) medicamentos->Add(e->getIdMedicamento(), e->getMedicamento());
				if (e->getFechaHoraProgramada() < min) min = e->getFechaHoraProgramada(); if (e->getFechaHoraProgramada() > max) max = e->getFechaHoraProgramada();
			}
			cmbPaciente->Items->Clear(); cmbPaciente->Items->Add("Todos los pacientes"); for each(KeyValuePair<int, String^> x in pacientes) cmbPaciente->Items->Add(x.Key + " - " + x.Value); cmbPaciente->SelectedIndex = 0;
			cmbMedicamento->Items->Clear(); cmbMedicamento->Items->Add("Todos los medicamentos"); for each(KeyValuePair<int, String^> x in medicamentos) cmbMedicamento->Items->Add(x.Key + " - " + x.Value); cmbMedicamento->SelectedIndex = 0;
			dtpDesde->Value = min == DateTime::MaxValue ? DateTime::Today.AddDays(-27) : min.Date; dtpHasta->Value = max == DateTime::MinValue ? DateTime::Today : max.Date;
		}

		void Actualizar() {
			List<LogEvento^>^ eventos = Filtrar(); SortedDictionary<int, array<int>^>^ semanas = gcnew SortedDictionary<int, array<int>^>(); Dictionary<String^, SortedDictionary<int, array<int>^>^>^ medicamentos = gcnew Dictionary<String^, SortedDictionary<int, array<int>^>^>();
			for each(LogEvento ^ e in eventos) {
				int semana = NumeroSemana(e->getFechaHoraProgramada()); if (!semanas->ContainsKey(semana)) semanas->Add(semana, gcnew array<int>(2)); { array<int>^ s = semanas[semana]; s[0]++; if (EsCumplida(e)) s[1]++; }
				String^ med = String::IsNullOrWhiteSpace(e->getMedicamento()) ? "Sin medicamento" : e->getMedicamento(); if (!medicamentos->ContainsKey(med)) medicamentos->Add(med, gcnew SortedDictionary<int, array<int>^>()); SortedDictionary<int, array<int>^>^ semanasMed = medicamentos[med]; if (!semanasMed->ContainsKey(semana)) semanasMed->Add(semana, gcnew array<int>(2)); { array<int>^ m = semanasMed[semana]; m[0]++; if (EsCumplida(e)) m[1]++; }
			}
			Series^ cumplimiento = chartEvolucion->Series["Cumplimiento"]; Series^ meta = chartEvolucion->Series["Meta 80%"]; Series^ tomadas = chartDosis->Series["Tomadas"]; Series^ omitidas = chartDosis->Series["Omitidas"]; cumplimiento->Points->Clear(); meta->Points->Clear(); tomadas->Points->Clear(); omitidas->Points->Clear(); chartMedicamentos->Series->Clear(); dgvDetalle->Rows->Clear();
			int total = eventos->Count, totalTomadas = 0, mejorSemana = 0, criticaSemana = 0; double mejor = -1.0, critica = 101.0, primera = 0.0, ultima = 0.0, anterior = 0.0; bool primero = true;
			for each(KeyValuePair<int, array<int>^> x in semanas) {
				int programadas = x.Value[0], cumplidas = x.Value[1], noCumplidas = programadas - cumplidas; totalTomadas += cumplidas; double porcentaje = programadas == 0 ? 0.0 : cumplidas * 100.0 / programadas; String^ etiqueta = "Semana " + x.Key;
				cumplimiento->Points->AddXY(etiqueta, porcentaje); meta->Points->AddXY(etiqueta, 80); tomadas->Points->AddXY(etiqueta, cumplidas); omitidas->Points->AddXY(etiqueta, noCumplidas);
				double variacion = primero ? 0.0 : porcentaje - anterior; DateTime inicio = dtpDesde->Value.Date.AddDays((x.Key - 1) * 7); DateTime fin = inicio.AddDays(6) > dtpHasta->Value.Date ? dtpHasta->Value.Date : inicio.AddDays(6);
				int fila = dgvDetalle->Rows->Add(etiqueta, inicio.ToString("dd/MM") + " - " + fin.ToString("dd/MM"), programadas, cumplidas, noCumplidas, String::Format("{0:F1}%", porcentaje), primero ? "-" : String::Format("{0:+0.0;-0.0;0.0}%", variacion));
				dgvDetalle->Rows[fila]->Cells[5]->Style->ForeColor = porcentaje >= 80 ? Color::FromArgb(20, 125, 95) : Color::FromArgb(180, 50, 50); if (porcentaje > mejor) { mejor = porcentaje; mejorSemana = x.Key; } if (porcentaje < critica) { critica = porcentaje; criticaSemana = x.Key; } if (primero) primera = porcentaje; ultima = porcentaje; anterior = porcentaje; primero = false;
			}
			array<Color>^ colores = { Color::FromArgb(29,158,117), Color::FromArgb(55,138,221), Color::FromArgb(239,159,39), Color::FromArgb(214,78,126), Color::FromArgb(105,95,210), Color::FromArgb(20,125,95) }; int color = 0;
			for each(KeyValuePair<String^, SortedDictionary<int, array<int>^>^> med in medicamentos) {
				Series^ s = gcnew Series(med.Key); s->ChartArea = "AreaMedicamentos"; s->Legend = "LeyendaMedicamentos"; s->ChartType = SeriesChartType::Line; s->BorderWidth = 3; s->MarkerStyle = MarkerStyle::Circle; s->Color = colores[color++ % colores->Length];
				for each(KeyValuePair<int, array<int>^> x in med.Value) s->Points->AddXY("Semana " + x.Key, x.Value[0] == 0 ? 0.0 : x.Value[1] * 100.0 / x.Value[0]); chartMedicamentos->Series->Add(s);
			}
			double general = total == 0 ? 0.0 : totalTomadas * 100.0 / total, variacionTotal = semanas->Count < 2 ? 0.0 : ultima - primera;
			lblMensual->Text = String::Format("{0:F1}%", general); lblMensual->ForeColor = general >= 80 ? Color::FromArgb(20, 125, 95) : Color::FromArgb(180, 50, 50); lblMejor->Text = mejorSemana == 0 ? "-" : "Semana " + mejorSemana; lblMejorSub->Text = mejorSemana == 0 ? "sin datos" : String::Format("{0:F1}% cumplimiento", mejor); lblCritica->Text = criticaSemana == 0 ? "-" : "Semana " + criticaSemana; lblCriticaSub->Text = criticaSemana == 0 ? "sin datos" : String::Format("{0:F1}% cumplimiento", critica); lblVariacion->Text = String::Format("{0:+0.0;-0.0;0.0}%", variacionTotal); lblVariacion->ForeColor = variacionTotal >= 0 ? Color::FromArgb(20, 125, 95) : Color::FromArgb(180, 50, 50); lblVariacionSub->Text = variacionTotal > 1 ? "tendencia ascendente" : variacionTotal < -1 ? "tendencia descendente" : "tendencia estable";
			StringBuilder^ texto = gcnew StringBuilder(); texto->Append("REPORTE DE TENDENCIAS DE CUMPLIMIENTO\r\n\r\n"); texto->AppendFormat("Periodo analizado: {0} al {1}\r\nPacientes: {2}\r\nMedicamentos: {3}\r\n\r\n", dtpDesde->Value.ToString("dd/MM/yyyy"), dtpHasta->Value.ToString("dd/MM/yyyy"), cmbPaciente->SelectedItem, cmbMedicamento->SelectedItem);
			if (total == 0) texto->Append("No existen eventos de toma para los filtros seleccionados."); else { texto->AppendFormat("Durante el periodo se registraron {0} dosis programadas, de las cuales {1} fueron tomadas correctamente o con retraso. El cumplimiento general fue de {2:F1}%.\r\n\r\n", total, totalTomadas, general); texto->AppendFormat("La mejor semana fue la Semana {0}, con {1:F1}% de cumplimiento. La Semana {2} presento el resultado mas bajo, con {3:F1}%.\r\n\r\n", mejorSemana, mejor, criticaSemana, critica); texto->AppendFormat("La variacion entre la primera y la ultima semana fue de {0:+0.0;-0.0;0.0} puntos porcentuales. ", variacionTotal); texto->Append(variacionTotal > 1 ? "La evolucion observada es favorable y ascendente." : variacionTotal < -1 ? "La evolucion es descendente; se recomienda revisar las causas de las omisiones recientes." : "El cumplimiento se mantuvo estable durante el periodo."); }
			txtReporte->Text = texto->ToString(); lblGenerado->Text = "Generado: " + DateTime::Now.ToString("dd/MM/yyyy HH:mm"); dgvDetalle->ClearSelection();
		}

		void Ajustar() {
			chartEvolucion->Dock = DockStyle::None; chartDosis->Dock = DockStyle::None; chartMedicamentos->Dock = DockStyle::None; dgvDetalle->Dock = DockStyle::None; chartEvolucion->Bounds = grpEvolucion->DisplayRectangle; chartDosis->Bounds = grpDosis->DisplayRectangle; chartMedicamentos->Bounds = grpMedicamentos->DisplayRectangle; dgvDetalle->Bounds = grpDetalle->DisplayRectangle; AnchorStyles a = AnchorStyles::Top | AnchorStyles::Bottom | AnchorStyles::Left | AnchorStyles::Right; chartEvolucion->Anchor = a; chartDosis->Anchor = a; chartMedicamentos->Anchor = a; dgvDetalle->Anchor = a;
			ChartArea^ area = chartEvolucion->ChartAreas["AreaEvolucion"]; area->AxisY->Minimum = 0; area->AxisY->Maximum = 100; area->AxisY->Interval = 20; area->AxisY->LabelStyle->Format = "0'%'"; area->AxisX->Interval = 1; area->Position->Auto = false; area->Position->X = 6; area->Position->Y = 12; area->Position->Width = 91; area->Position->Height = 78;
			area = chartDosis->ChartAreas["AreaDosis"]; area->AxisX->Interval = 1; area->Position->Auto = false; area->Position->X = 8; area->Position->Y = 14; area->Position->Width = 88; area->Position->Height = 76;
			area = chartMedicamentos->ChartAreas["AreaMedicamentos"]; area->AxisY->Minimum = 0; area->AxisY->Maximum = 100; area->AxisY->Interval = 20; area->AxisY->LabelStyle->Format = "0'%'"; area->AxisX->Interval = 1; area->Position->Auto = false; area->Position->X = 8; area->Position->Y = 14; area->Position->Width = 88; area->Position->Height = 76;
		}


		void AjustarDistribucion() {
			int margen = 22;
			int separacionHorizontal = 20;
			int espacioVertical = 18;

			int anchoDisponible =
				this->panelContenido->ClientSize.Width - (margen * 2);

			if (anchoDisponible < 900)
				anchoDisponible = 900;

			int anchoMitad =
				(anchoDisponible - separacionHorizontal) / 2;

			// Posiciones verticales uniformes y automáticas
			int yFiltros = 18;

			int yTarjetas =
				yFiltros +
				this->panelFiltros->Height +
				espacioVertical;

			int yEvolucion =
				yTarjetas +
				this->cardMensual->Height +
				espacioVertical;

			int yGraficosSecundarios =
				yEvolucion +
				this->grpEvolucion->Height +
				espacioVertical;

			int yDetalle =
				yGraficosSecundarios +
				this->grpDosis->Height +
				espacioVertical;

			int yReporte =
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

			// Cuatro tarjetas distribuidas uniformemente
			array<System::Windows::Forms::Panel^>^ tarjetas = {
				this->cardMensual,
				this->cardMejor,
				this->cardCritica,
				this->cardVariacion
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

			// Gráfico principal a todo el ancho
			this->grpEvolucion->Location =
				System::Drawing::Point(margen, yEvolucion);
			this->grpEvolucion->Width = anchoDisponible;

			// Gráficos secundarios en dos columnas
			this->grpDosis->Location =
				System::Drawing::Point(margen, yGraficosSecundarios);
			this->grpDosis->Width = anchoMitad;

			this->grpMedicamentos->Location =
				System::Drawing::Point(
					margen + anchoMitad + separacionHorizontal,
					yGraficosSecundarios
				);
			this->grpMedicamentos->Width = anchoMitad;

			// Tabla y reporte a todo el ancho
			this->grpDetalle->Location =
				System::Drawing::Point(margen, yDetalle);
			this->grpDetalle->Width = anchoDisponible;

			this->grpReporte->Location =
				System::Drawing::Point(margen, yReporte);
			this->grpReporte->Width = anchoDisponible;

			Ajustar();
		}

		System::Void frmTendencias_Resize(
			System::Object^ sender,
			System::EventArgs^ e
		) {
			AjustarDistribucion();
		}

		System::Void frmTendencias_Load(System::Object^, System::EventArgs^) {
			controller = gcnew GeneradorReportesController();
			CargarFiltros();
			Actualizar();
			AjustarDistribucion();
			BeginInvoke(
				gcnew MethodInvoker(
					this,
					&frmTendencias::AjustarDistribucion
				)
			);
		}
		System::Void btnAplicar_Click(System::Object^, System::EventArgs^) { if (dtpDesde->Value.Date > dtpHasta->Value.Date) { MessageBox::Show("La fecha inicial no puede ser posterior a la fecha final.", "Tendencias", MessageBoxButtons::OK, MessageBoxIcon::Warning); return; } Actualizar(); }
		System::Void btnRestablecer_Click(System::Object^, System::EventArgs^) { CargarFiltros(); Actualizar(); }

	private: System::Void cmbPaciente_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		int idPaciente = IdSeleccionado(cmbPaciente);
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