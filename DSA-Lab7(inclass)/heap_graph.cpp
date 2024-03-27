#include <iostream>
using namespace std;
int main() {
  FILE *gnuplotPipe = popen("gnuplot -persistent", "w");
  fprintf(gnuplotPipe, "set title 'Heap Sort'\n");
  fprintf(gnuplotPipe, "set xlabel 'inputs'\n");
  fprintf(gnuplotPipe, "set ylabel 'time'\n");
  fprintf(gnuplotPipe, "plot 'text.txt' with linespoints title 'Heap' \n");
  fflush(gnuplotPipe);
  return 0;
}