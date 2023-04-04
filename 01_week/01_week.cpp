// 01_week.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    std::cout << "01_week Hello World!\n";
    
    int iVal1 = -1;
    short shortVal2 = 0;
    int iVal3 = 42;
    float fVal4 = 0.34f;
    char chVal5 = 'a';
    fVal4 = 3.14f;
    
    std::cout << "\n iVal1 = ";
    std::cout << iVal1 << " address = " << &iVal1;
    std::cout << "\n shortVal2 = " << shortVal2 << " address = " << &shortVal2;

    std::cout << "\n\n ***** Size of int = " << sizeof(iVal1);
    std::cout << "\n\n ***** Size of int = " << sizeof(shortVal2);

    int* iPtr = NULL; // Init pointer variable 
    iPtr = &iVal1; // Set pointer to address of variable 
    //char* myCharPtr = (char*)&iVal1;

    *iPtr = 21;  //Change the value at the location in memory that is pointed to 
    std::cout << "\n\n value poionted to by iPtr = " << *iPtr; // Value that iPtr points to 
    std::cout << "\n Value of iPtr = " << iPtr;  // value inside of var iPtr - the memory location of iVal1
    std::cout << "\n address of iPtr is " << &iPtr;

    std::cout << "\n\n !!!!! Some value is " << *(iPtr - 6) << "      Address of iVal3: " << &iVal3 << "    Address of iPtr - 6: " << &(*(iPtr - 6));
    std::cout << "\n\n !!!!! Some value is " << *(iPtr + 12);

    std::cout << "\n ------ Starting Heap Stuff ------";

    //std::cout << "\n\n Strange stuff: " << *myCharPtr;

    //below is heap stuff
    char* cTemp = NULL;
    cTemp = (char*)malloc(20); // 20 bytes of heap memory
    memset(cTemp, NULL, 20); //instead of null you can put '\0' which is the old way of doing and will show a warning as not the correct way
    // Do stuff
    free(cTemp);

    std::cout << "\n\n ** End of Program ** \n\n";

}

