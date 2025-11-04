#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct studentType{
    string studentFName;
    string studentLName;
    int testScore;
    char grade;
};

const int P = 20;
studentType daftarMurid[P]; // mendeclare objek dengan tipe student
int nilaiTertinggi; //untuk menampung nilai tes tertinggi, dipakai dalam fungsi highestGrade dan highestGradeStudent

void read (); // fungsi untuk memasukkan data tiap murid
void relevantGrade (); // fungsi untuk menentukan grade tiap murid berdasarkan nilai tes
void printEachStudent (); // fungsi untuk menampilkan data tiap murid
void highestGrade (); // fungsi untuk mencari nilai tertinggi
void highestGradeStudent (); // fungsi untuk mencari murid dengan nilai tertinggi

int main(){
    read();
    relevantGrade();
    printEachStudent();
    highestGrade();
    highestGradeStudent();
    return 0;
}

void read (){
    for(int i =0;i<P;i++){
    cout << "masukkan nama depan murid :\n";
    cin >> daftarMurid[i].studentFName; //memasukkan nama depan murid 
    cout << "masukkan nama belakang murid :\n";
    cin >> daftarMurid[i].studentLName; //memasukkan nama belakang murid
    cout << "masukkan nilai tes :\n";
    cin >> daftarMurid[i].testScore; //memasukkan nilai tes murid
        if(daftarMurid[i].testScore>100){
            daftarMurid[i].testScore = 100;
        }else if (daftarMurid[i].testScore<0){
            daftarMurid[i].testScore = 0; // ketika nilai kurang dari 0 maka dianggap nilainya 0, jika nilai lebih dari 100 maka nilainya dianggap 100
        }
    }
}

void relevantGrade (){ 
    for(int i =0;i<P;i++){
    if(daftarMurid[i].testScore >= 90){
        daftarMurid[i].grade = 'A'; //jika nilai tes lebih dari 90 maka dapat grade A
    }else if (daftarMurid[i].testScore >= 80){
        daftarMurid[i].grade = 'B'; //jika nilai tes lebih dari 80 maka dapat grade B
    }else if (daftarMurid[i].testScore >= 70){
        daftarMurid[i].grade = 'C'; //jika nilai tes lebih dari 70 maka dapat grade C
    }else {
        daftarMurid[i].grade = 'D'; //jika nilai tes kurang dari maka dapat grade D
    }
    }
}

void printEachStudent(){
    cout << left << setw(5) << "No." << setw(25) << "Nama" << setw(8) << "Nilai" << setw(8) << "Grade" << endl;
    for(int i = 0;i<P;i++){
        cout << left << setw(5) << to_string(i+1) + "." 
            << setw(25) << daftarMurid[i].studentLName + ", " + daftarMurid[i].studentFName 
            << setw(8) << daftarMurid[i].testScore 
            << setw(8) << daftarMurid[i].grade << endl; 
    } //menampilkan data tiap murid
}
void highestGrade (){
    nilaiTertinggi = daftarMurid[0].testScore;
    for(int i = 0;i<P;i++){
        if(daftarMurid[i].testScore > nilaiTertinggi){
            nilaiTertinggi = daftarMurid[i].testScore;
        } //mencari nilai tes tertinggi
    }
    cout << "\nNilai tertinggi : "<< nilaiTertinggi << endl; //menampilkan nilai tertinggi
}

void highestGradeStudent (){
    cout << "\nMurid dengan nilai tertinggi :\n";
    for(int i = 0;i<P;i++){
        if(daftarMurid[i].testScore == nilaiTertinggi){
            cout << daftarMurid[i].studentLName << ", " << daftarMurid[i].studentFName << endl;
        } //mencari dan menampilkan murid dengan nilai tertinggi
    }
}

