///////////////////////////////////////////////////////////////
// Long template from: https://github.com/Zeldacrafter/CompProg
//
// Feature list:
// * C++14 compatibility.
// * Various 'define'-shorthands and typedefs.
// * Output stream that is only active with 'DEBUG'-flag set.
// * Input and output stream operators for...
//   * any container with 'begin' and 'end' iterator.
//   * tuples with any amount of elements 
//     (Except for 0 elements tuples :'( ) Related: https://xkcd.com/541/
//   * pairs.
// * Line seperated and aligned output of 2D vectors.
// * TODO: pretty printer
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
// Utility functions.
///////////////////////////////////////////////////////////////

namespace impl {
  template <typename T, typename F, size_t... Is>
  F for_each(T& t, F f, index_sequence<Is...>) {
    auto l = { (f(get<Is>(t), Is), 0)... };
    (void) l;
    return f;
  }
}

template <typename... Ts, typename F>
F for_each(tuple<Ts...>& t, F f) { 
  return impl::for_each(t, f, make_index_sequence<sizeof...(Ts)>{});
}

template <typename... Ts, typename F>
F for_each(const tuple<Ts...>& t, F f) { 
  return impl::for_each(t, f, make_index_sequence<sizeof...(Ts)>{});
}

// IsC indicates whether a type defines a 'const_iterator'.
// IsC::value is true if 'const_iterator' exists and false otherwise.
template <typename T> true_type const_iterator_check(typename T::const_iterator*);
template <typename T> false_type const_iterator_check(...);
template <typename T> struct IsC : decltype(const_iterator_check<T>(nullptr)) {};
// No new input/output for string as those already exist.
template <> struct IsC<string> : false_type {};

///////////////////////////////////////////////////////////////
// Begin Output 
///////////////////////////////////////////////////////////////

// Forward declarations.
template <typename T>
enable_if_t<IsC<T>::value, ostream&> operator<<(ostream&, const T&);
template <typename T1, typename T2>
ostream& operator<<(ostream&, const pair<T1, T2>&);

// Print each tuple element.
template <typename... Ts>
ostream& operator<<(ostream& o, const tuple<Ts...>& t) {
    o << '(';
    for_each(t, [&](auto& x, size_t i) { if(i) o << ", "; o << x; });
    return o << ')';
}

// Output for pairs via above defined tuple output routine.
template <typename T1, typename T2>
ostream& operator<<(ostream& o, const pair<T1, T2>& p) {
  return o << '(' << p.fi << ", " << p.se << ')';
}

// Output every element in a container with 'begin' and 'end' iterators.
template <typename T>
enable_if_t<IsC<T>::value, ostream&> operator<<(ostream& o, const T& c) {
  o << '[';
  for (auto it = c.cbegin(); it != c.cend(); ++it)
    o << *it << (next(it) != c.cend() ? ", " : "");
  return o << ']';
}

///////////////////////////////////////////////////////////////
// Pretty output
///////////////////////////////////////////////////////////////

// PrettyPrint struct that contains a value to be printed and
// a list of seperators which indicate how different dimensions
// of multidimensional values should be seperated.
template <typename T, size_t N>
struct PP {
  // Value to print.
  const T& v; 
  // Pointer to seperator list.
  shared_ptr<array<string, N>> se;
  // Index of next seperator.
  size_t idx;
  PP(const T& value, shared_ptr<array<string, N>> p, size_t i = 0) 
      : v{value}, se{p}, idx{i} {}
};

// If a value is not a pair, tuple or std-library-continer just print it.
// Pairs and tuples are implemented via template specialization further down.
template <typename T, size_t M>
enable_if_t<not IsC<T>::value, ostream&>
operator<<(ostream& o, const PP<T, M>& p) {
  return o << p.v;
}

// Prints every tuple element.
template <size_t M, typename... Ts>
ostream& operator<<(ostream& o, const PP<tuple<Ts...>, M>& p) {
  const string& sep = p.idx < M ? (*p.se)[p.idx] : " ";
  for_each(p.v, [&](auto& x, size_t i) { 
    if(i) o << sep; 
    o << PP<decay_t<decltype(x)>, M>(x, p.se, p.idx + 1);
  });
  return o;
}

