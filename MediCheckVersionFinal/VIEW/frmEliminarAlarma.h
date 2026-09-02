#pragma once
#include "frmEliminador.h"
namespace VIEW {
	using namespace MODEL;
	using namespace CONTROLLER;

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de frmEliminarAlarma
	/// </summary>
	public ref class frmEliminarAlarma : public System::Windows::Forms::Form
	{
	public:
		frmEliminarAlarma(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}
		frmEliminarAlarma(AlarmaController^ alarmaController, Alarma^ alarma)
		{
			InitializeComponent();
			this->alarmaController = alarmaController;
			this->alarma = alarma;
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmEliminarAlarma()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^ groupBox1;
	protected:
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;
	private: Alarma^ alarma;
	private: AlarmaController^ alarmaController;
	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

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
			this->groupBox1->TabIndex = 5;
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
			this->button2->Click += gcnew System::EventHandler(this, &frmEliminarAlarma::button2_Click);
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
			this->button1->Click += gcnew System::EventHandler(this, &frmEliminarAlarma::button1_Click);
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
			// frmEliminarAlarma
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(232, 150);
			this->Controls->Add(this->groupBox1);
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->Name = L"frmEliminarAlarma";
			this->Text = L"frmEliminarAlarma";
			this->Load += gcnew System::EventHandler(this, &frmEliminarAlarma::frmEliminarAlarma_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	int codigo = Convert::ToInt32(this->textBox1->Text);

	// Mismo patrón que medicamento: abrir frmEliminador para confirmar
	frmEliminador^ eliminador = gcnew frmEliminador(
		"¿Está seguro de eliminar esta alarma?\nEl paciente asociado quedará sin alarma y se le asignará una básica automáticamente."
	);

	if (eliminador->ShowDialog() == System::Windows::Forms::DialogResult::OK) {

		if (this->alarmaController->BuscarAlarmaPorIdTXT(codigo) != nullptr) {

			// Eliminar del TXT principal (el BU conserva el historial)
			this->alarmaController->EliminarAlarmaTXT(codigo);

			// ============================================================
			// TODO: cuando implementes Paciente, agregar aquí:
			// 1. Buscar el paciente que tenga alarma con este ID
			// 2. Crear una AlarmaSnooze básica con ObtenerSiguienteId()
			//    y tiempo de espera predeterminado (ej: 5 minutos)
			// 3. Asignar la nueva alarma al paciente y guardar en su TXT
			// Ejemplo futuro:
			//   PacienteController^ pc = gcnew PacienteController();
			//   Paciente^ paciente = pc->BuscarPacientePorIdAlarmaTXT(codigo);
			//   if (paciente != nullptr) {
			//       int nuevoId = this->alarmaController->ObtenerSiguienteId();
			//       AlarmaSnooze^ basica = gcnew AlarmaSnooze(nuevoId, false, 5);
			//       this->alarmaController->AgregarAlarmaTXT(basica);
			//       paciente->setAlarma(basica);
			//       pc->ActualizarArchivo(paciente);
			//   }
			// ============================================================

			MessageBox::Show("Alarma eliminada exitosamente.");
			this->Close();
		}
		else {
			MessageBox::Show("No se encontró la alarma indicada.");
		}
	}
}
private: System::Void frmEliminarAlarma_Load(System::Object^ sender, System::EventArgs^ e) {
	if (this->alarma != nullptr)
		this->textBox1->Text = this->alarma->getId().ToString();
}
};
}
