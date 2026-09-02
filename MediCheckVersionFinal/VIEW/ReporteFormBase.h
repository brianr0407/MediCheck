#pragma once

namespace VIEW {
	using namespace System;
	using namespace System::Collections::Generic;
	using namespace System::Drawing;
	using namespace System::Globalization;
	using namespace System::Windows::Forms;
	using namespace System::Windows::Forms::DataVisualization::Charting;
	using namespace MODEL;
	using namespace CONTROLLER;

	public ref class ReporteFormPresenter {
	private:
		Form^ vista;
		GeneradorReportesController^ controller;
		String^ nombreReporte;
		String^ tipoGrafico;
		String^ tipoPredeterminado;
		String^ estadoPredeterminado;
		int eventoSeleccionado;

		DataGridView^ tabla;
		Chart^ grafico;
		RichTextBox^ resumen;
		NumericUpDown^ idPaciente;
		TextBox^ paciente;
		NumericUpDown^ idMedicamento;
		TextBox^ medicamento;
		ComboBox^ tipoEvento;
		ComboBox^ estado;
		TextBox^ origen;
		DateTimePicker^ programada;
		DateTimePicker^ real;
		NumericUpDown^ cantidad;
		TextBox^ detalle;

	public:
		ReporteFormPresenter(
			Form^ vista,
			String^ nombreReporte,
			String^ tipoGrafico,
			String^ tipoPredeterminado,
			String^ estadoPredeterminado)
		{
			this->vista = vista;
			this->nombreReporte = nombreReporte;
			this->tipoGrafico = tipoGrafico;
			this->tipoPredeterminado = tipoPredeterminado;
			this->estadoPredeterminado = estadoPredeterminado;
			this->eventoSeleccionado = 0;
			this->controller = gcnew GeneradorReportesController();
			ConstruirVista();
			ActualizarReporte();
		}

		~ReporteFormPresenter() {}

	private:
		Panel^ CrearCampo(String^ etiqueta, Control^ control, int ancho) {
			Panel^ panel = gcnew Panel();
			panel->Width = ancho;
			panel->Height = 62;
			panel->Margin = System::Windows::Forms::Padding(5, 4, 5, 2);

			Label^ label = gcnew Label();
			label->Text = etiqueta;
			label->ForeColor = Color::FromArgb(74, 122, 155);
			label->Font = gcnew Drawing::Font("Segoe UI", 8.0f, FontStyle::Bold);
			label->AutoSize = true;
			label->Location = Point(0, 0);
			panel->Controls->Add(label);

			control->Location = Point(0, 19);
			control->Width = ancho - 2;
			control->Font = gcnew Drawing::Font("Segoe UI", 8.5f);
			panel->Controls->Add(control);
			return panel;
		}

		ComboBox^ CrearCombo(array<String^>^ opciones) {
			ComboBox^ combo = gcnew ComboBox();
			combo->DropDownStyle = ComboBoxStyle::DropDownList;
			combo->Items->AddRange(opciones);
			return combo;
		}

		Button^ CrearBoton(String^ texto, Color color, EventHandler^ handler) {
			Button^ boton = gcnew Button();
			boton->Text = texto;
			boton->Width = 115;
			boton->Height = 34;
			boton->Margin = System::Windows::Forms::Padding(6, 22, 2, 2);
			boton->BackColor = color;
			boton->ForeColor = Color::White;
			boton->FlatStyle = FlatStyle::Flat;
			boton->FlatAppearance->BorderSize = 0;
			boton->Cursor = Cursors::Hand;
			boton->Click += handler;
			return boton;
		}

		void ConstruirVista() {
			this->vista->Text = this->nombreReporte;
			this->vista->ControlBox = false;
			this->vista->BackColor = Color::FromArgb(238, 243, 247);
			this->vista->ClientSize = Drawing::Size(1280, 720);

			Panel^ cabecera = gcnew Panel();
			cabecera->Dock = DockStyle::Top;
			cabecera->Height = 58;
			cabecera->BackColor = Color::FromArgb(26, 58, 82);
			this->vista->Controls->Add(cabecera);

			Label^ titulo = gcnew Label();
			titulo->Text = "Reporte de " + this->nombreReporte;
			titulo->ForeColor = Color::White;
			titulo->Font = gcnew Drawing::Font("Segoe UI", 15.0f, FontStyle::Bold);
			titulo->AutoSize = true;
			titulo->Location = Point(18, 8);
			cabecera->Controls->Add(titulo);

			Label^ subtitulo = gcnew Label();
			subtitulo->Text = this->tipoGrafico + "  |  Fuente: Base de datos";
			subtitulo->ForeColor = Color::FromArgb(150, 205, 230);
			subtitulo->Font = gcnew Drawing::Font("Segoe UI", 8.5f);
			subtitulo->AutoSize = true;
			subtitulo->Location = Point(20, 34);
			cabecera->Controls->Add(subtitulo);

			FlowLayoutPanel^ editor = gcnew FlowLayoutPanel();
			editor->Dock = DockStyle::Top;
			editor->Height = 144;
			editor->Padding = System::Windows::Forms::Padding(8, 4, 8, 2);
			editor->BackColor = Color::White;
			editor->AutoScroll = true;
			editor->WrapContents = true;
			this->vista->Controls->Add(editor);

			this->idPaciente = gcnew NumericUpDown();
			this->idPaciente->Maximum = Decimal(1000000);
			editor->Controls->Add(CrearCampo("ID paciente", this->idPaciente, 90));

			this->paciente = gcnew TextBox();
			editor->Controls->Add(CrearCampo("Paciente", this->paciente, 150));

			this->idMedicamento = gcnew NumericUpDown();
			this->idMedicamento->Maximum = Decimal(1000000);
			editor->Controls->Add(CrearCampo("ID medicamento", this->idMedicamento, 105));

			this->medicamento = gcnew TextBox();
			editor->Controls->Add(CrearCampo("Medicamento", this->medicamento, 145));

			this->tipoEvento = CrearCombo(gcnew array<String^> {
				"Dosis", "Dispensacion", "Autenticacion", "Agua Servida",
				"Alerta Critica", "Error Hardware", "Pausa"
			});
			editor->Controls->Add(CrearCampo("Tipo evento", this->tipoEvento, 135));

			this->estado = CrearCombo(gcnew array<String^> {
				"Programada", "Tomada", "No tomada", "Exitosa", "Fallida",
				"A tiempo", "Retraso", "Omision", "Activa", "Resuelta", "PAUSA"
			});
			editor->Controls->Add(CrearCampo("Estado", this->estado, 120));

			this->origen = gcnew TextBox();
			editor->Controls->Add(CrearCampo("Origen", this->origen, 145));

			this->programada = gcnew DateTimePicker();
			this->programada->Format = DateTimePickerFormat::Custom;
			this->programada->CustomFormat = "dd/MM/yyyy HH:mm";
			editor->Controls->Add(CrearCampo("Fecha/hora programada", this->programada, 160));

			this->real = gcnew DateTimePicker();
			this->real->Format = DateTimePickerFormat::Custom;
			this->real->CustomFormat = "dd/MM/yyyy HH:mm";
			editor->Controls->Add(CrearCampo("Fecha/hora real", this->real, 160));

			this->cantidad = gcnew NumericUpDown();
			this->cantidad->Maximum = Decimal(1000000);
			editor->Controls->Add(CrearCampo("Cantidad / ml", this->cantidad, 105));

			this->detalle = gcnew TextBox();
			editor->Controls->Add(CrearCampo("Detalle", this->detalle, 210));

			editor->Controls->Add(CrearBoton("Agregar", Color::FromArgb(29, 158, 117),
				gcnew EventHandler(this, &ReporteFormPresenter::btnAgregar_Click)));
			editor->Controls->Add(CrearBoton("Editar", Color::FromArgb(55, 138, 221),
				gcnew EventHandler(this, &ReporteFormPresenter::btnEditar_Click)));
			editor->Controls->Add(CrearBoton("Eliminar", Color::FromArgb(180, 50, 50),
				gcnew EventHandler(this, &ReporteFormPresenter::btnEliminar_Click)));
			editor->Controls->Add(CrearBoton("Nuevo", Color::FromArgb(100, 110, 120),
				gcnew EventHandler(this, &ReporteFormPresenter::btnNuevo_Click)));

			SplitContainer^ contenido = gcnew SplitContainer();
			contenido->Dock = DockStyle::Fill;
			contenido->Orientation = Orientation::Vertical;
			contenido->SplitterDistance = 740;
			contenido->BackColor = Color::FromArgb(220, 230, 240);
			this->vista->Controls->Add(contenido);
			editor->BringToFront();
			cabecera->BringToFront();

			SplitContainer^ ladoIzquierdo = gcnew SplitContainer();
			ladoIzquierdo->Dock = DockStyle::Fill;
			ladoIzquierdo->Orientation = Orientation::Horizontal;
			ladoIzquierdo->SplitterDistance = 315;
			contenido->Panel1->Controls->Add(ladoIzquierdo);

			this->tabla = gcnew DataGridView();
			this->tabla->Dock = DockStyle::Fill;
			this->tabla->ReadOnly = true;
			this->tabla->AllowUserToAddRows = false;
			this->tabla->AllowUserToDeleteRows = false;
			this->tabla->MultiSelect = false;
			this->tabla->SelectionMode = DataGridViewSelectionMode::FullRowSelect;
			this->tabla->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::DisplayedCells;
			this->tabla->BackgroundColor = Color::White;
			this->tabla->BorderStyle = BorderStyle::None;
			this->tabla->CellClick += gcnew DataGridViewCellEventHandler(this, &ReporteFormPresenter::tabla_CellClick);
			this->tabla->Columns->Add("Id", "ID");
			this->tabla->Columns->Add("Paciente", "Paciente");
			this->tabla->Columns->Add("Medicamento", "Medicamento");
			this->tabla->Columns->Add("Tipo", "Tipo evento");
			this->tabla->Columns->Add("Estado", "Estado");
			this->tabla->Columns->Add("Origen", "Origen");
			this->tabla->Columns->Add("Programada", "Programada");
			this->tabla->Columns->Add("Real", "Real");
			this->tabla->Columns->Add("Cantidad", "Cantidad");
			this->tabla->Columns->Add("Detalle", "Detalle");
			ladoIzquierdo->Panel1->Controls->Add(this->tabla);

			this->resumen = gcnew RichTextBox();
			this->resumen->Dock = DockStyle::Fill;
			this->resumen->ReadOnly = true;
			this->resumen->BackColor = Color::White;
			this->resumen->BorderStyle = BorderStyle::None;
			this->resumen->Font = gcnew Drawing::Font("Consolas", 8.5f);
			this->resumen->ForeColor = Color::FromArgb(26, 58, 82);
			ladoIzquierdo->Panel2->Controls->Add(this->resumen);

			this->grafico = gcnew Chart();
			this->grafico->Dock = DockStyle::Fill;
			this->grafico->BackColor = Color::White;
			ChartArea^ area = gcnew ChartArea("Principal");
			area->AxisX->Interval = 1;
			area->AxisX->LabelStyle->Angle = -35;
			area->AxisY->MajorGrid->LineColor = Color::FromArgb(225, 232, 238);
			this->grafico->ChartAreas->Add(area);
			this->grafico->Legends->Add(gcnew Legend("Leyenda"));
			contenido->Panel2->Controls->Add(this->grafico);

			LimpiarEditor();
		}

		void LimpiarEditor() {
			this->eventoSeleccionado = 0;
			this->idPaciente->Value = 0;
			this->paciente->Clear();
			this->idMedicamento->Value = 0;
			this->medicamento->Clear();
			this->tipoEvento->SelectedItem = this->tipoPredeterminado;
			this->estado->SelectedItem = this->estadoPredeterminado;
			this->origen->Clear();
			this->programada->Value = DateTime::Now;
			this->real->Value = DateTime::Now;
			this->cantidad->Value = 0;
			this->detalle->Clear();
			this->tabla->ClearSelection();
		}

		LogEvento^ CrearDesdeEditor() {
			return this->controller->CrearEvento(
				Decimal::ToInt32(this->idPaciente->Value),
				this->paciente->Text,
				Decimal::ToInt32(this->idMedicamento->Value),
				this->medicamento->Text,
				safe_cast<String^>(this->tipoEvento->SelectedItem),
				safe_cast<String^>(this->estado->SelectedItem),
				this->origen->Text,
				this->programada->Value,
				this->real->Value,
				Decimal::ToInt32(this->cantidad->Value),
				this->detalle->Text);
		}

		void CargarEnEditor(LogEvento^ evento) {
			if (evento == nullptr)
				return;
			this->eventoSeleccionado = evento->getId();
			this->idPaciente->Value = Decimal(Math::Max(0, evento->getIdPaciente()));
			this->paciente->Text = evento->getNombrePaciente();
			this->idMedicamento->Value = Decimal(Math::Max(0, evento->getIdMedicamento()));
			this->medicamento->Text = evento->getMedicamento();
			this->tipoEvento->SelectedItem = evento->getTipoEvento();
			this->estado->SelectedItem = evento->getEstado();
			this->origen->Text = evento->getOrigen();
			this->programada->Value = evento->getFechaHoraProgramada() == DateTime::MinValue
				? DateTime::Now : evento->getFechaHoraProgramada();
			this->real->Value = evento->getFechaHoraReal() == DateTime::MinValue
				? DateTime::Now : evento->getFechaHoraReal();
			this->cantidad->Value = Decimal(Math::Max(0, evento->getCantidad()));
			this->detalle->Text = evento->getDetalle();
		}

		void ActualizarReporte() {
			List<LogEvento^>^ eventos = this->controller->ObtenerEventosReporte(this->nombreReporte);
			this->tabla->Rows->Clear();

			for each (LogEvento ^ evento in eventos) {
				String^ estadoVisible = this->nombreReporte == "Puntualidad"
					? this->controller->ClasificarPuntualidad(evento)
					: evento->getEstado();
				this->tabla->Rows->Add(gcnew array<Object^> {
					evento->getId(),
					evento->getNombrePaciente(),
					evento->getMedicamento(),
					evento->getTipoEvento(),
					estadoVisible,
					evento->getOrigen(),
					evento->getFechaHoraProgramada().ToString("dd/MM/yyyy HH:mm"),
					evento->getFechaHoraReal().ToString("dd/MM/yyyy HH:mm"),
					evento->getCantidad(),
					evento->getDetalle()
				});
			}

			this->resumen->Text = this->controller->GenerarResumen(this->nombreReporte);
			ActualizarGrafico(eventos);
		}

		Series^ AgregarSerie(String^ nombre, SeriesChartType tipo, Color color) {
			Series^ serie = gcnew Series(nombre);
			serie->ChartType = tipo;
			serie->ChartArea = "Principal";
			serie->Legend = "Leyenda";
			serie->Color = color;
			serie->IsValueShownAsLabel = true;
			this->grafico->Series->Add(serie);
			return serie;
		}

		void ActualizarGrafico(List<LogEvento^>^ eventos) {
			this->grafico->Series->Clear();
			this->grafico->Titles->Clear();
			this->grafico->Titles->Add(this->nombreReporte);
			this->grafico->ChartAreas["Principal"]->AxisY->Minimum = Double::NaN;
			this->grafico->ChartAreas["Principal"]->AxisY->Maximum = Double::NaN;

			if (this->nombreReporte == "Puntualidad") {
				Dictionary<String^, array<int>^>^ grupos = gcnew Dictionary<String^, array<int>^>();
				for each (LogEvento ^ evento in eventos) {
					String^ fecha = evento->getFechaHoraProgramada().ToString("dd/MM");
					if (!grupos->ContainsKey(fecha))
						grupos->Add(fecha, gcnew array<int>(3));
					String^ clasificacion = this->controller->ClasificarPuntualidad(evento);
					if (clasificacion == "A tiempo") grupos[fecha][0]++;
					else if (clasificacion == "Retraso") grupos[fecha][1]++;
					else grupos[fecha][2]++;
				}
				Series^ aTiempo = AgregarSerie("A tiempo", SeriesChartType::Line, Color::FromArgb(29, 158, 117));
				Series^ retraso = AgregarSerie("Retraso", SeriesChartType::Line, Color::FromArgb(230, 140, 30));
				Series^ omision = AgregarSerie("Omision", SeriesChartType::Line, Color::FromArgb(180, 50, 50));
				for each (Series ^ serie in this->grafico->Series) {
					serie->MarkerStyle = MarkerStyle::Circle;
					serie->MarkerSize = 7;
					serie->BorderWidth = 3;
				}
				for each (KeyValuePair<String^, array<int>^> grupo in grupos) {
					aTiempo->Points->AddXY(grupo.Key, grupo.Value[0]);
					retraso->Points->AddXY(grupo.Key, grupo.Value[1]);
					omision->Points->AddXY(grupo.Key, grupo.Value[2]);
				}
				return;
			}

			SeriesChartType tipo = SeriesChartType::Column;
			if (this->nombreReporte == "Dispensado" || this->nombreReporte == "Uso del Sistema")
				tipo = SeriesChartType::Pie;
			else if (this->nombreReporte == "Dosis Omitidas")
				tipo = SeriesChartType::Doughnut;
			else if (this->nombreReporte == "Alertas Criticas" || this->nombreReporte == "Tendencias")
				tipo = SeriesChartType::Line;
			else if (this->nombreReporte == "Adherencia por Medicamento")
				tipo = SeriesChartType::Bar;

			Series^ serie = AgregarSerie(this->nombreReporte, tipo, Color::FromArgb(55, 138, 221));
			if (tipo == SeriesChartType::Pie || tipo == SeriesChartType::Doughnut)
				serie->Label = "#VALX: #VAL";
			if (tipo == SeriesChartType::Line) {
				serie->MarkerStyle = MarkerStyle::Circle;
				serie->MarkerSize = 8;
				serie->BorderWidth = 3;
			}

			Dictionary<String^, double>^ valores = this->controller->ObtenerValoresGrafico(this->nombreReporte);
			for each (KeyValuePair<String^, double> valor in valores) {
				int indice = serie->Points->AddXY(valor.Key, valor.Value);
				if (this->nombreReporte == "Cumplimiento" ||
					this->nombreReporte == "Adherencia por Medicamento" ||
					this->nombreReporte == "Tendencias")
					serie->Points[indice]->Label = String::Format("{0:F1}%", valor.Value);
			}
			if (this->nombreReporte == "Cumplimiento" ||
				this->nombreReporte == "Adherencia por Medicamento" ||
				this->nombreReporte == "Tendencias") {
				this->grafico->ChartAreas["Principal"]->AxisY->Minimum = 0;
				this->grafico->ChartAreas["Principal"]->AxisY->Maximum = 100;
			}
		}

		void btnAgregar_Click(Object^ sender, EventArgs^ e) {
			try {
				this->controller->AgregarEvento(CrearDesdeEditor());
				LimpiarEditor();
				ActualizarReporte();
			}
			catch (Exception^ ex) {
				MessageBox::Show(ex->Message, "No se pudo agregar", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
		}

		void btnEditar_Click(Object^ sender, EventArgs^ e) {
			if (this->eventoSeleccionado <= 0) {
				MessageBox::Show("Seleccione un evento de la tabla.", "Editar evento",
					MessageBoxButtons::OK, MessageBoxIcon::Information);
				return;
			}
			try {
				LogEvento^ evento = CrearDesdeEditor();
				evento->setId(this->eventoSeleccionado);
				this->controller->ActualizarEvento(evento);
				LimpiarEditor();
				ActualizarReporte();
			}
			catch (Exception^ ex) {
				MessageBox::Show(ex->Message, "No se pudo editar", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
		}

		void btnEliminar_Click(Object^ sender, EventArgs^ e) {
			if (this->eventoSeleccionado <= 0) {
				MessageBox::Show("Seleccione un evento de la tabla.", "Eliminar evento",
					MessageBoxButtons::OK, MessageBoxIcon::Information);
				return;
			}
			if (MessageBox::Show("Este evento se eliminara de todos los reportes. Desea continuar?",
				"Confirmar", MessageBoxButtons::YesNo, MessageBoxIcon::Question) !=
				System::Windows::Forms::DialogResult::Yes)
				return;
			try {
				this->controller->EliminarEvento(this->eventoSeleccionado);
				LimpiarEditor();
				ActualizarReporte();
			}
			catch (Exception^ ex) {
				MessageBox::Show(ex->Message, "No se pudo eliminar", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
		}

		void btnNuevo_Click(Object^ sender, EventArgs^ e) {
			LimpiarEditor();
		}

		void tabla_CellClick(Object^ sender, DataGridViewCellEventArgs^ e) {
			if (e->RowIndex < 0)
				return;
			int id = Convert::ToInt32(this->tabla->Rows[e->RowIndex]->Cells[0]->Value);
			CargarEnEditor(this->controller->BuscarPorId(id));
		}
	};
}
