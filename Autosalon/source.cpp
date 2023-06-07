#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Car {
    string name;
    int year_of_release;
    int engine_volume;
    int price;
public:
    Car() {
        name = "not set\n";
        year_of_release = 0;
        engine_volume = 0;
        price = 0;
    }

    Car(string name, int year_of_release, int engine_volume, int price) {
        this->name = name;;
        this->year_of_release = year_of_release;
        this->engine_volume = engine_volume;
        this->price = price;
    }

    string get_name() { return name; }
    int get_year_of_release() { return year_of_release; }
    int get_engine_volume() { return engine_volume; }
    int get_price() { return price; }

    void print() {
        cout << "-------------------------------------------------------\n";
        cout << "Name: " << name << "\n";
        cout << "Year of release: " << year_of_release << "\n";
        cout << "Engine volume: " << engine_volume << "\n";
        cout << "Price: " << price << "\n";
        cout << "-------------------------------------------------------\n";
    }

};


class Cars {
    vector<Car> cars;
public:
    void add_car(string name, int year_of_release, int engine_volume, int price) {
        Car c(name, year_of_release, engine_volume, price);
        cars.push_back(c);
    }
    void delete_car_by_name(string name) {
        for (int i = 0; i < cars.size(); i++)
        {
            if (cars[i].get_name() == name) {
                cars.erase(cars.begin() + i);
            }
        }


    }

    void write_cars_to_file(const char* path) {
        FILE* file = fopen(path, "w");
        for (int i = 0; i < cars.size(); i++)
        {
            fprintf(file, "%s, %d, %d, %d\n", cars[i].get_name().c_str(), cars[i].get_year_of_release(), cars[i].get_engine_volume(), cars[i].get_price());
        }
        fclose(file);
    }

    void read_cars_from_file(const char* path) {
        FILE* file = fopen(path, "r");
        for (int i = 0; i < cars.size(); i++)
        {
            fscanf(file, "%s, %d, %d, %d\n", cars[i].get_name().c_str(), cars[i].get_year_of_release(), cars[i].get_engine_volume(), cars[i].get_price());
        }
        fclose(file);

    }

    void sort_by_year_of_release() {
        for (int i = 0; i < cars.size(); i++)
        {
            sort(cars.begin(), cars.end(), [](Car& c1, Car& c2) {
                return c1.get_year_of_release() > c2.get_year_of_release();
                });
        }

    }

    bool find_by_year_of_release(int year_of_release) {
        for (int i = 0; i < cars.size(); i++)
        {
            if (cars[i].get_year_of_release() == year_of_release) {
                return true;
            }
        }
        return false;

    }

    void print() {
        for (int i = 0; i < cars.size(); i++)
            cars[i].print();
    }
};

int menu() {
    int choice;
    cout << "0 - Exit\n";
    cout << "1 - Print cars\n";
    cout << "2 - Add car\n";
    cout << "3 - Delete car\n";
    cout << "4 - Sort by year of release\n";
    cout << "5 - Find by year of release\n";

    cout << "Enter choice: ";
    cin >> choice;
    return choice;
}


int main() {
    Cars cars;

    cars.add_car("Car1", 2017, 100, 50000);
    cars.add_car("Car2", 2018, 200, 40000);
    cars.add_car("Car3", 2020, 500, 10000);
    cars.add_car("Car4", 2016, 150, 30000);
    cars.add_car("Car5", 2014, 300, 60000);

    cars.read_cars_from_file("D:\\autosalon.txt");


    string name;
    int year_of_release;
    int engine_volume;
    int price;
    do
    {
        int choice = menu();
        if (!choice) {
            cars.write_cars_to_file("D:\\autosalon.txt");
            break;
        }

        switch (choice)
        {
        case 1:
            cars.print();
            break;
        case 2:
            cout << "Enter car name: ";
            cin >> name;
            cout << "Enter year of release: ";
            cin >> year_of_release;
            cout << "Enter engine volume: ";
            cin >> engine_volume;
            cout << "Enter price: ";
            cin >> price;
            cars.add_car(name, year_of_release, engine_volume, price);
            cars.print();
            break;
        case 3:
            cout << "Enter name of the car you want to delete: ";
            cin >> name;
            cars.delete_car_by_name(name);
            cars.print();
            break;
        case 4:
            cars.sort_by_year_of_release();
            cars.print();
            break;
        case 5:
            cout << "Enter year of release: ";
            cin >> year_of_release;
            if (cars.find_by_year_of_release(year_of_release)) cout << "Found!\n";
            else cout << "Not found!\n";
            break;
        default:
            break;
        }
    } while (true);






    return 0;
}