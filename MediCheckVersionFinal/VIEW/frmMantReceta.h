#pragma once
#include "frmAgregarReceta.h"
#include "frmModificarReceta.h"
#include "frmEliminarReceta.h"

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

	public ref class frmMantReceta : public System::Windows::Forms::Form
	{
	public:
		frmMantReceta(void)
		{
			InitializeComponent();
			this->recetaController = gcnew RecetaController();
			this->ControlBox = false;
		}
		frmMantReceta(RecetaController^ recetaController, Receta^ receta)
		{
			InitializeComponent();
			this->recetaController = recetaController;
			this->receta = receta;
			this->ControlBox = false;
		}

	protected:
		~frmMantReceta()
		{
			if (components)
				delete components;
		}

	private:
		RecetaController^ recetaController;
		Receta^ receta;
		DataTable^ tablaRecetas;

		System::Windows::Forms::Panel^ panelHeader;
		System::Windows::Forms::Label^ lblTitulo;
		System::Windows::Forms::Panel^ panelCuerpo;
		System::Windows::Forms::Panel^ panelBusqueda;
		System::Windows::Forms::Label^ lblBusqueda;
		System::Windows::Forms::Panel^ lineaBusqueda;
		System::Windows::Forms::Label^ label1;
		System::Windows::Forms::ComboBox^ comboBox1;
		System::Windows::Forms::Label^ label2;
		System::Windows::Forms::TextBox^ textBox2;
		System::Windows::Forms::Button^ button4;
		System::Windows::Forms::Panel^ panelResultados;
		System::Windows::Forms::Label^ lblResultados;
		System::Windows::Forms::DataGridView^ dataGridView1;
		System::Windows::Forms::Panel^ panelOpciones;
		System::Windows::Forms::Button^ button1;
		System::Windows::Forms::Button^ button2;
		System::Windows::Forms::Button^ button3;
		System::Windows::Forms::Button^ button5;

	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column6;

		   System::ComponentModel::Container^ components;

		   // ── Paleta de colores ─────────────────────────────────────────────────
		   // Azul marino oscuro  : Color::FromArgb(15, 41, 66)    → header
		   // Sidebar bg          : Color::FromArgb(247, 249, 251) → casi blanco frío
		   // Cuerpo bg           : Color::FromArgb(241, 244, 248) → gris azulado suave
		   // Labels campo        : Color::FromArgb(90, 115, 140)  → azul grisáceo
		   // Línea separadora    : Color::FromArgb(218, 227, 236)
		   // Header DGV          : Color::FromArgb(36, 66, 98)    → azul medio
		   // Fila par            : Color::FromArgb(246, 250, 253)
		   // Fila impar          : Color::White
		   // ─────────────────────────────────────────────────────────────────────

#pragma region Windows Form Designer generated code
		   void InitializeComponent(void)
		   {
			   System::Windows::Forms::DataGridViewCellStyle^ dgvHeaderStyle = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			   System::Windows::Forms::DataGridViewCellStyle^ dgvCellStyle = (gcnew System::Windows::Forms::DataGridViewCellStyle());

			   this->panelHeader = (gcnew System::Windows::Forms::Panel());
			   this->lblTitulo = (gcnew System::Windows::Forms::Label());
			   this->panelCuerpo = (gcnew System::Windows::Forms::Panel());
			   this->panelBusqueda = (gcnew System::Windows::Forms::Panel());
			   this->lblBusqueda = (gcnew System::Windows::Forms::Label());
			   this->lineaBusqueda = (gcnew System::Windows::Forms::Panel());
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			   this->label2 = (gcnew System::Windows::Forms::Label());
			   this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			   this->button4 = (gcnew System::Windows::Forms::Button());
			   this->panelResultados = (gcnew System::Windows::Forms::Panel());
			   this->lblResultados = (gcnew System::Windows::Forms::Label());
			   this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			   this->panelOpciones = (gcnew System::Windows::Forms::Panel());
			   this->button2 = (gcnew System::Windows::Forms::Button());
			   this->button3 = (gcnew System::Windows::Forms::Button());
			   this->button1 = (gcnew System::Windows::Forms::Button());
			   this->button5 = (gcnew System::Windows::Forms::Button());
			   this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->Column6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());

			   System::Windows::Forms::Panel^ panelTituloResultados = (gcnew System::Windows::Forms::Panel());

			   this->panelHeader->SuspendLayout();
			   this->panelCuerpo->SuspendLayout();
			   this->panelBusqueda->SuspendLayout();
			   this->panelResultados->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			   this->panelOpciones->SuspendLayout();
			   panelTituloResultados->SuspendLayout();
			   this->SuspendLayout();

			   // ── panelHeader ──────────────────────────────────────────────────
			   this->panelHeader->BackColor = Color::FromArgb(15, 41, 66);
			   this->panelHeader->Controls->Add(this->lblTitulo);
			   this->panelHeader->Dock = DockStyle::Top;
			   this->panelHeader->Name = L"panelHeader";
			   this->panelHeader->Size = System::Drawing::Size(963, 52);
			   this->panelHeader->TabIndex = 0;

			   // ── lblTitulo ────────────────────────────────────────────────────
			   this->lblTitulo->AutoSize = true;
			   this->lblTitulo->Font = gcnew System::Drawing::Font(L"Segoe UI", 13, FontStyle::Regular);
			   this->lblTitulo->ForeColor = Color::FromArgb(220, 233, 245);
			   this->lblTitulo->Location = Point(22, 14);
			   this->lblTitulo->Name = L"lblTitulo";
			   this->lblTitulo->TabIndex = 0;
			   this->lblTitulo->Text = L"Recetas";

			   // ── panelCuerpo ──────────────────────────────────────────────────
			   this->panelCuerpo->BackColor = Color::FromArgb(241, 244, 248);
			   this->panelCuerpo->Controls->Add(this->panelResultados); // Fill — primero
			   this->panelCuerpo->Controls->Add(this->panelBusqueda);   // Left  — segundo
			   this->panelCuerpo->Controls->Add(this->panelOpciones);   // Bottom — último
			   this->panelCuerpo->Dock = DockStyle::Fill;
			   this->panelCuerpo->Name = L"panelCuerpo";
			   this->panelCuerpo->Size = System::Drawing::Size(963, 518);
			   this->panelCuerpo->TabIndex = 1;

			   // ── panelBusqueda (sidebar ~40% del ancho) ───────────────────────
			   this->panelBusqueda->BackColor = Color::FromArgb(247, 249, 251);
			   this->panelBusqueda->Controls->Add(this->lblBusqueda);
			   this->panelBusqueda->Controls->Add(this->lineaBusqueda);
			   this->panelBusqueda->Controls->Add(this->label1);
			   this->panelBusqueda->Controls->Add(this->comboBox1);
			   this->panelBusqueda->Controls->Add(this->label2);
			   this->panelBusqueda->Controls->Add(this->textBox2);
			   this->panelBusqueda->Controls->Add(this->button4);
			   this->panelBusqueda->Dock = DockStyle::Left;
			   this->panelBusqueda->Width = 380;
			   this->panelBusqueda->Name = L"panelBusqueda";
			   this->panelBusqueda->TabIndex = 0;

			   // ── lblBusqueda ──────────────────────────────────────────────────
			   this->lblBusqueda->AutoSize = true;
			   this->lblBusqueda->Font = gcnew System::Drawing::Font(L"Segoe UI", 9, FontStyle::Regular);
			   this->lblBusqueda->ForeColor = Color::FromArgb(100, 120, 140);
			   this->lblBusqueda->Location = Point(20, 18);
			   this->lblBusqueda->Name = L"lblBusqueda";
			   this->lblBusqueda->TabIndex = 0;
			   this->lblBusqueda->Text = L"BÚSQUEDA";

			   // ── lineaBusqueda ────────────────────────────────────────────────
			   this->lineaBusqueda->BackColor = Color::FromArgb(218, 227, 236);
			   this->lineaBusqueda->Location = Point(20, 40);
			   this->lineaBusqueda->Name = L"lineaBusqueda";
			   this->lineaBusqueda->Size = System::Drawing::Size(340, 1);
			   this->lineaBusqueda->TabIndex = 1;

			   // ── label1 (#ID) ─────────────────────────────────────────────────
			   this->label1->AutoSize = true;
			   this->label1->Font = gcnew System::Drawing::Font(L"Segoe UI", 8, FontStyle::Bold);
			   this->label1->ForeColor = Color::FromArgb(90, 115, 140);
			   this->label1->Location = Point(20, 56);
			   this->label1->Name = L"label1";
			   this->label1->TabIndex = 2;
			   this->label1->Text = L"# ID";

			   // ── comboBox1 ────────────────────────────────────────────────────
			   this->comboBox1->Font = gcnew System::Drawing::Font(L"Segoe UI", 9.5F);
			   this->comboBox1->ForeColor = Color::FromArgb(30, 50, 70);
			   this->comboBox1->BackColor = Color::White;
			   this->comboBox1->FlatStyle = FlatStyle::Flat;
			   this->comboBox1->FormattingEnabled = true;
			   this->comboBox1->Items->AddRange(gcnew cli::array<System::Object^>(4) { L"1", L"2", L"3", L"4" });
			   this->comboBox1->Location = Point(20, 74);
			   this->comboBox1->Name = L"comboBox1";
			   this->comboBox1->Size = System::Drawing::Size(340, 25);
			   this->comboBox1->TabIndex = 3;

			   // ── label2 (Medicamento) ─────────────────────────────────────────
			   this->label2->AutoSize = true;
			   this->label2->Font = gcnew System::Drawing::Font(L"Segoe UI", 8, FontStyle::Bold);
			   this->label2->ForeColor = Color::FromArgb(90, 115, 140);
			   this->label2->Location = Point(20, 116);
			   this->label2->Name = L"label2";
			   this->label2->TabIndex = 4;
			   this->label2->Text = L"Medicamento";

			   // ── textBox2 ─────────────────────────────────────────────────────
			   this->textBox2->BorderStyle = BorderStyle::FixedSingle;
			   this->textBox2->Font = gcnew System::Drawing::Font(L"Segoe UI", 9.5F);
			   this->textBox2->BackColor = Color::White;
			   this->textBox2->Location = Point(20, 134);
			   this->textBox2->Name = L"textBox2";
			   this->textBox2->Size = System::Drawing::Size(340, 24);
			   this->textBox2->TabIndex = 5;
			   this->textBox2->Text = L"Ej. amoxicilina";
			   this->textBox2->ForeColor = Color::FromArgb(180, 190, 200);
			   this->textBox2->Enter += gcnew System::EventHandler(this, &frmMantReceta::textBox2_Enter);
			   this->textBox2->Leave += gcnew System::EventHandler(this, &frmMantReceta::textBox2_Leave);

			   // ── button4 (Buscar) ─────────────────────────────────────────────
			   this->button4->BackColor = Color::FromArgb(15, 41, 66);
			   this->button4->Cursor = Cursors::Hand;
			   this->button4->FlatAppearance->BorderSize = 0;
			   this->button4->FlatAppearance->MouseOverBackColor = Color::FromArgb(26, 62, 98);
			   this->button4->FlatStyle = FlatStyle::Flat;
			   this->button4->Font = gcnew System::Drawing::Font(L"Segoe UI", 9.5F, FontStyle::Regular);
			   this->button4->ForeColor = Color::FromArgb(220, 233, 245);
			   this->button4->Location = Point(20, 184);
			   this->button4->Name = L"button4";
			   this->button4->Size = System::Drawing::Size(340, 36);
			   this->button4->TabIndex = 6;
			   this->button4->Text = L"Buscar";
			   this->button4->UseVisualStyleBackColor = false;
			   this->button4->Click += gcnew System::EventHandler(this, &frmMantReceta::button4_Click);

			   // ── panelResultados ──────────────────────────────────────────────
			   this->panelResultados->BackColor = Color::FromArgb(241, 244, 248);
			   this->panelResultados->Padding = System::Windows::Forms::Padding(16, 8, 16, 0);
			   this->panelResultados->Controls->Add(this->dataGridView1);      // Fill — primero
			   this->panelResultados->Controls->Add(panelTituloResultados);    // Top  — segundo
			   this->panelResultados->Dock = DockStyle::Fill;
			   this->panelResultados->Name = L"panelResultados";
			   this->panelResultados->TabIndex = 1;

			   // ── panelTituloResultados ────────────────────────────────────────
			   panelTituloResultados->BackColor = Color::FromArgb(241, 244, 248);
			   panelTituloResultados->Dock = DockStyle::Top;
			   panelTituloResultados->Height = 32;
			   panelTituloResultados->Controls->Add(this->lblResultados);

			   // ── lblResultados ────────────────────────────────────────────────
			   this->lblResultados->AutoSize = true;
			   this->lblResultados->Font = gcnew System::Drawing::Font(L"Segoe UI", 9, FontStyle::Regular);
			   this->lblResultados->ForeColor = Color::FromArgb(90, 115, 140);
			   this->lblResultados->Location = Point(0, 8);
			   this->lblResultados->Name = L"lblResultados";
			   this->lblResultados->TabIndex = 0;
			   this->lblResultados->Text = L"Resultados";

			   // ── dataGridView1 ────────────────────────────────────────────────
			   dgvHeaderStyle->Alignment = DataGridViewContentAlignment::MiddleLeft;
			   dgvHeaderStyle->BackColor = Color::FromArgb(36, 66, 98);
			   dgvHeaderStyle->Font = gcnew System::Drawing::Font(L"Segoe UI", 8.5F, FontStyle::Regular);
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
			   this->dataGridView1->Columns->AddRange(gcnew cli::array<DataGridViewColumn^>(6) {
				   this->Column1, this->Column2, this->Column3,
					   this->Column4, this->Column5, this->Column6
			   });
			   this->dataGridView1->EnableHeadersVisualStyles = false;
			   this->dataGridView1->Dock = DockStyle::Fill;
			   this->dataGridView1->MultiSelect = false;
			   this->dataGridView1->Name = L"dataGridView1";
			   this->dataGridView1->ReadOnly = true;
			   this->dataGridView1->RowHeadersVisible = false;
			   this->dataGridView1->RowTemplate->Height = 32;
			   this->dataGridView1->SelectionMode = DataGridViewSelectionMode::FullRowSelect;
			   this->dataGridView1->TabIndex = 1;
			   this->dataGridView1->CellContentClick += gcnew DataGridViewCellEventHandler(this, &frmMantReceta::dataGridView1_CellContentClick);

			   // ── Columnas ─────────────────────────────────────────────────────
			   this->Column1->HeaderText = L"#ID";
			   this->Column1->Name = L"Column1";
			   this->Column1->ReadOnly = true;
			   this->Column1->Width = 60;

			   this->Column2->HeaderText = L"Medicamento";
			   this->Column2->Name = L"Column2";
			   this->Column2->ReadOnly = true;
			   this->Column2->Width = 160;

			   this->Column3->HeaderText = L"Tamaño";
			   this->Column3->Name = L"Column3";
			   this->Column3->ReadOnly = true;
			   this->Column3->Width = 100;

			   this->Column4->HeaderText = L"Paciente Asignado";
			   this->Column4->Name = L"Column4";
			   this->Column4->ReadOnly = true;
			   this->Column4->Width = 180;

			   this->Column5->HeaderText = L"Dosis Diaria";
			   this->Column5->Name = L"Column5";
			   this->Column5->ReadOnly = true;
			   this->Column5->Width = 120;

			   this->Column6->HeaderText = L"Hora Programada";
			   this->Column6->Name = L"Column6";
			   this->Column6->ReadOnly = true;
			   this->Column6->AutoSizeMode = DataGridViewAutoSizeColumnMode::Fill;

			   // ── panelOpciones ────────────────────────────────────────────────
			   this->panelOpciones->BackColor = Color::FromArgb(247, 249, 251);
			   this->panelOpciones->Controls->Add(this->button2);
			   this->panelOpciones->Controls->Add(this->button3);
			   this->panelOpciones->Controls->Add(this->button1);
			   this->panelOpciones->Controls->Add(this->button5);
			   this->panelOpciones->Dock = DockStyle::Bottom;
			   this->panelOpciones->Name = L"panelOpciones";
			   this->panelOpciones->Size = System::Drawing::Size(963, 60);
			   this->panelOpciones->TabIndex = 2;

			   System::Windows::Forms::Panel^ lineaOpciones = gcnew System::Windows::Forms::Panel();
			   lineaOpciones->BackColor = Color::FromArgb(210, 220, 232);
			   lineaOpciones->Dock = DockStyle::Top;
			   lineaOpciones->Height = 1;
			   this->panelOpciones->Controls->Add(lineaOpciones);

			   // ── Botones de acción ─────────────────────────────────────────────
			   // Eliminar — rojo suave
			   this->button2->BackColor = Color::FromArgb(252, 235, 235);
			   this->button2->FlatAppearance->BorderColor = Color::FromArgb(240, 160, 160);
			   this->button2->FlatAppearance->BorderSize = 1;
			   this->button2->FlatAppearance->MouseOverBackColor = Color::FromArgb(247, 193, 193);
			   this->button2->FlatStyle = FlatStyle::Flat;
			   this->button2->Cursor = Cursors::Hand;
			   this->button2->Font = gcnew System::Drawing::Font(L"Segoe UI", 9.5F, FontStyle::Regular);
			   this->button2->ForeColor = Color::FromArgb(163, 45, 45);
			   this->button2->Location = Point(20, 12);
			   this->button2->Name = L"button2";
			   this->button2->Size = System::Drawing::Size(150, 36);
			   this->button2->TabIndex = 0;
			   this->button2->Text = L"Eliminar";
			   this->button2->UseVisualStyleBackColor = false;
			   this->button2->Click += gcnew System::EventHandler(this, &frmMantReceta::button2_Click);

			   // Mostrar — azul suave
			   this->button3->BackColor = Color::FromArgb(230, 241, 251);
			   this->button3->FlatAppearance->BorderColor = Color::FromArgb(158, 198, 240);
			   this->button3->FlatAppearance->BorderSize = 1;
			   this->button3->FlatAppearance->MouseOverBackColor = Color::FromArgb(181, 212, 244);
			   this->button3->FlatStyle = FlatStyle::Flat;
			   this->button3->Cursor = Cursors::Hand;
			   this->button3->Font = gcnew System::Drawing::Font(L"Segoe UI", 9.5F, FontStyle::Regular);
			   this->button3->ForeColor = Color::FromArgb(12, 68, 124);
			   this->button3->Location = Point(186, 12);
			   this->button3->Name = L"button3";
			   this->button3->Size = System::Drawing::Size(150, 36);
			   this->button3->TabIndex = 1;
			   this->button3->Text = L"Mostrar";
			   this->button3->UseVisualStyleBackColor = false;
			   this->button3->Click += gcnew System::EventHandler(this, &frmMantReceta::button3_Click);

			   // Agregar — verde suave
			   this->button1->BackColor = Color::FromArgb(234, 243, 222);
			   this->button1->FlatAppearance->BorderColor = Color::FromArgb(168, 208, 106);
			   this->button1->FlatAppearance->BorderSize = 1;
			   this->button1->FlatAppearance->MouseOverBackColor = Color::FromArgb(192, 221, 151);
			   this->button1->FlatStyle = FlatStyle::Flat;
			   this->button1->Cursor = Cursors::Hand;
			   this->button1->Font = gcnew System::Drawing::Font(L"Segoe UI", 9.5F, FontStyle::Regular);
			   this->button1->ForeColor = Color::FromArgb(39, 80, 10);
			   this->button1->Location = Point(352, 12);
			   this->button1->Name = L"button1";
			   this->button1->Size = System::Drawing::Size(150, 36);
			   this->button1->TabIndex = 2;
			   this->button1->Text = L"Agregar";
			   this->button1->UseVisualStyleBackColor = false;
			   this->button1->Click += gcnew System::EventHandler(this, &frmMantReceta::button1_Click);

			   // Modificar — naranja suave
			   this->button5->BackColor = Color::FromArgb(250, 238, 218);
			   this->button5->FlatAppearance->BorderColor = Color::FromArgb(240, 192, 112);
			   this->button5->FlatAppearance->BorderSize = 1;
			   this->button5->FlatAppearance->MouseOverBackColor = Color::FromArgb(250, 199, 117);
			   this->button5->FlatStyle = FlatStyle::Flat;
			   this->button5->Cursor = Cursors::Hand;
			   this->button5->Font = gcnew System::Drawing::Font(L"Segoe UI", 9.5F, FontStyle::Regular);
			   this->button5->ForeColor = Color::FromArgb(99, 56, 6);
			   this->button5->Location = Point(518, 12);
			   this->button5->Name = L"button5";
			   this->button5->Size = System::Drawing::Size(150, 36);
			   this->button5->TabIndex = 3;
			   this->button5->Text = L"Modificar";
			   this->button5->UseVisualStyleBackColor = false;
			   this->button5->Click += gcnew System::EventHandler(this, &frmMantReceta::button5_Click);

			   // ── Form principal ───────────────────────────────────────────────
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->BackColor = Color::FromArgb(241, 244, 248);
			   this->ClientSize = System::Drawing::Size(963, 570);
			   this->ControlBox = false;
			   this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			   this->Controls->Add(this->panelCuerpo);
			   this->Controls->Add(this->panelHeader);
			   this->Name = L"frmMantReceta";
			   this->Text = L"";
			   this->Load += gcnew System::EventHandler(this, &frmMantReceta::frmMantReceta_Load);

			   this->panelHeader->ResumeLayout(false);
			   this->panelHeader->PerformLayout();
			   this->panelCuerpo->ResumeLayout(false);
			   this->panelBusqueda->ResumeLayout(false);
			   this->panelBusqueda->PerformLayout();
			   this->panelResultados->ResumeLayout(false);
			   this->panelResultados->PerformLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			   this->panelOpciones->ResumeLayout(false);
			   panelTituloResultados->ResumeLayout(false);
			   panelTituloResultados->PerformLayout();
			   this->ResumeLayout(false);
		   }
