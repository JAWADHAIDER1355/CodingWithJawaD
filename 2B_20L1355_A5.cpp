#include<iostream>
#include<cstring>
#include<fstream>
#include<stdlib.h>
using namespace std;
//counter of total words of inputfile of question 1
int a=0;
// VERTICES
int startingrowno;
int startingcolumno;
int endingrowno;
int endingcolumno;
int k;
//counters of eight conditions of question 2
int counter1;
int counter2;
//ROWZZ AND COLUM ARE ROW AND COLUMNS OF 2nd Question
int rowzz=0;
int colum=0;
int columcounter=0;//columncounter IS INTEGER VARIABLE SAVING THE COLUMN NUMBERS OF GRID
using namespace std;
char start[50][50];//50 50 ARE JUST IMAGINED WE WILL MAKE EXACT ALLOCATIONS AFTER SAVING IN ONE ARRAY LIKE START 2D array
char randomupperalphabets()//this function is used to generate random characters between 65 and 90(question 1 and 2 both)
{
    int c=0;
    char y;
    javi:;
    c=rand();
    if(c>=65&&c<=90)
    {
        y=c;
    }
    else
    {
        goto javi;
    }
    return y;
}
int main()
{
    cout<<"==========================ASSIGNMENT 5==================================="<<endl;
    cout<<"SELECT ANY ONE OPTION FROM THE GIVEN THREE OPTIONS ! \n 1) Create Grid \n 2) Search Words from Grid \n 3) Quit  \n";
    cout<<"Press C to create a grid, S to search words from grid, Q to use quit option...Use Capital form of C,S or Q!";
    cout<<endl;
    char option[0];
    cin>>option[0];
    if(option[0]=='C')
    {
        cout<<endl<<"================>>>>>Provide requirements<<<<<<<<<<================ "<<endl;
        ifstream f;
        string filename;
        cout <<endl<< "Please enter  name of the input file where a list of words is available(With Extension):  ";
        cin>> filename ;
        f.open( filename.c_str() );
        cout<<endl;
        cout<<"Number of words in the file:  ";
        int numofwordsinfile;
        cin>>numofwordsinfile;
        cout<<endl;
        cout<<"Number of rows in the grid:  ";
        int rows;
        cin>>rows;
        cout<<endl;
        cout<<"Number of cols in the grid:  ";
        int cols;
        cin>>cols;
        cout<<endl;
        ofstream outputfileobj;
        string outputfilename;
        cout <<endl<< "Please enter  name of the output file (With Extension):  ";
        cin>> outputfilename ;
        outputfileobj.open( outputfilename.c_str() );

        char jawad[200][50];
        for(int i=0;i<200;i++)
        {
            f.getline(jawad[i],50);
            cout<<jawad[i]<<endl;
            int j=0;
            if(jawad[i][j]=='\0')
            {
                a=i;
                goto jawad1;
            }
        }
        jawad1:;
        int totalwords=a;
        if(numofwordsinfile==totalwords)
        {


         char real[totalwords][30];
            int len[totalwords];
            int counterforalphabets;
            for(int i=0;i<totalwords;i++)
            {
                counterforalphabets=0;
                for(int j=0;j<strlen(jawad[i]);j++)
                {
                    if(jawad[i][j]==32)
                    {

                    }
                    if(jawad[i][j]!=32)
                    {
                        real[i][counterforalphabets]=jawad[i][j];
                        counterforalphabets++;
                    }
                len[i]=counterforalphabets;
                }
            }

                int highestwordlength =0;

                    for(int i=0;i<totalwords;i++)
                    {
                        if(len[i]>highestwordlength)
                        {
                            highestwordlength=len[i];
                        }
                    }
                    if(rows<highestwordlength&&cols<highestwordlength)
                    {
                        cout<<endl<<"Length of the longest word cannot fit in the user provided dimensions of the grid,MEANS GRID CAN NOT BE FORMED \nBETTER LUCK NEXT TIME!HAVE NICE DAY:)";
                        cout<<endl;
                        system("pause");
                        return 0;
                    }
                    for(int i=0;i<totalwords;i++)
                    {
                        for(int j=0;j<len[i];j++)
                        {
                            if(real[i][j]>=97)
                            {
                                real[i][j]=real[i][j]-32;
                            }
                        }
                    }
                    //printing for chek
                    for(int i=0;i<totalwords;i++)
                    {
                        for(int j=0;j<len[i];j++)
                        {
                            cout<<real[i][j];
                        }
                        cout<<endl;
                    }
            //===============================================================================================================================
                //here maxi is the maximum length of the given names and maximum is the maximum  number of names given in the input.txt file


                    if(highestwordlength>=totalwords)//if maximum length of biggest name is greater than maximum number of names in input file
                    {
//                        ofstream out("output.txt");
                        char finally[rows][cols];
                        for(int i=0;i <rows;i++)
                        {
                            if(i<totalwords)
                                {
                                    for(int j=0;j<cols;j++)
                                    {
                                        if(j>=len[i])
                                        {
                                           finally[i][j]=randomupperalphabets();
                                        }
                                        if(j<len[i])
                                        {
                                            finally[i][j]=real[i][j];
                                        }
                                    }
                                }
                            if(i>=totalwords)
                            {
                                for(int j=0;j<cols;j++)
                                {
                                    finally[i][j]=randomupperalphabets();
                                }
                            }
                        }

                        for(int i=0;i<rows;i++)
                        {

                            for(int j=0;j<cols;j++)
                            {
                                cout<<finally[i][j]<<" ";
                            }
                            cout<<endl;
                        }
                        //rows cols dalny according to user
                        char puzzle[rows][cols];
                        for(int i=0;i<rows;i++)
                        {
                            if((i%2)==0)
                            {
                                for(int j=0;j<cols;j++)
                                {
                                    puzzle[i][j]=finally[i][j];
                                }
                            }
                            if((i%2)==1)
                            {
                                int k=0;
                                for(int j=cols-1;j>=0;j--,k++)
                                {
                                    puzzle[i][k]=finally[i][j];
                                }
                            }
                        }

                    //============================================================================================================
                     // PREPARING OUTPUT FILE

                        for(int i=0;i<rows;i++)
                        {
                            for (int j=0;j<cols;j++)
                            {
                                outputfileobj<<puzzle[i][j]<<" ";
                            }
                            outputfileobj<<endl;
                        }
                    }
                    if(totalwords>highestwordlength)//if number of names are larger than maximum length of biggest name
                    {
//                        ofstream out("output.txt");
                        char finally[rows][cols];
                        for(int i=0;i <rows;i++)
                        {

                            if(i<totalwords)
                            {
                                for(int j=0;j<cols;j++)
                                {
                                    if(j>=len[i])
                                    {
                                       finally[i][j]=randomupperalphabets();
                                    }
                                    if(j<len[i])
                                    {
                                        finally[i][j]=real[i][j];
                                    }
                                }
                            }
                            if(i>=totalwords)
                            {
                                for(int j=0;j<cols;j++)
                                {
                                    {
                                        finally[i][j]=randomupperalphabets();
                                    }
                                }
                            }

                        }
                        cout<<endl<<"here major printing starts"<<endl;
                        for(int i=0;i<rows;i++)
                        {

                            for(int j=0;j<cols;j++)
                            {
                                cout<<finally[i][j]<<" ";
                            }
                            cout<<endl;
                        }
    //================================================================================================================================
                        char puzzle[rows][cols];

                        //////////////////////////////////////////////////////
                        for(int i=0;i<rows;i++)
                        {
                            if((i%2)==0)
                            {
                                for(int j=0;j<cols;j++)
                                {
                                    puzzle[i][j]=finally[i][j];
                                }
                            }
                            if((i%2)==1)
                            {
                                int k=0;
                                for(int j=cols-1;j>=0;j--,k++)
                                {
                                    puzzle[i][k]=finally[i][j];
                                }
                            }
                        }

                    //============================================================================================================
                     // PREPARING OUTPUT FILE

                        for(int i=0;i<rows;i++)
                        {
                            for (int j=0;j<cols;j++)
                            {
                                outputfileobj<<puzzle[i][j]<<" ";
                            }
                            outputfileobj<<endl;
                        }
                    }
                    cout<<endl<<"NOW YOU CAN SEE THE PUZZLE IN OUTPUT.TXT FILE MADE IN YOUR WORKING FOLDER...THANKYOU!"<<endl;
                    system("pause");
                    return 0;
        }
        else
        {
            cout<<endl<<"Entered NUMBER-of-WORDS are not equal to the real number of words in the file!!So Better luck next time,HAVE NICE DAY!!"<<endl;
            return 0;
        }
    }
    if(option[0]=='S')
    {
   //one file is output of first question(its name required) and scnd file(name required) is containing number of test cases,and after that names according to test cases
        cout<<endl<<"================>>>>>Provide requirements<<<<<<<<<<================ "<<endl;
        ifstream f;//f for first file
        string filename1;
        cout<<endl<<"Name of the input file which has a grid(with extension):  ";
        cin>> filename1 ;
        f.open( filename1.c_str() );
        cout<<endl<<"Name of the file which has ROW AND COLUMN OF GRID IN FIRST FILE AND NUMBER OF WORDS AND THE WORDS THEMSELVES(with extension):  ";
        ifstream s;//S for second file
        string filename2;
        cin>> filename2 ;
        s.open( filename2.c_str() );

        ofstream outputfileobj;
        string outputfilename;
        cout <<endl<< "Please enter  name of the output file (With Extension):  ";
        cin>> outputfilename ;
        outputfileobj.open( outputfilename.c_str() );



//     ====================================================================================================================================
        //FILE HANDLING=============================================================================================================
        //    ifstream in("input.txt");
            while(!f.eof())
            {
                f.getline(start[rowzz],50);
                rowzz++;
            }
            rowzz=rowzz-1;
            char real[rowzz][50];
            for(int i=0;i<rowzz;i++)
            {
                columcounter=0;
                for(int j=0;j<strlen(start[i]);j++)
                {
                    if(start[i][j]==32)
                    {
        //JUST TO IGNORE SPACE
                    }
                    if(start[i][j]!=32)
                    {
                        real[i][columcounter]=start[i][j];
                        columcounter++;
                    }
                }
                if(i==0)
                {
                    colum=columcounter;//JUST TO FIND COLUMNS
                }
            }
            cout<<"rowzz are "<<rowzz<<" starting from 0 to "<<rowzz-1<<endl;
            cout<<"colum is "<<colum<<" starting from 0 to "<<colum-1<<endl;
            for(int i=0;i<rowzz;i++)
            {
                for(int j=0;j<colum;j++)
                {
                    cout<<real[i][j]<<" ";
                }
                cout<<endl;
            }
        //===============================================================================================================================
        //inputs are here taken and their eight conditions are also applied in this loop


            /*int gridrow;
            int gridcol;
            cout<<"in which part of grid you want to find the indexes of the different words,Please...enter row and column number for the grid!!! "<<endl;
            cout<<"grid row??"<<endl;
            cin>>gridrow;
            cout<<"grid col??"<<endl;
            cin>>gridcol;
            */
            int row;
            int colm;
            s>>row;
            s>>colm;

            cout<<endl<<"Boundary between which we have to search the word vertices is given following according to the second file!!"<<endl;
            cout<<"rows:  "<<row<<endl<<"columns:  "<<colm<<endl;
            int inputwords;
            s>>inputwords;
            cout<<"NUMBER OF CASES FOR WHICH WE HAVE TO SEARCH ARE:  "<<inputwords<<endl;
            char input[inputwords][50];
            int inputsiz;
            //AND THE LOOP STARTS FROM HERE
            for(int a=-1;a<inputwords;a++)
            {
                int temp;
                s.getline(input[a],50);
                inputsiz=strlen(input[a]);
                for(int i=0;i<row;i++)
                {
                    for(int j=0;j<colm;j++)
                    {
                        if(input[a][0]==real[i][j])
                        {
                            temp=1;
                            int xxx=0;
                            //FIRST CONDITION==========================================================================
                            for(k=j;k<inputsiz+j;k++,xxx++)
                            {
                                if(input[a][xxx]!=real[i][k])
                                {
                                    temp=0;
                                }
                            }
                            if(temp==1)
                            {
                                startingrowno=i;
                                startingcolumno=k-inputsiz;
                                endingrowno=i;
                                endingcolumno=k-1;
                                outputfileobj<<"("<<startingrowno<<","<<startingcolumno<<")-----("<<endingrowno<<","<<endingcolumno<<")"<<endl;
                                cout<<"("<<startingrowno<<","<<startingcolumno<<")-----("<<endingrowno<<","<<endingcolumno<<")"<<endl;
                                goto nextinput;
                            }
                            else
                            {
                                temp=1;
                                int xxx=0;
                                //SECOND CONDITION==========================================================================
                                for(k=j;k>j-inputsiz;k--,xxx++)
                                {
                                    if(input[a][xxx]!=real[i][k])
                                    {
                                        temp=0;
                                    }
                                }
                                if(temp==1)
                                {
                                    startingrowno=i;
                                    startingcolumno=k+inputsiz;
                                    endingrowno=i;
                                    endingcolumno=k+1;
                                    outputfileobj<<"("<<startingrowno<<","<<startingcolumno<<")-----("<<endingrowno<<","<<endingcolumno<<")"<<endl;
                                    cout<<"("<<startingrowno<<","<<startingcolumno<<")-----("<<endingrowno<<","<<endingcolumno<<")"<<endl;
                                    goto nextinput;
                                }
                                else
                                {
                                    temp=1;
                                    int xxx=0;
                                    //THIRD CONDITION============================================================
                                    for(counter1=i;counter1<i+inputsiz;counter1++,xxx++)
                                    {
                                        if(input[a][xxx]!=real[counter1][j])
                                        {
                                            temp=0;
                                        }
                                    }
                                    if(temp==1)
                                    {
                                        startingrowno=counter1-inputsiz;
                                        startingcolumno=j;
                                        endingrowno=counter1-1;
                                        endingcolumno=j;
                                        outputfileobj<<"("<<startingrowno<<","<<startingcolumno<<")-----("<<endingrowno<<","<<endingcolumno<<")"<<endl;
                                        cout<<"("<<startingrowno<<","<<startingcolumno<<")-----("<<endingrowno<<","<<endingcolumno<<")"<<endl;
                                        goto nextinput;
                                    }
                                    else
                                    {
                                        temp=1;
                                        int xxx=0;
                          //FOURTH CONDITION=============================================================================
                                        for(counter1=i;counter1>i-inputsiz;counter1--,xxx++)
                                        {
                                            if(input[a][xxx]!=real[counter1][j])
                                            {
                                                temp=0;
                                            }
                                        }
                                        if(temp==1)
                                        {
                                            startingrowno=counter1+inputsiz;
                                            startingcolumno=j;
                                            endingrowno=counter1+1;
                                            endingcolumno=j;
                                            outputfileobj<<"("<<startingrowno<<","<<startingcolumno<<")-----("<<endingrowno<<","<<endingcolumno<<")"<<endl;
                                            cout<<"("<<startingrowno<<","<<startingcolumno<<")-----("<<endingrowno<<","<<endingcolumno<<")"<<endl;
                                            goto nextinput;
                                        }
                                        else
                                        {
                                            temp=1;
                                            int xxx=0;
                          //FIFTH CONDITION=============================================================================

                                            for(counter1=i,counter2=j;counter1<i+inputsiz&&counter2<j+inputsiz;counter1++,counter2++,xxx++)
                                            {
                                                if(input[a][xxx]!=real[counter1][counter2])
                                                {
                                                    temp=0;
                                                }
                                            }
                                            if(temp==1)
                                            {
                                                startingrowno=counter1-inputsiz;
                                                startingcolumno=counter2-inputsiz;
                                                endingrowno=counter1-1;
                                                endingcolumno=counter2-1;
                                                outputfileobj<<"("<<startingrowno<<","<<startingcolumno<<")-----("<<endingrowno<<","<<endingcolumno<<")"<<endl;
                                                cout<<"("<<startingrowno<<","<<startingcolumno<<")-----("<<endingrowno<<","<<endingcolumno<<")"<<endl;
                                                goto nextinput;
                                            }
                                            else
                                            {
                                                temp=1;
                                                int xxx=0;
                    //SIXTH CONDITION=============================================================================
                                                for(counter1=i,counter2=j;counter1>i-inputsiz&&counter2<j+inputsiz;counter1--,counter2++,xxx++)
                                                {
                                                    if(input[a][xxx]!=real[counter1][counter2])
                                                    {
                                                        temp=0;
                                                    }
                                                }
                                                if(temp==1)
                                                {
                                                    startingrowno=counter1+inputsiz;
                                                    startingcolumno=counter2-inputsiz;
                                                    endingrowno=counter1+1;
                                                    endingcolumno=counter2-1;
                                                    outputfileobj<<"("<<startingrowno<<","<<startingcolumno<<")-----("<<endingrowno<<","<<endingcolumno<<")"<<endl;
                                                    cout<<"("<<startingrowno<<","<<startingcolumno<<")-----("<<endingrowno<<","<<endingcolumno<<")"<<endl;
                                                    goto nextinput;
                                                }
                                                else
                                                {
                                                    temp=1;
                                                    int xxx=0;
                    //SEVENTH CONDITION=============================================================================
                                                    for(counter1=i,counter2=j;counter1<i+inputsiz&&counter2>j-inputsiz;counter1++,counter2--,xxx++)
                                                    {
                                                        if(input[a][xxx]!=real[counter1][counter2])
                                                        {
                                                            temp=0;
                                                        }
                                                    }
                                                    if(temp==1)
                                                    {
                                                        startingrowno=counter1-inputsiz;
                                                        startingcolumno=counter2+inputsiz;
                                                        endingrowno=counter1-1;
                                                        endingcolumno=counter2+1;
                                                        outputfileobj<<"("<<startingrowno<<","<<startingcolumno<<")-----("<<endingrowno<<","<<endingcolumno<<")"<<endl;
                                                        cout<<"("<<startingrowno<<","<<startingcolumno<<")-----("<<endingrowno<<","<<endingcolumno<<")"<<endl;
                                                        goto nextinput;
                                                    }
                                                    else
                                                    {
                                                        temp=1;
                                                        int xxx=0;
                          //EIGHT CONDITION=============================================================================
                                                        for(counter1=i,counter2=j;counter1>i-inputsiz&&counter2>j-inputsiz;counter1--,counter2--,xxx++)
                                                        {
                                                            if(input[a][xxx]!=real[counter1][counter2])
                                                            {
                                                                temp=0;
                                                            }
                                                        }
                                                        if(temp==1)
                                                        {
                                                            startingrowno=counter1+inputsiz;
                                                            startingcolumno=counter2+inputsiz;
                                                            endingrowno=counter1+1;
                                                            endingcolumno=counter2+1;
                                                            outputfileobj<<"("<<startingrowno<<","<<startingcolumno<<")-----("<<endingrowno<<","<<endingcolumno<<")"<<endl;
                                                            cout<<"("<<startingrowno<<","<<startingcolumno<<")-----("<<endingrowno<<","<<endingcolumno<<")"<<endl;
                                                            goto nextinput;
                                                        }


                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                if(a!=-1&&temp==0)
                {
                    outputfileobj<<endl<<"Vertices of that input word not found in given boundaries of rows and columns!"<<endl;
                    cout<<endl<<"Vertices of that input word not found in given boundaries of rows and columns!"<<endl;
                }

                nextinput:;
                //NOW LOOP WILL MOVE TO FIND THE INDEXES OF NEXT INPUT WHICH FOR WHICH I HAVE MADE SPECIALLY A SEPERATE CHARACTER ARRAY FOR INPUT BEFORE THESE LOOPS
            }
            system("pause");
            return 0;
    }
    if(option[0]=='Q')
    {
        return 0;
    }
    return 0;
}

