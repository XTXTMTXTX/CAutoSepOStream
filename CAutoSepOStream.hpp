#include <string>
#include <ostream>
class CAutoSepOStream : public std::ostream
{
private:
    bool firstElement = true;
    std::ostream &o;
    const std::string sep;
public:
    CAutoSepOStream(std::ostream &o, std::string sep = " ") : o(o), sep(sep) {}
    template<typename T>
    CAutoSepOStream &operator<<(T && a)
    {
        if (firstElement)
        {
            firstElement = false;
            o << std::forward<T>(a);
        }
        else
            o << sep << std::forward<T>(a);
        return *this;
    }
    CAutoSepOStream &operator<<(std::ostream&(*f)(std::ostream&))
    {
        o << f;
        if (f == (std::basic_ostream<char>& (*)(std::basic_ostream<char>&)) &std::endl)
            firstElement = true;
        return *this;
    }
};
