# LAPORAN PRAKTIKUM KOMPUTASI NUMERIK 

Nama Anggota : 
1. Nurmaida Intan Permadani     5025251040
2. Sanchia Revana Koasasi	      5025251060
3. Rida Izzati Azzahra		      5025251065

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

