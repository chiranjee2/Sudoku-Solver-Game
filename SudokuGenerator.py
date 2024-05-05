import random

def is_safe(grid, row, col, num):
    for i in range(9):
        if grid[row][i] == num or grid[i][col] == num:
            return False

        if grid[3 * (row // 3) + i // 3][3 * (col // 3) + i % 3] == num:
            return False

    return True

def generate_sudoku_board():
    grid = [[0] * 9 for _ in range(9)]
    random.seed()

    non_zero_elements = 6 + random.randint(0, 16)
    for _ in range(non_zero_elements):
        while True:
            num = random.randint(1, 9)
            row = random.randint(0, 8)
            col = random.randint(0, 8)

            if grid[row][col] == 0 and is_safe(grid, row, col, num):
                grid[row][col] = num
                break

    for row in grid:
        print(*row)

if __name__ == "__main__":
    generate_sudoku_board()
