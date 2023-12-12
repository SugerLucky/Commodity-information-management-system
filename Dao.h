#pragma once
#include <mysql/jdbc.h>
#include <mysqlx/xdevapi.h>
using namespace std;
//using namespace mysqlx;

//#include <jdbc/cppconn/resultset.h>
//#include <jdbc/cppconn/statement.h>
//#include <jdbc/mysql_connection.h>
//#include <jdbc/mysql_driver.h>
//#include <jdbc/cppconn/exception.h>
//#include <jdbc/cppconn/prepared_statement.h>

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
        //con = driver->connect("localhost", "root", "123456"); //返回一个表示与数据库的连接的对象，该对象包含了与数据库的通信所需的信息
        

        try {
            //sql::ConnectOptionsMap connection_properties;
            //connection_properties["OPT_MULTI_HOST"] = "true";
            //con = driver->connect(connection_properties);
            
            // 进行数据库连接的代码
            con = driver->connect("tcp://127.0.0.1:3306", "root", "123456");

            // 其他数据库操作
        }
        catch (sql::SQLException& e) {
            std::cout << "MySQL Error: " << e.what() << std::endl;
            // 其他错误处理
        }

        con->setSchema("goods_system");
    }

    ~Dao() {
        delete con; //释放连接资源
    }


    void connect() {
        try {
        // 准备参数
        int paramValue = 123;

        // 建立连接
        mysqlx::Session sess("host", 33060, "user", "password", "schema");

        // 执行参数化查询
        mysqlx::SqlStatement stmt = sess.sql("SELECT * FROM your_table WHERE id = :paramValue");
        stmt.bind("paramValue", paramValue);
        mysqlx::SqlResult res = stmt.execute();

        // 解析数据
        while (mysqlx::Row row = res.fetchOne()) {
            // 处理查询结果
        }
        
        // 关闭连接
        sess.close();
    } catch (const mysqlx::Error &err) {
        std::cerr << "Error: " << err << std::endl;
    }
    }



    /*公共获取数据函数*/

    bool check(const string& username, const string& password, int role) {
        try {
            sql::PreparedStatement* prep_stmt;
            /*
            PreparedStatement 是数据库编程中的一个重要概念，它提供了一种预编译 SQL 语句的机制，可以有效地执行参数化查询，提高了执行相似 SQL 语句的效率和安全性。

            在 C++ 中，对于一些数据库连接库，比如 MySQL C++ Connector，PreparedStatement 是用来执行带有参数的 SQL 查询语句的类。通过预编译 SQL 语句并绑定参数，可以减少 SQL 注入的风险，并且提高了多次执行相同查询的效率。

            在预编译之后，可以通过设置参数值来执行 SQL 查询，并且 PreparedStatement 会在执行时将参数值填入预编译的 SQL 语句中，从而执行具体的查询操作。这种机制不仅可以提高性能，还可以避免手动拼接 SQL 语句所带来的安全风险。

            总之，PreparedStatement 是一种用于执行带有参数的预编译 SQL 查询语句的机制，它在数据库编程中起到了重要的作用。
            */
            sql::ResultSet* res;
            /*
            ResultSet 是数据库编程中用来表示执行查询后返回的结果集的一个重要概念。在 C++ 的一些数据库连接库中，比如 MySQL C++ Connector，ResultSet 是一个类，用来表示数据库查询的结果集。

            一旦执行了查询操作，通常会得到一个 ResultSet 对象，这个对象包含了查询返回的数据行。通过 ResultSet 对象，可以逐行获取查询结果，并且处理这些数据，比如提取结果中的字段值、执行聚合操作、或者将结果用于生成报表等。

            ResultSet 对象提供了一系列的方法，用来操作和处理查询结果。通过这些方法，可以遍历结果集、获取特定列的值、进行数据操作等。在处理完结果集后，通常需要手动释放 ResultSet 对象以释放相关资源。
    
            总之，ResultSet 是一个用来表示数据库查询结果集的类，它在数据库编程中扮演了重要的角色，用于获取查询的结果并进行相应的操作。
            */
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

    void _register(string username, string password, int role) {
        
    }

    vector<Commodity> browseGoods() {
        vector<Commodity> res;




        return res;
    }

    Commodity searchGoods(int id) {
        Commodity goods;




        return goods;
    }

    /*Client特有的数据获取函数*/

    vector<Order> browseOrder() {
        vector<Order> result;
        try {
            //sql::Driver* driver;
            //sql::Connection* con;
            sql::Statement* stmt;
            sql::ResultSet* res;

            //driver = get_driver_instance();
            //con = driver->connect("tcp://127.0.0.1:3306", "username", "password");
            //con->setSchema("your_database");

            stmt = con->createStatement();
            res = stmt->executeQuery("SELECT id, create_time FROM items");

            while (res->next()) {
                Order order;
                //order.setCreateTime(res->getDateTime("create_time"));
                // Use the item object with the retrieved create time
            }

            delete res;
            delete stmt;
            delete con;
        }
        catch (sql::SQLException& e) {
            // Handle SQL exception
        }

        return result;
    }

    void purchase(int id, int num) {

    }

    /*Administrator特有的数据获取函数*/








	//void connect() {
 //       // 连接到MySQL数据库
 //       sql::Driver* driver;
 //       sql::Connection* con;
 //       driver = get_driver_instance();
 //       con = driver->connect("localhost", "username", "password");
 //       con->setSchema("your_database");

 //       // 执行SQL查询
 //       sql::Statement* stmt;
 //       sql::ResultSet* res;
 //       stmt = con->createStatement();
 //       res = stmt->executeQuery("SELECT id, name, age FROM your_table");

 //       // 封装数据到对象
 //       while (res->next()) {
 //           int id = res->getInt("id");
 //           std::string name = res->getString("name");
 //           int age = res->getInt("age");
 //           // 创建对象并将数据封装进去
 //            //User obj(id, name, age);
 //           // 将对象存储到合适的数据结构中，比如vector或map
 //       }

 //       // 释放资源
 //       delete res;
 //       delete stmt;
 //       delete con;
	//}

};

