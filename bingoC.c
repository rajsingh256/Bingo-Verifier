#include <stdio.h>
#include <string.h>
void rotate90Clockwise(char* a[5][5])
{

 char* temp1;
 char* temp2;
 char* temp3;
 char* temp4;
 // Traverse each cycle
 for (int i = 0; i < 5 / 2; i++)
 {
 for (int j = i; j < 5 - i - 1; j++)
 {
 // Swap elements of each cycle
 // in clockwise direction
 char* temp = a[i][j];
 temp2 = &a[5 - 1 - j][i];
 strcpy(&a[i][j], temp2);
 temp3 = &a[5 - 1 - i][5 - 1 - j];
 strcpy(&a[5-1-j][i], temp3);
 temp4 = &a[j][5 - 1 - i];
 strcpy(&a[5-1-i][5-1-j], temp4);
 temp1 = &temp;
 strcpy(&a[j][5-1-i], temp1);
 }
 }
}
int main(){
 char* initialBoard[5][5];
 char* bingoBoard[5][5];
 char numStr[225];

 int count=0;
 int noRotateCount=0;
 int rotateCount1=0;
 int rotateCount2=0;
 int rotateCount3=0;

 char *calledStrNums[75];
 char *oneStrNum;
 int calledCt = 0;
 //scan in initial Board
 for(int row=0; row<5; row++)
 {
 for(int col=0; col<5;col++)
 {
 fscanf(stdin,"%s",&initialBoard[row][col]);
 }
 }

 fgets(numStr,225,stdin);
 fgets(numStr,225,stdin);
 fgets(numStr,225,stdin);
 numStr[strlen(numStr + 1)] = 32;
 oneStrNum = strtok(numStr," ");

 /* tokenize the string of space-separated numbers */
 while (oneStrNum != NULL) {
 calledStrNums[calledCt] = oneStrNum;
 calledCt = calledCt + 1;
 oneStrNum = strtok(NULL," ");
 }
//use callStrNums
 //Scan in Actual Bingo Board
 for(int row=0; row<5; row++)
 {
 for(int col=0; col<5;col++)
 {
 fscanf(stdin,"%s",&bingoBoard[row][col]);
 }
 }
 //Checks to see if board contains 1s or 4s
 char* temp1;
 char* temp2 = "1";
 char* temp3 = "4";
 char* tempX = "X";

 for (int i = 0; i < 5; i++)
 {
 for (int j = 0; j < 5; j++)
 {
 temp1 = &initialBoard[i][j];

 if (strcmp(temp1 , temp2) == 0 || strcmp(temp1, temp3) == 0)
 {
 count++;
 }
 }
 }
 //copmpares callNumbers to Players Bingo Board.
for (int k=0; k<calledCt; k++) {
 temp1 = calledStrNums[k];
 for (int i = 0; i < 5; i++) {
 for (int j = 0; j < 5; j++) {
 temp2 = &bingoBoard[i][j];
 if(strcmp(temp2, temp1) == 0)
 strcpy(&bingoBoard[i][j], "X");
 }
 }
}
//Set 00 Free Space
strcpy(&bingoBoard[2][2], "X");
temp2 = "1";
for (int i=0; i<5; i++){
 for (int j=0; j<5; j++){
 char* tempNew1 = &initialBoard[i][j];
 char* tempNew2 = &bingoBoard[i][j];

 if(strcmp(tempNew1, temp2) == 0 && strcmp(tempNew2, tempX) == 0)
 {
 noRotateCount++;
 }
 if(strcmp(tempNew1, temp3) == 0 && strcmp(tempNew2, tempX) == 0)
 {
 noRotateCount++;
 }
 rotate90Clockwise(initialBoard);
 if(strcmp(tempNew1, temp3) == 0 && strcmp(tempNew2, tempX) == 0)
 {
 rotateCount1++;
 }
 rotate90Clockwise(initialBoard);
 if(strcmp(tempNew1, temp3) == 0 && strcmp(tempNew2, tempX) == 0)
 {
 rotateCount2++;
 }
 rotate90Clockwise(initialBoard);
 if(strcmp(tempNew1, temp3) == 0 && strcmp(tempNew2, tempX) == 0)
 {
 rotateCount3++;
 }
 rotate90Clockwise(initialBoard);
 }
 }
 if (count == noRotateCount) {
 printf("VALID BINGO");
 }
 else if(count == rotateCount1){
 printf("VALID BINGO");
 }
 else if(count == rotateCount2){
 printf("VALID BINGO");
 }
 else if(count == rotateCount3){
 printf("VALID BINGO");
 }
 else{
 printf("NO BINGO");
 }
} 