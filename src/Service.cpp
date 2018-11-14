#include "Service.hpp"

#include <functional>

using std::function;

Service::Service() {
    m_storage = Storage::getInstance();
}

Service::~Service() {
    m_storage->sync();
}

list<Person> Service::allPerson() const {
    return m_storage->QueryPerson([](const Person &x) {return true;});
}

Person Service::findPerson(string name) {
    auto l = m_storage->QueryPerson([name](const Person &x) {if (x.getName() == name) return true; else return false;});
    return *(l.begin());
}

void Service::addPerson(string name, Gender g, int age) {
    m_storage->AddPerson(Person(name, g, age));
}

void Service::deletePerson(string name) {
    m_storage->DeletePerson([name](const Person &x) {if (x.getName() == name) return true; else return false;});
}

list<Relation> Service::listRelations(string name) const {
    return m_storage->QueryRelation([name](const Relation &x) {if (x.getSrc().getName() == name) return true; else return false;});
}

void Service::deleteRelation(string src, string dst) {
    m_storage->DeleteRelation([src, dst](const Relation &x) {if (x.getSrc().getName() == src && x.getDst().getName() == dst) return true; else return false;});
}

void Service::addRelation(string src, string dst, Relationship rel) {
    m_storage->AddRelation(Relation(findPerson(src), findPerson(dst), rel));
}