// Print pairs with the specified seperator for that level.
template <typename T1, typename T2, size_t M>
ostream& operator<<(ostream& o, const PP<pair<T1, T2>, M>& p) {
  const string& sep = p.idx < M ? (*p.se)[p.idx] : " ";
  return o << PP<T1, M>(p.v.fi, p.se, p.idx + 1) << sep
           << PP<T2, M>(p.v.se, p.se, p.idx + 1);
}

// Print std-library-container with the specified seperator.
template <typename T, size_t M>
enable_if_t<IsC<T>::value, ostream&>
operator<<(ostream& o, const PP<T, M>& p) {
  // Seperator for the current layer (or default)
  const string& sep = p.idx < M ? (*p.se)[p.idx] : " ";
  // Print every container element
  for (auto it = p.v.cbegin(); it != p.v.cend(); ++it)
    o << PP<typename T::value_type, M>(*it, p.se, p.idx + 1)
      << (next(it) != p.v.cend() ? sep : "");
  return o;
}

// Function for PrettyPrinting a object with specified seperators.
// Each additional seperator specifies the seperator for one level
// further into a nested structure. Pairs, tuples and std-library-container
// cause the level to increase.
// If no seperator is specified a default of " "(space) is used.
// For example a call 
//    vector<ii> a(4, mp(1, 2));
//    cout << pp(a, " | ", "-");
// results in the output (without trailing newline)
//    1-2 | 1-2 | 1-2 | 1-2
//
// This function is the main way for a user to interface with the PrettyPrinter.
template <typename T, typename... Ts, size_t N = sizeof...(Ts)>
PP<T, N> pp(const T& value, Ts... seps) {
  return PP<T, N>(value, make_shared<array<string, N>>(array<string, N>{seps...}));
}

///////////////////////////////////////////////////////////////
// Begin Input 
///////////////////////////////////////////////////////////////

// Forward declarations.
template <typename T>
enable_if_t<IsC<T>::value, istream&> operator>>(istream&, T&);
template <typename T1, typename T2>
istream& operator>>(istream&, pair<T1, T2>&);

// Read a tuple.
template <typename... Ts>
istream& operator>>(istream& i, tuple<Ts...>& t) {
  for_each(t, [&](auto& x, int) { cin >> x; });
  return i;
}

// Read the contents of a 'pair' object.
template <typename T1, typename T2>
istream& operator>>(istream& i, pair<T1, T2>& p) {
  return i >> p.fi >> p.se;
}

// Read containers with 'begin' and 'end' iterators.
template <typename T>
enable_if_t<IsC<T>::value, istream&> operator>>(istream& i, T& v) {
  for (auto& x : v) i >> x;
  return i;
}


///////////////////////////////////////////////////////////////
// Operators
///////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////
// Utility functions.
///////////////////////////////////////////////////////////////

namespace impl {
  template <typename T, typename U, typename F, size_t... Is>
  T zipWith(const T& t, const U& u, F f, index_sequence<Is...>) { 
    return mt((static_cast<tuple_element_t<Is, T>>(f(get<Is>(t), get<Is>(u), Is)))...);
  }

  template <typename T, typename U, typename F, size_t... Is>
  F for_each_2t(T& t, const U& u, F f, index_sequence<Is...>) {
    auto l = { (f(get<Is>(t), get<Is>(u)), 0)... };
    (void) l;
    return f;
  }
}

template <typename... Ts, typename... Us, typename F>
tuple<Ts...> zipWith(const tuple<Ts...>& t, const tuple<Us...>& u, F f) { 
  static_assert(sizeof...(Ts) == sizeof...(Us), "Tuples must be the same size");
  return impl::zipWith(t, u, f, make_index_sequence<sizeof...(Ts)>{});
}

