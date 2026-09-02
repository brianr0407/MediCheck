#pragma once
#include	"frmEliminador.h"
namespace VIEW {
	using namespace MODEL;
	using namespace CONTROLLER;
	using namespace System::Collections::Generic;

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de frmEliminarPaciente
	/// </summary>
	public ref class frmEliminarPaciente : public System::Windows::Forms::Form
	{
	public:
		frmEliminarPaciente(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}
		frmEliminarPaciente(PacienteController^ pacienteController, Paciente^ paciente)
		{
			InitializeComponent();
			this->pacienteController = pacienteController;
			this->paciente = paciente;
			//
			//TODO: agregar código de constructor aquí
			//
		}
	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmEliminarPaciente()
		{
			if (components)
			{
				delete components;
			}
		}

	private: PacienteController^ pacienteController;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;
	private: Paciente^ paciente;
	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->button2);
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(9, 10);
			this->groupBox1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->groupBox1->Size = System::Drawing::Size(212, 129);
			this->groupBox1->TabIndex = 3;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Eliminar";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(22, 74);
			this->button2->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(56, 23);
			this->button2->TabIndex = 11;
			this->button2->Text = L"Aceptar";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &frmEliminarPaciente::button2_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(118, 74);
			this->button1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(56, 23);
			this->button1->TabIndex = 10;
			this->button1->Text = L"Cancelar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &frmEliminarPaciente::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Enabled = false;
			this->textBox1->Location = System::Drawing::Point(99, 26);
			this->textBox1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(76, 20);
			this->textBox1->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(20, 28);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(78, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"# ID a eliminar:";
			// 
			// frmEliminarPaciente
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(237, 147);
			this->Controls->Add(this->groupBox1);
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->Name = L"frmEliminarPaciente";
			this->Text = L"frmEliminarPaciente";
			this->Load += gcnew System::EventHandler(this, &frmEliminarPaciente::frmEliminarPaciente_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void frmEliminarPaciente_Load(System::Object^ sender, System::EventArgs^ e) {
		this->textBox1->Text = Convert::ToString(this->paciente->getId());

	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		//aceptar
		frmEliminador^ eliminador = gcnew frmEliminador("¿Esta seguro de eliminar este Paciente?\nLas Recetas asociadas tambien se eliminaran");
		if (eliminador->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			// código de eliminar
			int codigo = Convert::ToInt32(this->textBox1->Text);
			if (this->pacienteController->BuscarPacientePorIdTXT(codigo) != nullptr) {

				// 1. Eliminar todas las recetas del paciente
				RecetaController^ recetaController = gcnew RecetaController();
				List<Receta^>^ recetas = recetaController->BuscarRecetasActivasPorCronogramaIdTXT(codigo);
				for each (Receta ^ receta in recetas) {
					recetaController->EliminarRecetaTXT(receta->getIdReceta());
				}

				// 2. Eliminar el cronograma (mismo id que el paciente)
				CronogramaTomaController^ cronogramaController = gcnew CronogramaTomaController();
				cronogramaController->EliminarCronogramaTomaTXT(codigo);

				// 3. Eliminar el paciente
				this->pacienteController->EliminarPacienteTXT(codigo);

				MessageBox::Show("Paciente Eliminado exitosamente");
				this->Close();
			}

		}
	};
	};
}