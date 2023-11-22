#include <iostream>
#include <iomanip>
using namespace std;

void skala(int &x, int &y, int sx, int sy) 
{
    x *= sx;
    y *= sy;
}

int main() 
{

    int x = 2, y = 4;

    // Faktor skala
    int sx = 3, sy = 3;


    cout << "Koordinat awal: P(" << x << ", " << y << ")\n";

    // Melakukan skala
    skala(x, y, sx, sy);

    // Menampilkan matriks
    // Menggunakan setw(4) untuk membuat lebar tetap pada setiap elemen matriks
    cout << "Koordinat setelah skala: P(" << x << ", " << y << ")\n";
    cout << "Matriks skala:\n";
    for (int i = 0; i < 3; ++i) 
    {
        for (int j = 0; j < 3; ++j) 
        {
            if (i == j) 
            {
                cout << setw(4) << ((i == 0) ? sx : ((i == 1) ? sy : 1));
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
