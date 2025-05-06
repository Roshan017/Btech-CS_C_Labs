#include <ctype.h>
#include <stdio.h>
#include <string.h>



int main() {
  FILE *input, *output, *symbol;
  int l = 1; 
  int t = 1; 
  int id = 0;
  int i, flag;
  char ch, str[20];
  char symbolTable[1000][20]; 
  int symbolCount = 0;                   

  input = fopen("input.txt", "r");
  output = fopen("output.txt", "w");
  symbol = fopen("symbol.txt", "w");
  fprintf(symbol, "Symbol Table:\nId No\t\t\tId Name\n");
  fprintf(output, "Line no. \t\t Token no. \t\t Token \t\t Lexeme\n\n");

  while ((ch = fgetc(input)) != EOF) {
    i = 0;
    flag = 0;

    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '=' ||
        ch == '!' || ch == '<' || ch == '>') {
      char op = ch;
      ch = fgetc(input);

      if ((op == '=' && ch == '=') || (op == '!' && ch == '=') ||
          (op == '<' && ch == '=') || (op == '>' && ch == '=')) {
        fprintf(output, "%7d\t\t %7d\t\t Operator\t %7c%c\n", l, t++, op, ch);
      } else if ((op == '&' && ch == '&') || (op == '|' && ch == '|')) {
        fprintf(output, "%7d\t\t %7d\t\t Operator\t %7c%c\n", l, t++, op, ch);
      } else {
        ungetc(ch, input);
        fprintf(output, "%7d\t\t %7d\t\t Operator\t\t %7c\n", l, t++, op);
      }
    }

    else if (ch == ';' || ch == '{' || ch == '}' || ch == '(' || ch == ')' ||
             ch == '?' || ch == '@' || ch == '%' || ch == ',' || ch == '[' ||
             ch == ']') {
      fprintf(output, "%7d\t\t %7d\t\t Special symbol\t %7c\n", l, t++, ch);
    }

    else if (isdigit(ch)) {
      str[i] = ch;
      i++;
      ch = fgetc(input); 

      while (isdigit(ch)) {
        str[i] = ch;
        i++;
        ch = fgetc(input);
      }

      str[i] = '\0';
      fprintf(output, "%7d\t\t %7d\t\t Number\t\t %7s\n", l, t++, str);
      ungetc(ch, input);
    }

    else if (isalpha(ch)) {
      str[i] = ch;
      i++;
      ch = fgetc(input); 

      while (isalnum(ch) || ch == '_') {
        str[i] = ch;
        i++;
        ch = fgetc(input);
      }

      str[i] = '\0'; 

      
      if (str[0] == 'i') {
        if (str[1] == 'f') {
          if (str[2] == '\0') {
            flag = 1;
          }
        } else if (str[1] == 'n') {
          if (str[2] == 't') {
            if (str[3] == '\0') {
              flag = 1; 
            }
          }
        }
      } else if (str[0] == 'v') {
        if (str[1] == 'o') {
          if (str[2] == 'i') {
            if (str[3] == 'd') {
              if (str[4] == '\0') {
                flag = 1; 
              }
            }
          }
        }
      } else if (str[0] == 'w') {
        if (str[1] == 'h') {
          if (str[2] == 'i') {
            if (str[3] == 'l') {
              if (str[4] == 'e') {
                if (str[5] == '\0') {
                  flag = 1;
                }
              }
            }
          }
        }
      } else if (str[0] == 'f') {
        if (str[1] == 'l') {
          if (str[2] == 'o') {
            if (str[3] == 'a') {
              if (str[4] == 't') {
                if (str[5] == '\0') {
                  flag = 1;
                }
              }
            }
          }
        } else if (str[1] == 'o') {
          if (str[2] == 'r') {
            if (str[3] == '\0') {
              flag = 1; 
            }
          }
        }
      } else if (str[0] == 'm') {
        if (str[1] == 'a') {
          if (str[2] == 'i') {
            if (str[3] == 'n') {
              if (str[4] == '\0') {
                flag = 1;
              }
            }
          }
        }
      }

      if (flag == 1) {
        fprintf(output, "%7d\t\t %7d\t\t Keyword\t\t %7s\n", l, t++, str);
      } else {
        // Check for duplicate identifier in the symbol table
        int isDuplicate = 0;
        for (int j = 0; j < symbolCount; j++) {
          if (strcmp(symbolTable[j], str) == 0) {
            isDuplicate = 1;
            break;
          }
        }

        if (!isDuplicate) {
          // Add new identifier to the symbol table
          strcpy(symbolTable[symbolCount++], str);
          fprintf(symbol, "Id%d\t\t\t%7s\n", id++, str);
        }
      }

      ungetc(ch, input);
    }

    else if (ch == '\n') {
      l++;
    }
  }

  

  fclose(input);
  fclose(output);
  return 0;
}
/*
input.txt
void main()
{
int a = 5;

if (a > 0) {
    a = a + 1;
}

output.txt
Line no. 		 Token no. 		 Token 		 Lexeme

      1		       1		 Keyword		    void
      1		       2		 Keyword		    main
      1		       3		 Special symbol	       (
      1		       4		 Special symbol	       )
      2		       5		 Special symbol	       {
      3		       6		 Keyword		     int
      3		       7		 Operator		       =
      3		       8		 Number		       5
      3		       9		 Special symbol	       ;
      5		      10		 Keyword		      if
      5		      11		 Special symbol	       (
      5		      12		 Operator		       >
      5		      13		 Number		       0
      5		      14		 Special symbol	       )
      5		      15		 Special symbol	       {
      6		      16		 Operator		       =
      6		      17		 Operator		       +
      6		      18		 Number		       1
      6		      19		 Special symbol	       ;
      7		      20		 Special symbol	       }

symbol.txt
Symbol Table:
Id No			Id Name
Id0			      a

*/