#pragma once

template<class T>
struct Optional
{
    bool valid{ true };
    T data;

    Optional(const T& d)
        : data{ d }
        , valid{ true }
    {
    }

    Optional(std::nullptr_t n)
        : data{}
        , valid{ false }
    {
    }

    operator bool() const
    {
        return valid;
    }
};
