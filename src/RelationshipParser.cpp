#include "RelationshipParser.hpp"
#include <exception>

using std::exception;

// RelationshipParser类的实现

RelationshipParser::RelationshipParser(string Gender) {
    this->relation = "I";
    this->gender = Gender;
}

string RelationshipParser::getRelationship(void) {
    return this->relation;
}

void RelationshipParser::elevateRelation(string elevate) {
    if (relation == "I") {
        // My Mother is my Mother
        // My Father is my Father
        // My Son is my Son
        // My Daughter is my Daughter
        if (elevate == "Mother")
            relation = "Mother";
        else if (elevate == "Father")
            relation = "Father";
        else if (elevate == "Son")
            relation = "Son";
        else if (elevate == "Daughter")
            relation = "Daughter";
        else 
            throw exception();
    } else if (relation == "Mother") {
        // My mom's mom is my grandmother (surprise!)
        // My mom's father is my grandfather
        // My mom's son is my brother (myself not allowed)
        // My mom's daughter is my sister
        if (elevate == "Mother")
            relation = "Grandmother";
        else if (elevate == "Father")
            relation = "Grandfather";
        else if (elevate == "Son")
            relation = "Brother";
        else if (elevate == "Daughter")
            relation = "Sister";
        else 
            throw exception();
    } else if (relation == "Father") {
        // My dad's mom is my grandmother
        // My dad's father is my grandfather
        // My dad's son is my brother (myself not allowed)
        // My dad's daughter is my sister
        if (elevate == "Mother")
            relation = "Grandmother";
        else if (elevate == "Father")
            relation = "Grandfather";
        else if (elevate == "Son")
            relation = "Brother";
        else if (elevate == "Daughter")
            relation = "Sister";
        else 
            throw exception();
    } else if (relation == "Son") {
        // Based on different gender, variation exist
        if (elevate == "Mother")
            relation = ((gender == "Male") ? "Wife" : "I");
        else if (elevate == "Father")
            relation = ((gender == "Female") ? "Husband" : "I");
        else if (elevate == "Son")
            relation = "Grandson-son";
        else if (elevate == "Daughter")
            relation = "Granddaughter-son";
        else 
            throw exception();
    } else if (relation == "Daughter") {
        // Based on different gender, variation exist
        if (elevate == "Mother")
            relation = ((gender == "Male") ? "Wife" : "I");
        else if (elevate == "Father")
            relation = ((gender == "Female") ? "Husband" : "I");
        else if (elevate == "Son")
            relation = "Grandson-daughter";
        else if (elevate == "Daughter")
            relation = "Granddaughter-daughter";
        else 
            throw exception();
    } else if (relation == "Grandmother") {
        // No circle is allowed, and we only support up to grand-
        if (elevate == "Son")
            relation = "Uncle";
        else if (elevate == "Daughter")
            relation = "Aunt";
        else 
            throw exception();
    } else if (relation == "Grandfather") {
        // No circle is allowed, and we only support up to grand-
        if (elevate == "Son")
            relation = "Uncle";
        else if (elevate == "Daughter")
            relation = "Aunt";
        else 
            throw exception();
    } else if (relation == "Brother") {
        if (elevate == "Mother")
            relation = "Mother";
        else if (elevate == "Father")
            relation = "Father";
        else if (elevate == "Son")
            relation = "Nephew-brother";
        else if (elevate == "Daughter")
            relation = "Niece-brother";
        else 
            throw exception();
    } else if (relation == "Sister") {
        if (elevate == "Mother")
            relation = "Mother";
        else if (elevate == "Father")
            relation = "Father";
        else if (elevate == "Son")
            relation = "Nephew-sister";
        else if (elevate == "Daughter")
            relation = "Niece-sister";
        else 
            throw exception();
    } else if (relation == "Wife") {
        if (elevate == "Son")
            relation = "Son";
        else if (elevate == "Daughter")
            relation = "Daughter";
        else 
            throw exception();
    } else if (relation == "Husband") {
        // We don't care what's on their side
        if (elevate == "Son")
            relation = "Son";
        else if (elevate == "Daughter")
            relation = "Daughter";
        else 
            throw exception();
    } else if (relation == "Grandson-son") {
        // we support down to grand-
        if (elevate == "Father")
            relation = "Son";
        else 
            throw exception();
    } else if (relation == "Granddaughter-son") {
        if (elevate == "Father")
            relation = "Son";
        else 
            throw exception();
    } else if (relation == "Grandson-daughter") {
        if (elevate == "Mother")
            relation = "Daughter";
        else 
            throw exception();
    } else if (relation == "Granddaughter-daughter") {
        if (elevate == "Mother")
            relation = "Daughter";
        else 
            throw exception();
    } else if (relation == "Uncle") {
        if (elevate == "Father")
            relation = "Grandfather";
        else if (elevate == "Mother")
            relation = "Grandmother";
        else if (elevate == "Son")
            relation = "Nephew-uncle";
        else if (elevate == "Daughter")
            relation = "Niece-uncle";
        else 
            throw exception();
    } else if (relation == "Aunt") {
        if (elevate == "Father")
            relation = "Grandfather";
        else if (elevate == "Mother")
            relation = "Grandmother";
        else if (elevate == "Son")
            relation = "Nephew-aunt";
        else if (elevate == "Daughter")
            relation = "Niece-aunt";
        else 
            throw exception();
    } else if (relation == "Nephew-uncle") {
        if (elevate == "Father")
            relation = "Uncle";
        else 
            throw exception();
    } else if (relation == "Niece-uncle") {
        if (elevate == "Father")
            relation = "Uncle";
        else 
            throw exception();
    } else if (relation == "Nephew-aunt") {
        if (elevate == "Mother")
            relation = "Aunt";
        else 
            throw exception();
    } else if (relation == "Niece-aunt") {
        if (elevate == "Mother")
            relation = "Aunt";
        else 
            throw exception();
    } else if (relation == "Nephew-brother") {
        if (elevate == "Father")
            relation = "Brother";
        else 
            throw exception();
    } else if (relation == "Niece-brother") {
        if (elevate == "Father")
            relation = "Brother";
        else 
            throw exception();
    } else if (relation == "Nephew-sister") {
        if (elevate == "Mother")
            relation = "Sister";
        else 
            throw exception();
    } else if (relation == "Niece-sister") {
        if (elevate == "Mother")
            relation = "Sister";
        else 
            throw exception();
    } else {
        throw exception();
    }
}