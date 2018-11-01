#include "Person.hpp"

// Person类的实现
// 这么简单的类还有什么实现的必要吗?

Person::Person(string name, Gender gender) {
    p_name = name;
    p_gender = gender;
}

string getName() {
    return p_name;
}

void setName(string name) {
    if (p_name != name) {
        p_name = name;
    }
}

Gender getGender() {
    return p_gender;
}

void setGender(Gender gender) {
    if (p_gender != gender) {
        p_gender = gender;
    }
}
