#pragma once
#pragma warning(disable : 4996) 

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include <cmath>
#include <cstdlib>
using namespace std;

const string gFileName = "Clients.txt";

namespace lib {

	enum enCharType { CapitalLetter = 1, SmallLetter = 2, SpecialCharacter = 3, Digit = 4 };

	struct stClient
	{
		string AccountNumber;
		string PinCode;
		string FullName;
		string PhoneNumber;
		double BalanceAmount;
		bool MarkedForDelete = false;
	};

	struct stDate
	{
		short Day;
		short Month;
		short Year;
	};

	void ReadFileData(string filename, string filePath) {
		fstream MyFile;
		string name;  bool again = true;
		MyFile.open(filename, ios::out | ios::app);
		if (MyFile.is_open())
		{
			MyFile << name << endl;
			while (again)
			{
				cout << "Whats your name? ";
				cin >> name;
				MyFile << name << endl;
				cout << "do u want to add anouther name?  ";
				cin >> again;
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					again = true;
				}
				else if (name == "clr")
				{
					MyFile.close();
					MyFile.open(filePath, ios::out);
				}
			}
			MyFile.close();
		}
	}

	void PrintFileData(string filename) {
		fstream MyFile;
		MyFile.open(filename, ios::in);
		string line;
		while (getline(MyFile, line))
		{
			cout << line << endl;
		}
		MyFile.close();
	}

	void LoadFileToVector(string filename, vector<string>& vFileContents) {
		fstream file;
		file.open(filename, ios::in);
		string line;
		while (getline(file, line))
		{
			vFileContents.push_back(line);
		}
		file.close();
	}

	void SaveFileFromVector(string filename, vector<string>& vFileContents) {
		fstream file;
		file.open(filename, ios::out);
		for (string& line : vFileContents)
		{
			if (line != "") {
				file << line << endl;
			}
		}
		file.close();
	}

	void RemoveRecordFromVector(string filename, vector<string>& vFileContents, string Record) {
		fstream file;
		file.open(filename, ios::out);
		for (string& Line : vFileContents)
		{
			if (Line == Record)
				Line = "";
		}
		file.close();
	}

	void EditRecordFromVector(string filename, vector<string>& vFileContents, string Record, string UpdateTo) {
		fstream file;
		file.open(filename, ios::out);
		for (string& Line : vFileContents)
		{
			if (Line == Record)
				Line = UpdateTo;
		}
		file.close();
	}

	int ReadPositiveNumbers(string Message) {
		int Number = 0;
		do {
			cout << Message;
			cin >> Number;
		} while (Number < 0);
		return Number;
	}

	void Swap(int& x, int& y) {
		int temp = x;
		x = y;
		y = temp;
	}

	void Swap(string& x, string& y) {
		string temp = x;
		x = y;
		y = temp;
	}

	void FillArrWith1ToN(int N, int Array[10000]) {
		for (int i = 0; i < N; i++)
			Array[i] = i + 1;
	}

	void ReadArr(int& ArraySize, int Array[10000]) {
		ArraySize = ReadPositiveNumbers("Input The Size Of the Array: ");
		for (int i = 0; i < ArraySize; i++)
		{
			cout << "Element [" << i + 1 << "]:";
			cin >> Array[i];
		}
		cout << endl;
	}

	string ReadString(string Message) {
		string text;
		cout << Message;
		getline(cin, text);
		return text;
	}

	void PrintIntArr(int ArraySize, int Array[10000]) {
		for (int i = 0; i < ArraySize; i++)
			cout << Array[i] << " ";
		cout << endl;
	}

	void PrintIntMatrix(int Matrix[100][100], int Rows, int Cols) {
		for (int i = 0; i < Rows; i++) {
			for (int j = 0; j < Cols; j++)
				printf(" %0*d   ", 2, Matrix[i][j]);
			cout << endl;
		}
		cout << endl;
	}

	void PrintStringArr(int ArraySize, string Array[10000]) {
		for (int i = 0; i < ArraySize; i++)
			cout << "Array[" << i << "]:" << Array[i] << endl;
	}

	int ArrRepeatCounter(int Array[10000], int SizeOfArray, int Original) {
		int Counter = 0;
		for (int i = 0; i < SizeOfArray; i++)
		{
			if (Array[i] == Original)
				Counter++;
		}
		return Counter;
	}

	int NumReverse(int Number) {
		int Reversed = 0;
		while (Number > 0)
		{
			int Reminder = Number % 10;
			Number /= 10;
			Reversed = Reversed * 10 + Reminder;
		}
		return Reversed;
	}

	bool IsItPalindrom(int Number) {
		return Number == NumReverse(Number);
	}

	bool IsItPrime(int Number) {
		if (Number == 1 || Number == 0)
			return false;
		for (int i = 2; i < round(Number / 2); i++)
		{
			if (Number % i == 0)
				return false;
		}
		return true;
	}

	void NumPattern(int Number) {
		for (int i = 0; i <= Number; i++)
		{
			for (int j = 0; j < i; j++)
				cout << i;
			cout << endl;
		}
	}

	void LetterPattern(int Number) {
		for (char i = 65; i <= Number + 64; i++)
		{

			for (int j = 0; j <= i - 65; j++)
				cout << i;
			cout << endl;
		}
	}

	bool WordsPattern(string password) {
		int counter = 0;
		string word = "";
		for (int x = 65; x <= 65 + 25; x++)
		{
			for (int y = 65; y <= 65 + 25; y++)
			{
				for (int z = 65; z <= 65 + 25; z++)
				{
					word = "";
					word = word + (char)x;
					word = word + (char)y;
					word = word + (char)z;
					cout << word << endl;
					counter++;
					if (word == password)
					{
						cout << "_______________________________________________________\n";
						cout << "Password is " << word << endl;
						cout << "found after " << counter << " Trail(s)";
						return true;
					}
				}
			}
		}
		return false;
	}

	string Encryption(string text, short EncryptionKey) {
		for (int i = 0; i < text.length(); i++)
			text[i] = char(int(text[i]) + EncryptionKey);
		return text;
	}

	string Decryption(string Encrypted_text, short EncryptionKey) {
		for (int i = 0; i < Encrypted_text.length(); i++)
			Encrypted_text[i] = char(int(Encrypted_text[i]) - EncryptionKey);
		return Encrypted_text;
	}

	int Random(int from, int to) {
		return(rand() % (to - from - 1) + from);
	}

	char GetRandomCharacter(enCharType CharType) {
		switch (CharType)
		{
		case SmallLetter:
			return Random(97, 122);
			break;
		case CapitalLetter:
			return Random(65, 90);
			break;
		case SpecialCharacter:
			return Random(33, 47);
			break;
		case Digit:
			return Random(48, 57);
			break;
		default:
			break;
		}
	}

	string WordGen(enCharType CharType, short Length) {
		string Word;
		for (int i = 0; i < Length; i++)
			Word = Word + GetRandomCharacter(CharType);
		return Word;
	}

	string KeyGen() {
		string Key = "";
		for (int j = 1; j <= 4; j++)
		{
			Key += WordGen(CapitalLetter, 4);
			if (j < 4)
				Key += "-";
		}
		return Key;
	}

	void KeysPrinter(short NumOfKeys) {
		for (int i = 1; i <= NumOfKeys; i++)
			cout << "Key[" << i << "] : " << KeyGen() << endl;
	}

	void RandomArr(int ArraySize, int Array[100]) {
		for (int i = 0; i < ArraySize; i++)
			Array[i] = Random(1, 100);
	}

	void RandomArr(int RowsNum, int ColumsNum, int Array[100][100]) {
		for (int i = 0; i < RowsNum; i++) {
			for (int j = 0; j < ColumsNum; j++)
				Array[i][j] = Random(1, 100);
		}
	}

	int RowSum(int RowNumber, int ColumsNumber, int Array[100][100]) {
		int sum = 0;
		for (int i = 0; i < ColumsNumber; i++)
			sum += Array[RowNumber][i];
		return sum;
	}

	void FillMatrixRowSumToArr(int RowSumArr[100], int RowsNum, int ColumsNum, int OriginalArr[100][100]) {
		for (int i = 0; i < RowsNum; i++)
		{
			RowSumArr[i] = RowSum(i, ColumsNum, OriginalArr);
		}
	}

	void PrintAllRowsSum(int RowsNum, int ColumsNum, int Array[100][100]) {
		for (int i = 0; i < RowsNum; i++)
			cout << "Row " << i + 1 << " sum = " << RowSum(i, ColumsNum, Array);
	}

	int MaxArr(int ArraySize, int Array[100]) {
		int Max = 0;
		for (int i = 0; i < ArraySize; i++)
		{
			if (Max < Array[i])
				Max = Array[i];
		}    return Max;
	}

	int MinArr(int ArraySize, int Array[100]) {
		int Min = Array[0];
		for (int i = 0; i < ArraySize; i++)
		{
			if (Min > Array[i])
				Min = Array[i];
		}
		return Min;
	}

	int SumArr(int ArraySize, int Array[100]) {
		int sum = 0;
		for (int i = 0; i < ArraySize; i++)
			sum += Array[i];
		return sum;
	}

	float AverageArr(int ArraySize, int Array[100]) {
		return float(SumArr(ArraySize, Array) / ArraySize);
	}

	void CpyArr(int ArraySize, int ArrSource[100], int ArrDestination[100]) {
		for (int i = 0; i < ArraySize; i++)
			ArrDestination[i] = ArrSource[i];
	}

	void CpyMatrix(int Rows, int Cols, int ArrSource[100][100], int ArrDestination[100][100]) {
		for (int i = 0; i < Rows; i++) {
			for (int j = 0; j < Cols; j++)
				ArrDestination[i][j] = ArrSource[i][j];
		}
	}

	void PrimeOnlyCpyArr(int ArrSourceSize, int& ArrDestinationSize, int ArrSource[1000], int ArrDestination[10000])
	{
		ArrDestinationSize = 0;
		for (int i = 0; i < ArrSourceSize; i++)
		{
			if (IsItPrime(ArrSource[i]))
			{
				ArrDestination[ArrDestinationSize] = ArrSource[i];
				ArrDestinationSize++;
			}
		}
	}

	void SumValuesArr(int Arr1Size, int Arr2Size, int& ArrSumSize, int Arr1[10000], int Arr2[10000], int ArrSum[10000]) {
		ArrSumSize = 0;
		if (Arr1Size > Arr2Size)
			ArrSumSize = Arr1Size;
		else
			ArrSumSize = Arr2Size;
		for (int i = 0; i < ArrSumSize; i++)
			ArrSum[i] = Arr1[i] + Arr2[i];
	}

	void ShuffleArr(int ArrSize, int Arr[10000]) {
		for (int i = 0; i < ArrSize; i++)
			Swap(Arr[Random(0, ArrSize - 1)], Arr[Random(0, ArrSize - 1)]);
	}

	void ReverseArr(int ArrSize, int Arr[10000]) {
		for (int i = 0; i < ArrSize / 2; i++)
		{
			Swap(Arr[i], Arr[(ArrSize - 1) - i]);
		}
	}

	void ReverseVector(vector<string>& vVictor) {
		for (int i = 0; i < vVictor.size() / 2; i++)
		{
			Swap(vVictor[i], vVictor[(vVictor.size() - 1) - i]);
		}
	}

	void KeysArr(int ArrSize, string sArr[10000]) {
		for (int i = 0; i < ArrSize; i++)
			sArr[i] = KeyGen();
	}

	short FindInArr(int ArrSize, int index, int Arr[10000]) {
		for (int i = 0; i < ArrSize; i++) {
			if (Arr[i] == index)
				return i;
		}
		return -1;
	}

	bool IsItInArr(int ArrSize, int index, int Arr[10000]) {
		return !(FindInArr(ArrSize, index, Arr) == -1);
	}

	int ColumSum(int RowsNumber, int ColumNumber, int Array[100][100]) {
		int sum = 0;
		for (int i = 0; i < RowsNumber; i++)
			sum += Array[i][ColumNumber];
		return sum;
	}

	void FillMatrixColumSumToArr(int ColumSumArr[100], int RowsNum, int ColumsNum, int OriginalArr[100][100]) {
		for (int i = 0; i < RowsNum; i++)
			ColumSumArr[i] = ColumSum(RowsNum, i, OriginalArr);
	}

	void FillMatrixWithOrderedNumbers(int Matrix[100][100], int Cols, int Rows) {
		int Counter = 0;
		for (int i = 0; i < Rows; i++)
		{
			for (int j = 0; j < Cols; j++)
			{
				Counter++;
				Matrix[i][j] = Counter;
			}
		}
	}

	void TransposeMatrix(int Matrix[100][100], int TransposedMatrix[100][100], int Cols, int Rows) {
		for (int i = 0; i < Rows; i++)
		{
			for (int j = 0; j < Cols; j++)
				Matrix[i][j] = TransposedMatrix[j][i];
		}
	}

	int MatrixSumer(int Matrix[100][100], int Rows, int Cols) {
		int Sum = 0;
		for (int i = 0; i < Rows; i++) {
			for (int j = 0; j < Cols; j++) {
				Sum += Matrix[i][j];
			}
		}
		return Sum;
	}

	void MaricesSumer(int Matrix_1[100][100], int Matrix_2[100][100], int OutputMatrix[100][100], int Rows, int Cols) {

		for (int i = 0; i < Rows; i++) {
			for (int j = 0; j < Cols; j++)
				OutputMatrix[i][j] = Matrix_1[i][j] + Matrix_2[i][j];
		}
	}

	void MaricesMultiplier(int Matrix_1[100][100], int Matrix_2[100][100], int OutputMatrix[100][100], int Rows, int Cols) {

		for (int i = 0; i < Rows; i++) {
			for (int j = 0; j < Cols; j++)
				OutputMatrix[i][j] = Matrix_1[i][j] * Matrix_2[i][j];
		}
	}

	void PrintMiddleRow(int Matrix[100][100], int Rows, int Cols) {
		Rows /= 2;
		for (int i = 0; i < Cols; i++)
			cout << Matrix[Rows][i] << " ";
	}

	void PrintMiddleColum(int Matrix[100][100], int Rows, int Cols) {
		Cols /= 2;
		for (int i = 0; i < Rows; i++)
			cout << Matrix[i][Cols] << " ";
	}

	bool AreEqualMatrices(int Matrix_1[100][100], int Matrix_2[100][100], int Rows, int Cols)
	{
		return MatrixSumer(Matrix_1, Rows, Cols) == MatrixSumer(Matrix_2, Rows, Cols);
	}

	bool AreTipicalMatrices(int Matrix_1[100][100], int Matrix_2[100][100], int Rows, int Cols) {
		for (int i = 0; i < Rows; i++)
		{
			for (int j = 0; j < Cols; j++)
			{
				if (Matrix_1[i][j] != Matrix_2[i][j])
					return false;
			}
		}
		return true;
	}

	bool IsItIdintityMatrix(int Matrix[100][100], int Rows, int Cols) {
		for (int i = 0; i < Rows; i++)
		{
			for (int j = 0; j < Cols; j++) {
				if (i == j && Matrix[i][j] != 1)
					return false;
				else if (i != j && Matrix[i][j] != 0)
					return false;
			}
		}
		return true;
	}

	bool IsItScalarMatrix(int Matrix[100][100], int Rows, int Cols) {
		for (int i = 0; i < Rows; i++)
		{
			for (int j = 0; j < Cols; j++) {

				if (i == j && Matrix[i][j] != Matrix[0][0])
					return false;
				else if (i != j && Matrix[i][j] != 0)
					return false;
			}
		}
		return true;
	}

	int NumInMatrixCounter(int x[100][100], int Rows, int Cols, int Number) {
		int Counter = 0;
		for (int i = 0; i < Rows; i++)
		{
			for (int j = 0; j < Cols; j++) {
				if (Number == x[i][j])
					Counter++;
			}
		}
		return Counter;
	}

	bool IsItSparceMatrix(int x[100][100], int Rows, int Cols) {
		return NumInMatrixCounter(x, 3, 3, 0) >= (Rows * Cols) / 2;
	}

	bool IsInMatrix(int x[100][100], int Rows, int Cols, int Number) {
		for (int i = 0; i < Rows; i++)
		{
			for (int j = 0; j < Cols; j++) {
				if (x[i][j] == Number)
					return true;
			}

		}
		return false;
	}

	void PrintIntersectedNumbers(int Matrix1[100][100], int Matrix2[100][100], short Rows, short Cols) {
		for (int i = 0; i < Rows; i++)
		{
			for (int j = 0; j < Cols; j++)
			{
				if (IsInMatrix(Matrix1, 3, 3, Matrix2[i][j]))
				{
					cout << Matrix2[i][j] << " ";
				}
			}
		}
	}

	int MaxInMatrix(int Matrix[100][100], int Rows, int Cols)
	{
		int Max = Matrix[0][0];
		for (int i = 0; i < Rows; i++)
		{
			for (int j = 0; j < Cols; j++)
			{
				Max = max(Max, Matrix[i][j]);
			}
		}
		return Max;
	}

	int MinInMatrix(int Matrix[100][100], int Rows, int Cols)
	{
		int Min = Matrix[0][0];
		for (int i = 0; i < Rows; i++)
		{
			for (int j = 0; j < Cols; j++)
			{
				Min = min(Min, Matrix[i][j]);
			}
		}
		return Min;
	}

	bool IsItPalindromeMatrix(int Matrix[100][100], int Rows, int Cols)
	{
		for (int i = 0; i < Rows; i++)
		{
			for (int j = 0; j < Cols; j++)
			{
				if (Matrix[i][j] != Matrix[i][Cols - 1 - j])
				{
					return false;
				}
			}
		}
		return true;
	}

	void PrintFibonacciUsingLoop(int Number) {
		int first_index = 0;
		int second_index = 1;
		for (short i = 0; i < Number; i++)
		{
			cout << second_index << " ";
			int FibonacciNumber = first_index + second_index;
			first_index = second_index;
			second_index = FibonacciNumber;
		}
	}

	void PrintFibonacciUsingRecursion(int counter, int first_index, int second_index)
	{
		if (counter > 0)
		{
			cout << second_index << endl;
			int fibonacci = first_index + second_index;
			first_index = second_index;
			second_index = fibonacci;
			PrintFibonacciUsingRecursion(counter - 1, first_index, second_index);
		}
	}

	void PrintFirstLetterOfEachWord(string String)
	{
		bool IsFirstLetter = true;
		for (int i = 0; i < String.length(); i++)
		{
			if (String[i] != ' ' && IsFirstLetter)
			{
				cout << String[i] << endl;
			}
			IsFirstLetter = (String[i] == ' ' ? true : false);
		}
	}
	string ChangeFirstLetterToUpper(string String)
	{
		bool IsFirstLetter = true;
		for (int i = 0; i < String.length(); i++)
		{
			if (String[i] != ' ' && IsFirstLetter)
			{
				String[i] = toupper(String[i]);
			}
			IsFirstLetter = (String[i] == ' ' ? true : false);
		}
		return String;
	}

	string ChangeFirstLetterToLower(string String)
	{
		bool IsFirstLetter = true;
		for (int i = 0; i < String.length(); i++)
		{
			if (String[i] != ' ' && IsFirstLetter)
			{
				String[i] = tolower(String[i]);
			}
			IsFirstLetter = (String[i] == ' ' ? true : false);
		}
		return String;
	}

	string AllUpper(string String)
	{
		for (int i = 0; i < String.length(); i++)
		{

			String[i] = toupper(String[i]);
		}
		return String;
	}

	string AllLower(string String)
	{
		for (int i = 0; i < String.length(); i++)
		{

			String[i] = tolower(String[i]);
		}
		return String;
	}

	void AllUpAllLow(string String)
	{
		cout << "Upper: " << AllUpper(String) << endl;
		cout << "Lower: " << AllLower(String) << endl;
	}

	char InvertLetterCase(char Ch)
	{
		return isupper(Ch) ? tolower(Ch) : toupper(Ch);
	}

	string InvertStringCase(string String)
	{
		for (int i = 0; i < String.length(); i++)
		{
			String[i] = InvertLetterCase(String[i]);
		}
		return String;
	}

	short CountCapitalLetters(string String)
	{
		short Counter = 0;
		for (int i = 0; i < String.length(); i++)
		{
			if (isupper(String[i]))
				Counter++;
		}
		return Counter;
	}

	short CountSmallLetters(string String)
	{
		short Counter = 0;
		for (int i = 0; i < String.length(); i++)
		{
			if (islower(String[i]))
				Counter++;
		}
		return Counter;
	}

	short CountLetter(string String, char Ch)
	{
		short Counter = 0;
		for (int i = 0; i < String.length(); i++)
		{
			if (String[i] == Ch)
				Counter++;
		}
		return Counter;
	}

	void PrintEachWord(string String)
	{
		string delim = " ";
		cout << "\nYour String words are: \n";
		short pos = 0;
		string sWord;
		while ((pos = String.find(delim)) != std::string::npos)
		{
			sWord = String.substr(0, pos);
			if (sWord != "")
			{
				cout << sWord << endl;
			}
			String.erase(0, pos + delim.length());
		}
		if (String != "")
		{
			cout << String << endl;
		}
	}

	int CountEachWord(string String)
	{
		int Counter = 0;
		string delim = " ";
		short pos = 0;
		string sWord;
		while ((pos = String.find(delim)) != std::string::npos)
		{
			sWord = String.substr(0, pos);
			if (sWord != "")
			{
				Counter++;
			}
			String.erase(0, pos + delim.length());
		}
		if (String != "")
		{
			Counter++;
		}
		return Counter;
	}

	vector <string> SplitToWords(string SourceString, string delimeter = " ")
	{
		vector <string> vWords;
		short pos = 0;
		string sWord;
		while ((pos = SourceString.find(delimeter)) != std::string::npos)
		{
			sWord = SourceString.substr(0, pos);
			if (!sWord.empty())
			{
				vWords.push_back(sWord);
			}
			SourceString.erase(0, pos + delimeter.length());
		}
		if (!SourceString.empty())
		{
			vWords.push_back(SourceString);
		}
		return vWords;
	}

	string TrimRight(string SourceString)
	{
		for (int i = SourceString.length() - 1; i >= 0; i--)
		{
			if (SourceString[i] != ' ')
			{
				return SourceString.substr(0, i + 1);
			}
		}
		return "";

	}

	string TrimLeft(string SourceString)
	{
		for (int i = 0; i < SourceString.length(); i++)
		{
			if (SourceString[i] != ' ')
			{
				return SourceString.substr(i, SourceString.length() - 1);
			}
		}
		return "";
	}

	string Trim(string SourceString)
	{
		return TrimLeft(TrimRight(SourceString));
	}

	string JoinString(vector<string> vWords, string delimeter = " ")
	{
		string sJoined = "";
		for (short i = 0; i < vWords.size(); i++)
		{
			sJoined += vWords[i];
			if (i != vWords.size() - 1)
			{
				sJoined += delimeter;
			}
		}
		return sJoined;
	}

	string JoinString(string arrWords[], int arrLength, string delimeter = " ")
	{
		string sJoined = "";
		for (short i = 0; i < arrLength; i++)
		{
			sJoined += arrWords[i];
			if (i != arrLength - 1)
			{
				sJoined += delimeter;
			}
		}
		return sJoined;
	}

	string ReverseWordsInString(string SourceString)
	{
		vector<string>vWords;
		vWords = SplitToWords(SourceString);
		ReverseVector(vWords);
		return  JoinString(vWords);
	}

	string ReplaceWordInStringUsingSplit(string SourceString, string sFrom, string sTo, bool MatchCase = true)
	{
		vector<string>vWords;
		vWords = SplitToWords(SourceString);
		vector<string>::iterator iter = vWords.begin();
		while (iter != vWords.end())
		{
			if (MatchCase)
			{
				if (*iter == sFrom)
					*iter = sTo;
			}
			else
			{
				if (AllLower(*iter) == AllLower(sFrom))
					*iter = sTo;
			}
			iter++;
		}
		return JoinString(vWords);
	}

	string ReplaceWordInStringUsingBuiltInFunction(string source, string from, string to)
	{
		short pos = source.find(from);
		while (pos != std::string::npos)
		{
			source.replace(pos, from.length(), to);
			pos = source.find(from);
		}
		return source;
	}

	stClient ReadNewClient(stClient NewClient)
	{
		cout << "Enter Account Number : ";
		getline(cin >> ws, NewClient.AccountNumber);
		cout << "Enter Pin Code       : ";
		getline(cin, NewClient.PinCode);
		cout << "Enter Full Name      : ";
		getline(cin, NewClient.FullName);
		cout << "Enter Phone Number   : ";
		getline(cin, NewClient.PhoneNumber);
		cout << "Enter Balance Amount : ";
		cin >> NewClient.BalanceAmount;
		cout << endl << endl;
		cin.ignore();
		return NewClient;
	}

	void SaveRecordToFile(string Record, string FileName)
	{
		fstream File;
		File.open(FileName, ios::out | ios::app);
		if (File.is_open())
		{
			File << Record << endl;
			File.close();
		}
	}

	string RecordToLine(stClient Client, string Seperator = "#//#")
	{
		string Line = "";
		Line += Client.AccountNumber + Seperator;
		Line += Client.PinCode + Seperator;
		Line += Client.FullName + Seperator;
		Line += Client.PhoneNumber + Seperator;
		Line += to_string(Client.BalanceAmount);
		return Line;
	}

	stClient LineToRecord(string Line, string Seperator = "#//#")
	{
		stClient Client;
		vector<string> vData = SplitToWords(Line, Seperator);
		if (vData.size() < 5) {
			throw runtime_error("Error: Insufficient data in line");
		}
		Client.AccountNumber = vData[0];
		Client.PinCode = vData[1];
		Client.FullName = vData[2];
		Client.PhoneNumber = vData[3];
		Client.BalanceAmount = stof(vData[4]);
		return Client;
	}

	void PrintClientCard(stClient Client)
	{
		cout << "Account Number : " << Client.AccountNumber << endl;
		cout << "Pin Code       : " << Client.PinCode << endl;
		cout << "Full Name      : " << Client.FullName << endl;
		cout << "Phone Number   : " << Client.PhoneNumber << endl;
		cout << "Balance Amount : " << Client.BalanceAmount << endl;
	}

	void AddNewClient(stClient Client, string FileName)
	{
		cout << "New Client Added \n\n";
		string ClientLine = RecordToLine(Client);
		SaveRecordToFile(ClientLine, FileName);
	}

	void AddClients(string FileName)
	{
		stClient Client;
		char YesOrNo;
		do
		{
			system("cls");
			AddNewClient(ReadNewClient(Client), FileName);
			cout << "Do U want 2 add more (y/n)? ";
			cin >> YesOrNo;
		} while (toupper(YesOrNo) == 'Y');
	}

	vector<stClient> LoadClientsFromFile(string FileName)
	{
		fstream File;
		vector <stClient> Clients;
		File.open(FileName, ios::in);
		if (File.is_open())
		{
			string Line = "";
			stClient TempClient;
			while (getline(File, Line))
			{
				TempClient = LineToRecord(Line);
				Clients.push_back(TempClient);
			}
			File.close();
		}
		return Clients;
	}

	void PrintAllClientsData(vector <stClient> vClients)
	{
		cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;
		cout << "| " << left << setw(15) << "Accout Number";
		cout << "| " << left << setw(10) << "Pin Code";
		cout << "| " << left << setw(40) << "Client Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(12) << "Balance";
		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;
		for (stClient Client : vClients)
		{
			cout << "| " << setw(15) << left << Client.AccountNumber;
			cout << "| " << setw(10) << left << Client.PinCode;
			cout << "| " << setw(40) << left << Client.FullName;
			cout << "| " << setw(12) << left << Client.PhoneNumber;
			cout << "| " << setw(12) << left << Client.BalanceAmount;
			cout << endl;
		}
		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;
	}

	bool FindByAccountNumber(string AccountNumber, stClient& Client, vector<stClient> Clients)
	{
		for (int i = 0; i < Clients.size(); i++)
		{
			if (Clients[i].AccountNumber == AccountNumber)
			{
				Client = Clients[i];
				return true;
			}
		}
		return false;
	}

	bool MarkClientForDelete(string AccountNumber, vector <stClient>& vClients)
	{
		for (int i = 0; i < vClients.size(); i++)
		{
			if (vClients[i].AccountNumber == AccountNumber)
			{
				vClients[i].MarkedForDelete = true;
				return true;
			}
		}
		return false;
	}

	void SaveClientsFromVector(vector <stClient>& vClients, string FileName)
	{
		fstream File;
		File.open(FileName, ios::out);
		if (File.is_open())
		{
			for (stClient TempClient : vClients)
			{
				if (!TempClient.MarkedForDelete)
				{
					File << RecordToLine(TempClient) << endl;
				}
			}

		}
		File.close();
	}

	bool DeleteClientFromFile(string AccountNumber, vector <stClient>& vClients)
	{
		char Answer = 'n';
		stClient TempClient;
		if (FindByAccountNumber(AccountNumber, TempClient, vClients))
		{
			PrintClientCard(TempClient);
			cout << "\nDo u Really want to Delete this client? (y/n)" << endl;
			cin >> Answer;
			if (tolower(Answer) == 'y')
			{
				MarkClientForDelete(AccountNumber, vClients);
				SaveClientsFromVector(vClients, gFileName);
				vClients = LoadClientsFromFile(gFileName);
				cout << "Client deleted";
				return true;
			}
		}
		else
		{
			cout << "Account Number (" << AccountNumber << ") was not found";
		}
		return false;
	}

	stClient EditClientRecord(string AccountNumber)
	{
		stClient Client;
		Client.AccountNumber = AccountNumber;
		cout << "Enter Pin Code       : ";
		getline(cin >> ws, Client.PinCode);
		cout << "Enter Full Name      : ";
		getline(cin, Client.FullName);
		cout << "Enter Phone Number   : ";
		getline(cin, Client.PhoneNumber);
		cout << "Enter Balance Amount : ";
		cin >> Client.BalanceAmount;
		cout << endl << endl;
		cin.ignore();
		return Client;
	}

	bool EditClientFromFile(string AccountNumber, vector <stClient>& vClients)
	{
		char Answer = 'n';
		stClient TempClient;
		if (FindByAccountNumber(AccountNumber, TempClient, vClients))
		{
			PrintClientCard(TempClient);
			cout << "\nDo u Really want to Edit this client? (y/n)" << endl;
			cin >> Answer;
			if (tolower(Answer) == 'y')
			{
				for (stClient& C : vClients)
				{
					if (C.AccountNumber == AccountNumber)
					{
						C = EditClientRecord(AccountNumber);
						break;
					}
				}

				SaveClientsFromVector(vClients, gFileName);
				cout << "Client Edited";
				return true;
			}
		}
		else
		{
			cout << "Account Number (" << AccountNumber << ") was not found";
		}
		return false;
	}

	void waitForKeyPress() {
		cout << "Press any key to continue...";
		system("pause");  // Executes the pause command
	}

	string NumberToText(int Num)
	{
		if (Num == 0)
		{
			return "";
		}
		else if (Num >= 1 && Num <= 19)
		{
			string arr[] = { "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
			return arr[Num];
		}
		else if (Num >= 20 && Num <= 99)
		{
			string arr[] = { "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };
			return arr[Num / 10] + " " + NumberToText(Num % 10);
		}
		//----------------------------------------------------------------
		else if (Num >= 100 && Num <= 199)
		{
			return "One Hundred " + NumberToText(Num % 100);
		}
		else if (Num >= 200 && Num <= 999)
		{
			return  NumberToText(Num / 100) + " Hundreds " + NumberToText(Num % 100);
		}
		//----------------------------------------------------------------
		else if (Num >= 1000 && Num <= 1999)
		{
			return "One Thousand " + NumberToText(Num % 1000);
		}
		else if (Num >= 2000 && Num <= 999999)
		{
			return NumberToText(Num / 1000) + " Thousands " + NumberToText(Num % 1000);
		}
		//----------------------------------------------------------------
		else if (Num >= 1000000 && Num <= 1999999)
		{
			return "One Million " + NumberToText(Num % 1000000);
		}
		else if (Num >= 2000000 && Num <= 99999999)
		{
			return  NumberToText(Num / 1000000) + " Millions " + NumberToText(Num % 1000000);
		}
		//----------------------------------------------------------------
		else if (Num >= 10000000 && Num <= 19999999)
		{
			return "One Billion " + NumberToText(Num % 10000000);
		}
		else if (Num >= 20000000 && Num <= 999999999)
		{
			return  NumberToText(Num / 1000000) + " Billions " + NumberToText(Num % 1000000);
		}
		else
			return to_string(Num) + " Out of Range\n";
	}

	short ReadDay() {
		short Day;
		cout << "\nPlease enter a Day? ";
		cin >> Day;
		return Day;
	}

	short ReadMonth() {
		short Month;
		cout << "\nPlease enter a Month? ";
		cin >> Month;
		return Month;
	}

	short ReadYear() {
		short Year;
		cout << "\nPlease enter a year? ";
		cin >> Year;
		return Year;
	}

	stDate ReadFullDate() {
		stDate Date;
		Date.Day = ReadDay();
		Date.Month = ReadMonth();
		Date.Year = ReadYear();
		return Date;
	}

	bool IsLeapYear(int year)
	{
		return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	}

	short NumberOfDaysInYear(short year)
	{
		return IsLeapYear(year) ? 366 : 365;
	}

	int NumberOfHoursInYear(short year)
	{
		return NumberOfDaysInYear(year) * 24;
	}

	int NumberOfMinutesInYear(short year)
	{
		return NumberOfHoursInYear(year) * 60;
	}

	int NumberOfSecondsInYear(short year)
	{
		return NumberOfMinutesInYear(year) * 60;
	}

	short NumberOfDaysInMonth(short year, short month)
	{
		if (month < 1 || month>12)
			return 0;
		return (month == 2) ? (IsLeapYear(year) ? 29 : 28) : ((month % 2 == 1 && month < 8) || (month % 2 == 0 && month > 7) ? 31 : 30);
	}

	int NumberOfHoursInMonth(short year, short month)
	{
		return NumberOfDaysInMonth(year, month) * 24;
	}

	int NumberOfMinutesInYear(short year, short month)
	{
		return NumberOfHoursInMonth(year, month) * 60;
	}

	int NumberOfSecondsInYear(short year, short month)
	{
		return NumberOfMinutesInYear(year, month) * 60;
	}

	short DayOfWeekOrder(short day, short month, short year)
	{
		short a = (14 - month) / 12;
		short y = year - a;
		short m = month + 12 * a - 2;
		return (day + y + (y / 4) - (y / 100) + (y / 400) + (13 * m / 12)) % 7;
	}

	short DayOfWeekOrder(stDate Date)
	{
		return DayOfWeekOrder(Date.Day,Date.Month,Date.Year);
	}

	string DayOfWeekShortName(short DayOfTheWeekOrder)
	{
		//Week Starts from Sunday
		if (DayOfTheWeekOrder > 6 || DayOfTheWeekOrder < 0)
			return "Invalid Day Order!\n";
		else
		{
			string arrDays[] = { "Sun" ,"Mon" ,"Tue" ,"Wed" ,"Thu" ,"Fri" ,"Sat" };
			return arrDays[DayOfTheWeekOrder];
		}
	}

	string MonthShortName(short Month)
	{
		if (Month > 12 || Month < 1)
			return "Invalid Month Order!\n";
		else
		{
			string arrMonths[] = { "" , "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
			return arrMonths[Month];
		}

	}

	void PrintMonthCalendar(short month, short year, string ScreenOffset = "  ")
	{
		cout << endl << ScreenOffset << "____________" << MonthShortName(month) << "____________" << endl;
		cout << endl << ScreenOffset << "Sun Mon Tue Wed Thu Fri Sat\n";
		short FirstDayOfWeek = DayOfWeekOrder(1, month, year);
		short MonthLength = NumberOfDaysInMonth(year, month);
		cout << ScreenOffset;
		for (int i = 0; i < FirstDayOfWeek; i++)
			cout << setw(4) << " ";
		for (int i = 0; i < MonthLength; i++)
		{
			cout << setw(3) << i + 1 << " ";
			if ((i + 1 + FirstDayOfWeek) % 7 == 0 || i == MonthLength)
				cout << "\n" << ScreenOffset;
		}
		cout << endl << ScreenOffset << "___________________________\n";
	}

	void PrintYearCalendar(short year, string ScreenOffset = "  ")
	{
		cout << endl << ScreenOffset << "___________________________" << endl;
		cout << endl << ScreenOffset << "     Calendar  -  " << year;
		cout << endl << ScreenOffset << "___________________________" << endl;

		for (int i = 1; i <= 12; i++)
			PrintMonthCalendar(i, year, ScreenOffset);

		cout << endl << ScreenOffset << "___________________________\n";
	}

	void SwapDates(stDate& Date1, stDate& Date2)
	{
		stDate temp = Date1;
		Date1 = Date2;
		Date2 = temp;
	}

	short NumberOfDaysFromTheBeginingOfTheYear(short day, short month, short year)
	{
		short TotalDays = 0;
		for (short i = 1; i < month; i++)
			TotalDays += NumberOfDaysInMonth(year, i);
		TotalDays += day;
		return TotalDays;
	}

	short NumberOfDaysFromTheBeginingOfTheYear(stDate Date)
	{
		short TotalDays = 0;
		for (short i = 1; i < Date.Month; i++)
			TotalDays += NumberOfDaysInMonth(Date.Year, i);
		TotalDays += Date.Day;
		return TotalDays;
	}

	stDate DateFromNumberOfDays(short year, int NumberOfDays)
	{
		stDate Date;
		for (short i = 1; i <= 12; i++)
		{
			NumberOfDays -= NumberOfDaysInMonth(year, i);
			if (NumberOfDays < 0)
			{
				NumberOfDays += NumberOfDaysInMonth(year, i);
				Date.Month = i;
				break;
			}
			if (i == 12 && NumberOfDays > 0)
			{
				year++;
				i = 1;
			}
		}
		Date.Day = NumberOfDays;
		Date.Year = year;
		return Date;
	}

	void AddDaysToDate(stDate& Date, int DaysToAdd)
	{
		DaysToAdd += NumberOfDaysFromTheBeginingOfTheYear(Date.Day, Date.Month, Date.Year);
		Date = DateFromNumberOfDays(Date.Year, DaysToAdd);
	}

	stDate StringToDate(string Date, string Delim = "/")
	{
		vector<string> Tokens = SplitToWords(Date, Delim);
		stDate DateToReturn;
		DateToReturn.Day = short(stoi(Tokens[0]));
		DateToReturn.Month = short(stoi(Tokens[1]));
		DateToReturn.Year = short(stoi(Tokens[2]));
		return DateToReturn;
	}
	
	string FormatDate(stDate Date, string Format = "dd/mm/yyyy")
	{
		ReplaceWordInStringUsingBuiltInFunction(Format, "dd", to_string(Date.Day));
		ReplaceWordInStringUsingBuiltInFunction(Format, "mm", to_string(Date.Month));
		ReplaceWordInStringUsingBuiltInFunction(Format, "yyyy", to_string(Date.Year));
		return Format;
	}

	string DateToString(stDate Date, string Delim = "/")
	{
		return to_string(Date.Year) + Delim + to_string(Date.Month) + Delim + to_string(Date.Day);
	}

	bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
	{
		if (Date1.Year != Date2.Year)
			return Date1.Year < Date2.Year;
		if (Date1.Month != Date2.Month)
			return Date1.Month < Date2.Month;
		return Date1.Day < Date2.Day;
	}

	bool IsDate1EqualDate2(stDate Date1, stDate Date2)
	{
		return Date1.Year != Date2.Year ? false : (Date1.Month != Date2.Month ? false : (Date1.Day == Date2.Day ? true : false));
	}

	bool IsDate1AfterDate2(stDate Date1, stDate Date2)
	{
		return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));
	}


	enum enDateCompare { Before = -1, Equal = 0, After = 1 };

	enDateCompare CompareDate(stDate Date1, stDate Date2)
	{
		if (IsDate1BeforeDate2(Date1, Date2))
			return Before;
		else if (IsDate1EqualDate2(Date1, Date2))
			return Equal;
		return After;
	}

	bool IsLastDayInMonth(stDate Date)
	{
		return Date.Day == NumberOfDaysInMonth(Date.Year, Date.Month);
	}

	bool IsLastMonthInYear(short month)
	{
		return month == 12;
	}

	bool IsFirstDayInMonth(stDate Date)
	{
		return Date.Day == 1;
	}

	bool IsFirstMonthInYear(short month)
	{
		return month == 1;
	}

	bool IsEndOfWeek(stDate Date)
	{
		return DayOfWeekOrder(Date) == 6;
	}

	bool IsWeekEnd(stDate Date)
	{
		short DayIndex = DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
		return  (DayIndex == 5 || DayIndex == 6);
	}

	bool IsBusinessDay(stDate Date)
	{
		return !IsWeekEnd(Date);
	}

	short DaysUntilEndOfWeek(stDate Date)
	{
		return 6 - DayOfWeekOrder(Date);
	}

	short DaysUntilEndOfMonth(stDate Date)
	{
		return NumberOfDaysInMonth(Date.Year, Date.Month) - Date.Day;
	}

	short DaysUntilEndOfYear(stDate Date)
	{
		return NumberOfDaysInYear(Date.Year) - NumberOfDaysFromTheBeginingOfTheYear(Date);
	}

	int GetDifferenceInDays(stDate OldDate, stDate RecentDate, bool IncludeEndDay = false)
	{
		int DifferenceInDays = 0;
		short SwapDatesFlag = 1;

		if (!IsDate1BeforeDate2(OldDate, RecentDate))
		{
			SwapDates(OldDate,RecentDate);
			SwapDatesFlag = -1;
		}

		short Date1TotalDays = NumberOfDaysInYear(OldDate.Year) - NumberOfDaysFromTheBeginingOfTheYear(OldDate);
		short Date2TotalDays = NumberOfDaysFromTheBeginingOfTheYear(RecentDate);

		if (OldDate.Year < RecentDate.Year)
		{
			for (int year = OldDate.Year + 1; year < RecentDate.Year; year++)
				DifferenceInDays += NumberOfDaysInYear(year);
		}

		DifferenceInDays += (Date2TotalDays + Date1TotalDays);
		return IncludeEndDay ? DifferenceInDays++ * SwapDatesFlag : DifferenceInDays * SwapDatesFlag;
	}
	
	stDate GetSystemDate()
	{
		stDate Date;
		time_t t = time(0);
		tm* now = localtime(&t);
		Date.Year = now->tm_year + 1900;
		Date.Month = now->tm_mon + 1;
		Date.Day = now->tm_mday;
		return Date;
	}

	int CalculateAgeInDays(stDate BirthDate)
	{
		return GetDifferenceInDays(BirthDate, GetSystemDate(), true);
	}

	stDate IncreaseDateByOneDay(stDate& Date)
	{
		if (IsLastDayInMonth(Date))
		{
			Date.Day = 1;
			if (IsLastMonthInYear(Date.Month))
			{
				Date.Month = 1;
				Date.Year++;
			}
			else
				Date.Month++;
		}
		else
			Date.Day++;
		return Date;
	}

	stDate IncreaseDateByXDays(stDate& Date, short NumOfDays)
	{
		for (short i = 0; i < NumOfDays; i++)
			IncreaseDateByOneDay(Date);
		return Date;
	}

	stDate IncreaseDateByOneWeek(stDate& Date)
	{
		IncreaseDateByXDays(Date, 7);
		return Date;
	}

	stDate IncreaseDateByXWeeks(stDate& Date, short NumOfWeek)
	{
		for (short i = 0; i < NumOfWeek; i++)
			IncreaseDateByOneWeek(Date);
		return Date;
	}

	stDate IncreaseDateByOneMonth(stDate& Date)
	{
		if (IsLastMonthInYear(Date.Month))
		{
			Date.Month = 1;
			Date.Year++;
		}
		else
			Date.Month++;
		
		short DaysInCurrentMonth = NumberOfDaysInMonth(Date.Year, Date.Month);
		if (Date.Day > DaysInCurrentMonth)
			Date.Day = DaysInCurrentMonth;

		return Date;
	}

	stDate IncreaseDateByXMonths(stDate& Date, short NumOfMonths)
	{
		for (short i = 0; i < NumOfMonths; i++)
			IncreaseDateByOneMonth(Date);
		return Date;
	}

	stDate IncreaseDateByOneYear(stDate& Date)
	{
		IncreaseDateByXMonths(Date, 12);
		return Date;
	}

	stDate IncreaseDateByXYears(stDate& Date, short NumOfYears)
	{
		for (short i = 0; i < NumOfYears; i++)
			IncreaseDateByOneYear(Date);
		return Date;
	}

	stDate IncreaseDateByXYearsFaster(stDate& Date, short NumOfYears)
	{
		Date.Year += NumOfYears;
		return Date;
	}

	stDate IncreaseDateByOneDecade(stDate& Date)
	{
		IncreaseDateByXYears(Date, 10);
		return Date;
	}

	stDate IncreaseDateByXDecades(stDate& Date, short NumOfDecades)
	{
		for (short i = 0; i < NumOfDecades; i++)
			IncreaseDateByOneDecade(Date);
		return Date;
	}

	stDate IncreaseDateByXDecadesFaster(stDate& Date, short NumOfDecades)
	{
		IncreaseDateByXYearsFaster(Date, 10 * NumOfDecades);
		return Date;
	}

	stDate IncreaseDateByOneCentury(stDate& Date)
	{
		Date.Year += 100;
		return Date;
	}

	stDate IncreaseDateByOneMillennium(stDate& Date)
	{
		Date.Year += 1000;
		return Date;
	}

	stDate DecreaseDateByOneDay(stDate& Date)
	{
		if (IsFirstDayInMonth(Date))
		{
			if (IsFirstMonthInYear(Date.Month))
			{
				Date.Month = 12;
				Date.Year--;
			}
			else
				Date.Month--;
			Date.Day = NumberOfDaysInMonth(Date.Year, Date.Month);
		}
		else
			Date.Day--;
		return Date;
	}

	stDate DecreaseDateByXDays(stDate& Date, short NumOfDays)
	{
		for (short i = 0; i < NumOfDays; i++)
			DecreaseDateByOneDay(Date);
		return Date;
	}

	stDate DecreaseDateByOneWeek(stDate& Date)
	{
		DecreaseDateByXDays(Date, 7);
		return Date;
	}

	stDate DecreaseDateByXWeeks(stDate& Date, short NumOfWeek)
	{
		for (short i = 0; i < NumOfWeek; i++)
			DecreaseDateByOneWeek(Date);
		return Date;
	}

	stDate DecreaseDateByOneMonth(stDate& Date)
	{
		if (IsFirstMonthInYear(Date.Month))
		{
			Date.Month = 12;
			Date.Year--;
		}
		else
			Date.Month--;

		short DaysInCurrentMonth = NumberOfDaysInMonth(Date.Year, Date.Month);
		if (Date.Day > DaysInCurrentMonth)
			Date.Day = DaysInCurrentMonth;

		return Date;
	}

	stDate DecreaseDateByXMonths(stDate& Date, short NumOfMonths)
	{
		for (short i = 0; i < NumOfMonths; i++)
			DecreaseDateByOneMonth(Date);
		return Date;
	}

	stDate DecreaseDateByOneYear(stDate& Date)
	{
		DecreaseDateByXMonths(Date, 12);
		return Date;
	}

	stDate DecreaseDateByXYears(stDate& Date, short NumOfYears)
	{
		for (short i = 0; i < NumOfYears; i++)
			DecreaseDateByOneYear(Date);
		return Date;
	}

	stDate DecreaseDateByXYearsFaster(stDate& Date, short NumOfYears)
	{
		Date.Year -= NumOfYears;
		return Date;
	}

	stDate DecreaseDateByOneDecade(stDate& Date)
	{
		DecreaseDateByXYears(Date, 10);
		return Date;
	}

	stDate DecreaseDateByXDecades(stDate& Date, short NumOfDecades)
	{
		for (short i = 0; i < NumOfDecades; i++)
			DecreaseDateByOneDecade(Date);
		return Date;
	}

	stDate DecreaseDateByXDecadesFaster(stDate& Date, short NumOfDecades)
	{
		DecreaseDateByXYearsFaster(Date, 10 * NumOfDecades);
		return Date;
	}

	stDate DecreaseDateByOneCentury(stDate& Date)
	{
		Date.Year -= 100;
		return Date;
	}

	stDate DecreaseDateByOneMillennium(stDate& Date)
	{
		Date.Year -= 1000;
		return Date;
	}

	short CalculateVacationDays(stDate From, stDate To)
	{
		short VacationDays = 0;
		while (IsDate1BeforeDate2(From, To))
		{
			if (IsBusinessDay(From))
			{
				VacationDays++;
			}
			IncreaseDateByOneDay(From);
		}
		return VacationDays;
	}

	stDate CalculateVacationReturnDate(stDate DateFrom, short VacationDays)
	{
		short WeekEndCounter = 0;

		while (IsWeekEnd(DateFrom))
		{
			DateFrom = IncreaseDateByOneDay(DateFrom);
		}

		for (short i = 1; i <= VacationDays + WeekEndCounter; i++)
		{

			if (IsWeekEnd(DateFrom))
				WeekEndCounter++;

			DateFrom = IncreaseDateByOneDay(DateFrom);
		}

		while (IsWeekEnd(DateFrom))
		{
			DateFrom = IncreaseDateByOneDay(DateFrom);
		}

		return DateFrom;
	}

	struct stPeriod
	{
		stDate StartDate;
		stDate EndDate;
	};

	stPeriod ReadPeriod() {
		stPeriod Period;
		cout << "\nEnter Start Date:\n";
		Period.StartDate = ReadFullDate();
		cout << "\nEnter End Date:\n";
		Period.EndDate = ReadFullDate();
		return Period;
	}

	bool IsOverlapPeriods(stPeriod Period1, stPeriod Period2)
	{
		return IsDate1BeforeDate2(Period1.StartDate, Period2.EndDate) && IsDate1BeforeDate2(Period2.StartDate, Period1.EndDate);
	}

	short PeriodLengthInDays(stPeriod Period, bool IncludeEndDay = false)
	{
		return GetDifferenceInDays(Period.StartDate, Period.EndDate, IncludeEndDay);
	}

	bool IsDateWithinPeriod(stDate Date, stPeriod Period)
	{
		stPeriod SingleDate;
		SingleDate.StartDate = Date;
		SingleDate.EndDate = Date;
		return IsOverlapPeriods(Period, SingleDate);
	}

	int CountOverlapDays(stPeriod Period1, stPeriod Period2) {
		if (!IsOverlapPeriods(Period1, Period2))
			return 0;

		stDate StartDate = (CompareDate(Period1.StartDate, Period2.StartDate) == enDateCompare::Before) ? Period1.StartDate : Period2.StartDate;
		stDate EndDate = (CompareDate(Period1.EndDate, Period2.EndDate) == enDateCompare::Before) ? Period1.EndDate : Period2.EndDate;

		return GetDifferenceInDays(StartDate, EndDate);
	}

	bool IsValidDate(stDate Date)
	{
		if (Date.Month > 12)
			return false;
		else if (Date.Day > NumberOfDaysInMonth(Date.Year, Date.Month))
			return false;
		else
			return true;
	}
}