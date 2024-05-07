#ifndef INSTANCEOUTOFBOUND_HPP
#define INSTANCEOUTOFBOUND_HPP

#include <future>
#include <cstring>

class InstanceOutOfBound : public std::future_error {

private:
    char* m_msg;

public:

    InstanceOutOfBound() = delete;
    InstanceOutOfBound(const InstanceOutOfBound&) = delete;
    InstanceOutOfBound(InstanceOutOfBound&&) = delete;

    InstanceOutOfBound& operator = (InstanceOutOfBound&) = delete;
    InstanceOutOfBound& operator = (InstanceOutOfBound&&) = delete;


    InstanceOutOfBound(std::future_errc err,const char* msg) :
        std::future_error(err)
    {
        m_msg = new char[strlen(msg)+1];
        strcpy(m_msg,msg);
    }


    virtual const char*
    what() const noexcept override {
        return m_msg;
    }


    ~InstanceOutOfBound() {
        delete[] m_msg;
    }


};

#endif // INSTANCEOUTOFBOUND_HPP
