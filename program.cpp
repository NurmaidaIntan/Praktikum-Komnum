#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <cctype>
using namespace std;

class falsi{
    string teks;
    int indeks;
    double nilai_x;
    double operasi1(){
        double hasil = operasi2();
        while (indeks < teks.length()){
            if (teks[indeks] == '+'){
                indeks++;
                hasil += operasi2();
            }
            else if (teks[indeks] == '-'){
                indeks++;
                hasil -= operasi2();
            }
            else break;
        }
        return hasil;
    }

    double operasi2(){
        double hasil = faktor();
        while (indeks < teks.length()){
            if (teks[indeks] == '*'){
                indeks++;
                hasil *= faktor();
            }
            else if (teks[indeks] == '/'){
                indeks++;
                hasil /= faktor();
            }
            else break;
        }
        return hasil;
    }

    double faktor(){
        if (indeks >= teks.length()) return 0;
        if (teks[indeks]== '+'){
            indeks++;
            return faktor();
        }
        if (teks[indeks]== '-'){
            indeks++;
            return -faktor();
        }

        double hasil = 0;
        if (teks[indeks]== '('){
            indeks++;
            hasil = operasi1();
            if (indeks < teks.length() && teks[indeks] == ')') indeks++;
        }
        else if (isalpha(teks[indeks])){
            string huruf = "";
            while (indeks < teks.length() && isalpha(teks[indeks])){
                huruf += teks[indeks++];
            }
            if (huruf == "x"){
                hasil = nilai_x;
            }
            else if (huruf == "e"){
                hasil = 2.718281828459045;
            }
            else if (huruf == "sin"){
                if (teks[indeks]== '('){
                    indeks++;
                    hasil = sin(operasi1());
                    if (indeks < teks.length() && teks[indeks] == ')') indeks++;
                }
            }
            else if (huruf == "cos"){
                if (teks[indeks]== '('){
                    indeks++;
                    hasil = cos(operasi1());
                    if (indeks < teks.length() && teks[indeks] == ')') indeks++;
                }
            }
            else if (huruf == "exp"){
                if (teks[indeks] == '('){
                    indeks++;
                    hasil = exp(operasi1());
                    if (indeks < teks.length() && teks[indeks] == ')') indeks++;
                }
            }
            else if (huruf == "ln"){
                if (teks[indeks] == '('){
                    indeks++;
                    hasil = log(operasi1());
                    if (indeks < teks.length() && teks[indeks] == ')') indeks++;
                }
            }
        }
        else if (isdigit(teks[indeks]) || teks[indeks] == '.'){
            string angka = "";
            while (indeks < teks.length() && (isdigit(teks[indeks]) || teks[indeks] == '.')){
                angka += teks[indeks++];
            }
            hasil = stod(angka);
        }

        if (indeks < teks.length() && teks[indeks] == '^'){
            indeks++;
            hasil = pow(hasil, faktor());
        }
        return hasil;
    }

public:
    void setExpression(string e){
        teks = "";
        for (char k : e){
            if (k != ' ') teks += k;
        }
    }
    double evaluasi(double x){
        nilai_x = x;
        indeks = 0;
        return operasi1();
    }
};

int main(){
    falsi hitung;
    string input_fungsi;
    double a, b, c, fa, fb, fc, error;
    int maks_iterasi, iterasi = 1;
    cout << "Masukkan fungsi f(x)     : ";
    getline(cin, input_fungsi);
    hitung.setExpression(input_fungsi);
    cout << "Masukkan selang awal a   : "; cin >> a;
    cout << "Masukkan selang awal b   : "; cin >> b;
    cout << "Masukkan batas toleransi : "; cin >> error;
    cout << "Masukkan maks iterasi    : "; cin >> maks_iterasi;
    fa = hitung.evaluasi(a);
    fb = hitung.evaluasi(b);

    if (fa * fb > 0.0){
        cout << "\nError: Selang awal tidak mengurung akar.\n";
        return 0;
    }
    cout << "\n";
    cout << setw(10) << "Iterasi"
         << setw(15) << "a"
         << setw(15) << "b"
         << setw(15) << "c"
         << setw(20) << "f(c)" << "\n";
    cout << "---------------------------------------------------------------------------\n";
    do{
        fa = hitung.evaluasi(a);
        fb = hitung.evaluasi(b);
        c = b - (fb*(b-a)) / (fb-fa);
        fc = hitung.evaluasi(c);
        cout << setw(10) << iterasi << fixed << setprecision(4)
             << setw(15) << a
             << setw(15) << b
             << setw(15) << c
             << setw(20) << fc << "\n";
        if (abs(fc) <= error){
            break;
        }
        if (fa * fc < 0){
            b = c;
        } else{
            a = c;
        }
        iterasi++;
    }
    while (iterasi <= maks_iterasi);
    cout << "---------------------------------------------------------------------------\n";
    cout << "\nKesimpulan:\n";
    if (iterasi > maks_iterasi){
        cout << "Akar Pendekatan (c) = " << c << " (Mencapai batas iterasi maksimum)\n";
    }
    else{
        cout << "Akar persamaan (c) = " << c << "\n";
        cout << "Berhasil ditemukan pada iterasi ke-" << iterasi << "\n";
    }
    return 0;
}
