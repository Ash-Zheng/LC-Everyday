# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverse(self,head,tail): #reverse the head to tail-1
        prehead=head
        p=head
        q=tail
        temp=p
        while p.next!=tail:
            temp=p.next
            p.next=q
            q=p
            p=temp
        p.next=q
        return p,prehead

    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        if k<=1 or head==None:
            return head

        front=ListNode(0)
        last_tail=front
        point=last_tail
        front.next=head
        cnt=0
        while point!=None: #break：point == tail
            point=point.next
            cnt+=1
            if cnt==k+1:
                cnt=1
                temp,pretemp=self.reverse(last_tail.next,point)
                last_tail.next=temp
                last_tail=pretemp

        return front.next