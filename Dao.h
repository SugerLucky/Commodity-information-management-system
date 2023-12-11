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
* 数据访问层（Data Access Object）：负责数据访问的操作，增删改查等
* 拿到数据库的数据返回给业务处理层
*/
class Dao
{
private:
    sql::Driver* driver;
    sql::Connection* con; 


public:
    Dao() {
        driver = get_driver_instance(); //获取MySQL驱动程序的实例
        con = driver->connect("localhost", "root", "123456"); //返回一个表示与数据库的连接的对象，该对象包含了与数据库的通信所需的信息
        con->setSchema("goods_system");
    }

    ~Dao() {
        delete con; //释放连接资源
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

            while (res->next()) { //遍历每一条数据
                string dbUsername = res->getString("username");
                string dbPassword = res->getString("password");
                // 进行其他操作
                if (dbUsername == username && dbPassword == password) {
                    // 匹配成功，执行相关操作
                    return true;
                }
            }

            delete prep_stmt; // 释放资源
            delete res; // 释放资源

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

    //    // 设置参数值
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
    //        // 创建对象并将数据封装进去
    //         //User obj(id, name, age);
    //        // 将对象存储到合适的数据结构中，比如vector或map
    //    }

    //    // 释放资源
    //    delete res;
    //    delete stmt;
    //    delete con;
    //}


	void connect() {
        // 连接到MySQL数据库
        sql::Driver* driver;
        sql::Connection* con;
        driver = get_driver_instance();
        con = driver->connect("localhost", "username", "password");
        con->setSchema("your_database");

        // 执行SQL查询
        sql::Statement* stmt;
        sql::ResultSet* res;
        stmt = con->createStatement();
        res = stmt->executeQuery("SELECT id, name, age FROM your_table");

        // 封装数据到对象
        while (res->next()) {
            int id = res->getInt("id");
            std::string name = res->getString("name");
            int age = res->getInt("age");
            // 创建对象并将数据封装进去
             //User obj(id, name, age);
            // 将对象存储到合适的数据结构中，比如vector或map
        }

        // 释放资源
        delete res;
        delete stmt;
        delete con;
	}

};

