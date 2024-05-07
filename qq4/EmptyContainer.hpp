#ifndef EMPTYCONTAINER_HPP
#define EMPTYCONTAINER_HPP

#include <future>
#include <cstring>

class EmptyContainer : public std::future_error {

private:
    char* m_msg;

public:

    EmptyContainer() = delete;
    EmptyContainer(const EmptyContainer&) = delete;
    EmptyContainer(EmptyContainer&&) = delete;

    EmptyContainer& operator = (EmptyContainer&) = delete;
    EmptyContainer& operator = (EmptyContainer&&) = delete;


    EmptyContainer(std::future_errc err,const char* msg) :
        std::future_error(err)
    {
        m_msg = new char[strlen(msg)+1];
        strcpy(m_msg,msg);
    }


    virtual const char*
    what() const noexcept override {
        return m_msg;
    }


    ~EmptyContainer() {
        delete[] m_msg;
    }


};

#endif // EMPTYCONTAINER_HPP
