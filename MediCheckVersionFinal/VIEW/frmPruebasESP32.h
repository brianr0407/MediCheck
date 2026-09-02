#pragma once

namespace VIEW {
    using namespace System;
    using namespace System::IO::Ports;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class frmPruebasESP32 : public System::Windows::Forms::Form
    {
    public:
        frmPruebasESP32(void)
        {
            InitializeComponent();
        }

    protected:
        ~frmPruebasESP32()
        {
            if (components)
                delete components;
        }

    private:
        System::IO::Ports::SerialPort^ puerto;
        System::Windows::Forms::Timer^ timerSerial;
        bool ledEncendido;
    private: System::Windows::Forms::GroupBox^ groupBox1;


    private: System::Windows::Forms::Button^ button8;
    private: System::Windows::Forms::Button^ button7;
    private: System::Windows::Forms::Button^ button6;
    private: System::Windows::Forms::Button^ button5;
    private: System::Windows::Forms::Button^ button4;
    private: System::Windows::Forms::Button^ button3;
    private: System::Windows::Forms::Button^ button2;
    private: System::Windows::Forms::Button^ button1;
    private: System::Windows::Forms::Label^ label2;
    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::ComboBox^ comboBox3;
    private: System::Windows::Forms::ComboBox^ comboBox2;
    private: System::Windows::Forms::ComboBox^ comboBox1;
    private: System::Windows::Forms::GroupBox^ groupBox2;
    private: System::Windows::Forms::TextBox^ textBox1;
    private: System::Windows::Forms::Label^ label6;
    private: System::Windows::Forms::Label^ label5;
    private: System::Windows::Forms::Label^ label4;
    private: System::Windows::Forms::Label^ label3;
    private: System::Windows::Forms::Label^ label8;
    private: System::Windows::Forms::TextBox^ textBox4;
    private: System::Windows::Forms::TextBox^ textBox3;
    private: System::Windows::Forms::TextBox^ textBox2;
    private: System::Windows::Forms::Label^ label7;
    private: System::Windows::Forms::Panel^ panelHeader;
    private: System::Windows::Forms::Label^ lblTitulo;
    private: System::Windows::Forms::Label^ lblSubtitulo;


    private: System::ComponentModel::IContainer^ components;


#pragma region Windows Form Designer generated code
           void InitializeComponent(void)
           {
               this->components = (gcnew System::ComponentModel::Container());
               this->timerSerial = (gcnew System::Windows::Forms::Timer(this->components));
               this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
               this->label8 = (gcnew System::Windows::Forms::Label());
               this->textBox4 = (gcnew System::Windows::Forms::TextBox());
               this->textBox3 = (gcnew System::Windows::Forms::TextBox());
               this->textBox2 = (gcnew System::Windows::Forms::TextBox());
               this->label7 = (gcnew System::Windows::Forms::Label());
               this->panelHeader = (gcnew System::Windows::Forms::Panel());
               this->lblTitulo = (gcnew System::Windows::Forms::Label());
               this->lblSubtitulo = (gcnew System::Windows::Forms::Label());
               this->label6 = (gcnew System::Windows::Forms::Label());
               this->label5 = (gcnew System::Windows::Forms::Label());
               this->label4 = (gcnew System::Windows::Forms::Label());
               this->label3 = (gcnew System::Windows::Forms::Label());
               this->label2 = (gcnew System::Windows::Forms::Label());
               this->label1 = (gcnew System::Windows::Forms::Label());
               this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
               this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
               this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
               this->button8 = (gcnew System::Windows::Forms::Button());
               this->button7 = (gcnew System::Windows::Forms::Button());
               this->button6 = (gcnew System::Windows::Forms::Button());
               this->button5 = (gcnew System::Windows::Forms::Button());
               this->button4 = (gcnew System::Windows::Forms::Button());
               this->button3 = (gcnew System::Windows::Forms::Button());
               this->button2 = (gcnew System::Windows::Forms::Button());
               this->button1 = (gcnew System::Windows::Forms::Button());
               this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
               this->textBox1 = (gcnew System::Windows::Forms::TextBox());
               this->groupBox1->SuspendLayout();
               this->groupBox2->SuspendLayout();
               this->panelHeader->SuspendLayout();
               this->SuspendLayout();
               // 
               // timerSerial
               // 
               this->timerSerial->Tick += gcnew System::EventHandler(this, &frmPruebasESP32::timerSerial_Tick);
               // 
               // groupBox1
               // 
               this->groupBox1->BackColor = System::Drawing::Color::White;
               this->groupBox1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular));
               this->groupBox1->ForeColor = System::Drawing::Color::FromArgb(15, 41, 66);
               this->groupBox1->Controls->Add(this->label8);
               this->groupBox1->Controls->Add(this->textBox4);
               this->groupBox1->Controls->Add(this->textBox3);
               this->groupBox1->Controls->Add(this->textBox2);
               this->groupBox1->Controls->Add(this->label7);
               this->groupBox1->Controls->Add(this->label6);
               this->groupBox1->Controls->Add(this->label5);
               this->groupBox1->Controls->Add(this->label4);
               this->groupBox1->Controls->Add(this->label3);
               this->groupBox1->Controls->Add(this->label2);
               this->groupBox1->Controls->Add(this->label1);
               this->groupBox1->Controls->Add(this->comboBox3);
               this->groupBox1->Controls->Add(this->comboBox2);
               this->groupBox1->Controls->Add(this->comboBox1);
               this->groupBox1->Controls->Add(this->button8);
               this->groupBox1->Controls->Add(this->button7);
               this->groupBox1->Controls->Add(this->button6);
               this->groupBox1->Controls->Add(this->button5);
               this->groupBox1->Controls->Add(this->button4);
               this->groupBox1->Controls->Add(this->button3);
               this->groupBox1->Controls->Add(this->button2);
               this->groupBox1->Controls->Add(this->button1);
               this->groupBox1->Location = System::Drawing::Point(22, 18);
               this->groupBox1->Name = L"groupBox1";
               this->groupBox1->Size = System::Drawing::Size(520, 640);
               this->groupBox1->TabIndex = 0;
               this->groupBox1->TabStop = false;
               this->groupBox1->Text = L"Panel de control";
               // 
               // label8
               // 
               this->label8->AutoSize = true;
               this->label8->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F, System::Drawing::FontStyle::Regular));
               this->label8->ForeColor = System::Drawing::Color::FromArgb(90, 115, 140);
               this->label8->Location = System::Drawing::Point(16, 281);
               this->label8->Name = L"label8";
               this->label8->Size = System::Drawing::Size(73, 15);
               this->label8->TabIndex = 23;
               this->label8->Text = L"Ingresar ID :";
               // 
               // textBox4
               // 
               this->textBox4->BackColor = System::Drawing::Color::FromArgb(247, 249, 251);
               this->textBox4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
               this->textBox4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F));
               this->textBox4->ForeColor = System::Drawing::Color::FromArgb(40, 60, 80);
               this->textBox4->Location = System::Drawing::Point(98, 277);
               this->textBox4->MaxLength = 3;
               this->textBox4->Name = L"textBox4";
               this->textBox4->Size = System::Drawing::Size(82, 20);
               this->textBox4->TabIndex = 22;
               // 
               // textBox3
               // 
               this->textBox3->BackColor = System::Drawing::Color::FromArgb(247, 249, 251);
               this->textBox3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
               this->textBox3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F));
               this->textBox3->ForeColor = System::Drawing::Color::FromArgb(40, 60, 80);
               this->textBox3->Location = System::Drawing::Point(228, 379);
               this->textBox3->MaxLength = 20;
               this->textBox3->Name = L"textBox3";
               this->textBox3->Size = System::Drawing::Size(100, 20);
               this->textBox3->TabIndex = 21;
               // 
               // textBox2
               // 
               this->textBox2->BackColor = System::Drawing::Color::FromArgb(247, 249, 251);
               this->textBox2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
               this->textBox2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F));
               this->textBox2->ForeColor = System::Drawing::Color::FromArgb(40, 60, 80);
               this->textBox2->Location = System::Drawing::Point(98, 379);
               this->textBox2->MaxLength = 20;
               this->textBox2->Name = L"textBox2";
               this->textBox2->Size = System::Drawing::Size(100, 20);
               this->textBox2->TabIndex = 20;
               // 
               // label7
               // 
               this->label7->AutoSize = true;
               this->label7->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F, System::Drawing::FontStyle::Regular));
               this->label7->ForeColor = System::Drawing::Color::FromArgb(90, 115, 140);
               this->label7->Location = System::Drawing::Point(16, 379);
               this->label7->Name = L"label7";
               this->label7->Size = System::Drawing::Size(70, 15);
               this->label7->TabIndex = 19;
               this->label7->Text = L"Texto LCD :";
               // 
               // label6
               // 
               this->label6->AutoSize = true;
               this->label6->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F, System::Drawing::FontStyle::Bold));
               this->label6->ForeColor = System::Drawing::Color::FromArgb(90, 115, 140);
               this->label6->Location = System::Drawing::Point(6, 249);
               this->label6->Name = L"label6";
               this->label6->Size = System::Drawing::Size(121, 15);
               this->label6->TabIndex = 18;
               this->label6->Text = L"Opciones de Huella :";
               // 
               // label5
               // 
               this->label5->AutoSize = true;
               this->label5->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F, System::Drawing::FontStyle::Bold));
               this->label5->ForeColor = System::Drawing::Color::FromArgb(90, 115, 140);
               this->label5->Location = System::Drawing::Point(6, 150);
               this->label5->Name = L"label5";
               this->label5->Size = System::Drawing::Size(76, 15);
               this->label5->TabIndex = 17;
               this->label5->Text = L"Dispensado:";
               // 
               // label4
               // 
               this->label4->AutoSize = true;
               this->label4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F, System::Drawing::FontStyle::Bold));
               this->label4->ForeColor = System::Drawing::Color::FromArgb(90, 115, 140);
               this->label4->Location = System::Drawing::Point(16, 102);
               this->label4->Name = L"label4";
               this->label4->Size = System::Drawing::Size(162, 15);
               this->label4->TabIndex = 16;
               this->label4->Text = L"Probar Conexiones y Puerto:";
               // 
               // label3
               // 
               this->label3->AutoSize = true;
               this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F, System::Drawing::FontStyle::Regular));
               this->label3->ForeColor = System::Drawing::Color::FromArgb(90, 115, 140);
               this->label3->Location = System::Drawing::Point(16, 201);
               this->label3->Name = L"label3";
               this->label3->Size = System::Drawing::Size(123, 15);
               this->label3->TabIndex = 15;
               this->label3->Text = L"Tipo de Dispensado :";
               // 
               // label2
               // 
               this->label2->AutoSize = true;
               this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F, System::Drawing::FontStyle::Regular));
               this->label2->ForeColor = System::Drawing::Color::FromArgb(90, 115, 140);
               this->label2->Location = System::Drawing::Point(16, 174);
               this->label2->Name = L"label2";
               this->label2->Size = System::Drawing::Size(98, 15);
               this->label2->TabIndex = 14;
               this->label2->Text = L"Compartimento :";
               // 
               // label1
               // 
               this->label1->AutoSize = true;
               this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F, System::Drawing::FontStyle::Regular));
               this->label1->ForeColor = System::Drawing::Color::FromArgb(90, 115, 140);
               this->label1->Location = System::Drawing::Point(16, 36);
               this->label1->Name = L"label1";
               this->label1->Size = System::Drawing::Size(97, 15);
               this->label1->TabIndex = 13;
               this->label1->Text = L"Ingresar Puerto :";
               // 
               // comboBox3
               // 
               this->comboBox3->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
               this->comboBox3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
               this->comboBox3->BackColor = System::Drawing::Color::White;
               this->comboBox3->ForeColor = System::Drawing::Color::FromArgb(30, 50, 70);
               this->comboBox3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F));
               this->comboBox3->FormattingEnabled = true;
               this->comboBox3->Location = System::Drawing::Point(151, 198);
               this->comboBox3->Name = L"comboBox3";
               this->comboBox3->Size = System::Drawing::Size(96, 21);
               this->comboBox3->TabIndex = 12;
               // 
               // comboBox2
               // 
               this->comboBox2->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
               this->comboBox2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
               this->comboBox2->BackColor = System::Drawing::Color::White;
               this->comboBox2->ForeColor = System::Drawing::Color::FromArgb(30, 50, 70);
               this->comboBox2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F));
               this->comboBox2->FormattingEnabled = true;
               this->comboBox2->Location = System::Drawing::Point(151, 171);
               this->comboBox2->Name = L"comboBox2";
               this->comboBox2->Size = System::Drawing::Size(96, 21);
               this->comboBox2->TabIndex = 11;
               // 
               // comboBox1
               // 
               this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
               this->comboBox1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
               this->comboBox1->BackColor = System::Drawing::Color::White;
               this->comboBox1->ForeColor = System::Drawing::Color::FromArgb(30, 50, 70);
               this->comboBox1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.5F));
               this->comboBox1->FormattingEnabled = true;
               this->comboBox1->Location = System::Drawing::Point(151, 33);
               this->comboBox1->Name = L"comboBox1";
               this->comboBox1->Size = System::Drawing::Size(96, 21);
               this->comboBox1->TabIndex = 10;
               // 
               // button8
               // 

               this->button8->BackColor = System::Drawing::Color::FromArgb(234, 243, 222);
               this->button8->ForeColor = System::Drawing::Color::FromArgb(39, 80, 10);
               this->button8->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
               this->button8->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(168, 208, 106);
               this->button8->FlatAppearance->BorderSize = 1;
               this->button8->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(192, 221, 151);
               this->button8->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.0F, System::Drawing::FontStyle::Regular));
               this->button8->Cursor = System::Windows::Forms::Cursors::Hand;
               this->button8->Location = System::Drawing::Point(98, 414);
               this->button8->Name = L"button8";
               this->button8->Size = System::Drawing::Size(75, 23);
               this->button8->TabIndex = 7;
               this->button8->Text = L"Enviar";
               this->button8->UseVisualStyleBackColor = false;
               this->button8->Click += gcnew System::EventHandler(this, &frmPruebasESP32::button8_Click);
               // 
               // button7
               // 

               this->button7->BackColor = System::Drawing::Color::FromArgb(230, 241, 251);
               this->button7->ForeColor = System::Drawing::Color::FromArgb(12, 68, 124);
               this->button7->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
               this->button7->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(158, 198, 240);
               this->button7->FlatAppearance->BorderSize = 1;
               this->button7->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(181, 212, 244);
               this->button7->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.0F, System::Drawing::FontStyle::Regular));
               this->button7->Cursor = System::Windows::Forms::Cursors::Hand;
               this->button7->Location = System::Drawing::Point(227, 445);
               this->button7->Name = L"button7";
               this->button7->Size = System::Drawing::Size(101, 32);
               this->button7->TabIndex = 6;
               this->button7->Text = L"STATUS";
               this->button7->UseVisualStyleBackColor = false;
               this->button7->Click += gcnew System::EventHandler(this, &frmPruebasESP32::button7_Click);
               // 
               // button6
               // 

               this->button6->BackColor = System::Drawing::Color::FromArgb(230, 241, 251);
               this->button6->ForeColor = System::Drawing::Color::FromArgb(12, 68, 124);
               this->button6->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
               this->button6->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(158, 198, 240);
               this->button6->FlatAppearance->BorderSize = 1;
               this->button6->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(181, 212, 244);
               this->button6->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.0F, System::Drawing::FontStyle::Regular));
               this->button6->Cursor = System::Windows::Forms::Cursors::Hand;
               this->button6->Location = System::Drawing::Point(235, 316);
               this->button6->Name = L"button6";
               this->button6->Size = System::Drawing::Size(93, 23);
               this->button6->TabIndex = 5;
               this->button6->Text = L"CANCELAR";
               this->button6->UseVisualStyleBackColor = false;
               this->button6->Click += gcnew System::EventHandler(this, &frmPruebasESP32::button6_Click);
               // 
               // button5
               // 

               this->button5->BackColor = System::Drawing::Color::FromArgb(234, 243, 222);
               this->button5->ForeColor = System::Drawing::Color::FromArgb(39, 80, 10);
               this->button5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
               this->button5->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(168, 208, 106);
               this->button5->FlatAppearance->BorderSize = 1;
               this->button5->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(192, 221, 151);
               this->button5->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.0F, System::Drawing::FontStyle::Regular));
               this->button5->Cursor = System::Windows::Forms::Cursors::Hand;
               this->button5->Location = System::Drawing::Point(235, 274);
               this->button5->Name = L"button5";
               this->button5->Size = System::Drawing::Size(93, 23);
               this->button5->TabIndex = 4;
               this->button5->Text = L"REGISTRAR";
               this->button5->UseVisualStyleBackColor = false;
               this->button5->Click += gcnew System::EventHandler(this, &frmPruebasESP32::button5_Click);
               // 
               // button4
               // 

               this->button4->BackColor = System::Drawing::Color::FromArgb(230, 241, 251);
               this->button4->ForeColor = System::Drawing::Color::FromArgb(12, 68, 124);
               this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
               this->button4->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(158, 198, 240);
               this->button4->FlatAppearance->BorderSize = 1;
               this->button4->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(181, 212, 244);
               this->button4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.0F, System::Drawing::FontStyle::Regular));
               this->button4->Cursor = System::Windows::Forms::Cursors::Hand;
               this->button4->Location = System::Drawing::Point(98, 316);
               this->button4->Name = L"button4";
               this->button4->Size = System::Drawing::Size(131, 23);
               this->button4->TabIndex = 3;
               this->button4->Text = L"Leer Huella";
               this->button4->UseVisualStyleBackColor = false;
               this->button4->Click += gcnew System::EventHandler(this, &frmPruebasESP32::button4_Click);
               // 
               // button3
               // 

               this->button3->BackColor = System::Drawing::Color::FromArgb(234, 243, 222);
               this->button3->ForeColor = System::Drawing::Color::FromArgb(39, 80, 10);
               this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
               this->button3->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(168, 208, 106);
               this->button3->FlatAppearance->BorderSize = 1;
               this->button3->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(192, 221, 151);
               this->button3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.0F, System::Drawing::FontStyle::Regular));
               this->button3->Cursor = System::Windows::Forms::Cursors::Hand;
               this->button3->Location = System::Drawing::Point(151, 230);
               this->button3->Name = L"button3";
               this->button3->Size = System::Drawing::Size(118, 23);
               this->button3->TabIndex = 2;
               this->button3->Text = L"EJECUTAR";
               this->button3->UseVisualStyleBackColor = false;
               this->button3->Click += gcnew System::EventHandler(this, &frmPruebasESP32::button3_Click);
               // 
               // button2
               // 

               this->button2->BackColor = System::Drawing::Color::FromArgb(230, 241, 251);
               this->button2->ForeColor = System::Drawing::Color::FromArgb(12, 68, 124);
               this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
               this->button2->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(158, 198, 240);
               this->button2->FlatAppearance->BorderSize = 1;
               this->button2->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(181, 212, 244);
               this->button2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.0F, System::Drawing::FontStyle::Regular));
               this->button2->Cursor = System::Windows::Forms::Cursors::Hand;
               this->button2->Location = System::Drawing::Point(193, 97);
               this->button2->Name = L"button2";
               this->button2->Size = System::Drawing::Size(75, 23);
               this->button2->TabIndex = 1;
               this->button2->Text = L"PING";
               this->button2->UseVisualStyleBackColor = false;
               this->button2->Click += gcnew System::EventHandler(this, &frmPruebasESP32::button2_Click);
               // 
               // button1
               // 

               this->button1->BackColor = System::Drawing::Color::FromArgb(234, 243, 222);
               this->button1->ForeColor = System::Drawing::Color::FromArgb(39, 80, 10);
               this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
               this->button1->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(168, 208, 106);
               this->button1->FlatAppearance->BorderSize = 1;
               this->button1->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(192, 221, 151);
               this->button1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.0F, System::Drawing::FontStyle::Regular));
               this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
               this->button1->Location = System::Drawing::Point(253, 33);
               this->button1->Name = L"button1";
               this->button1->Size = System::Drawing::Size(75, 23);
               this->button1->TabIndex = 0;
               this->button1->Text = L"Conectar";
               this->button1->UseVisualStyleBackColor = false;
               this->button1->Click += gcnew System::EventHandler(this, &frmPruebasESP32::button1_Click);
               // 
               // groupBox2
               // 
               this->groupBox2->BackColor = System::Drawing::Color::White;
               this->groupBox2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular));
               this->groupBox2->ForeColor = System::Drawing::Color::FromArgb(15, 41, 66);
               this->groupBox2->Controls->Add(this->textBox1);
               this->groupBox2->Location = System::Drawing::Point(562, 18);
               this->groupBox2->Name = L"groupBox2";
               this->groupBox2->Size = System::Drawing::Size(496, 640);
               this->groupBox2->TabIndex = 1;
               this->groupBox2->TabStop = false;
               this->groupBox2->Text = L"Log de eventos";
               // 
               // textBox1
               // 
               this->textBox1->BackColor = System::Drawing::Color::FromArgb(247, 249, 251);
               this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
               this->textBox1->Font = (gcnew System::Drawing::Font(L"Consolas", 9.5F));
               this->textBox1->ForeColor = System::Drawing::Color::FromArgb(40, 60, 80);
               this->textBox1->Location = System::Drawing::Point(18, 30);
               this->textBox1->Multiline = true;
               this->textBox1->Name = L"textBox1";
               this->textBox1->ReadOnly = true;
               this->textBox1->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
               this->textBox1->Size = System::Drawing::Size(201, 447);
               this->textBox1->TabIndex = 0;
               // 
               // panelHeader
               // 
               this->panelHeader->BackColor = System::Drawing::Color::FromArgb(15, 41, 66);
               this->panelHeader->Controls->Add(this->lblSubtitulo);
               this->panelHeader->Controls->Add(this->lblTitulo);
               this->panelHeader->Dock = System::Windows::Forms::DockStyle::Top;
               this->panelHeader->Location = System::Drawing::Point(0, 0);
               this->panelHeader->Name = L"panelHeader";
               this->panelHeader->Size = System::Drawing::Size(1080, 84);
               this->panelHeader->TabIndex = 2;
               // 
               // lblTitulo
               // 
               this->lblTitulo->AutoSize = true;
               this->lblTitulo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15, System::Drawing::FontStyle::Regular));
               this->lblTitulo->ForeColor = System::Drawing::Color::FromArgb(220, 233, 245);
               this->lblTitulo->Location = System::Drawing::Point(24, 13);
               this->lblTitulo->Name = L"lblTitulo";
               this->lblTitulo->Size = System::Drawing::Size(132, 28);
               this->lblTitulo->TabIndex = 0;
               this->lblTitulo->Text = L"Pruebas ESP32";
               // 
               // lblSubtitulo
               // 
               this->lblSubtitulo->AutoSize = true;
               this->lblSubtitulo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
               this->lblSubtitulo->ForeColor = System::Drawing::Color::FromArgb(200, 218, 235);
               this->lblSubtitulo->Location = System::Drawing::Point(27, 50);
               this->lblSubtitulo->Name = L"lblSubtitulo";
               this->lblSubtitulo->Size = System::Drawing::Size(420, 19);
               this->lblSubtitulo->TabIndex = 1;
               this->lblSubtitulo->Text = L"Conexión, validación y comandos de prueba para el módulo ESP32.";
               // 
               // 
               // frmPruebasESP32
               // 
               this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
               this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
               this->BackColor = System::Drawing::Color::FromArgb(241, 244, 248);
               this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
               this->ClientSize = System::Drawing::Size(1080, 680);
               this->Controls->Add(this->groupBox2);
               this->Controls->Add(this->groupBox1);
               this->Controls->Add(this->panelHeader);
               this->Margin = System::Windows::Forms::Padding(2);
               this->Name = L"frmPruebasESP32";
               this->Text = L"";
               this->Load += gcnew System::EventHandler(this, &frmPruebasESP32::frmPruebasESP32_Load);
               this->Resize += gcnew System::EventHandler(this, &frmPruebasESP32::frmPruebasESP32_Resize);
               this->groupBox1->ResumeLayout(false);
               this->groupBox1->PerformLayout();
               this->groupBox2->ResumeLayout(false);
               this->groupBox2->PerformLayout();
               this->panelHeader->ResumeLayout(false);
               this->panelHeader->PerformLayout();
               this->ResumeLayout(false);

           }