template <typename... Ts, typename... Us, typename F>
F for_each_2t(tuple<Ts...>& t, const tuple<Us...>& u, F f) { 
  static_assert(sizeof...(Ts) == sizeof...(Us), "Tuples must be the same size");
  return impl::for_each_2t(t, u, f, make_index_sequence<sizeof...(Ts)>{});
}

template <typename T> true_type tuple_size_check(typename tuple_size<T>::type*);
template <typename T> false_type tuple_size_check(...);
template <typename T> struct IsT : decltype(tuple_size_check<T>(nullptr)) {};
template <typename T> true_type stream_check(typename T::off_type*);
template <typename T> false_type stream_check(...);
template <typename T> struct IsSt : decltype(stream_check<T>(nullptr)) {};
template <typename T> struct IsS : integral_constant<bool, IsT<T>::value or IsC<T>::value or IsSt<T>::value> {};

#define vAssignmentOpF(name) \
  template <typename T, typename U> \
  vector<T>& name(vector<T>&, const U&); \
  template <typename T, typename U> \
  vector<T>& name(vector<T>&, const vector<U>&);

#define vAssignmentOp(name, op)     \
  template <typename T, typename U> \
  vector<T>& name(vector<T>& v, const U& x) { \
    for (auto& i : v) i op x; \
    return v; \
  } \
  template <typename T, typename U> \
  vector<T>& name(vector<T>& v, const vector<U>& w) { \
    F0R (i, min(SZ(v), SZ(w))) v[i] op w[i]; \
    return v; \
  }

#define vIncDecF(name) \
  template<typename T> \
  vector<T>& name(vector<T>&); \
  template<typename T> \
  vector<T> name(vector<T>&, int);

#define vIncDec(name, op)     \
  template<typename T> \
  vector<T>& name(vector<T>& v) { \
    for (auto& x : v) op x; \
    return v; \
  } \
  template<typename T> \
  vector<T> name(vector<T>& v, int) { \
    vector<T> t{v}; \
    op v; \
    return t; \
  }

#define vBinOpF(name) \
  template <typename T, typename U> \
  vector<T> name(vector<T>, const vector<U>&); \
  template <typename T, typename U> \
  vector<T> name(vector<T>, const U&); \
  template <typename T, typename U> \
  enable_if_t<!IsS<U>::value, vector<T>> \
  name(const U&, vector<T>);

#define vBinOp(name, op) \
  template <typename T, typename U> \
  vector<T> name(vector<T> v, const vector<U>& u) { return v op u; } \
  template <typename T, typename U> \
  vector<T> name(vector<T> v, const U& u) { return v op u; } \
  template <typename T, typename U> \
  enable_if_t<!IsS<U>::value, vector<T>> \
  name(const U& u, vector<T> v) { return v op u; }

#define vBinOpNo(name, op, ex) \
  template <typename T, typename U> \
  vector<T> name(vector<T> v, const vector<U>& u) { return v op u; } \
  template <typename T, typename U> \
  vector<T> name(vector<T> v, const U& u) { return v op u; } \
  template <typename T, typename U> \
  enable_if_t<!IsS<U>::value, vector<T>> \
  name(const U& u, vector<T> v) { for (auto& i : v) i = u ex i; return v; }

#define pAssignmentOpF(name) \
  template <typename T1, typename T2, typename U1, typename U2> \
  pair<T1, T2>& name(pair<T1, T2>&, const pair<U1, U2>&); \
  template <typename T1, typename T2, typename U> \
  pair<T1, T2>& name(pair<T1, T2>&, const U&); 

#define pAssignmentOp(name, op) \
  template <typename T1, typename T2, typename U1, typename U2> \
  pair<T1, T2>& name(pair<T1, T2>& p1, const pair<U1, U2>& p2) { \
    p1.fi op p2.fi; p1.se op p2.se; return p1; \
  } \
  template <typename T1, typename T2, typename U> \
  pair<T1, T2>& name(pair<T1, T2>& p, const U& u) { \
    p.fi op u; p.se op u; return p; \
  }

