def work():
    string = raw_input ()
    size = len(string)
    check = string.isalpha ()
    if size > 0 and check == True:
        return string
    else:
        return "empty"

work()
