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
        //con = driver->connect("localhost", "root", "123456"); //����һ����ʾ�����ݿ�����ӵĶ��󣬸ö�������������ݿ��ͨ���������Ϣ
        

        try {
            //sql::ConnectOptionsMap connection_properties;
            //connection_properties["OPT_MULTI_HOST"] = "true";
            //con = driver->connect(connection_properties);
            
            // �������ݿ����ӵĴ���
            con = driver->connect("tcp://127.0.0.1:3306", "root", "123456");

            // �������ݿ����
        }
        catch (sql::SQLException& e) {
            std::cout << "MySQL Error: " << e.what() << std::endl;
            // ����������
        }

        con->setSchema("goods_system");
    }

    ~Dao() {
        delete con; //�ͷ�������Դ
    }


    void connect() {
        try {
        // ׼������
        int paramValue = 123;

        // ��������
        mysqlx::Session sess("host", 33060, "user", "password", "schema");

        // ִ�в�������ѯ
        mysqlx::SqlStatement stmt = sess.sql("SELECT * FROM your_table WHERE id = :paramValue");
        stmt.bind("paramValue", paramValue);
        mysqlx::SqlResult res = stmt.execute();

        // ��������
        while (mysqlx::Row row = res.fetchOne()) {
            // �����ѯ���
        }
        
        // �ر�����
        sess.close();
    } catch (const mysqlx::Error &err) {
        std::cerr << "Error: " << err << std::endl;
    }
    }



    /*������ȡ���ݺ���*/

    bool check(const string& username, const string& password, int role) {
        try {
            sql::PreparedStatement* prep_stmt;
            /*
            PreparedStatement �����ݿ����е�һ����Ҫ������ṩ��һ��Ԥ���� SQL ���Ļ��ƣ�������Ч��ִ�в�������ѯ�������ִ������ SQL ����Ч�ʺͰ�ȫ�ԡ�

            �� C++ �У�����һЩ���ݿ����ӿ⣬���� MySQL C++ Connector��PreparedStatement ������ִ�д��в����� SQL ��ѯ�����ࡣͨ��Ԥ���� SQL ��䲢�󶨲��������Լ��� SQL ע��ķ��գ���������˶��ִ����ͬ��ѯ��Ч�ʡ�

            ��Ԥ����֮�󣬿���ͨ�����ò���ֵ��ִ�� SQL ��ѯ������ PreparedStatement ����ִ��ʱ������ֵ����Ԥ����� SQL ����У��Ӷ�ִ�о���Ĳ�ѯ���������ֻ��Ʋ�������������ܣ������Ա����ֶ�ƴ�� SQL ����������İ�ȫ���ա�

            ��֮��PreparedStatement ��һ������ִ�д��в�����Ԥ���� SQL ��ѯ���Ļ��ƣ��������ݿ�����������Ҫ�����á�
            */
            sql::ResultSet* res;
            /*
            ResultSet �����ݿ�����������ʾִ�в�ѯ�󷵻صĽ������һ����Ҫ����� C++ ��һЩ���ݿ����ӿ��У����� MySQL C++ Connector��ResultSet ��һ���࣬������ʾ���ݿ��ѯ�Ľ������

            һ��ִ���˲�ѯ������ͨ����õ�һ�� ResultSet ���������������˲�ѯ���ص������С�ͨ�� ResultSet ���󣬿������л�ȡ��ѯ��������Ҵ�����Щ���ݣ�������ȡ����е��ֶ�ֵ��ִ�оۺϲ��������߽�����������ɱ���ȡ�

            ResultSet �����ṩ��һϵ�еķ��������������ʹ����ѯ�����ͨ����Щ���������Ա������������ȡ�ض��е�ֵ���������ݲ����ȡ��ڴ�����������ͨ����Ҫ�ֶ��ͷ� ResultSet �������ͷ������Դ��
    
            ��֮��ResultSet ��һ��������ʾ���ݿ��ѯ��������࣬�������ݿ����а�������Ҫ�Ľ�ɫ�����ڻ�ȡ��ѯ�Ľ����������Ӧ�Ĳ�����
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

    /*Client���е����ݻ�ȡ����*/

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

    /*Administrator���е����ݻ�ȡ����*/








	//void connect() {
 //       // ���ӵ�MySQL���ݿ�
 //       sql::Driver* driver;
 //       sql::Connection* con;
 //       driver = get_driver_instance();
 //       con = driver->connect("localhost", "username", "password");
 //       con->setSchema("your_database");

 //       // ִ��SQL��ѯ
 //       sql::Statement* stmt;
 //       sql::ResultSet* res;
 //       stmt = con->createStatement();
 //       res = stmt->executeQuery("SELECT id, name, age FROM your_table");

 //       // ��װ���ݵ�����
 //       while (res->next()) {
 //           int id = res->getInt("id");
 //           std::string name = res->getString("name");
 //           int age = res->getInt("age");
 //           // �������󲢽����ݷ�װ��ȥ
 //            //User obj(id, name, age);
 //           // ������洢�����ʵ����ݽṹ�У�����vector��map
 //       }

 //       // �ͷ���Դ
 //       delete res;
 //       delete stmt;
 //       delete con;
	//}

};

