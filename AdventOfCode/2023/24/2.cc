#include <Eigen/Geometry>

#include "ortools/base/logging.h"
#include "ortools/sat/cp_model.h"
#include "ortools/sat/cp_model.pb.h"
#include "ortools/sat/cp_model_solver.h"
#include "ortools/util/sorted_interval_list.h"

using namespace std;
using Vec3  = Eigen::Matrix<long long, 3, 1>;

// Surely this is the intended way to solve this :)

int main() {
    using namespace operations_research;
    using namespace operations_research::sat;
    
    vector<Vec3> coords, dirs;

    {
        double x, y, z, dx, dy, dz;
        char c;
        while (cin >> x >> c >> y >> c >> z >> c >> dx >> c >> dy >> c >> dz) {
            coords.emplace_back(x, y, z);
            dirs.emplace_back(dx, dy, dz);
        }
    }

    CpModelBuilder cp_model;
    long long base_size = 100000000000000ll;
    Domain area(0, 8*base_size);
    Domain areaVel(-1000, 1000);
    Domain areaTime(0, base_size);
    Domain areaTimeDx(-1000*base_size, 1000*base_size);

    IntVar x = cp_model.NewIntVar(area).WithName("x");
    IntVar y = cp_model.NewIntVar(area).WithName("y");
    IntVar z = cp_model.NewIntVar(area).WithName("z");
    IntVar dx = cp_model.NewIntVar(areaVel).WithName("dx");
    IntVar dy = cp_model.NewIntVar(areaVel).WithName("dy");
    IntVar dz = cp_model.NewIntVar(areaVel).WithName("dz");

    for(size_t i = 0; i < coords.size(); ++i) {
        IntVar time_i = cp_model.NewIntVar(areaTime).WithName("T_" + to_string(i));
        IntVar mulTimeDx = cp_model.NewIntVar(areaTimeDx).WithName("mulTimeDx");
        IntVar mulTimeDy = cp_model.NewIntVar(areaTimeDx).WithName("mulTimeDy");
        IntVar mulTimeDz = cp_model.NewIntVar(areaTimeDx).WithName("mulTimeDz");

        cp_model.AddMultiplicationEquality(mulTimeDx, { time_i, dx });
        cp_model.AddMultiplicationEquality(mulTimeDy, { time_i, dy });
        cp_model.AddMultiplicationEquality(mulTimeDz, { time_i, dz });

        cp_model.AddEquality(x + mulTimeDx, coords[i][0] + time_i*dirs[i][0]);
        cp_model.AddEquality(y + mulTimeDy, coords[i][1] + time_i*dirs[i][1]);
        cp_model.AddEquality(z + mulTimeDz, coords[i][2] + time_i*dirs[i][2]);
    }
    cout << "Starting the solve:" << endl;
    const CpSolverResponse response = Solve(cp_model.Build());
    if (response.status() == CpSolverStatus::OPTIMAL ||
        response.status() == CpSolverStatus::FEASIBLE) {
        LOG(INFO) << "x = " << SolutionIntegerValue(response, x);
        LOG(INFO) << "y = " << SolutionIntegerValue(response, y);
        LOG(INFO) << "z = " << SolutionIntegerValue(response, z);
        LOG(INFO) << "dx= " << SolutionIntegerValue(response, dx);
        LOG(INFO) << "dy= " << SolutionIntegerValue(response, dy);
        LOG(INFO) << "dz= " << SolutionIntegerValue(response, dz);

        cout << SolutionIntegerValue(response, x)
              + SolutionIntegerValue(response, y)
              + SolutionIntegerValue(response, z) << endl;
    } else {
        LOG(INFO) << "No solution found.";
        assert(false);
    }

    return 0;
}

