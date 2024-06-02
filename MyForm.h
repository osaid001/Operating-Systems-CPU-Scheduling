#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include "FCFS.h"
#include "SJFnp.h"
#include <msclr/marshal_cppstd.h>
#include "DeadlockManager.h"
#include "RR.h"
#include "MyForm1.h"
#include "SJFp.h"
#include "priorityPRE.h"
#include "priorityNP.h"
#include "multiLVL.h"
#include <list>



using namespace std;
using namespace msclr::interop;
namespace osproj 
{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::Label^ label1;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::ComboBox^ comboBox2;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Button^ button2;
	private: int proc;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: int total_rec;
	public: int count = 1;
	private: int* arivaltimes;
	private: int* bursttimes;
	private: string* recources;
	private: string* needed;
	private: int* priorities;
	private: int rr;
	private: int q1,q2;

	private: int* completion_times;
	private: int* turnaround_times;
	private: int* waiting_times;
	private: int* response_Times;
	private: int* process_ids;

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(12, 262);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(474, 55);
			this->label1->TabIndex = 1;
			this->label1->Text = L"number of processes";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(378, 262);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(466, 55);
			this->label2->TabIndex = 3;
			this->label2->Text = L"number of recources";
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox2->Location = System::Drawing::Point(614, 259);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(70, 62);
			this->textBox2->TabIndex = 4;
			this->textBox2->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox2_KeyDown);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.125F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(22, 763);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(228, 76);
			this->button1->TabIndex = 5;
			this->button1->Text = L"Add process data";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(12, 324);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(272, 55);
			this->label3->TabIndex = 6;
			this->label3->Text = L"PROCESS:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(75, 406);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(275, 55);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Arival Time:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(75, 492);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(268, 55);
			this->label5->TabIndex = 8;
			this->label5->Text = L"Burst Time:";
			// 
			// textBox3
			// 
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox3->Location = System::Drawing::Point(85, 442);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(135, 62);
			this->textBox3->TabIndex = 9;
			this->textBox3->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox3_KeyDown);
			// 
			// textBox4
			// 
			this->textBox4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox4->Location = System::Drawing::Point(85, 534);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(135, 62);
			this->textBox4->TabIndex = 10;
			this->textBox4->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox4_KeyDown);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(75, 579);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(432, 55);
			this->label6->TabIndex = 11;
			this->label6->Text = L"Allocate recources:";
			// 
			// textBox5
			// 
			this->textBox5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox5->Location = System::Drawing::Point(85, 621);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(135, 62);
			this->textBox5->TabIndex = 12;
			this->textBox5->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox5_KeyDown);
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(249, 259);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(70, 62);
			this->textBox1->TabIndex = 13;
			this->textBox1->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox1_KeyDown);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(86, 362);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(233, 55);
			this->label7->TabIndex = 14;
			this->label7->Text = L"process 1";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(721, 262);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(397, 55);
			this->label8->TabIndex = 15;
			this->label8->Text = L"Sellect Scheduler";
			// 
			// comboBox1
			// 
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(7) {
				L"First Come First Serve", L"Shorthes Job First (premeptive)",
					L"Priority Sceduling (premeptive)", L"Shorthes Job First (non-premeptive)", L"Priority Sceduling (non-premeptive)", L"Round Robin",
					L"Multilevel Sceduling"
			});
			this->comboBox1->Location = System::Drawing::Point(940, 262);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(285, 45);
			this->comboBox1->TabIndex = 16;
			this->comboBox1->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::comboBox1_KeyDown);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->Location = System::Drawing::Point(721, 406);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(341, 55);
			this->label9->TabIndex = 17;
			this->label9->Text = L"Sellect Priority:";
			// 
			// comboBox2
			// 
			this->comboBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(10) {
				L"1", L"2", L"3", L"4", L"5", L"6", L"7", L"8",
					L"9", L"10"
			});
			this->comboBox2->Location = System::Drawing::Point(721, 442);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(181, 45);
			this->comboBox2->TabIndex = 18;
			this->comboBox2->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::comboBox2_KeyDown);
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->Location = System::Drawing::Point(721, 372);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(233, 55);
			this->label10->TabIndex = 19;
			this->label10->Text = L"process 1";
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(520, 686);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(249, 95);
			this->button2->TabIndex = 20;
			this->button2->Text = L"RUN";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->Location = System::Drawing::Point(75, 670);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(432, 55);
			this->label11->TabIndex = 21;
			this->label11->Text = L"Needed recources:";
			// 
			// textBox6
			// 
			this->textBox6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox6->Location = System::Drawing::Point(85, 705);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(135, 62);
			this->textBox6->TabIndex = 22;
			this->textBox6->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox6_KeyDown);
			// 
			// MyForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->ClientSize = System::Drawing::Size(1777, 1176);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->DoubleBuffered = true;
			this->Name = L"MyForm";
			this->Text = L"CPU Scheduler";
			this->ResumeLayout(false);
			this->PerformLayout();

			this->label3->Hide();
			this->label7->Hide();
			this->label4->Hide();
			this->textBox3->Hide();
			this->label5->Hide();
			this->textBox4->Hide();
			this->label6->Hide();
			this->textBox5->Hide();
			this->button1->Hide();
			this->label10->Hide();
			this->label9->Hide();
			this->comboBox2->Hide();
			this->label11->Hide();
			this->textBox6->Hide();

			this->button2->Hide();
		}

