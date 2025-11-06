#include <bits/stdc++.h>
using namespace std;

const double phi = 3.1416;

double distance(double x1, double y1, double x2, double y2) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    return sqrt(dx*dx + dy*dy);
}

double radius(double x_pusat, double y_pusat , double x_padalingkaran, double y_padalingkaran) {
    return distance(x_pusat, y_pusat , x_padalingkaran, y_padalingkaran);
}

double circumference(double r) {
    return 2 * phi * r;
}

double area(double r) {
    return phi * r * r;
}

int main() {
    double x_pusat, y_pusat , x_padalingkaran, y_padalingkaran;
    cout << "Masukkan koordinat pusat lingkaran (x_pusat, y_pusat ): ";
    cin >> x_pusat >> y_pusat ;
    cout << "Masukkan koordinat titik pada lingkaran (x_padalingkaran, y_padalingkaran): ";
    cin >> x_padalingkaran >> y_padalingkaran;

    double r = radius(x_pusat, y_pusat , x_padalingkaran, y_padalingkaran);
    double d = 2 * r;
    double keliling = circumference(r);
    double luas = area(r);

    cout << "Hasil        :" << endl;
    cout << "Radius       : " << r << endl;
    cout << "Diameter     : " << d << endl;
    cout << "Circumference: " << keliling << endl;
    cout << "Area         : " << luas << endl;

    return 0;
}
