#pragma once

namespace VIEW {
    using namespace MODEL;
    using namespace CONTROLLER;
    using namespace System;
    using namespace System::Collections::Generic;
    using namespace System::ComponentModel;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace System::Windows::Forms;

    public ref class frmRestauracion : public System::Windows::Forms::Form
    {
    public:
        frmRestauracion(void)
        {
            InitializeComponent();
            this->adminController = gcnew AdminController();
            this->pacienteController = gcnew PacienteController();
            this->medicamentoController = gcnew MedicamentoController();
            this->recetaController = gcnew RecetaController();
            this->ControlBox = false;
        }

    protected:
        ~frmRestauracion()
        {
            if (components)
                delete components;
        }

    private:
        AdminController^ adminController;
        PacienteController^ pacienteController;
        MedicamentoController^ medicamentoController;
        RecetaController^ recetaController;

        System::ComponentModel::Container^ components;
        System::Windows::Forms::Panel^ panelHeader;
        System::Windows::Forms::Panel^ panelBody;
        System::Windows::Forms::Label^ lblTitulo;
        System::Windows::Forms::Label^ lblSubtitulo;
        System::Windows::Forms::TabControl^ tabControl1;

        System::Windows::Forms::TabPage^ tabAdministradores;
        System::Windows::Forms::TabPage^ tabPacientes;
        System::Windows::Forms::TabPage^ tabMedicamentos;
        System::Windows::Forms::TabPage^ tabRecetas;

        System::Windows::Forms::DataGridView^ dgvAdministradores;
        System::Windows::Forms::DataGridView^ dgvPacientes;
        System::Windows::Forms::DataGridView^ dgvMedicamentos;
        System::Windows::Forms::DataGridView^ dgvRecetas;

        System::Windows::Forms::Button^ btnRestaurarAdministrador;
        System::Windows::Forms::Button^ btnRestaurarPaciente;
        System::Windows::Forms::Button^ btnRestaurarMedicamento;
        System::Windows::Forms::Button^ btnRestaurarReceta;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->components = gcnew System::ComponentModel::Container();
            this->panelHeader = gcnew System::Windows::Forms::Panel();
            this->panelBody = gcnew System::Windows::Forms::Panel();
            this->lblTitulo = gcnew System::Windows::Forms::Label();
            this->lblSubtitulo = gcnew System::Windows::Forms::Label();
            this->tabControl1 = gcnew System::Windows::Forms::TabControl();
            this->tabAdministradores = gcnew System::Windows::Forms::TabPage();
            this->tabPacientes = gcnew System::Windows::Forms::TabPage();
            this->tabMedicamentos = gcnew System::Windows::Forms::TabPage();
            this->tabRecetas = gcnew System::Windows::Forms::TabPage();
            this->dgvAdministradores = gcnew System::Windows::Forms::DataGridView();
            this->dgvPacientes = gcnew System::Windows::Forms::DataGridView();
            this->dgvMedicamentos = gcnew System::Windows::Forms::DataGridView();
            this->dgvRecetas = gcnew System::Windows::Forms::DataGridView();
            this->btnRestaurarAdministrador = gcnew System::Windows::Forms::Button();
            this->btnRestaurarPaciente = gcnew System::Windows::Forms::Button();
            this->btnRestaurarMedicamento = gcnew System::Windows::Forms::Button();
            this->btnRestaurarReceta = gcnew System::Windows::Forms::Button();

            this->SuspendLayout();

            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::FromArgb(241, 244, 248);
            this->ClientSize = System::Drawing::Size(1280, 720);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
            this->Name = L"frmRestauracion";
            this->Text = L"";

            this->panelHeader->BackColor = System::Drawing::Color::FromArgb(15, 41, 66);
            this->panelHeader->Dock = System::Windows::Forms::DockStyle::Top;
            this->panelHeader->Height = 84;

            this->lblTitulo->AutoSize = true;
            this->lblTitulo->Font = gcnew System::Drawing::Font(L"Segoe UI", 15.0f, System::Drawing::FontStyle::Regular);
            this->lblTitulo->ForeColor = System::Drawing::Color::FromArgb(220, 233, 245);
            this->lblTitulo->Location = System::Drawing::Point(24, 13);
            this->lblTitulo->Text = L"Restauracion";

            this->lblSubtitulo->AutoSize = true;
            this->lblSubtitulo->Font = gcnew System::Drawing::Font(L"Segoe UI", 9.5f);
            this->lblSubtitulo->ForeColor = System::Drawing::Color::FromArgb(200, 218, 235);
            this->lblSubtitulo->Location = System::Drawing::Point(27, 50);
            this->lblSubtitulo->Text = L"Restaura registros con baja logica en administradores, pacientes, medicamentos y recetas.";

            this->panelHeader->Controls->Add(this->lblTitulo);
            this->panelHeader->Controls->Add(this->lblSubtitulo);

            this->panelBody->Dock = System::Windows::Forms::DockStyle::Fill;
            this->panelBody->Padding = System::Windows::Forms::Padding(22, 18, 22, 18);
            this->panelBody->BackColor = System::Drawing::Color::FromArgb(241, 244, 248);

            this->tabControl1->Dock = System::Windows::Forms::DockStyle::Fill;
            this->tabControl1->Font = gcnew System::Drawing::Font(L"Segoe UI", 9.5f, System::Drawing::FontStyle::Regular); this->tabControl1->Appearance = System::Windows::Forms::TabAppearance::Normal; this->tabControl1->SizeMode = System::Windows::Forms::TabSizeMode::Fixed; this->tabControl1->ItemSize = System::Drawing::Size(170, 34);

            ConfigurarTab(this->tabAdministradores, L"Administradores", this->dgvAdministradores, this->btnRestaurarAdministrador, gcnew EventHandler(this, &frmRestauracion::btnRestaurarAdministrador_Click));
            ConfigurarTab(this->tabPacientes, L"Pacientes", this->dgvPacientes, this->btnRestaurarPaciente, gcnew EventHandler(this, &frmRestauracion::btnRestaurarPaciente_Click));
            ConfigurarTab(this->tabMedicamentos, L"Medicamentos", this->dgvMedicamentos, this->btnRestaurarMedicamento, gcnew EventHandler(this, &frmRestauracion::btnRestaurarMedicamento_Click));
            ConfigurarTab(this->tabRecetas, L"Recetas", this->dgvRecetas, this->btnRestaurarReceta, gcnew EventHandler(this, &frmRestauracion::btnRestaurarReceta_Click));

            this->tabControl1->TabPages->Add(this->tabAdministradores);
            this->tabControl1->TabPages->Add(this->tabPacientes);
            this->tabControl1->TabPages->Add(this->tabMedicamentos);
            this->tabControl1->TabPages->Add(this->tabRecetas);

            this->panelBody->Controls->Add(this->tabControl1);
            this->Controls->Add(this->panelBody);
            this->Controls->Add(this->panelHeader);

            this->Load += gcnew EventHandler(this, &frmRestauracion::frmRestauracion_Load);
            this->Resize += gcnew EventHandler(this, &frmRestauracion::frmRestauracion_Resize);
            this->ResumeLayout(false);
        }
#pragma endregion

