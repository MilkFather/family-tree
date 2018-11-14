#ifndef RELATION_HPP
#define RELATION_HPP

#include "Person.hpp"
#include <string>

using std::string;

// 人际关系类Relation
// 很像某可恶的Meeting呢

enum Relationship { none, myself, father, mother, 
                    brother, sister, grandfather, grandmother, 
                    son, daughter, 
                    grandson_son, granddaughter_son, 
                    grandson_daughter, granddaughter_daughter,
                    aunt, uncle, 
                    nephew_brother, niece_brother,
                    nephew_sister, niece_sister,
                    nephew_aunt, niece_aunt,
                    nephew_uncle, niece_uncle,
                    wife, husband };

Relationship Str2Rel(string s);
string Rel2Str(Relationship s);

class Relation {
private:
    // dst is the rel of src.
	Person src, dst;
    Relationship rel;

public:
    Relation(Person r_src, Person r_dst, Relationship r_rel): src(r_src), dst(r_dst), rel(r_rel) {};
    Person getSrc() const;
    void setSrc(Person &r_src);
    Person getDst() const;
    void setDst(Person &r_dst);
    Relationship getRel() const;
    void setRel(Relationship &r_rel);
};

#endif
