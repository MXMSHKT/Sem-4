#pragma once

#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

class vector2 {

public:
    explicit vector2(float x_ = 0, float y_ = 0) : x(x_), y(y_) {}

    float x_() const { return x; }

    float y_() const { return y; }

    void assign(float x_, float y_) {
        x = x_;
        y = y_;
    }

    float len() const {
        return sqrt(x_() * x_() + y_() * y_());
    }

    float squareLen() const {
        return (x_() * x_() + y_() * y_());
    }

    vector2 norm() const {
        float n = sqrt(x_() * x_() + y_() * y_());
        return vector2(x_() / n, y_() / n);
    }

    vector2 normal() const {
        return vector2(y_(), -x_());
    }

    void rotate() {
        float temp = x;
        x = y;
        y = -temp;
    }

    vector2 getRotated() {
        return norm();
    }

private:
    float x = 0;
    float y = 0;
};

ostream &operator<<(ostream &stream, vector2 &v) {
    stream << v.x_() << " " << v.y_();
    return stream;
}

istream &operator>>(istream &stream, vector2 &v) {
    float x, y;
    stream >> x >> y;
    v.assign(x, y);
    return stream;
}

vector2 operator+(const vector2 &v1, const vector2 &v2) {
    return vector2(v1.x_() + v2.x_(), v1.y_() + v2.y_());
}

vector2 &operator+=(vector2 &v1, const vector2 &v2) {
    v1.assign(v1.x_() + v2.x_(), v1.y_() + v2.y_());
    return v1;
}

vector2 operator-(const vector2 &v1, const vector2 &v2) {
    return vector2(v1.x_() - v2.x_(), v1.y_() - v2.y_());
}

vector2 &operator-=(vector2 &v1, const vector2 &v2) {
    v1.assign(v1.x_() - v2.x_(), v1.y_() - v2.y_());
    return v1;
}

float operator*(const vector2 v1, const vector2 v2) {
    return (v1.x_() * v2.x_() + v1.y_() * v2.y_());
}

float operator^(const vector2 v1, const vector2 v2) {
    return (v1.x_() * v2.x_() - v1.y_() * v2.y_());
}

vector2 operator*(float k, vector2 &v) {
    return vector2(v.x_() * k, v.y_() * k);
}

vector2 operator*(vector2 &v, float k) {
    return vector2(v.x_() * k, v.y_() * k);
}

vector2 operator/(vector2 &v, float k) {
    return vector2(v.x_() / k, v.y_() / k);
}

vector2 &operator--(vector2 &v) {
    v.assign(v.x_() - 1, v.y_() - 1);
    return v;
}

vector2 &operator++(vector2 &v) {
    v.assign(v.x_() + 1, v.y_() + 1);
    return v;
}
