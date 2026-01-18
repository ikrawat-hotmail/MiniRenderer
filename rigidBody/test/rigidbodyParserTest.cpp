#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <memory>
#include <cstring>
#include <cstdlib>


extern "C" {
    #include "sj.h"
}


// Helper function to extract string from sj_Value
std::string extractString(sj_Value val) {
    return std::string(val.start, val.end - val.start);
}

// Helper function to extract double from sj_Value
float extractNumber(sj_Value val) {
    std::string numStr(val.start, val.end - val.start);
    return std::stof(numStr);
}

// Helper function to compare string keys
bool keyEquals(sj_Value key, const char* str) {
    size_t len = strlen(str);
    if ((size_t)(key.end - key.start) != len)
        return false;
    return strncmp(key.start, str, len) == 0;
}


int rigidBodyParseFromJson(std::string& jsonStr) {

    // clean me
    // for each hirarchy of objects, there will be a separate file
    std::string jsonData(jsonStr);

    // ig this uses length of string being parsed at a time
    sj_Reader reader = sj_reader(&jsonData[0], jsonData.size());

    // root object
    sj_Value arr = sj_read(&reader);
    if (arr.type != SJ_ARRAY) {
        std::cout << "Error: Expected root object\n";
        std::cout << "Error: Expected root object : SJ_TYPE: " << arr.type << std::endl;
        return 1;
    } else {
        std::cout << "This works\n";
    }

    // Parse object fields
    sj_Value obj;
    while (sj_iter_array(&reader, arr, &obj)) {
        if (obj.type != SJ_OBJECT) {
            std::cout << "Not object" << std::endl;
        } else {
            sj_Value shapeKey, shapeVal;
            while (sj_iter_object(&reader, obj, &shapeKey, &shapeVal)) {
                if (keyEquals(shapeKey, "id")) {
                    std::string s = extractString(shapeVal);
                    std::cout << "id: " << s << std::endl;
                } else if (keyEquals(shapeKey, "orientation")) {
                    float f = extractNumber(shapeVal);
                    std::cout << "orientation: " << f << std::endl;
                }
            }
        }
    }
    return 1;
}

int main() {
    std::string testJson = R"([
  { "id": "rigidBody1", "position": [10, 5], "orientation": 0.785 },
  { "id": "rigidBody2", "position": [20, 15], "orientation": 0.0 }
  ])";
    return rigidBodyParseFromJson(testJson);

}
