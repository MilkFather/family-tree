#ifndef CSV_HPP
#define CSV_HPP

#include <vector>
#include <string>

// 负责处理CSV文件格式的CSV类
// 故名思意, Storage可以调用这里的方法进行CSV的读写与解析
// 这样Storage就不用担心文件格式问题了, 将二者分离也是好事

using std::vector;
using std::string;

typedef vector<string> CSVRow;

class CSV {
public:
    static vector<CSVRow> openFile(string filename);
    static void writeFile(vector<CSVRow> table, string filename);
    
private:
    static CSVRow parseLine(string l);
    static string makeLine(CSVRow r);
};

#endif
