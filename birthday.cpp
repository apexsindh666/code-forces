#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>
 
using namespace std;
 
// Define PI explicitly to avoid compilation errors with M_PI across different compilers
const double PI = acos(-1.0);
 
// Structure to represent a 2D point with integer coordinates
struct Point {
    long long x, y;
    
    // Sort lexicographically by x, then by y
    bool operator<(const Point& p) const {
        return x < p.x || (x == p.x && y < p.y);
    }
};
 
// Cross product of vectors OA and OB
// Returns positive if CCW, negative if CW, 0 if collinear
long long cross(const Point& O, const Point& A, const Point& B) {
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}
 
// Computes the 2D cross product of vector (0,0)->A and (0,0)->B
// Equivalent to x1*y2 - x2*y1
long long origin_cross(const Point& A, const Point& B) {
    return A.x * B.y - B.x * A.y;
}
 
int main() {
    // Optimize standard I/O operations for fast execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n;
    double r;
    if (!(cin >> n >> r)) return 0;
 
    vector<Point> pts(n);
    for (int i = 0; i < n; ++i) {
        cin >> pts[i].x >> pts[i].y;
    }
 
    // Step 1: Build the Convex Hull using Monotone Chain Algorithm
    sort(pts.begin(), pts.end());
 
    vector<Point> hull;
    
    // Build lower hull
    for (int i = 0; i < n; ++i) {
        while (hull.size() >= 2 && cross(hull[hull.size() - 2], hull.back(), pts[i]) <= 0) {
            hull.pop_back();
        }
        hull.push_back(pts[i]);
    }
 
    // Build upper hull
    size_t lower_size = hull.size();
    for (int i = n - 2; i >= 0; --i) {
        while (hull.size() > lower_size && cross(hull[hull.size() - 2], hull.back(), pts[i]) <= 0) {
            hull.pop_back();
        }
        hull.push_back(pts[i]);
    }
 
    // Remove the last element because it's the same as the first vertex
    if (hull.size() > 1) {
        hull.pop_back();
    }
 
    // Step 2: Determine optimal cutting distance d from the origin (0,0)
    double min_d = 0.0;
 
    // If the hull has fewer than 3 vertices, it has no 2D interior area,
    // so the origin cannot be strictly trapped inside. We can cut directly through (0,0).
    if (hull.size() >= 3) {
        bool strictly_inside = true;
        double closest_edge_dist = 1e18;
        int m = (int)hull.size();
 
        for (int i = 0; i < m; ++i) {
            Point A = hull[i];
            Point B = hull[(i + 1) % m];
 
            long long cp = origin_cross(A, B);
 
            // Since the hull is counter-clockwise, if the origin is on the right
            // or directly on any edge vector, it is NOT strictly inside the polygon.
            if (cp <= 0) {
                strictly_inside = false;
                break;
            }
 
            // Calculate perpendicular distance from (0,0) to edge AB
            double dx = (double)(B.x - A.x);
            double dy = (double)(B.y - A.y);
            double edge_len = sqrt(dx * dx + dy * dy);
            double dist = (double)cp / edge_len;
 
            if (dist < closest_edge_dist) {
                closest_edge_dist = dist;
            }
        }
 
        // Only push the cut line away from the center if the origin is strictly trapped inside
        if (strictly_inside) {
            min_d = closest_edge_dist;
        }
    }
 
    // Step 3: Calculate the maximum area of the smaller cake piece
    double area = 0.0;
    
    if (min_d == 0.0) {
        // Cut passes through the center: exactly half the circle
        area = 0.5 * PI * r * r;
    } else if (min_d < r) {
        // Calculate circular segment area at distance min_d from center
        // Formula: r^2 * arccos(d/r) - d * sqrt(r^2 - d^2)
        area = r * r * acos(min_d / r) - min_d * sqrt(r * r - min_d * min_d);
    } else {
        // If distance exceeds or equals radius, the smaller piece area is 0
        area = 0.0;
    }
 
    // Print the result with required precision (10^-6 tolerance)
    cout << fixed << setprecision(15) << area << "\n";
 
    return 0;
}