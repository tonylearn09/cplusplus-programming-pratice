#ifndef GUARD_Handle_h
#define GUARd_Handle_h

template <class T>
class Handle {
public:
    Handle(): p(0) { }
    Handle(const Handle& s): p(0) { if (s.p) p = s.p->clone(); }
    Handle& operator=(const Handle&);
    ~Handle() { delete p; }

    // conversion
    // to bind the pointer to actual object
    Handle(T* t): p(t) { }

    // check if the pointer is bound
    operator bool() const { return p; }

    // implement* and ->
    T& operator*() const;
    T* operator->() const;
    
private:
    T* p;
};


// template implementation
#include <stdexcept>

using std::runtime_error;

template <class T>
Handle<T>& Handle<T>::operator=(const Handle& rhs)
{
    if (&rhs != this) {
        delete p;
        // use rhs.p->clone
        // inportent
        // i do it wrong, and wrok for a long time to get right
        p = rhs.p ? rhs.p->clone() : 0;
    }

    return *this;
}

// see Accelerated c++ for more detail
template <class T>
T& Handle<T>::operator*() const
{
    if (p)
        return *p;
    throw runtime_error("unbound Handle");
}

template <class T>
T* Handle<T>::operator->() const
{
    if (p)
        return p;
    throw runtime_error("unbound Handle");
}
#endif
