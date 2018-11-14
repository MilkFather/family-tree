#include "Storage.hpp"
#include <vector>
#include <string>
#include <exception>
#include "CSV.hpp"
#include "Path.hpp"
#include "Person.hpp"
#include "Relation.hpp"
#include "RelationshipParser.hpp"

using std::vector;
using std::list;
using std::string;
using std::exception;
using std::stoi;
using std::to_string;

// Storage类的实现

shared_ptr<Storage> Storage::m_instance = nullptr;

shared_ptr<Storage> Storage::getInstance(void) {
    if (m_instance == nullptr) {
        m_instance = shared_ptr<Storage>(new Storage());
    }
    return m_instance;
}

Storage::Storage() {
    relationMatrix = nullptr;
    LoadPersons();
    LoadRelations();
    RegenerateMatrix();
    CalculateRelation();
}

Storage::~Storage() {
    sync();
}

int Storage::FlattenTo1D(int row, int col) {
    return row * this->m_persons.size() + col;
}

int Storage::findPersonIndex(string name) {
    int result = -1;
    for (auto p : this->m_persons) {
        result++;
        if (p.getName() == name) {
            return result;
        }
    }
    return -1;
}

Person Storage::findPersonByName(string name) {
    for (auto p : this->m_persons) {
        if (p.getName() == name) {
            return p;
        }
    }
    return Person("", Male, 0);
}

void Storage::LoadPersons() {
    vector<vector<string> > persons = CSV::openFile(Path::peoplePath);
    for (int i = 0; i < persons.size(); i++) {
        vector<string> person = persons[i];
        if (person.size() != 3)
            continue;  // bad data skip
        string s_name = person[0], s_gender = person[1], s_age = person[2];
        Gender g = Str2Gen(s_gender);
        int a = stoi(s_age);
        m_persons.push_back(Person(s_name, g, a));
    }
}

void Storage::LoadRelations() {
    vector<vector<string> > relations = CSV::openFile(Path::metaBioPath);
    for (int i = 0; i < relations.size(); i++) {
        vector<string> relation = relations[i];
        if (relation.size() != 3)
            continue;  // bad data skip
        string s_srcname = relation[0], s_dstname = relation[1], s_rel = relation[2];
        Person src = findPersonByName(s_srcname);
        Person dst = findPersonByName(s_dstname);
        Relation rel(src, dst, Str2Rel(s_rel));

        m_metarelations.push_back(rel);
    }
}

void Storage::SavePersons() {
    vector<vector<string> > persons;
    for (auto p : m_persons) {
        vector<string> v;
        v.push_back(p.getName());
        v.push_back(Gen2Str(p.getGender()));
        v.push_back(to_string(p.getAge()));
        persons.push_back(v);
    }
    CSV::writeFile(persons, Path::peoplePath);
}

void Storage::SaveRelations() {
    vector<vector<string> > relations;
    for (auto r : m_metarelations) {
        vector<string> v;
        v.push_back(r.getSrc().getName());
        v.push_back(r.getDst().getName());
        v.push_back(Rel2Str(r.getRel()));
        relations.push_back(v);
    }
    CSV::writeFile(relations, Path::metaBioPath);
}

void Storage::RegenerateMatrix() {
    if (relationMatrix != nullptr) delete [] relationMatrix;
    //if (relationMatrix != nullptr) free(relationMatrix);
    m_deducedrelations.clear();
    relationMatrix = new bool [m_persons.size() * m_persons.size()];
    //relationMatrix = (Relation **)malloc(sizeof(Relation*) * m_persons.size() * m_persons.size());
    // Pre-fill all relations as nullptr
    for (int i = 0; i < m_persons.size(); i++) {
        for (int j = 0; j < m_persons.size(); j++) {
            relationMatrix[i * m_persons.size() + j] = false;
        }
    }
    // Map each relation into its place
    for (auto r : this->m_metarelations) {
        int srcpos = findPersonIndex(r.getSrc().getName());
        int dstpos = findPersonIndex(r.getDst().getName());
        relationMatrix[FlattenTo1D(srcpos, dstpos)] = true;
    }
    // The matrix is self-reflexive
    for (auto p : m_persons) {
        Relation selfrel(p, p, myself);
        m_deducedrelations.push_back(selfrel);
        int pos = findPersonIndex(p.getName());
        relationMatrix[FlattenTo1D(pos, pos)] = true;
    }
}

