#include <ostream>
#include <stdexcept>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

template <typename T> class Set;

template <typename T>
std::ostream& operator<<(std::ostream& os, const Set<T>& s);

template <typename T>
std::istream& operator>>(std::istream& in, Set<T>& s);

template <typename T>
Set<T> operator+(const Set<T>& a, const Set<T>& b);

template <typename T>
Set<T> operator-(const Set<T>& a, const Set<T>& b);
    
template <typename T>
class Set {
private:
    std::vector<T> data{};

public:
    Set() = default;

    Set(const Set& a) {
        data.resize(a.data.size());
        for (size_t i = 0; i < data.size(); i++) {
            data[i] = a.data[i];
        }
    }

    Set& operator=(const Set& other) {
        if (&other == this) return *this;
        data = other.data;
        return *this;
    }

    Set(std::vector<T>& vector) {
        int flag = 0;
        for (size_t i = 0; i + 1 < vector.size(); i++) {
            flag = 0;
            for (size_t j = i + 1; j < vector.size(); j++) {
                if (vector[i] > vector[j]) {
                    std::swap(vector[i], vector[j]);
                    flag = 1;
                }
            }
            if (flag == 0) return;
        }
        if (vector.size() <= 1) { data = vector; return; }
        size_t i = 1;
        T temp = vector[0];
        while (i < vector.size()) {
            if (vector[i] == temp) {
                vector.erase(vector.begin() + i);
            }
            else {
                temp = vector[i++];
            }
        }
        data = vector;
    }

    void insert(const T& value) {
        for (size_t i = 0; i < data.size(); i++) {
            if (data[i] == value) return;
        }
        data.push_back(value);
        for (size_t i = 0; i + 1 < data.size(); i++) {
            for (size_t j = i + 1; j < data.size(); j++) {
                if (data[i] > data[j]) {
                    std::iter_swap(data.begin() + i, data.begin() + j);
                }
            }
        }
    }

    bool find(const T& value) const {
        for (size_t i = 0; i < data.size(); i++) {
            if (data[i] == value) return true;
        }
        return false;
    }

    bool replace(const T& old_value, const T& new_value) {
        size_t pos = data.size();
        for (size_t i = 0; i < data.size(); ++i) {
            if (data[i] == old_value) { pos = i; break; }
        }
        if (pos == data.size()) return false;

        if (old_value == new_value) return true;

        if (find(new_value)) {
            data.erase(data.begin() + pos);
            return true;
        }

        data.erase(data.begin() + pos);
        insert(new_value);
        return true;
    }

    size_t size() const { return data.size(); }

    Set intersect(const Set& s) const {
        Set new_set;
        for (size_t i = 0; i < data.size(); i++) {
            for (size_t j = 0; j < s.data.size(); j++) {
                if (data[i] == s.data[j]) {
                    new_set.data.push_back(data[i]);
                }
            }
        }
        if (!new_set.data.empty()) return new_set;
        throw std::runtime_error("Empty intersection");
    }

    friend std::ostream& operator<< <T>(std::ostream& os, const Set& s);
    friend std::istream& operator>> <T>(std::istream& in, Set& s);
    friend Set operator+ <T>(const Set& a, const Set& b);
    friend Set operator- <T>(const Set& a, const Set& b);
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Set<T>& s) {
    os << "{ ";
    for (size_t i = 0; i < s.data.size(); ++i) {
        os << s.data[i] << ", ";
    }
    os << "}";
    return os;
}

template <typename T>
std::istream& operator>>(std::istream& in, Set<T>& s) {
    s.data.clear();

    in >> std::ws;
    char ch;
    if (!(in >> ch)) return in;
    if (ch != '{') { in.setstate(std::ios::failbit); return in; }

    in >> std::ws;
    if (in.peek() == '}') { in.get(); return in; }

    while (true) {
        T value{};
        if (!(in >> value)) { in.setstate(std::ios::failbit); return in; }
        s.insert(value);

        in >> std::ws;
        int next = in.peek();
        if (next == '}') { in.get(); break; }
        if (next == ',') {
            in.get();
            in >> std::ws;
            if (in.peek() == '}') { in.get(); break; }
            continue;
        }
        in.setstate(std::ios::failbit);
        return in;
    }

    return in;
}

template <typename T>
Set<T> operator+(const Set<T>& a, const Set<T>& b) {
    Set<T> res;
    size_t i = 0, j = 0;
    while (i < a.data.size() && j < b.data.size()) {
        if (a.data[i] < b.data[j]) {
            res.data.push_back(a.data[i++]);
        }
        else if (b.data[j] < a.data[i]) {
            res.data.push_back(b.data[j++]);
        }
        else {
            res.data.push_back(a.data[i]);
            ++i; ++j;
        }
    }
    while (i < a.data.size()) res.data.push_back(a.data[i++]);
    while (j < b.data.size()) res.data.push_back(b.data[j++]);
    return res;
}

template <typename T>
Set<T> operator-(const Set<T>& a, const Set<T>& b) {
    Set<T> res;
    size_t i = 0, j = 0;
    while (i < a.data.size() && j < b.data.size()) {
        if (a.data[i] < b.data[j]) {
            res.data.push_back(a.data[i++]);
        }
        else if (b.data[j] < a.data[i]) {
            ++j;
        }
        else {
            ++i; ++j;
        }
    }
    while (i < a.data.size()) res.data.push_back(a.data[i++]);
    return res;
}