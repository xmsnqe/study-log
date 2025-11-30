class ListNode:
    """链表节点类"""
    def __init__(self, val: int):
        self.val: int = val               # 节点值
        self.next: ListNode | None = None # 指向下一节点的引用

    def insert(n0: ListNode, p: ListNode)
        """在链表的节点 n0 之后插入节点 p"""
        n1 = n0.next
        p.next = n1
        n0.next = p

    def delete(n0: ListNode) -> ListNode:
        """删除链表节点 n0的后一个节点"""
        if not n0.next:
            return
        p = n0.next
        n1 = p.next
        n0.next = n1
    
    def access(head: ListNode, index: int) -> ListNode | None:
        """访问链表的第 index 个节点"""
        for _ in range(index):
            if not head:
                return None
            head = head.next
        return head
    
    def find(head: ListNode, target: int) -> int:
        """查找链表中值为 target 的第一个节点"""
        index = 0
        while head:
            if head.val == target:
                return index
            head = head.next
            index += 1
        return -1
    
    def print(head: ListNode) -> None:
        """打印链表"""
        while head:
            print(head.val, end=" -> ")
            head = head.next
        print("None")