#pragma endregion
		private: System::Void textBox1_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
		{
			if (e->KeyValue == (int)Keys::Enter && System::Convert::ToInt16(textBox1->Text) > 0 && textBox1->Text != "")
			{
				proc = Convert::ToInt16(textBox1->Text);
				arivaltimes = new int[proc];
				bursttimes = new int[proc];
				recources = new string[proc];
				needed = new string[proc];
				textBox2->Focus();
			}
		}

		private: System::Void textBox2_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
		{
			if (e->KeyValue == (int)Keys::Enter && System::Convert::ToInt16(textBox2->Text) > 0 && textBox2->Text != "")
			{
				total_rec = System::Convert::ToInt16(textBox2->Text);

				label3->Show();
				label7->Show();
				label4->Show();
				textBox3->Show();
				label5->Show();
				textBox4->Show();
				label6->Show();
				textBox5->Show();
				button1->Show();
				label11->Show();
				textBox6->Show();
				textBox3->Focus();
			}
		}

		private: System::Void textBox3_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
		{
			if (e->KeyValue == (int)Keys::Enter && textBox3->Text != "")
			{
				textBox4->Focus();
			}
		}

		private: System::Void textBox4_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
		{
			if (e->KeyValue == (int)Keys::Enter && System::Convert::ToInt16(textBox4->Text) > 0 && textBox4->Text != "")
			{
				textBox5->Focus();
			}
		}

		private: System::Void textBox5_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) 
		{
			if (e->KeyValue == (int)Keys::Enter && textBox5->Text != "")
			{
				textBox6->Focus();
			}
		}

	private: System::Void textBox6_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
	{
		if (e->KeyValue == (int)Keys::Enter && textBox6->Text != "")
		{
			if (count < proc)
			{
				count++;
				arivaltimes[count - 2] = System::Convert::ToInt16(textBox3->Text);
				bursttimes[count - 2] = System::Convert::ToInt16(textBox4->Text);
				System::String^ managedString = textBox5->Text;
				string s = marshal_as<string>(managedString);
				recources[count - 2] = s;

				System::String^ managedString1 = textBox6->Text;
				string s1 = marshal_as<string>(managedString1);
				needed[count - 2] = s1;

				this->label7->Text = "process " + count;
				textBox3->Text = "";
				textBox4->Text = "";
				textBox5->Text = "";
				textBox6->Text = "";
				textBox3->Focus();

			}
			else
			{
				arivaltimes[count - 1] = System::Convert::ToInt16(textBox3->Text);
				bursttimes[count - 1] = System::Convert::ToInt16(textBox4->Text);
				System::String^ managedString = textBox5->Text;
				string s = marshal_as<string>(managedString);
				recources[count - 1] = s;

				System::String^ managedString1 = textBox6->Text;
				string s1 = marshal_as<string>(managedString1);
				needed[count - 1] = s1;

				textBox3->Text = "";
				textBox4->Text = "";
				textBox5->Text = "";
				textBox6->Text = "";
				comboBox1->Focus();
				label3->Hide();
				label7->Hide();
				label4->Hide();
				textBox3->Hide();
				label5->Hide();
				textBox4->Hide();
				label6->Hide();
				textBox5->Hide();
				textBox6->Hide();
				label11->Hide();
				button1->Hide();
				count = 1;
			}
		}
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (count < proc)
		{
			count++;

			arivaltimes[count - 2] = System::Convert::ToInt16(textBox3->Text);
			bursttimes[count - 2] = System::Convert::ToInt16(textBox4->Text);
			System::String^ managedString = textBox5->Text;
			string s = marshal_as<string>(managedString);
			recources[count - 2] = s;

			System::String^ managedString1 = textBox6->Text;
			string s1 = marshal_as<string>(managedString1);
			needed[count - 2] = s1;

			this->label7->Text = "process " + count;
			textBox3->Text = "";
			textBox4->Text = "";
			textBox5->Text = "";
			textBox6->Text = "";

			textBox3->Focus();

		}
		else
		{
			arivaltimes[count - 1] = System::Convert::ToInt16(textBox3->Text);
			bursttimes[count - 1] = System::Convert::ToInt16(textBox4->Text);
			System::String^ managedString = textBox5->Text;
			string s = marshal_as<string>(managedString);
			recources[count - 1] = s;

			System::String^ managedString1 = textBox6->Text;
			string s1 = marshal_as<string>(managedString1);
			needed[count - 1] = s1;

			textBox3->Text = "";
			textBox4->Text = "";
			textBox5->Text = "";
			textBox6->Text = "";

			comboBox1->Focus();
			label3->Hide();
			label7->Hide();
			label4->Hide();
			textBox3->Hide();
			label5->Hide();
			textBox4->Hide();
			label6->Hide();
			textBox5->Hide();
			button1->Hide();
			textBox6->Hide();
			label11->Hide();
			count = 1;
		}
	
	}
