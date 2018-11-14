#include "Storage.hpp"
#include <vector>
#include <string>
#include <exception>
#include "CSV.hpp"
#include "Path.hpp"
#include "Person.hpp"
#include "Relation.hpp"

using std::vector;
using std::list;
using std::string;

// Storage类的实现

shared_ptr<Storage> Storage::getInstance(void) {
    if (m_instance == nullptr) {
        m_instance = shared_ptr<Storage>(new Storage());
    }
    return m_instance;
}

Storage::Storage() {
    LoadPersons();
    LoadRelations();
    RegenerateMatrix();
}

// TODO
void Storage::LoadPersons() {
    vector<vector<string> > persons = CSV::openFile(Path::peoplePath);
    for (int i = 0; i < persons.size(); i++) {
        vector<string> person = persons[i];
        if (person.size() != 3)
            continue;  // bad data skip
        string s_name = person[0], s_gender = person[1], s_age = person[2];
        // convert s_name to string
        // convert s_gender to Gender
        // convert s_age to int

        // skip on any error
    }
    // list add new person
}

// TODO
void Storage::LoadRelations() {
    vector<vector<string> > relations = CSV::openFile(Path::metaBioPath);
    for (int i = 0; i < relations.size(); i++) {
        vector<string> relation = relations[i];
        if (relation.size() != 3)
            continue;  // bad data skip
        string s_srcname = relation[0], s_dstname = relation[1], s_rel = relation[2];
        // check the srcname and the dstname all exists in persons
        // if not skip
        // check the relation is legal, see RelationshipParser.cpp for a full list of relations
        // if not skip
    }
    // list add new relation
}

// TODO
void Storage::RegenerateMatrix() {
    relationMatrix = new Relation* [m_persons.size() * m_persons.size];
    // Pre-fill all relations as nullptr
    for (int i = 0; i < m_persons.size(); i++) {
        for (int j = 0; j < m_persons.size(); j++) {
            relationMatrix[i * m_persons.size() + j] = nullptr;
        }
    }
    // Map each relation into its place
}

void Storage::CalculateRelation() {

}