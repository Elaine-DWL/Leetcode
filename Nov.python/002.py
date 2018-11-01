class Solution(object):
	def addTwoNumbers(self, l1, l2):
		carry = 0
		cur = dummy = ListNode(0)
		while l1 or l2 or carry:
			if l1:
				carry += l1.val
				l1 = l1.next
			if l2:
				carry += l2.val
				l2 = l2.next
			# 生成一个新节点
			cur.next = ListNode(carry%10)
			cur = cur.next
			carry //= 10
		return dummy.next