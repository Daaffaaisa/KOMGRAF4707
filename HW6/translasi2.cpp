#include <iostream>
#include <iomanip>
using namespace std;

void translasi(int &x, int &y, int tx1, int ty1, int tx2, int ty2) 
{
    x += tx1;
    y += ty1;
    x += tx2;
    y += ty2;
}

int main() 
{

    int x = 1, y = 4;

    // Vektor translasi
    int tx1 = 7, ty1 = 6;
    int tx2 = 7, ty2 = 1;

    cout << "Koordinat awal: P(" << x << ", " << y << ")\n";

    // Melakukan translasi
    translasi(x, y, tx1, ty1, tx2, ty2);

    // Menampilkan matriks
    cout << "Koordinat setelah translasi: P(" << x << ", " << y << ")\n";
    cout << "Matriks translasi:\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) 
        {
            if (i == j) 
            {
                if (i == 2) 
                {
                    cout << setw(4) << 1;
                } 
                else 
                {
                    cout << setw(4) << 1;
                }
            } 
            else if (j == 2) 
            {
                if (i == 0) 
                {
                    cout << setw(4) << tx1;
                } 
                else if (i == 1) {
                    cout << setw(4) << tx2;
                } 
                else 
                {
                    cout << setw(4) << 0;
                }
            } 
            else 
            {
                cout << setw(4) << 0;
            }
        }
        cout << "\n";
    }

    return 0;
}
