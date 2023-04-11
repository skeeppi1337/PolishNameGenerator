#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <atlbase.h>
#include <atlconv.h>
#include<string.h>

int firstNameGen();
int lastNameGen();
int  main() {
    ShowWindow(GetConsoleWindow(), SW_HIDE);

    int firstNameIndex = firstNameGen();
    int LastNameIndex = lastNameGen();
    LPCWSTR firstNamePrint;
    LPCWSTR lastNamePrint;
    int finishbox;
    std::wstring result;
    LPCWSTR resultPrint;

    LPCWSTR firstName[20] = { L"Piotr " , L"Krzysztof " , L"Andrzej " , L"Tomasz " , L"Jan " , L"Pawel "
                              , L"Michal " , L"Marcin " , L"Stanislaw " , L"Jakub " , L"Adam " , L"Marek "
                              , L"Lukasz " ,  L"Grzegorz " , L"Mateusz " , L"Wojciech " 
                              , L"Mariusz " , L"Dariusz " , L"Zbigniew " , L"Jerzy " };

    LPCWSTR lastName[20] = { L"Nowak" , L"Kowalski" , L"Lewandowski" , L"Kowalczyk" , L"Kaminski" 
                              , L"Zielinski" , L"Jankowski" , L"Wojciechowski" , L"Kwiatkowski" 
                              , L"Kaczmarek" , L"Mazur" , L"Krawczyk" , L"Piotrowski" , L"Grabowski" 
                              , L"Nowakowski" , L"Pawlowski" , L"Michalski" , L"Adamczyk" };

    int polishNameGenerator = MessageBox(
        NULL,
        (LPCWSTR)L"Do you want to generate polish name",
        (LPCWSTR)L"Polish name generator",
        MB_ICONQUESTION | MB_YESNO 
    );
    switch (polishNameGenerator)
    {
    case (IDYES):
       firstNamePrint = firstName[firstNameIndex];
       lastNamePrint = lastName[LastNameIndex];
       result = std::wstring(firstNamePrint) + lastNamePrint;
       resultPrint = result.c_str(); // this is stupid
       finishbox = MessageBox(
           NULL,
           (LPCWSTR)resultPrint,
           (LPCWSTR)L"Polish name generator",
           MB_ICONINFORMATION | MB_OK
       );
       break;
    case (IDNO):
       return 0;
    }
        
    return 0;
}

int firstNameGen() {
    int index = 0;
    srand(time(NULL));
    index = rand() % 20;
    return index;
}

int lastNameGen() {
    int index = 0;
    srand(time(NULL));
    index = rand() % 20;
    return index;
}