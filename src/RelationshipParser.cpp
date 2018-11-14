#include "RelationshipParser.hpp"
#include <exception>

using std::exception;

// RelationshipParser类的实现

RelationshipParser::RelationshipParser(Relationship rel, Gender gender) {
    this->relation = rel;
    this->gender = gender;
}

Relationship RelationshipParser::getRelationship(void) {
    return this->relation;
}

void RelationshipParser::elevateRelation(Relationship elevate) {
    switch (relation) {
        case myself:
            switch (elevate) {
                case mother: relation = mother; break;
                case father: relation = father; break;
                case son: relation = son; break;
                case daughter: relation = daughter; break;
                default: throw exception(); break;
            }
            break;
        
        case father:
            switch (elevate) {
                case mother: relation = grandmother; break;
                case father: relation = grandfather; break;
                case son: relation = brother; break;
                case daughter: relation = sister; break;
                default: throw exception(); break;
            }
            break;

        case mother:
            switch (elevate) {
                case mother: relation = grandmother; break;
                case father: relation = grandfather; break;
                case son: relation = brother; break;
                case daughter: relation = sister; break;
                default: throw exception(); break;
            }
            break;

        case brother:
            switch (elevate) {
                case mother: relation = mother; break;
                case father: relation = father; break;
                case son: relation = nephew_brother; break;
                case daughter: relation = niece_brother; break;
                default: throw exception(); break;
            }
            break;

        case sister:
            switch (elevate) {
                case mother: relation = mother; break;
                case father: relation = father; break;
                case son: relation = nephew_sister; break;
                case daughter: relation = niece_sister; break;
                default: throw exception(); break;
            }
            break;

        case grandfather:
            switch (elevate) {
                case son: relation = uncle; break;
                case daughter: relation = aunt; break;
                default: throw exception(); break;
            }
            break;

        case grandmother:
            switch (elevate) {
                case son: relation = uncle; break;
                case daughter: relation = aunt; break;
                default: throw exception(); break;
            }
            break;
        
        case son:
            switch (elevate) {
                case mother: relation = (gender == Male) ? wife : myself; break;
                case father: relation = (gender == Female) ? husband : myself; break;
                case son: relation = grandson_son; break;
                case daughter: relation = granddaughter_son; break;
                default: throw exception(); break;
            }
            break;

        case daughter:
            switch (elevate) {
                case mother: relation = (gender == Male) ? wife : myself; break;
                case father: relation = (gender == Female) ? husband : myself; break;
                case son: relation = grandson_daughter; break;
                case daughter: relation = granddaughter_daughter; break;
                default: throw exception(); break;
            }
            break;

        case grandson_son:
            switch (elevate) {
                case father: relation = son; break;
                default: throw exception(); break;
            }
            break;

        case granddaughter_son:
            switch (elevate) {
                case father: relation = son; break;
                default: throw exception(); break;
            }
            break;

        case grandson_daughter:
            switch (elevate) {
                case mother: relation = daughter; break;
                default: throw exception(); break;
            }
            break;

        case granddaughter_daughter:
            switch (elevate) {
                case mother: relation = daughter; break;
                default: throw exception(); break;
            }
            break;

        case aunt:
            switch (elevate) {
                case father: relation = grandfather; break;
                case mother: relation = grandmother; break;
                case son: relation = nephew_aunt; break;
                case daughter: relation = niece_aunt; break;
                default: throw exception(); break;
            }
            break;

        case uncle:
            switch (elevate) {
                case father: relation = grandfather; break;
                case mother: relation = grandmother; break;
                case son: relation = nephew_uncle; break;
                case daughter: relation = niece_uncle; break;
                default: throw exception(); break;
            }
            break;

        case nephew_brother:
            switch (elevate) {
                case father: relation = brother; break;
                default: throw exception(); break;
            }
            break;

        case niece_brother:
            switch (elevate) {
                case father: relation = brother; break;
                default: throw exception(); break;
            }
            break;

        case nephew_sister:
            switch (elevate) {
                case mother: relation = sister; break;
                default: throw exception(); break;
            }
            break;

        case niece_sister:
            switch (elevate) {
                case mother: relation = sister; break;
                default: throw exception(); break;
            }
            break;

        case nephew_aunt:
            switch (elevate) {
                case mother: relation = aunt; break;
                default: throw exception(); break;
            }
            break;

        case niece_aunt:
            switch (elevate) {
                case mother: relation = aunt; break;
                default: throw exception(); break;
            }
            break;

        case nephew_uncle:
            switch (elevate) {
                case father: relation = uncle; break;
                default: throw exception(); break;
            }
            break;

        case niece_uncle:
            switch (elevate) {
                case father: relation = uncle; break;
                default: throw exception(); break;
            }
            break;

        case wife:
            switch (elevate) {
                case son: relation = son; break;
                case daughter: relation = daughter; break;
                default: throw exception(); break;
            }
            break;

        case husband:
            switch (elevate) {
                case son: relation = son; break;
                case daughter: relation = daughter; break;
                default: throw exception(); break;
            }
            break;

        default:
            throw exception();
            break;
    }
}