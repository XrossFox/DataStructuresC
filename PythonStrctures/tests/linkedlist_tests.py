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


if __name__ == '__main__':
    unittest.main()
