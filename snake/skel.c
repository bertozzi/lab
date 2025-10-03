#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

// DO NOT MODIFY THIS SECTION... NOT NEEDED AT THE BEGINNING OF THE DEVELOPMENT
// ALREADY DEFINED FUNCTIONS: 

void gotoxy(int, int);                   // move the cursor to a given screen position (column and row, respectively)
                                         // when used before a printf() or similar functions it allows to print at an arbitrary
                                         // position on the screen
                                         // the top-left position on the screen has (0, 0) coordinates. 
                                         //  column index increases moving right
                                         //  row index increases moving down

char getcommand(void);                   // read a char from keyboard in a non blocking fashion, returns 0 if no key has been stroke


void clearscreen(void);                  // clear the whole screen (actually, not needed)
// END OF SECTION THAT MUST NOT BE MODIFIED


int main()
{

  // YOUR CODE HERE

  return 0;
}








// PREDEFINED FUNCTIONS DO NOT MODIFY BELOW THIS LINE!

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <conio.h>

char getcommand(void)
{

  char ch = 0;

  if (kbhit())
  {
    ch = getch(); // Read the character
  }

  return ch;
}

void gotoxy(int x, int y)
{
  COORD coord = {.X = x, .Y = y};
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void clearscreen()
{
  HANDLE                     hStdOut;
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  DWORD                      count;
  DWORD                      cellCount;
  COORD                      homeCoords = { 0, 0 };

  hStdOut = GetStdHandle( STD_OUTPUT_HANDLE );
  if (hStdOut == INVALID_HANDLE_VALUE) return;

  /* Get the number of cells in the current buffer */
  if (!GetConsoleScreenBufferInfo( hStdOut, &csbi )) return;
  cellCount = csbi.dwSize.X *csbi.dwSize.Y;

  /* Fill the entire buffer with spaces */
  if (!FillConsoleOutputCharacter(
    hStdOut,
    (TCHAR) ' ',
    cellCount,
    homeCoords,
    &count
    )) return;

  /* Fill the entire buffer with the current colors and attributes */
  if (!FillConsoleOutputAttribute(
    hStdOut,
    csbi.wAttributes,
    cellCount,
    homeCoords,
    &count
    )) return;

  /* Move the cursor home */
  SetConsoleCursorPosition( hStdOut, homeCoords );
}

#else // !_WIN32
#include <unistd.h>
#include <term.h>


void gotoxy(int x, int y)
{
  printf("%s%d;%d%c", "\033[", y+1, x+1, 'H');
  fflush(stdout);
}

void clearscreen()
{
   printf("\e[2J\e[H");
}

char getcommand(void)
{
  gotoxy(COLS, ROWS);
  printf("\b \b");
  struct termios orig_term, raw_term;

  // Get terminal settings and save a copy for later
  tcgetattr(STDIN_FILENO, &orig_term);
  raw_term = orig_term;

  // Turn off echoing and canonical mode
  raw_term.c_lflag &= ~(ECHO | ICANON);

  // Set min character limit and timeout to 0 so read() returns immediately
  // whether there is a character available or not
  raw_term.c_cc[VMIN] = 0;
  raw_term.c_cc[VTIME] = 0;

  // Apply new terminal settings
  tcsetattr(STDIN_FILENO, TCSANOW, &raw_term);

  char ch = 0;
  int len = read(STDIN_FILENO, &ch, 1);
  if(len == 1)
  {
    printf("\b \b");
    fflush(stdout);
  }

  // Make sure no characters are left in the input stream as
  // plenty of keys emit ESC sequences, otherwise they'll appear
  // on the command-line after we exit.
  while(read(STDIN_FILENO, &ch, 1)==1)
    printf("\b \b");;

  // Restore original terminal settings
  tcsetattr(STDIN_FILENO, TCSANOW, &orig_term);
  if(len == 1)
    printf("\b \b");;
  return ch;
}
#endif