#pragma endregion

    private:

        // ══════════════════════════════════════════════════
        //  FUNCIONES AUXILIARES
        // ══════════════════════════════════════════════════

        void Log(String^ msg) {
            String^ linea = DateTime::Now.ToString("HH:mm:ss") + "  " + msg;
            textBox1->AppendText(linea + Environment::NewLine);
            textBox1->ScrollToCaret();
        }

        void Enviar(String^ cmd) {
            if (puerto == nullptr || !puerto->IsOpen) {
                Log("ERROR: no conectado");
                return;
            }
            puerto->WriteLine(cmd);
            Log(">>> " + cmd);
        }

        // ══════════════════════════════════════════════════
        //  CARGA DEL FORMULARIO
        // ══════════════════════════════════════════════════


        void AjustarDistribucion() {
            int margen = 22;
            int separacion = 20;
            int altoHeader = 84;
            int yInicio = altoHeader + 18;
            int anchoDisponible = this->ClientSize.Width - (margen * 2);

            if (anchoDisponible < 900)
                anchoDisponible = 900;

            int anchoPanelControl = (int)(anchoDisponible * 0.54);
            int anchoLog = anchoDisponible - anchoPanelControl - separacion;
            int altoDisponible = this->ClientSize.Height - yInicio - 18;

            if (altoDisponible < 560)
                altoDisponible = 560;

            this->panelHeader->Width = this->ClientSize.Width;
            this->panelHeader->Height = altoHeader;

            this->groupBox1->Location =
                System::Drawing::Point(margen, yInicio);
            this->groupBox1->Size =
                System::Drawing::Size(anchoPanelControl, altoDisponible);

            this->groupBox2->Location =
                System::Drawing::Point(
                    margen + anchoPanelControl + separacion,
                    yInicio
                );
            this->groupBox2->Size =
                System::Drawing::Size(anchoLog, altoDisponible);

            // El log ocupa todo el espacio interior disponible
            this->textBox1->Location =
                System::Drawing::Point(16, 30);
            this->textBox1->Size =
                System::Drawing::Size(
                    Math::Max(160, this->groupBox2->ClientSize.Width - 32),
                    Math::Max(180, this->groupBox2->ClientSize.Height - 46)
                );
            this->textBox1->Anchor =
                System::Windows::Forms::AnchorStyles::Top |
                System::Windows::Forms::AnchorStyles::Bottom |
                System::Windows::Forms::AnchorStyles::Left |
                System::Windows::Forms::AnchorStyles::Right;

            // Mantener el panel de controles centrado y con separaciones estables
            int anchoInterior = this->groupBox1->ClientSize.Width;
            int xCampo = Math::Max(150, anchoInterior / 3);
            int anchoCampo = Math::Max(110, anchoInterior / 4);
            int anchoBoton = Math::Max(95, anchoInterior / 5);

            this->comboBox1->Location = System::Drawing::Point(xCampo, 40);
            this->comboBox1->Width = anchoCampo;
            this->button1->Location =
                System::Drawing::Point(
                    anchoInterior - anchoBoton - 18,
                    38
                );
            this->button1->Size =
                System::Drawing::Size(anchoBoton, 32);

            this->button2->Location =
                System::Drawing::Point(
                    anchoInterior - anchoBoton - 18,
                    102
                );
            this->button2->Size =
                System::Drawing::Size(anchoBoton, 32);

            this->comboBox2->Location = System::Drawing::Point(xCampo, 178);
            this->comboBox2->Width = anchoCampo;
            this->comboBox3->Location = System::Drawing::Point(xCampo, 212);
            this->comboBox3->Width = anchoCampo;

            this->button3->Location =
                System::Drawing::Point(xCampo, 248);
            this->button3->Size =
                System::Drawing::Size(
                    Math::Max(130, anchoCampo + 20),
                    34
                );

            this->textBox4->Location =
                System::Drawing::Point(xCampo, 314);
            this->textBox4->Width = Math::Max(90, anchoCampo - 30);

            this->button5->Location =
                System::Drawing::Point(
                    anchoInterior - anchoBoton - 18,
                    310
                );
            this->button5->Size =
                System::Drawing::Size(anchoBoton, 34);

            this->button4->Location =
                System::Drawing::Point(xCampo, 356);
            this->button4->Size =
                System::Drawing::Size(
                    Math::Max(130, anchoCampo + 20),
                    34
                );

            this->button6->Location =
                System::Drawing::Point(
                    anchoInterior - anchoBoton - 18,
                    356
                );
            this->button6->Size =
                System::Drawing::Size(anchoBoton, 34);

            int anchoLinea =
                Math::Max(120, (anchoInterior - xCampo - 50) / 2);

            this->textBox2->Location =
                System::Drawing::Point(xCampo, 426);
            this->textBox2->Width = anchoLinea;

            this->textBox3->Location =
                System::Drawing::Point(
                    xCampo + anchoLinea + 14,
                    426
                );
            this->textBox3->Width = anchoLinea;

            this->button8->Location =
                System::Drawing::Point(xCampo, 466);
            this->button8->Size =
                System::Drawing::Size(110, 34);

            this->button7->Location =
                System::Drawing::Point(
                    anchoInterior - anchoBoton - 18,
                    512
                );
            this->button7->Size =
                System::Drawing::Size(anchoBoton, 34);
        }

        System::Void frmPruebasESP32_Resize(
            System::Object^ sender,
            System::EventArgs^ e
        ) {
            AjustarDistribucion();
        }

        System::Void frmPruebasESP32_Load(System::Object^ sender, System::EventArgs^ e) {
            puerto = nullptr;

            // Llenar puerto COM
            comboBox1->Items->Clear();
            array<String^>^ puertos = SerialPort::GetPortNames();
            for each(String ^ p in puertos)
                comboBox1->Items->Add(p);
            int idx = comboBox1->Items->IndexOf("COM8");
            comboBox1->SelectedIndex = (idx >= 0) ? idx : (comboBox1->Items->Count > 0 ? 0 : -1);

            // Llenar compartimentos
            comboBox2->Items->Clear();
            comboBox2->Items->Add("1");
            comboBox2->Items->Add("2");
            comboBox2->Items->Add("3");
            comboBox2->Items->Add("4");
            comboBox2->SelectedIndex = 0;

            // Llenar tipo de dispensado
            comboBox3->Items->Clear();
            comboBox3->Items->Add("NORMAL");
            comboBox3->Items->Add("ALARMA");
            comboBox3->Items->Add("LED");
            comboBox3->SelectedIndex = 0;

            // Timer
            timerSerial->Interval = 100;

            Log("Listo. Selecciona el puerto y presiona Conectar.");
            AjustarDistribucion();
            this->BeginInvoke(
                gcnew MethodInvoker(
                    this,
                    &frmPruebasESP32::AjustarDistribucion
                )
            );
        }

        // ══════════════════════════════════════════════════
        //  TIMER — leer respuestas del ESP32
        // ══════════════════════════════════════════════════


        System::Void timerSerial_Tick(System::Object^ sender, System::EventArgs^ e) {
            if (puerto == nullptr || !puerto->IsOpen) return;
            try {
                while (puerto->BytesToRead > 0) {
                    String^ linea = puerto->ReadLine();
                    if (linea == nullptr) continue;
                    linea = linea->Trim();
                    if (String::IsNullOrEmpty(linea)) continue;

                    Log("<<< " + linea);

                    // Respuestas especiales
                    if (linea == "READY") {
                        Log("=== ESP32 listo ===");
                    }
                    else if (linea == "PONG") {
                        Log("=== Conexion OK ===");
                    }
                    else if (linea->StartsWith("OK:REGISTRADO:")) {
                        String^ id = linea->Substring(14);
                        Log("=== Huella registrada con ID: " + id + " ===");
                    }
                    else if (linea->StartsWith("OK:")) {
                        Log("=== " + linea->Substring(3) + " ===");
                    }
                    else if (linea->StartsWith("ERR:")) {
                        Log("!!! ERROR: " + linea->Substring(4));
                    }
                    else if (linea->StartsWith("REG:")) {
                        Log("--- " + linea->Substring(4));
                    }
                    else if (linea->StartsWith("INFO:")) {
                        Log("--- " + linea->Substring(5));
                    }
                    // Huella leida — llega solo el int
                    else {
                        int id;
                        if (int::TryParse(linea, id)) {
                            if (id == -1)
                                Log("!!! Huella NO registrada");
                            else
                                Log("=== Huella reconocida — ID: " + id + " ===");
                        }
                    }
                }
            }
            catch (TimeoutException^) {}
            catch (...) {}
        }


        System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
            // Si ya esta conectado → desconectar
            if (puerto != nullptr && puerto->IsOpen) {
                timerSerial->Stop();
                puerto->Close();
                button1->Text = L"Conectar";
                button1->BackColor = System::Drawing::Color::Empty;
                Log("Desconectado.");
                return;
            }

            // Si no hay puerto seleccionado
            if (comboBox1->SelectedItem == nullptr) {
                MessageBox::Show("Selecciona un puerto COM.");
                return;
            }

            // Conectar
            try {
                puerto = gcnew SerialPort(comboBox1->SelectedItem->ToString(), 115200);
                puerto->ReadTimeout = 200;
                puerto->WriteTimeout = 200;
                puerto->Open();
                timerSerial->Start();
                button1->Text = L"Desconectar";
                button1->BackColor = System::Drawing::Color::LightGreen;
                Log("Conectado a " + comboBox1->SelectedItem->ToString());
            }
            catch (Exception^ ex) {
                MessageBox::Show("Error al conectar: " + ex->Message);
            }
        }
        System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
            Enviar("PING");
        }
        System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
            if (comboBox2->SelectedItem == nullptr) {
                Log("ERROR: selecciona un compartimento.");
                return;
            }
            if (comboBox3->SelectedItem == nullptr) {
                Log("ERROR: selecciona el tipo de dispensado.");
                return;
            }

            String^ comp = comboBox2->SelectedItem->ToString();
            String^ tipo = comboBox3->SelectedItem->ToString();
            Enviar("DISP:" + comp + ":" + tipo);
        }
        System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
            //leer huella
            Enviar("LEER");
        }
        System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
            //registrar huella
            String^ texto = textBox4->Text->Trim();
            if (String::IsNullOrEmpty(texto)) {
                Log("ERROR: escribe el ID de huella (1-127).");
                return;
            }

            int id;
            if (!int::TryParse(texto, id) || id < 1 || id > 127) {
                Log("ERROR: ID invalido, debe ser un numero entre 1 y 127.");
                return;
            }

            Enviar("REGISTRAR:" + id);
        }
        System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
            //cancelar
            Enviar("CANCELAR");
        }
        System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
            //status
            Enviar("STATUS");
        }
        System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) {
            //enviar texto LCD
            String^ linea1 = textBox2->Text->Trim();
            String^ linea2 = textBox3->Text->Trim();

            if (String::IsNullOrEmpty(linea1) && String::IsNullOrEmpty(linea2)) {
                Log("ERROR: escribe algo para mostrar en el LCD.");
                return;
            }

            // Si solo hay linea1, enviar sin el separador |
            if (String::IsNullOrEmpty(linea2))
                Enviar("LCD:" + linea1);
            else
                Enviar("LCD:" + linea1 + "|" + linea2);
        }
        // ══════════════════════════════════════════════════
        //  CERRAR FORMULARIO
        // ══════════════════════════════════════════════════

    protected:
        virtual void OnFormClosing(
            System::Windows::Forms::FormClosingEventArgs^ e) override {
            if (timerSerial != nullptr) timerSerial->Stop();
            if (puerto != nullptr && puerto->IsOpen) puerto->Close();
            Form::OnFormClosing(e);
        }
    };
}