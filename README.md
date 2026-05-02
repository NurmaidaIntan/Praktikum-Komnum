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
