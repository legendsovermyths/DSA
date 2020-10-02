class Node {
  constructor(val) {
    this.val = val;
    this.next = null;
  }
}
class SinglyLinkedList {
  constructor() {
    this.head = null;
    this.tail = null;
    this.length = 0;
  }
  push(val) {
    var node = new Node(val);
    if (this.head === null) {
      this.head = node;
      this.tail = node;
      this.length += 1;
    } else {
      this.tail.next = node;
      this.tail = node;
      this.length += 1;
    }
  }
  pop() {
    var prev = this.head;
    while (prev.next.next != null) {
      prev = prev.next;
    }
    this.tail = prev;
    this.tail.next = null;
    this.length -= 1;
  }
}
list = new SinglyLinkedList();
list.push(12);
list.push(13);
list.push(16);
list.push(18);
console.log(list);
list.pop();
console.log(list);
