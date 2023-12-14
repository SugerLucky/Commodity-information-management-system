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



public:
    Dao() {
        
        
        

    }

    ~Dao() {
        
    }


    void connect() {
        try {
        // 建立连接
            mysqlx::Session sess("localhost", 3306, "root", "123456", "goods_system");

            // 执行参数化查询
            //mysqlx::RowResult res = sess.sql("SELECT * FROM your_table WHERE id = :paramValue1 AND name = :paramValue2")
            //    .bind("paramValue1", paramValue1)
            //    .bind("paramValue2", paramValue2)
            //    .execute();
        

            //// 解析数据
            //while (mysqlx::Row row = res.fetchOne()) {
            //    // 处理查询结果
            //}
        
            // 关闭连接
            sess.close();
        } catch (const mysqlx::Error &err) {
            std::cerr << "Error: " << err << std::endl;
        }
    }

    /*公共获取数据函数*/

    bool check(const string& username, const string& password, int role) {
        try {
            // 建立连接
            mysqlx::Session sess("localhost", 33060, "root", "123456", "goods_system");

            cout << "数据库连接成功" << endl;

            // 执行参数化查询
            mysqlx::RowResult res;
            if (role == 1) {
                res = sess.sql("SELECT * FROM administrator").execute();
            }
            else {
                res = sess.sql("SELECT * FROM client").execute();
            }

            //mysqlx::RowResult res = sess.sql("SELECT * FROM your_table WHERE username = :paramValue1 AND password = :paramValue2")
            //    .bind("paramValue1", username)
            //    .bind("paramValue2", password)
            //    .execute();


            // 解析数据
            while (mysqlx::Row row = res.fetchOne()) {
                // 处理查询结果
                string user = row.get(2).get<std::string>();
                string pwd = row.get(3).get<std::string>();
                if (user == username && pwd == password) {
                    return true;
                }
            }
            // 关闭连接
            sess.close();
        }
        catch (const mysqlx::Error& err) {
            std::cerr << "Error: " << err << std::endl;
        }

        return false;
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


        return result;
    }

    void purchase(int id, int num) {

    }

    /*Administrator特有的数据获取函数*/



};

