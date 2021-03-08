from LinkedList.node import Node


class LinkedList:

    def __init__(self):
        self._head = None
        self._tail = None
        self._size = 0

    @property
    def head(self) -> Node:
        '''
        returns head node
        '''
        return self._head

    @head.setter
    def head(self, node_instance):
        '''
        Sets the head node as an instance of class Node or None.
        '''
        if (not isinstance(node_instance, Node)):
            if not (node_instance is None):
                raise TypeError("Instance is not of type Node or None")

        self._head = node_instance

    @property
    def size(self) -> int:
        '''
        returns the size of the list
        '''
        return self._size

    @size.setter
    def size(self, value):
        '''
        Raises the size from the received int.
        '''
        if (not isinstance(value, int) or value < 1):
            raise TypeError("value is not of type int or is less than 0")

        self._size += value

    @property
    def tail(self) -> Node:
        '''
        returns tail node
        '''
        return self._tail

    @tail.setter
    def tail(self, node_instance):
        '''
        Sets the tail node as an instance of class Node or None.
        '''
        if (not isinstance(node_instance, Node)):
            if not (node_instance is None):
                raise TypeError("Instance is not of type Node or None")

        self._tail = node_instance

    def append(self, value):
        '''
        Appends a new element to the Linked List at the end. If
        the list is empty, then it´s added as both, head and tail nodes.
        Arguments:
        value -- an object to add.
        '''

        new_node = Node()
        new_node.data = value

        if(self.head is None):

            self.head = new_node
            self.tail = new_node
            return

        self.tail.next = new_node
        new_node.previous = self.tail
        self.tail = new_node
