def check(chk, char):
    if chk == '(' and char == ')':
        return True
    elif chk == '[' and char == ']':
        return True
    else:
        return False

def sol(s):
    stack = []
    for char in s:
        if char in "([":
            stack.append(char)
        elif char in ")]":
            if not stack:
                return 'no'
            else:
                chk = stack.pop()
                if not check(chk, char):
                    return 'no'
    if stack:
        return 'no'
    else:
        return 'yes'


s = input()
while s[0] != '.':
    print(sol(s))
    s = input()