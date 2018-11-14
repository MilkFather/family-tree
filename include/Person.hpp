#ifndef PERSON_HPP
#define PERSON_HPP

#include <string>

// 一个人。没错，就是一个人。有名有姓有性别的人。

using std::string;

enum Gender { Male, Female };

Gender Str2Gen(string s);
string Gen2Str(Gender s);

class Person {
public:
    Person(string name, Gender gender, int age);
    string getName() const;
    void setName(string name);
    Gender getGender() const;
    void setGender(Gender gender);
    int getAge() const;
    void setAge(int age);

    bool operator==(Person &rhs);
    bool operator!=(Person &rhs);
    Person operator=(Person &rhs);
    
private:
    string p_name;
    Gender p_gender;
    int p_age;
};

#endif
