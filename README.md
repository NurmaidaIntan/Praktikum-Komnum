# LAPORAN PRAKTIKUM KOMPUTASI NUMERIK 

<div align="center">
   
| NAMA | NRP |
| :---: | :---: |
| Nurmaida Intan Permadani | 5025251040 |
| Sanchia Revana Koasasi | 5025251060 |
| Rida Izzati Azzahra | 5025251065 |

</div>

# BAB 1 PENDAHULUAN
## Latar Belakang

Dalam bidang sains dan teknik, seringkali ditemukan persamaan non - linear kompleks yang sulit atau bahkan tidak mungkin diselesakan menggunakan metode analitik biasa (seperti pemfaktoran atau rumus kuadrat). Oleh karena itu, penggunaan metode numerik menjadi solusi esensial unuk mendapatkan akar persamaan melalui pendekatan iteratif. Salah satu metode yang paling stabil dalam kategori metode tertutup (bracketing method) adalah metode Regula Falsi (Posisi Palsu).

Metode Regula Falsi merupakan pengembangan dari metode Biseksi. Jika metode Biseksi selalu membagi rentang menjadi dua bagian sama besar tanpa mempedulikan nilai fungsi, Regula Fali memanfaatkan kemiringan garis yang menghubungkan dua titik batas untuk memperkirakan letak akar dengan lebih akurat. Hal ini secara teoritis memungkinkan konvergensi yang lebih cepat dibandingkan biseksi pada banyak kasus fungsi non - linear. Melalui praktikum ini, pemahaman mengenai algoritma pencarian akar akan diimplementasikan ke dalam kode program untuk mengamati efisiensi dan akurasi komputasi dari metode tersebut.


## Tujuan Praktikum 

1. Memahami konsep dasar dan logika matematika di balik metoe Regula Falsi
2. Mampu mengimplementasikan algoritma Regula Falsi ke dalam bahasa C++


# BAB 2 ALGORITMA
## Langkah-Langkah
Algoritma program ini berjalan sesuai dengan ketentuan Metode Regulasi Falsi yang mana sebagai berikut:
1. Mulai Program.
2. Definisikan fungsi f(x) yang akan dicari akarnya.
3. Tentukan nilai tebakan awal untuk batas bawah (a) dan batas atas (b).
4. Tentukan nilai batas toleransi dan batas maksimum iterasi.
5. Hitung nilai evaluasi fungsi pada titik tebakan awal, yaitu f(a) dan f(b).
6. Jika hasil perkalian f(a) dan f(b) > 0, maka tampilkan pesan error sedangkan sebaliknya lanjut ke langkah berikutnya.
7. Inisialisasi variabel iterasi dari angka 1.
8. Lakukan perulangan selama iterasi masih lebih kecil atau sama dengan batas maksimum iterasi.
9. Hitung nilai titik akar pendekatan baru (c) dengan menggunakan rumus Regulasi Falsi:
   c = b - (f(b)(b-a))/(f(b)-f(a))
10. Hitung nilai fungsi f(c).
11. Cetak hasil a, b, c, dan f(c) pada tabel.
12. Jika |f(c)| ≤ batas toleransi, maka perulangan dihentikan dan akar yang ditemukan dicetak.
13. Jika masih belum mencapai batas toleransi cek:
    - f(a).f(b) < 0 maka akar berada antara a dan c serta ubah nilai batas atas b = c.
    - jika f(a).f(b) > 0 maka akar berada antara c dan b serta ubah nilai batas bawah a = c.
    - Tambah nilai iterasi = iterasi + 1
16. Tampilkan kesimpulan nilai c terakhir sebagai akar persamaan dari fungsi f(x).
17. Selesai.

# BAB 3 IMPLEMENTASI PROGRAM
## Penjelasan Program

Dalam program kali ini, untuk mencapai hasil yang akurat, iteratif, dan efisien diperlukan beberapa library untuk menunjang terbentuknya hasil yang maksimal. Library itu sendiri adalah sebagai berikut:
| LIBRARY | FUNGSI |
| :---: | :---: |
| iostream | I/O standar |
| iomanip | mengatur tampilan output |
| cmath | fungsi matematika |
| string | memproses tipe data string |
| cctype | mengecek tipe karakter |

