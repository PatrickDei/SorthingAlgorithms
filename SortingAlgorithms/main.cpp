#include "Columns.h"
#include "SelectionSort.h"
#include "BubbleSort.h"
#include "Insertion.h"
#include "ShellSort.h"
#include "QuickSort.h"
#include <string>

using namespace sf;
using namespace std;

bool isShuffled(vector<Columns> c) {
    for (size_t i = 0; i < c.size()-1; i++)
        if (c[i].number > c[i + 1].number)
            return true;
    return false;
}

void resetSorting(string &sort) {
    sort = "";
    SelectionSort::placeToStart = 0;
    BubbleSort::loopCounter = 0;
    SelectionSort::loopCounter = 0;
    BubbleSort::numOfCalls = 0;
    InsertionSort::loopCounter = 1;
    ShellSort::gap = 320 / 2;
    ShellSort::loopCounter = 320 / 2;
}


double BubbleSort::loopCounter = 0;
double SelectionSort::loopCounter = 0;
double InsertionSort::loopCounter = 1;
int ShellSort::gap = 320 / 2;

int SelectionSort::placeToStart = 0;
int BubbleSort::numOfCalls = 0;
int ShellSort::loopCounter = gap;

int main()
{
    RenderWindow window(VideoMode(1600, 960), "Sorting algorithms");

    //vector init
    vector<Columns> columns;
    for (int i = 0; i < 320; i++)
        columns.push_back(i*3);
    random_shuffle(columns.begin(), columns.end());

    bool shuffled;
    string sort;

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
            if (Keyboard::isKeyPressed(Keyboard::S))
                sort = "selection";
            if (Keyboard::isKeyPressed(Keyboard::B))
                sort = "bubble";
            if (Keyboard::isKeyPressed(Keyboard::I))
                sort = "insertion";
            if (Keyboard::isKeyPressed(Keyboard::Space))
                sort = "shell";
            if (Keyboard::isKeyPressed(Keyboard::Q))
                sort = "quick";
            if (Keyboard::isKeyPressed(Keyboard::R)) {
                random_shuffle(columns.begin(), columns.end());
                resetSorting(sort);
            }
                
        }

        //setText(text, sort);
        shuffled = isShuffled(columns);

        if (sort == "selection" && shuffled)
            SelectionSort::sort(columns);
            
        if (sort == "bubble" && shuffled)
            BubbleSort::sort(columns);

        if (sort == "insertion" && shuffled)
            InsertionSort::sort(columns);

        if (sort == "shell" && shuffled)
            ShellSort::sort(columns);

        if (sort == "quick" && shuffled)
            QuickSort::sort(columns, 0, 319);
            
        if (!shuffled)
            resetSorting(sort);
        
        /*cout << SelectionSort::loopCounter << endl;
        cout << BubbleSort::loopCounter << endl;*/

        //drawing
        window.clear();
        for (int j = 0; j < 320; j++)
            window.draw(Columns::drawColumn(columns[j].number, j));
        //window.draw(text);
        window.display();
        sleep(milliseconds(10));
    }
    return 0;
}