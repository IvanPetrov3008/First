
#include <iostream>
#include <vector>
using namespace std;

struct rectangle {
    int x1;
    int y1;
    int x2;
    int y2;
};
//x y левый верхний угол
bool isRectangleContainSquare(rectangle r, int x, int y) {
    return r.x1 <= x && x < r.x2 && r.y1 <= y && y < r.y2;
}

bool isAnyRectangleContainsSquare(vector<rectangle> v, int x, int y) {
    for(int i = 0; i < v.size(); i++) {
        if(isRectangleContainSquare(v[i], x, y)) {
            return true;
        }
    }
    return false;
}

int main() {
    vector<rectangle> v;
    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        rectangle r;
        cin >> r.x1 >> r.y1 >> r.x2 >> r.y2;
        v.push_back(r);
    }
    
    int count = 0;
    
    for (int x = -1000; x <= 1000; x++) {
        for (int y = -1000; y <= 1000; y++) {
            if(isAnyRectangleContainsSquare(v, x, y)) {
                count++;
//                cout << x << " " << y << endl;
            }
        }
    }
    
    cout << count << endl;
    
    return 0;
}
