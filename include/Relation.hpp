#ifndef RELATION_HPP
#define RELATION_HPP

#include "Person.hpp"

// 人际关系类Relation
// 很像某可恶的Meeting呢

enum Relationship { none, myself, father, mother, brother, sister, grandfather, grandmother, son, daughter, grandson, granddaughter};

class Relation {
private:
    // dst is the rel of src.
	Person &src, &dst;
    Relationship rel;

public:
    Relation(Person &r_src, Person &r_dst, Relationship r_rel);
    Person &getSrc();
    void setSrc(Person &r_src);
    Person &getDst();
    void setDst(Person &r_dst);
    Relationship getRel();
    void setRel(Relationship &r_rel);
};

#endif