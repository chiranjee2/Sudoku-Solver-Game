def is_valid(board, row, col, c):
    for i in range(9):
        if board[i][col] == c or board[row][i] == c:
            return False

        if board[3 * (row // 3) + i // 3][3 * (col // 3) + i % 3] == c:
            return False

    return True

def solve_sudoku(board):
    for i in range(9):
        for j in range(9):
            if board[i][j] == 0:
                for c in range(1, 10):
                    if is_valid(board, i, j, c):
                        board[i][j] = c

                        if solve_sudoku(board):
                            return True
                        else:
                            board[i][j] = 0

                return False

    return True

if __name__ == "__main__":
    board = [list(map(int, input().split())) for _ in range(9)]

    if solve_sudoku(board):
        for row in board:
            print(*row)
    else:
        print("This is not a valid Sudoku.")