#define pIncDecF(name) \
  template<typename T1, typename T2> \
  pair<T1, T2>& name(pair<T1, T2>&); \
  template<typename T1, typename T2> \
  pair<T1, T2> name(pair<T1, T2>&, int);

#define pIncDec(name, op) \
  template<typename T1, typename T2> \
  pair<T1, T2>& name(pair<T1, T2>& p) { \
    op p.fi; op p.se; \
    return p; \
  } \
  template<typename T1, typename T2> \
  pair<T1, T2> name(pair<T1, T2>& p, int) { \
    pair<T1, T2> t{p}; \
    op p; \
    return t; \
  }

#define pBinOpF(name) \
  template <typename T1, typename T2, typename U1, typename U2> \
  pair<T1, T2> name(pair<T1, T2>, const pair<U1, U2>&); \
  template <typename T1, typename T2, typename U> \
  pair<T1, T2> name(pair<T1, T2>, const U&); \
  template <typename T1, typename T2, typename U> \
  enable_if_t<!IsS<U>::value, pair<T1, T2>> \
  name(const U&, pair<T1, T2>);

#define pBinOp(name, op) \
  template <typename T1, typename T2, typename U1, typename U2> \
  pair<T1, T2> name(pair<T1, T2> p1, const pair<U1, U2>& p2) { return p1 op p2; } \
  template <typename T1, typename T2, typename U> \
  pair<T1, T2> name(pair<T1, T2> p, const U& u) { return p op u; } \
  template <typename T1, typename T2, typename U> \
  enable_if_t<!IsS<U>::value, pair<T1, T2>> \
  name(const U& u, pair<T1, T2> p) { return p op u; }

#define pBinOpNo(name, op, ex) \
  template <typename T1, typename T2, typename U1, typename U2> \
  pair<T1, T2> name(pair<T1, T2> p1, const pair<U1, U2>& p2) { return p1 op p2; } \
  template <typename T1, typename T2, typename U> \
  pair<T1, T2> name(pair<T1, T2> p, const U& u) { return p op u; } \
  template <typename T1, typename T2, typename U> \
  enable_if_t<!IsS<U>::value, pair<T1, T2>> \
  name(const U& u, pair<T1, T2> p) { p.fi = u ex p.fi; p.se = u ex p.se; }

#define tAssignmentOpF(name) \
  template <typename... Ts, typename U> \
  tuple<Ts...>& name(tuple<Ts...>&, const U&); \
  template <typename... Ts, typename... Us> \
  tuple<Ts...>& name(tuple<Ts...>&, const tuple<Us...>&);

#define tAssignmentOp(name, op)     \
  template <typename... Ts, typename U> \
  tuple<Ts...>& name(tuple<Ts...>& t, const U& u) { \
    for_each(t, [&](auto& x, int) { x op u; }); \
    return t; \
  } \
  template <typename... Ts, typename... Us> \
  tuple<Ts...>& name(tuple<Ts...>& t1, const tuple<Us...>& t2) { \
    for_each_2t(t1, t2, [](auto& x, const auto& y) { x op y; }); \
    return t1; \
  }

#define tIncDecF(name) \
  template<typename... Ts> \
  tuple<Ts...>& name(tuple<Ts...>&); \
  template<typename... Ts> \
  tuple<Ts...> name(tuple<Ts...>&, int);

#define tIncDec(name, op)     \
  template<typename... Ts> \
  tuple<Ts...>& name(tuple<Ts...>& t) { \
    for_each(t,  [](auto& x, int) { op x; }); \
    return t; \
  } \
  template<typename... Ts> \
  tuple<Ts...> name(tuple<Ts...>& t, int) { \
    tuple<Ts...> tp{t}; \
    op t; \
    return tp; \
  }

#define tBinOpF(name) \
  template <typename... Ts, typename... Us> \
  tuple<Ts...> name(tuple<Ts...>, const tuple<Us...>&); \
  template <typename... Ts, typename U> \
  tuple<Ts...> name(tuple<Ts...>, const U&); \
  template <typename... Ts, typename U> \
  enable_if_t<!IsS<U>::value, tuple<Ts...>> \
  name(const U&, tuple<Ts...>);

