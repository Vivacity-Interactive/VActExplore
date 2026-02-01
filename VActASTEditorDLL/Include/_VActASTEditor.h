#pragma once

#if defined(_WIN32)
    #if defined(EDITOR_BUILD_DLL)
        #define VACTASTEDITOR_API __declspec(dllexport)
    #else
        #define VACTASTEDITOR_API __declspec(dllimport)
    #endif
#else
    #define VACTASTEDITOR_API
#endif  

#ifndef _VACTASTEDITOR_DEFAULT_BODY
#define _VACTASTEDITOR_DEFAULT_BODY(CLASSNAME) \
    CLASSNAME(const CLASSNAME& Other) = default; \
    CLASSNAME(CLASSNAME&& Other) noexcept = default; \
    CLASSNAME& operator=(CLASSNAME&& Other) noexcept = default; \
    CLASSNAME& operator=(const CLASSNAME& Other) = default;
#endif

#if defined(_VACTASTEDITOR_CUSTOM_STRING)
#include <string_view>
#include <string>
#include <algorithm>
#include <ostream>

namespace VActExplore::ASTEditor
{
    struct VACTASTEDITOR_API string_t
    {
        char* _data;
        size_t _length;

        string_t()
            : _data(nullptr)
            , _length(0)
        {
            clear();
        }

        string_t(const string_t& other, bool b_delete = true)
            : string_t()
        {
            assign(other._data, other._length, b_delete);
        }

        string_t(string_t&& other, bool b_delete = true) noexcept
            : _data(other._data)
            , _length(other._length)
        {
            other.clear(b_delete);
        }

        template<typename Iter>
        string_t(const Iter first, const Iter last, bool b_delete = true)
        {
            assign(first, last, b_delete);
        }

        string_t(const char* str, bool b_delete = true)
        {
            assign(str, b_delete);
        }

        string_t(const char* str, size_t count, bool b_delete = true)
        {
            assign(str, count, b_delete);
        }

        string_t(std::string& str, bool b_delete = true)
            : string_t(str.c_str(), str.length(), b_delete)
        {
        }

        ~string_t()
        {
            delete[] _data;
        }

        void clear(bool b_delete = true)
        {
            if (b_delete && _data) { delete[] _data; }
            _data = new char[1];
            _data[0] = L'\0';
            _length = 0;
        }

        template<typename Iter>
        char* assign(const Iter first, const Iter last, bool b_delete = true)
        {
            if (b_delete && _data) { delete[] _data; }
            _length = std::distance(first, last);
            _data = new char[_length + 1];
            std::copy(first, last, _data);
            _data[0] = L'\0';
            return _data;
        }

        char* assign(const char* str, size_t count, bool b_delete = true)
        {
			return assign(str, str + count, b_delete);
        }

        __forceinline char* assign(const char* str, bool b_delete = true)
        {
            return assign(str, std::strlen(str), b_delete);
        }

        __forceinline char* data()
        {
            return _data;
        }

        __forceinline const char* data() const
        {
            return _data;
        }

        __forceinline char* c_str()
        {
            return _data;
        }

        __forceinline const char* c_str() const
        {
            return _data;
        }

        __forceinline size_t length() const
        {
            return _length;
        }

        __forceinline size_t size() const
        {
            return _length;
        }

        __forceinline std::string_view view() const
        {
            return std::string_view(_data, _length);
        }

        __forceinline char* operator*()
        {
            return _data;
        }

        __forceinline const char* operator*() const
        {
            return _data;
        }

        __forceinline char operator[](size_t index) const
        {
            return _data[index];
        }

        __forceinline char& operator[](size_t index)
        {
            return _data[index];
        }

        __forceinline string_t& operator=(const std::string str)
        {
            assign(str.c_str(), str.length());
            return *this;
        }

        __forceinline string_t& operator=(const char* str)
        {
            assign(str, std::strlen(str));
            return *this;
        }

        string_t& operator=(const string_t& other)
        {
            if (this != &other)
            {
                assign(other._data, other._length);
            }
            return *this;
        }

        string_t& operator=(string_t&& other) noexcept
        {
            if (this != &other)
            {
                if (_data) { delete[] _data; }
                _data = other._data;
                _length = other._length;
                other.clear();
            }
            return *this;
        }

        __forceinline std::ostream& operator<<(std::ostream& os) {
            return os << std::string_view(_data, _length);
        }

        __forceinline operator const char* () const
        {
            return _data;
        }

        __forceinline operator char* ()
        {
            return _data;
        }

        __forceinline operator std::string() const
        {
            return std::string(_data, _length);
        }

        __forceinline  operator std::string_view() const
        {
            return std::string_view(_data, _length);
        }
    };
}
#else
#include <string>
using string_t = std::string;
#endif