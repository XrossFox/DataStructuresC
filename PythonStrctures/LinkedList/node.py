
class Node:

    def __init__(self):
        self._previous = None
        self._data = None
        self._next = None

    @property
    def previous(self):
        """
        Returns the 'previous' Node instance.
        """
        return self._previous

    @previous.setter
    def previous(self, node_instance):
        '''
        Sets the previous Node to an instance of Node or None type.
        '''
        if (not isinstance(node_instance, Node)):
            if not (node_instance is None):
                raise TypeError("Instance is not of type Node or None")

        self._previous = node_instance

    @property
    def next(self):
        '''
        Retrn the 'next' Node instance.
        '''
        return self._next

    @next.setter
    def next(self, node_instance):
        '''
        Sets the next Node to an instance of Node or None type.
        '''
        if (not isinstance(node_instance, Node)):
            if not (node_instance is None):
                raise TypeError("Instance is not of type Node or None")

        self._next = node_instance

    @property
    def data(self):
        """
        Returns the dat of the current node.
        """
        return self._data

    @data.setter
    def data(self, value):
        self._data = value
