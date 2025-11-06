#include <iostream>
#include <string>
using namespace std;

const int ARRAY_SIZE = 20;

// mendefinisikan komponen-komponen yang ada di dalam struct studentType
struct studentType {
    string studentFName;
    string studentLName;
    int testScore;
    char grade;
};

// mendefinisikan struct studentListType yang berisi array dari struct studentType dan integer untuk menyimpan panjang array
struct studentListType {
    studentType students_array[ARRAY_SIZE];
    int listLength;
};

// A function to read the students’ data into the array (fungsi untuk mengisi data mahasiswa)
void readDataStudent (studentType students[], int size){
    string firstName[ARRAY_SIZE] = {"Lestari", "Lala", "Yona", "Enni", "Nazma", "Kalila", "Fairuz", "Mayya", "Tisya", "Hanif", 
                               "Salma", "Candra", "Daffa", "Javier", "Putra", "Raihan", "Kayla", "Nida", "Gisell", "Rafif"};
    string lastName[ARRAY_SIZE] = {"Azzahra", "Alifia", "Novena", "Nadiyya", "Desyana", "Priyanto", "Safira", "Syifani", "Berliana", "Abdurrahman",
                              "Karimah", "Wibowo", "Firdaus", "Ramadhan", "Kusuma", "Cahyaputra", "Musakina", "Cahyadewi", "Asmaranti", "Aditya"};
    int scores [ARRAY_SIZE] = {85, 78, 92, 67, 74, 88, 90, 81, 76, 95,
                          69, 83, 87, 97, 73, 80, 77, 84, 66, 89};

    for (int i = 0; i < size; i++){
        students[i].studentFName = firstName[i];
        students[i].studentLName = lastName[i];
        students[i].testScore = scores[i];
    };
};

// A function to assign the relevant grade to each student (fungsi untuk memberikan nilai huruf kepada tiap skor mahasiswa)
void assignGrades(studentType students[], int size) {
    for (int i = 0; i < size; i++) {
        // Assign grade based on score
        if (students[i].testScore >= 90) {
            students[i].grade = 'A';
        } else if (students[i].testScore >= 80) {
            students[i].grade = 'B';
        } else if (students[i].testScore >= 70) {
            students[i].grade = 'C';
        } else if (students[i].testScore >= 60) {
            students[i].grade = 'D';
        } else {
            students[i].grade = 'F';
        }
    }
};

// A function to find the highest test score (fungsi untuk mencari skor tertinggi)
int findHighestScore(const studentType students[], int size) {
    int highestScore = students[0].testScore;
    for (int i = 1; i < size; i++) {
        if (students[i].testScore > highestScore) {
            highestScore = students[i].testScore;
        }
    }
    return highestScore;
};

// A function to print the names of the students having the highest test score (fungsi untuk menampilkan mahasiswa dengan skor tertinggi)
void displayHighestScorers(const studentType students[], int size, int highestScore) {
    cout << "Students with the highest score :" << endl;
    for (int i = 0; i < size; i++) {
        if (students[i].testScore == highestScore) {
            cout << students[i].studentFName << " " << students[i].studentLName << " - Score: " << students[i].testScore << ", Grade: " << students[i].grade << endl;
        }
    }
};

int main (){
    studentListType sList;
    sList.listLength = ARRAY_SIZE;

    readDataStudent(sList.students_array, sList.listLength);
    assignGrades(sList.students_array, sList.listLength);
    int highestScore = findHighestScore(sList.students_array, sList.listLength);

    cout << "Students Data :" << endl;
    for (int i = 0; i < sList.listLength; i++) {
        cout << sList.students_array[i].studentLName << ", " << sList.students_array[i].studentFName;
        cout << " - Score: " << sList.students_array[i].testScore;
        cout << ", Grade: " << sList.students_array[i].grade << endl;
    }

    displayHighestScorers(sList.students_array, sList.listLength, highestScore);

    return 0;
}