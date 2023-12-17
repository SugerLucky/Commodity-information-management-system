#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
#include <algorithm>

#include <nlohmann/json.hpp>
using namespace std;

//���Կ���ʹ�ø���ȫ�����л��ͷ����л�����������ʹ�� C++ �����л������ JSON ���л���

// ÿ�������Ӧһ���ļ����ļ���Ϊ���������
class FileStorage {
public:
    // ���浥�������ļ�
    template <typename T>
    static bool save(const T& obj) {
        ofstream file(T::getFileName());
        if (file.is_open()) {
            nlohmann::json j;
            obj.serialize(j);
            file << j.dump(4);
            file.close();
            return true;
        }
        else {
            cerr << "Error: Unable to open file for writing: " << T::getFileName() << endl;
            return false;
        }
    }

    // ���ļ��������ж�������
    template <typename T>
    static vector<T> loadAll() {
        vector<T> objects;
        ifstream file(T::getFileName());
        if (file.is_open()) {
            nlohmann::json j;
            file >> j;
            file.close();
            if (!j.is_null()) {
                if (j.is_array()) {
                    for (const auto& item : j) {
                        T obj;
                        obj.deserialize(item);
                        objects.push_back(obj);
                    }
                }
                else {
                    T obj;
                    obj.deserialize(j);
                    objects.push_back(obj);
                }
            }
        }
        else {
            cerr << "Error: Unable to open file for reading: " << T::getFileName() << endl;
        }
        return objects;
    }
};
