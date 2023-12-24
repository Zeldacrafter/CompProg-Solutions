#include <bits/stdc++.h>
#include <Eigen/Geometry> // Using external geometry library :)

using namespace std;
using Line2 = Eigen::Hyperplane<double,2>;
using Vec2  = Eigen::Vector2d;

const double MN = 200000000000000.0;
const double MX = 400000000000000.0;

double sgn(float x) { return (x > 0) - (x < 0); }

int main() {
    vector<Vec2> coords, dirs;
    double x, y, z, dx, dy, dz; char c;
    while(cin >> x >> c >> y >> c >> z >> c >> dx >> c >> dy >> c >> dz) {
        coords.emplace_back(x, y);
        dirs.emplace_back(dx, dy);
    }

    int res = 0;
    for(int i = 0; i < coords.size(); ++i) {
        for(int j = i + 1; j < coords.size(); ++j) {
            Line2 l1 = Line2::Through(coords[i], coords[i] + dirs[i]);
            Line2 l2 = Line2::Through(coords[j], coords[j] + dirs[j]);
            Vec2 pInt = l1.intersection(l2);

            if(MN <= pInt[0] && pInt[0] <= MX &&
               MN <= pInt[1] && pInt[1] <= MX &&
               sgn(pInt[0] - coords[i][0]) == sgn(dirs[i][0]) &&
               sgn(pInt[0] - coords[j][0]) == sgn(dirs[j][0])) {
                res++;
            }

        }
    }
    cout << res << endl;

    return 0;
}

