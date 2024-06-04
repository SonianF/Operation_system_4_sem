#pragma once
#include "C:\Users\Mi\source\repos\LR6_Server\LR6_Server\Server.h"
#include <string>
#include <Windows.h>

namespace LR6Client {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;

	/// <summary>
	/// Сводка для Client
	/// </summary>
	public ref class Client : public System::Windows::Forms::Form
	{
	public:
		Client(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}
		Client(LR6Server::Server^ serv) {

			InitializeComponent();
			server = serv;
			Thread^ thread = gcnew Thread(gcnew ThreadStart(this, &Client::creation));
			thread->Start();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Client()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::RadioButton^ radioButton1;
	private: System::Windows::Forms::RadioButton^ radioButton2;



	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Client::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::LightSteelBlue;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(317, 410);
			this->label1->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(502, 48);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Введите тип гладиатора:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::LightSteelBlue;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(1237, 301);
			this->label2->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(309, 44);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Клиент запущен";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::LightSteelBlue;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(884, 511);
			this->button1->Margin = System::Windows::Forms::Padding(6);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(396, 57);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Подтвердить тип гладиатора";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Client::button1_Click);
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::Color::LightSteelBlue;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox2->Location = System::Drawing::Point(1073, 368);
			this->textBox2->Margin = System::Windows::Forms::Padding(6);
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->Size = System::Drawing::Size(644, 50);
			this->textBox2->TabIndex = 4;
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::LightSteelBlue;
			this->button2->Enabled = false;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(1780, 352);
			this->button2->Margin = System::Windows::Forms::Padding(6);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(178, 62);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Close";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Visible = false;
			this->button2->Click += gcnew System::EventHandler(this, &Client::button2_Click);
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->BackColor = System::Drawing::Color::LightSteelBlue;
			this->radioButton1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->radioButton1->Location = System::Drawing::Point(471, 599);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(238, 55);
			this->radioButton1->TabIndex = 6;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Самниты";
			this->radioButton1->UseVisualStyleBackColor = false;
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->BackColor = System::Drawing::Color::LightSteelBlue;
			this->radioButton2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->radioButton2->Location = System::Drawing::Point(1392, 599);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(264, 55);
			this->radioButton2->TabIndex = 7;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"Фракийцы";
			this->radioButton2->UseVisualStyleBackColor = false;
			// 
			// Client
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(2116, 1399);
			this->Controls->Add(this->radioButton2);
			this->Controls->Add(this->radioButton1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Margin = System::Windows::Forms::Padding(6);
			this->MaximumSize = System::Drawing::Size(2142, 1470);
			this->MinimumSize = System::Drawing::Size(2142, 1470);
			this->Name = L"Client";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Client";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		LR6Server::Server^ server;
		int index;
	public: delegate System::Void log(String^ t);
	public: System::Void LogOutClient(String^ t) {
		if (textBox2->InvokeRequired) {
			Invoke(lr, t);
		}
		else {
			textBox2->Text += t;
			textBox2->SelectionStart = textBox2->TextLength;
		}
	}
		  log^ lr = gcnew log(this, &Client::LogOutClient);

	private: System::Void creation() {
		HANDLE hEvent = OpenEvent(EVENT_ALL_ACCESS, TRUE, L"Event");
	};
	private: System::Void work() {
		HANDLE glad[2] = {
	OpenEvent(EVENT_ALL_ACCESS,FALSE,L"S"),
	OpenEvent(EVENT_ALL_ACCESS,FALSE,L"T"),
		};
		HANDLE win[3] = {
	OpenEvent(EVENT_ALL_ACCESS,FALSE, L"+"),
	OpenEvent(EVENT_ALL_ACCESS,FALSE, L"-"),
	OpenEvent(EVENT_ALL_ACCESS,FALSE, L"N"),
		};
		if (radioButton1->Checked) {
			SetEvent(glad[0]);
		}
		else{
			SetEvent(glad[1]);
		}

		int ind = WaitForMultipleObjects(3, win, FALSE, 30000);

		if (ind == 0)
			LogOutClient("Поздравляю, ты победил!");
		else if (ind == 1)
			LogOutClient("К сожалению, ты проиграл((");
		else if (ind == 2)
			LogOutClient("Ты не учавствовал в битве(");
		else
		{
			MessageBox::Show("Сервер отключен.", "Ошибка");
		}

	};

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
			Thread^ th = gcnew Thread(gcnew ThreadStart(this, &Client::work));
			th->Start();
			button1->Visible = false;
			button1->Enabled = false;
			button2->Visible = true;
			button2->Enabled = true;
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		Close();
	}
};
}