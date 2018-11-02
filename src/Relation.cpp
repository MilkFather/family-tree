#include "Relation.hpp"

// Relation的实现呢

Relation::Relation(Person &r_src, Person &r_dst, Relationship r_rel) {
    src = r_src;
    dst = r_dst;
    rel = r_rel;
}

Person &Relation::getSrc() {
    return src;
}

void Relation::setSrc(Person &r_src) {
    if (src != r_src) {
        src = r_src;
    }
}
    
Person &Relation::getDst() {
    return dst;
}
   
void Relation::setDst(Person &r_dst) {
    if (dst != r_dst) {
        dst = r_dst;
    }
}
    
Relationship Relation::getRel() {
    return rel;
}
   
void Relation::setRel(Relationship &r_rel) {
    if (rel != r_rel) {
        rel = r_rel;
    }
}