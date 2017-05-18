from names import get_formatted_name

print("enter q to quit anytime\n")
while True:
    first = input("enter your first name: ")
    if first == 'q':
        break
    last = input("enter your last name:")
    if last == 'q':
        break

    formatted_name = get_formatted_name(first, last)
    print(formatted_name)