#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Performer {
private:
    string name;
    int age;

public:
    Performer(const string& name, int age) : name(name), age(age) {}

    string getName() const { return name; }
    int getAge() const { return age; }

    virtual void perform() const {
        cout << getName() << " is giving a performance." << endl;
    }
};


class Singer : public Performer {
private:
    string vocalRange;

public:
    Singer(const string& name, int age, const string& vocalRange) : Performer(name, age), vocalRange(vocalRange) {}

    string getVocalRange() const { return vocalRange; }

    void sing() const {
        cout << getName() << " is singing with a " << vocalRange << " range." << endl;
    }

    void perform() const override {
        sing();
    }
};


class Dancer : public Performer {
private:
    string danceStyle;

public:
    Dancer(const string& name, int age, const string& danceStyle) : Performer(name, age), danceStyle(danceStyle) {}

    string getDanceStyle() const { return danceStyle; }

    void dance() const {
        cout << getName() << " is performing " << danceStyle << " dance." << endl;
    }

    void perform() const override {
        dance();
    }
};

void makePerformances(const vector<Performer*>& performers) {
    cout << "\n--- Performances ---" << endl;
    for (const Performer* performer : performers) {
        performer->perform();
    }
    cout << "--------------------" << endl;
}

int main() {
    vector<Performer*> performers;
    performers.push_back(new Performer("Generic Performer", 30));
    performers.push_back(new Singer("Charlie", 35, "Tenor"));
    performers.push_back(new Singer("Diana", 28, "Soprano"));
    performers.push_back(new Dancer("Carlos", 22, "Hip-hop"));
    performers.push_back(new Dancer("maria", 27, "maro"));

    int choice;
    do {
       
        cout << "1.  singer" << endl;
        cout << "2.  dancer" << endl;
        cout << "3. Make all performers perform" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
            case 1: {
                string name, vocalRange;
                int age;
                cout << "Enter singer's name: ";
                getline(cin, name);
                cout << "Enter singer's age: ";
                cin >> age;
                cin.ignore();
                cout << "Enter singer's vocal range: ";
                getline(cin, vocalRange);
                performers.push_back(new Singer(name, age, vocalRange));
                cout << "Singer added." << endl;
                break;
            }
            case 2: {
                string name, danceStyle;
                int age;
                cout << "Enter dancer's name: ";
                getline(cin, name);
                cout << "Enter dancer's age: ";
                cin >> age;
                cin.ignore();
                cout << "Enter dancer's dance style: ";
                getline(cin, danceStyle);
                performers.push_back(new Dancer(name, age, danceStyle));
                cout << "Dancer added." << endl;
                break;
            }
            case 3:
                makePerformances(performers);
                break;
            case 0:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);

    
    for (Performer* performer : performers) {
        delete performer;
    }
    performers.clear();

    return 0;
}