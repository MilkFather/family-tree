#include "Service.hpp"
#include "Person.hpp"
#include "Relation.hpp"

#include <list>
#include <iostream>

using std::list;
using std::cout;
using std::endl;

int main() {
    Service s;
    s.addPerson("Kevin", Male, 19);
    s.addPerson("Lemon", Male, 48);
    s.addPerson("Gao", Male, 81);
    s.addPerson("Dx", Female, 50);
    s.addPerson("Bow", Male, 19);
    s.addRelation("Kevin", "Lemon", father);
    s.addRelation("Lemon", "Kevin", son);
    s.addRelation("Lemon", "Gao", father);
    s.addRelation("Gao", "Lemon", son);
    s.addRelation("Dx", "Gao", father);
    s.addRelation("Gao", "Dx", daughter);
    s.addRelation("Dx", "Bow", son);
    s.addRelation("Bow", "Dx", mother);
    
    auto l = s.listRelations("Kevin");
    for (auto p : l) {
        cout << p.getSrc().getName() << " has a " << Rel2Str(p.getRel()) << ": " << p.getDst().getName() << endl;
    }
    auto ll = s.listRelations("Lemon");
    for (auto p : ll) {
        cout << p.getSrc().getName() << " has a " << Rel2Str(p.getRel()) << ": " << p.getDst().getName() << endl;
    }
    return 0;
}
