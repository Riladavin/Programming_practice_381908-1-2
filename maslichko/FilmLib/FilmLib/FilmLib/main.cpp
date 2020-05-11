#include "Creature.h"

int main()
{
    SetConsoleCP(1251); //��������� ������� �������� win-cp 1251 � ����� �����
    SetConsoleOutputCP(1251); //� ����� ������
    Creature c1;

    vector<string> temp_data, temp_producer, temp_year, temp_fees, temp_fees_year;
    string title, producer, screenwriter, composer, data;
    long long fees;
    int menu, year, quantity;

    while (1)
    {
        cout << endl;
        cout << "1. Add film" << endl;
        cout << "2. Change film data selected by name" << endl;
        cout << "3. Find a film by title and year" << endl;
        cout << "4. Issue all films of a given director" << endl;
        cout << "5. Issue all films released in the selected year" << endl;
        cout << "6. Issue a given number of films with the highest fees" << endl;
        cout << "7. Issue a given number of films with the highest fees in the selected year" << endl;
        cout << "8. Find out the current number of films" << endl;
        cout << "9. Delete film by name" << endl;
        cout << "10. Save film library to file" << endl;
        cout << "11. Read film library from file" << endl;

        cout << endl << "Select the desired action: ";
        cin >> menu;

        switch (menu)
        {
        case 1:
            cin.get(); // Eliminate the unextracted delimiter in the keyboard buffer (line feed character)
            cout << endl << "Enter film title: ";
            getline(cin, title);
            cout << endl << "Enter Director: ";
            getline(cin, producer);
            cout << endl << "Enter screenwriter: ";
            getline(cin, screenwriter);
            cout << endl << "Enter composer: ";
            getline(cin, composer);
            cout << endl << "Enter release date: ";
            getline(cin, data);
            cout << endl << "Enter fees: ";
            cin >> fees;

            c1.Add(title, producer, screenwriter, composer, data, fees);
            break;
        case 2:
            cin.get();
            cout << endl << "Enter the name of the film whose data you want to change : ";
            getline(cin, title);
            cout << endl << "Enter Director: ";
            getline(cin, producer);
            cout << endl << "Enter screenwriter: ";
            getline(cin, screenwriter);
            cout << endl << "Enter composer: ";
            getline(cin, composer);
            cout << endl << "Enter release date: ";
            getline(cin, data);
            cout << endl << "Enter fees: ";
            cin >> fees;

            c1.Change(title, producer, screenwriter, composer, data, fees);
            break;
        case 3:
            cin.get();
            cout << endl << "Enter film title: ";
            getline(cin, title);
            cout << endl << "Enter film release year: ";
            cin >> year;
            temp_data = c1.Find(title, year);

            for (int i = 0; i < temp_data.size(); i++)
            {
                cout << endl << temp_data[i];
            }
            break;
        case 4:
            cin.get();
            cout << endl << "Enter Director: ";
            getline(cin, producer);
            temp_producer = c1.MovieSearch(producer);

            for (int i = 0; i < temp_producer.size(); i++)
            {
                cout << endl << temp_producer[i];
            }
            break;
        case 5:
            cin.get();
            cout << endl << "Enter year: ";
            cin >> year;
            temp_year = c1.MovieSearch(year);

            for (int i = 0; i < temp_year.size(); i++)
            {
                cout << endl << temp_year[i];
            }
            break;
        case 6:
            cin.get();
            cout << endl << "Enter the number of film to display: ";
            cin >> quantity;
            temp_fees = c1.NumberFilms(quantity);

            for (int i = 0; i < temp_fees.size(); i++)
            {
                cout << endl << temp_fees[i];
            }
            break;
        case 7:
            cin.get();
            cout << endl << "Enter the number of film to display: ";
            cin >> quantity;
            cout << endl << "Enter year: ";
            cin >> year;
            temp_fees_year = c1.NumberFilms(quantity, year);

            for (int i = 0; i < temp_fees_year.size(); i++)
            {
                cout << endl << temp_fees_year[i];
            }
            break;
        case 8:
            cin.get();
            cout << endl << "The number of films in the library: " << c1.Total();
            break;
        case 9:
            cin.get();
            cout << endl << "Enter the name of the film you want to remove: ";
            getline(cin, title);
            c1.DeleteMovie(title);
            break;
        case 10:
            c1.SaveLibrary();
            break;
        case 11:
            c1.ReadLibrary();
            break;
        }
    }
    system("pause");
    return 0;
}