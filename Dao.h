#pragma once
#include <jdbc/cppconn/resultset.h>
#include <jdbc/cppconn/statement.h>
#include <jdbc/mysql_connection.h>
#include <jdbc/mysql_driver.h>
#include <jdbc/cppconn/exception.h>
#include <jdbc/cppconn/prepared_statement.h>

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
private:
    sql::Driver* driver;
    sql::Connection* con; 


public:
    Dao() {
        driver = get_driver_instance(); //��ȡMySQL���������ʵ��
        con = driver->connect("localhost", "root", "123456"); //����һ����ʾ�����ݿ�����ӵĶ��󣬸ö�������������ݿ��ͨ���������Ϣ
        con->setSchema("goods_system");
    }

    ~Dao() {
        delete con; //�ͷ�������Դ
    }

    bool check(const string& username, const string& password, int role) {
        try {
            sql::PreparedStatement* prep_stmt;
            sql::ResultSet* res;

            if (role == 1) {
                prep_stmt = con->prepareStatement("SELECT username, password FROM administrator where username = ? and password = ?");
                prep_stmt->setString(1, username);
                prep_stmt->setString(2, password);
                res = prep_stmt->executeQuery();
            }
            else {
                prep_stmt = con->prepareStatement("SELECT username, password FROM client where username = ? and password = ?");
                prep_stmt->setString(1, username);
                prep_stmt->setString(2, password);
                res = prep_stmt->executeQuery();
            }

            while (res->next()) { //����ÿһ������
                string dbUsername = res->getString("username");
                string dbPassword = res->getString("password");
                // ������������
                if (dbUsername == username && dbPassword == password) {
                    // ƥ��ɹ���ִ����ز���
                    return true;
                }
            }

            delete prep_stmt; // �ͷ���Դ
            delete res; // �ͷ���Դ

            return false;
        }
        catch (sql::SQLException& e) {
            std::cout << "SQLException: " << e.what() << std::endl;
            return false;
        }
    }


    //bool check(const string& username,const string& password, int role) {
    //    //sql::Driver* driver;
    //    //sql::Connection* con;
    //    //driver = get_driver_instance();
    //    //con = driver->connect("localhost", "root", "123456");
    //    //con->setSchema("goods_system");
    //    sql::PreparedStatement* prep_stmt;
    //    sql::ResultSet* res;

    //    if (role == 1) {
    //        prep_stmt = con->prepareStatement("SELECT username, password FROM administrator where username = ? and password = ?");
    //    }
    //    else {
    //        prep_stmt = con->prepareStatement("SELECT username, password FROM client where username = ? and password = ?");
    //    }

    //    // ���ò���ֵ
    //    prep_stmt->setString(1, username);
    //    prep_stmt->setString(2, password);



    //    //sql::Statement* stmt;
    //    //sql::ResultSet* res;
    //    /*prep_stmt = con->createStatement();*/
    //    //if (role == 1) {
    //    //    res = stmt->executeQuery("SELECT username, password FROM administrator where username = ?");
    //    //}
    //    //else {
    //    //    res = stmt->executeQuery("SELECT username, password FROM client where username = ?");
    //    //}

    //    while (res->next()) {
    //        /*int id = res->getInt("id");
    //        std::string name = res->getString("name");
    //        int age = res->getInt("age");*/
    //        // �������󲢽����ݷ�װ��ȥ
    //         //User obj(id, name, age);
    //        // ������洢�����ʵ����ݽṹ�У�����vector��map
    //    }

    //    // �ͷ���Դ
    //    delete res;
    //    delete stmt;
    //    delete con;
    //}


	void connect() {
        // ���ӵ�MySQL���ݿ�
        sql::Driver* driver;
        sql::Connection* con;
        driver = get_driver_instance();
        con = driver->connect("localhost", "username", "password");
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

};

