# Tugas Kecil 1 Strategi Algoritma
> Word Puzzle Solver: Program ini merupakan program yang dapat menyelesaikan word puzzle secara brute force dari input file user. Word Puzzle dicari berdasarkan delapan arah, yaitu horizontal ke kanan, horizontal ke kiri, vertical ke bawah, vertical ke atas, diagonal utama ke kanan bawah, diagonal utama ke kiri atas, diagonal samping ke kiri bawah dan diagonal samping ke kanan atas. Pada akhir program, akan ditampilkan word puzzle yang telah diwarnai huruf-huruf yang bersesuaian dengan kata yang dicari. Program ini dibuat untuk memenuhi tugas kecil 1 mata kuliah Strategi Algoritma semester genap tahun 2021/2022

## Technologies Used
- Bahasa: C++ (utama), shell (membantu compile dan run)

## Features
- Menerima input user file word puzzle mana yang akan dicek
- Memberikan validasi jika file tidak ada
- Membaca file word puzzle lalu mengolahnya serta menampilkan word puzzle yang telah diwarnai huruf-hurufnya sesuai dengan kata-kata yang dicari
- Menampilkan berapa banyak komparasi yang dibutuhkan serta waktu pengolahan word puzzle

## Setup
- Program ini berhasil dijalankan dan dites di **OS Windows 10** dan dengan compiler **GNU C++ (G++) versi 9.2.0**
- Program **belum sepenuhnya** dites pada environment lain dan tidak dispesifikasikan untuk dapat dijalankan di semua environment, sehingga jika ingin dilakukan tes kembali, mohon gunakan environment yang sama untuk hasil yang serupa.
- Pastikan setiap file test **memiliki baris kosong di akhir** untuk mencegah pemrosesan yang berulang

## Usage
- Masukkan file testing pada folder `test`
- Windows:
  ```sh
  mkdir bin
  run <nama_file_test>    # misal: run small_1.txt
  ```
- Linux / WSL:
  ```sh
  mkdir bin
  ./run.sh <nama_file_test>   # misal: ./run.sh large_1.txt
  ```

## Project Status
- Program ini sudah selesai dikembangkan dan ditest pada beberapa kasus baik word puzzle ukuran kecil, sedang, dan besar, serta telah lulus semua test tersebut.

| Poin  | Ya | Tidak |
|---|---|---|
| Program berhasil dikompilasi tanpa kesalahan (no syntax error) | V |   |
| Program berhasil running | V |   |
| Program dapat membaca file masukan dan menuliskan luaran | V |   |
| Program berhasil menemukan semua kata di dalam puzzle | V |  |


## Developed by
- Malik Akbar Hashemi Rafsanjani
- 13520105
- Teknik Informatika 2020