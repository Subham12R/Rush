#include <iostream>
using namespace std;

class Movie{
    private:
    string name;
    string time;
    int seat[100];

    public:
    Movie(string name, string time) : name(name), time(time) {
        for(int i = 0; i < 100; i++){
            seat[i] = 0;
        }
        cout << "Movie: " << name << " at " << time << " created." << endl;
    }

    void bookSeat(){
        int seatNo;
        cout << "Enter seat number to book: ";
        cin >> seatNo;
        if(seat[seatNo] == 1){
            cout << "Seat is already booked for " << name << " at " << time << "." << endl;
            return;
        }
        if(seatNo < 0 || seatNo >= 100){
            cout << "Invalid seat number. Please choose between 0 and 99." << endl;
            return;
        }
        seat[seatNo] = 1;
        cout << "Seat " << seatNo << " has been booked for " << name << " at " << time << "." << endl;
        printFile(seatNo);
    }

    void displaySeats(){
        cout << "Booked seats for " << name << " at " << time << ": ";
        for(int i = 0; i < 100; i++){
            if(seat[i] == 1){
                cout << i << " ";
            }
        }
        cout << endl;
    }

    void printFile(int seatNo){ 
        FILE *fptr;
        fptr = fopen("movies.txt", "a");
        if (fptr == NULL) {
            cout << "Error opening file!" << endl;
            return;
        }
        fprintf(fptr, "Movie: %s, Time: %s, Booked Seat: %d\n", name.c_str(), time.c_str(), seatNo);
        fclose(fptr);
    }
    

};

int main() {
    Movie movie1("Inception", "7:00 PM");
    Movie movie2("The Matrix", "9:00 PM");

    int choice;
    do {
        cout << "1. Book seat for Inception" << endl;
        cout << "2. Book seat for The Matrix" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice){
            case 1:
                movie1.bookSeat();
                break;
            case 2:
                movie2.bookSeat();
                break;
            case 3:
                cout << "Exiting..." << endl;
                break;
            case 4:
                cout << "Displaying booked seats:" << endl;
                movie1.displaySeats();
                movie2.displaySeats();
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 3);
    


    return 0;
}