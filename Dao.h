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



public:
    Dao() {
        
        
        

    }

    ~Dao() {
        
    }


    void connect() {
        try {
        // ��������
            mysqlx::Session sess("localhost", 3306, "root", "123456", "goods_system");

            // ִ�в�������ѯ
            //mysqlx::RowResult res = sess.sql("SELECT * FROM your_table WHERE id = :paramValue1 AND name = :paramValue2")
            //    .bind("paramValue1", paramValue1)
            //    .bind("paramValue2", paramValue2)
            //    .execute();
        

            //// ��������
            //while (mysqlx::Row row = res.fetchOne()) {
            //    // �����ѯ���
            //}
        
            // �ر�����
            sess.close();
        } catch (const mysqlx::Error &err) {
            std::cerr << "Error: " << err << std::endl;
        }
    }

    /*������ȡ���ݺ���*/

    bool check(const string& username, const string& password, int role) {
        try {
            // ��������
            mysqlx::Session sess("localhost", 33060, "root", "123456", "goods_system");

            cout << "���ݿ����ӳɹ�" << endl;

            // ִ�в�������ѯ
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


            // ��������
            while (mysqlx::Row row = res.fetchOne()) {
                // �����ѯ���
                string user = row.get(2).get<std::string>();
                string pwd = row.get(3).get<std::string>();
                if (user == username && pwd == password) {
                    return true;
                }
            }
            // �ر�����
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

    /*Client���е����ݻ�ȡ����*/

    vector<Order> browseOrder() {
        vector<Order> result;


        return result;
    }

    void purchase(int id, int num) {

    }

    /*Administrator���е����ݻ�ȡ����*/



};

