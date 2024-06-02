#pragma once

namespace osproj
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyForm1 : public System::Windows::Forms::Form
	{
	public:
		MyForm1(void)
		{
			InitializeComponent();
		}
	protected:
		~MyForm1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::DataGridView^ dataGridView2;
	private: System::Windows::Forms::Label^ label3;

	protected:
	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle4 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->label3 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AllowUserToResizeColumns = false;
			this->dataGridView1->AllowUserToResizeRows = false;
			this->dataGridView1->BackgroundColor = System::Drawing::Color::White;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.875F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.875F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView1->DefaultCellStyle = dataGridViewCellStyle2;
			this->dataGridView1->EnableHeadersVisualStyles = false;
			this->dataGridView1->Location = System::Drawing::Point(118, 233);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->RowHeadersWidth = 82;
			this->dataGridView1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridView1->Size = System::Drawing::Size(704, 166);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm1::dataGridView1_CellContentClick);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(388, 558);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(163, 71);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Okay";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm1::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(120, 193);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(163, 51);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Output:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 22.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(12, 24);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(187, 67);
			this->label2->TabIndex = 3;
			this->label2->Text = L"label2";
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->AutoSize = true;
			this->tableLayoutPanel1->ColumnCount = 1;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 1;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(980, 0);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// dataGridView2
			// 
			this->dataGridView2->AllowUserToAddRows = false;
			this->dataGridView2->AllowUserToDeleteRows = false;
			this->dataGridView2->AllowUserToResizeColumns = false;
			this->dataGridView2->AllowUserToResizeRows = false;
			this->dataGridView2->BackgroundColor = System::Drawing::Color::White;
			dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle3->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.875F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle3->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle3->SelectionBackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle3->SelectionForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle3->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView2->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle3;
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			dataGridViewCellStyle4->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle4->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.875F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle4->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle4->SelectionBackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle4->SelectionForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle4->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView2->DefaultCellStyle = dataGridViewCellStyle4;
			this->dataGridView2->EnableHeadersVisualStyles = false;
			this->dataGridView2->Location = System::Drawing::Point(24, 436);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->ReadOnly = true;
			this->dataGridView2->RowHeadersVisible = false;
			this->dataGridView2->RowHeadersWidth = 82;
			this->dataGridView2->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridView2->Size = System::Drawing::Size(944, 99);
			this->dataGridView2->TabIndex = 4;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(28, 402);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(255, 51);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Gantt Chart:";
			// 
			// MyForm1
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->ClientSize = System::Drawing::Size(980, 641);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->dataGridView2);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"MyForm1";
			this->Text = L"Output";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		public: void SetCellColor(DataGridView^ grid, int rowIndex, int columnIndex, Color color)
		{
			grid->Rows[rowIndex]->Cells[columnIndex]->Style->SelectionBackColor = color;
			if (rowIndex >= 0 && rowIndex < grid->RowCount && columnIndex >= 0 && columnIndex < grid->ColumnCount)
			{
				grid->Rows[rowIndex]->Cells[columnIndex]->Style->BackColor = color;
			}
		}

	public: void ShowGrandChart(int num, int* timeLine, string ss, int* timeLine2, int* timeLine3)
	{
		if (ss != "Multilevel Sceduling")
		{
			dataGridView2->Columns->Clear();
			dataGridView2->Rows->Clear();

			int columnWidth = 55;

			for (int i = 0; i < num; ++i)
			{
				DataGridViewColumn^ col = gcnew DataGridViewTextBoxColumn();
				col->Name = "Column" + i.ToString();
				col->HeaderText = (i).ToString() + " - " + (i + 1).ToString();
				col->Width = columnWidth;
				dataGridView2->Columns->Add(col);
			}

			dataGridView2->Rows->Add();

			for (int i = 0; i < num; ++i)
			{
				if (timeLine[i] == 0)
				{
					dataGridView2->Rows[0]->Cells[i]->Value = "";
					SetCellColor(dataGridView2, 0, i, Color::OrangeRed);
				}
				else
				{
					dataGridView2->Rows[0]->Cells[i]->Value = "P" + (timeLine[i]).ToString();
				}
			}
		}
		else if(ss == "Multilevel Sceduling")
		{

			dataGridView2->Columns->Clear();
			dataGridView2->Rows->Clear();

			int columnWidth = 55;

			for (int i = 0; i < num; ++i)
			{
				DataGridViewColumn^ col = gcnew DataGridViewTextBoxColumn();
				col->Name = "Column" + i.ToString();
				col->HeaderText = (i).ToString() + " - " + (i + 1).ToString();
				col->Width = columnWidth;
				dataGridView2->Columns->Add(col);
			}

			dataGridView2->Rows->Add();
			dataGridView2->Rows->Add();
			dataGridView2->Rows->Add();

			for (int i = 0; i < num; ++i)
			{
				if (timeLine[i] == 0)
				{
					dataGridView2->Rows[0]->Cells[i]->Value = "";
					SetCellColor(dataGridView2, 0, i, Color::OrangeRed);
				}
				else
				{
					dataGridView2->Rows[0]->Cells[i]->Value = "P" + (timeLine[i]).ToString();
				}
				if (timeLine2[i] == 0)
				{
					dataGridView2->Rows[1]->Cells[i]->Value = "";
					SetCellColor(dataGridView2, 1, i, Color::OrangeRed);
				}
				else
				{
					dataGridView2->Rows[1]->Cells[i]->Value = "P" + (timeLine2[i]).ToString();
				}
				if (timeLine3[i] == 0)
				{
					dataGridView2->Rows[2]->Cells[i]->Value = "";
					SetCellColor(dataGridView2, 2, i, Color::OrangeRed);
				}
				else
				{
					dataGridView2->Rows[2]->Cells[i]->Value = "P" + (timeLine3[i]).ToString();
				}
			}

		}
		dataGridView1->ClearSelection();
	}

	public: void PopulateTable(int* process_ids, int* arival_times, int* burst_times, int* completion_times, int* turnaround_times,
		int* waiting_times, int* response_times, int* priorities, int proc, string sss)
	{
		if (sss == "Priority Sceduling (non-premeptive)" || sss == "Priority Sceduling (premeptive)")
		{
			dataGridView1->Columns->Add("ProcessID", "Process No");
			dataGridView1->Columns->Add("ArrivalTime", "Arrival Time");
			dataGridView1->Columns->Add("BurstTime", "Burst Time");
			dataGridView1->Columns->Add("priorities", "Priorities");
			dataGridView1->Columns->Add("CompletionTime", "Completion Time");
			dataGridView1->Columns->Add("TurnaroundTime", "Turnaround Time");
			dataGridView1->Columns->Add("WaitingTime", "Waiting Time");
			dataGridView1->Columns->Add("ResponseTime", "Response Time");

			for (int i = 0; i < proc; ++i)
			{
				int x = i + 1;
				dataGridView1->Rows->Add(
					x,
					arival_times[i],
					burst_times[i],
					priorities[i],
					completion_times[i],
					turnaround_times[i],
					waiting_times[i],
					response_times[i]
				);
			}
		}
		else
		{
			dataGridView1->Columns->Add("ProcessID", "Process No");
			dataGridView1->Columns->Add("ArrivalTime", "Arrival Time");
			dataGridView1->Columns->Add("BurstTime", "Burst Time");
			dataGridView1->Columns->Add("CompletionTime", "Completion Time");
			dataGridView1->Columns->Add("TurnaroundTime", "Turnaround Time");
			dataGridView1->Columns->Add("WaitingTime", "Waiting Time");
			dataGridView1->Columns->Add("ResponseTime", "Response Time");


			for (int i = 0; i < proc; ++i)
			{
				int x = i + 1;
				dataGridView1->Rows->Add(
					x,
					arival_times[i],
					burst_times[i],
					completion_times[i],
					turnaround_times[i],
					waiting_times[i],
					response_times[i]
				);
			}
		}

		if (sss == "Round Robin")
		{
			label2->Text = "Round Robin";
		}
		else if (sss == "Multilevel Sceduling")
		{
			label2->Text = "Multilevel Sceduling";
		}
		else if (sss == "Priority Sceduling (non-premeptive)")
		{
			label2->Text = "Priority Sceduling (non-premeptive)";
		}
		else if (sss == "Shorthes Job First (non-premeptive)")
		{
			label2->Text = "Shorthes Job First (non-premeptive)";
		}
		else if (sss == "Priority Sceduling (premeptive)")
		{
			label2->Text = "Priority Sceduling (premeptive)";
		}
		else if (sss == "Shorthes Job First (premeptive)")
		{
			label2->Text = "Shorthes Job First (premeptive)";
		}
		else if (sss == "First Come First Serve")
		{
			label2->Text = "First Come First Serve";
		}

		dataGridView1->ClearSelection();
	}

#pragma endregion
	private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->Close();
	}
	};
}
