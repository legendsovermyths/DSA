function countUniqueValues(arr) {
  var count = 1;
  var left = 0;
  var right = 1;
  if (arr.length === 0) {
    return 0;
  }
  while (right < arr.length) {
    if (arr[right] != arr[left]) {
      count++;
      right += 1;
      left += 1;
    } else {
      right += 1;
      left += 1;
    }
  }
  return count;
}
