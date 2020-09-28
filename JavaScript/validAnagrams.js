const validAnagram = (str1, str2) => {
  var obj1 = {};
  var obj2 = {};
  if (str1.length != str2.length) {
    return false;
  }
  for (var str of str1) {
    if (str in obj1) {
      obj1[str] += 1;
    } else {
      obj1[str] = 1;
    }
  }
  for (var str of str2) {
    if (str in obj2) {
      obj2[str] += 1;
    } else {
      obj2[str] = 1;
    }
  }
  for (var obj in obj1) {
    if (!(obj in obj2)) {
      return false;
    }
    if (obj in obj2) {
      if (!(obj1[obj] == obj2[obj])) {
        return false;
      }
    }
  }
  return true;
};
