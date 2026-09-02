#pragma once

#include "frmMantAdministrador.h"
#include "frmMantPacientes.h"
#include "frmMantMedicamentos.h"
#include "frmMantAlarma.h"
#include "frmVerificador.h"
#include "frmMantReceta.h"
#include "frmPruebasESP32.h"
#include "frmRestauracion.h"
#include "frmCumplimiento.h"
#include "frmDispensado.h"
#include "frmPuntualidad.h"
#include "frmDosisOmitidas.h"
#include "frmAlertasCriticas.h"
#include "frmUsoSistema.h"
#include "frmAdherenciaMedicamento.h"
#include "frmTendencias.h"

namespace VIEW {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace CONTROLLER;

	// ── DTO para el dashboard extendido ──────────────────────────────────────
	ref class CumplimientoPacienteDTO {
	public:
		String^ nombrePaciente;
		int     porcentaje;
	};

	public ref class frmPrincipal : public System::Windows::Forms::Form
	{
	public:
		frmPrincipal(void)
		{
			InitializeComponent();
			dashboardActualizandose = false;
			dashboardDisponible = false;
			dashDosisOmitidas = 0;
			dashAlertasCriticas = 0;
			dashPuntualidad = 0;
			dashPacientesRiesgo = 0;
			panelCumplimiento = nullptr;
			panelResumen = nullptr;
		}

	protected:
		~frmPrincipal()
		{
			if (components)
				delete components;
		}

	private:
		// ── Controles de menú ─────────────────────────────────────────────────
		System::Windows::Forms::MenuStrip^ menuStrip1;
		System::Windows::Forms::ToolStripMenuItem^ mantenimientoToolStripMenuItem;
		System::Windows::Forms::ToolStripMenuItem^ medicamentosToolStripMenuItem;
		System::Windows::Forms::ToolStripMenuItem^ recetasToolStripMenuItem;
		System::Windows::Forms::ToolStripMenuItem^ alarmasToolStripMenuItem;
		System::Windows::Forms::ToolStripMenuItem^ pacientesToolStripMenuItem;
		System::Windows::Forms::ToolStripMenuItem^ administradoresToolStripMenuItem;
		System::Windows::Forms::ToolStripMenuItem^ reportesToolStripMenuItem;
		System::Windows::Forms::ToolStripMenuItem^ cumplimientoDiarioToolStripMenuItem;
		System::Windows::Forms::ToolStripMenuItem^ registroDeTomasToolStripMenuItem;
		System::Windows::Forms::ToolStripMenuItem^ dosisOmitidasToolStripMenuItem;
		System::Windows::Forms::ToolStripMenuItem^ puntualidadToolStripMenuItem;
		System::ComponentModel::Container^ components;

		// ── Sidebar y status ──────────────────────────────────────────────────
		Panel^ panelSidebar;
		StatusStrip^ statusStrip1;
		ToolStripStatusLabel^ lblEstado;
		ToolStripStatusLabel^ lblSpring;
		ToolStripStatusLabel^ lblInfoUsuario;
		System::Windows::Forms::Timer^ timerReloj;
		System::Windows::Forms::Timer^ timerDashboard;

		// ── Panel principal del dashboard ─────────────────────────────────────
		Panel^ panelDashboard;
		Label^ lblFechaDashboard;
		Label^ lblValorPacientes;
		Label^ lblValorMedicamentos;
		Label^ lblValorAlarmas;
		Label^ lblValorCumplimiento;
		Label^ lblUltimaActualizacion;

		// ── Paneles extendidos (se reconstruyen en cada actualización) ─────────
		Panel^ panelCumplimiento;
		Panel^ panelResumen;

		// ── Estado del segundo plano ──────────────────────────────────────────
		bool    dashboardActualizandose;
		bool    dashboardDisponible;

		// Métricas básicas
		int     dashboardPacientes;
		int     dashboardMedicamentos;
		int     dashboardAlarmas;
		double  dashboardCumplimiento;

		// Datos extendidos
		int     dashDosisOmitidas;
		int     dashAlertasCriticas;
		int     dashPuntualidad;
		int     dashPacientesRiesgo;
		List<CumplimientoPacienteDTO^>^ dashCumplimientoPacientes;

		// ── Botones sidebar - Módulos ─────────────────────────────────────────
		Button^ btnInicio;
		Button^ btnMedicamentos;
		Button^ btnRecetas;
		Button^ btnAlarmas;
		Button^ btnPacientes;
		Button^ btnAdmins;

		// ── Botones sidebar - Reportes ────────────────────────────────────────
		Button^ btnCumplimiento;
		Button^ btnRegistroTomas;
		Button^ btnDosisOmitidas;
		Button^ btnPuntualidad;
		Button^ btnAlertasCriticas;
		Button^ btnUsoSistema;
		Button^ btnAdherenciaMedicamento;
		Button^ btnTendencias;

		// ── Botones especiales ────────────────────────────────────────────────
		Button^ btnESP32;
		Button^ btnRestauracion;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->mantenimientoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->medicamentosToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->recetasToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->alarmasToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pacientesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->administradoresToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->reportesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->cumplimientoDiarioToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->registroDeTomasToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->dosisOmitidasToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->puntualidadToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();

			// menuStrip1
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array<System::Windows::Forms::ToolStripItem^>(2) {
				this->mantenimientoToolStripMenuItem,
					this->reportesToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1200, 28);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";

			// mantenimientoToolStripMenuItem
			this->mantenimientoToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array<System::Windows::Forms::ToolStripItem^>(5) {
				this->medicamentosToolStripMenuItem,
					this->recetasToolStripMenuItem,
					this->alarmasToolStripMenuItem,
					this->pacientesToolStripMenuItem,
					this->administradoresToolStripMenuItem
			});
			this->mantenimientoToolStripMenuItem->Name = L"mantenimientoToolStripMenuItem";
			this->mantenimientoToolStripMenuItem->Text = L"Mantenimiento";

