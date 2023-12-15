#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
#include <algorithm>

using namespace std;

// ÿ�������Ӧһ���ļ����ļ���Ϊ���������
class FileStorage {
public:
    template<typename T>
    static void save(const T& obj) {
        ofstream file(T::getFileName(), ios::app);
        if (file.is_open()) {
            file << obj.toString() << endl;
        }
    }

    template<typename T>
    static vector<string> loadAll() {
        vector<string> result;
        string line;
        ifstream file(T::getFileName());
        if (file.is_open()) {
            while (getline(file, line)) {
                result.push_back(line);
            }
        }
        return result;
    }
};

