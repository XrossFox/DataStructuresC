import unittest
from LinkedList import node


class NodeTests(unittest.TestCase):

    def test_init(self):
        """
        Test that all base values are initialized properly
        1. previous = None
        2. next = None
        3. data = None
        """
        test_node = node.Node()
        self.assertEqual(test_node.previous, None)
        self.assertEqual(test_node.next, None)
        self.assertEqual(test_node.data, None)

    # Previous Node

    def test_previous_get(self):
        '''
        Test for getter.
        1. Should return None (the instance hasn't been setted yet).
        '''
        test_node = node.Node()
        self.assertEqual(test_node.previous, None)

    def test_previous_set(self):
        '''
        Test for setter.
        1. Should set an instance of Node.
        '''
        test_node = node.Node()
        another_node = node.Node()
        test_node.previous = another_node
        self.assertEquals(test_node.previous, another_node)

    def test_previous_set_non_instance_of_node_exception(self):
        '''
        Test for setter
        1. should rise an exception if a non-node instance is
        received.
        '''
        with self.assertRaises(TypeError):
            test_node = node.Node()
            test_node.previous = 15

    def test_previous_set_as_none(self):
        '''
        Test for setter.
        1. previous should be able to set as None, even if there is
        already another value.
        '''
        test_node = node.Node()
        another_node = node.Node()
        test_node.previous = another_node
        test_node.previous = None
        self.assertEqual(test_node.previous, None)

    # Next Node

    def test_next_get(self):
        '''
        Test for getter.
        1. Should return None (the instance hasn't been setted yet).
        '''
        test_node = node.Node()
        self.assertEqual(test_node.next, None)

    def test_next_set(self):
        '''
        Test for setter.
        1. Should set an instance of Node.
        '''
        test_node = node.Node()
        another_node = node.Node()
        test_node.next = another_node
        self.assertEquals(test_node.next, another_node)

    def test_next_set_non_instance_of_node_exception(self):
        '''
        Test for setter
        1. should rise an exception if a non-node instance is
        received.
        '''
        with self.assertRaises(TypeError):
            test_node = node.Node()
            test_node.next = 15

    def test_next_set_as_none(self):
        '''
        Test for setter.
        1. next should be able to set as None, even if there is
        already another value.
        '''
        test_node = node.Node()
        another_node = node.Node()
        test_node.next = another_node
        test_node.next = None
        self.assertEqual(test_node.next, None)

    # Data Values

    def test_value_get_can_be_Node(self):
        '''
        Test for getter
        1. Data could be None
        '''
        test_node = node.Node()
        self.assertEqual(test_node.data, None)

    def test_value_get_can_be_object(self):
        '''
        Test for getter.
        1. Data can be an instance of object
        '''
        test_node = node.Node()
        test_node.data = "Alo!"
        self.assertTrue(isinstance(test_node.data, object))
        test_node.data = 15
        self.assertTrue(isinstance(test_node.data, object))
        test_node.data = {1: "alo"}
        self.assertTrue(isinstance(test_node.data, object))
        test_node.data = [1, ]
        self.assertTrue(isinstance(test_node.data, object))


if __name__ == '__main__':
    unittest.main()
