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

    // 从文件加载所有对象到数组
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
