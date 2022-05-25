//���� dbmslib5.h
#pragma once
#ifndef _dbmsLib5_
#define _dbmsLib5_
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <strstream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;
namespace dbmsLib5
{
	enum Errors {
		EMPTY_ARGUMENT,
		INCORRECT_INPUT,
		EMPRTY_CLASS_FIELD,
		NOTHING_TO_PRINT,
		NOT_EMPTY_CLASS
	};

	static const int arrDays[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	//====================����� DBDate5======================
	class DBDate5
	{
		friend string DateToStr(DBDate5& date);
		friend ostream& operator<<(ostream& out, DBDate5& date);
		int day, month, year;
		bool IsLeapYear(int year); //��� ����������?
		int GetDaysInMonth(int month, int year);//���������� ���� � ������
		int DaysInCurYear();//���������� ���� �� ������ ���� �� ������� ����
	public:
		DBDate5(string date);//������ ������: dd.mm.yyyy
		DBDate5(int d, int m, int y);
		DBDate5() :day(0), month(0), year(0) {};//???����������� �� ���������
		DBDate5(DBDate5& dat) :day(dat.day), month(dat.month), year(dat.year) {}
		int GetDay();
		int GetMonth();
		int GetYear();
		bool operator==(DBDate5& date);
		bool operator<(DBDate5& date);
		bool operator>(DBDate5& date);
		bool operator<= (DBDate5& date);
		bool operator>= (DBDate5& date);
		bool operator!= (DBDate5& date);
		const DBDate5& operator+=(int days);//���������� � ������� ���� days ����
		DBDate5& operator-=(int days);//�������� �� ������� ���� days ����
		int operator-(DBDate5& date);	//���������� ���� ����� ������� ����� � date
		//���� ������� ���� > date, ��������� < 0.
	};
	//DBType-������������ ����� ����� ������ ��:
	enum DBType { NoType, Int32, Double, String, Date };
	//typeNames - ������ ���� �����. 
	//������������ ��� �������������� ����� ���� (char*) � ������ DBType 
	static const char* typeNames[]={
		"NoType",
		"Int32",
		"Double",
		"String",
		"DBDate5"
	};
	//Condition-������������ �������, �� ������� ����� ������������� ���� ������ ��:
	enum Condition { Undefined, Equal, NotEqual, Less, Greater, LessOrEqual, GreaterOrEqual };
	const int LENGTH = 24;//����� ����� ������� � ����� �������.
	//ColumnDesc - �������� ������ � ������� ������� 
	//������ ���� string ����� ���������� ����� (length) ������ ������ �������, 
	//�� � ������ �������� �� ����� ����� ����������
	struct ColumnDesc {
		char colName[LENGTH];//��� �������
		DBType colType;//��� ������ � ������� �������
		int length; //������������ ����� ��������, ���������� 
		//��� ������������� ������ � �������
	};
	struct Strip {//������ ���������� �������
		int nField;//����� ����� 
		int* fieldWidth;//������ ����� � ������ (������)
	};
	typedef map<string, void*> Row;
	typedef map<string, ColumnDesc> Header;
	//-----------------����� DBDate5----------------------------
	class DBTable5 {
	private:
		Header columnHeaders;
		vector<Row> data;
		string tableName;
	public:
		DBType GetType(char* columnName);
		const char* TypeName(DBType type);
		virtual ~DBTable5() {};//����������� ����������
		virtual Header GetHeader() = 0;
		virtual vector<int> IndexOfRecord(void* keyValue, string keyColumnName) = 0;
		virtual vector<Row> GetData() = 0;
		//�� �������� ����� ���������� 
		//���������� ����� (������) ������ (������) � data.
		// keyValue-�������� ����� (��������� �� string, int ��� DBDate5)
		// keyColumnName-��� ��������� ������� (��������� ��� ��������� ����)
		//� ������� ����� ���� ��������� ������� � ���������� ��������� ���������� �����.
		virtual Row GetRow(int index) = 0;
		virtual Row operator[](int index) = 0;
		virtual string valueToString(Row& row, string columnName) = 0;
		virtual int GetSize() = 0;
		virtual void SetHeader(Header& hdr) = 0;
		virtual void ReadDBTable5(string fileName) = 0;//fileName="..\\"+dbName+"\\"+tableName+".bin"|".txt"	
		virtual void PrintTable5(int screenwidth);

		virtual void WriteDBTable5(string fileName) = 0;
		virtual void SetTableName(string tName) = 0;
		virtual void SetPrimaryKey(string key) = 0;
		virtual string GetTableName() = 0;
		virtual string GetPrimaryKey() = 0;
		virtual void SetFileName(string path) = 0;
		virtual string GetFileName() = 0;
		//virtual void PrintTable(int screenWidth) = 0;
		virtual Row CreateRow() = 0;
		virtual void AddRow(int index) = 0;
		virtual DBTable5* SelfRows(string colName, Condition cond, void* value) = 0;
		virtual void CreateTableMaket(Strip*& strips, int& nStrip, int screenWidth) = 0;
	};

	//===============class DBTableTxt5=============================
	class DBTableTxt5 : public DBTable5 {
	private:
		Header columnHeaders;
		string tableName;
		string primaryKey;
		vector<Row> data;
		string fileName;
	public:
		DBTableTxt5() {}
		DBTableTxt5(string tabName);/*: DBTable5(tabName){}*/
		DBTableTxt5(string tabName, Header hdr, string primKey);/*:DBTable5(tabName,hdr,primKey){}*/
		~DBTableTxt5();//!!!���������� ����������,����� ������,���������� void*,�� �������
		vector<int> IndexOfRecord(void* keyValue, string keyColumnName);
		string valueToString(Row& row, string columnName);
		void ReadDBTable5(string tabName);//tabName=path+tableName
		void PrintTable5(int screenWidth);
		void WriteDBTable5(string tabName);//tabName=path+tableName	
		int GetSize();
		vector<Row> GetData();
		Row operator[](int ind) { return this->data[ind]; };
		void SetFileName(string path);
		void SetTableName(string tName);
		void SetPrimaryKey(string key);
		string GetFileName();
		string GetTableName();
		string GetPrimaryKey() { return primaryKey; }
		Header GetHeader();
		void SetHeader(Header& hdr);
		Row CreateRow() { return Row(); };
		Row GetRow(int index);
		void AddRow(int index);
		DBTable5* SelfRows(string columnName, Condition cond, void* value);
		//����� ���������� �������:
		//screenWidth - ������ ������ (������� ��������)
		//nStrips - ����� ����� � ���������� (�������� ��������)
		//strips[nStrips] - �������� ����� �������: 
		//����� �������� � ������ ������� ������� � ������ (�������� ��������)
		void CreateTableMaket(Strip*& strips, int& nStrips, int screenWidth);

		friend void WriteTableBin5(DBTableTxt5& tab, string fileName);
		friend void ReadTableBin5(DBTableTxt5& tab, string tabName);
	};
	//=====================����� DBTableBin5=====================================
	class DBTableBin5 : public DBTable5 {
		Header columnHeaders;
		string tableName;
		string primaryKey;//��� ������� �� ���������� ���������� �����
		int nColumn;
		//ColumnDesc* header;
		int nRows;
		int RowLength();
		int DataBegin();
		int FieldPosition(string colName);//�������� ���� colName �� ������ ������ � ������
		int FieldLength(string colName);//����� ���� colName � ������
		void ResizeData(int deltaRows);
		vector<Row> data;
		int maxRows;//����� ����� � data � ������ DELTA (��� ���������� �������//????int maxRows()
		//�� ����� ��������������� ������ nRows+DELTA).� ���� �� ������������
		char fileName[80];//� ���� �� ������������. ������������ � ������� ���
		//��������� � �����
	public:
		DBTableBin5() {}
		DBTableBin5(string tableName);
		DBTableBin5(string tableName, Header hdr, string primKey);
		~DBTableBin5();
		Header GetHeader();
		vector<int> IndexOfRecord(void* keyPtr, string keyName);
		vector<Row> GetData();
		//�� �������� ����� ���������� 
		//���������� ����� (������) ������ (������) � data.
		// keyPtr-�������� ����� (��������� �� string, int ��� DBDate5)
		// keyName-��� ��������� ������� (��������� ��� ��������� ����)
		//� ������� ����� ���� ��������� ������� � ���������� ��������� ���������� �����.
		int FieldPosInFile(int rowIndex, string columnName);
		Row GetRow(int index);
		Row operator[](int index);
		string valueToString(Row& row, string columnName);
		int GetSize();
		void SetHeader(Header& hdr);
		void ReadDBTable5(string fileName);//fileName="..\\"+dbName+"\\"+tableName+".bin"											
		void WriteDBTable5(string fileName);
		void SetTableName(string tName);
		void SetPrimaryKey(string key);
		string GetTableName();
		string GetPrimaryKey();
		void SetFileName(string path);
		string GetFileName();
		void PrintTable5(int screenWidth);
		Row CreateRow();
		void AddRow(int index);
		DBTable5* SelfRows(string colName, Condition cond, void* value);

		void CreateTableMaket(Strip*& strips, int& nStrips, int screenWidth);
	};
	//==============����� DBTableSet5============================
	struct Relation {//��������� ����� ���� ������
		string relationName;
		string parentTable;
		string parentPrimaryKey;
		string childTable;
		string childSecondaryKey;
	};
	void PrintRow(Row row, DBTable5* tab);
	//-------------------------����� DBTableSet5---------------------
	class DBTableSet5
	{
	private:
		string dbName;
		map<string, DBTable5*> db;
	public:
		DBTableSet5() {};
		DBTableSet5(string name);
		map<string, DBTable5*> GetDB();
		void ReadDB5();
		void PrintDB5(int numcol);
		void WriteDB5();
		string GetDBName() { return dbName; }
		DBTable5* operator[](string tableName);
		Relation GetRelation(string relationName);
		Row ParentRow(Relation& relation, Row& childRow);
		DBTable5* ChildRows(Relation& relation, Row& parentRow);

		friend string FileType(string dbName);

		int initNewDB(vector<string> tableNames);
	};

	const int DELTA = 10;//����� � 10 ����� ��� ����� ������� � �������. 
	//���� ����� ������������, �� ��� ��� �������������� ����� ���������
	//�� DELTA ������ ������������� ������� char* data[]. 
	//const int LENGTH = 24;//����� ����� ������� � ����� �������.

	string GetTabNameFromPath(string path);
	string ignoreBlanc(const string str);
	void* GetValue(string value, string columnName, Header hdr);
	void* SetValue(string value, string columnName, Header hdr);
	bool comparator(/*TableDataType*/DBType type, void* obj1, Condition condition, void* obj);
	int GetLength(ColumnDesc colDesc);
}

#endif //����� _dbmsLib_