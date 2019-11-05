def convert(s):
    try:
        return int(s)
    except (ValueError, TypeError) as e:
        print(str(e))
        return -1
