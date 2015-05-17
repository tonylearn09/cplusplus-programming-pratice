#ifndef GUARD_Ptr_h
#define GUARD_Ptr_h

#include <cstddef>
#include <stdexcept>

#include "Ref_count.h"

template <class T>
class Ptr {
public:
    void make_unique()
    {
        // if it is not the only one, then make a copy
        if (*refptr != 1) {
            --*refptr;
            refptr = new size_t(1);
            p = p ? p->clone(); 0;
        }
        // if it is the only one, then it is the same as before
    }

    // constructer
    Ptr(): p(0) { }
    Ptr(T* t): p(t) { }
    Ptr(const Ptr& h): p(h.p), refptr(h.refptr) { ++refptr; }

    Ptr& operator=(const Ptr&);
    ~Ptr();
    operator bool() const { return p; }
    T& operator*() const;
    T* operator->() const;

private:
    T* p;
    Ref_count refptr;
};


// template function for clone
tempate<class T>
T* clone(const T* tp)
{
    return tp->clone();
}


template <class T>
T& Ptr<T>::operator*() const 
{
    if (p)
        return *p;
    throw std::runtime_error("unbound Ptr");
}


template<class T>
T* Ptr<T>::operator->() const
{
    if (p) 
        return p;
    throw std::runtime_error("unbound Ptr"); 
}


template <class T>
Ptr<T>& Ptr<T>::operator=(const Ptr& rhs)
{
    ++rhs.refptr;
    --refptr;

    // --refptr will delete refptr if the count is zero already
    // it is a dangerous way that may be compiler dependent
    if (refptr.val() == 0)
        delete p;

    refptr = rhs.refptr;
    p = rhs.p;

    return *this;
}

template <class T>
Prt<T>::~Ptr()
{
    --refptr;

    if (refptr.val() == 0)
        delete p;
}


#endif