#define tBinOp(name, op) \
  template <typename... Ts, typename... Us> \
  tuple<Ts...> name(tuple<Ts...> t, const tuple<Us...>& u) {return t op u; } \
  template <typename... Ts, typename U> \
  tuple<Ts...> name(tuple<Ts...> t, const U& u) { return t op u; } \
  template <typename... Ts, typename U> \
  enable_if_t<!IsS<U>::value, tuple<Ts...>> \
  name(const U& u, tuple<Ts...> t) { return t op u; }

#define tBinOpNo(name, op, ex) \
  template <typename... Ts, typename... Us> \
  tuple<Ts...> name(tuple<Ts...> t, const tuple<Us...>& u) {return t op u; } \
  template <typename... Ts, typename U> \
  tuple<Ts...> name(tuple<Ts...> t, const U& u) { return t op u; } \
  template <typename... Ts, typename U> \
  enable_if_t<!IsS<U>::value, tuple<Ts...>> \
  name(const U& u, tuple<Ts...> t) { for_each(t, [&](auto& x, int) { x = u ex x; }); return t; }

// vector forward declarations
vAssignmentOpF(operator+=) vAssignmentOpF(operator-=)
vAssignmentOpF(operator*=) vAssignmentOpF(operator/=) vAssignmentOpF(operator%=)
vAssignmentOpF(operator^=) vAssignmentOpF(operator|=) vAssignmentOpF(operator&=)
vAssignmentOpF(operator<<=) vAssignmentOpF(operator>>=)
vBinOpF(operator+) vBinOpF(operator-)
vBinOpF(operator*) vBinOpF(operator/) vBinOpF(operator%)
vBinOpF(operator^) vBinOpF(operator|) vBinOpF(operator&)
vBinOpF(operator<<) vBinOpF(operator>>)
vIncDecF(operator++) vIncDecF(operator--)
template <typename T> vector<T> operator-(vector<T> v);
template <typename T> vector<T> operator+(vector<T> v);

// pair forward declarations
pAssignmentOpF(operator+=) pAssignmentOpF(operator-=)
pAssignmentOpF(operator*=) pAssignmentOpF(operator/=) pAssignmentOpF(operator%=)
pAssignmentOpF(operator^=) pAssignmentOpF(operator|=) pAssignmentOpF(operator&=)
pAssignmentOpF(operator<<=) pAssignmentOpF(operator>>=)
pBinOpF(operator+) pBinOpF(operator-)
pBinOpF(operator*) pBinOpF(operator/) pBinOpF(operator%)
pBinOpF(operator^) pBinOpF(operator|) pBinOpF(operator&)
pBinOpF(operator<<) pBinOpF(operator>>)
pIncDecF(operator++) pIncDecF(operator--)
template <typename T1, typename T2>
pair<T1, T2> operator-(const pair<T1, T2>& p);
template <typename T1, typename T2>
pair<T1, T2> operator+(const pair<T1, T2>& p);

// tuple forward declarations
tAssignmentOpF(operator+=) tAssignmentOpF(operator-=)
tAssignmentOpF(operator*=) tAssignmentOpF(operator/=) tAssignmentOpF(operator%=)
tAssignmentOpF(operator^=) tAssignmentOpF(operator|=) tAssignmentOpF(operator&=)
tAssignmentOpF(operator<<=) tAssignmentOpF(operator>>=)
tBinOpF(operator+) tBinOpF(operator-)
tBinOpF(operator*) tBinOpF(operator/) tBinOpF(operator%)
tBinOpF(operator^) tBinOpF(operator|) tBinOpF(operator&)
tBinOpF(operator<<) tBinOpF(operator>>)
tIncDecF(operator++) tIncDecF(operator--)
template <typename... Ts> tuple<Ts...> operator-(tuple<Ts...> v);
template <typename... Ts> tuple<Ts...> operator+(tuple<Ts...> v);

