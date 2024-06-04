#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>
#include <ctime>
#include <sstream>  
#include <fstream>
#include <TlHelp32.h>
#include <minwinbase.h>
#pragma once
using namespace std;
namespace LR6Server {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Threading;
	using namespace System::Diagnostics;
	/// <summary>
	/// Сводка для Server
	/// </summary>
	public ref class Server : public System::Windows::Forms::Form
	{
	public:
		Server(void)
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
		~Server()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox1;

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	

	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Server::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::LightSteelBlue;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(54, 102);
			this->label1->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(807, 73);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Введите кол-во клиентов:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(54, 206);
			this->label2->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(0, 73);
			this->label2->TabIndex = 1;
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::LightSteelBlue;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(1086, 102);
			this->textBox1->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(617, 73);
			this->textBox1->TabIndex = 2;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::LightSteelBlue;
			this->button1->Location = System::Drawing::Point(215, 782);
			this->button1->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(413, 138);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Начать работу";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Server::button1_Click);
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::Color::NavajoWhite;
			this->textBox2->Location = System::Drawing::Point(135, 224);
			this->textBox2->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->textBox2->MaximumSize = System::Drawing::Size(1510, 504);
			this->textBox2->MaxLength = 1510;
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBox2->Size = System::Drawing::Size(1510, 504);
			this->textBox2->TabIndex = 5;
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::LightSlateGray;
			this->button2->Enabled = false;
			this->button2->Location = System::Drawing::Point(1267, 782);
			this->button2->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(436, 138);
			this->button2->TabIndex = 6;
			this->button2->Text = L"Close";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Visible = false;
			this->button2->Click += gcnew System::EventHandler(this, &Server::button2_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(0, 0);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 1;
			// 
			// richTextBox1
			// 
			/*this->richTextBox1->Location = System::Drawing::Point(0, 0);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(100, 96);
			this->richTextBox1->TabIndex = 0;
			this->richTextBox1->Text = L"";
			*/
			// 
			// Server
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(14, 26);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(1932, 998);
			//this->Controls->Add(this->richTextBox1);
			//this->Controls->Add(this->button4);
			//this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Location = System::Drawing::Point(12, 307);
			this->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->Name = L"Server";
			this->Text = L"Server";
			this->ResumeLayout(false);
			this->PerformLayout();

		}


#pragma endregion
		int N;
		StreamReader^ file;
		String^ filen = "";

	public: delegate System::Void logs(String^ t);
	public: System::Void LogOut(String^ t) {
		if (textBox2->InvokeRequired) {
			Invoke(lr, t);
		}
		else {
			textBox2->Text += t;
			System::IO::File::AppendAllText("log.txt", textBox2->Text + "\r\n");
			textBox2->SelectionStart = textBox2->TextLength; textBox2->ScrollToCaret();
		}
	}
		  logs^ lr = gcnew logs(this, &Server::LogOut);

		  bool Protect() {
			  if (textBox1->Text->Length == 0) { return false; }
			  for (int i = 0; i < textBox1->Text->Length; i++) {
				  if ((textBox1->Text[i] >= '0') && (textBox1->Text[i] <= '9')) {}
				  else return false;
			  }
			  return true;
		  }
	private: System::Void Start()
	{
		STARTUPINFO sc;
		PROCESS_INFORMATION pi;
		ZeroMemory(&sc, sizeof(sc));
		ZeroMemory(&pi, sizeof(pi));
		HANDLE glad[2] = {
		CreateEvent(NULL,FALSE,FALSE,L"S"),
		CreateEvent(NULL,FALSE,FALSE,L"T"),
		};
		HANDLE win[3] = {
		CreateEvent(NULL,FALSE,FALSE,L"+"),
		CreateEvent(NULL,FALSE,FALSE,L"-"),
		CreateEvent(NULL,FALSE,FALSE,L"N"),
		};
		int sampoints = 0;
		int thrpoints = 0;
		vector<int> samnits;
		vector<int> thracians;
		LogOut("Да начнутся гладиаторские поединки\r\n");
		vector<int> res(N);

		for (int i = 0; i < N; i++) {
			ZeroMemory(&sc, sizeof(sc));
			ZeroMemory(&pi, sizeof(pi));
			HANDLE hEvent = CreateEvent(NULL, FALSE, FALSE, L"Event");
			LogOut("Подключился " + (i + 1) + " гладиатор\r\n");
			CreateProcess(L"C:\\Users\Mi\source\repos\LR6_Client\x64\Debug\LR6_Client.exe", NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &sc, &pi);

			int ind = WaitForMultipleObjects(2, glad, FALSE, INFINITE);
			if (ind == 0)
			{
				samnits.push_back(i);
				if (samnits.size() != 0 && thracians.size() != 0) {
					srand(time(0));
					int winner = rand() % 100;
					if (winner < 50) {
						res[samnits[0]] = 0;
						res[thracians[0]] = 1;
						++sampoints;
						samnits.erase(samnits.begin());
						thracians.erase(thracians.begin());
						LogOut("Самнит победил фрайкийца\r\n");
						LogOut("Счет: Самниты " + sampoints + " Фракийцы " + thrpoints + "\r\n");
					}
					else {
						res[samnits[0]] = 1;
						res[thracians[0]] = 0;
						++thrpoints;
						samnits.erase(samnits.begin());
						thracians.erase(thracians.begin());
						LogOut("Фракийец победил самнита\r\n");
						LogOut("Счет: Самниты " + sampoints + " Фракийцы " + thrpoints + "\r\n");
					}
					LogOut(winner + "\r\n");
				}
			}
			else
			{
				thracians.push_back(i);
				if (samnits.size() != 0 && thracians.size() != 0) {
					srand(time(0));
					int winner = rand() % 100;
					if (winner < 50) {
						res[samnits[0]] = 0;
						res[thracians[0]] = 1;
						++sampoints;
						samnits.erase(samnits.begin());
						thracians.erase(thracians.begin());
						LogOut("Самнит победил фрайкийца\r\n");
						LogOut("Счет: Самниты " + sampoints + " Фракийцы " + thrpoints + "\r\n");
					}
					else {
						res[thracians[0]] = 0;
						res[samnits[0]] = 1;
						++thrpoints;
						samnits.erase(samnits.begin());
						thracians.erase(thracians.begin());
						LogOut("Фракийец победил самнита\r\n");
						LogOut("Счет: Самниты " + sampoints + " Фракийцы " + thrpoints + "\r\n");
					}
					LogOut(winner + "\r\n");
				}
			}
		}
		while (samnits.size() != 0) {
			res[samnits[0]] = 2;
			LogOut("Гладиатор " + (samnits[0] + 1) + " не учавствовал в битве\r\n");
			samnits.erase(samnits.begin());
		}
		while (thracians.size() != 0) {
			res[thracians[0]] = 2;
			LogOut("Гладиатор " + (thracians[0] + 1) + " не учавствовал в битве\r\n");
			thracians.erase(thracians.begin());
		}

		for (int i = 0; i < res.size(); i++)
		{
			Sleep(500);
			if (res[i] == 0)
				SetEvent(win[0]);
			else if (res[i] == 1)
				SetEvent(win[1]);
			else
				SetEvent(win[2]);
		}
		if (sampoints > thrpoints) {
			LogOut("Победили самниты\r\n");
		}
		else if (thrpoints > sampoints) {
			LogOut("Победили фракийцы\r\n");
		}
		else if (sampoints == 0 && thrpoints == 0) {
			LogOut("Сражений не было все участники одного типа\r\n");
		}
		else {
			LogOut("Ничья\r\n");
		}
		LogOut("Ave, Caesar!\r\n");
		for (int i = 0; i < 2; i++)
		{
			CloseHandle(glad[i]);
		}
		for (int i = 0; i < 3; i++)
		{
			CloseHandle(win[i]);
		}

	};

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (Protect()) {
			N = System::Convert::ToInt32(textBox1->Text);
			if ((N < 2) || (N > 50)) {
				MessageBox::Show("Неверное кол-во клиентов. Введите число от 2 до 50.", "Ошибка");
			}
			Thread^ th = gcnew Thread(gcnew ThreadStart(this, &Server::Start));
			th->Start();
			button1->Visible = false;
			button1->Enabled = false;
			button2->Visible = true;
			button2->Enabled = true;
		}
		else MessageBox::Show("Ошибка ввода.", "Ошибка");
	}

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		abort();
		Close();
	}
/*private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ file_text = read_FILE("C:\\Users\\Mi\\source\\repos\\LR6_Server\\LR6_Server\\log.txt");

	this->richTextBox1->Text = file_text;
}
	   String^ read_FILE(String^ file_path) {
		   try {
			   StreamReader^ reader = gcnew StreamReader(file_path);

			   String^ file_content = reader->ReadToEnd();
			   reader->Close();
			   return file_content;
		   }
		   catch (Exception^ ex) {
			   MessageBox::Show("Ошибка при чтении файла: " + ex->Message);
			   return "";
		   }
	   }*/
};
}