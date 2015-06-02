// This file contains sample implementations of assorted algorithms
// from the standard library.  It is not actually used by any of the
// other code in the book.

template <class In, class X>
In find(In begin, In end, const X& x)
{
    while (begin != end && *begin != x)
        ++begin;
    return begin;
}

template <class In, class Out>
Out copy(In begin, In end, Out dest)
{
    while (begin != end)
        *dest++ = *begin++;
    return dest;
}

template <clsss For, class X>
void replace(For begin, For end, const X& x, const X& y)
{
    while (begin != end) {
        if (*begin == x)
            *begin = y;

        ++begin;
    }
}

template <class Bi>
void reverse(Bi begin, Bi end)
{
    while (begin != end) {
        --end;
        if (begin != end)
            swap(*begin++, *end);
    }
}

template <class Ran, class X>
bool binary_search(Ran begin, Ran end, const X& x)
{
    while (begin < end) {
        // find the midpoint of the range
        Ran mid = begin + (end - begin) / 2;

        // see which part contains x
        // keep looking only at that part
        if (x < *mid)
            end = mid;
        else if (x > *mid)
            begin = mid + 1;
        // we find it, x == *mid
        else
            return true;
    }

    return false;
}
