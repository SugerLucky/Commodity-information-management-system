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
        ofstream file(T::getFileName(), ios::out | ios::binary);
        if (file.is_open()) {
            file.write(reinterpret_cast<const char*>(&obj), sizeof(T));
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
        ifstream file(T::getFileName(), ios::in | ios::binary);
        if (file.is_open()) {
            while (!file.eof()) {
                T obj;
                file.read(reinterpret_cast<char*>(&obj), sizeof(T));
                if (file.gcount() == sizeof(T)) {
                    objects.push_back(obj);
                }
            }
            file.close();
        }
        else {
            cerr << "Error: Unable to open file for reading: " << T::getFileName() << endl;
        }
        return objects;
    }
};

