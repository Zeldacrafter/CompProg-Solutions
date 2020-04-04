#include <bits/stdc++.h>
using namespace std;
typedef pair<double, double> dd;

class Solution {
public:
    bool in(int x, int y, int x1, int x2, int y1, int y2) {
        return x >= x1 && x <= x2 && y >= y1 && y <= y2;
    }
    
    double dist(double x1, double y1, double x2, double y2) {
        return hypot(x1 - x2, y1 - y2);
    }
    
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        if(in(x_center, y_center, x1, x2, y1, y2))
            return true;
        
        if(dist(x_center, y_center, x1, y1) <= radius)
            return true;
        if(dist(x_center, y_center, x2, y1) <= radius)
            return true;
        if(dist(x_center, y_center, x1, y2) <= radius)
            return true;
        if(dist(x_center, y_center, x2, y2) <= radius)
            return true;
        
        if(abs(x1 - x_center) <= radius && y1 <= y_center && y2 >= y_center)
            return true;
        if(abs(y1 - y_center) <= radius && x1 <= x_center && x2 >= x_center)
            return true;
        if(abs(x2 - x_center) <= radius && y1 <= y_center && y2 >= y_center)
            return true;
        if(abs(y2 - y_center) <= radius && x1 <= x_center && x2 >= x_center)
            return true;
        
        return false;
    }
};
