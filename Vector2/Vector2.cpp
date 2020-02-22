#include "Vector2.h"
#include <iostream>

using namespace std;

int main() {
    float k = 2;
    vector2 v1;
    cin >> v1;
    vector2 v2;
    cin >> v2;
    cout << v1 << ":v1-v2: " << v2 << endl;
    vector2 v3 = v1 + v2;
    vector2 v4 = v1 - v2;
    v1 += v2;
    cout << v3 << "-v3;" << v4 << "-v4;" << v1 << endl;
    v1 -= v1;

    cout << v1 << "-v1: v3*v2 " << v3 * v2 << endl;
    v3 = v3 * k;
    cout << v3;

}
