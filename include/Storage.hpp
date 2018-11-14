#ifndef STORAGE_HPP
#define STORAGE_HPP

#include <memory>
#include <list>
#include <vector>
#include "Person.hpp"
#include "Relation.hpp"

using std::list;
using std::vector;
using std::string;
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

    void LoadPersons();
    void LoadRelations();

    void RegenerateMatrix();
    void CalculateRelation();
    
public:
    static shared_ptr<Storage> getInstance(void);
    ~Storage();

    //void AddPerson()
    
private:
    static shared_ptr<Storage> m_instance;
    vector<Person> m_persons;
    vector<Relation> m_metarelations;
    Relation **relationMatrix;
    bool m_dirty;
    vector<int>a;
};

#endif
