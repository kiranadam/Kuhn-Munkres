/********************************************************************
 ********************************************************************
 ** C++ class modified implemention of Kuhn-Munkres algorithm by Kirankumar, 2017 
 **	
 ** from David Schwarz, 2012 and O(n^3) implementation derived from libhungarian by Cyrill Stachniss, 2004
 **
 **
 ** Solving the Minimum Assignment Problem using the 
 ** Hungarian Method.
 **
 ** ** This file may be freely copied and distributed! **
 **
 **
 ** This file is distributed in the hope that it will be useful,
 ** but WITHOUT ANY WARRANTY; without even the implied 
 ** warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 ** PURPOSE.  
 **
 ********************************************************************
 ********************************************************************/

#include "hungarian.hpp"
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > array_to_matrix(int* m, int rows, int cols)
{
  	int i,j;
  	vector<vector<int> > r;
  	r.resize(rows, vector<int>(cols, 0));

  	for(i=0;i<rows;i++)
  	{
    		for(j=0;j<cols;j++)
      			r[i][j] = m[i*cols+j];
  	}
  	return r;
}


int main(int , char**) 
{

  	/* an example cost matrix */
  	int r[4*3] =  {	100, 100, 1, 
			100, 2, 21512, 
			1, 4, 9852, 
			6, 30252, 400 };

  	vector<vector<int> > m = array_to_matrix(r,4,3);	

  	/* initialize the gungarian_problem using the cost matrix*/
  	Hungarian<int> hungarian(m , 4,3, HUNGARIAN_MODE_MINIMIZE_COST) ;

  	/* some output */
  	cout<<"cost-matrix:";
  	hungarian.print_cost();

  	/* solve the assignement problem */
  	hungarian.solve();

  	/* some output */
  	cout<<"\nassignment:";
  	hungarian.print_assignment();

  	return 0;
}

