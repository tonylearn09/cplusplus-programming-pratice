#ifndef GUARD_handle_h
#define GUARD_handle_h

#include <cstddef>
#include <stdexcept>

template <class T>
class Ref_handle {
public:
    // menage reference count as well as pointer
    Ref_handle(): p(0), refptr(new size_t(1)) { }
    Ref_handle(T* t): p(t), refptr(new size_t(1)) { }
    // increment since there is more copy
    // they point to the same objcet and the same count
    Ref_handle(const Ref_handle& h): p(h.p), refptr(h.refptr)
    {
        ++*refptr;
    }

    Ref_handle& operator=(const Ref_handle&);

    ~Ref_handle();

    // same as Handle.h
    operator bool() const { return p; }
    T& operator*() const
    {
        if (p)
            return *p;
        throw std::runtime_error("unbound Ref_handle");
    }

    T* operator->() const
    {
        if (p)
            return p;
        throw std::runtime_error("unbound Ref_handle");
    }

private:
    T* p;
    std::size_t* refptr;
};


template <class T>
Ref_handle<T>& Ref_handle<T>::operator=(const Ref_handle& rhs)
{
    ++*rhs.refptr;

    // free the left-hand side
    // destroy pointer if only one
    if (--*refptr == 0) {
        delete refptr;
        delete p;
    }

    // copy value from the right hand side
    refptr = rhs.refptr;
    p = rhs.p;
    return *this;
}

template <class T>
Ref_handle<T>::~Ref_handle()
{
    // if only one left
    // delte pointer and also refptr
    if (--*refptr == 0) {
        delete refptr;
        delete p;
    }
}

#endif
