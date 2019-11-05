#!/usr/bin/env python3
""" Retrieve words from url

Usage:
    python3 words.py <url> 
    python3 words.py 'http://sixty-north.com/c/t.txt'
"""

import sys
from urllib.request import urlopen

def fetch_words(url):
    with urlopen(url) as story:
        story_words = []
        for line in story:
            line_words = line.decode('utf-8').split()
            for word in line_words:
                story_words.append(word)
    return story_words


def print_items(items):
    """ Print the item in iterable items
    """
    for item in items:
        print(item)

def main(url):
    words = fetch_words(url)
    print_items(words)

if __name__ == '__main__':
    main(sys.argv[1]) # the 0th arg is module filename