#pragma endregion

		   // ── LÓGICA (sin cambios) ──────────────────────────────────────────────
	private: void mostrarGrilla(DataTable^ tabla) {
		this->dataGridView1->Rows->Clear();
		if (tabla == nullptr)
			return;

		for (int i = 0; i < tabla->Rows->Count; i++) {
			DataRow^ row = tabla->Rows[i];
			array<String^>^ fila = gcnew array<String^>(6);
			fila[0] = Convert::ToString(row["idReceta"]);
			fila[1] = Convert::ToString(row["medicamento"]);
			fila[2] = Convert::ToString(row["tamano"]);
			fila[3] = Convert::ToString(row["pacienteAsignado"]);
			fila[4] = Convert::ToString(row["dosisDiaria"]);
			fila[5] = Convert::ToString(row["horasProgramadas"]);
			this->dataGridView1->Rows->Add(fila);

			if (i % 2 == 0)
				this->dataGridView1->Rows[i]->DefaultCellStyle->BackColor = Color::FromArgb(246, 250, 253);
			else
				this->dataGridView1->Rows[i]->DefaultCellStyle->BackColor = Color::White;
		}
	}

	private: void RecargarRecetas() {
		this->tablaRecetas = this->recetaController->ObtenerRecetasParaGrillaTXT();
		mostrarGrilla(this->tablaRecetas);
	}

	private: System::Void frmMantReceta_Load(System::Object^ sender, System::EventArgs^ e) {
		RecargarRecetas();
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		RecargarRecetas();
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ filtroId = this->comboBox1->Text->Trim();
		String^ filtroMed = this->textBox2->Text->Trim()->ToUpperInvariant();
		DataTable^ resultados = this->tablaRecetas == nullptr
			? gcnew DataTable()
			: this->tablaRecetas->Clone();

		if (this->tablaRecetas != nullptr) {
			for each (DataRow ^ row in this->tablaRecetas->Rows) {
				bool coincide = true;
				if (filtroId != "" && Convert::ToString(row["idReceta"]) != filtroId)
					coincide = false;
				if (coincide && filtroMed != ""
					&& !Convert::ToString(row["nombreMedicamento"])->ToUpperInvariant()->Contains(filtroMed))
					coincide = false;
				if (coincide)
					resultados->ImportRow(row);
			}
		}
		mostrarGrilla(resultados);
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->dataGridView1->SelectedRows->Count == 0) {
			MessageBox::Show("Seleccione una receta primero", "Aviso",
				MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}
		int filaSeleccionada = this->dataGridView1->SelectedRows[0]->Index;
		int id = Convert::ToInt32(this->dataGridView1->Rows[filaSeleccionada]->Cells[0]->Value->ToString());
		Receta^ receta = this->recetaController->BuscarRecetaPorIdTXT(id);

		frmEliminarReceta^ ventana = gcnew frmEliminarReceta(this->recetaController, receta);
		ventana->ShowDialog();
		RecargarRecetas();
	}
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->dataGridView1->SelectedRows->Count == 0) {
			MessageBox::Show("Seleccione una receta primero", "Aviso",
				MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}
		int filaSeleccionada = this->dataGridView1->SelectedRows[0]->Index;
		int id = Convert::ToInt32(this->dataGridView1->Rows[filaSeleccionada]->Cells[0]->Value->ToString());
		Receta^ receta = this->recetaController->BuscarRecetaPorIdTXT(id);

		frmModificarReceta^ ventana = gcnew frmModificarReceta(this->recetaController, receta);
		ventana->ShowDialog();
		RecargarRecetas();
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		frmAgregarReceta^ ventana = gcnew frmAgregarReceta(this->recetaController);
		ventana->ShowDialog();
		RecargarRecetas();
	}
	private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	}

	private: System::Void textBox2_Enter(System::Object^ sender, System::EventArgs^ e) {
		if (this->textBox2->Text == L"Ej. amoxicilina") {
			this->textBox2->Text = L"";
			this->textBox2->ForeColor = Color::FromArgb(30, 50, 70);
		}
	}
	private: System::Void textBox2_Leave(System::Object^ sender, System::EventArgs^ e) {
		if (this->textBox2->Text->Trim() == L"") {
			this->textBox2->Text = L"Ej. amoxicilina";
			this->textBox2->ForeColor = Color::FromArgb(180, 190, 200);
		}
	}
	};
}
