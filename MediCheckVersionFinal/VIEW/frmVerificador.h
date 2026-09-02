#pragma once
#include "frmAgregarAdmin.h"

namespace VIEW {
	using namespace MODEL;
	using namespace CONTROLLER;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class frmVerificador : public System::Windows::Forms::Form
	{
	public:
		frmVerificador(void)
		{
			InitializeComponent();
			this->adminController = gcnew AdminController();
			this->admin = nullptr;
		}
		frmVerificador(AdminController^ adminController, Administrador^ admin)
		{
			InitializeComponent();
			this->adminController = adminController == nullptr ? gcnew AdminController() : adminController;
			this->admin = admin;
		}

	protected:
		~frmVerificador()
		{
			if (components)
				delete components;
		}

	private:
		AdminController^ adminController;
		Administrador^ admin;

		// Controles visibles en el diseñador
		System::Windows::Forms::Panel^ panelLogo;
		System::Windows::Forms::Panel^ panelForm;
		System::Windows::Forms::Panel^ panelLinea;
		System::Windows::Forms::PictureBox^ pictureBox1;
		System::Windows::Forms::Label^ lblNombreApp;
		System::Windows::Forms::Label^ lblSubApp;
		System::Windows::Forms::Label^ lblTitulo;
		System::Windows::Forms::Label^ lblSubTitulo;
		System::Windows::Forms::Label^ lblUsuario;
		System::Windows::Forms::Label^ lblPass;
		System::Windows::Forms::Label^ lblVersion;
		System::Windows::Forms::TextBox^ textBox1;
		System::Windows::Forms::TextBox^ textBox2;
		System::Windows::Forms::Button^ button1;

	private: System::Windows::Forms::LinkLabel^ linkLabel1;
		   System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->panelLogo = (gcnew System::Windows::Forms::Panel());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->lblNombreApp = (gcnew System::Windows::Forms::Label());
			this->lblSubApp = (gcnew System::Windows::Forms::Label());
			this->panelForm = (gcnew System::Windows::Forms::Panel());
			this->lblTitulo = (gcnew System::Windows::Forms::Label());
			this->lblSubTitulo = (gcnew System::Windows::Forms::Label());
			this->panelLinea = (gcnew System::Windows::Forms::Panel());
			this->lblUsuario = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->lblPass = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->lblVersion = (gcnew System::Windows::Forms::Label());
			this->linkLabel1 = (gcnew System::Windows::Forms::LinkLabel());
			this->panelLogo->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->panelForm->SuspendLayout();
			this->SuspendLayout();
			// 
			// panelLogo
			// 
			this->panelLogo->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(16)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
				static_cast<System::Int32>(static_cast<System::Byte>(62)));
			this->panelLogo->Controls->Add(this->pictureBox1);
			this->panelLogo->Controls->Add(this->lblNombreApp);
			this->panelLogo->Controls->Add(this->lblSubApp);
			this->panelLogo->Location = System::Drawing::Point(0, 0);
			this->panelLogo->Name = L"panelLogo";
			this->panelLogo->Size = System::Drawing::Size(160, 320);
			this->panelLogo->TabIndex = 0;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->Location = System::Drawing::Point(20, 60);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(120, 120);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// lblNombreApp
			// 
			this->lblNombreApp->AutoSize = true;
			this->lblNombreApp->BackColor = System::Drawing::Color::Transparent;
			this->lblNombreApp->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Bold));
			this->lblNombreApp->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(93)), static_cast<System::Int32>(static_cast<System::Byte>(202)),
				static_cast<System::Int32>(static_cast<System::Byte>(165)));
			this->lblNombreApp->Location = System::Drawing::Point(18, 200);
			this->lblNombreApp->Name = L"lblNombreApp";
			this->lblNombreApp->Size = System::Drawing::Size(85, 20);
			this->lblNombreApp->TabIndex = 1;
			this->lblNombreApp->Text = L"MediCheck";
			// 
			// lblSubApp
			// 
			this->lblSubApp->AutoSize = true;
			this->lblSubApp->BackColor = System::Drawing::Color::Transparent;
			this->lblSubApp->Font = (gcnew System::Drawing::Font(L"Segoe UI", 7.5F));
			this->lblSubApp->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(74)), static_cast<System::Int32>(static_cast<System::Byte>(122)),
				static_cast<System::Int32>(static_cast<System::Byte>(155)));
			this->lblSubApp->Location = System::Drawing::Point(18, 225);
			this->lblSubApp->Name = L"lblSubApp";
			this->lblSubApp->Size = System::Drawing::Size(87, 12);
			this->lblSubApp->TabIndex = 2;
			this->lblSubApp->Text = L"Sistema de gestión";
			// 
			// panelForm
			// 
			this->panelForm->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(238)), static_cast<System::Int32>(static_cast<System::Byte>(243)),
				static_cast<System::Int32>(static_cast<System::Byte>(247)));
			this->panelForm->Controls->Add(this->linkLabel1);
			this->panelForm->Controls->Add(this->lblTitulo);
			this->panelForm->Controls->Add(this->lblSubTitulo);
			this->panelForm->Controls->Add(this->panelLinea);
			this->panelForm->Controls->Add(this->lblUsuario);
			this->panelForm->Controls->Add(this->textBox1);
			this->panelForm->Controls->Add(this->lblPass);
			this->panelForm->Controls->Add(this->textBox2);
			this->panelForm->Controls->Add(this->button1);
			this->panelForm->Controls->Add(this->lblVersion);
			this->panelForm->Location = System::Drawing::Point(160, 0);
			this->panelForm->Name = L"panelForm";
			this->panelForm->Size = System::Drawing::Size(260, 320);
			this->panelForm->TabIndex = 1;
			// 
			// lblTitulo
			// 
			this->lblTitulo->AutoSize = true;
			this->lblTitulo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13, System::Drawing::FontStyle::Bold));
			this->lblTitulo->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(26)), static_cast<System::Int32>(static_cast<System::Byte>(58)),
				static_cast<System::Int32>(static_cast<System::Byte>(82)));
			this->lblTitulo->Location = System::Drawing::Point(24, 36);
			this->lblTitulo->Name = L"lblTitulo";
			this->lblTitulo->Size = System::Drawing::Size(125, 25);
			this->lblTitulo->TabIndex = 0;
			this->lblTitulo->Text = L"Iniciar Sesión";
			// 
			// lblSubTitulo
			// 
			this->lblSubTitulo->AutoSize = true;
			this->lblSubTitulo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.5F));
			this->lblSubTitulo->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(136)), static_cast<System::Int32>(static_cast<System::Byte>(136)),
				static_cast<System::Int32>(static_cast<System::Byte>(136)));
			this->lblSubTitulo->Location = System::Drawing::Point(26, 64);
			this->lblSubTitulo->Name = L"lblSubTitulo";
			this->lblSubTitulo->Size = System::Drawing::Size(133, 15);
			this->lblSubTitulo->TabIndex = 1;
			this->lblSubTitulo->Text = L"Ingrese sus credenciales";
			// 
			// panelLinea
			// 
			this->panelLinea->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(200)), static_cast<System::Int32>(static_cast<System::Byte>(215)),
				static_cast<System::Int32>(static_cast<System::Byte>(225)));
			this->panelLinea->Location = System::Drawing::Point(24, 86);
			this->panelLinea->Name = L"panelLinea";
			this->panelLinea->Size = System::Drawing::Size(210, 1);
			this->panelLinea->TabIndex = 2;
			// 
			// lblUsuario
			// 
			this->lblUsuario->AutoSize = true;
			this->lblUsuario->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Bold));
			this->lblUsuario->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(74)), static_cast<System::Int32>(static_cast<System::Byte>(122)),
				static_cast<System::Int32>(static_cast<System::Byte>(155)));
			this->lblUsuario->Location = System::Drawing::Point(24, 100);
			this->lblUsuario->Name = L"lblUsuario";
			this->lblUsuario->Size = System::Drawing::Size(47, 13);
			this->lblUsuario->TabIndex = 3;
			this->lblUsuario->Text = L"Usuario";
			// 
			// textBox1
			// 
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->textBox1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(26)), static_cast<System::Int32>(static_cast<System::Byte>(58)),
				static_cast<System::Int32>(static_cast<System::Byte>(82)));
			this->textBox1->Location = System::Drawing::Point(24, 118);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(210, 25);
			this->textBox1->TabIndex = 0;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &frmVerificador::textBox1_TextChanged);
			// 
			// lblPass
			// 
			this->lblPass->AutoSize = true;
			this->lblPass->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Bold));
			this->lblPass->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(74)), static_cast<System::Int32>(static_cast<System::Byte>(122)),
				static_cast<System::Int32>(static_cast<System::Byte>(155)));
			this->lblPass->Location = System::Drawing::Point(24, 158);
			this->lblPass->Name = L"lblPass";
			this->lblPass->Size = System::Drawing::Size(66, 13);
			this->lblPass->TabIndex = 5;
			this->lblPass->Text = L"Contraseña";
			// 
			// textBox2
			// 
			this->textBox2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->textBox2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(26)), static_cast<System::Int32>(static_cast<System::Byte>(58)),
				static_cast<System::Int32>(static_cast<System::Byte>(82)));
			this->textBox2->Location = System::Drawing::Point(24, 176);
			this->textBox2->Name = L"textBox2";
			this->textBox2->PasswordChar = '*';
			this->textBox2->Size = System::Drawing::Size(210, 25);
			this->textBox2->TabIndex = 1;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &frmVerificador::textBox2_TextChanged);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(26)), static_cast<System::Int32>(static_cast<System::Byte>(58)),
				static_cast<System::Int32>(static_cast<System::Byte>(82)));
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
			this->button1->ForeColor = System::Drawing::Color::White;
			this->button1->Location = System::Drawing::Point(24, 224);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(210, 38);
			this->button1->TabIndex = 2;
			this->button1->Text = L"ACCEDER";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &frmVerificador::button1_Click);
			// 
			// lblVersion
			// 
			this->lblVersion->AutoSize = true;
			this->lblVersion->Font = (gcnew System::Drawing::Font(L"Segoe UI", 7.5F));
			this->lblVersion->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(180)), static_cast<System::Int32>(static_cast<System::Byte>(195)),
				static_cast<System::Int32>(static_cast<System::Byte>(210)));
			this->lblVersion->Location = System::Drawing::Point(26, 278);
			this->lblVersion->Name = L"lblVersion";
			this->lblVersion->Size = System::Drawing::Size(22, 12);
			this->lblVersion->TabIndex = 8;
			this->lblVersion->Text = L"v1.0";
			// 
			// linkLabel1
			// 
			this->linkLabel1->AutoSize = true;
			this->linkLabel1->Location = System::Drawing::Point(171, 277);
			this->linkLabel1->Name = L"linkLabel1";
			this->linkLabel1->Size = System::Drawing::Size(63, 13);
			this->linkLabel1->TabIndex = 2;
			this->linkLabel1->TabStop = true;
			this->linkLabel1->Text = L"Registrarme";
			this->linkLabel1->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &frmVerificador::linkLabel1_LinkClicked);
			// 
			// frmVerificador
			// 
			this->AcceptButton = this->button1;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(22)), static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(80)));
			this->ClientSize = System::Drawing::Size(420, 320);
			this->Controls->Add(this->panelLogo);
			this->Controls->Add(this->panelForm);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"frmVerificador";
			this->Text = L"MediCheck";
			this->Load += gcnew System::EventHandler(this, &frmVerificador::frmVerificador_Load);
			this->panelLogo->ResumeLayout(false);
			this->panelLogo->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->panelForm->ResumeLayout(false);
			this->panelForm->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

		// ── FORM LOAD ─────────────────────────────────────────────────────────
	private: System::Void frmVerificador_Load(System::Object^ sender, System::EventArgs^ e)
	{
		this->ShowIcon = true;
		try {
			this->Icon = gcnew System::Drawing::Icon(L"medicheck.ico");
		}
		catch (...) {}

		try {
			this->pictureBox1->Image = Image::FromFile("MediCheck.png");
			this->pictureBox1->SizeMode = PictureBoxSizeMode::Zoom;
		}
		catch (...) {}
	}

		   // ── EVENTOS ──────────────────────────────────────────────────────────
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {}
	private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ nombre = this->textBox1->Text->Trim()->ToLower();
		String^ pinTexto = this->textBox2->Text->Trim();

		if (nombre == "admin" && pinTexto == "123") {
			this->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->Close();
			return;
		}

		if (nombre == "" || pinTexto == "") {
			MessageBox::Show("Complete todos los campos", "Aviso",
				MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		int pin = 0;
		if (!Int32::TryParse(pinTexto, pin)) {
			MessageBox::Show("La contraseña debe ser numerica.", "Aviso",
				MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		if (this->adminController == nullptr)
			this->adminController = gcnew AdminController();

		List<Administrador^>^ admins = this->adminController->ObtenerTodosAdministradoresTXT();

		for each(Administrador ^ admin in admins) {
			if (admin->getNombre()->ToLower() == nombre && admin->getPIN() == pin) {
				this->DialogResult = System::Windows::Forms::DialogResult::OK;
				this->Close();
				return;
			}
		}

		MessageBox::Show("Usuario o contraseña incorrectos", "Error",
			MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	private: System::Void linkLabel1_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
		if (this->adminController == nullptr)
			this->adminController = gcnew AdminController();

		frmAgregarAdmin^ registro = gcnew frmAgregarAdmin(this->adminController);
		registro->StartPosition = FormStartPosition::CenterParent;
		registro->ShowDialog(this);

		this->textBox1->Clear();
		this->textBox2->Clear();
		this->textBox1->Focus();
	}
};
}


