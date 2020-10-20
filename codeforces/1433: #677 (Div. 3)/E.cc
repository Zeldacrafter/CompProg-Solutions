///////////////////////////////////////////////////////////////
// Long template from: https://github.com/Zeldacrafter/CompProg
//
// Feature list:
// * C++11 compatibility.
// * Various 'define'-shorthands and typedefs.
// * Output stream that is only active with 'DEBUG'-flag set.
// * Input and output stream operators for...
//   * any container with 'begin' and 'end' iterator.
//   * tuples with any amount of elements 
//     (Except for 0 elements tuples :'( ) Related: https://xkcd.com/541/
//   * pairs.
// * Line seperated and aligned output of 2D vectors.
///////////////////////////////////////////////////////////////

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
#define fi first
#define se second
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define endl '\n'
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define SZ(x) (int)(x).size()
#define FOR(a, b, c) for (auto a = (b); (a) < (c); ++(a))
#define F0R(a, b) FOR (a, 0, (b))
template <typename T>
bool ckmin(T& a, const T& b) { return a > b ? a = b, true : false; }
template <typename T>
bool ckmax(T& a, const T& b) { return a < b ? a = b, true : false; }

// Output to 'cerr' if 'DEBUG' flag is set. Do nothing otherwise.
#ifndef DEBUG
#define DEBUG 0
#endif
#define dout if (DEBUG) cerr
// Output all passed variables with their corresponding name and value.
#define dvar(...) " \x1b[35m[" << #__VA_ARGS__ ": " << mt(__VA_ARGS__) << "]\x1b[0m "

///////////////////////////////////////////////////////////////
// Begin template definitions for input/output.
///////////////////////////////////////////////////////////////

// IsC indicates whether a type defines a 'const_iterator'.
// IsC::value is true if 'const_iterator' exists and false otherwise.
template <typename T> true_type const_iterator_check(typename T::const_iterator*);
template <typename T> false_type const_iterator_check(...);
template <typename T> struct IsC : decltype(const_iterator_check<T>(nullptr)) {};
// No new input/output for string as those already exist.
template <> struct IsC<string> : false_type {};

template <typename... T> using TS = tuple_size<tuple<T...>>;

///////////////////////////////////////////////////////////////
// Begin Output 
///////////////////////////////////////////////////////////////

// Forward declarations.
template <typename C>
typename enable_if<IsC<C>::value, ostream&>::type operator<<(ostream&, const C&);
template <typename T1, typename T2>
ostream& operator<<(ostream&, const pair<T1, T2>&);

// Output routine for tuples:
// 'idx' tracks the index of the current element that we want to print.
// The last element is at index 'TS<T...>::value - 1'.

// Print the last element of the tuple.
template <size_t idx, typename... T>
typename enable_if<TS<T...>::value == idx + 1, ostream&>::type
operator<<(ostream& o, const tuple<T...>& t) {
  return o << ", " << get<idx>(t) << ')';
}
// Print all but the first and last element of a tuple.
template <size_t idx, typename... T>
typename enable_if<0 < idx && idx + 1 < TS<T...>::value, ostream&>::type
operator<<(ostream& o, const tuple<T...>& t) {
  return operator<<<idx + 1>(o << ", " << get<idx>(t), t);
}
// Print the first element of a tuple.
template <size_t idx = 0, typename... T>
typename enable_if<1 < TS<T...>::value && !idx, ostream&>::type
operator<<(ostream& o, const tuple<T...>& t) {
  return operator<<<idx + 1>(o << '(' << get<idx>(t), t);
}

// Print tuples with only one contained element.
// Mainly here so that 'dvar(..)' functions correctly with only one element.
template <typename T>
ostream& operator<<(ostream& o, const tuple<T>& t) {
  return o << get<0>(t);
}


// Output for pairs via above defined tuple output routine.
template <typename T1, typename T2>
ostream& operator<<(ostream& o, const pair<T1, T2>& p) {
  return o << mt(p.fi, p.se);
}
// Output every element in a container with 'begin' and 'end' iterators.
template <typename C>
typename enable_if<IsC<C>::value, ostream&>::type operator<<(
    ostream& o, const C& c) {
  o << '[';
  for (auto it = c.cbegin(); it != c.cend(); ++it)
    o << *it << (next(it) != c.cend() ? ", " : "");
  return o << ']';
}

// Print a 2D-vector as a grid to the specified ostream with a specified minimum width per element.
template <typename T>
void tprint(vector<vector<T>>& v, size_t width = 0, ostream& o = cerr) {
  if (!DEBUG) return;
  for (const auto& vv : v) {
    for (const auto& i : vv) o << setw(width) << i;
    o << endl;
  }
}

///////////////////////////////////////////////////////////////
// Begin Input 
///////////////////////////////////////////////////////////////

// Forward declarations.
template <typename C>
typename enable_if<IsC<C>::value, istream&>::type operator>>(istream&, C&);
template <typename T1, typename T2>
istream& operator>>(istream&, pair<T1, T2>&);

// Input routine for tuples:
// 'idx' tracks the index of the current element that we want to read.
// The last element is at index 'TS<T...>::value - 1'.

// Read the last element of the tuple.
template <size_t idx, typename... T>
typename enable_if<TS<T...>::value == idx + 1, istream&>::type
operator>>(istream& i, tuple<T...>& t) {
  return i >> get<idx>(t);
}
// Read all but the first and last element of a tuple.
template <size_t idx, typename... T>
typename enable_if<0 < idx && idx + 1 < TS<T...>::value, istream&>::type
operator>>(istream& i, tuple<T...>& t) {
  return operator>><idx + 1>(i >> get<idx>(t), t);
}
// Read the first element of a tuple.
template <size_t idx = 0, typename... T>
typename enable_if<1 < TS<T...>::value && !idx, istream&>::type
operator>>(istream& i, tuple<T...>& t) {
  return operator>><idx + 1>(i >> get<idx>(t), t);
}

// Read tuples with only one contained element. 
//   (You could also just use this thing called a 'variable')
template <typename T>
istream& operator>>(istream& i, tuple<T>& t) {
  return i >> get<0>(t);
}

// Read the contents of a 'pair' object.
template <typename T1, typename T2>
istream& operator>>(istream& i, pair<T1, T2>& p) {
  return i >> p.fi >> p.se;
}

// Read containers with 'begin' and 'end' iterators.
template <typename C>
typename enable_if<IsC<C>::value, istream&>::type operator>>(istream& i, C& v) {
  for (auto& x : v) i >> x;
  return i;
}

///////////////////////////////////////////////////////////////
// Begin solution
///////////////////////////////////////////////////////////////

ll choose(int n, int k) {
    ll res = 1;
    FOR(i, n - k + 1, n + 1) res *= i;
    FOR(i, 2, k + 1) res /= i;
    return res;
}

ll fac(int n) {
    ll res = 1;
    F0R(i, n)
        res *= i + 1;
    return res;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    cout << (choose(n, n/2) * fac(n/2 - 1)*fac(n/2 - 1))/2 << endl;
}
