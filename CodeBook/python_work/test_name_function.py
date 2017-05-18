import unittest
from name_function import *


class TestName(unittest.TestCase):
    def name_check(self):
        format_name = got_formatted_name('hhh', 'ttt')
        self.assertEqual(format_name, 'Hhh Ttt')


unittest.main()
