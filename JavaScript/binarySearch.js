function binarySearch(arr, key) {
  var left = 0;
  var right = arr.length - 1;
  var mid = Math.floor((left + right) / 2);
  while (left <= right) {
    if (arr[mid] === key) {
      return mid;
    }
    if (arr[mid] > key) {
      right = mid - 1;
      mid = Math.floor((left + right) / 2);
    }
    if (arr[mid] < key) {
      left = mid + 1;
      mid = Math.floor((left + right) / 2);
    }
  }
  return -1;
}
console.log(binarySearch([12, 13, 14, 15, 16, 17, 18], 19));
