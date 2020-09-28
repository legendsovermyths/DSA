function flatten(arr) {
  var newArr = [];
  function helper(oldArr) {
    for (var i = 0; i < oldArr.length; i++) {
      if (Array.isArray(oldArr[i])) {
        helper(oldArr[i]);
      } else {
        newArr.push(oldArr[i]);
      }
    }
  }
  helper(arr);
  return newArr;
}
console.log(flatten([1, 2, 3, [4, 5]]));
