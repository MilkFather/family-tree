#ifndef PATH_HPP
#define PATH_HPP

class Path {
public:
    static const char *peoplePath;
    static const char *metaBioPath;
    static const char *metaLawPath;
    static const char *dataBioPath;
    static const char *dataLawPath;
};

const char *Path::peoplePath = "data/people.csv"
const char *Path::metaBioPath = "data/metabio.csv";
const char *Path::metaLawPath = "data/metalaw.csv";
const char *Path::dataBioPath = "data/bio.csv";
const char *Path::dataLawPath = "data/law.csv";

#endif

