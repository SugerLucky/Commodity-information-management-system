#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
#include <algorithm>

#include <nlohmann/json.hpp>

using namespace std;

//可以考虑使用更安全的序列化和反序列化方法，比如使用 C++ 的序列化库或者 JSON 序列化。

// 每个对象对应一个文件，文件名为对象的类名
class FileStorage {
public:
    // 保存单个对象到文件
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

    // 从文件加载所有对象到数组
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

