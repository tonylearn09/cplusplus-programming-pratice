#include <algorithm>
#include <vector>
#include <stdexcept>

template <class T>
T median(std::vector<T> v)
{
    typedef typename std::vector<T>::size_type vec_sz;
    vec_sz size = v.size();
    
    if (size == 0)
        throw std::domain_error("median of empty vector!");

    std::sort(v.begin(), v.end());
    vec_sz mid = size / 2;
    return size % 2 == 0 ? (v[mid] + v[mid - 1]) / 2 : v[mid];
}
