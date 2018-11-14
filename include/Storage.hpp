#ifndef STORAGE_HPP
#define STORAGE_HPP

#include <memory>
#include <list>
#include <vector>
#include <functional>
#include "Person.hpp"
#include "Relation.hpp"

using std::list;
using std::vector;
using std::string;
using std::function;
// 负责数据存储的Storage类
// 看得眼熟?
// 毕竟, 这就是仿照Agenda的模式写的项目嘛

using std::shared_ptr;

class Storage {
private:
    Storage();
    Storage(const Storage &t_another) = delete;
    void operator=(const Storage &t_another) = delete;

    int FlattenTo1D(int row, int col);

    int findPersonIndex(string);
    Person findPersonByName(string);
    Relation findRelationByName(string, string) const;

    void LoadPersons();
    void LoadRelations();

    void SavePersons();
    void SaveRelations();

    void RegenerateMatrix();
    void CalculateRelation();
    
public:
    static shared_ptr<Storage> getInstance(void);
    ~Storage();

    void AddPerson(const Person &p);
    void DeletePerson(function<bool(const Person &)> filter);
    list<Person> QueryPerson(function<bool(const Person &)> filter) const;

    void AddRelation(const Relation &p);
    void DeleteRelation(function<bool(const Relation &)> filter);
    list<Relation> QueryRelation(function<bool(const Relation &)> filter) const;

    void sync();
    
private:
    static shared_ptr<Storage> m_instance;
    list<Person> m_persons;
    list<Relation> m_metarelations;
    list<Relation> m_deducedrelations;
    //Relation **relationMatrix;
    bool *relationMatrix;
};

#endif
