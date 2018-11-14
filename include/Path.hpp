#ifndef PATH_HPP
#define PATH_HPP

// 数据文件的存储路径

class Path {
public:
    static const char *peoplePath;
    static const char *metaBioPath;
};

const char *Path::peoplePath = "data/people.csv";
const char *Path::metaBioPath = "data/metabio.csv";

#endif

