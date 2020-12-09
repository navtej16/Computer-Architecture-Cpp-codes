#include <iostream>
#include<bits/stdc++.h> 
#include <vector>
#include <string>
#include <fstream>

using namespace std;

long double intpoint( int T , int E , long arr[] ) {
 long double sum = 0 ;
long double sum1 = 0 ;
     for(int i = T-1 ; i >= 1 ; i--)
     {
          sum = sum + arr[i] * ( pow(2, T - 1 - i )  ) ;
          cout<< sum << endl ;
     }

    




    long double finalnumber = sum + sum1 ;
if(arr[0] == 0 )
    {
         finalnumber = 1 * finalnumber ;
    }
    else {
         finalnumber = -1 * finalnumber ;
    }
     return finalnumber;




}

long double fixedpoint( int T , int E , long arr[] ) {
 long double sum = 0 ;
long double sum1 = 0 ;
     for(int i = E-1 ; i >= 0 ; i--)
     {
         
          sum = sum + arr[i] * ( pow(2, E -1 - i )  ) ;
          cout<< sum << endl ;
     }

     

     for(int i = E ; i <= T -1 ; i++ )
     {
          
          sum1 = sum1 + arr[i] * (  pow( 2, E - i -1 ) )  ;
         cout<< sum1 <<endl ;
     }

    long double finalnumber = sum + sum1 ;
if(arr[0] == 0 )
    {
         finalnumber = 1 * finalnumber ;
    }
    else {
         finalnumber = -1 * finalnumber ;
    }
     return finalnumber;




}




long double floatingpoint( int T , int E , long arr[] ) {
 long double sum = 0 ;
long double sum1 = 0 ;
     for(int i = E ; i >= 1 ; i--)
     {
         
          sum = sum + arr[i] * ( pow(2, E - i)  ) ;
          cout<< sum << endl ;
     }

     

     for(int i = E+1 ; i <= T -1 ; i++ )
     {
          
          sum1 = sum1 + arr[i] * (  pow( 2, E + 1 - i -1 ) )  ;
         cout<< sum1 <<endl ;
     }

    long double finalnumber = ( 1 + sum1 ) * ( pow ( 2 , sum - 127)  ) ;
if(arr[0] == 0 )
    {
         finalnumber = 1 * finalnumber ;
    }
    else {
         finalnumber = -1 * finalnumber ;
    }
     return finalnumber;

}


int main()
{
    int T ,E ;
    string categ;
    string arr ;
    cin >> T ;
    cin >> E;
    cin >> categ ;
     
     
    

    if (categ == "Single"){
         cin >> arr ;
     

   ofstream MyFile(std::string ("19116043_") +  to_string(T) + std::string("_") + to_string(E) + "_Single"+ std::string(arr) +".txt");
  
          
  long  intArray[arr.length()];
  for(int idx = 0; idx < arr.length() ; idx++)
  {
    intArray[idx] = arr[idx] - '0';
  }
 long double a  = floatingpoint( T , E , intArray );
 long double b  = fixedpoint( T , E , intArray );
 long double c  = intpoint( T , E , intArray );

 MyFile << " FP IEEE764 Format - " << a ;
 MyFile << " Fixed Point Format - " << b ;
 MyFile << " Int point Format - " << c ;

 

  MyFile.close();
 
    } 

    else {

         ofstream MyFile(std::string ("19116043_") +  to_string(T) + std::string("_") + to_string(E) + "_All.txt");

         int a = 1 ;
         long b =0  ;

         for (int x = 0 ; x < T ; x++ ) {

         b = b + pow(2 , x ) ; 
         
         }

         cout <<b ;
 
         for ( int j =0 ; j <= b ; j++ )
         {
              
             

             long bin32[T] ;
             for (int i =0 ;i <T ;i++) {
                  bin32[i] = 0 ;
             }

             int c = j ;

            for (int pos = T-1 ; pos >= 0; pos-- )
            {
               if (c % 2 != 0) 
               bin32[pos] = 1;
              cout<< pos <<endl;
               c = c /  2;
            } 
             
              string bin = "";
            
             for (int i =0 ;i <T ;i++) {
                  cout << bin32[i] ;
                  bin +=  to_string(bin32[i]) ;
             }

             cout<<endl ;

           long double a  = floatingpoint( T , E , bin32 );
           long double b  = fixedpoint( T , E , bin32 );
           long double d  = intpoint( T , E , bin32 );
             cout << a ;
             MyFile << " FP IEEE764 Format of " << bin << " " << a << endl ;
             MyFile << " fixedPoint  Format of "<< bin << " " << b << endl ;
             MyFile << " int Format of "<< bin << " " << d << endl ;
             
            


              

         }




    }

 //  long ieee[32] 
 //       = { 1, 
 //           1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 
 //           0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
 //           0, 0, 0, 0, 0, 0, 0, 0, 0 }; 
// 11000000000100000000000000000000

  //  cout<<floatingpoint( 32 , 8 , ieee );
 //    cout<<fixedpoint( 32 , 8 , ieee );
  // cout<<intpoint( 32 , 8 , ieee );
   return 0;

}