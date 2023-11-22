#include <iostream>
#include <iomanip>
using namespace std;


void translasi(int &x, int &y, int tx, int ty) 
{
    x += tx;
    y += ty;
}

int main() 
{
    // Koordinat titik P
    int x = 2, y = 4;

    // Vektor translasi
    int tx = 3, ty = 5;

    // Menampilkan koordinat awal
    cout << "Koordinat awal: P(" << x << ", " << y << ")\n";

    // Melakukan translasi
    translasi(x, y, tx, ty);


    // Menampilkan matriks
    // Menggunakan setw(4) untuk membuat lebar tetap pada setiap elemen matriks
    cout << "Koordinat setelah translasi: P(" << x << ", " << y << ")\n";
    cout << "Matriks translasi:\n";
    for (int i = 0; i < 3; ++i) 
    {
        for (int j = 0; j < 3; ++j) 
        {
            if (i == j) 
            {
                cout << setw(4) << 1;
            } else if (j == 2) 
                {
                    cout << setw(4) << ((i == 0) ? tx : ty);
                } else 
                    {
                        cout << setw(4) << 0;
                    }
        }
        cout << "\n";
    }

    return 0;
}
