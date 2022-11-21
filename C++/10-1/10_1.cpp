#include <iostream>

using namespace std;

#include "Profesor.h"
#include "Asistent.h"
#include "Demonstrator.h"

int instructions();

int main()
{
    int choise;
    Profesor arrayOfProfesori[100];
    Asistent arrayOfAsistenti[100];
    Demonstrator arrayOfDemonstratori[100];
    int counterProfesori = 0;
    int counterAsistenti = 0;
    int counterDemonstratori = 0;

    while((choise = instructions()) != 3)
    {
        switch(choise)
        {
            case 1:
                {
                    int employeeType;
                    cout << "Izberi broj\n(1 - Profesor)\n"
                            "(2 - Asistent)\n(3 - Demonstrator)\n";
                    cin >> employeeType;
                    if(employeeType == 1)
                    {
                        Profesor newProfesor = newProfesor.postaviProfesor();
                        arrayOfProfesori[counterProfesori++] = newProfesor;
                        cout << "Uspesno vnesen profesor.\n";
                        break;

                    }
                    else if(employeeType == 2)
                    {
                        Asistent newAsistent = newAsistent.postaviAsistent();
                        arrayOfAsistenti[counterAsistenti++] = newAsistent;
                        cout << "Uspesno vnesen asistent.\n";
                        break;
                    }
                     else if(employeeType == 3)
                    {
                        Demonstrator newDemonstrator = 
                                newDemonstrator.postaviDemonstrator();
                        arrayOfDemonstratori[counterDemonstratori++] = 
                                                        newDemonstrator;
                        cout << "Uspesno vnesen asistent.\n";
                        break;
                    }
                    else
                    {
                        cout << "Vnesovte pogresen broj.\n";
                        break;
                    }
                }
            case 2:
                {
                    int employeeType;
                    cout << "Izberi broj\n(1 - Profesor)\n"
                            "(2 - Asistent)\n(3 - Demonstrator)\n";
                    cin >> employeeType;
                    if(employeeType == 1)
                    {
                        if(counterProfesori == 0)
                        {
                            cout << "Nemate vneseno profesori.\n";
                            break;
                        }
                        for(int i = 0; i < counterProfesori; ++i)
                        {
                            cout << "\nProfesor " << i + 1 << endl;
                            arrayOfProfesori[i].prikaziPodatociProfesor();
                        }
                        break;
                    }
                    else if(employeeType == 2)
                    {
                       if(counterAsistenti == 0)
                        {
                            cout << "Nemate vneseno asistenti.\n";
                            break;
                        }
                        for(int i = 0; i < counterAsistenti; ++i)
                        {
                            cout << "\nAsistent " << i + 1 << endl;
                            arrayOfAsistenti[i].prikaziPodatociAsistent();
                        }
                        break;
                    }
                     else if(employeeType == 3)
                    {
                       if(counterDemonstratori == 0)
                        {
                            cout << "Nemate vneseno demonstratori.\n";
                            break;
                        }
                        for(int i = 0; i < counterDemonstratori; ++i)
                        {
                            cout << "\nDemonstrator " << i + 1 << endl;
                            arrayOfDemonstratori[i].prikaziPodatociDemonstrator();
                        }
                        break;
                    }
                    else
                    {
                        cout << "Vnesovte pogresen broj.\n";
                        break;
                    } 
                }
           
            default:
                cout << "Vnesovte pogresen broj " << endl;
                break;
        }
    }
    return 0;
}

int instructions()
{
    int choise;
    cout<<"Izberi broj: \n"
        "1 - Dodadi Vraboten.\n"
        "2 - Prikazi vraboteni.\n"
        "3 - Za kraj.\n";
    cin >> choise;
    return choise;
}