#pragma comment(lib,"libmysql.lib")
//#include <iostream>
//#include <string>
#include "Mymysql.h"
#define SQL_HOST "localhost"
#define SQL_USER "root"
#define SQL_PASSWORD ""
#define SQL_DATABASE "manage"
#define SQL_DATABASE_AFTER "Parking_Lot_member_database"
string colon[4]={"num","ID","passward","state"};
#define SQL_PORT 3306
using namespace std;
enum Example_test{
	new_database,
	new_table,
	new_data,
	update_data,
	search_data,
	search_table_slot,
	delete_data,
	delete_table,
	delete_table_slot,
	delete_database
};
Example_test test_sample=search_table_slot;//delete_data;//new_data;
/*新增資料庫*/
//void Query(MYSQL*,string,string);
/*新增資料表*/
//void Query_create(MYSQL*,string,string,string);

void main()  
{  
	Mymysql SQL(SQL_HOST,SQL_USER,SQL_PASSWORD,SQL_DATABASE,SQL_PORT);

#if test_sample==search_table_slot
	vector<string> name;
	name.push_back("root");
	name.push_back("basda");
	name.push_back("A123A");
	vector<string> value;
	value.push_back("A");
	value.push_back("B");
	value.push_back("D");
#endif

	switch(test_sample)
	{
	case new_database:
		break;
	case new_table:
		break;
	case new_data:
		SQL.Query_insert_data("hi",name,value);
		break;
	case update_data:
		break;
	case search_data:
		break;
	case search_table_slot:
		SQL.Query_search_slot(NULL,NULL,1);
		break;
	case delete_data:
		SQL.Query_delete_data("hi","A123A","C");
		break;
	case delete_table:
		break;
	case delete_table_slot:
		break;
	case delete_database:
		break;
	}
	system("pause");
}
	/*
	
	*/
	
	/*control test*/
	/*int flag=1;
	while(flag)
	{
		fflush(stdin);
		SQL.testQuery();  
		int choose=0;
		string temp;
		cout<<"Please Enter you want to do ?>"<<endl<<"(1)new data"<<endl<<"(2)delete data"<<endl<<"(3)exit"<<endl<<">";
		cin>>choose;
		SQL.Query_create_DATATABLE("hA","hi");
		switch(choose)
		{
		case 1:
			cout<<"Please Enter data name ?>";
			cin>>temp;
			SQL.Query_Alert_data("hi",temp,"HH");
			break;
		case 2:
			cout<<"Please Enter data name ?>";
			cin>>temp;
			SQL.Query_Drop_data("hi",temp,"HH");
			//Query_Drop_data(mysql,"hi",temp,"HH");
			break;
		case 3:
			flag=0;
			break;
		}
		system("pause");
		system("cls");
	}*/

	/*NEW test*/

	/*
	for(int i=0;i<52;i++)
	{
		char temp[2]={48+i,'\0'};
		string ttemps(temp);
		cout<<i<<"\t:Alert"+ttemps<<endl;
		SQL.Query_Alert_DATATABLE("hi","A"+ttemps+"A","HH");
	}*/
/*
void Query(MYSQL *mysql,string DATABASE,string DATATABLE)
{
	MYSQL_ROW row;  
    MYSQL_RES *res = NULL;  
    MYSQL_FIELD *fields = NULL;  
    int i, field_count;  
    string sql_instuction= "select "+DATABASE+" from "+DATATABLE;
	char *INST=new char[sql_instuction.length()+1];
	strcpy(INST,sql_instuction.c_str());
    int flag = mysql_real_query(mysql, INST, (unsigned long)strlen(INST));  
    if (flag)  
    {  
        printf("Query error:%d, %s\n",mysql_errno(mysql), mysql_error(mysql));  
        return;  
    }  
  
    res = mysql_store_result(mysql);  
  
    fields = mysql_fetch_fields(res);  
  
    field_count = mysql_field_count(mysql);  
    for (i = 0; i < field_count; i++)  
    {  
        printf("%s\t", fields[i].name);  
    }  
  
    printf("\n");  
      
    while (row = mysql_fetch_row(res))  
    {  
        for (i = 0; i < field_count; i++)  
        {  
            printf("%s\t", row[i]);  
        }  
        printf("\n");  
    }  
	delete [] INST;
}
void Query_create(MYSQL *mysql,string DATABASE,string DATATABLE,string mode)
{
	MYSQL_ROW row;  
    MYSQL_RES *res = NULL;  
    MYSQL_FIELD *fields = NULL;  
    int i, field_count;  
	string sql_instuction;
	if(mode.compare("DATABASE"))
	{
		sql_instuction= "create database "+DATABASE;

	}
    sql_instuction= "select "+DATABASE+" from "+DATATABLE;
	char *INST=new char[sql_instuction.length()+1];
	strcpy(INST,sql_instuction.c_str());
    int flag = mysql_real_query(mysql, INST, (unsigned long)strlen(INST));  
    if (flag)  
    {  
        printf("Query error:%d, %s\n",mysql_errno(mysql), mysql_error(mysql));  
        return;  
    }  
  
    res = mysql_store_result(mysql);  
    fields = mysql_fetch_fields(res);  
  
    field_count = mysql_field_count(mysql);  
    for (i = 0; i < field_count; i++)  
        printf("%s\t", fields[i].name);
    printf("\n");  
    while (row = mysql_fetch_row(res))  
    {  
        for (i = 0; i < field_count; i++)  
			printf("%s\t", row[i]);  
        printf("\n");  
    }  
	delete [] INST;
}
*/