#ifndef NEGATIVEINSTANCE_HPP
#define NEGATIVEINSTANCE_HPP

#include <future>
#include <cstring>

class NegativeInstance : public std::future_error {

private:
    char* m_msg;

public:

    NegativeInstance() = delete;
    NegativeInstance(const NegativeInstance&) = delete;
    NegativeInstance(NegativeInstance&&) = delete;

    NegativeInstance& operator = (NegativeInstance&) = delete;
    NegativeInstance& operator = (NegativeInstance&&) = delete;


    NegativeInstance(std::future_errc err,const char* msg) :
        std::future_error(err)
    {
        m_msg = new char[strlen(msg)+1];
        strcpy(m_msg,msg);
    }


    virtual const char*
    what() const noexcept override {
        return m_msg;
    }


    ~NegativeInstance() {
        delete[] m_msg;
    }


};

#endif // NEGATIVEINSTANCE_HPP
