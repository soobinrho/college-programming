# invoice.py
'''Class Invoice for managing items sold at hardware stores.'''
import pandas as pd
import re

class Invoice:
    '''
        Class Invoice consists of
        the following attributes:
            part_number, 
            part_description,
            quatity_sold, and
            price_per_item.
            
        This class also has a method
        that calculates the invoice amount.
    '''
    
    # --------------------------- #
    # Constructing Class Invoice.
    # --------------------------- #
    def __init__(
        self,
        part_number: str,
        part_description: str,
        quantity_sold: int,
        price_per_item: float
    ):
        '''Initializes the attributes.'''
        self.part_number = part_number
        self.part_description = part_description
        self.quantity_sold = quantity_sold
        self.price_per_item = price_per_item
        
    # ----------------------------- #
    # part_number getter and setter
    # ----------------------------- #
    @property
    def part_number(self) -> str:
        '''Returns part_number.'''
        return self._part_number
        
    @part_number.setter
    def part_number(self, part_number: str):
        '''Sets part_number.'''
        
        # Converting the input into a string,
        # in case it's not already a string.
        part_number = str(part_number)
        
        # If the input has non-numbers,
        # raise ValueError.
        if re.search(r'^\d+$', part_number) == None:
            raise ValueError('Invalid part number.')
        self._part_number = part_number
        
    # ---------------------------------- #
    # part_description getter and setter
    # ---------------------------------- #        
    @property
    def part_description(self) -> str:
        '''Returns part_description.'''
        return self._part_description
        
    @part_description.setter
    def part_description(self, part_description: str):
        '''Sets part_description.'''
        
        # Converting the input into a string,
        # in case it's not already a string.
        part_description = str(part_description)
        self._part_description = part_description
        
    # ------------------------------- #
    # quantity_sold getter and setter
    # ------------------------------- #
    @property
    def quantity_sold(self) -> int:
        '''Returns quantity_sold.'''
        return self._quantity_sold
        
    @quantity_sold.setter
    def quantity_sold(self, quantity_sold: int):
        '''Sets quantity_sold.'''
        
        # If the input value is negative,
        # raise ValueError.
        if quantity_sold < 0:
            raise ValueError('Invalid quantity being sold.')
        self._quantity_sold = quantity_sold
        
    # ------------------------------- #
    # price_per_item getter and setter
    # ------------------------------- #
    @property
    def price_per_item(self) -> float:
        '''Returns price_per_item.'''
        return self._price_per_item
        
    @price_per_item.setter
    def price_per_item(self, price_per_item: float):
        '''Sets price_per_item.'''
        
        # If the input value is negative,
        # raise ValueError.
        if price_per_item < 0:
            raise ValueError('Invalid price per item.')
        self._price_per_item = price_per_item
        
    # ----------------------------------- #
    # Method for calculating the invoice.
    # ----------------------------------- #
    def calculate_invoice(self) -> float:
        total = self.price_per_item * self.quantity_sold
        return total
    
    def __repr__(self):
        '''Returns the object for repr().'''
        
        # Returning the attributes in a nice format.
        # DataFrame is used here because it
        # automatically adjusts alignments.
        repr_string = pd.DataFrame(
            [
                [self.part_number],
                [self.quantity_sold],
                [self.price_per_item]
            ],
            index=[
                'Part Number',
                'Quantity Sold',
                'Price Per Item'
            ],
            columns=[self.part_description]
        )
        repr_string = str(repr_string)
        return repr_string
        
