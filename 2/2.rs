// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
// 
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
impl Solution {
    pub fn add_two_numbers(l1: Option<Box<ListNode>>, l2: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut dummy_head = ListNode::new(0);
        let mut current = &mut dummy_head;
        let mut p = l1;
        let mut q = l2;
        
        let mut carry: i32 = 0;
        
        while p != None || q != None {
            let sum = match(&p, &q) {
                (Some(n1), Some(n2)) => n1.val + n2.val + carry,
                (Some(n1), None) => n1.val + carry,
                (None, Some(n2)) => n2.val + carry,
                (None, None) => carry,
            };
            
            carry = sum / 10;
            current.next = Some(Box::new(ListNode::new(sum % 10)));
            current = current.next.as_mut().unwrap();
            
            p = if p != None { p.unwrap().next } else { p };
            q = if q != None { q.unwrap().next } else { q };
        }
        
        if carry != 0 {
            current.next = Some(Box::new(ListNode::new(carry)));
        }
        
        dummy_head.next
    }
}