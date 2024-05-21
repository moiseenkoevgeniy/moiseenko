	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			int number = Int32::Parse(textBox1->Text);

			if (number < 100 || number > 999) {
				MessageBox::Show("Please enter a three-digit number.", "Input Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}

			int hundreds = number / 100;
			int tens = (number / 10) % 10;
			int units = number % 10;

			int newNumber = tens * 100 + hundreds * 10 + units;

			textBox5->Text = newNumber.ToString();
		}
		catch (FormatException^ ex) {
			MessageBox::Show("Please enter a valid numeric value.", "Input Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		catch (Exception^ ex) {
			MessageBox::Show("An error occurred: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog();
		openFileDialog1->Filter = "Text Files (*.txt)|*.txt|All Files (*.*)|*.*";
		openFileDialog1->Title = "Select a Text File";
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			String^ filename = openFileDialog1->FileName;
			StreamReader^ reader = gcnew StreamReader(filename);
			textBox1->Text = reader->ReadLine();
			reader->Close();
		}
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		SaveFileDialog^ saveFileDialog1 = gcnew SaveFileDialog();
		saveFileDialog1->Filter = "Text Files (*.txt)|*.txt|All Files (*.*)|*.*";
		saveFileDialog1->Title = "Save Result to a Text File";

		if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			String^ resultFilename = saveFileDialog1->FileName;
			StreamWriter^ writer = gcnew StreamWriter(resultFilename);
			writer->WriteLine(textBox5->Text);
			writer->Close();
		}
	}
