#pragma once
#include <jdbc/cppconn/resultset.h>
#include <jdbc/cppconn/statement.h>
#include <jdbc/mysql_connection.h>
#include <jdbc/mysql_driver.h>
#include "User.h"
#include "Client.h"
#include "Administrator.h"
#include "Commodity.h"
#include "Order.h"
#include "Supplier.h"

/*
* ���ݷ��ʲ㣨Data Access Object�����������ݷ��ʵĲ�������ɾ�Ĳ��
* �õ����ݿ�����ݷ��ظ�ҵ�����
*/
class Dao
{
	//����MySQL���ݿ�
	void connect() {
        // ���ӵ�MySQL���ݿ�
        sql::Driver* driver;
        sql::Connection* con;
        driver = get_driver_instance();
        con = driver->connect("tcp://127.0.0.1:3306", "username", "password");
        con->setSchema("your_database");

        // ִ��SQL��ѯ
        sql::Statement* stmt;
        sql::ResultSet* res;
        stmt = con->createStatement();
        res = stmt->executeQuery("SELECT id, name, age FROM your_table");

        // ��װ���ݵ�����
        while (res->next()) {
            int id = res->getInt("id");
            std::string name = res->getString("name");
            int age = res->getInt("age");
            // �������󲢽����ݷ�װ��ȥ
             //User obj(id, name, age);
            // ������洢�����ʵ����ݽṹ�У�����vector��map
        }

        // �ͷ���Դ
        delete res;
        delete stmt;
        delete con;
	}


	//


};

