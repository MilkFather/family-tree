#include "Person.hpp"

// Person类的实现
// 这么简单的类还有什么实现的必要吗?

Person::Person(string name, Gender gender, int age) {
    p_name = name;
    p_gender = gender;
    p_age = age;
}

string Person::getName() const {
    return p_name;
}

void Person::setName(string name) {
    if (p_name != name) {
        p_name = name;
    }
}

Gender Person::getGender() const {
    return p_gender;
}

void Person::setGender(Gender gender) {
    if (p_gender != gender) {
        p_gender = gender;
    }
}

int Person::getAge() const {
    return p_age;
}

void Person::setAge(int age) {
    if (p_age != age) {
        p_age = age;
    }
}

bool Person::operator==(Person &rhs) {
    return (p_name == rhs.p_name && p_gender == rhs.p_gender && p_age == rhs.p_age);
}

bool Person::operator!=(Person &rhs) {
    return !((*this) == rhs);
}

Person Person::operator=(Person &rhs) {
    p_name = rhs.p_name;
    p_gender = rhs.p_gender;
    p_age = rhs.p_age;

    return *this;
}

Gender Str2Gen(string s) {
    if (s == "male") return Male;
    if (s == "female") return Female;
    return Male;
}

string Gen2Str(Gender s) {
    if (s == Male) return "male";
    if (s == Female) return "female";
    return "male";
}