Selanjutnya, kita akan masuk ke `class falsi` untuk mengubah string menjadi sebuah nilai numerik. Pertama kita akan menyimpan rumus yang telah dimasukkan oleh user dengan `string teks`, menginisialisasi karakter yang sedang diproses dengan `indeks` dan  menggantikan variabel `x` dengan `double nilai_x`.
```cpp
string teks;
    int indeks;
    double nilai_x;
    double operasi1(){
```
Kemudian kita lanjutkan untuk membuat beberapa fungsi operasi yang mewakili setiap operasi matematika yang akan terjadi. Pada `operasi()` kita akan membuat fungsi untuk penjumlahan dan pengurangan. Di mana di dalam fungsi ini kita akan mengambil hasil dari `operasi2()` terlebih dahulu sesuai dengan prioritas (perkalian/pembagian didahulukan) lalu kita akan melakukkan loop sampai akhir dari string. Di dalam loop ini sendiri kita akan masuk ke dalam percabangan jika teks yang didapatkan adalah `teks[indeks] == '+'` indeks akan bertambah dan hasilnya ditambahkan dengan hasil operasi berikutnya, begitu juga dengan `teks[indeks] == '-'` indeks akan bertambah dengan hasil yang dikurangi dengan hasil berikutnya. Diakhiri dengan `break` dan `return hasil` untuk mengirimkan hasilnya.
```cpp
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
```
Operasi yang kedua adalah operasi perkalian dan pembagian. Sama seperti sebelumnya, kita akan memanggil fungsi `faktor()` untuk kita masukkan ke dalam hasil sesuai dengan urutan prioritas. Lalu kita _loop_ sampai teks berakhir untuk masuk ke dalam percabangan. Jika hasilnya adalah `teks[indeks] == '*'`, maka indeks bertambah dan hasil akan dikalikan dengan hasil faktor berikutnya. Dan jika `teks[indeks] == '/'`, indeks akan bertambah juga dengan hasil yang dibagi faktor berikutnya.
```cpp
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
```
Kemudian kita akan masuk ke fungsi terakhir, yaitu `faktor()`. Sebagai base case, jika ideks sudah lebih dari sama dengan panjang teks, maka akan kita `return 0`. Untuk menangani tanpa positif dan negatif di depan angka, akan kita buat percabangan yang jika `teks[indeks]== '+'` indeks akan bertambah dan kita return fungsi seperti biasa, sedangkan jika `teks[indeks]== '-'` akan kita return fungsi yang sudah diminuskan. Lalu kita inisialisasi hasil awal dengan 0 sebelum masuk ke percabangan berikutnya. Jika didapatkan `teks[indeks]== '('` maka akan memanggil `operasi1()` lalu kita lewati kurung tutup untuk menuju indeks selanjutnya. Jika ditemukan karakter adalah huruf dengan `isalpha(teks[indeks])`, kita inisialisasi huruf diawal sebelum masuk ke _loop_ yang akan berjalan selama panjang loop dan merupakan huruf untuk mengambil karakter huruf dan menambahkannya ke dalam string huruf yang sudah kita inisialisasi tadi. Ketika sudah keluar, maka akan masuk ke dalam percabangan yang mengecek apakah `huruf == "x"` untuk variabel x, `huruf == "e"` untuk konstanta e, atau berupa trigonometri seperti `sin` yang kemudian akan masuk percabangan jika ditemukan kurung buka lalu memanggil fungsi sin dari operasi1, begitu juga `cos`, `exp` untuk exponensial, dan `ln` untuk logaritma. Namun, jika karakter adalah angka `isdigit(teks[indeks]) || teks[indeks] == '.'`, maka program akan mengambil seluruh angka tersebut dan mengubahnya menjadi double menggunakan `stod()`. Terakhir, jika operasi berupa pangkat `^` maka akan kita panggil fungsi `pow()` untuk membantu mengoperasikan yang kemudian hasil dari semua ini akan kita `return`.
```cpp
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
```
Masuk ke dalam bagian `public`, pertama kita akan membuat fungsi `setExpression(string e)` untuk menghapis spasi dari inputan dan menyimpannya ke dalam variabel `teks`. Kita buat juga fungsi `evaluasi(double x)` untuk menghitung nilai f(x) dengan meriset indeks ke 0 dan memulai operasi dari `operas1()`.
```cpp
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
```
Ketika semua operasi dan fungsi pembantu sudah siap, kita akan mulai untuk memogramkan logika regulasi falsi di dalam fungsi `main()`. Kita inisialisasi terlebih dahulu seperti objek dari class `falsi` berupa `hitung`, `input_fungsi` untuk inputan fungsi dari user, `double a` untuk batas bawah, `b` batas atas, `c` estimasi nilai akar, `fa` hasil evaluasi a, `fb` hasil evaluasi b, `fc` hasil evaluasi c, `error` toleransi error, `int maks_iterasi` maksimal iterasi, dan `iterasi = 1` untuk memulai. Lalu kita minta inputan dari user terkait a, b, error, dan maks_iterasi yang dilanjutnya dengan memasukkan hasil `hitung.evaluasi()` kedalam fa dan fb.
```cpp
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
```
Kemudian kita cek terlebih dahulu apakah fa dan fb sudah berbeda tanda atau tidak dengan `fa * fb > 0.0`. Jika tidak berbeda tanda makan akan keluar output error dan langsung `return 0`. Lanjut kita akan ouputkan terlebih dahulu header tabel dengan bantuan `setw()`.

Untuk mengisi tabel itu sendiri, kita akan melakukan perulangan yang akan menghitung nilai c dengan rumus `c = b - (fb*(b-a)) / (fb-fa)` lalu kita hitung nilai fungsinya di titik baru c sebelum kita tampilkan tabel iterasi dengan `cout`. Jika nilai f(c) sudah mendekati nol yang kurang dari toleransi error, akar ditemukan dan loop berhenti. Namun, jika tidak maka akan kita tentutkan selang baru untuk iterasi selanjutnya dengan ketentuan jika fa dikali dengan fc kurang dari 0, maka selang atas akan menjadi c, sebaliknya maka selang bawah akan menjadi c. Kita tambahkan iterasinya dan kita _loop_ hingga iterasi mencapai batas maksimal iterasi.
```cpp
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
```
Terakhir, kita akan menampilkan hasil iterasi yang jika iterasi lebih dari batas maka akan muncul `"Akar Pendekatan (c) = " << c << " (Mencapai batas iterasi maksimum)\n"`. Namun jika sudah ditemukan hasilnya maka akan ditampilkan hasil akarnya dan pada iterasi keberapa akar tersebut ditemukan.
```cpp
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
```
## Program
```cpp
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
```
## Output Program
<img width="1067" height="546" alt="image (30)" src="https://github.com/user-attachments/assets/bba62ae9-d96c-4549-9123-6128a93d27aa" />
