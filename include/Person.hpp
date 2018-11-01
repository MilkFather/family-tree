#ifndef PERSON_HPP
#define PERSON_HPP

#include <string>

// 一个人。没错，就是一个人。有名有姓有性别的人。

using std::string;

enum Gender = {Male, Female};

class Person {
public:
    Person(string name, Gender gender);
    string getName();
    void setName(string name);
    Gender getGender();
    void setGender(Gender gender);
    
private:
    string p_name;
    Gender p_gender;
};

#endif