private: System::Void comboBox1_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
{
	if (e->KeyValue == (int)Keys::Enter)
	{
		if (System::Convert::ToString(comboBox1->Text) == "First Come First Serve")
		{
			button2->Show();
		}
		else if (System::Convert::ToString(comboBox1->Text) == "Shorthes Job First (premeptive)")
		{
			button2->Show();
		}
		else if (System::Convert::ToString(comboBox1->Text) == "Priority Sceduling (premeptive)")
		{
			priorities = new int[proc];
			this->label10->Show();
			this->label9->Show();
			this->comboBox2->Show();
			this->comboBox2->Focus();
		}
		else if (System::Convert::ToString(comboBox1->Text) == "Shorthes Job First (non-premeptive)")
		{
			button2->Show();
		}
		else if (System::Convert::ToString(comboBox1->Text) == "Priority Sceduling (non-premeptive)")
		{
			priorities = new int[proc];
			this->label10->Show();
			this->label9->Show();
			this->comboBox2->Show();
			this->comboBox2->Focus();

		}
		else if (System::Convert::ToString(comboBox1->Text) == "Round Robin")
		{
			this->label9->Show();
			this->label9->Text = "Sellect quantum:";
			this->comboBox2->Show();
			this->comboBox2->Focus();

		}
		else if (System::Convert::ToString(comboBox1->Text) == "Multilevel Sceduling")
		{
			this->label9->Show();
			this->label10->Show();
			this->comboBox2->Show();
			this->label9->Text = "Sellect quantum:";
			label10->Text = "Queue 1:";
			this->comboBox2->Focus();

		}
		else 
		{
			MessageBox::Show("no valid algorithm!","error!",MessageBoxButtons::OK,MessageBoxIcon::Error);
		}
	}
}
private: System::Void comboBox2_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) 
{
	if (e->KeyValue == (int)Keys::Enter && System::Convert::ToInt16(comboBox2->Text) > 0 && System::Convert::ToInt16(comboBox2->Text) < 11)
	{
		if (System::Convert::ToString(comboBox1->Text) == "Priority Sceduling (premeptive)")
		{
			if (count < proc)
			{
				priorities[count - 1] = System::Convert::ToInt16(comboBox2->Text);
				comboBox2->Text = "";
				comboBox2->Focus();
				count++;
				label10->Text = "process "+ count;
			}
			else
			{
				priorities[count-1] = System::Convert::ToInt16(comboBox2->Text);
				comboBox2->Text = "";

				this->label9->Hide();
				this->comboBox2->Hide();
				this->label10->Hide();
				count = 1;
				button2->Show();
			}
		}
		else if (System::Convert::ToString(comboBox1->Text) == "Priority Sceduling (non-premeptive)")
		{
			if (count < proc)
			{
				priorities[count-1] = System::Convert::ToInt16(comboBox2->Text);
				comboBox2->Text = "";
				comboBox2->Focus();
				count++;
				label10->Text = "process " + count;
			}
			else
			{
				priorities[count-1] = System::Convert::ToInt16(comboBox2->Text);
				comboBox2->Text = "";

				this->label9->Hide();
				this->comboBox2->Hide();
				this->label10->Hide();
				count = 1;
				button2->Show();
			}
		}
		else if (System::Convert::ToString(comboBox1->Text) == "Round Robin")
		{
			rr = System::Convert::ToInt16(comboBox2->Text);

			comboBox2->Text = "";
			this->label9->Hide();
			this->comboBox2->Hide();
			this->label10->Hide();
			button2->Show();

		}
		else if (System::Convert::ToString(comboBox1->Text) == "Multilevel Sceduling")
		{
			if (count == 1)
			{
				q1 = System::Convert::ToInt16(comboBox2->Text);
				this->comboBox2->Text = "";
				this->comboBox2->Focus();
				count++;
				label10->Text = "Queue 2:";
			}
			else if (count == 2)
			{
				q2 = System::Convert::ToInt16(comboBox2->Text);
				comboBox2->Text = "";
				this->comboBox2->Hide();
				this->label10->Hide();
				this->label9->Hide();
				count = 1;
				button2->Show();
			}
		}
		else
		{
			MessageBox::Show("no valid algorithm!", "error!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) 
{
	if (System::Convert::ToString(comboBox1->Text) == "First Come First Serve")
	{
		scheduler obj;

		for (int i = 0; i < proc; ++i) 
		{
			int p, a, b;
			p = i + 1;
			a = arivaltimes[i];
			b = bursttimes[i];

			obj.addProcess(p, a, b);
		}

		obj.calcCompletionTime();
		obj.calcTurnAroundAndWaitingTime();

		completion_times = new int[proc];
		turnaround_times = new int[proc];
		waiting_times = new int[proc];
		process_ids = new int[proc];
		response_Times = new int[proc];

		obj.getProcessIdsInCompletionOrder(process_ids);

		DeadlockManager ddchk;

		if (ddchk.checkrepetitions(total_rec, proc, recources))
		{
			MessageBox::Show("more than 1 processes are allocated same recource!", "Warning!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
		if (!ddchk.checkrange(total_rec, proc, recources, needed))
		{
			MessageBox::Show("allocated or needed recources not valid!", "Warning!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
		if (ddchk.chkdeadlock(total_rec, proc, process_ids, recources, needed))
		{
			MessageBox::Show("DeadLock!!!", "error!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		if (!ddchk.chkdeadlock(total_rec, proc, process_ids, recources, needed))
		{
			obj.getCompletionTimes(completion_times);
			obj.getTurnAroundTimes(turnaround_times);
			obj.getWaitingTimes(waiting_times);
			obj.getWaitingTimes(response_Times);

			int total_time = 0;
			int* runningTimeline = obj.getProcessRunningTimeline(total_time);

			osproj::MyForm1^ form1 = gcnew osproj::MyForm1();

			string sss = "First Come First Serve";
			form1->PopulateTable(process_ids, arivaltimes, bursttimes, completion_times, turnaround_times, waiting_times, response_Times, priorities, proc, sss);
			form1->ShowGrandChart(total_time, runningTimeline, sss, runningTimeline, runningTimeline);
			form1->ShowDialog();
		}
	}
	else if (System::Convert::ToString(comboBox1->Text) == "Shorthes Job First (premeptive)")
	{
		SchedulerSJF obj(proc);

		for (int i = 0; i < proc; ++i)
		{
			string pid;
			int arrival, burst;
			pid = to_string(i + 1);
			arrival = arivaltimes[i];
			burst = bursttimes[i];

			obj.addProcess(i, pid, arrival, burst);
		}

		obj.schedule();

		completion_times = new int[proc];
		turnaround_times = new int[proc];
		waiting_times = new int[proc];
		process_ids = new int[proc];
		response_Times = new int[proc];

		string* processIds = new string[proc];

		obj.getProcessOrder(processIds);

		for (int i = 0; i < proc; ++i)
		{
			process_ids[i] = stoi(processIds[i]);
		}
		delete[] processIds;

		DeadlockManager ddchk;

		if (ddchk.checkrepetitions(total_rec, proc, recources))
		{
			MessageBox::Show("more than 1 processes are allocated same recource!", "Warning!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
		if (!ddchk.checkrange(total_rec, proc, recources, needed))
		{
			MessageBox::Show("allocated or needed recources not valid!", "Warning!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
		if (ddchk.chkdeadlock(total_rec, proc, process_ids, recources, needed))
		{
			MessageBox::Show("DeadLock!!!", "error!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		if (!ddchk.chkdeadlock(total_rec, proc, process_ids, recources, needed))
		{
			obj.getCompletionTimes(completion_times);
			obj.getTurnAroundTimes(turnaround_times);
			obj.getWaitingTimes(waiting_times);
			obj.getResponseTimes(response_Times);

			int total_time = 0;
			int* runningTimeline = obj.recordProcessExecution(total_time);

			osproj::MyForm1^ form1 = gcnew osproj::MyForm1();

			string sss = "Shorthes Job First (premeptive)";
			form1->PopulateTable(process_ids, arivaltimes, bursttimes, completion_times, turnaround_times, waiting_times, response_Times, priorities, proc, sss);
			form1->ShowGrandChart(total_time, runningTimeline, sss, runningTimeline, runningTimeline);

			form1->ShowDialog();
		}
	}
	else if (System::Convert::ToString(comboBox1->Text) == "Priority Sceduling (premeptive)")
	{

		SchedulerPriority objp(proc);

		for (int i = 0; i < proc; ++i)
		{
			int id = i + 1;
			int arrival, burst, priority;
			arrival = arivaltimes[i];
			burst = bursttimes[i];
			priority = priorities[i];
			objp.addProcess(i, id, arrival, burst, priority);
		}

		objp.schedulePreemptive();

		completion_times = new int[proc];
		turnaround_times = new int[proc];
		waiting_times = new int[proc];
		process_ids = new int[proc];
		response_Times = new int[proc];

		objp.getProcessOrder(process_ids);

		DeadlockManager ddchk;

		if (ddchk.checkrepetitions(total_rec, proc, recources))
		{
			MessageBox::Show("more than 1 processes are allocated same recource!", "Warning!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
		if (!ddchk.checkrange(total_rec, proc, recources, needed))
		{
			MessageBox::Show("allocated or needed recources not valid!", "Warning!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
		if (ddchk.chkdeadlock(total_rec, proc, process_ids, recources, needed))
		{
			MessageBox::Show("DeadLock!!!", "error!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		if (!ddchk.chkdeadlock(total_rec, proc, process_ids, recources, needed))
		{
			objp.getCompletionTimes(completion_times);
			objp.getTurnaroundTimes(turnaround_times);
			objp.getWaitingTimes(waiting_times);
			objp.getResponseTimes(response_Times);

			int total_time = 0;
			int* executionTimeline = objp.recordProcessExecution(total_time);

			osproj::MyForm1^ form1 = gcnew osproj::MyForm1();

			string sss = "Priority Sceduling (premeptive)";
			form1->PopulateTable(process_ids, arivaltimes, bursttimes, completion_times, turnaround_times, waiting_times, response_Times, priorities, proc, sss);
			form1->ShowGrandChart(total_time, executionTimeline, sss, executionTimeline, executionTimeline);

			form1->ShowDialog();
		}
	}
	else if (System::Convert::ToString(comboBox1->Text) == "Shorthes Job First (non-premeptive)")
	{
		SchedulerSJF obj(proc);

		for (int i = 0; i < proc; ++i) 
		{
			string pid;
			int arrival, burst;
			pid = to_string(i+1);
			arrival = arivaltimes[i];
			burst = bursttimes[i];

			obj.addProcess(i, pid, arrival, burst);
		}

		obj.schedule();

		completion_times = new int[proc];
		turnaround_times = new int[proc];
		waiting_times = new int[proc];
		process_ids = new int[proc];
		response_Times = new int[proc];

		string* processIds = new string[proc];

		obj.getProcessOrder(processIds);

		for (int i = 0; i < proc; ++i)
		{
			process_ids[i] = stoi(processIds[i]);
		}
		delete[] processIds;

		DeadlockManager ddchk;

		if (ddchk.checkrepetitions(total_rec, proc, recources))
		{
			MessageBox::Show("more than 1 processes are allocated same recource!", "Warning!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
		if (!ddchk.checkrange(total_rec, proc, recources, needed))
		{
			MessageBox::Show("allocated or needed recources not valid!", "Warning!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
		if (ddchk.chkdeadlock(total_rec, proc, process_ids, recources, needed))
		{
			MessageBox::Show("DeadLock!!!", "error!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		if (!ddchk.chkdeadlock(total_rec, proc, process_ids, recources, needed))
		{
			obj.getCompletionTimes(completion_times);
			obj.getTurnAroundTimes(turnaround_times);
			obj.getWaitingTimes(waiting_times);
			obj.getResponseTimes(response_Times);
			
			int total_time = 0;
			int* runningTimeline = obj.recordProcessExecution(total_time);

			osproj::MyForm1^ form1 = gcnew osproj::MyForm1();

			string sss = "Shorthes Job First (non-premeptive)";
			form1->PopulateTable(process_ids, arivaltimes, bursttimes, completion_times, turnaround_times, waiting_times, response_Times, priorities, proc, sss);
			form1->ShowGrandChart(total_time, runningTimeline, sss, runningTimeline, runningTimeline);

			form1->ShowDialog();
		}

	}
	else if (System::Convert::ToString(comboBox1->Text) == "Priority Sceduling (non-premeptive)")
	{
		SchedulerPriorityNP obj(proc);

		for (int i = 0; i < proc; ++i) 
		{
			int id = i + 1;
			int arrival, burst, priority;
			arrival = arivaltimes[i];
			burst = bursttimes[i];
			priority = priorities[i];
			obj.addProcess(i, id, arrival, burst, priority);
		}

		obj.scheduleNonPreemptive();

		completion_times = new int[proc];
		turnaround_times = new int[proc];
		waiting_times = new int[proc];
		process_ids = new int[proc];
		response_Times = new int[proc];

		obj.getProcessOrder(process_ids);

		DeadlockManager ddchk;

		if (ddchk.checkrepetitions(total_rec, proc, recources))
		{
			MessageBox::Show("more than 1 processes are allocated same recource!", "Warning!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
		if (!ddchk.checkrange(total_rec, proc, recources, needed))
		{
			MessageBox::Show("allocated or needed recources not valid!", "Warning!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
		if (ddchk.chkdeadlock(total_rec, proc, process_ids, recources, needed))
		{
			MessageBox::Show("DeadLock!!!", "error!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		if (!ddchk.chkdeadlock(total_rec, proc, process_ids, recources, needed))
		{
			obj.getCompletionTimes(completion_times);
			obj.getTurnaroundTimes(turnaround_times);
			obj.getWaitingTimes(waiting_times);
			obj.getResponseTimes(response_Times);
			int total_time = 0;
			int* runningTimeline = obj.getganttChart(total_time);
			osproj::MyForm1^ form1 = gcnew osproj::MyForm1();

			string sss = "Priority Sceduling (non-premeptive)";
			form1->PopulateTable(process_ids, arivaltimes, bursttimes, completion_times, turnaround_times, waiting_times, response_Times, priorities, proc, sss);
			form1->ShowGrandChart(total_time, runningTimeline, sss, runningTimeline, runningTimeline);

			form1->ShowDialog();

		}
	}
	else if (System::Convert::ToString(comboBox1->Text) == "Round Robin")
	{
		SchedulerRR obj(proc, rr);

		for (int i = 0; i < proc; ++i) 
		{
			string pid;
			int arrival, burst;

			pid = to_string(i + 1);
			arrival = arivaltimes[i];
			burst = bursttimes[i];

			obj.addProcess(i, pid, arrival, burst);
		}

		obj.schedule();

		completion_times = new int[proc];
		turnaround_times = new int[proc];
		waiting_times = new int[proc];
		process_ids = new int[proc];
		response_Times = new int[proc];

		string* processIds = new string[proc];

		obj.getProcessOrder(processIds);

		for (int i = 0; i < proc; ++i)
		{
			process_ids[i] = stoi(processIds[i]);
		}
		delete[] processIds;

		DeadlockManager ddchk;

		if (ddchk.checkrepetitions(total_rec, proc, recources))
		{
			MessageBox::Show("more than 1 processes are allocated same recource!", "Warning!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
		if (!ddchk.checkrange(total_rec, proc, recources, needed))
		{
			MessageBox::Show("allocated or needed recources not valid!", "Warning!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
		if (ddchk.chkdeadlock(total_rec, proc, process_ids, recources, needed))
		{
			MessageBox::Show("DeadLock!!!", "error!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		if (!ddchk.chkdeadlock(total_rec, proc, process_ids, recources, needed))
		{
			obj.getCompletionTimes(completion_times);
			obj.getTurnAroundTimes(turnaround_times);
			obj.getWaitingTimes(waiting_times);
			obj.getResponseTimes(response_Times);

			int total_time = 0;
			int* runningTimeline = obj.recordProcessExecution(total_time);

			osproj::MyForm1^ form1 = gcnew osproj::MyForm1();

			string sss = "Round Robin";
			form1->PopulateTable(process_ids, arivaltimes, bursttimes, completion_times, turnaround_times, waiting_times, response_Times, priorities, proc, sss);
			form1->ShowGrandChart(total_time, runningTimeline, sss, runningTimeline, runningTimeline);

			form1->ShowDialog();
		}
	}
	else if (System::Convert::ToString(comboBox1->Text) == "Multilevel Sceduling")
	{
		process* processes = new process[proc];
		process* processestemp = new process[proc];

		list<process*> qu1, qu2, qu3, temp_q1, temp_q2, temp_q3;

		for (int i = 0; i < proc; ++i)
		{
			int arrival, burst;
			arrival = arivaltimes[i];
			burst = bursttimes[i];
			addProcess(processes, qu1, i + 1, arrival, burst);
			addProcess(processestemp, temp_q1, i + 1, arrival, burst);
		}

		int currentTime = 0;

		qrun(qu1, q1, currentTime, qu2);
		currentTime = q1;
		qrun(qu2, q2, currentTime, qu3);
		currentTime = q2;
		executeFCFS(qu3, currentTime);

		calculateTimes(processes, proc);

		completion_times = new int[proc];
		turnaround_times = new int[proc];
		waiting_times = new int[proc];
		process_ids = new int[proc];
		response_Times = new int[proc];


		getProcessOrder(processes, proc, process_ids);

		DeadlockManager ddchk;

		if (ddchk.checkrepetitions(total_rec, proc, recources))
		{
			MessageBox::Show("more than 1 processes are allocated same recource!", "Warning!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
		if (!ddchk.checkrange(total_rec, proc, recources, needed))
		{
			MessageBox::Show("allocated or needed recources not valid!", "Warning!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
		if (ddchk.chkdeadlock(total_rec, proc, process_ids, recources, needed))
		{
			MessageBox::Show("DeadLock!!!", "error!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		if (!ddchk.chkdeadlock(total_rec, proc, process_ids, recources, needed))
		{
			getCompletionTimes(processes, proc, completion_times);
			getTurnaroundTimes(processes, proc, turnaround_times);
			getWaitingTimes(processes, proc, waiting_times);
			getResponseTimes(processes, proc, response_Times);

			int timeOFtimeline = getTotalTime(processes, proc);

			int* timeline_q1 = recordProcessExecutionQueue(0, q1, timeOFtimeline, temp_q1, temp_q2);
			int* timeline_q2 = recordProcessExecutionQueue(q1, q2, timeOFtimeline, temp_q2, temp_q3);
			int* timeline_q3 = recordProcessExecutionQueue3(q2, timeOFtimeline, temp_q3);

			osproj::MyForm1^ form1 = gcnew osproj::MyForm1();
			string sss = "Multilevel Sceduling";
			form1->PopulateTable(process_ids, arivaltimes, bursttimes, completion_times, turnaround_times, waiting_times, response_Times, priorities, proc, sss);
			form1->ShowGrandChart(timeOFtimeline, timeline_q1, sss, timeline_q2, timeline_q3);
			form1->ShowDialog();
		}
	}
	else
	{
		MessageBox::Show("no valid algorithm!", "error!", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}
};
}