// vector implementation
vAssignmentOp(operator+=, +=) vAssignmentOp(operator-=, -=)
vAssignmentOp(operator*=, *=) vAssignmentOp(operator/=, /=) vAssignmentOp(operator%=, %=)
vAssignmentOp(operator^=, ^=) vAssignmentOp(operator|=, |=) vAssignmentOp(operator&=, &=)
vAssignmentOp(operator<<=, <<=) vAssignmentOp(operator>>=, >>=)
vBinOp(operator+, +=) vBinOpNo(operator-, -=, -)
vBinOp(operator*, *=) vBinOpNo(operator/, /=, /) vBinOpNo(operator%, %=, %)
vBinOp(operator^, ^=) vBinOp(operator|, |=) vBinOp(operator&, &=)
vBinOpNo(operator<<, <<=, <<) vBinOpNo(operator>>, >>=, <<)
vIncDec(operator++, ++) vIncDec(operator--, --)
template <typename T> vector<T> operator-(vector<T> v) {
  for (auto& i : v) i = -i;
  return v;
}
template <typename T> vector<T> operator+(vector<T> v) {
  for (auto& i : v) i = +i;
  return v;
}

// pair implementation
pAssignmentOp(operator+=, +=) pAssignmentOp(operator-=, -=)
pAssignmentOp(operator*=, *=) pAssignmentOp(operator/=, /=) pAssignmentOp(operator%=, %=)
pAssignmentOp(operator^=, ^=) pAssignmentOp(operator|=, |=) pAssignmentOp(operator&=, &=)
pAssignmentOp(operator<<=, <<=) pAssignmentOp(operator>>=, >>=)
pBinOp(operator+, +=) pBinOpNo(operator-, -=, -)
pBinOp(operator*, *=) pBinOpNo(operator/, /=, /) pBinOpNo(operator%, %=, %)
pBinOp(operator^, ^=) pBinOp(operator|, |=) pBinOp(operator&, &=)
pBinOpNo(operator<<, <<=, <<) pBinOpNo(operator>>, >>=, <<)
pIncDec(operator++, ++) pIncDec(operator--, --)
template <typename T1, typename T2>
pair<T1, T2> operator-(const pair<T1, T2>& p) { return mp(-p.fi, -p.se); }
template <typename T1, typename T2>
pair<T1, T2> operator+(const pair<T1, T2>& p) { return mp(+p.fi, +p.se); }

// tuple implementation
tAssignmentOp(operator+=, +=) tAssignmentOp(operator-=, -=)
tAssignmentOp(operator*=, *=) tAssignmentOp(operator/=, /=) tAssignmentOp(operator%=, %=)
tAssignmentOp(operator^=, ^=) tAssignmentOp(operator|=, |=) tAssignmentOp(operator&=, &=)
tAssignmentOp(operator<<=, <<=) tAssignmentOp(operator>>=, >>=)
tBinOp(operator+, +=) tBinOpNo(operator-, -=, -)
tBinOp(operator*, *=) tBinOpNo(operator/, /=, /) tBinOpNo(operator%, %=, %)
tBinOp(operator^, ^=) tBinOp(operator|, |=) tBinOp(operator&, &=)
tBinOpNo(operator<<, <<=, <<) tBinOpNo(operator>>, >>=, <<)
tIncDec(operator++, ++) tIncDec(operator--, --)
template <typename... Ts> tuple<Ts...> operator-(tuple<Ts...> t) {
  for_each(t, [](auto& x, int) { x = -x; });
  return t;
}
template <typename... Ts> tuple<Ts...> operator+(tuple<Ts...> t) {
  for_each(t, [](auto& x, int) { x = +x; });
  return t;
}

///////////////////////////////////////////////////////////////
// Begin solution
///////////////////////////////////////////////////////////////

