import math

'''change returns a tuple of minimum U.S. quarters, dimes, nickels
and pennies for the given cents input'''
def change(amount):
    if amount < 0:
        raise ValueError('amount cannot be negative')
    result = []
    remaining = amount
    for i in [25, 10, 5, 1]:
        result.append(math.floor(remaining / i))
        remaining %= i
    return tuple(result)

'''strip_quotes takes in a string and returns a string with all apostrophes and
double quotes removed'''
import re
def strip_quotes(original):
    return re.sub(r'[\"\']', '', original)

'''scramble takes in a string returns the string scrambled
with each possibility having an equal chance of occuring'''
from random import shuffle
def scramble(word):
    word_list = list(word)
    shuffle(word_list)
    return (''.join(word_list))

''' say is a chainable function that returns concatenated string
from previous arguments when a None argument is received'''
def say(first_word = None):
    words = []
    def say_more(word = None):
        if word is None:
            return ' '.join(words)
        words.append(word)
        return say_more
    return say_more(first_word)

'''powers is a generator function that takes in a base
and a limit and generate successive powers of the base
up to the limit'''
def powers(base, limit):
    power = 1
    while power <= limit:
        yield power
        power *= base

'''triples takes in a value that is a hypotenuse limit
and returns a list of tuples of Pythagorean
triples below that limit'''
def triples(hypotenuse_lim):
    pytriples = []
    for a in range(1, hypotenuse_lim):
        for b in range(a, hypotenuse_lim):
            for c in range(1, hypotenuse_lim +1):
                if a**2 + b** 2 == c**2:
                    triple = (a,b,c)
                    pytriples.append(triple)
    return pytriples

'''Returns the interleave of an array
with the rest of input values'''
def interleave(a, *b):
    result = []
    first_length = len(a)
    second_length = len(b)
    m = max(first_length, second_length)
    for i in range(0, m):
        if i < first_length: result.append(a[i])
        if i < second_length: result.append(b[i])
    return result

class Cylinder:
    "A cylinder with a height and a radius"

    def __init__(self, radius = 1 , height = 1):
        self.radius = radius
        self.height = height

    @property
    def surface_area(self):
        "Returns the cylinder's surface area"
        return (2 * math.pi * (self.radius ** 2) + 2 * math.pi * self.radius * self.height)

    @property
    def volume(self):
        "Returns the cylinder's volume"
        return (math.pi * (self.radius ** 2) * self.height)

    def widen(self, factor):
        "Increases the cylinder's radius by a factor"
        self.radius *= factor
        return self

    def stretch(self, factor):
        "Increases the cylinder's height by a factor"
        self.height *= factor
        return self

from Crypto.Cipher import AES
def make_crypto_functions(key, iv):
    def encrypt(msg):
        cipher = AES.new(key, AES.MODE_CBC, iv)
        return cipher.encrypt(msg)
    def decrypt(msg):
        cipher = AES.new(key, AES.MODE_CBC, iv)
        return cipher.decrypt(msg)
    return (encrypt, decrypt)

'''random_name takes a region and gender and return a randomized name
from the uinames API based on the input parameter values'''
import requests
def random_name(region, gender):
    p = {'params':{'region': region, 'gender': gender, 'amount': 1}}
    r = requests.get('https://uinames.com/api', **p)
    if r.status_code is not 200:
        raise ValueError(r.text)
        return
    else:
        rjson = r.json()
        return rjson['surname'] + ', ' + rjson['name']
