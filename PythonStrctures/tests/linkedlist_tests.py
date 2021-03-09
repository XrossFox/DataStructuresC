from unittest import TestCase
import unittest
from LinkedList.linkedlist import LinkedList


class LinkedListTests(TestCase):

    def test_append_test_empty_list(self):
        """
        Tests that when appending a new element to an empty linked list:
        1. it must be added properly as head.
        2. Must also be tail.
        3. And next and previous nodes should be None.
        4. Check that Node's value is set properly.
        """
        ll = LinkedList()
        some_string = "holi"
        ll.append(some_string)
        self.assertEqual(ll.head.data, some_string)
        self.assertEqual(ll.tail.data, some_string)
        self.assertEqual(ll.head.previous, None)
        self.assertEqual(ll.head.next, None)

    def test_append_test_non_empty_list(self):
        """
        Tests that when appending to a non-empty list, the element should be
        added as tail.
        1. Current tails should be updated to link it's next node to
        the new element.
        2. New element's previous node should be linked to Current Tail.
        3. New element's next node should be None.
        4. And then, new element should be set as Tail.
        5. Check that Node's value is set properly.
        """
        ll = LinkedList()
        some_string = "holis"
        some_value = 15
        ll.append(some_string)
        ll.append(some_value)
        self.assertEqual(ll.tail.previous.next.data, some_value)
        self.assertEqual(ll.tail.previous.data, some_string)
        self.assertEqual(ll.tail.next, None)
        self.assertEqual(ll.tail.data, some_value)

    def test_list_size_is_zero(self):
        '''
        1. If the linked list is empty, then it's property size should be 0
        '''
        ll = LinkedList()
        self.assertEqual(ll.size, 0)

    def test_list_size_grows_when_appending(self):
        '''
        1. The size of the linked list must be equal to the nodes,
        raised when a new node is added.
        '''
        ll = LinkedList()
        ll.append("Halooo!")
        self.assertEqual(ll.size, 1)
        ll.append("Konichiwa")
        self.assertEqual(ll.size, 2)

    def test_list_insert_at_position_list_is_empty(self):
        '''
        When trying to insert an element at a given index, and the list is
        empty.
        1. The element should be inserted at index 0.
        2. Inserted element should be treated as head.
        3. Inserted element should be treated as tail.
        4. Inserted element should be linked to None, forward and backward.
        '''
        ll = LinkedList()
        some_value = "holis"
        ll.insert_at(0, some_value)
        self.assertEqual(ll.head.data, some_value)
        self.assertEqual(ll.head.previous, None)
        self.assertEqual(ll.head.next, None)
        self.assertEqual(ll.tail.data, some_value)
        self.assertEqual(ll.tail.previous, None)
        self.assertEqual(ll.tail.next, None)

    def test_list_insert_at_head_list_not_empty(self):
        '''
        When trying to insert an element at the head position, and the list is
        not empty.
        1. The element should be inserted at position 0.
        2. The new head should be updated to be the new node.
        3. The old head should be the next element to new head.
        4. the new head should be previous element to old head.
        '''
        ll = LinkedList()
        a_value = "Primer Valor"
        ll.append(a_value)
        some_value = "Segundo valor"
        ll.insert_at(0, some_value)
        self.assertEqual(ll.head.data, some_value)
        self.assertEqual(ll.head.next.data, a_value)
        self.assertEqual(ll.head.next.previous.data, some_value)

    def test_list_insert_at_tail_list_not_empty(self):
        '''
        When trying to insert an element at the tail position and the
        list is not empty.
        1. The list must be size > 1.
        2. The element should be inserted at position 'size'
        That means, the new element should be inserted after the old tail, and
        become the new one.
        3. The new node must be new tail.
        4. the old tail next node should be new node.
        5. the new node previous node must be old tail.
        '''
        ll = LinkedList()
        a_value = "Hai!"
        other_value = "Gutentag"
        ll.append("konnichiwa")
        ll.append(a_value)
        ll.insert_at(ll.size, other_value)
        self.assertTrue(ll.size > 1)
        self.assertEqual(ll.tail.data, other_value)
        self.assertEqual(ll.tail.previous.next.data, other_value)
        self.assertEqual(ll.tail.previous.data, a_value)      

    def test_list_insert_not_head_nor_tail(self):
        '''
        When trying to insert at a position between head and tail.
        1. List size must be 2.
        2. New node should not be head, or tail.
        3. New node should be inserted at index 1 (not 0).
        '''
        ll = LinkedList()
        a_value = "Hai, domo!"
        ll.append("Kizuna AI Desu!")
        ll.append("fokiu!")
        ll.insert_at(1, a_value)
        self.assertEqual(ll.head.next.data, a_value)


if __name__ == '__main__':
    unittest.main()