    private:
        void ConfigurarTab(System::Windows::Forms::TabPage^ tab, String^ titulo, System::Windows::Forms::DataGridView^ grid, System::Windows::Forms::Button^ boton, EventHandler^ eventoClick)
        {
            tab->Text = titulo;
            tab->BackColor = System::Drawing::Color::White;
            tab->Padding = System::Windows::Forms::Padding(16);

            System::Windows::Forms::Panel^ panelAcciones = gcnew System::Windows::Forms::Panel();
            panelAcciones->Dock = System::Windows::Forms::DockStyle::Top;
            panelAcciones->Height = 76;
            panelAcciones->BackColor = System::Drawing::Color::White;

            System::Windows::Forms::Panel^ panelBoton = gcnew System::Windows::Forms::Panel();
            panelBoton->Dock = System::Windows::Forms::DockStyle::Right;
            panelBoton->Width = 230;
            panelBoton->BackColor = System::Drawing::Color::White;

            System::Windows::Forms::Label^ lbl = gcnew System::Windows::Forms::Label();
            lbl->AutoSize = true;
            lbl->Font = gcnew System::Drawing::Font(L"Segoe UI", 10.5f, System::Drawing::FontStyle::Regular);
            lbl->ForeColor = System::Drawing::Color::FromArgb(15, 41, 66);
            lbl->Location = System::Drawing::Point(8, 12);
            lbl->Text = String::Concat(L"Registros inactivos de ", titulo);

            System::Windows::Forms::Label^ lblAyuda = gcnew System::Windows::Forms::Label();
            lblAyuda->AutoSize = true;
            lblAyuda->Font = gcnew System::Drawing::Font(L"Segoe UI", 8.5f);
            lblAyuda->ForeColor = System::Drawing::Color::FromArgb(90, 115, 140);
            lblAyuda->Location = System::Drawing::Point(10, 40);
            lblAyuda->Text = L"Seleccione una fila del DataGridView y luego pulse Restaurar.";

            boton->Text = L"Restaurar seleccionado";
            boton->Size = System::Drawing::Size(200, 38);
            boton->Location = System::Drawing::Point(15, 19);
            boton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right);
            boton->BackColor = System::Drawing::Color::FromArgb(234, 243, 222);
            boton->ForeColor = System::Drawing::Color::FromArgb(39, 80, 10);
            boton->Font = gcnew System::Drawing::Font(L"Segoe UI", 9.5f, System::Drawing::FontStyle::Regular);
            boton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            boton->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(168, 208, 106);
            boton->FlatAppearance->BorderSize = 1;
            boton->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(192, 221, 151);
            boton->Cursor = System::Windows::Forms::Cursors::Hand;
            boton->Click += eventoClick;

