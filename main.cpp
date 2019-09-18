using namespace std;
#include <iostream>
#include <cstdlib>
#include <graphics.h>
#include <fstream>
#include  <stdio.h>
#include <chrono>

const int LINE_COLOR=GREEN;
const int BK_COLOR=BLACK;
const int SPACE_BETWEEN_LINES=6;
const int LEFT_SPACE=20;
const int Y_START = 400;
const int DEFAULT_DELAY=50;
const int NUMBERS=100;
const int MAX_NUMBERS=390;

void wait_for_char()
{
    //Wait for a key press
    int in = 0;
    while (in == 0)
    {
        in = getchar();
    }
}

//functia afiseaza vectorul sortat sub liniile ordonate
void drawVector (int v[])
{
    char arr[5];
    int o,y,rows;
    for (rows=1,y=410,o=0; rows<=5; rows++,y=y+10,o++)
    {
        for (int i=o*20; i<(o+1)*20; i++)
        {
            sprintf(arr,"%d",v[i]);
            outtextxy((i%20)*30,y,arr);
        }
    }
}

//functia copiaza un vector in altul
void copyVector (int v[],int v2[],int lenght)
{
    for (int i=0; i<lenght; i++)
    {
        v2[i]=v[i];
    }
}

//functia inverseaza doua numere
void swapNumbers(int *a,int *b)
{
    int aux=*a;
    *a=*b;
    *b=aux;
}

//functia deseneaza o linie
void drawLine (int n, int x,int y,int color,int pdelay)
{
    setcolor(color);
    line(x,y,x,y-n);
    delay(pdelay);
}

//functia sorteaza vectorul cu metoda quick sort
void quickSortn (int v[],int left,int right)
{
    int i=left, j=right;
    int pivot=v[(left+right)/2];
    while (i<=j)
    {
        while (v[i]<pivot)
            i++;
        while (v[j]>pivot)
            j--;
        if (i<=j)
        {
            drawLine(v[i],LEFT_SPACE+i*SPACE_BETWEEN_LINES,Y_START,BK_COLOR,1);
            drawLine(v[j],LEFT_SPACE+j*SPACE_BETWEEN_LINES,Y_START,BK_COLOR,1);
            swapNumbers(&v[i],&v[j]);
            drawLine(v[i],LEFT_SPACE+i*SPACE_BETWEEN_LINES,Y_START,LINE_COLOR,1);
            drawLine(v[j],LEFT_SPACE+j*SPACE_BETWEEN_LINES,Y_START,LINE_COLOR,1);
            i++;
            j--;
        }
    }
    if (left<j)
        quickSortn(v,left,j);
    if (i<right)
        quickSortn(v,i,right);
}

//functia sorteaza sirul si liniile cu metoda quick sort
void quickSort (int v[])
{
    setbkcolor (BK_COLOR);
    setfontcolor (LINE_COLOR);
    outtextxy (getmaxx()/2-35,5,"QUICK SORT");
    for (int i=0; i<NUMBERS; i++)
    {
        drawLine(v[i],LEFT_SPACE+i*SPACE_BETWEEN_LINES,Y_START,LINE_COLOR,DEFAULT_DELAY);
    }
    quickSortn(v,0,NUMBERS-1);
    drawVector(v);
}

//functia sorteaza sirul si liniile cu metoda bubble sort
void bubbleSort (int v[])
{
    setbkcolor (BK_COLOR);
    setfontcolor (LINE_COLOR);
    outtextxy (getmaxx()/2-35,5,"BUBBLE SORT");
    for (int i=0; i<NUMBERS; i++)
    {
        drawLine(v[i],LEFT_SPACE+i*SPACE_BETWEEN_LINES,Y_START,LINE_COLOR,DEFAULT_DELAY);
    }
    bool swaped=true;
    while (swaped==true)
    {
        swaped=false;
        for (int i=1; i<NUMBERS; i++)
        {
            if (v[i]<v[i-1])
            {
                drawLine(v[i],LEFT_SPACE+i*SPACE_BETWEEN_LINES,Y_START,BK_COLOR,1);
                drawLine(v[i-1],LEFT_SPACE+(i-1)*SPACE_BETWEEN_LINES,Y_START,BK_COLOR,1);
                swapNumbers(&v[i],&v[i-1]);
                drawLine(v[i],LEFT_SPACE+i*SPACE_BETWEEN_LINES,Y_START,LINE_COLOR,1);
                drawLine(v[i-1],LEFT_SPACE+(i-1)*SPACE_BETWEEN_LINES,Y_START,LINE_COLOR,1);
                swaped=true;
            }
        }
    }
    drawVector(v);
}

