
void printArray(int a, int b, const int (*(&arr))[3] )
{
  for(int i=0; i<a; i++)
  {
    for(int j=0; j < b; j++)
    {
      std::cout << arr[i][j] << "  ";
    }
    std::cout << std::endl;
  }

}


int main()
{
  const int arr[][3] = { {1, 2, 3}, {2, 3, 4} };
  printArray(2, 3, arr); 
  return 0;

} 
