#include <stdio.h>
#include <assert.h>
#include <math.h>

using namespace std;
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>

typedef pair<int, int> point;

float  area(const point& x, const point& y)
{
    float ar = x.first * y.second - x.second * y.first;
    return ar;
}

float area2(const vector<point>& points)
{
    assert(points.size() == 3);

    float a2 = area(points[0], points[1]); 
    a2 += area(points[1], points[2]);
    a2 += area(points[2], points[0]);
    
    return a2;
}

bool to_left_test(const vector<point>& points)
{
    return area2(points) >= 0;
}

point find_ltl_point(const vector<point>& points)
{
    int xmin = pow(10, 5), ymin = pow(10, 5); 
    int argymin = -1;

    for (int k = 0; k < points.size(); k++)
    {
        ymin = std::min<int>(ymin, points[k].second); 
    }

    vector<point> ltls;
    for (int k = 0; k < points.size(); k++)
    {
        if (ymin == points[k].second)
            ltls.push_back(points[k]);
    }

    point ltl; 
    for (int k = 0; k < points.size(); k++)
    {
        if (xmin > points[k].first){
            xmin = points[k].first;
            ltl = points[k];
        }
    }

    return ltl;
}

float angle(const point & p1, const point & p2)
{
    float dotp = 0;
    float x = (p2.first - p1.first);
    float y = (p2.second - p1.second);
    float norm = x*x + y*y;
    float a = x / sqrt(norm);
    return acos(a);
}

inline bool comp(const pair<point, float>& a, const pair<point, float>& b){
    return a.second > b.second;
}

vector<pair<point, size_t>> sort_in_angle(const vector<point> & points)
{
    point ltl = find_ltl_point(points);

    vector<pair<point, float>> angles; 
    for (auto p : points)
    {
        if (p == ltl)
            angles.push_back(make_pair(p, 0.0));
        else{
            float g = angle(ltl, p);
            angles.push_back(make_pair(p, g));
        }
    }

    vector<size_t> idx(angles.size());
    for (size_t i = 0; i != idx.size(); ++i) idx[i] = i;

//    std::sort(angles.begin(), angles.end(), comp);
    std::sort(idx.begin(), idx.end(), [&angles](size_t i1, size_t i2){return angles[i1].second > angles[i2].second; }); 
    
    vector<pair<point, size_t>> vsorted; 
    for (auto p : idx)
        vsorted.push_back(make_pair(angles[p].first, p));

    return vsorted;
}

vector<pair<point, size_t>> graham_scan(const vector<pair<point, size_t>>& points)
{
    vector<pair<point, size_t>> t = points; 
    vector<pair<point, size_t>> s;

    s.push_back(t.back());
    t.pop_back();
    s.push_back(t.back());
    t.pop_back();

    while (t.size() > 0)
    {
        pair<point , size_t> t_top = t.back();
        pair<point, size_t> s1 = s[s.size() - 1];
        pair<point, size_t> s0 = s[s.size() - 2];

        vector<point> vobs; 
        vobs.push_back(s0.first); vobs.push_back(s1.first); vobs.push_back(t_top.first);

        if (to_left_test(vobs))
        {
            s.push_back(t_top);
            t.pop_back();
        }
        else
        {
            s.pop_back();
        }
    }

    return s;
}

int main(int argc, char** argv) {
  
    vector<point> points;
    /*
    points.push_back(make_pair(7, 9));
    points.push_back(make_pair(-8, -1));
    points.push_back(make_pair(-3, -1));
    points.push_back(make_pair(1, 4));
    points.push_back(make_pair(-3, 9));
    points.push_back(make_pair(6, -4));
    points.push_back(make_pair(7, 5));
    points.push_back(make_pair(6, 6));
    points.push_back(make_pair(-6, 10));
    points.push_back(make_pair(0, 8));
    */

/*    string fname = argv[1];

    ifstream ifs;
    ifs.open(fname.c_str());
    */
    int npoint; 
    cin >> npoint; 
    for (int k = 0; k < npoint; k++)
    {
        int x, y;
        cin >> x >> y;
        points.push_back(make_pair(x, y));
    }
//    ifs.close();

    vector<pair<point, size_t>> sorted = sort_in_angle(points);
    vector<pair<point,size_t>> cvx_hull = graham_scan(sorted);

    /// output ( s1 * s2 * s3 * ... * sh * h ) mod (n + 1)
    size_t o = 1;
    for (auto p : cvx_hull)
    {
        o *= (p.second + 1);
    }
    o *= cvx_hull.size();
    o = fmod(o, points.size() + 1);

    cout << o;

    return o;
}

