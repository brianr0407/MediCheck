#include "frmAgregarPaciente.h"
#include "frmModificarPaciente.h"
#include "frmEliminarPaciente.h"
#include "frmAgregarRecetasPaciente.h"
#pragma once

namespace VIEW {
	using namespace MODEL;
	using namespace CONTROLLER;
	using namespace System;
	using namespace System::Collections::Generic;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class frmMantPacientes : public System::Windows::Forms::Form
	{
	public:
		frmMantPacientes(void)
		{
			InitializeComponent();
			this->pacienteController = gcnew PacienteController();
			this->recetaController = gcnew RecetaController();
			this->ControlBox = false;
		}

	protected:
		~frmMantPacientes()
		{
			if (components)
				delete components;
		}

	private:
		PacienteController^ pacienteController;
		RecetaController^ recetaController;

		System::Windows::Forms::Panel^ panelHeader;
		System::Windows::Forms::Label^ lblTitulo;
		System::Windows::Forms::Panel^ panelCuerpo;
		System::Windows::Forms::Panel^ panelBusqueda;
		System::Windows::Forms::Label^ lblBusqueda;
		System::Windows::Forms::Panel^ lineaBusqueda;
		System::Windows::Forms::Label^ label1;
		System::Windows::Forms::TextBox^ textBox1;
		System::Windows::Forms::Label^ label2;
		System::Windows::Forms::TextBox^ textBox2;
		System::Windows::Forms::Label^ label3;
		System::Windows::Forms::TextBox^ textBox3;
		System::Windows::Forms::Button^ button4;
		System::Windows::Forms::Panel^ panelResultados;
		System::Windows::Forms::Label^ lblResultados;
		System::Windows::Forms::DataGridView^ dataGridView1;
		System::Windows::Forms::Panel^ panelOpciones;
		System::Windows::Forms::Button^ button1;
		System::Windows::Forms::Button^ button2;
		System::Windows::Forms::Button^ button3;
		System::Windows::Forms::Button^ button5;
		System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column5;






		   System::ComponentModel::Container^ components;


#pragma region Windows Form Designer generated code
		   void InitializeComponent(void)
		   {
			   System::Windows::Forms::DataGridViewCellStyle^ dgvHeaderStyle =
				   (gcnew System::Windows::Forms::DataGridViewCellStyle());
			   System::Windows::Forms::DataGridViewCellStyle^ dgvCellStyle =
				   (gcnew System::Windows::Forms::DataGridViewCellStyle());

			   this->panelHeader = (gcnew System::Windows::Forms::Panel());
			   this->lblTitulo = (gcnew System::Windows::Forms::Label());
			   this->panelCuerpo = (gcnew System::Windows::Forms::Panel());
			   this->panelBusqueda = (gcnew System::Windows::Forms::Panel());
			   this->lblBusqueda = (gcnew System::Windows::Forms::Label());
			   this->lineaBusqueda = (gcnew System::Windows::Forms::Panel());
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			   this->label2 = (gcnew System::Windows::Forms::Label());
			   this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			   this->label3 = (gcnew System::Windows::Forms::Label());
			   this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			   this->button4 = (gcnew System::Windows::Forms::Button());
			   this->panelResultados = (gcnew System::Windows::Forms::Panel());
			   this->lblResultados = (gcnew System::Windows::Forms::Label());
			   this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			   this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->panelOpciones = (gcnew System::Windows::Forms::Panel());
			   this->button2 = (gcnew System::Windows::Forms::Button());
			   this->button3 = (gcnew System::Windows::Forms::Button());
			   this->button1 = (gcnew System::Windows::Forms::Button());
			   this->button5 = (gcnew System::Windows::Forms::Button());
			   this->button6 = (gcnew System::Windows::Forms::Button());

			   System::Windows::Forms::Panel^ panelTituloResultados =
				   (gcnew System::Windows::Forms::Panel());
			   System::Windows::Forms::Panel^ lineaOpciones =
				   (gcnew System::Windows::Forms::Panel());

			   this->panelHeader->SuspendLayout();
			   this->panelCuerpo->SuspendLayout();
			   this->panelBusqueda->SuspendLayout();
			   this->panelResultados->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			   this->panelOpciones->SuspendLayout();
			   panelTituloResultados->SuspendLayout();
			   this->SuspendLayout();

			   // ── Encabezado ──────────────────────────────────────────────────────
			   this->panelHeader->BackColor = Color::FromArgb(15, 41, 66);
			   this->panelHeader->Controls->Add(this->lblTitulo);
			   this->panelHeader->Dock = DockStyle::Top;
			   this->panelHeader->Name = L"panelHeader";
			   this->panelHeader->Size = System::Drawing::Size(963, 52);
			   this->panelHeader->TabIndex = 0;

			   this->lblTitulo->AutoSize = true;
			   this->lblTitulo->Font = gcnew System::Drawing::Font(L"Segoe UI", 13, FontStyle::Regular);
			   this->lblTitulo->ForeColor = Color::FromArgb(220, 233, 245);
			   this->lblTitulo->Location = Point(22, 14);
			   this->lblTitulo->Name = L"lblTitulo";
			   this->lblTitulo->TabIndex = 0;
			   this->lblTitulo->Text = L"Pacientes";

			   // ── Cuerpo ──────────────────────────────────────────────────────────
			   this->panelCuerpo->BackColor = Color::FromArgb(241, 244, 248);
			   this->panelCuerpo->Controls->Add(this->panelResultados);
			   this->panelCuerpo->Controls->Add(this->panelBusqueda);
			   this->panelCuerpo->Controls->Add(this->panelOpciones);
			   this->panelCuerpo->Dock = DockStyle::Fill;
			   this->panelCuerpo->Name = L"panelCuerpo";
			   this->panelCuerpo->Size = System::Drawing::Size(963, 518);
			   this->panelCuerpo->TabIndex = 1;

			   // ── Panel de búsqueda ───────────────────────────────────────────────
			   this->panelBusqueda->BackColor = Color::FromArgb(247, 249, 251);
			   this->panelBusqueda->Controls->Add(this->lblBusqueda);
			   this->panelBusqueda->Controls->Add(this->lineaBusqueda);
			   this->panelBusqueda->Controls->Add(this->label1);
			   this->panelBusqueda->Controls->Add(this->textBox1);
			   this->panelBusqueda->Controls->Add(this->label2);
			   this->panelBusqueda->Controls->Add(this->textBox2);
			   this->panelBusqueda->Controls->Add(this->label3);
			   this->panelBusqueda->Controls->Add(this->textBox3);
			   this->panelBusqueda->Controls->Add(this->button4);
			   this->panelBusqueda->Dock = DockStyle::Left;
			   this->panelBusqueda->Width = 380;
			   this->panelBusqueda->Name = L"panelBusqueda";
			   this->panelBusqueda->TabIndex = 0;

			   this->lblBusqueda->AutoSize = true;
			   this->lblBusqueda->Font = gcnew System::Drawing::Font(L"Segoe UI", 9, FontStyle::Regular);
			   this->lblBusqueda->ForeColor = Color::FromArgb(100, 120, 140);
			   this->lblBusqueda->Location = Point(20, 18);
			   this->lblBusqueda->Name = L"lblBusqueda";
			   this->lblBusqueda->Text = L"BÚSQUEDA";

			   this->lineaBusqueda->BackColor = Color::FromArgb(218, 227, 236);
			   this->lineaBusqueda->Location = Point(20, 40);
			   this->lineaBusqueda->Name = L"lineaBusqueda";
			   this->lineaBusqueda->Size = System::Drawing::Size(340, 1);

			   this->label1->AutoSize = true;
			   this->label1->Font = gcnew System::Drawing::Font(L"Segoe UI", 8, FontStyle::Bold);
			   this->label1->ForeColor = Color::FromArgb(90, 115, 140);
			   this->label1->Location = Point(20, 56);
			   this->label1->Text = L"# ID";

			   this->textBox1->BorderStyle = BorderStyle::FixedSingle;
			   this->textBox1->Font = gcnew System::Drawing::Font(L"Segoe UI", 9.5F);
			   this->textBox1->BackColor = Color::White;
			   this->textBox1->ForeColor = Color::FromArgb(30, 50, 70);
			   this->textBox1->Location = Point(20, 74);
			   this->textBox1->Name = L"textBox1";
			   this->textBox1->Size = System::Drawing::Size(340, 24);

			   this->label2->AutoSize = true;
			   this->label2->Font = gcnew System::Drawing::Font(L"Segoe UI", 8, FontStyle::Bold);
			   this->label2->ForeColor = Color::FromArgb(90, 115, 140);
			   this->label2->Location = Point(20, 116);
			   this->label2->Text = L"Nombre";

			   this->textBox2->BorderStyle = BorderStyle::FixedSingle;
			   this->textBox2->Font = gcnew System::Drawing::Font(L"Segoe UI", 9.5F);
			   this->textBox2->BackColor = Color::White;
			   this->textBox2->ForeColor = Color::FromArgb(30, 50, 70);
			   this->textBox2->Location = Point(20, 134);
			   this->textBox2->Name = L"textBox2";
			   this->textBox2->Size = System::Drawing::Size(340, 24);

			   this->label3->AutoSize = true;
			   this->label3->Font = gcnew System::Drawing::Font(L"Segoe UI", 8, FontStyle::Bold);
			   this->label3->ForeColor = Color::FromArgb(90, 115, 140);
			   this->label3->Location = Point(20, 174);
			   this->label3->Text = L"Apellido";

			   this->textBox3->BorderStyle = BorderStyle::FixedSingle;
			   this->textBox3->Font = gcnew System::Drawing::Font(L"Segoe UI", 9.5F);
			   this->textBox3->BackColor = Color::White;
			   this->textBox3->ForeColor = Color::FromArgb(30, 50, 70);
			   this->textBox3->Location = Point(20, 192);
			   this->textBox3->Name = L"textBox3";
			   this->textBox3->Size = System::Drawing::Size(340, 24);

			   this->button4->BackColor = Color::FromArgb(15, 41, 66);
			   this->button4->Cursor = Cursors::Hand;
			   this->button4->FlatAppearance->BorderSize = 0;
			   this->button4->FlatAppearance->MouseOverBackColor = Color::FromArgb(26, 62, 98);
			   this->button4->FlatStyle = FlatStyle::Flat;
			   this->button4->Font = gcnew System::Drawing::Font(L"Segoe UI", 9.5F);
			   this->button4->ForeColor = Color::FromArgb(220, 233, 245);
			   this->button4->Location = Point(20, 244);
			   this->button4->Name = L"button4";
			   this->button4->Size = System::Drawing::Size(340, 36);
			   this->button4->Text = L"Buscar";
			   this->button4->UseVisualStyleBackColor = false;
			   this->button4->Click += gcnew System::EventHandler(this, &frmMantPacientes::button4_Click);

			   // ── Resultados ──────────────────────────────────────────────────────
			   this->panelResultados->BackColor = Color::FromArgb(241, 244, 248);
			   this->panelResultados->Padding = System::Windows::Forms::Padding(16, 8, 16, 0);
			   this->panelResultados->Controls->Add(this->dataGridView1);
			   this->panelResultados->Controls->Add(panelTituloResultados);
			   this->panelResultados->Dock = DockStyle::Fill;
			   this->panelResultados->Name = L"panelResultados";

			   panelTituloResultados->BackColor = Color::FromArgb(241, 244, 248);
			   panelTituloResultados->Dock = DockStyle::Top;
			   panelTituloResultados->Height = 32;
			   panelTituloResultados->Controls->Add(this->lblResultados);

			   this->lblResultados->AutoSize = true;
			   this->lblResultados->Font = gcnew System::Drawing::Font(L"Segoe UI", 9, FontStyle::Regular);
			   this->lblResultados->ForeColor = Color::FromArgb(90, 115, 140);
			   this->lblResultados->Location = Point(0, 8);
			   this->lblResultados->Text = L"Resultados";

			   dgvHeaderStyle->Alignment = DataGridViewContentAlignment::MiddleLeft;
			   dgvHeaderStyle->BackColor = Color::FromArgb(36, 66, 98);
			   dgvHeaderStyle->Font = gcnew System::Drawing::Font(L"Segoe UI", 8.5F);
			   dgvHeaderStyle->ForeColor = Color::FromArgb(200, 218, 235);
			   dgvHeaderStyle->SelectionBackColor = Color::FromArgb(36, 66, 98);
			   dgvHeaderStyle->SelectionForeColor = Color::FromArgb(200, 218, 235);
			   dgvHeaderStyle->WrapMode = DataGridViewTriState::True;

			   dgvCellStyle->Alignment = DataGridViewContentAlignment::MiddleLeft;
			   dgvCellStyle->BackColor = Color::White;
			   dgvCellStyle->Font = gcnew System::Drawing::Font(L"Segoe UI", 9.5F);
			   dgvCellStyle->ForeColor = Color::FromArgb(40, 60, 80);
			   dgvCellStyle->SelectionBackColor = Color::FromArgb(210, 228, 248);
			   dgvCellStyle->SelectionForeColor = Color::FromArgb(12, 52, 100);
			   dgvCellStyle->WrapMode = DataGridViewTriState::False;

			   this->dataGridView1->AllowUserToAddRows = false;
			   this->dataGridView1->AllowUserToDeleteRows = false;
			   this->dataGridView1->BackgroundColor = Color::FromArgb(247, 249, 251);
			   this->dataGridView1->BorderStyle = BorderStyle::None;
			   this->dataGridView1->CellBorderStyle = DataGridViewCellBorderStyle::SingleHorizontal;
			   this->dataGridView1->GridColor = Color::FromArgb(220, 230, 240);
			   this->dataGridView1->ColumnHeadersBorderStyle = DataGridViewHeaderBorderStyle::None;
			   this->dataGridView1->ColumnHeadersDefaultCellStyle = dgvHeaderStyle;
			   this->dataGridView1->ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
			   this->dataGridView1->ColumnHeadersHeight = 36;
			   this->dataGridView1->DefaultCellStyle = dgvCellStyle;
			   this->dataGridView1->Columns->AddRange(gcnew cli::array<DataGridViewColumn^>(5) {
				   this->Column1, this->Column2, this->Column3, this->Column4, this->Column5
			   });
			   this->dataGridView1->EnableHeadersVisualStyles = false;
			   this->dataGridView1->Dock = DockStyle::Fill;
			   this->dataGridView1->MultiSelect = false;
			   this->dataGridView1->ReadOnly = true;
			   this->dataGridView1->RowHeadersVisible = false;
			   this->dataGridView1->RowTemplate->Height = 32;
			   this->dataGridView1->SelectionMode = DataGridViewSelectionMode::FullRowSelect;

			   this->Column1->HeaderText = L"#ID";
			   this->Column1->ReadOnly = true;
			   this->Column1->Width = 60;

			   this->Column2->HeaderText = L"Nombre";
			   this->Column2->ReadOnly = true;
			   this->Column2->Width = 150;

			   this->Column3->HeaderText = L"Apellido";
			   this->Column3->ReadOnly = true;
			   this->Column3->Width = 150;

			   this->Column4->HeaderText = L"En Casa";
			   this->Column4->ReadOnly = true;
			   this->Column4->Width = 90;

			   this->Column5->HeaderText = L"Días Estancia";
			   this->Column5->ReadOnly = true;
			   this->Column5->AutoSizeMode = DataGridViewAutoSizeColumnMode::Fill;

			   // ── Opciones ────────────────────────────────────────────────────────
			   this->panelOpciones->BackColor = Color::FromArgb(247, 249, 251);
			   this->panelOpciones->Controls->Add(this->button2);
			   this->panelOpciones->Controls->Add(this->button3);
			   this->panelOpciones->Controls->Add(this->button1);
			   this->panelOpciones->Controls->Add(this->button5);
			   this->panelOpciones->Controls->Add(this->button6);
			   this->panelOpciones->Controls->Add(lineaOpciones);
			   this->panelOpciones->Dock = DockStyle::Bottom;
			   this->panelOpciones->Height = 60;

			   lineaOpciones->BackColor = Color::FromArgb(210, 220, 232);
			   lineaOpciones->Dock = DockStyle::Top;
			   lineaOpciones->Height = 1;

			   // Eliminar
			   this->button2->BackColor = Color::FromArgb(252, 235, 235);
			   this->button2->FlatAppearance->BorderColor = Color::FromArgb(240, 160, 160);
			   this->button2->FlatAppearance->BorderSize = 1;
			   this->button2->FlatAppearance->MouseOverBackColor = Color::FromArgb(247, 193, 193);
			   this->button2->FlatStyle = FlatStyle::Flat;
			   this->button2->Cursor = Cursors::Hand;
			   this->button2->Font = gcnew System::Drawing::Font(L"Segoe UI", 9.5F);
			   this->button2->ForeColor = Color::FromArgb(163, 45, 45);
			   this->button2->Location = Point(20, 12);
			   this->button2->Size = System::Drawing::Size(140, 36);
			   this->button2->Text = L"Eliminar";
			   this->button2->UseVisualStyleBackColor = false;
			   this->button2->Click += gcnew System::EventHandler(this, &frmMantPacientes::button2_Click);

			   // Mostrar
			   this->button3->BackColor = Color::FromArgb(230, 241, 251);
			   this->button3->FlatAppearance->BorderColor = Color::FromArgb(158, 198, 240);
			   this->button3->FlatAppearance->BorderSize = 1;
			   this->button3->FlatAppearance->MouseOverBackColor = Color::FromArgb(181, 212, 244);
			   this->button3->FlatStyle = FlatStyle::Flat;
			   this->button3->Cursor = Cursors::Hand;
			   this->button3->Font = gcnew System::Drawing::Font(L"Segoe UI", 9.5F);
			   this->button3->ForeColor = Color::FromArgb(12, 68, 124);
			   this->button3->Location = Point(176, 12);
			   this->button3->Size = System::Drawing::Size(140, 36);
			   this->button3->Text = L"Mostrar";
			   this->button3->UseVisualStyleBackColor = false;
			   this->button3->Click += gcnew System::EventHandler(this, &frmMantPacientes::button3_Click);

			   // Agregar
			   this->button1->BackColor = Color::FromArgb(234, 243, 222);
			   this->button1->FlatAppearance->BorderColor = Color::FromArgb(168, 208, 106);
			   this->button1->FlatAppearance->BorderSize = 1;
			   this->button1->FlatAppearance->MouseOverBackColor = Color::FromArgb(192, 221, 151);
			   this->button1->FlatStyle = FlatStyle::Flat;
			   this->button1->Cursor = Cursors::Hand;
			   this->button1->Font = gcnew System::Drawing::Font(L"Segoe UI", 9.5F);
			   this->button1->ForeColor = Color::FromArgb(39, 80, 10);
			   this->button1->Location = Point(332, 12);
			   this->button1->Size = System::Drawing::Size(140, 36);
			   this->button1->Text = L"Agregar";
			   this->button1->UseVisualStyleBackColor = false;
			   this->button1->Click += gcnew System::EventHandler(this, &frmMantPacientes::button1_Click);

			   // Modificar
			   this->button5->BackColor = Color::FromArgb(250, 238, 218);
			   this->button5->FlatAppearance->BorderColor = Color::FromArgb(240, 192, 112);
			   this->button5->FlatAppearance->BorderSize = 1;
			   this->button5->FlatAppearance->MouseOverBackColor = Color::FromArgb(250, 199, 117);
			   this->button5->FlatStyle = FlatStyle::Flat;
			   this->button5->Cursor = Cursors::Hand;
			   this->button5->Font = gcnew System::Drawing::Font(L"Segoe UI", 9.5F);
			   this->button5->ForeColor = Color::FromArgb(99, 56, 6);
			   this->button5->Location = Point(488, 12);
			   this->button5->Size = System::Drawing::Size(140, 36);
			   this->button5->Text = L"Modificar";
			   this->button5->UseVisualStyleBackColor = false;
			   this->button5->Click += gcnew System::EventHandler(this, &frmMantPacientes::button5_Click);

			   // Recetas
			   this->button6->BackColor = Color::FromArgb(235, 231, 250);
			   this->button6->FlatAppearance->BorderColor = Color::FromArgb(183, 169, 230);
			   this->button6->FlatAppearance->BorderSize = 1;
			   this->button6->FlatAppearance->MouseOverBackColor = Color::FromArgb(211, 202, 242);
			   this->button6->FlatStyle = FlatStyle::Flat;
			   this->button6->Cursor = Cursors::Hand;
			   this->button6->Font = gcnew System::Drawing::Font(L"Segoe UI", 9.5F);
			   this->button6->ForeColor = Color::FromArgb(76, 57, 135);
			   this->button6->Location = Point(644, 12);
			   this->button6->Size = System::Drawing::Size(140, 36);
			   this->button6->Text = L"Recetas";
			   this->button6->UseVisualStyleBackColor = false;
			   this->button6->Click += gcnew System::EventHandler(this, &frmMantPacientes::button6_Click);

			   // ── Formulario ──────────────────────────────────────────────────────
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->BackColor = Color::FromArgb(241, 244, 248);
			   this->ClientSize = System::Drawing::Size(963, 570);
			   this->ControlBox = false;
			   this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			   this->Controls->Add(this->panelCuerpo);
			   this->Controls->Add(this->panelHeader);
			   this->Name = L"frmMantPacientes";
			   this->Text = L"";
			   this->Load += gcnew System::EventHandler(this, &frmMantPacientes::frmMantPacientes_Load);

			   this->panelHeader->ResumeLayout(false);
			   this->panelHeader->PerformLayout();
			   this->panelCuerpo->ResumeLayout(false);
			   this->panelBusqueda->ResumeLayout(false);
			   this->panelBusqueda->PerformLayout();
			   this->panelResultados->ResumeLayout(false);
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			   this->panelOpciones->ResumeLayout(false);
			   panelTituloResultados->ResumeLayout(false);
			   panelTituloResultados->PerformLayout();
			   this->ResumeLayout(false);
		   }
#pragma endregion


		   // ── LOGICA ───────────────────────────────────────────────────────────
	private: void mostrarGrilla(List<Paciente^>^ listaPacientes) {
		this->dataGridView1->Rows->Clear();
		for (int i = 0; i < listaPacientes->Count; i++) {
			Paciente^ paciente = listaPacientes[i];
			PacienteInvitado^ invitado = dynamic_cast<PacienteInvitado^>(paciente);

			array<String^>^ fila = gcnew array<String^>(5);
			fila[0] = paciente->getId().ToString();
			fila[1] = paciente->getNombre();
			fila[2] = paciente->getApellido();
			fila[3] = paciente->getEnCasa() ? "Si" : "No";
			fila[4] = (invitado != nullptr) ? invitado->getDiasEstancia().ToString() : "-";
			this->dataGridView1->Rows->Add(fila);

			if (i % 2 == 0)
				this->dataGridView1->Rows[i]->DefaultCellStyle->BackColor = System::Drawing::Color::FromArgb(245, 249, 252);
			else
				this->dataGridView1->Rows[i]->DefaultCellStyle->BackColor = System::Drawing::Color::White;
		}
	}

	private: System::Void frmMantPacientes_Load(System::Object^ sender, System::EventArgs^ e) {
		mostrarGrilla(this->pacienteController->ObtenerTodosPacientesTXT());
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		mostrarGrilla(this->pacienteController->ObtenerTodosPacientesTXT());
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		List<Paciente^>^ todos = this->pacienteController->ObtenerTodosPacientesTXT();
		List<Paciente^>^ resultados = gcnew List<Paciente^>();

		String^ filtroId = this->textBox1->Text->Trim();
		String^ filtroNombre = this->textBox2->Text->Trim()->ToUpper();
		String^ filtroApellido = this->textBox3->Text->Trim()->ToUpper();

		for each(Paciente ^ p in todos) {
			bool coincide = true;
			if (filtroId != "" && p->getId().ToString() != filtroId)                        coincide = false;
			if (filtroNombre != "" && !p->getNombre()->ToUpper()->Contains(filtroNombre))       coincide = false;
			if (filtroApellido != "" && !p->getApellido()->ToUpper()->Contains(filtroApellido))   coincide = false;
			if (coincide) resultados->Add(p);
		}
		mostrarGrilla(resultados);
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		frmAgregarPaciente^ ventana = gcnew frmAgregarPaciente(this->pacienteController);
		ventana->ShowDialog();
		mostrarGrilla(this->pacienteController->ObtenerTodosPacientesTXT());
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->dataGridView1->SelectedRows->Count == 0) {
			MessageBox::Show("Seleccione un paciente primero", "Aviso",
				MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}
		int fila = this->dataGridView1->SelectedRows[0]->Index;
		int id = Convert::ToInt32(this->dataGridView1->Rows[fila]->Cells[0]->Value->ToString());
		Paciente^ paciente = this->pacienteController->BuscarPacientePorIdTXT(id);

		frmEliminarPaciente^ ventana = gcnew frmEliminarPaciente(this->pacienteController, paciente);
		ventana->ShowDialog();
		mostrarGrilla(this->pacienteController->ObtenerTodosPacientesTXT());
	}
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->dataGridView1->SelectedRows->Count == 0) {
			MessageBox::Show("Seleccione un paciente primero", "Aviso",
				MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}
		int fila = this->dataGridView1->SelectedRows[0]->Index;
		int id = Convert::ToInt32(this->dataGridView1->Rows[fila]->Cells[0]->Value->ToString());
		Paciente^ paciente = this->pacienteController->BuscarPacientePorIdTXT(id);

		frmModificarPaciente^ ventana = gcnew frmModificarPaciente(this->pacienteController, paciente);
		ventana->ShowDialog();
		mostrarGrilla(this->pacienteController->ObtenerTodosPacientesTXT());
	}
	private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->dataGridView1->SelectedRows->Count == 0) {
			MessageBox::Show("Seleccione un paciente primero", "Aviso",
				MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}
		int fila = this->dataGridView1->SelectedRows[0]->Index;
		int id = Convert::ToInt32(this->dataGridView1->Rows[fila]->Cells[0]->Value->ToString());
		Paciente^ paciente = this->pacienteController->BuscarPacientePorIdTXT(id);

		frmAgregarRecetasPaciente^ ventana = gcnew frmAgregarRecetasPaciente(this->recetaController, this->pacienteController, paciente);
		ventana->ShowDialog();
	}
	private: System::Void groupBox2_Enter(System::Object^ sender, System::EventArgs^ e) {}
	};
}

