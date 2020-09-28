function nestedEvenSum(obj) {
  var newArr = [];
  function helper(newObj) {
    for (var obj2 in newObj) {
      if (typeof newObj[obj2] === "object") {
        helper(newObj[obj2]);
      }
      if (typeof newObj[obj2] === "number") {
        if (newObj[obj2] % 2 == 0) {
          newArr.push(newObj[obj2]);
        }
      }
    }
  }
  helper(obj);
  if (newArr.length === 0) return 0;
  return newArr.reduce((a, b) => a + b);
}
