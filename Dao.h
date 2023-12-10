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
* 数据访问层（Data Access Object）：负责数据访问的操作，增删改查等
* 拿到数据库的数据返回给业务处理层
*/
class Dao
{
	//连接MySQL数据库
	void connect() {
        // 连接到MySQL数据库
        sql::Driver* driver;
        sql::Connection* con;
        driver = get_driver_instance();
        con = driver->connect("tcp://127.0.0.1:3306", "username", "password");
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


	//


};

