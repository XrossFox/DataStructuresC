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

    def test_list_insert_negative_index(self):
        '''
        When trying to insert below zero index.
        1. Insert at a negative index.
        2. LookUpException is expected.
        '''
        ll = LinkedList()
        with self.assertRaises(LookupError):
            ll.insert_at(-1, "15")

    def test_list_insert_above_last_index(self):
        '''
        When trying to insert above the last index.
        1. Insert at a higher than size index.
        2. LookUpException is expected.
        '''
        ll = LinkedList()
        with self.assertRaises(LookupError):
            ll.append("10")
            ll.append("20")
            ll.insert_at(ll.size+1, "15")

    def test_list_insert_index_not_int(self):
        '''
        When trying to insert when index is not an int value.
        1. Pass insert as a string.
        2. TypeError is expected
        '''
        ll = LinkedList()
        with self.assertRaises(TypeError):
            ll.insert_at("0", "15")

    def test_get_by_index(self):
        '''
        Returns the data attribute of the node at given index.
        1. List size must be > 1.
        2. Value must be present at given index.
        '''
        ll = LinkedList()
        some_value = 15
        ll.append("12")
        ll.append(18)
        ll.append(some_value)
        self.assertEqual(ll.get_at(2), some_value)

    def test_get_by_index_below_0(self):
        '''
        When trying to access a node below index 0.
        1. Index must be below 0.
        2. LookupError expected
        '''
        ll = LinkedList()
        with self.assertRaises(LookupError):
            ll.get_at(-1)

    def test_get_by_index_above_size(self):
        '''
        When trying to access a node below index 0.
        1. Index must be below 0.
        2. LookupError expected
        '''
        ll = LinkedList()
        with self.assertRaises(LookupError):
            ll.get_at(1)

    def test_get_by_index_not_int(self):
        '''
        When trying to access a node with a non-int index.
        1. Index must be non-int.
        2. TypeError expected.
        '''
        ll = LinkedList()
        with self.assertRaises(TypeError):
            ll.get_at("1")

    def test_is_present_true(self):
        '''
        When trying to find out if a value is present in the list.
        1. The value must be previously inserted.
        2. When method is called, True is expected.
        '''
        ll = LinkedList()
        some_value = "gutentag"
        ll.append("alo")
        ll.append("aloha")
        ll.append(some_value)
        self.assertTrue(ll.is_present(some_value))

    def test_is_present_false(self):
        '''
        When trying to find out if a value is present in the list.
        1. The value must be previously inserted.
        2. When method is called, False is expected.
        '''
        ll = LinkedList()
        some_value = "gutentag"
        ll.append("alo")
        ll.append("aloha")
        ll.append("Konnichiwa")
        self.assertFalse(ll.is_present(some_value))

    def test_get_index_of(self):
        '''
        When trying to get the index of a given value.
        1. The value must be added to the list beforehand.
        2. Pass the value to the method.
        3. Must return the index of the element.
        '''
        ll = LinkedList()
        some_value = "Jolis!"
        ll.append("A")
        ll.append("B")
        ll.append(some_value)
        ll.append("C")
        returnal = ll.get_index_of(some_value)
        self.assertEqual(returnal, 2)
        self.assertEqual(ll.get_at(returnal), some_value)

    def test_get_index_of_value_not_present(self):
        '''
        When trying to get the index of a given value.
        1. Pass the value to the method that is not in the list.
        2. LookupError expected.
        '''
        ll = LinkedList()
        some_value = "Jolis!"
        ll.append("A")
        ll.append("B")
        ll.append(some_value)
        ll.append("C")
        with self.assertRaises(LookupError):
            ll.get_index_of("Konnichiwa!")

    def test_delete_at_index(self):
        '''
        When trying to delete a node at a given position.
        1. Delete a node at a desired index.
        2. index must not be present in the list.
        '''
        ll = LinkedList()
        some_value = "Delete me"
        ll.append("s")
        ll.append("d")
        ll.append(some_value)
        ll.append("45")
        self.assertEqual(ll.delete_at(2), some_value)
        self.assertFalse(ll.is_present(some_value))

    def test_delete_at_index_below_0(self):
        '''
        When trying to delete a node at a given position.
        1. Index must be below 0.
        2. LookupError Expected.
        '''
        ll = LinkedList()
        some_value = "Delete me"
        ll.append("s")
        ll.append("d")
        ll.append(some_value)
        ll.append("45")
        with self.assertRaises(LookupError):
            ll.delete_at(-1)

    def test_delete_at_index_above_or_equal_to_size(self):
        '''
        When trying to delete a node at a given position.
        1. Index must be equal or above size.
        2. LookupError Expected.
        '''
        ll = LinkedList()
        some_value = "Delete me"
        ll.append("s")
        ll.append("d")
        ll.append(some_value)
        ll.append("45")
        with self.assertRaises(LookupError):
            ll.delete_at(ll.size)


if __name__ == '__main__':
    unittest.main()
