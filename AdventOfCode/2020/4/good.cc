#include "../template.cc"

template<typename T>
bool betw(T a, T b, T c) {
    return a >= b && a <= c;
}

vector<string> need{"byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid"};
set<string> eyeColors{"amb", "blu", "brn", "gry", "grn", "hzl", "oth"};

struct Height {
    string id = "";
    int val = 0;

    bool isValid() {
        return (id == "cm" && betw(val, 150, 193)) ||
               (id == "in" && betw(val, 50, 76));
    }

    friend ostream& operator<<(ostream& o, const Height& h) {
        return o << mp(h.val, h.id);
    }
};

class Passport {
    public:
    string pid = "";
    int cid = 0;
    int byr = 0;
    int iyr = 0;
    int eyr = 0;
    Height hgt = {};
    string hcl = "";
    string ecl = "";

    bool isValid() {
        bool ok = true;

        ok &= SZ(pid) == 9 && all_of(ALL(pid), [](char c) { return isdigit(c); });

        ok &= true; // No validation for cid

        ok &= betw(byr, 1920, 2002);

        ok &= betw(iyr, 2010, 2020);

        ok &= betw(eyr, 2020, 2030);

        ok &= hgt.isValid();

        ok &= SZ(hcl) == 7 && hcl[0] == '#' &&
              all_of(1 + ALL(hcl), [](char c) { return isdigit(c) || betw(c, 'a', 'f'); });

        ok &= eyeColors.count(ecl);

        return ok;
    }

    void parse(string& key, string& val) {
        if (key == "byr") {
            byr = stoi(val);
        } else if (key == "iyr") {
            iyr = stoi(val);
        } else if (key == "eyr") {
            eyr = stoi(val);
        } else if (key == "hgt") {
            if(SZ(val) > 2) {
                hgt.val = stoi(val.substr(0, SZ(val) - 2));
                hgt.id = val.substr(SZ(val) - 2, 2);
            }
        } else if (key == "hcl") {
            hcl = val;
        } else if (key == "ecl") {
            ecl = val;
        } else if (key == "pid") {
            pid = val;
        } else if (key == "cid") {
            cid = stoi(val);
        }
    }

    static vector<Passport> parseAll(bool onlyValid = true) {
        vector<Passport> res;
        Passport curr = {};

        getInp([&](auto& cin, int) {
            int cnt = 0;
            while(true) {
                string key, value;
                char colon;

                if(cin.peek() == EOF) break;
                while(cin.peek() == ' ') cin.get();
                while(cin.peek() != ':') key.pb(cin.get());
                cin >> colon >> value;

                curr.parse(key, value);

                cnt++;
            }

            if (!cnt) {
                if(!onlyValid || curr.isValid())
                    res.pb(curr);
                curr = {};
            }
        });
        if(!onlyValid || curr.isValid())
            res.pb(curr);

        return res;
    }

    friend ostream& operator<<(ostream& o, const Passport pp) {
        return o << mt(pp.pid, pp.cid, pp.byr, pp.iyr, pp.eyr, pp.hgt, pp.hcl, pp.ecl);
    }
};

void solve() {
    set<string> keys;

    vector<Passport> pps = Passport::parseAll();
    cout << SZ(pps) << endl;
}


