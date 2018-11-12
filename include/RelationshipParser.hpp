#ifndef RELATIONSHIP_PARSER_HPP
#define RELATIONSHIP_PARSER_HPP

#include <string>

using std::string;

// RelationshipParser: 简单的家族成员关系推断单元类
// 基础知识: 数字电路(有限自动机)

// 限制: 关系通路中不能存在环
class RelationshipParser {
private:
    string relation;
    string gender;

public:
    RelationshipParser(string Gender);
    string getRelationship();
    void elevateRelation(string elevate);
};

#endif
