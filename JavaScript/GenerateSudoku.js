var numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9];
function shuffle(array) {
  var m = array.length,
    t,
    i;
  while (m) {
    i = Math.floor(Math.random() * m--);
    t = array[m];
    array[m] = array[i];
    array[i] = t;
  }

  return array;
}
function fillDiagonal(SudokuGrid) {
  const array1 = shuffle(numbers);
  for (let i = 0; i < 3; i++) {
    for (let j = 0; j < 3; j++) {
      SudokuGrid[i][j] = array1[3 * i + j];
    }
  }
  const array2 = shuffle(numbers);
  for (let i = 3; i < 6; i++) {
    for (let j = 3; j < 6; j++) {
      SudokuGrid[i][j] = array2[3 * (i - 3) + (j - 3)];
    }
  }
  const array3 = shuffle(numbers);
  for (let i = 6; i < 9; i++) {
    for (let j = 6; j < 9; j++) {
      SudokuGrid[i][j] = array3[3 * (i - 6) + (j - 6)];
    }
  }
  return SudokuGrid;
}
function isValid(board, row, col, k) {
  for (let i = 0; i < 9; i++) {
    const m = 3 * Math.floor(row / 3) + Math.floor(i / 3);
    const n = 3 * Math.floor(col / 3) + (i % 3);
    if (board[row][i] == k || board[i][col] == k || board[m][n] == k) {
      return false;
    }
  }
  return true;
}

function sodokoSolver(SudokuGrid) {
  for (let i = 0; i < 9; i++) {
    for (let j = 0; j < 9; j++) {
      if (SudokuGrid[i][j] == 0) {
        for (let k = 1; k <= 9; k++) {
          if (isValid(SudokuGrid, i, j, k)) {
            SudokuGrid[i][j] = k;
            if (sodokoSolver(SudokuGrid)) {
              return true;
            } else {
              SudokuGrid[i][j] = 0;
            }
          }
        }
        return false;
      }
    }
  }
  return true;
}
function removeKDigits(k, sudokuGrid) {
  var count = k;
  while (count != 0) {
    var cellId = Math.floor(Math.random() * 81);
    var row = Math.floor(cellId / 9);
    var col = cellId % 9;
    if (col != 0) {
      col = col - 1;
    }
    if (sudokuGrid[row][col] != 0) {
      count--;
      sudokuGrid[row][col] = 0;
    }
  }
}
let array = Array(9)
  .fill()
  .map(() => Array(9).fill(0));
let SudokuGrid = fillDiagonal(array);
sodokoSolver(fillDiagonal(SudokuGrid));
removeKDigits(51, SudokuGrid);
printSudokuGrid(SudokuGrid);
function printSudokuGrid(sudokuGrid) {
  for (let i = 0; i < 9; i++) {
    console.log(sudokuGrid[i]);
  }
}