            panelAcciones->Controls->Add(lbl);
            panelAcciones->Controls->Add(lblAyuda);
            panelBoton->Controls->Add(boton);
            panelAcciones->Controls->Add(panelBoton);

            ConfigurarGrid(grid);
            grid->Dock = System::Windows::Forms::DockStyle::Fill;

            tab->Controls->Add(grid);
            tab->Controls->Add(panelAcciones);
        }

        void ConfigurarGrid(System::Windows::Forms::DataGridView^ grid)
        {
            grid->AllowUserToAddRows = false;
            grid->AllowUserToDeleteRows = false;
            grid->AllowUserToResizeRows = false;
            grid->MultiSelect = false;
            grid->ReadOnly = true;
            grid->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
            grid->RowHeadersVisible = false;
            grid->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
            grid->BackgroundColor = System::Drawing::Color::FromArgb(247, 249, 251);
            grid->BorderStyle = System::Windows::Forms::BorderStyle::None;
            grid->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::SingleHorizontal;
            grid->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
            grid->Dock = System::Windows::Forms::DockStyle::Fill;
            grid->GridColor = System::Drawing::Color::FromArgb(220, 230, 240);
            grid->DefaultCellStyle->BackColor = System::Drawing::Color::White;
            grid->DefaultCellStyle->ForeColor = System::Drawing::Color::FromArgb(40, 60, 80);
            grid->DefaultCellStyle->SelectionBackColor = System::Drawing::Color::FromArgb(210, 228, 248);
            grid->DefaultCellStyle->SelectionForeColor = System::Drawing::Color::FromArgb(12, 52, 100);
            grid->DefaultCellStyle->Font = gcnew System::Drawing::Font(L"Segoe UI", 9.5f);
            grid->ColumnHeadersDefaultCellStyle->BackColor = System::Drawing::Color::FromArgb(36, 66, 98);
            grid->ColumnHeadersDefaultCellStyle->ForeColor = System::Drawing::Color::FromArgb(200, 218, 235);
            grid->ColumnHeadersDefaultCellStyle->SelectionBackColor = System::Drawing::Color::FromArgb(36, 66, 98);
            grid->ColumnHeadersDefaultCellStyle->SelectionForeColor = System::Drawing::Color::FromArgb(200, 218, 235);
            grid->ColumnHeadersDefaultCellStyle->Font = gcnew System::Drawing::Font(L"Segoe UI", 8.5f, System::Drawing::FontStyle::Regular);
            grid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
            grid->ColumnHeadersHeight = 36;
            grid->EnableHeadersVisualStyles = false;
            grid->Cursor = System::Windows::Forms::Cursors::Hand;
            grid->RowTemplate->Height = 32;
        }

        void ConfigurarColumnasAdministradores()
        {
            this->dgvAdministradores->Columns->Clear();
            this->dgvAdministradores->DataSource = nullptr;
            this->dgvAdministradores->Columns->Add(L"colIdAdmin", L"ID");
            this->dgvAdministradores->Columns->Add(L"colNombreAdmin", L"Nombre");
            this->dgvAdministradores->Columns->Add(L"colApellidoAdmin", L"Apellido");
            this->dgvAdministradores->Columns->Add(L"colPinAdmin", L"PIN");
        }

        void ConfigurarColumnasPacientes()
        {
            this->dgvPacientes->Columns->Clear();
            this->dgvPacientes->DataSource = nullptr;
            this->dgvPacientes->Columns->Add(L"colIdPaciente", L"ID");
            this->dgvPacientes->Columns->Add(L"colNombrePaciente", L"Nombre");
            this->dgvPacientes->Columns->Add(L"colApellidoPaciente", L"Apellido");
            this->dgvPacientes->Columns->Add(L"colHuellaPaciente", L"Huella");
            this->dgvPacientes->Columns->Add(L"colEstadoPaciente", L"En casa");
            this->dgvPacientes->Columns->Add(L"colDiasEstancia", L"Dias estancia");
        }

        void ConfigurarColumnasMedicamentos()
        {
            this->dgvMedicamentos->Columns->Clear();
            this->dgvMedicamentos->DataSource = nullptr;
            this->dgvMedicamentos->Columns->Add(L"colIdMedicamento", L"ID");
            this->dgvMedicamentos->Columns->Add(L"colNombreMedicamento", L"Nombre");
            this->dgvMedicamentos->Columns->Add(L"colTamanoMedicamento", L"Tamano");
            this->dgvMedicamentos->Columns->Add(L"colTipoMedicamento", L"Tipo");
        }

        void CargarAdministradores()
        {
            ConfigurarColumnasAdministradores();
            List<Administrador^>^ lista = this->adminController->ObtenerAdministradoresInactivosTXT();
            for each(Administrador ^ admin in lista)
                this->dgvAdministradores->Rows->Add(admin->getId(), admin->getNombre(), admin->getApellido(), admin->getPIN());
        }

        void CargarPacientes()
        {
            ConfigurarColumnasPacientes();
            List<Paciente^>^ lista = this->pacienteController->ObtenerPacientesInactivosTXT();

            for each(Paciente ^ paciente in lista) {
                PacienteInvitado^ invitado = dynamic_cast<PacienteInvitado^>(paciente);
                String^ diasEstancia = invitado == nullptr ? L"-" : invitado->getDiasEstancia().ToString();
                this->dgvPacientes->Rows->Add(
                    paciente->getId(),
                    paciente->getNombre(),
                    paciente->getApellido(),
                    paciente->getHuellaID(),
                    paciente->getEnCasa() ? L"Si" : L"No",
                    diasEstancia);
            }
        }

        void CargarMedicamentos()
        {
            ConfigurarColumnasMedicamentos();
            List<Medicamento^>^ lista = this->medicamentoController->ObtenerMedicamentosInactivosTXT();

            for each(Medicamento ^ medicamento in lista)
                this->dgvMedicamentos->Rows->Add(
                    medicamento->getId(),
                    medicamento->getNombre(),
                    medicamento->getTamano(),
                    this->medicamentoController->ObtenerTipo(medicamento));
        }

        void CargarRecetas()
        {
            this->dgvRecetas->Columns->Clear();
            this->dgvRecetas->DataSource = nullptr;
            this->dgvRecetas->DataSource = this->recetaController->ObtenerRecetasInactivasTablaTXT();

            if (this->dgvRecetas->Columns->Contains(L"idReceta")) this->dgvRecetas->Columns[L"idReceta"]->HeaderText = L"ID";
            if (this->dgvRecetas->Columns->Contains(L"idPaciente")) this->dgvRecetas->Columns[L"idPaciente"]->HeaderText = L"ID Paciente";
            if (this->dgvRecetas->Columns->Contains(L"paciente")) this->dgvRecetas->Columns[L"paciente"]->HeaderText = L"Paciente";
            if (this->dgvRecetas->Columns->Contains(L"estadoPaciente")) this->dgvRecetas->Columns[L"estadoPaciente"]->HeaderText = L"Estado paciente";
            if (this->dgvRecetas->Columns->Contains(L"idMedicamento")) this->dgvRecetas->Columns[L"idMedicamento"]->HeaderText = L"ID Medicamento";
            if (this->dgvRecetas->Columns->Contains(L"medicamento")) this->dgvRecetas->Columns[L"medicamento"]->HeaderText = L"Medicamento";
            if (this->dgvRecetas->Columns->Contains(L"estadoMedicamento")) this->dgvRecetas->Columns[L"estadoMedicamento"]->HeaderText = L"Estado medicamento";
            if (this->dgvRecetas->Columns->Contains(L"dosisDiaria")) this->dgvRecetas->Columns[L"dosisDiaria"]->HeaderText = L"Dosis diaria";
            if (this->dgvRecetas->Columns->Contains(L"dosisTomada")) this->dgvRecetas->Columns[L"dosisTomada"]->HeaderText = L"Dosis tomada";
        }

        void RecargarTodo()
        {
            CargarAdministradores();
            CargarPacientes();
            CargarMedicamentos();
            CargarRecetas();
        }

        int ObtenerIdSeleccionado(System::Windows::Forms::DataGridView^ grid)
        {
            if (grid->SelectedRows->Count == 0)
                return -1;

            Object^ valor = grid->SelectedRows[0]->Cells[0]->Value;
            if (valor == nullptr || valor == DBNull::Value)
                return -1;

            return Convert::ToInt32(valor);
        }

        void AjustarDistribucion()
        {
            int margenHorizontal = 22;
            int margenVertical = 18;

            this->panelBody->Padding =
                System::Windows::Forms::Padding(
                    margenHorizontal,
                    margenVertical,
                    margenHorizontal,
                    margenVertical
                );

            this->panelHeader->Height = 84;
            this->tabControl1->ItemSize =
                System::Drawing::Size(
                    Math::Max(140, (this->tabControl1->ClientSize.Width - 8) / 4),
                    34
                );
        }

        System::Void frmRestauracion_Resize(
            System::Object^ sender,
            System::EventArgs^ e
        )
        {
            AjustarDistribucion();
        }

        System::Void frmRestauracion_Load(System::Object^ sender, System::EventArgs^ e)
        {
            RecargarTodo();
            AjustarDistribucion();
            this->BeginInvoke(
                gcnew MethodInvoker(
                    this,
                    &frmRestauracion::AjustarDistribucion
                )
            );
        }

        System::Void btnRestaurarAdministrador_Click(System::Object^ sender, System::EventArgs^ e)
        {
            int id = ObtenerIdSeleccionado(this->dgvAdministradores);
            if (id < 0) {
                MessageBox::Show(L"Seleccione un administrador para restaurar.", L"Restauracion",
                    MessageBoxButtons::OK, MessageBoxIcon::Information);
                return;
            }

            if (this->adminController->RestaurarAdministradorTXT(id)) {
                MessageBox::Show(L"Administrador restaurado correctamente.", L"Restauracion",
                    MessageBoxButtons::OK, MessageBoxIcon::Information);
                RecargarTodo();
                return;
            }

            MessageBox::Show(L"No se pudo restaurar el administrador seleccionado.", L"Restauracion",
                MessageBoxButtons::OK, MessageBoxIcon::Warning);
        }

        System::Void btnRestaurarPaciente_Click(System::Object^ sender, System::EventArgs^ e)
        {
            int id = ObtenerIdSeleccionado(this->dgvPacientes);
            if (id < 0) {
                MessageBox::Show(L"Seleccione un paciente para restaurar.", L"Restauracion",
                    MessageBoxButtons::OK, MessageBoxIcon::Information);
                return;
            }

            if (this->pacienteController->RestaurarPacienteTXT(id)) {
                MessageBox::Show(L"Paciente restaurado correctamente.", L"Restauracion",
                    MessageBoxButtons::OK, MessageBoxIcon::Information);
                RecargarTodo();
                return;
            }

            MessageBox::Show(L"No se pudo restaurar el paciente seleccionado.", L"Restauracion",
                MessageBoxButtons::OK, MessageBoxIcon::Warning);
        }

        System::Void btnRestaurarMedicamento_Click(System::Object^ sender, System::EventArgs^ e)
        {
            int id = ObtenerIdSeleccionado(this->dgvMedicamentos);
            if (id < 0) {
                MessageBox::Show(L"Seleccione un medicamento para restaurar.", L"Restauracion",
                    MessageBoxButtons::OK, MessageBoxIcon::Information);
                return;
            }

            if (this->medicamentoController->RestaurarMedicamentoTXT(id)) {
                MessageBox::Show(L"Medicamento restaurado correctamente.", L"Restauracion",
                    MessageBoxButtons::OK, MessageBoxIcon::Information);
                RecargarTodo();
                return;
            }

            MessageBox::Show(L"No se pudo restaurar el medicamento. Verifique que aun haya espacio dentro del limite de 4 medicamentos activos.", L"Restauracion",
                MessageBoxButtons::OK, MessageBoxIcon::Warning);
        }

        System::Void btnRestaurarReceta_Click(System::Object^ sender, System::EventArgs^ e)
        {
            int id = ObtenerIdSeleccionado(this->dgvRecetas);
            if (id < 0) {
                MessageBox::Show(L"Seleccione una receta para restaurar.", L"Restauracion",
                    MessageBoxButtons::OK, MessageBoxIcon::Information);
                return;
            }

            String^ mensajeError = L"";
            if (this->recetaController->RestaurarRecetaTXT(id, mensajeError)) {
                MessageBox::Show(L"Receta restaurada correctamente.", L"Restauracion",
                    MessageBoxButtons::OK, MessageBoxIcon::Information);
                RecargarTodo();
                return;
            }

            if (String::IsNullOrWhiteSpace(mensajeError))
                mensajeError = L"No se pudo restaurar la receta seleccionada.";

            MessageBox::Show(mensajeError, L"Restauracion",
                MessageBoxButtons::OK, MessageBoxIcon::Warning);
        }
    };
}
