import java.util.ArrayList;
import java.util.Scanner;

public class bingoJava {
public static void main(String[] args) {
    int [][]initialBoard = new int[5][5];
    int [][]playerPattern = new int[5][5];
    int [][]bingoBoard = new int[5][5];
    ArrayList<Integer> callNums = new ArrayList<>();

    int count=0; 
    int noRotateCount= 0; 
    int rotationCount1 = 0;
    int rotationCount2 = 0;
    int rotationCount3 = 0;

    Scanner scan = new Scanner(System.in);

//Scan in Winning Patter Bingo Board
    for(int row=0; row<5; row++)
    {
        for(int col=0; col<5;col++)
        {
            initialBoard[row][col] = scan.nextInt();

        }
    }

//Get to the Next set of Integers
    scan.nextLine();
    scan.nextLine();


//Scan in the Call Numbers into the ArrayList
 String [] s = scan.nextLine().split(" ");

 for (int i = 0; i < s.length; i++) {
     callNums.add(Integer.parseInt(s[i]));
 }
 

//Scan in the Bingo Board. 
 for(int row=0; row<5; row++)
 {
     for(int col=0; col<5;col++)
     {
         bingoBoard[row][col] = scan.nextInt();

     }
 }

//Checks to see if board contains 1s or 4s
 for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
        if (initialBoard[i][j] == 1 || initialBoard[i][j] == 4) {
            count++;
        }
    }
}
//copmpares callNumbers to Players Bingo Board. 
for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
        if (callNums.contains(bingoBoard[i][j])) {
            playerPattern[i][j] = 1;
        }
        else {
            playerPattern[i][j] = 0;
        }
    }
}

//Set 00 Free Space
playerPattern[2][2] = 1;

// compare winning pattern to playerPattern
for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
        if (initialBoard[i][j] == 1 && playerPattern[i][j] == 1) {
            noRotateCount++;
        }
        if (initialBoard[i][j] == 4 && playerPattern[i][j] == 1) {
            noRotateCount++;
        }
        rotate90Clockwise(initialBoard);
        if (initialBoard[i][j] == 4 && playerPattern[i][j] == 1) {
            rotationCount1++;
        }
        rotate90Clockwise(initialBoard);
        if (initialBoard[i][j] == 4 && playerPattern[i][j] == 1) {

            rotationCount2++;
        }
        rotate90Clockwise(initialBoard);
        if (initialBoard[i][j] == 4 && playerPattern[i][j] == 1) {

            rotationCount3++;
        }
        rotate90Clockwise(initialBoard);
    }
}


//Checks to See if Bingo Board is Winner Or Not

        if (count == noRotateCount) {
            System.out.println("VALID BINGO");
        }
        else if(count == rotationCount1){
            System.out.println("VALID BINGO");
        }
        else if(count == rotationCount2){
            System.out.println("VALID BINGO");
        }
        else if(count == rotationCount3){
            System.out.println("VALID BINGO");
        }
        else{
            System.out.println("NO BINGO");
        }







     
} 

//Rotate Matrix Method: Found Online
static void rotate90Clockwise(int a[][])
{
 
    // Traverse each cycle
    for (int i = 0; i < 5 / 2; i++)
    {
        for (int j = i; j < 5 - i - 1; j++)
        {
 
            // Swap elements of each cycle
            // in clockwise direction
            int temp = a[i][j];
            a[i][j] = a[5 - 1 - j][i];
            a[5 - 1 - j][i] = a[5 - 1 - i][5 - 1 - j];
            a[5 - 1 - i][5 - 1 - j] = a[j][5 - 1 - i];
            a[j][5 - 1 - i] = temp;
        }
    }
}

}
