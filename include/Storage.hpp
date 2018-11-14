#ifndef STORAGE_HPP
#define STORAGE_HPP

#include <memory>
#include <list>
#include "Person.hpp"
#include "Relation.hpp"

using std::list;

// 负责数据存储的Storage类
// 看得眼熟?
// 毕竟, 这就是仿照Agenda的模式写的项目嘛

using std::shared_ptr;

class Storage {
private:
    Storage();
    Storage(const Storage &t_another) = delete;
    void operator=(const Storage &t_another) = delete;

    void LoadPersons();
    void LoadRelations();

    void RegenerateMatrix();
    void CalculateRelation();
    
public:
    static shared_ptr<Storage> getInstance(void);
    ~Storage();
    
private:
    static shared_ptr<Storage> m_instance;
    list<Person> m_persons;
    list<Relation> m_metarelations;
    Relation **relationMatrix;
    bool m_dirty;
};

#endif