void Storage::CalculateRelation() {
    // run for 4 times
    for (int i = 0; i < 3; i++) {
        // for every row and exery column...
        for (auto src : m_persons) {
            for (auto dest : m_persons) {
                for (auto mid : m_persons) {
                    int srcpos = findPersonIndex(src.getName());
                    int destpos = findPersonIndex(dest.getName());
                    int midpos = findPersonIndex(mid.getName());
                    if (srcpos == destpos || destpos == midpos || midpos == srcpos)
                        continue;   // no reference to oneself
                    if (relationMatrix[FlattenTo1D(srcpos, destpos)] == true)
                        continue;   // relation already exists
                    if (relationMatrix[FlattenTo1D(srcpos, midpos)] == false || relationMatrix[FlattenTo1D(midpos, destpos)] == false)
                        continue;   // no bridge

                    // we now deduce.
                    try {
                        string srcname = src.getName(), midname = mid.getName(), dstname = dest.getName();
                        RelationshipParser parse(findRelationByName(srcname, midname).getRel(), src.getGender());
                        parse.elevateRelation(findRelationByName(midname, dstname).getRel());
                        Relation newrel(src, dest, parse.getRelationship());
                        this->m_deducedrelations.push_back(newrel);
                        relationMatrix[FlattenTo1D(srcpos, destpos)] = true;
                    } catch (const exception e) {}
                }
            }
        }
    }
}

void Storage::AddPerson(const Person &p) {
    m_persons.push_back(p);
    RegenerateMatrix();
    CalculateRelation();
}

void Storage::DeletePerson(function<bool(const Person &)> filter) {
    bool flag = false;
    for (auto it = this->m_persons.begin(); it != this->m_persons.end(); ) {
        if (filter(*it) == true) {
            it = this->m_persons.erase(it);
            flag = true;
        } else {
            ++it;
        }
    }
    if (flag) {
        RegenerateMatrix();
        CalculateRelation();
    }
}

list<Person> Storage::QueryPerson(function<bool(const Person &)> filter) const {
    list<Person> res;
    list<Person>::const_iterator it = this->m_persons.cbegin();
    for (; it != this->m_persons.cend(); it++) {
        if (filter(*it) == true) {
            res.push_back(*it);
        }
    }
    return res;
}

void Storage::AddRelation(const Relation &p) {
    m_metarelations.push_back(p);
    RegenerateMatrix();
    CalculateRelation();
}

void Storage::DeleteRelation(function<bool(const Relation &)> filter) {
    bool flag = false;
    for (auto it = this->m_metarelations.begin(); it != this->m_metarelations.end(); ) {
        if (filter(*it) == true) {
            it = this->m_metarelations.erase(it);
            flag = true;
        } else {
            ++it;
        }
    }
    if (flag) {
        RegenerateMatrix();
        CalculateRelation();
    }
}

Relation Storage::findRelationByName(string n1, string n2) const {
    auto l = QueryRelation([n1, n2](const Relation& x){return x.getSrc().getName() == n1 && x.getDst().getName() == n2;});
    Relation r = *(l.begin());
    return r;
}

list<Relation> Storage::QueryRelation(function<bool(const Relation &)> filter) const {
    list<Relation> res;
    list<Relation>::const_iterator it = this->m_metarelations.cbegin();
    for (; it != this->m_metarelations.cend(); it++) {
        if (filter(*it) == true) {
            res.push_back(*it);
        }
    }
    list<Relation>::const_iterator it2 = this->m_deducedrelations.cbegin();
    for (; it2 != this->m_deducedrelations.cend(); it2++) {
        if (filter(*it2) == true) {
            res.push_back(*it2);
        }
    }
    return res;
}

void Storage::sync() {
    SavePersons();
    SaveRelations();
}
