#include "Relation.hpp"

// Relation的实现呢

Person Relation::getSrc() const {
    return src;
}

void Relation::setSrc(Person &r_src) {
    if (src != r_src) {
        src = r_src;
    }
}
    
Person Relation::getDst() const {
    return dst;
}
   
void Relation::setDst(Person &r_dst) {
    if (dst != r_dst) {
        dst = r_dst;
    }
}
    
Relationship Relation::getRel() const {
    return rel;
}
   
void Relation::setRel(Relationship &r_rel) {
    if (rel != r_rel) {
        rel = r_rel;
    }
}

Relationship Str2Rel(string s) {
    if (s == "myself") return myself;
    if (s == "father") return father;
    if (s == "mother") return mother;
    if (s == "brother") return brother;
    if (s == "sister") return sister;
    if (s == "grandfather") return grandfather;
    if (s == "grandmother") return grandmother;
    if (s == "son") return son;
    if (s == "daughter") return daughter;
    if (s == "grandson_son") return grandson_son;
    if (s == "granddaughter_son") return granddaughter_son;
    if (s == "grandson_daughter") return grandson_daughter;
    if (s == "granddaughter_daughter") return granddaughter_daughter;
    if (s == "aunt") return aunt;
    if (s == "uncle") return uncle;
    if (s == "nephew_brother") return nephew_brother;
    if (s == "niece_brother") return niece_brother;
    if (s == "nephew_sister") return nephew_sister;
    if (s == "niece_sister") return niece_sister;
    if (s == "nephew_aunt") return nephew_aunt;
    if (s == "niece_aunt") return niece_aunt;
    if (s == "nephew_uncle") return nephew_uncle;
    if (s == "niece_uncle") return niece_uncle;
    if (s == "wife") return wife;
    if (s == "husband") return husband;
    return none;
}

string Rel2Str(Relationship s) {
    switch (s) {
        case none: return "none"; break;
        case myself: return "myself"; break; 
        case father: return "father"; break;
        case mother: return "mother"; break; 
        case brother: return "brother"; break;
        case sister: return "sister"; break;
        case grandfather: return "grandfather"; break;
        case grandmother: return "grandmother"; break; 
        case son: return "son"; break;
        case daughter: return "daughter"; break; 
        case grandson_son: return "grandson_son"; break;
        case granddaughter_son: return "granddaughter_son"; break; 
        case grandson_daughter: return "grandson_daughter"; break;
        case granddaughter_daughter: return "granddaughter_daughter"; break;
        case aunt: return "aunt"; break;
        case uncle: return "uncle"; break; 
        case nephew_brother: return "nephew_brother"; break;
        case niece_brother: return "niece_brother"; break;
        case nephew_sister: return "nephew_sister"; break;
        case niece_sister: return "niece_sister"; break;
        case nephew_aunt: return "nephew_aunt"; break; 
        case niece_aunt: return "niece_aunt"; break;
        case nephew_uncle: return "nephew_uncle"; break;
        case niece_uncle: return "niece_uncle"; break;
        case wife: return "wife"; break;
        case husband: return "husband"; break;
    }
    return "none";
}