			this->medicamentosToolStripMenuItem->Name = L"medicamentosToolStripMenuItem";
			this->medicamentosToolStripMenuItem->Text = L"Medicamentos";
			this->medicamentosToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmPrincipal::medicamentosToolStripMenuItem_Click);

			this->recetasToolStripMenuItem->Name = L"recetasToolStripMenuItem";
			this->recetasToolStripMenuItem->Text = L"Recetas";
			this->recetasToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmPrincipal::recetasToolStripMenuItem_Click);

			this->alarmasToolStripMenuItem->Name = L"alarmasToolStripMenuItem";
			this->alarmasToolStripMenuItem->Text = L"Alarmas";
			this->alarmasToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmPrincipal::alarmasToolStripMenuItem_Click);

			this->pacientesToolStripMenuItem->Name = L"pacientesToolStripMenuItem";
			this->pacientesToolStripMenuItem->Text = L"Pacientes";
			this->pacientesToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmPrincipal::pacientesToolStripMenuItem_Click);

			this->administradoresToolStripMenuItem->Name = L"administradoresToolStripMenuItem";
			this->administradoresToolStripMenuItem->Text = L"Administradores";
			this->administradoresToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmPrincipal::administradoresToolStripMenuItem_Click);

			// reportesToolStripMenuItem
			this->reportesToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array<System::Windows::Forms::ToolStripItem^>(4) {
				this->cumplimientoDiarioToolStripMenuItem,
					this->registroDeTomasToolStripMenuItem,
					this->dosisOmitidasToolStripMenuItem,
					this->puntualidadToolStripMenuItem
			});
			this->reportesToolStripMenuItem->Name = L"reportesToolStripMenuItem";
			this->reportesToolStripMenuItem->Text = L"Reportes";

			this->cumplimientoDiarioToolStripMenuItem->Name = L"cumplimientoDiarioToolStripMenuItem";
			this->cumplimientoDiarioToolStripMenuItem->Text = L"Cumplimiento diario";
			this->cumplimientoDiarioToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmPrincipal::cumplimientoDiarioToolStripMenuItem_Click);

			this->registroDeTomasToolStripMenuItem->Name = L"registroDeTomasToolStripMenuItem";
			this->registroDeTomasToolStripMenuItem->Text = L"Dispensado";
			this->registroDeTomasToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmPrincipal::registroDeTomasToolStripMenuItem_Click);

			this->dosisOmitidasToolStripMenuItem->Name = L"dosisOmitidasToolStripMenuItem";
			this->dosisOmitidasToolStripMenuItem->Text = L"Dosis Omitidas";
			this->dosisOmitidasToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmPrincipal::dosisOmitidasToolStripMenuItem_Click);

			this->puntualidadToolStripMenuItem->Name = L"puntualidadToolStripMenuItem";
			this->puntualidadToolStripMenuItem->Text = L"Puntualidad";
			this->puntualidadToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmPrincipal::puntualidadToolStripMenuItem_Click);

			// frmPrincipal
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1200, 714);
			this->Controls->Add(this->menuStrip1);
			this->IsMdiContainer = true;
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"frmPrincipal";
			this->Text = L"MediCheck";
			this->Load += gcnew System::EventHandler(this, &frmPrincipal::frmPrincipal_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion

		// ═══════════════════════════════════════════════════════════════════════════
		// HELPERS
		// ═══════════════════════════════════════════════════════════════════════════
	private:
		// Comparación flexible, igual que en frmDispensado / frmAlertasCriticas.
		// Usar esto en vez de "==" porque los estados/tipos son texto libre en la BD
		// (ej. el estado real puede ser "Tomada", no "Completado").
		bool Contiene(String^ texto, String^ valor) {
			return !String::IsNullOrWhiteSpace(texto) &&
				texto->IndexOf(valor, StringComparison::OrdinalIgnoreCase) >= 0;
		}

		// Un evento es "de dosis" si corresponde a una toma de medicamento
		// (excluye alertas de hardware / alarmas criticas del dispensador).
		bool EsEventoDeDosis(MODEL::LogEvento^ evento) {
			return evento != nullptr &&
				(Contiene(evento->getTipoEvento(), "Toma") || Contiene(evento->getTipoEvento(), "Dosis"));
		}

		bool EsTomada(MODEL::LogEvento^ evento) {
			return evento != nullptr && Contiene(evento->getEstado(), "Tomada");
		}

		bool EsRetraso(MODEL::LogEvento^ evento) {
			return evento != nullptr && Contiene(evento->getEstado(), "Retraso");
		}

		bool EsExitosa(MODEL::LogEvento^ evento) {
			return EsTomada(evento) || EsRetraso(evento);
		}

		bool EsOmitida(MODEL::LogEvento^ evento) {
			return evento != nullptr && EsEventoDeDosis(evento) &&
				(Contiene(evento->getEstado(), "Omitida") ||
					Contiene(evento->getEstado(), "No tomada") ||
					Contiene(evento->getEstado(), "Omision"));
		}

		bool EsHardware(MODEL::LogEvento^ evento) {
			return evento != nullptr &&
				(Contiene(evento->getTipoEvento(), "Error Hardware") ||
					Contiene(evento->getTipoEvento(), "Alerta Critica") ||
					Contiene(evento->getOrigen(), "Alarma Critica") ||
					Contiene(evento->getOrigen(), "Error"));
		}

		// Fecha real del evento: usa fechaHoraReal si existe, si no, la programada.
		// (igual que FechaEvento() en frmAlertasCriticas)
		DateTime FechaEvento(MODEL::LogEvento^ evento) {
			return evento->getFechaHoraReal() == DateTime::MinValue
				? evento->getFechaHoraProgramada()
				: evento->getFechaHoraReal();
		}

		Button^ CrearBotonSidebar(String^ texto, int y)
		{
			Button^ btn = gcnew Button();
			btn->Text = texto;
			btn->Size = System::Drawing::Size(156, 40);
			btn->Location = Point(7, y);
			btn->FlatStyle = FlatStyle::Flat;
			btn->FlatAppearance->BorderSize = 0;
			btn->FlatAppearance->MouseOverBackColor = Color::FromArgb(30, 64, 96);
			btn->UseVisualStyleBackColor = false;
			btn->BackColor = Color::FromArgb(22, 51, 80);
			btn->ForeColor = Color::FromArgb(122, 173, 204);
			btn->Font = gcnew System::Drawing::Font(L"Segoe UI", 9.5f);
			btn->UseCompatibleTextRendering = true;
			btn->TextAlign = ContentAlignment::MiddleLeft;
			btn->Padding = System::Windows::Forms::Padding(10, 0, 0, 0);
			btn->Cursor = Cursors::Hand;
			return btn;
		}

		Panel^ CrearCard(String^ titulo, String^ valor, Color colorBorde, int x, int y, Label^% lblValorDestino)
		{
			Panel^ card = gcnew Panel();
			card->Size = System::Drawing::Size(195, 108);
			card->Location = Point(x, y);
			card->BackColor = Color::White;

			Panel^ borde = gcnew Panel();
			borde->Size = System::Drawing::Size(195, 5);
			borde->Location = Point(0, 0);
			borde->BackColor = colorBorde;
			card->Controls->Add(borde);

			Label^ lblT = gcnew Label();
			lblT->Text = titulo;
			lblT->BackColor = Color::White;
			lblT->ForeColor = Color::FromArgb(136, 136, 136);
			lblT->Font = gcnew System::Drawing::Font(L"Segoe UI", 9.5f);
			lblT->Location = Point(14, 18);
			lblT->AutoSize = true;
			card->Controls->Add(lblT);

			Label^ lblV = gcnew Label();
			lblV->Text = valor;
			lblV->BackColor = Color::White;
			lblV->ForeColor = Color::FromArgb(26, 58, 82);
			lblV->Font = gcnew System::Drawing::Font(L"Segoe UI", 25.0f, FontStyle::Bold);
			lblV->Location = Point(12, 46);
			lblV->AutoSize = true;
			card->Controls->Add(lblV);
			lblValorDestino = lblV;

			return card;
		}

		// Panel blanco con título y borde izquierdo de color
		Panel^ CrearPanelSeccion(String^ titulo, Color colorAccento, int x, int y, int ancho, int alto)
		{
			Panel^ p = gcnew Panel();
			p->Size = System::Drawing::Size(ancho, alto);
			p->Location = Point(x, y);
			p->BackColor = Color::White;

			Panel^ acento = gcnew Panel();
			acento->Size = System::Drawing::Size(3, alto);
			acento->Location = Point(0, 0);
			acento->BackColor = colorAccento;
			p->Controls->Add(acento);

			Label^ lbl = gcnew Label();
			lbl->Text = titulo;
			lbl->Font = gcnew System::Drawing::Font(L"Segoe UI", 11.0f, FontStyle::Bold);
			lbl->ForeColor = Color::FromArgb(26, 58, 82);
			lbl->Location = Point(16, 14);
			lbl->AutoSize = true;
			p->Controls->Add(lbl);

			return p;
		}

		String^ FormatearCumplimiento(double porcentaje)
		{
			return porcentaje < 0.0 ? L"--%" : String::Format("{0:F0}%", porcentaje);
		}

		void ResaltarBoton(Button^ btnActivo)
		{
			array<Button^>^ botones = {
				btnInicio, btnMedicamentos, btnRecetas, btnAlarmas,
				btnPacientes, btnAdmins, btnCumplimiento,
				btnRegistroTomas, btnDosisOmitidas, btnPuntualidad,
				btnAlertasCriticas, btnUsoSistema, btnAdherenciaMedicamento,
				btnTendencias, btnESP32, btnRestauracion
			};
			for each (Button ^ btn in botones) {
				btn->BackColor = Color::Transparent;
				btn->ForeColor = Color::FromArgb(122, 173, 204);
			}
			btnActivo->BackColor = Color::FromArgb(30, 64, 96);
			btnActivo->ForeColor = Color::FromArgb(225, 245, 238);
		}

		// ═══════════════════════════════════════════════════════════════════════════
		// LÓGICA DEL DASHBOARD (segundo plano + hilo visual)
		// ═══════════════════════════════════════════════════════════════════════════
	private:
		void ActualizarDashboard()
		{
			if (dashboardActualizandose) return;
			dashboardActualizandose = true;
			System::Threading::ThreadPool::QueueUserWorkItem(
				gcnew System::Threading::WaitCallback(this, &frmPrincipal::CargarDashboardEnSegundoPlano));
		}

		void CargarDashboardEnSegundoPlano(Object^ estado)
		{
			dashboardDisponible = true;
			try {
				PacienteController^ pacientesCtrl = gcnew PacienteController();
				MedicamentoController^ medicamentosCtrl = gcnew MedicamentoController();
				AlarmaController^ alarmasCtrl = gcnew AlarmaController();
				GeneradorReportesController^ reportesCtrl = gcnew GeneradorReportesController();
				reportesCtrl->CargarDatos();

				// ── Métricas básicas ──────────────────────────────────────────
				dashboardPacientes = pacientesCtrl->ObtenerCantidadPacientesActivos();
				dashboardMedicamentos = medicamentosCtrl->ObtenerCantidadMedicamentos();
				dashboardAlarmas = alarmasCtrl->ObtenerCantidadAlarmas();
				dashboardCumplimiento = reportesCtrl->ObtenerPorcentajeCumplimientoGlobal();

				// ── Eventos del dia (por fecha REAL si existe, si no la programada) ──
				List<MODEL::LogEvento^>^ todos = reportesCtrl->ObtenerTodos();

				dashDosisOmitidas = 0;
				dashAlertasCriticas = 0;
				dashCumplimientoPacientes = gcnew List<CumplimientoPacienteDTO^>();

				Dictionary<String^, array<int>^>^ mapa = gcnew Dictionary<String^, array<int>^>();

				for each (MODEL::LogEvento ^ e in todos) {
					DateTime fecha = FechaEvento(e);
					if (fecha == DateTime::MinValue || fecha.Date != DateTime::Today)
						continue;

					// Dosis omitidas hoy
					if (EsOmitida(e))
						dashDosisOmitidas++;

					// Alertas criticas (hardware / dispensador) hoy
					if (EsHardware(e))
						dashAlertasCriticas++;

					// Cumplimiento por paciente: solo eventos de dosis (tomada/retraso/omitida)
					if (EsEventoDeDosis(e) && (EsExitosa(e) || EsOmitida(e))) {
						String^ nombre = String::IsNullOrWhiteSpace(e->getNombrePaciente())
							? "Sin paciente" : e->getNombrePaciente();
						array<int>^ valores = nullptr;
						if (!mapa->TryGetValue(nombre, valores)) {
							valores = gcnew array<int>(2);
							valores[0] = 0; // exitosos
							valores[1] = 0; // total
							mapa->Add(nombre, valores);
						}
						valores[1]++;
						if (EsExitosa(e))
							valores[0]++;
					}
				}

				// Convertir mapa a lista de DTOs
				for each (KeyValuePair<String^, array<int>^> kvp in mapa) {
					CumplimientoPacienteDTO^ dto = gcnew CumplimientoPacienteDTO();
					dto->nombrePaciente = kvp.Key;
					dto->porcentaje = kvp.Value[1] > 0
						? (int)((double)kvp.Value[0] / kvp.Value[1] * 100) : 0;
					dashCumplimientoPacientes->Add(dto);
				}

				dashPacientesRiesgo = 0;
				for each (CumplimientoPacienteDTO ^ dto in dashCumplimientoPacientes)
					if (dto->porcentaje < 80)
						dashPacientesRiesgo++;

				// Puntualidad aproximada del dia
				List<MODEL::LogEvento^>^ eventosPunt = reportesCtrl->ObtenerEventosReporte("Puntualidad");
				int puntOk = 0;
				for each (MODEL::LogEvento ^ e in eventosPunt)
					if (EsTomada(e)) puntOk++;
				dashPuntualidad = eventosPunt->Count > 0
					? (int)((double)puntOk / eventosPunt->Count * 100) : 0;
			}
			catch (Exception^) {
				dashboardDisponible = false;
			}

			if (this->IsDisposed || !this->IsHandleCreated) {
				dashboardActualizandose = false;
				return;
			}
			try {
				this->BeginInvoke(gcnew MethodInvoker(this, &frmPrincipal::AplicarDashboard));
			}
			catch (Exception^) {
				dashboardActualizandose = false;
			}
		}

		void AplicarDashboard()
		{
			if (this->IsDisposed) { dashboardActualizandose = false; return; }

			// Fecha
			if (lblFechaDashboard != nullptr)
				lblFechaDashboard->Text = DateTime::Now.ToString("dddd, d 'de' MMMM 'de' yyyy");
			if (lblUltimaActualizacion != nullptr)
				lblUltimaActualizacion->Text =
				L"Última actualización: " + DateTime::Now.ToString("HH:mm:ss");

			// ── Métricas básicas ──────────────────────────────────────────────
			if (dashboardDisponible) {
				if (lblValorPacientes != nullptr) lblValorPacientes->Text = dashboardPacientes.ToString();
				if (lblValorMedicamentos != nullptr) lblValorMedicamentos->Text = dashboardMedicamentos.ToString();
				if (lblValorAlarmas != nullptr) lblValorAlarmas->Text = dashboardAlarmas.ToString();
				if (lblValorCumplimiento != nullptr) {
					lblValorCumplimiento->Text = FormatearCumplimiento(dashboardCumplimiento);
					lblValorCumplimiento->ForeColor = dashboardCumplimiento < 0.0
						? Color::FromArgb(26, 58, 82)
						: dashboardCumplimiento >= 80.0
						? Color::FromArgb(20, 125, 95)
						: Color::FromArgb(180, 50, 50);
				}
				if (lblEstado != nullptr) lblEstado->Text = L"Dashboard actualizado";
			}
			else {
				if (lblValorCumplimiento != nullptr) lblValorCumplimiento->Text = L"--%";
				if (lblEstado != nullptr) lblEstado->Text = L"Sin conexion a la base de datos";
				dashboardActualizandose = false;
				return;
			}

			// ── Limpiar paneles extendidos anteriores ─────────────────────────
			if (panelCumplimiento != nullptr) {
				panelDashboard->Controls->Remove(panelCumplimiento);
				panelCumplimiento = nullptr;
			}
			if (panelResumen != nullptr) {
				panelDashboard->Controls->Remove(panelResumen);
				panelResumen = nullptr;
			}

			// ── Panel: Cumplimiento por paciente ──────────────────────────────
			int cantPac = (dashCumplimientoPacientes != nullptr)
				? dashCumplimientoPacientes->Count : 0;

			int altoComp = 62 + cantPac * 40 + 20;
			if (altoComp < 180) altoComp = 180;

			panelCumplimiento = CrearPanelSeccion(
				L"Cumplimiento diario por paciente",
				Color::FromArgb(55, 138, 221),
				190, 285, 1000, altoComp);

			int ayC = 54;
			if (dashCumplimientoPacientes != nullptr &&
				dashCumplimientoPacientes->Count > 0) {

				for each (CumplimientoPacienteDTO ^ c in dashCumplimientoPacientes) {
					Label^ lNom = gcnew Label();
					lNom->Text = c->nombrePaciente;
					lNom->Font = gcnew System::Drawing::Font(L"Segoe UI", 10.0f);
					lNom->ForeColor = Color::FromArgb(26, 58, 82);
					lNom->Location = Point(20, ayC);
					lNom->Size = System::Drawing::Size(220, 24);
					lNom->AutoEllipsis = true;
					panelCumplimiento->Controls->Add(lNom);

					Panel^ barBg = gcnew Panel();
					barBg->Size = System::Drawing::Size(650, 14);
					barBg->Location = Point(260, ayC + 5);
					barBg->BackColor = Color::FromArgb(225, 232, 240);
					panelCumplimiento->Controls->Add(barBg);

					Color colorBarra = c->porcentaje >= 90
						? Color::FromArgb(29, 158, 117)
						: c->porcentaje >= 70
						? Color::FromArgb(55, 138, 221)
						: Color::FromArgb(239, 159, 39);

					Panel^ barFill = gcnew Panel();
					barFill->Size = System::Drawing::Size(
						(int)(650.0 * c->porcentaje / 100.0), 14);
					barFill->Location = Point(0, 0);
					barFill->BackColor = colorBarra;
					barBg->Controls->Add(barFill);

					Label^ lPct = gcnew Label();
					lPct->Text = c->porcentaje.ToString() + "%";
					lPct->Font = gcnew System::Drawing::Font(
						L"Segoe UI", 10.0f, FontStyle::Bold);
					lPct->ForeColor = colorBarra;
					lPct->Location = Point(928, ayC);
					lPct->AutoSize = true;
					panelCumplimiento->Controls->Add(lPct);

					ayC += 40;
				}
			}
			else {
				Label^ lVacio = gcnew Label();
				lVacio->Text = L"Sin datos de cumplimiento registrados para hoy.";
				lVacio->Font = gcnew System::Drawing::Font(
					L"Segoe UI", 10.0f, FontStyle::Italic);
				lVacio->ForeColor = Color::FromArgb(150, 170, 185);
				lVacio->Location = Point(20, 62);
				lVacio->AutoSize = true;
				panelCumplimiento->Controls->Add(lVacio);
			}
			panelDashboard->Controls->Add(panelCumplimiento);

			// ── Panel: resumen ampliado con 4 indicadores ─────────────────────
			int yResumen = panelCumplimiento->Location.Y +
				panelCumplimiento->Height + 20;

			panelResumen = gcnew Panel();
			panelResumen->Size = System::Drawing::Size(1000, 96);
			panelResumen->Location = Point(190, yResumen);
			panelResumen->BackColor = Color::Transparent;
			panelDashboard->Controls->Add(panelResumen);

			array<String^>^ miniTit = {
				L"Dosis omitidas hoy",
				L"Puntualidad promedio",
				L"Alertas críticas",
				L"Pacientes en seguimiento"
			};

			array<String^>^ miniVal = {
				dashDosisOmitidas.ToString(),
				dashPuntualidad.ToString() + "%",
				dashAlertasCriticas.ToString(),
				dashPacientesRiesgo.ToString()
			};

			array<Color>^ miniCol = {
				Color::FromArgb(29, 158, 117),
				Color::FromArgb(55, 138, 221),
				Color::FromArgb(239, 159, 39),
				Color::FromArgb(180, 85, 70)
			};

			for (int i = 0; i < 4; i++) {
				Panel^ mini = gcnew Panel();
				mini->Size = System::Drawing::Size(238, 88);
				mini->Location = Point(i * 254, 0);
				mini->BackColor = Color::White;
				panelResumen->Controls->Add(mini);

				Panel^ acc = gcnew Panel();
				acc->Size = System::Drawing::Size(5, 88);
				acc->Location = Point(0, 0);
				acc->BackColor = miniCol[i];
				mini->Controls->Add(acc);

				Label^ lT = gcnew Label();
				lT->Text = miniTit[i];
				lT->Font = gcnew System::Drawing::Font(L"Segoe UI", 9.0f);
				lT->ForeColor = Color::FromArgb(110, 125, 140);
				lT->Location = Point(16, 14);
				lT->Size = System::Drawing::Size(210, 22);
				lT->AutoEllipsis = true;
				mini->Controls->Add(lT);

				Label^ lV = gcnew Label();
				lV->Text = miniVal[i];
				lV->Font = gcnew System::Drawing::Font(
					L"Segoe UI", 22.0f, FontStyle::Bold);
				lV->ForeColor = miniCol[i];
				lV->Location = Point(16, 40);
				lV->AutoSize = true;
				mini->Controls->Add(lV);
			}

			dashboardActualizandose = false;
		}

		// ═══════════════════════════════════════════════════════════════════════════
		// FORM LOAD
		// ═══════════════════════════════════════════════════════════════════════════
	private: System::Void frmPrincipal_Load(System::Object^ sender, System::EventArgs^ e)
	{
		this->UseWaitCursor = false;
		this->Cursor = Cursors::Default;
		this->WindowState = FormWindowState::Maximized;
		this->ShowIcon = true;
		try { this->Icon = gcnew System::Drawing::Icon(L"medicheck.ico"); }
		catch (...) {}

		// Menú
		this->menuStrip1->BackColor = Color::FromArgb(26, 58, 82);
		this->menuStrip1->ForeColor = Color::White;
		this->menuStrip1->Font = gcnew System::Drawing::Font(L"Segoe UI", 9.5f);
		this->menuStrip1->Visible = false;
		this->BackColor = Color::FromArgb(238, 243, 247);
		this->StartPosition = FormStartPosition::CenterScreen;

		Color dropBg = Color::FromArgb(22, 51, 80);
		Color dropFg = Color::FromArgb(181, 212, 244);
		medicamentosToolStripMenuItem->BackColor = dropBg; medicamentosToolStripMenuItem->ForeColor = dropFg;
		recetasToolStripMenuItem->BackColor = dropBg; recetasToolStripMenuItem->ForeColor = dropFg;
		alarmasToolStripMenuItem->BackColor = dropBg; alarmasToolStripMenuItem->ForeColor = dropFg;
		pacientesToolStripMenuItem->BackColor = dropBg; pacientesToolStripMenuItem->ForeColor = dropFg;
		administradoresToolStripMenuItem->BackColor = dropBg; administradoresToolStripMenuItem->ForeColor = dropFg;
		cumplimientoDiarioToolStripMenuItem->BackColor = dropBg; cumplimientoDiarioToolStripMenuItem->ForeColor = dropFg;
		registroDeTomasToolStripMenuItem->BackColor = dropBg; registroDeTomasToolStripMenuItem->ForeColor = dropFg;
		dosisOmitidasToolStripMenuItem->BackColor = dropBg; dosisOmitidasToolStripMenuItem->ForeColor = dropFg;
		puntualidadToolStripMenuItem->BackColor = dropBg; puntualidadToolStripMenuItem->ForeColor = dropFg;

		// ── SIDEBAR ───────────────────────────────────────────────────────────
		panelSidebar = gcnew Panel();
		panelSidebar->Dock = DockStyle::Left;
		panelSidebar->Width = 170;
		panelSidebar->BackColor = Color::FromArgb(22, 51, 80);
		panelSidebar->AutoScroll = true;
		this->Controls->Add(panelSidebar);
		panelSidebar->BringToFront();

		// Cabecera
		Panel^ sideHeader = gcnew Panel();
		sideHeader->Size = System::Drawing::Size(170, 56);
		sideHeader->Location = Point(0, 0);
		sideHeader->BackColor = Color::FromArgb(16, 40, 62);
		panelSidebar->Controls->Add(sideHeader);

		Label^ lblApp = gcnew Label();
		lblApp->Text = L"MediCheck";
		lblApp->BackColor = Color::FromArgb(16, 40, 62);
		lblApp->ForeColor = Color::FromArgb(93, 202, 165);
		lblApp->Font = gcnew System::Drawing::Font(L"Segoe UI", 9.5f, FontStyle::Bold);
		lblApp->Location = Point(10, 10);
		lblApp->Size = System::Drawing::Size(155, 20);
		sideHeader->Controls->Add(lblApp);

		Label^ lblSub = gcnew Label();
		lblSub->Text = L"Sistema de gestion";
		lblSub->BackColor = Color::FromArgb(16, 40, 62);
		lblSub->ForeColor = Color::FromArgb(74, 122, 155);
		lblSub->Font = gcnew System::Drawing::Font(L"Segoe UI", 7.5f);
		lblSub->Location = Point(10, 32);
		lblSub->AutoSize = true;
		sideHeader->Controls->Add(lblSub);

		// Sección MÓDULOS
		Label^ lblModulos = gcnew Label();
		lblModulos->Text = L"MÓDULOS";
		lblModulos->BackColor = Color::FromArgb(22, 51, 80);
		lblModulos->ForeColor = Color::FromArgb(74, 122, 155);
		lblModulos->Font = gcnew System::Drawing::Font(L"Segoe UI", 7.5f, FontStyle::Bold);
		lblModulos->Location = Point(12, 66);
		lblModulos->AutoSize = true;
		panelSidebar->Controls->Add(lblModulos);

		btnInicio = CrearBotonSidebar(L"  Inicio", 90);
		btnMedicamentos = CrearBotonSidebar(L"  Medicamentos", 132);
		btnRecetas = CrearBotonSidebar(L"  Recetas", 174);
		btnAlarmas = CrearBotonSidebar(L"  Alarmas", 216);
		btnPacientes = CrearBotonSidebar(L"  Pacientes", 258);
		btnAdmins = CrearBotonSidebar(L"  Administradores", 300);

		Panel^ sep1 = gcnew Panel();
		sep1->Size = System::Drawing::Size(140, 1);
		sep1->Location = Point(15, 346);
		sep1->BackColor = Color::FromArgb(30, 64, 96);
		panelSidebar->Controls->Add(sep1);

		// Sección REPORTES
		Label^ lblReportes = gcnew Label();
		lblReportes->Text = L"REPORTES";
		lblReportes->BackColor = Color::FromArgb(22, 51, 80);
		lblReportes->ForeColor = Color::FromArgb(74, 122, 155);
		lblReportes->Font = gcnew System::Drawing::Font(L"Segoe UI", 7.5f, FontStyle::Bold);
		lblReportes->Location = Point(12, 356);
		lblReportes->AutoSize = true;
		panelSidebar->Controls->Add(lblReportes);

		btnCumplimiento = CrearBotonSidebar(L"  Cumplimiento", 374);
		btnRegistroTomas = CrearBotonSidebar(L"  Dispensado", 416);
		btnDosisOmitidas = CrearBotonSidebar(L"  Dosis Omitidas", 458);
		btnPuntualidad = CrearBotonSidebar(L"  Puntualidad", 500);
		btnAlertasCriticas = CrearBotonSidebar(L"  Alertas Criticas", 542);
		btnUsoSistema = CrearBotonSidebar(L"  Uso del Sistema", 584);
		btnAdherenciaMedicamento = CrearBotonSidebar(L"  Adherencia Medic.", 626);
		btnTendencias = CrearBotonSidebar(L"  Tendencias", 668);

		Panel^ sep2 = gcnew Panel();
		sep2->Size = System::Drawing::Size(140, 1);
		sep2->Location = Point(15, 714);
		sep2->BackColor = Color::FromArgb(30, 64, 96);
		panelSidebar->Controls->Add(sep2);

		btnESP32 = CrearBotonSidebar(L"  Pruebas ESP32", 724);
		btnRestauracion = CrearBotonSidebar(L"  Restauracion", 766);

		// Resaltar Inicio por defecto
		btnInicio->BackColor = Color::FromArgb(30, 64, 96);
		btnInicio->ForeColor = Color::FromArgb(225, 245, 238);

		// Eventos módulos
		btnInicio->Click += gcnew EventHandler(this, &frmPrincipal::btnInicio_Click);
		btnMedicamentos->Click += gcnew EventHandler(this, &frmPrincipal::medicamentosToolStripMenuItem_Click);
		btnRecetas->Click += gcnew EventHandler(this, &frmPrincipal::recetasToolStripMenuItem_Click);
		btnAlarmas->Click += gcnew EventHandler(this, &frmPrincipal::alarmasToolStripMenuItem_Click);
		btnPacientes->Click += gcnew EventHandler(this, &frmPrincipal::pacientesToolStripMenuItem_Click);
		btnAdmins->Click += gcnew EventHandler(this, &frmPrincipal::administradoresToolStripMenuItem_Click);

		// Eventos reportes
		btnCumplimiento->Click += gcnew EventHandler(this, &frmPrincipal::cumplimientoDiarioToolStripMenuItem_Click);
		btnRegistroTomas->Click += gcnew EventHandler(this, &frmPrincipal::registroDeTomasToolStripMenuItem_Click);
		btnDosisOmitidas->Click += gcnew EventHandler(this, &frmPrincipal::dosisOmitidasToolStripMenuItem_Click);
		btnPuntualidad->Click += gcnew EventHandler(this, &frmPrincipal::puntualidadToolStripMenuItem_Click);
		btnAlertasCriticas->Click += gcnew EventHandler(this, &frmPrincipal::btnAlertasCriticas_Click);
		btnUsoSistema->Click += gcnew EventHandler(this, &frmPrincipal::btnUsoSistema_Click);
		btnAdherenciaMedicamento->Click += gcnew EventHandler(this, &frmPrincipal::btnAdherenciaMedicamento_Click);
		btnTendencias->Click += gcnew EventHandler(this, &frmPrincipal::btnTendencias_Click);
		btnESP32->Click += gcnew EventHandler(this, &frmPrincipal::btnESP32_Click);
		btnRestauracion->Click += gcnew EventHandler(this, &frmPrincipal::btnRestauracion_Click);

		// Agregar botones al sidebar
		panelSidebar->Controls->Add(btnInicio);
		panelSidebar->Controls->Add(btnMedicamentos);
		panelSidebar->Controls->Add(btnRecetas);
		panelSidebar->Controls->Add(btnAlarmas);
		panelSidebar->Controls->Add(btnPacientes);
		panelSidebar->Controls->Add(btnAdmins);
		panelSidebar->Controls->Add(btnCumplimiento);
		panelSidebar->Controls->Add(btnRegistroTomas);
		panelSidebar->Controls->Add(btnDosisOmitidas);
		panelSidebar->Controls->Add(btnPuntualidad);
		panelSidebar->Controls->Add(btnAlertasCriticas);
		panelSidebar->Controls->Add(btnUsoSistema);
		panelSidebar->Controls->Add(btnAdherenciaMedicamento);
		panelSidebar->Controls->Add(btnTendencias);
		panelSidebar->Controls->Add(btnESP32);
		panelSidebar->Controls->Add(btnRestauracion);

		// ── STATUS BAR ────────────────────────────────────────────────────────
		statusStrip1 = gcnew StatusStrip();
		statusStrip1->BackColor = Color::FromArgb(26, 58, 82);
		statusStrip1->SizingGrip = false;

		lblEstado = gcnew ToolStripStatusLabel();
		lblEstado->Text = L"Dispensador conectado";
		lblEstado->ForeColor = Color::FromArgb(93, 202, 165);
		lblEstado->Font = gcnew System::Drawing::Font(L"Segoe UI", 8.5f);

		lblSpring = gcnew ToolStripStatusLabel();
		lblSpring->Spring = true;

		lblInfoUsuario = gcnew ToolStripStatusLabel();
		lblInfoUsuario->Text = L"Administrador  |  " + DateTime::Now.ToString("dddd d MMM yyyy");
		lblInfoUsuario->ForeColor = Color::FromArgb(74, 122, 155);
		lblInfoUsuario->Font = gcnew System::Drawing::Font(L"Segoe UI", 8.5f);

		statusStrip1->Items->Add(lblEstado);
		statusStrip1->Items->Add(lblSpring);
		statusStrip1->Items->Add(lblInfoUsuario);
		this->Controls->Add(statusStrip1);

		// ── TIMERS ────────────────────────────────────────────────────────────
		timerReloj = gcnew System::Windows::Forms::Timer();
		timerReloj->Interval = 60000;
		timerReloj->Tick += gcnew EventHandler(this, &frmPrincipal::timerReloj_Tick);
		timerReloj->Start();

		timerDashboard = gcnew System::Windows::Forms::Timer();
		timerDashboard->Interval = 5000;
		timerDashboard->Tick += gcnew EventHandler(this, &frmPrincipal::timerDashboard_Tick);
		timerDashboard->Start();

		// ── PANEL DASHBOARD ───────────────────────────────────────────────────
		panelDashboard = gcnew Panel();
		panelDashboard->Dock = DockStyle::Fill;
		panelDashboard->BackColor = Color::FromArgb(238, 243, 247);
		panelDashboard->Padding = System::Windows::Forms::Padding(20);
		panelDashboard->AutoScroll = true;
		this->Controls->Add(panelDashboard);
		panelDashboard->BringToFront();
		panelSidebar->BringToFront();

		// Título
		Label^ lblBienvenida = gcnew Label();
		lblBienvenida->Text = L"Bienvenido al Sistema";
		lblBienvenida->BackColor = Color::FromArgb(238, 243, 247);
		lblBienvenida->ForeColor = Color::FromArgb(26, 58, 82);
		lblBienvenida->Font = gcnew System::Drawing::Font(L"Segoe UI", 20.0f, FontStyle::Bold);
		lblBienvenida->Location = Point(190, 24);
		lblBienvenida->AutoSize = true;
		panelDashboard->Controls->Add(lblBienvenida);

		lblFechaDashboard = gcnew Label();
		lblFechaDashboard->Text = DateTime::Now.ToString("dddd, d 'de' MMMM 'de' yyyy");
		lblFechaDashboard->BackColor = Color::FromArgb(238, 243, 247);
		lblFechaDashboard->ForeColor = Color::FromArgb(136, 136, 136);
		lblFechaDashboard->Font = gcnew System::Drawing::Font(L"Segoe UI", 10.5f);
		lblFechaDashboard->Location = Point(192, 66);
		lblFechaDashboard->AutoSize = true;
		panelDashboard->Controls->Add(lblFechaDashboard);

		lblUltimaActualizacion = gcnew Label();
		lblUltimaActualizacion->Text = L"Última actualización: --:--:--";
		lblUltimaActualizacion->BackColor = Color::FromArgb(238, 243, 247);
		lblUltimaActualizacion->ForeColor = Color::FromArgb(90, 115, 140);
		lblUltimaActualizacion->Font = gcnew System::Drawing::Font(L"Segoe UI", 9.0f);
		lblUltimaActualizacion->Location = Point(980, 70);
		lblUltimaActualizacion->AutoSize = true;
		panelDashboard->Controls->Add(lblUltimaActualizacion);

		Panel^ linea = gcnew Panel();
		linea->Size = System::Drawing::Size(1000, 1);
		linea->Location = Point(190, 100);
		linea->BackColor = Color::FromArgb(200, 215, 225);
		panelDashboard->Controls->Add(linea);

		// Tarjetas métricas
		panelDashboard->Controls->Add(CrearCard(L"Pacientes activos", L"...", Color::FromArgb(29, 158, 117), 190, 122, this->lblValorPacientes));
		panelDashboard->Controls->Add(CrearCard(L"Medicamentos", L"...", Color::FromArgb(55, 138, 221), 425, 122, this->lblValorMedicamentos));
		panelDashboard->Controls->Add(CrearCard(L"Alarmas registradas", L"...", Color::FromArgb(239, 159, 39), 660, 122, this->lblValorAlarmas));
		panelDashboard->Controls->Add(CrearCard(L"Cumplimiento global", L"--%", Color::FromArgb(93, 202, 165), 895, 122, this->lblValorCumplimiento));

		// Nota: se removió el bloque de "Accesos rápidos" y el panel de
		// "Próximas alarmas" (no había una fuente de datos confiable de horarios).

		// Disparar primera carga
		ActualizarDashboard();
	}

		   // ═══════════════════════════════════════════════════════════════════════════
		   // EVENTOS
		   // ═══════════════════════════════════════════════════════════════════════════
	private: System::Void timerReloj_Tick(System::Object^ sender, System::EventArgs^ e) {
		lblInfoUsuario->Text = L"Administrador  |  " + DateTime::Now.ToString("dddd d MMM yyyy  HH:mm");
	}

	private: System::Void timerDashboard_Tick(System::Object^ sender, System::EventArgs^ e) {
		if (panelDashboard != nullptr && panelDashboard->Visible)
			ActualizarDashboard();
	}

	private: System::Void btnInicio_Click(System::Object^ sender, System::EventArgs^ e) {
		ResaltarBoton(btnInicio);
		for each (Form ^ hijo in this->MdiChildren) hijo->Close();
		panelDashboard->Visible = true;
		ActualizarDashboard();
		panelDashboard->BringToFront();
		panelSidebar->BringToFront();
	}

	private: System::Void medicamentosToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		ResaltarBoton(btnMedicamentos);
		panelDashboard->Visible = false;
		for each (Form ^ hijo in this->MdiChildren) hijo->Close();
		frmMantMedicamentos^ v = gcnew frmMantMedicamentos();
		v->MdiParent = this; v->Dock = DockStyle::Fill; v->Show();
	}

	private: System::Void recetasToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		ResaltarBoton(btnRecetas);
		panelDashboard->Visible = false;
		for each (Form ^ hijo in this->MdiChildren) hijo->Close();
		frmMantReceta^ v = gcnew frmMantReceta();
		v->MdiParent = this; v->Dock = DockStyle::Fill; v->Show();
	}

	private: System::Void pacientesToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		ResaltarBoton(btnPacientes);
		panelDashboard->Visible = false;
		for each (Form ^ hijo in this->MdiChildren) hijo->Close();
		frmMantPacientes^ v = gcnew frmMantPacientes();
		v->MdiParent = this; v->Dock = DockStyle::Fill; v->Show();
	}

	private: System::Void administradoresToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		ResaltarBoton(btnAdmins);
		panelDashboard->Visible = false;
		for each (Form ^ hijo in this->MdiChildren) hijo->Close();
		frmMantAdministrador^ v = gcnew frmMantAdministrador();
		v->MdiParent = this; v->Dock = DockStyle::Fill; v->Show();
	}

	private: System::Void alarmasToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		ResaltarBoton(btnAlarmas);
		panelDashboard->Visible = false;
		for each (Form ^ hijo in this->MdiChildren) hijo->Close();
		frmMantAlarma^ v = gcnew frmMantAlarma();
		v->MdiParent = this; v->Dock = DockStyle::Fill; v->Show();
	}

	private: System::Void cumplimientoDiarioToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		ResaltarBoton(btnCumplimiento);
		panelDashboard->Visible = false;
		for each (Form ^ hijo in this->MdiChildren) hijo->Close();
		frmCumplimiento^ v = gcnew frmCumplimiento();
		v->MdiParent = this; v->Dock = DockStyle::Fill; v->Show();
	}

	private: System::Void registroDeTomasToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		ResaltarBoton(btnRegistroTomas);
		panelDashboard->Visible = false;
		for each (Form ^ hijo in this->MdiChildren) hijo->Close();
		frmDispensado^ v = gcnew frmDispensado();
		v->MdiParent = this; v->Dock = DockStyle::Fill; v->Show();
	}

	private: System::Void dosisOmitidasToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		ResaltarBoton(btnDosisOmitidas);
		panelDashboard->Visible = false;
		for each (Form ^ hijo in this->MdiChildren) hijo->Close();
		frmDosisOmitidas^ v = gcnew frmDosisOmitidas();
		v->MdiParent = this; v->Dock = DockStyle::Fill; v->Show();
	}

	private: System::Void puntualidadToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		ResaltarBoton(btnPuntualidad);
		panelDashboard->Visible = false;
		for each (Form ^ hijo in this->MdiChildren) hijo->Close();
		frmPuntualidad^ v = gcnew frmPuntualidad();
		v->MdiParent = this; v->Dock = DockStyle::Fill; v->Show();
	}

	private: System::Void btnAlertasCriticas_Click(System::Object^ sender, System::EventArgs^ e) {
		ResaltarBoton(btnAlertasCriticas);
		panelDashboard->Visible = false;
		for each (Form ^ hijo in this->MdiChildren) hijo->Close();
		frmAlertasCriticas^ v = gcnew frmAlertasCriticas();
		v->MdiParent = this; v->Dock = DockStyle::Fill; v->Show();
	}

	private: System::Void btnUsoSistema_Click(System::Object^ sender, System::EventArgs^ e) {
		ResaltarBoton(btnUsoSistema);
		panelDashboard->Visible = false;
		for each (Form ^ hijo in this->MdiChildren) hijo->Close();
		frmUsoSistema^ v = gcnew frmUsoSistema();
		v->MdiParent = this; v->Dock = DockStyle::Fill; v->Show();
	}

	private: System::Void btnAdherenciaMedicamento_Click(System::Object^ sender, System::EventArgs^ e) {
		ResaltarBoton(btnAdherenciaMedicamento);
		panelDashboard->Visible = false;
		for each (Form ^ hijo in this->MdiChildren) hijo->Close();
		frmAdherenciaMedicamento^ v = gcnew frmAdherenciaMedicamento();
		v->MdiParent = this; v->Dock = DockStyle::Fill; v->Show();
	}

	private: System::Void btnTendencias_Click(System::Object^ sender, System::EventArgs^ e) {
		ResaltarBoton(btnTendencias);
		panelDashboard->Visible = false;
		for each (Form ^ hijo in this->MdiChildren) hijo->Close();
		frmTendencias^ v = gcnew frmTendencias();
		v->MdiParent = this; v->Dock = DockStyle::Fill; v->Show();
	}

	private: System::Void btnESP32_Click(System::Object^ sender, System::EventArgs^ e) {
		ResaltarBoton(btnESP32);
		panelDashboard->Visible = false;
		for each (Form ^ hijo in this->MdiChildren) hijo->Close();
		frmPruebasESP32^ v = gcnew frmPruebasESP32();
		v->MdiParent = this; v->Dock = DockStyle::Fill; v->Show();
	}

	private: System::Void btnRestauracion_Click(System::Object^ sender, System::EventArgs^ e) {
		ResaltarBoton(btnRestauracion);
		panelDashboard->Visible = false;
		for each (Form ^ hijo in this->MdiChildren) hijo->Close();
		frmRestauracion^ v = gcnew frmRestauracion();
		v->MdiParent = this; v->Dock = DockStyle::Fill; v->Show();
	}
	};
}