template <class T>
int sign(T a) {
  return (a > 0) - (0 > a);
}
using vll = vector<ll>;
using vit = vll::const_iterator;
struct bigint {
  static const ll base = 1e9;
  int signum;
  vll mag;
  bigint() : signum(0), mag() {}
  bigint(ll val) : signum(sign(val)), mag() {
    val = abs(val);
    while (val) mag.pb(val % base), val /= base;
  }
  bigint(int sig, vll&& m) : signum(sig), mag(m) {
    if (!sig) mag.clear();
    trim();
  }
  bigint(string s) {
    if (s.empty() || s == "0")
      signum = 0;
    else {
      signum = s[0] == '-' ? -1 : 1;
      for (int i = SZ(s) - 1, j = 0, b = 1; ~i && isdigit(s[i]);
           --i, ++j, b *= 10) {
        if (b == base) j = 0, b = 1;
        if (!j) mag.pb(0);
        mag.back() += (s[i] - '0') * b;
      }
    }
  }
  size_t size() const { return mag.size(); }
  static void trim(vll& v) {
    while (SZ(v) && !v.back()) v.pop_back();
  }
  void trim() {
    trim(mag);
    if (mag.empty()) signum = 0;
  }
  ll val(int index) { return index < SZ(mag) ? mag[index] : 0; }
  friend bigint operator-(bigint a) {
    a.signum *= -1;
    return a;
  }
  bigint& operator+=(ll val) {
    bigint t{val};
    return (*this) += t;
  }
  bigint& operator+=(const bigint& other) {
    if (!other.signum) return *this;
    if (!signum) return *this = other;
    if (signum == other.signum)
      add_to(mag, ALL(other.mag));
    else if (less(ALL(mag), ALL(other.mag)))
      signum *= -1, mag = sub(ALL(other.mag), ALL(mag));
    else
      sub_from(mag, ALL(other.mag));
    trim();
    return *this;
  }
  friend bigint operator+(bigint a, const bigint& b) { return a += b; }
  friend bigint operator+(bigint a, ll val) { return a += val; }
  friend bigint operator+(ll val, bigint a) { return a += val; }
  static vll add(vit ab, vit ae, vit bb, vit be) {
    vll out(ab, ae);
    add_to(out, bb, be);
    return out;
  }
  static void add_to(vll& v, vit ob, vit oe) {
    v.resize(max(SZ(v), (int)distance(ob, oe)) + 1);
    for (int i = 0, c = 0; ob != oe || c; ++i) {
      v[i] += (ob != oe ? *ob : 0) + c;
      c = v[i] >= base;
      v[i] %= base;
      if (ob != oe) ++ob;
    }
    trim(v);
  }
  bigint& operator-=(ll val) {
    bigint t{val};
    return (*this) -= t;
  }
  bigint& operator-=(const bigint& other) {
    if (!other.signum) return *this;
    if (!signum) {
      mag = other.mag;
      signum = -1 * other.signum;
      return *this;
    }
    if (signum != other.signum)
      add_to(mag, ALL(other.mag));
    else if (less(ALL(mag), ALL(other.mag)))
      signum *= -1, mag = sub(ALL(other.mag), ALL(mag));
    else
      sub_from(mag, ALL(other.mag));
    trim();
    return *this;
  }
  friend bigint operator-(bigint a, const bigint& b) { return a -= b; }
  friend bigint operator-(bigint a, ll val) { return a -= val; }
  friend bigint operator-(ll val, bigint a) { return a -= val; }
  static vll sub(vit ab, vit ae, vit bb, vit be) {
    // assert(!less(ab, ae, bb, be));
    vll out(ab, ae);
    sub_from(out, bb, be);
    return out;
  }
  static void sub_from(vll& v, vit ob, vit oe) {
    // assert(!less(ALL(v), ob, oe));
    if (ob == oe) return;
    for (int i = 0, c = 0; ob != oe || c; ++i) {
      ll sub = (ob != oe ? *ob : 0) + c;
      c = 0;
      if (v[i] < sub) c = 1, v[i] += base;
      v[i] -= sub;
      if (ob != oe) ++ob;
    }
    trim(v);
  }
  bigint& operator*=(ll val) {
    if (!signum || !val) {
      signum = 0, mag.clear();
      return *this;
    }
    mag = small_mult(ALL(mag), val);
    signum *= sign(val);
    return *this;
  }
  bigint& operator*=(const bigint& other) {
    if (!signum || !other.signum) {
      signum = 0, mag.clear();
      return *this;
    }
    mag = karat_mult(ALL(mag), ALL(other.mag));
    signum *= other.signum;
    return *this;
  }
  friend bigint operator*(bigint a, const bigint& b) { return a *= b; }
  friend bigint operator*(bigint a, ll val) { return a *= val; }
  friend bigint operator*(ll val, bigint a) { return a *= val; }
  static vll karat_mult(vit ab, vit ae, vit bb, vit be) {
    if (ab == ae || bb == be) return vll();
    if (distance(ab, ae) < distance(bb, be))
      swap(ab, bb), swap(ae, be);
    if (distance(bb, be) == 1) return small_mult(ab, ae, *bb);
    int split = distance(ab, ae) / 2;
    vit amid = ab + split,
        bmid = bb + min(split, (int)distance(bb, be));
    vll z0 = karat_mult(ab, amid, bb, bmid);
    vll z2 = karat_mult(amid, ae, bmid, be);
    vll x1x0 = add(ab, amid, amid, ae);
    vll y1y0 = add(bb, bmid, bmid, be);
    vll z1 = karat_mult(ALL(x1x0), ALL(y1y0));
    sub_from(z1, ALL(z2));
    sub_from(z1, ALL(z0));
    vll out(max({SZ(z0), split + SZ(z1), split * 2 + SZ(z2)}) + 1);
    auto add = [&](vll& v, int offset) {
      for (int i = 0, c = 0; i < SZ(v) || c; ++i) {
        out[i + offset] += (i < SZ(v) ? v[i] : 0) + c;
        c = out[i + offset] >= base;
        out[i + offset] %= base;
      }
    };
    add(z0, 0);
    add(z1, split);
    add(z2, split * 2);
    trim(out);
    return out;
  }
  static vll small_mult(vit ab, vit ae, ll fac) {
    if (ab == ae || fac == 0) return vll();
    vll out(ab, ae);
    ll c = 0;
    for (int i = 0; i < SZ(out) || c; ++i) {
      if (i == SZ(out)) out.pb(0);
      out[i] = out[i] * fac + c;
      c = out[i] / base;
      out[i] %= base;
    }
    trim(out);
    return out;
  }
  friend bool operator<(const bigint& a, const bigint& b) {
    if (a.signum != b.signum) return a.signum < b.signum;
    if (!a.signum) return false;
    int c = cmp(ALL(a.mag), ALL(b.mag));
    return a.signum > 0 ? c < 0 : c > 0;
  }
  static int less(vit ab, vit ae, vit bb, vit be) {
    return cmp(ab, ae, bb, be) < 0;
  }
  static int cmp(vit ab, vit ae, vit bb, vit be) {
    if (ab == ae && bb == be) return 0;
    auto cmp = sign(distance(ab, ae) - distance(bb, be));
    if (cmp) return cmp;
    do {
      ae = prev(ae), be = prev(be);
      cmp = sign(*ae - *be);
    } while (!cmp && ae != ab);
    return cmp;
  }
  friend string to_string(const bigint& bi) {
    if (!bi.signum) return "0";
    stringstream ss;
    ss << bi.signum * bi.mag.back();
    for (int i = SZ(bi) - 2; ~i; --i)
      ss << setfill('0') << setw(9) << bi.mag[i];
    return ss.str();
  }
  friend istream& operator>>(istream& i, bigint& bi) {
    string s;
    i >> s;
    bi = bigint(s);
    return i;
  }
  friend ostream& operator<<(ostream& o, const bigint& bi) {
    return o << to_string(bi);
  }
};



ll gaus(int n) {
    return (ll)n*(n + 1)/2;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    ll sum = 0;
    while(n--) {
        int a, b;
        cin >> a >> b;
        sum += gaus(b) - gaus(a - 1);
    }
    cout << sum;
}
