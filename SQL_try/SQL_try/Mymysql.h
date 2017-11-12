#pragma once
#pragma comment(lib,"libmysql.lib")
#ifndef _mysql_h
#include <mysql.h> 
#endif
#ifndef _IOSTREAM_
#include<iostream>
#endif
#ifndef _STRING_
#include<string>
#endif
#ifndef _VECTOR_
#include<vector>
#endif
#define _DEBUG_THE_API 1
using namespace std;
class Mymysql
{
	MYSQL *mysql; 
	string host;
	string user;
	string password;
	string database;
	int port;
	
public:
	Mymysql(string,	string ,string ,string ,int);
	/*Table and Database building*/
	/*�j�M��ƪ����*/
	void Query_search_slot(vector<string> *name,int *num,int Display_switch);  
	/*���J��ƪ�(�q���Ӹ�ƪ�)*/
	void Query_Alert_DATATABLE(string DATATABLE,string DATA,string mode);
	/*�R����ƪ�(�q���Ӹ�ƪ�)*/
	void Query_Drop_data(string DATATABLE,string DATA,string mode);
	void Query_create_DATATABLE(string DATATABLE,string mode);

	/*�s�W*/
	void Query_insert_data(string DATATABLE,vector<string> SlotName,vector<string> SlotValue);
	/*��s*/
	void Query_update_data(string DATATABLE,vector<string> SlotName,vector<string> SlotValue,string condition,string conditionValue);
	void Query_update_data(string DATATABLE,vector<string> SlotName,vector<string> SlotValue,vector<string> condition);
	/*�R��*/
	void Query_delete_data(string DATATABLE,string conditionName,string conditionValue);
	/*�s�W��Ʈw*/
	//void Query(MYSQL*,string,string);
	/*�s�W��ƪ�*/
	//void Query_create_DATATABLE(MYSQL*,string,string,string);
	~Mymysql(void);
};

