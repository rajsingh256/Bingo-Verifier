import sys


# Scan in Winning Pattern Bingo Board
def winning_pattern_board():
    initialBoard = []
    for i in range(0, 5):
        row = (input().split())
        numbers = [int(num) for num in row]

        initialBoard.append(numbers)
    return initialBoard


# Scan in Call Numbers
def call_numbers():
    input()
    row = (input().split())
    numbers = [int(num) for num in row]
    input()
    return numbers


# Scan in Actual Bingo Board
def actual_bingo_board():
    bingoBoard = []
    for i in range(0, 5):
        row = (input().split())
        numbers = [int(num) for num in row]

        bingoBoard.append(numbers)
    return bingoBoard


# Check and get count of if there are any 1's or 4's in the initial board
def check_count(initial_board):
    count = 0
    for i in range(0, 5):
        for j in range(0, 5):
            if initial_board[i][j] == 1 or initial_board[i][j] == 4:
                count = count + 1

    return count


def check_if_crazy(initial_board):
    for i in range(0, 5):
        for j in range(0, 5):
            if initial_board[i][j] == 4:
                return True

    return False


# Compare the call numbers to the actaual bingo board
def compare_nums_to_board(call_nums, bingo_board):
    player_pattern = []

    for i in range(0, 5):
        temp = []
        for j in range(0, 5):
            if bingo_board[i][j] in call_nums:
                temp.append(1)
            else:
                temp.append(0)
        player_pattern.append(temp)
    return player_pattern


#  Rotate Matrix Found Online But it Works THO
def rotate_matrix(matrix):
    rows = len(matrix)
    columns = len(matrix[0])

    # inverse row
    for i in range(rows // 2):
        matrix[i], matrix[columns - i - 1] = \
            matrix[columns - i - 1], matrix[i]

    # transpose
    for i in range(rows):
        for j in range(i):
            matrix[i][j], matrix[j][i] = \
                matrix[j][i], matrix[i][j]


def main():
    winPattern = winning_pattern_board()
    bingoNUms = call_numbers()
    bingoBoard = actual_bingo_board()
    player_pattern = compare_nums_to_board(bingoNUms, bingoBoard)
    player_pattern[2][2] = 1

    count = check_count(winPattern)

    noRotateCount = 0
    rotateCount1 = 0
    rotateCount2 = 0
    rotateCount3 = 0

    for i in range(0, 5):
        for j in range(0, 5):
            if winPattern[i][j] == 1 and player_pattern[i][j] == 1:


                noRotateCount+=1

            else:
                if winPattern[i][j] == 4 and player_pattern[i][j] == 1:

                    noRotateCount+=1

                    


                rotate_matrix(winPattern)
                if winPattern[i][j] == 4 and player_pattern[i][j] == 1:
                    rotateCount1 = rotateCount1 + 1
                rotate_matrix(winPattern)

                if winPattern[i][j] == 4 and player_pattern[i][j] == 1:
                    rotateCount2 = rotateCount2 + 1
                rotate_matrix(winPattern)

                if winPattern[i][j] == 4 and player_pattern[i][j] == 1:
                    rotateCount3 = rotateCount3 + 1
                rotate_matrix(winPattern)



   
    if count <= noRotateCount:
        print("Valid Bingo")
        sys.exit()
    else:
        if check_if_crazy(winPattern):

            if count == rotateCount1:
                print("Valid Bingo")
                sys.exit()

            if count == rotateCount2:
                print("Valid Bingo")
                sys.exit()

            if count == rotateCount3:
                print("Valid Bingo")
                sys.exit()
            else:
                print("No Bingo")

        else:
            print("No Bingo")


main()