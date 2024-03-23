struct P {
    ll x, y;

    P(){}
    P(ll x, ll y) : x(x), y(y) {}
    void read() { cin >> x >> y; }

    P operator - (const P& b) const {
        return P(x - b.x, y - b.y);
    }

    ll operator * (const P& b) const {
        return x * b.y - y * b.x;
    }

    void operator -= (const P& b) {
        x -= b.x, y -= b.y;
    }

    bool operator < (const P& b) const {
        return make_pair(x, y) < make_pair(b.x, b.y);
    }

    ll triangle(const P& b, const P& c) const {
        return (b - *this) * (c - *this);
    }

    bool inside(const P& b, const P& c) const { // point inside segment
        return x >= min(b.x, c.x) && x <= max(b.x, c.x) 
                && y >= min(b.y, c.y) && y <= max(b.y, c.y);
    }
};

bool intersect(P a, P b, P c, P d) { // line intersection
    if ((b - a) * (d - c) == 0) { 
        if (a.triangle(c, d) != 0) return false;
        return a.inside(c, d) || b.inside(c, d) || c.inside(a, b) || d.inside(a, b);
    }
    for (int rep = 0; rep < 2; rep ++) {
        ll o1 = a.triangle(b, c);
        ll o2 = a.triangle(b, d);
        if (o1 < 0 && o2 < 0) return false;
        if (o1 > 0 && o2 > 0) return false;
        swap(a, c);
        swap(b, d);
    }
    return true;
}   

vector<P> convex_hull(vector<P>& points) {
    sort(points.begin(), points.end());

    vector<P> hull_top;
    for (P C : points) {
        while (hull_top.size() >= 2) {
            P A = hull_top[(int)hull_top.size()-2];
            P B = hull_top[(int)hull_top.size()-1];

            if (A.triangle(B, C) <= 0) break;
            hull_top.pop_back();
        }
        hull_top.push_back(C);
    }

    reverse(points.begin(), points.end());

    vector<P> hull_bottom;
    for (P C : points) {
        while (hull_bottom.size() >= 2) {
            P A = hull_bottom[(int)hull_bottom.size()-2];
            P B = hull_bottom[(int)hull_bottom.size()-1];

            if (A.triangle(B, C) <= 0) break;
            hull_bottom.pop_back();
        }
        hull_bottom.push_back(C);
    }

    vector<P> hull;
    for (int i = 0; i < (int)hull_top.size() - 1; i ++) hull.push_back(hull_top[i]);
    for (int i = 0; i < (int)hull_bottom.size() - 1; i ++) hull.push_back(hull_bottom[i]);
    
    return hull;
}