//functia sorteaza sirul si liniile cu metoda intsert sort
void insertSort (int v[])
{
    setbkcolor (BK_COLOR);
    setfontcolor (LINE_COLOR);
    outtextxy (getmaxx()/2-35,5,"INSERT SORT");
    for (int i=0; i<NUMBERS; i++)
    {
        drawLine(v[i],LEFT_SPACE+i*SPACE_BETWEEN_LINES,Y_START,LINE_COLOR,DEFAULT_DELAY);
    }
    for (int i=1; i<NUMBERS; i++)
    {
        if (v[i]<v[i-1])
        {
            for (int j=i; j>0; j--)
            {
                if (v[j]<v[j-1])
                {
                    drawLine(v[j],LEFT_SPACE+j*SPACE_BETWEEN_LINES,Y_START,BK_COLOR,1);
                    drawLine(v[j-1],LEFT_SPACE+(j-1)*SPACE_BETWEEN_LINES,Y_START,BK_COLOR,1);
                    swapNumbers(&v[j],&v[j-1]);
                    drawLine(v[j],LEFT_SPACE+j*SPACE_BETWEEN_LINES,Y_START,LINE_COLOR,1);
                    drawLine(v[j-1],LEFT_SPACE+(j-1)*SPACE_BETWEEN_LINES,Y_START,LINE_COLOR,1);
                }
            }
        }
    }
    drawVector(v);
}

//functia sorteaza sirul si liniile cu metoda select sort
void selectSort (int v[])
{
    setbkcolor (BK_COLOR);
    setfontcolor (LINE_COLOR);
    outtextxy (getmaxx()/2-35,5,"SELECT SORT");
    for (int i=0; i<NUMBERS; i++)
    {
        drawLine(v[i],LEFT_SPACE+i*SPACE_BETWEEN_LINES,Y_START,LINE_COLOR,DEFAULT_DELAY);
    }
    for (int i=0; i<NUMBERS-1; i++)
    {
        for (int j=i+1; j<NUMBERS; j++)
            if (v[j]<v[i])
            {
                drawLine(v[j],LEFT_SPACE+j*SPACE_BETWEEN_LINES,Y_START,BK_COLOR,1);
                drawLine(v[i],LEFT_SPACE+i*SPACE_BETWEEN_LINES,Y_START,BK_COLOR,1);
                swapNumbers(&v[j],&v[i]);
                drawLine(v[j],LEFT_SPACE+j*SPACE_BETWEEN_LINES,Y_START,LINE_COLOR,1);
                drawLine(v[i],LEFT_SPACE+i*SPACE_BETWEEN_LINES,Y_START,LINE_COLOR,1);
            }
    }
    drawVector(v);
}

void ord_vector (int v[],int lenght)
{
    bool swap = true ;
    int i;
    while (swap == true)
    {
        for (i=1;i<=lenght;i++)
        {
            if (v[i-1]>v[i])
            {
                int aux=v[i];
                v[i]=v[i-1];
                v[i-1]=aux;
            }
        }
    }
}

int main()
{
    //se genereaza un sir random
    int v[NUMBERS];
    int elapsed_time,elapsed_time_2,elapsed_time_3,elapsed_time_4;
    srand (time(NULL));
    for (int i=0; i<NUMBERS; i++)
    {
        v[i]=rand() % MAX_NUMBERS;
    }
    int v5[3];
    int v2[NUMBERS];
    int v3[NUMBERS];
    int v4[NUMBERS];
    copyVector(v,v2,NUMBERS);
    copyVector(v,v3,NUMBERS);
    copyVector(v,v4,NUMBERS);
    //sortam acelasi sir cu toate metodele
    int gd = DETECT,gm;
    initgraph(&gd,&gm,NULL);
    auto start = chrono::steady_clock::now();
    bubbleSort(v);
    auto end = chrono::steady_clock::now();
    elapsed_time = chrono::duration_cast <chrono::milliseconds> (end-start).count() ;
    char arr[10];
    delay(3000);
    //functia cleardevice curata ecranul
    cleardevice();
    auto start2 = chrono::steady_clock::now();
    insertSort(v2);
    auto end2 = chrono::steady_clock::now();
    elapsed_time_2 = (chrono::duration_cast <chrono::milliseconds> (end2-start2).count());
    delay(3000);
    cleardevice();
    auto start3 =chrono::steady_clock::now();
    selectSort(v3);
    auto end3 = chrono::steady_clock::now();
    elapsed_time_3 = (chrono::duration_cast <chrono::milliseconds> (end3-start3).count());
    delay(3000);
    cleardevice();
    auto start4 = chrono::steady_clock::now();
    quickSort(v4);
    auto end4 = chrono::steady_clock::now();
    elapsed_time_4 = (chrono::duration_cast <chrono::milliseconds> (end4-start4).count());
    delay(3000);
    cleardevice();
    char array1[50],array2[50],array3[50],array4[50];
    outtextxy(getmaxx()/2-3,2,"Times");
    sprintf(array1,"Bubble sort: %d miliseconds",elapsed_time);
    outtextxy(0,22,array1);
    sprintf(array2,"Insert sort: %d miliseconds",elapsed_time_2);
    outtextxy(0,32, array2);
    sprintf(array3,"Select sort: %d miliseconds",elapsed_time_3);
    outtextxy(0,42,array3);
    sprintf(array4,"Quick sort: %d miliseconds",elapsed_time_4);
    outtextxy(0,52,array4);
    v5[0]=elapsed_time;
    v5[1]=elapsed_time_2;
    v5[2]=elapsed_time_3;
    v5[3]=elapsed_time_4;
    ord_vector (v5,4);
    wait_for_char();
    closegraph();
    return 0;
}
