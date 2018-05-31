#pragma once
#include "filereader.h"
#include "parametry.h"
#include "calculation.h"
#include "ftp.h"
#include "draw.h"
#include "filereaderGPS.h"
#include "parametryGPS.h"
#include "calcgps.h"
#include "geometrfactor.h"


namespace Sputniki {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			

			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::TextBox^  textBox6;
	private: System::Windows::Forms::TextBox^  textBox7;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::TextBox^  textBox8;
	private: System::Windows::Forms::TextBox^  textBox9;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::TextBox^  textBox10;
	private: System::Windows::Forms::TextBox^  textBox11;
	private: System::Windows::Forms::TextBox^  textBox12;
	private: System::Windows::Forms::TextBox^  textBox13;
	private: System::Windows::Forms::TextBox^  textBox14;
	private: System::Windows::Forms::TextBox^  textBox15;
	private: System::Windows::Forms::TextBox^  textBox16;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column4;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::TextBox^  textBox17;
	private: System::Windows::Forms::TextBox^  textBox18;
	private: System::Windows::Forms::TextBox^  textBox19;
	private: System::Windows::Forms::TextBox^  textBox20;
	private: System::Windows::Forms::TextBox^  textBox21;
	private: System::Windows::Forms::TextBox^  textBox22;
	private: System::Windows::Forms::TextBox^  textBox23;
	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::Label^  label17;
	private: System::Windows::Forms::Label^  label18;
	private: System::Windows::Forms::Label^  label19;
	private: System::Windows::Forms::Label^  label20;
	private: System::Windows::Forms::TextBox^  textBox24;
	private: System::Windows::Forms::TextBox^  textBox25;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::DataGridView^  dataGridView2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn4;
	private: System::Windows::Forms::Label^  label21;
	private: System::Windows::Forms::Label^  label22;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column6;
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			this->textBox11 = (gcnew System::Windows::Forms::TextBox());
			this->textBox12 = (gcnew System::Windows::Forms::TextBox());
			this->textBox13 = (gcnew System::Windows::Forms::TextBox());
			this->textBox14 = (gcnew System::Windows::Forms::TextBox());
			this->textBox15 = (gcnew System::Windows::Forms::TextBox());
			this->textBox16 = (gcnew System::Windows::Forms::TextBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->textBox17 = (gcnew System::Windows::Forms::TextBox());
			this->textBox18 = (gcnew System::Windows::Forms::TextBox());
			this->textBox19 = (gcnew System::Windows::Forms::TextBox());
			this->textBox20 = (gcnew System::Windows::Forms::TextBox());
			this->textBox21 = (gcnew System::Windows::Forms::TextBox());
			this->textBox22 = (gcnew System::Windows::Forms::TextBox());
			this->textBox23 = (gcnew System::Windows::Forms::TextBox());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->textBox24 = (gcnew System::Windows::Forms::TextBox());
			this->textBox25 = (gcnew System::Windows::Forms::TextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->label22 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			this->SuspendLayout();
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(104, 224);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 0;
			this->button2->Text = L"Считать";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click_1);
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(111, 61);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(68, 22);
			this->textBox8->TabIndex = 1;
			this->textBox8->Text = L"7";
			// 
			// textBox9
			// 
			this->textBox9->Location = System::Drawing::Point(271, 61);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(55, 22);
			this->textBox9->TabIndex = 2;
			this->textBox9->Text = L"0";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(24, 61);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(81, 17);
			this->label7->TabIndex = 3;
			this->label7->Text = L"Часы(UTC)";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(201, 61);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(59, 17);
			this->label8->TabIndex = 4;
			this->label8->Text = L"Минуты";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(40, 101);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(58, 17);
			this->label9->TabIndex = 5;
			this->label9->Text = L"Широта";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(37, 143);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(63, 17);
			this->label10->TabIndex = 6;
			this->label10->Text = L"Долгота";
			this->label10->Click += gcnew System::EventHandler(this, &MyForm::label10_Click);
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(37, 186);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(57, 17);
			this->label11->TabIndex = 7;
			this->label11->Text = L"Высота";
			// 
			// textBox10
			// 
			this->textBox10->Location = System::Drawing::Point(104, 96);
			this->textBox10->Name = L"textBox10";
			this->textBox10->Size = System::Drawing::Size(68, 22);
			this->textBox10->TabIndex = 8;
			this->textBox10->Text = L"55";
			// 
			// textBox11
			// 
			this->textBox11->Location = System::Drawing::Point(188, 96);
			this->textBox11->Name = L"textBox11";
			this->textBox11->Size = System::Drawing::Size(72, 22);
			this->textBox11->TabIndex = 9;
			this->textBox11->Text = L"45";
			// 
			// textBox12
			// 
			this->textBox12->Location = System::Drawing::Point(281, 96);
			this->textBox12->Name = L"textBox12";
			this->textBox12->Size = System::Drawing::Size(76, 22);
			this->textBox12->TabIndex = 10;
			this->textBox12->Text = L"07";
			// 
			// textBox13
			// 
			this->textBox13->Location = System::Drawing::Point(104, 140);
			this->textBox13->Name = L"textBox13";
			this->textBox13->Size = System::Drawing::Size(68, 22);
			this->textBox13->TabIndex = 11;
			this->textBox13->Text = L"37";
			// 
			// textBox14
			// 
			this->textBox14->Location = System::Drawing::Point(188, 138);
			this->textBox14->Name = L"textBox14";
			this->textBox14->Size = System::Drawing::Size(72, 22);
			this->textBox14->TabIndex = 12;
			this->textBox14->Text = L"36";
			// 
			// textBox15
			// 
			this->textBox15->Location = System::Drawing::Point(281, 138);
			this->textBox15->Name = L"textBox15";
			this->textBox15->Size = System::Drawing::Size(76, 22);
			this->textBox15->TabIndex = 13;
			this->textBox15->Text = L"56";
			// 
			// textBox16
			// 
			this->textBox16->Location = System::Drawing::Point(104, 181);
			this->textBox16->Name = L"textBox16";
			this->textBox16->Size = System::Drawing::Size(100, 22);
			this->textBox16->TabIndex = 14;
			this->textBox16->Text = L"0";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(47, 269);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(184, 17);
			this->label12->TabIndex = 15;
			this->label12->Text = L"Кол-во видимых спутников";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(237, 269);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(0, 17);
			this->label13->TabIndex = 16;
			this->label13->Click += gcnew System::EventHandler(this, &MyForm::label13_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->Column1,
					this->Column2, this->Column3, this->Column4, this->Column5
			});
			this->dataGridView1->Location = System::Drawing::Point(37, 298);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(538, 341);
			this->dataGridView1->TabIndex = 17;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellContentClick);
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"№";
			this->Column1->Name = L"Column1";
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"X";
			this->Column2->Name = L"Column2";
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Y";
			this->Column3->Name = L"Column3";
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Z";
			this->Column4->Name = L"Column4";
			// 
			// Column5
			// 
			this->Column5->HeaderText = L"Радиус орбиты";
			this->Column5->Name = L"Column5";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(37, 9);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(231, 17);
			this->label14->TabIndex = 18;
			this->label14->Text = L"Координаты спутников ГЛОНАСС";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(701, 9);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(194, 17);
			this->label15->TabIndex = 19;
			this->label15->Text = L"Координаты спутников GPS";
			// 
			// textBox17
			// 
			this->textBox17->Location = System::Drawing::Point(665, 178);
			this->textBox17->Name = L"textBox17";
			this->textBox17->Size = System::Drawing::Size(100, 22);
			this->textBox17->TabIndex = 34;
			this->textBox17->Text = L"0";
			// 
			// textBox18
			// 
			this->textBox18->Location = System::Drawing::Point(842, 135);
			this->textBox18->Name = L"textBox18";
			this->textBox18->Size = System::Drawing::Size(76, 22);
			this->textBox18->TabIndex = 33;
			this->textBox18->Text = L"56";
			// 
			// textBox19
			// 
			this->textBox19->Location = System::Drawing::Point(749, 135);
			this->textBox19->Name = L"textBox19";
			this->textBox19->Size = System::Drawing::Size(72, 22);
			this->textBox19->TabIndex = 32;
			this->textBox19->Text = L"36";
			// 
			// textBox20
			// 
			this->textBox20->Location = System::Drawing::Point(665, 137);
			this->textBox20->Name = L"textBox20";
			this->textBox20->Size = System::Drawing::Size(68, 22);
			this->textBox20->TabIndex = 31;
			this->textBox20->Text = L"37";
			// 
			// textBox21
			// 
			this->textBox21->Location = System::Drawing::Point(842, 93);
			this->textBox21->Name = L"textBox21";
			this->textBox21->Size = System::Drawing::Size(76, 22);
			this->textBox21->TabIndex = 30;
			this->textBox21->Text = L"07";
			// 
			// textBox22
			// 
			this->textBox22->Location = System::Drawing::Point(749, 93);
			this->textBox22->Name = L"textBox22";
			this->textBox22->Size = System::Drawing::Size(72, 22);
			this->textBox22->TabIndex = 29;
			this->textBox22->Text = L"45";
			// 
			// textBox23
			// 
			this->textBox23->Location = System::Drawing::Point(665, 93);
			this->textBox23->Name = L"textBox23";
			this->textBox23->Size = System::Drawing::Size(68, 22);
			this->textBox23->TabIndex = 28;
			this->textBox23->Text = L"55";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(598, 183);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(57, 17);
			this->label16->TabIndex = 27;
			this->label16->Text = L"Высота";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(598, 140);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(63, 17);
			this->label17->TabIndex = 26;
			this->label17->Text = L"Долгота";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(601, 98);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(58, 17);
			this->label18->TabIndex = 25;
			this->label18->Text = L"Широта";
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(762, 58);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(59, 17);
			this->label19->TabIndex = 24;
			this->label19->Text = L"Минуты";
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(585, 58);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(81, 17);
			this->label20->TabIndex = 23;
			this->label20->Text = L"Часы(UTC)";
			// 
			// textBox24
			// 
			this->textBox24->Location = System::Drawing::Point(832, 58);
			this->textBox24->Name = L"textBox24";
			this->textBox24->Size = System::Drawing::Size(55, 22);
			this->textBox24->TabIndex = 22;
			this->textBox24->Text = L"0";
			// 
			// textBox25
			// 
			this->textBox25->Location = System::Drawing::Point(672, 58);
			this->textBox25->Name = L"textBox25";
			this->textBox25->Size = System::Drawing::Size(68, 22);
			this->textBox25->TabIndex = 21;
			this->textBox25->Text = L"7";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(665, 221);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 20;
			this->button3->Text = L"Считать";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// dataGridView2
			// 
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->dataGridViewTextBoxColumn1,
					this->dataGridViewTextBoxColumn2, this->dataGridViewTextBoxColumn3, this->dataGridViewTextBoxColumn4, this->Column6
			});
			this->dataGridView2->Location = System::Drawing::Point(601, 298);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->RowTemplate->Height = 24;
			this->dataGridView2->Size = System::Drawing::Size(550, 325);
			this->dataGridView2->TabIndex = 37;
			// 
			// dataGridViewTextBoxColumn1
			// 
			this->dataGridViewTextBoxColumn1->HeaderText = L"№";
			this->dataGridViewTextBoxColumn1->Name = L"dataGridViewTextBoxColumn1";
			// 
			// dataGridViewTextBoxColumn2
			// 
			this->dataGridViewTextBoxColumn2->HeaderText = L"X";
			this->dataGridViewTextBoxColumn2->Name = L"dataGridViewTextBoxColumn2";
			// 
			// dataGridViewTextBoxColumn3
			// 
			this->dataGridViewTextBoxColumn3->HeaderText = L"Y";
			this->dataGridViewTextBoxColumn3->Name = L"dataGridViewTextBoxColumn3";
			// 
			// dataGridViewTextBoxColumn4
			// 
			this->dataGridViewTextBoxColumn4->HeaderText = L"Z";
			this->dataGridViewTextBoxColumn4->Name = L"dataGridViewTextBoxColumn4";
			// 
			// Column6
			// 
			this->Column6->HeaderText = L"Радиус орбиты";
			this->Column6->Name = L"Column6";
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Location = System::Drawing::Point(808, 269);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(0, 17);
			this->label21->TabIndex = 36;
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Location = System::Drawing::Point(618, 269);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(184, 17);
			this->label22->TabIndex = 35;
			this->label22->Text = L"Кол-во видимых спутников";
			// 
			// MyForm
			// 
			this->ClientSize = System::Drawing::Size(1174, 635);
			this->Controls->Add(this->dataGridView2);
			this->Controls->Add(this->label21);
			this->Controls->Add(this->label22);
			this->Controls->Add(this->textBox17);
			this->Controls->Add(this->textBox18);
			this->Controls->Add(this->textBox19);
			this->Controls->Add(this->textBox20);
			this->Controls->Add(this->textBox21);
			this->Controls->Add(this->textBox22);
			this->Controls->Add(this->textBox23);
			this->Controls->Add(this->label16);
			this->Controls->Add(this->label17);
			this->Controls->Add(this->label18);
			this->Controls->Add(this->label19);
			this->Controls->Add(this->label20);
			this->Controls->Add(this->textBox24);
			this->Controls->Add(this->textBox25);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->textBox16);
			this->Controls->Add(this->textBox15);
			this->Controls->Add(this->textBox14);
			this->Controls->Add(this->textBox13);
			this->Controls->Add(this->textBox12);
			this->Controls->Add(this->textBox11);
			this->Controls->Add(this->textBox10);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->textBox9);
			this->Controls->Add(this->textBox8);
			this->Controls->Add(this->button2);
			this->Name = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
			 //ГЛОНАСС
	private: System::Void button2_Click_1(System::Object^  sender, System::EventArgs^  e) 
	{
		dataGridView1->Rows->Clear();
		double B, L, H;
		int hours, minute, kolvovidimyh;
		hours = Convert::ToInt32(textBox8->Text);
		minute = Convert::ToInt32(textBox9->Text);
		string name;
		ftp ftp("GLONASS");
		ftp.publicDecompress();
		parametry::MarshalString(ftp.getFileName(), name);
		vector<Parametry> sattelits;
		vector<Parametry> vidimye;
		sattelits = filereader::readfile(name);
		calculation calc;

		sattelits = calc.SatteliteHM(hours, minute, sattelits);
		B = calc.GradtoRad(Convert::ToDouble(textBox10->Text) + (Convert::ToDouble(textBox11->Text) / 60) + (Convert::ToDouble(textBox12->Text) / 3600));
		L = calc.GradtoRad(Convert::ToDouble(textBox13->Text) + (Convert::ToDouble(textBox14->Text) / 60) + (Convert::ToDouble(textBox15->Text) / 3600));
		H = Convert::ToDouble(textBox16->Text);
		kolvovidimyh = calc.calcNumberSattelites(B, L, H, sattelits, vidimye);
		label13->Text = Convert::ToString(kolvovidimyh);

		for (int i = 0;i <kolvovidimyh;i++)
		{
			dataGridView1->Rows->Add(Convert::ToString(vidimye[i].number), Convert::ToString(vidimye[i].X), Convert::ToString(vidimye[i].Y), Convert::ToString(vidimye[i].Z), Convert::ToString(calculation::rCalc(vidimye[i].X, vidimye[i].Y, vidimye[i].Z)-6356));
		}

		filereader::copyFile("template.stl", "result.stl");
		draw::generateCoord("result.stl", vidimye, kolvovidimyh);
		Geometrfactor geo(vidimye[0].X , vidimye[0].Y , vidimye[0].Z, B,L);
	}
			 //GPS
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e)
	{
		dataGridView2->Rows->Clear();
		double B, L, H;
		int hours, minute, kolvovidimyh;
		hours = Convert::ToInt32(textBox25->Text);
		minute = Convert::ToInt32(textBox24->Text);
		string name;
		ftp ftp("GPS");
		ftp.publicDecompress();
		parametry::MarshalString(ftp.getFileName(), name);
		vector<ParametryGPS> sattelits;
		vector<ParametryGPS> vidimye;
		sattelits = filereaderGPS::readfile(name);
		calcgps calc;

		sattelits = calc.satteliteT(hours, minute, sattelits);
		B = calc.GradtoRad(Convert::ToDouble(textBox23->Text) + (Convert::ToDouble(textBox22->Text) / 60) + (Convert::ToDouble(textBox21->Text) / 3600));
		L = calc.GradtoRad(Convert::ToDouble(textBox19->Text) + (Convert::ToDouble(textBox19->Text) / 60) + (Convert::ToDouble(textBox18->Text) / 3600));
		H = Convert::ToDouble(textBox16->Text);
		kolvovidimyh = calc.calcNumberSattelites(B, L, H, sattelits, vidimye);
		label21->Text = Convert::ToString(kolvovidimyh);
		for (int i = 0; i < kolvovidimyh; i++)
		{
			dataGridView2->Rows->Add(Convert::ToString(vidimye[i].number), Convert::ToString(vidimye[i].X /1000), Convert::ToString(vidimye[i].Y /1000), Convert::ToString(vidimye[i].Z /1000), Convert::ToString(calculation::rCalc(vidimye[i].X /1000, vidimye[i].Y /1000, vidimye[i].Z /1000)-6356));
		}
		filereader::copyFile("template.stl", "resultGPS.stl");
		int ff = sattelits.size();
		draw::generateCoordGPS("resultGPS.stl", sattelits, kolvovidimyh);

	}
private: System::Void label10_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label13_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void dataGridView1_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
}
private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
}

};
}
