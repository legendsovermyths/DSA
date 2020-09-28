function someRecursicve(arr, func) {
  if (arr.length === 0) return false;
  if (func(arr[0])) return true;
  if (!func(arr[0])) return someRecursicve(arr.splice(1), func);
}
console.log(someRecursicve([2, 8, 4, 12, 6], (val) => val % 2 == 1));
