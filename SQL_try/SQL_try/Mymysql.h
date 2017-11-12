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
	/*搜尋資料表欄位*/
	void Query_search_slot(vector<string> *name,int *num,int Display_switch);  
	/*插入資料表(從哪個資料表)*/
	void Query_Alert_DATATABLE(string DATATABLE,string DATA,string mode);
	/*刪除資料表(從哪個資料表)*/
	void Query_Drop_data(string DATATABLE,string DATA,string mode);
	void Query_create_DATATABLE(string DATATABLE,string mode);

	/*新增*/
	void Query_insert_data(string DATATABLE,vector<string> SlotName,vector<string> SlotValue);
	/*更新*/
	void Query_update_data(string DATATABLE,vector<string> SlotName,vector<string> SlotValue,string condition,string conditionValue);
	void Query_update_data(string DATATABLE,vector<string> SlotName,vector<string> SlotValue,vector<string> condition);
	/*刪除*/
	void Query_delete_data(string DATATABLE,string conditionName,string conditionValue);
	/*新增資料庫*/
	//void Query(MYSQL*,string,string);
	/*新增資料表*/
	//void Query_create_DATATABLE(MYSQL*,string,string,string);
	~Mymysql(void);
};

