#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
float const pi=3.14;
using namespace std;
struct Triangle
{
    double a,b,c,area,perimeter;//sides
    double A,B,C;//angles
    void Areacalculation()
	{
        double s=(a+b+c)/2;
        area = sqrt(s*(s-a)*(s-b)*(s-c));
    }
    void Perimetercalculation()
	{
        perimeter=a+b+c;
    }
    void Anglescalculation()
	{
        C=acos((a*a+b*b-c*c)/(2*a*b))*180/pi;
        A= acos((b*b+c*c-a*a)/(2*b*c))*180/pi;
        B= 180-C-A;
    }
    bool validity()
	{
        return(a+b>c)&&(a+c>b)&&(b+c>a);
    }
};
void swap(Triangle &t1,Triangle &t2)
{
    Triangle temp= t1;
    t1=t2;
    t2=temp;
}
Triangle GenerateRandomTriangle()
{
    Triangle t;
    do {
        t.a=rand()%90+10;
        t.b= rand()%90+10;
        t.c=rand()%90+10;
    } while(!t.validity());
    t.Anglescalculation();
    t.Areacalculation();
    t.Perimetercalculation();
    return t;
}
void displayTriangle(const Triangle &t, int index)
{
    cout<<"Triangle:- "<< index <<"\n";
    cout<<"Sides:- " <<t.a<<","<<t.b<<","<<t.c<<"\n";
    cout<<"Angles:- "<<t.A<<" degree"<<"<<,"<<t.B<<" degree"<<","<<t.C<<" degree"<<"\n";
    cout<<"Area:- "<<t.area<<"\n";
    cout<<"Perimeter:- "<<t.perimeter<<"\n";
}
void savingTEXTFILE(const Triangle triangles[],int count,const string &filename)
{
    ofstream outFile(filename);
    for (int i=0;i<count;i++)
	{
        outFile<<"Triangle:- "<<i+1<< "\n";
        outFile<<"Sides:- "<<triangles[i].a<<","<<triangles[i].b<<","<< triangles[i].c<<"\n";
        outFile<<"Angles:- "<<triangles[i].A<<"," <<triangles[i].B<<","<< triangles[i].C<<"\n";
        outFile<<"Area:- "<<triangles[i].area<<"\n";
        outFile<<"Perimeter:- "<< triangles[i].perimeter << "\n";
    }
    outFile.close();
}
void savingBINARYFILE(const Triangle triangles[], int count,const string &filename)
{
    ofstream outFile(filename,ios::binary);
    for (int i=0;i<count;i++) {
        outFile.write((char*)&triangles[i].a,sizeof(double));
        outFile.write((char*)&triangles[i].b,sizeof(double));
        outFile.write((char*)&triangles[i].c,sizeof(double));
        outFile.write((char*)&triangles[i].area,sizeof(double));
        outFile.write((char*)&triangles[i].perimeter,sizeof(double));
        outFile.write((char*)&triangles[i].A,sizeof(double));
        outFile.write((char*)&triangles[i].B,sizeof(double));
        outFile.write((char*)&triangles[i].C,sizeof(double));
    }
    outFile.close();
}
void sortByArea(Triangle triangles[],int SIZE,bool ascending)
{
    for(int i=0;i<SIZE;i++)
	{
        triangles[i].Areacalculation();
    }
    for (int i=0;i<SIZE-1;i++)
	{
        int index=i;
        for(int j=i+1;j<SIZE;j++)
		{
            if(ascending){
                if(triangles[j].area<triangles[index].area)
                    index=j;
            } else{
                if(triangles[j].area>triangles[index].area)
                    index = j;
            }
        }
        if(index!=i)
            swap(triangles[i],triangles[index]);
    }
}
void sortByPerimeter(Triangle triangles[],int SIZE) {
    for (int i=0;i<SIZE;i++) {
        triangles[i].Perimetercalculation();
    }
    for(int i=0; i<SIZE-1;i++)
	{
        int index=i;
        for(int j=i+1;j<SIZE;j++)
		{
            if(triangles[j].perimeter<triangles[index].perimeter)
                index=j;
        }
        if(index!=i)
            swap(triangles[i],triangles[index]);
    }
}
void displayTrianglesWithPerimeterLessThan(Triangle triangles[],int count,double maxPeri)
{
    cout<<"Triangles with perimeter less than:-"<<maxPeri<<"\n";
    bool found=false;
    for(int i=0;i<count;++i)
	{
        if(triangles[i].perimeter<maxPeri)
		{
            displayTriangle(triangles[i],i+1);
            found=true;
        }
    }
    if (!found)
        cout<<"None found/!!!come on ,do better mate"<<endl;
}
int main()
{
    srand(time(0));
    const int Triangle_count=10;
    Triangle triangles[Triangle_count];
    bool initialized=false;
    bool running=true;
    while (running){
        cout << "           MENU    "<<endl;
        cout << "\n";
        cout << "     1. Generate triangles"<<endl;
        cout << "     2. Display all triangles"<<endl;
        cout << "     3. Sort by area (ascending)"<<endl;
        cout << "     4. Sort by area (descending)"<<endl;
        cout << "     5. Sort by perimeter"<<endl;
        cout << "     6. Display triangles with perimeter less than input" << endl;
        cout << "     7. Save to files text as well as binary:-"<<endl;
        cout << "     8. Exit"<<endl;
        cout << "     Enter your choice: ";
        int choice;
        cin>>choice;
        switch(choice)
		{
            case 1:
                for(int i=0;i<Triangle_count;i++)
                    triangles[i]=GenerateRandomTriangle();
                initialized=true;
                cout<<"Triangles generated."<< endl;
                break;
            case 2:
                if (initialized)
                    for(int i=0;i<Triangle_count;i++)
                        displayTriangle(triangles[i],i+1);
                else
                    cout<<"Generate triangles first."<<endl;
                break;

            case 3:
                if (initialized)
				{
                    sortByArea(triangles,Triangle_count,true);
                    cout<<"Triangles sorted by area (ascending):-"<< endl;
                    for(int i=0;i<Triangle_count;i++)
                        displayTriangle(triangles[i],i+1);
                } else
                    cout<<"Generate triangles first."<<endl;
                break;
            case 4:
                if(initialized)
				{
                    sortByArea(triangles,Triangle_count,false);
                    cout<<"Triangles sorted by area(descending or hiagh to low value):-"<<endl;
                    for(int i=0;i<Triangle_count;i++)
                        displayTriangle(triangles[i],i+1);
                } else
                    cout<<"Generate triangles first."<<endl;
                break;
            case 5:
                if (initialized)
				{
                    sortByPerimeter(triangles,Triangle_count);
                    cout<<"Triangles sorted by perimeter:-"<<endl;
                    for (int i = 0;i<Triangle_count;i++)
                        displayTriangle(triangles[i],i+1);
                } else
                    cout<<"Generate triangles first."<<endl;
                break;
            case 6:
                if(initialized)
				{
                    double limit_for_peri;
                    cout<<"Enter max perimeter:-";
                    cin>>limit_for_peri;
                    displayTrianglesWithPerimeterLessThan(triangles,Triangle_count,limit_for_peri);
                } else
                    cout<<"Generate triangles first!!"<<endl;
                break;
            case 7:
                if(initialized)
				{
                    savingTEXTFILE(triangles,Triangle_count,"kaam.txt");
                    savingBINARYFILE(triangles,Triangle_count,"kaam.bin");
                    cout<<"Data saved to files."<<endl;
                } else
                    cout<<"No triangles generated. Generate first."<<endl;
                break;
            case 8:
                running=false;
                break;
            default:
                cout<<"Invalid option, try again!"<<endl;
        }
    }
    return 0;
}