
void increaseArray(int**& ary, int& numRows, int& numColumns, 
				int addRows, int addColumns);


int main()
{
}

void increaseArray(int**& ary, int& numRows, int& numColumns, 
				int addRows, int addColumns)
{
   // Allocate new array to be size (numRows + addRows) x (numColumns + addColumns)
   int** temp = new int*[numRows + addRows];
   for (int i = 0; i< (numRows + addRows); i++)
      temp[i] = new int[numColumns + addColumns];
   
}
