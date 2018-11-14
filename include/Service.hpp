#ifndef SERVICE_HPP
#define SERVICE_HPP

#include "Storage.hpp"
#include "Person.hpp"
#include "Relation.hpp"

#include <list>
#include <string>
#include <memory>

using std::string;
using std::list;
using std::shared_ptr;


class Service {
public:
    Service();
    ~Service();
    list<Person> allPerson() const;
    Person findPerson(string name);
    void addPerson(string name, Gender g, int age);
    void deletePerson(string name);

    list<Relation> listRelations(string name) const;
    void addRelation(string src, string dst, Relationship rel);
    void deleteRelation(string src, string dst);

private:
    shared_ptr<Storage> m_storage;

};

#endif
