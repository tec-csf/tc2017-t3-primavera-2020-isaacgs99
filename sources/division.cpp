#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

/**
 * Resets a value to zero
 * 
 * @param[in] an integer.
 * 
 * @returns the new integer value.
*/
int reset(int a)
{
  a = 0;
  return a;
}
/**
 * Resets a value to zero
 * 
 * @param[in] a double.
 * 
 * @returns the new double value.
*/
double reset(double a)
{
  a = 0;
  return a;
}
/**
 * Calculates a cost
 * 
 * @param[in] index i, index j, optimal space, total accumulated and maximum length of width.
 * 
 * @returns the new integer value.
*/
double cost(double i, double j, double b, double total, double L)
{
  double costo = 0.0;
  if(j==i){ 
  /*
  if a new line is created and the next new word doesn't 
  fit, it assumes that the cost always be higher
  */
    return 10000;
  }else{
  double bPrime = (L - total)/(j-i); 
  costo = (j-i)*(abs(bPrime-b));
  }

  return costo;
}

/**
 * Wraps the text to the optimal line length
 * 
 * @param[in] text, the line length, optimal space and total words.
 * 
 * @returns the wrapped text.
*/
void wrap( vector<double> text, double line_length, double b, int n)
{
    double k = 1.0;
    double j = 1.0;
    int linea = 1;
    double cost_1 = 0.0;
    double cost_2 = 0.0;
    double total = 0.0; //total cost 
    double lengthTotal = 0.0; //number of words and spaces on a line
    double totalWords = 0.0; //number of words on a line

    cout<<"Linea "<<linea<<": "<<"(";
    
    for(int i = 0; i<n; i++)
    {
      if (text[i] + lengthTotal + b < line_length) //Checks if a word can fit with spaces included
      {

          cout<<text[i]<<", ";
          lengthTotal += text[i] + b; 
          totalWords += text[i];
          j++;
        
      }else
      {
        if (text[i] + lengthTotal == line_length ) //Checks if a word can fit without spaces included to finish the line
        {
          cout<<text[i]<<")"<<endl;
          k = j;
          j++;
          linea++;
          cout<<"Linea "<<linea<<": "<<"(";

          totalWords = reset(totalWords);
          lengthTotal = reset(lengthTotal);
        }else //Checks where the word is going to have less cost
        {
          totalWords += text[i];
          cost_1 = cost(k,j,b,totalWords,line_length); //cost to decrement space
          cost_2 = cost(k,j-1,b,totalWords-text[i],line_length); //cost to increment space

          if (cost_1<cost_2)
          {
            cout<<text[i]<<")"<<endl;
            total += cost_1;
            k = j+1;
            j++;
            linea++;
            cout<<"Linea "<<linea<<": "<<"(";
            totalWords = reset(totalWords);
            lengthTotal = reset(lengthTotal);

          }else{
            cout<<")"<<endl;
            total += cost_2;
            k = j;
            j++;
            linea++;
            totalWords = reset(totalWords);
            lengthTotal = reset(lengthTotal);

            lengthTotal += text[i] + b; 
            totalWords += text[i];
            cout<<"Linea "<<linea<<": "<<"("<<text[i]<<",";
            
          }
        } 
      }      
    }
    cout<<"\nEl costo total fue: "<< total<< endl;
  
}
 
int main()
{
  //Ejemplo 1
  double lineLength = 26.0;
  double optimalSpace = 2.0; 

  vector<double> text;
  text.push_back(10.0);
  text.push_back(10.0);
  text.push_back(4.0);
  text.push_back(8.0);
  text.push_back(10.0);
  text.push_back(12.0);
  text.push_back(12.0);

  wrap(text,lineLength, optimalSpace,text.size());

  cout<< "Este algoritmo tiene una complejidad O(n)"<<endl;
}