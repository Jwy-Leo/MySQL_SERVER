#include "Mymysql.h"


Mymysql::Mymysql(string HOST,string USER,string P_WORD,string D_BASE,int PORT)
{
	mysql = mysql_init((MYSQL *)0); 
	host= HOST;
	user= USER;
	password= P_WORD;
	database= D_BASE;
	port=PORT;
	mysql = mysql_real_connect(mysql,host.c_str(),user.c_str(), password.c_str(),database.c_str(),port, NULL, 0);  
	if (mysql)  
		cout<<"connection succellfull the database!\n"<<endl;  
	else
	{
		cout<<"connection error:"<<mysql_errno(mysql)<<","<<mysql_error(mysql)<<endl;  
		system("pause");
		exit(0);
	}
}
/*create table 資料表名稱(
sn integer auto_increment primary key,
name char(20),
mail char(50),
home char(50),
messages char(50)
);*/
void Mymysql::Query_create_DATATABLE(string DATATABLE,string mode)
{
	MYSQL_ROW row;  
    MYSQL_RES *res = NULL;  
    MYSQL_FIELD *fields = NULL;  
    int i, field_count;  
	string sql_instuction;
    sql_instuction= "create table "+DATATABLE+"( sn integer auto_increment primary key,name char(20),mail char(50),home char(50),messages char(50));";
    int flag = mysql_real_query(mysql, sql_instuction.c_str(), (unsigned long)sql_instuction.length());  
    if (flag&&_DEBUG_THE_API)  
		cout<<"Query error:"<<mysql_errno(mysql)<<","<<mysql_error(mysql)<<endl;
}

void Mymysql::Query_search_slot(vector<string> *name,int *num,int Display_switch)
{
	int flagR=1;
	if(name==NULL||num==NULL)
		flagR=0;
	MYSQL_ROW row;  
    MYSQL_RES *res = NULL;  
    MYSQL_FIELD *fields = NULL;  
    int i, field_count;  
    char *sql = "select * from hi";  
    int flag = mysql_real_query(mysql, sql, (unsigned long)strlen(sql));  
    if (flag&&_DEBUG_THE_API)  
    {  
        printf("Query error:%d, %s\n",mysql_errno(mysql), mysql_error(mysql));  
        return;  
    }  
	
    res = mysql_store_result(mysql);  
    fields = mysql_fetch_fields(res);  
    field_count = mysql_field_count(mysql);  
	if(flagR)
		*num=field_count;
	cout<<"\ttitle\t"; 
    for (i = 0; i < field_count; i++)  
	{
		if(flagR)
			name->push_back(fields[i].name);
		if(Display_switch)
			cout<<fields[i].name<<"\t";  
	}
    cout<<endl<<endl;
	cout<<"index"<<endl;
	int ii=0;
    while (row = mysql_fetch_row(res))  
    {  
		cout<<ii+1<<"\t\t";
        for (i = 0; i < field_count; i++)  
            printf("%s\t", row[i]);  
        printf("\n");
		ii++;
    }
	mysql_free_result(res);
}
void Mymysql::Query_Alert_DATATABLE(string DATATABLE,string DATA,string mode)
{
	int DATALength=DATA.length();
	char buf[1024];
	itoa(DATALength,buf,10);
	string sql_instuction;
	sql_instuction= "alter table "+DATATABLE+" add column "+ DATA +" VARCHAR("+buf +");";
	int flag = mysql_real_query(mysql, sql_instuction.c_str(), (unsigned long)sql_instuction.length());  
    if (flag&&_DEBUG_THE_API)  
		cout<<"Query error:"<<mysql_errno(mysql)<<","<<mysql_error(mysql)<<endl; 
}
void Mymysql::Query_Drop_data(string DATATABLE,string DATA,string mode)
{
	string sql_instuction;
    sql_instuction= "alter table "+DATATABLE+" drop column "+ DATA ;
    int flag = mysql_real_query(mysql, sql_instuction.c_str(), (unsigned long)sql_instuction.length());  
    if (flag&&_DEBUG_THE_API)  
		cout<<"Query error:"<<mysql_errno(mysql)<<","<<mysql_error(mysql)<<endl; 
}
	
/*新增*/
void Mymysql::Query_insert_data(string DATATABLE,vector<string> SlotName,vector<string> SlotValue)
{
	if(SlotName.size()==SlotValue.size())
	{ 
		string sql_instuction;
		sql_instuction= "INSERT INTO "+DATATABLE+"(";
		for(int i=0;i<SlotName.size()-1;i++)
			sql_instuction+="`"+SlotName[i]+"`,";
		sql_instuction+="`"+SlotName[SlotName.size()-1]+"`) VALUES (";
		for(int i=0;i<SlotValue.size()-1;i++)
			sql_instuction+="'"+SlotValue[i]+"',";
		sql_instuction+="'"+SlotValue[SlotValue.size()-1]+"')";
		if(_DEBUG_THE_API)
			cout<<sql_instuction<<endl;
		int flag = mysql_real_query(mysql, sql_instuction.c_str(), (unsigned long)sql_instuction.length());  
		if (flag&&_DEBUG_THE_API)  
			cout<<"Query error:"<<mysql_errno(mysql)<<","<<mysql_error(mysql)<<endl; 
	}
	else
		cout<<"Query_insert_data ERROR of vector size unsame"<<endl;
}
/*更新*/
void Mymysql::Query_update_data(string DATATABLE,vector<string> SlotName,vector<string> SlotValue,string conditionName,string conditionValue)
{
	
	if(SlotName.size()==SlotValue.size())
	{ 
		string sql_instuction;
		sql_instuction="update "+DATATABLE+" set ";
		for(int i=0;i<SlotName.size();i++)
			sql_instuction+=SlotName[i]+"='"+SlotValue[i]+"' ";
		sql_instuction+="where "+conditionName+"='"+conditionValue+"'";
		if(_DEBUG_THE_API)
			cout<<sql_instuction<<endl;
		int flag = mysql_real_query(mysql, sql_instuction.c_str(), (unsigned long)sql_instuction.length());  
		if (flag&&_DEBUG_THE_API)  
			cout<<"Query error:"<<mysql_errno(mysql)<<","<<mysql_error(mysql)<<endl; 
	}
	else
		cout<<"Query_insert_data ERROR of vector size unsame"<<endl;
	
}
void Mymysql::Query_update_data(string DATATABLE,vector<string> SlotName,vector<string> SlotValue,vector<string> condition)
{
	string sql_instuction;
	sql_instuction="update "+DATATABLE+" set root\=\'MY\' ";
	int flag = mysql_real_query(mysql, sql_instuction.c_str(), (unsigned long)sql_instuction.length());  
    if (flag&&_DEBUG_THE_API)  
		cout<<"Query error:"<<mysql_errno(mysql)<<","<<mysql_error(mysql)<<endl; 
}
/*刪除*/
void Mymysql::Query_delete_data(string DATATABLE,string conditionName,string conditionValue)
{
	string sql_instuction;
	sql_instuction="delete from "+DATATABLE+" where "+conditionName+"='"+conditionValue+"'";
	int flag = mysql_real_query(mysql, sql_instuction.c_str(), (unsigned long)sql_instuction.length());  
    if (flag&&_DEBUG_THE_API)  
		cout<<"Query error:"<<mysql_errno(mysql)<<","<<mysql_error(mysql)<<endl; 
}
Mymysql::~Mymysql(void)
{
	mysql_close(mysql); 
}
